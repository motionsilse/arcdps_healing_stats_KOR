#include "UpdateGUI.h"

#include "Exports.h"
#include "ImGuiEx.h"
#include "Localization.h"
#include "Log.h"

#include <shellapi.h>
#include <cpr/cpr.h>

static const char* L(const char* pKey, const char* pFallback)
{
	return Localization::Get("update", pKey, pFallback);
}

void UpdateChecker::Log(std::string&& pMessage)
{
	LogI("{}", pMessage);
}

bool UpdateChecker::HttpDownload(const std::string& pUrl, const std::filesystem::path& pOutputFile)
{
	std::ofstream outputStream(pOutputFile, std::ios_base::out | std::ios_base::binary);
	cpr::Response response = cpr::Download(outputStream, cpr::Url{pUrl});
	if (response.status_code != 200) {
		Log(std::format("Downloading {} failed - http failure {} {}", pUrl, response.status_code,
		                response.status_line));
		return false;
	}

	return true;
}

std::optional<std::string> UpdateChecker::HttpGet(const std::string& pUrl)
{
	cpr::Response response = cpr::Get(cpr::Url{pUrl});
	if (response.status_code != 200) {
		Log(std::format("Getting {} failed - {} {}", pUrl, response.status_code, response.status_line));
		return std::nullopt;
	}

	return response.text;
}

void Display_UpdateWindow()
{
	auto& state = GlobalObjects::UPDATE_STATE;
	if (state == nullptr)
	{
		return;
	}

	std::lock_guard lock(state->Lock);
	if (state->UpdateStatus != UpdateChecker::Status::Unknown && state->UpdateStatus != UpdateChecker::Status::Dismissed)
	{
		bool shown = true;
		if (ImGui::Begin(
			L("window_title", "Healing Stats Update###HEALING_STATS_UPDATE"),
			&shown,
			ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize) == true)
		{
			const UpdateChecker::Version& currentVersion = *state->CurrentVersion;
			const UpdateChecker::Version& newVersion = state->NewVersion;

			ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), L("available", "A new update for the healing stats addon is available"));
			ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), L("current_version", "Current version: %u.%urc%u"), currentVersion[0], currentVersion[1], currentVersion[2]);
			ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), L("new_version", "New version: %u.%urc%u"), newVersion[0], newVersion[1], newVersion[2]);

			if (ImGui::Button(L("open_download_page", "Open download page")) == true)
			{
				ShellExecuteA(nullptr, nullptr, "https://github.com/motionsilse/arcdps_healing_stats_KOR/releases", nullptr, nullptr, SW_SHOW);
			}

			switch (state->UpdateStatus)
			{
			case UpdateChecker::Status::UpdateAvailable:
				if (ImGui::Button(L("update_automatically", "Update automatically")) == true)
				{
					GlobalObjects::UPDATE_CHECKER->PerformInstallOrUpdate(*state);
				}
				break;
			case UpdateChecker::Status::UpdateInProgress:
				ImGui::TextUnformatted(L("update_in_progress", "Update in progress"));
				break;
			case UpdateChecker::Status::UpdateSuccessful:
				ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), L("update_successful", "Update finished, restart Guild Wars 2 for the update to take effect"));
				break;
			case UpdateChecker::Status::UpdateError:
				ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), L("update_error", "An error occured while updating"));
				break;
			default:
				break;
			}

			ImGui::End();
		}

		if (shown != true)
		{
			state->UpdateStatus = ArcdpsExtension::UpdateCheckerBase::Status::Dismissed;
		}
	}
}
