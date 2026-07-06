#include "Localization.h"

#include "Log.h"
#include "SimpleIni.h"

#include <array>
#include <filesystem>
#include <map>
#include <string>

namespace
{
	CSimpleIniA gLocalizationIni(true /* isUtf8 */);
	std::map<std::string, std::string> gLocalizationCache;
	bool gLocalizationLoaded = false;

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

	std::array<char, MAX_PATH> executablePath{};
	DWORD length = GetModuleFileNameA(nullptr, executablePath.data(), static_cast<DWORD>(executablePath.size()));
	if (length == 0 || length >= executablePath.size())
	{
		LogW("Could not resolve executable path for localization file");
		return;
	}

	std::filesystem::path localizationPath = std::filesystem::path{executablePath.data()}.parent_path() / "addons" / "arcdps" / "Healing_Stats.ko.ini";
	if (std::filesystem::exists(localizationPath) == false)
	{
		LogI("Localization file not found at '{}'; using English fallback strings", localizationPath.string());
		return;
	}

	SI_Error result = gLocalizationIni.LoadFile(localizationPath.string().c_str());
	if (result < 0)
	{
		LogW("Loading localization file '{}' failed with {}", localizationPath.string(), static_cast<int>(result));
		return;
	}

	gLocalizationLoaded = true;
	LogI("Loaded localization file '{}'", localizationPath.string());
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
