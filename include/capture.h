#pragma once

#include <windows.h>
#include <D3D9.h>
#include <D3dx9tex.h>

class ScreenCapture
{
	DWORD m_dwDisplayModeFormat;

public:

	DWORD GetDisplayModeFormat(){ return m_dwDisplayModeFormat; }

	HRESULT CaptureByD3D(HWND hWnd, LPCSTR szFileName);

	HRESULT CaptureByD3D(HWND hWnd, LPBYTE * pData);

};

namespace capture
{
	unsigned int GetWindowKey(HWND hwnd);
};