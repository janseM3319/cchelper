// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MOUSEHOOK_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MOUSEHOOK_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MOUSEHOOK_EXPORTS
#define MOUSEHOOK_API __declspec(dllexport)
#else
#define MOUSEHOOK_API __declspec(dllimport)
#endif

// This class is exported from the mousehook.dll
class MOUSEHOOK_API CMouseHook {
public:
	static HMODULE  m_hModule;
	static HWND		m_hWnd;
	static HHOOK	m_hHook;
public:

	static LRESULT CALLBACK GetMsgProc(int nCode, WPARAM wParam, LPARAM lParam);

	//安装钩子函数  
	static BOOL   StartHook(HWND   hWnd);

	//卸载钩子函数 
	static BOOL   StopHook();
};
