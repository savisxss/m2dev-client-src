#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>

extern "C" {

	inline int		WebBrowser_Startup(HINSTANCE hInstance) { return 0; }
	inline void	WebBrowser_Cleanup() {}
	inline void	WebBrowser_Destroy() {}
	inline int		WebBrowser_Show(HWND parent, const char* addr, const RECT* rcWebBrowser) { return 0; }
	inline void	WebBrowser_Hide() {}
	inline void	WebBrowser_Move(const RECT* rcWebBrowser) {}
	inline int WebBrowser_IsVisible() { return 0; }
	inline const RECT& WebBrowser_GetRect() { static RECT dummy; return dummy; }

}