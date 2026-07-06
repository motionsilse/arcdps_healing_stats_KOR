#include "Localization.h"

#include "Log.h"
#include "SimpleIni.h"

#include <algorithm>
#include <array>
#include <cctype>
#include <filesystem>
#include <map>
#include <optional>
#include <string>

namespace
{
	CSimpleIniA gLocalizationIni(true /* isUtf8 */);
	std::map<std::string, std::string> gLocalizationCache;
	bool gLocalizationLoaded = false;

	std::string PathForLog(const std::filesystem::path& pPath)
	{
		auto path = pPath.u8string();
		return std::string{ reinterpret_cast<const char*>(path.c_str()), path.size() };
	}

	std::optional<std::filesystem::path> GetArcdpsDirectory()
	{
		std::array<wchar_t, 32768> executablePath{};
		DWORD length = GetModuleFileNameW(nullptr, executablePath.data(), static_cast<DWORD>(executablePath.size()));
		if (length == 0 || static_cast<size_t>(length) >= executablePath.size())
		{
			LogW("Could not resolve executable path for localization file");
			return std::nullopt;
		}

		return std::filesystem::path{ executablePath.data() }.parent_path() / "addons" / "arcdps";
	}

	std::optional<std::string> NormalizeLanguageCode(const char* pValue)
	{
		if (pValue == nullptr)
		{
			return std::nullopt;
		}

		std::string code{ pValue };
		code.erase(code.begin(), std::find_if(code.begin(), code.end(), [](unsigned char ch)
		{
			return std::isspace(ch) == 0;
		}));
		code.erase(std::find_if(code.rbegin(), code.rend(), [](unsigned char ch)
		{
			return std::isspace(ch) == 0;
		}).base(), code.end());

		if (code.empty() == true || code.size() > 16)
		{
			return std::nullopt;
		}

		for (char& ch : code)
		{
			unsigned char unsignedCh = static_cast<unsigned char>(ch);
			if (std::isalnum(unsignedCh) == 0 && ch != '-' && ch != '_')
			{
				return std::nullopt;
			}
			ch = static_cast<char>(std::tolower(unsignedCh));
		}

		return code;
	}

	std::optional<std::string> ReadConfiguredLanguage(const std::filesystem::path& pArcdpsDirectory)
	{
		const std::filesystem::path localeConfigPath = pArcdpsDirectory / "Healing_Stats.locale.ini";
		if (std::filesystem::exists(localeConfigPath) == false)
		{
			return std::nullopt;
		}

		CSimpleIniA localeIni(true /* isUtf8 */);
		SI_Error result = localeIni.LoadFile(localeConfigPath.wstring().c_str());
		if (result < 0)
		{
			LogW("Loading localization config '{}' failed with {}", PathForLog(localeConfigPath), static_cast<int>(result));
			return std::nullopt;
		}

		std::optional<std::string> language = NormalizeLanguageCode(localeIni.GetValue("localization", "language", nullptr));
		if (language.has_value() == false)
		{
			LogW("Localization config '{}' does not contain a valid [localization] language value", PathForLog(localeConfigPath));
		}

		return language;
	}

	std::optional<std::filesystem::path> ResolveLocalizationPath(const std::filesystem::path& pArcdpsDirectory)
	{
		std::optional<std::string> configuredLanguage = ReadConfiguredLanguage(pArcdpsDirectory);
		if (configuredLanguage.has_value() == true)
		{
			if (*configuredLanguage == "en")
			{
				LogI("Localization language is set to English; using fallback strings");
				return std::nullopt;
			}

			std::filesystem::path configuredPath = pArcdpsDirectory / ("Healing_Stats." + *configuredLanguage + ".ini");
			if (std::filesystem::exists(configuredPath) == true)
			{
				return configuredPath;
			}

			LogW("Configured localization file '{}' was not found; using English fallback strings", PathForLog(configuredPath));
			return std::nullopt;
		}

		std::filesystem::path koreanPath = pArcdpsDirectory / "Healing_Stats.ko.ini";
		if (std::filesystem::exists(koreanPath) == true)
		{
			return koreanPath;
		}

		LogI("Localization file not found at '{}'; using English fallback strings", PathForLog(koreanPath));
		return std::nullopt;
	}

	std::string DecodeEscapes(const char* pValue)
	{
		std::string decoded;
		for (const char* ch = pValue; *ch != '\0'; ch++)
		{
			if (*ch == '\\' && ch[1] != '\0')
			{
				ch++;
				switch (*ch)
				{
				case 'n':
					decoded.push_back('\n');
					break;
				case 't':
					decoded.push_back('\t');
					break;
				case '\\':
					decoded.push_back('\\');
					break;
				default:
					decoded.push_back('\\');
					decoded.push_back(*ch);
					break;
				}
			}
			else
			{
				decoded.push_back(*ch);
			}
		}

		return decoded;
	}
}

void Localization::Load(HMODULE pModule)
{
	(void)pModule;
	gLocalizationLoaded = false;
	gLocalizationIni.Reset();
	gLocalizationCache.clear();

	std::optional<std::filesystem::path> arcdpsDirectory = GetArcdpsDirectory();
	if (arcdpsDirectory.has_value() == false)
	{
		return;
	}

	std::optional<std::filesystem::path> localizationPath = ResolveLocalizationPath(*arcdpsDirectory);
	if (localizationPath.has_value() == false)
	{
		return;
	}

	SI_Error result = gLocalizationIni.LoadFile(localizationPath->wstring().c_str());
	if (result < 0)
	{
		LogW("Loading localization file '{}' failed with {}", PathForLog(*localizationPath), static_cast<int>(result));
		return;
	}

	gLocalizationLoaded = true;
	LogI("Loaded localization file '{}'", PathForLog(*localizationPath));
}

const char* Localization::Get(const char* pSection, const char* pKey, const char* pFallback)
{
	if (gLocalizationLoaded == false)
	{
		return pFallback;
	}

	const char* value = gLocalizationIni.GetValue(pSection, pKey, nullptr);
	if (value == nullptr)
	{
		return pFallback;
	}

	std::string cacheKey = std::string{ pSection } + '\n' + pKey;
	auto iter = gLocalizationCache.find(cacheKey);
	if (iter == gLocalizationCache.end())
	{
		iter = gLocalizationCache.emplace(cacheKey, DecodeEscapes(value)).first;
	}

	return iter->second.c_str();
}

bool Localization::IsLoaded()
{
	return gLocalizationLoaded;
}
