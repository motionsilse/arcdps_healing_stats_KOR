#pragma once

#include <Windows.h>

namespace Localization
{
	void Load(HMODULE pModule);
	const char* Get(const char* pSection, const char* pKey, const char* pFallback);
	bool IsLoaded();
}
