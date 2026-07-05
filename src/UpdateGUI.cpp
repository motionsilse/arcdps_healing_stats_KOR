#include "UpdateGUI.h"

#include "Exports.h"
#include "ImGuiEx.h"
#include "Log.h"

#include <shellapi.h>
#include <cpr/cpr.h>

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
			"치유 통계 업데이트###HEALING_STATS_UPDATE",
			&shown,
			ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize) == true)
		{
			const UpdateChecker::Version& currentVersion = *state->CurrentVersion;
			const UpdateChecker::Version& newVersion = state->NewVersion;

			ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "치유 통계 애드온 새 업데이트가 있습니다");
			ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "현재 버전: %u.%urc%u", currentVersion[0], currentVersion[1], currentVersion[2]);
			ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), "새 버전: %u.%urc%u", newVersion[0], newVersion[1], newVersion[2]);

			if (ImGui::Button("다운로드 페이지 열기") == true)
			{
				ShellExecuteA(nullptr, nullptr, "https://github.com/Krappa322/arcdps_healing_stats/releases", nullptr, nullptr, SW_SHOW);
			}

			switch (state->UpdateStatus)
			{
			case UpdateChecker::Status::UpdateAvailable:
				if (ImGui::Button("자동 업데이트") == true)
				{
					GlobalObjects::UPDATE_CHECKER->PerformInstallOrUpdate(*state);
				}
				break;
			case UpdateChecker::Status::UpdateInProgress:
				ImGui::TextUnformatted("업데이트 중");
				break;
			case UpdateChecker::Status::UpdateSuccessful:
				ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), "업데이트 완료. 적용하려면 Guild Wars 2를 다시 시작하세요");
				break;
			case UpdateChecker::Status::UpdateError:
				ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "업데이트 중 오류가 발생했습니다");
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
