#pragma once

#include <direct.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>

struct AppEnv
{
	static TCHAR szAppPath[_MAX_PATH];
	static TCHAR szMediaPath[_MAX_PATH];
	static TCHAR szEngine[_MAX_PATH];
	static int	nThinkTime;

	static bool LoadEnv(TCHAR * szSettingFile);
	static TCHAR * GetMediaPath(TCHAR * szMediaFile);
};

