// mousehook.cpp : Defines the exported functions for the DLL application.
//

#include <windows.h>
#include "mousehook.h"
#include "log.h"
#include <tchar.h>

#pragma data_seg(".JOE")
void * g_pShareData = NULL;
#pragma data_seg()
#pragma comment(linker, "/section:.JOE,rws")

HMODULE CMouseHook::m_hModule = NULL;
HHOOK   CMouseHook::m_hHook	= NULL;
HWND	CMouseHook::m_hWnd	= NULL;

void ErrorMsg()
{
	LPVOID lpMsgBuf;

	FormatMessage(

		FORMAT_MESSAGE_ALLOCATE_BUFFER |

		FORMAT_MESSAGE_FROM_SYSTEM |

		FORMAT_MESSAGE_IGNORE_INSERTS,

		NULL,

		GetLastError(),

		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // 既定の言語

		(LPTSTR) &lpMsgBuf,

		0,

		NULL

	);

	// lpMsgBuf 内のすべての挿入シーケンスを処理する。

	// ...

	// 文字列を表示する。

	MessageBox(NULL, (LPCTSTR)lpMsgBuf, _T("Error"), MB_OK | MB_ICONINFORMATION);

	// バッファを解放する。

	LocalFree(lpMsgBuf);

}

LRESULT CALLBACK CMouseHook::GetMsgProc(int nCode,
    WPARAM wParam,
    LPARAM lParam
)
{
    if(nCode < 0)
	{	/* pass it on */
		 CallNextHookEx(m_hHook, nCode, wParam, lParam);
		 return 0;
	} /* pass it on */
	
	LPMSG msg = (LPMSG)lParam;
	OutputDebugString(_T("test..."));
	if(msg->hwnd == m_hWnd )
		return 0;
     
	 return CallNextHookEx(m_hHook, nCode, wParam, lParam);
} // msghook


BOOL CMouseHook::StartHook(HWND   hWnd)
{
     m_hHook = SetWindowsHookEx(WH_GETMESSAGE,
			    (HOOKPROC)GetMsgProc,
			    GetModuleHandle(NULL),
			    0);

	if( m_hHook )
	{
		m_hWnd = hWnd;
		StopHook();
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL  CMouseHook::StopHook()
{
	if(m_hHook && UnhookWindowsHookEx(m_hHook))
	{
		m_hHook = NULL;
		m_hWnd = NULL;
		return TRUE;
	} else
	{
		 ErrorMsg();
	}
	return FALSE;
}