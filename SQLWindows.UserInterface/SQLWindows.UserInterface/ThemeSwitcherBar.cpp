#include "stdafx.h"
#include "Prof-UIS.h"

extern "C" __declspec(dllexport) HANDLE WINAPI UISalThemeSwitcherBarCreate(HWND parentWindow)
{
	// create Theme Switcher Bar object
	CExtThemeSwitcherToolControlBar* themeSwitcherBar = new CExtThemeSwitcherToolControlBar();
	// themeSwitcherBar->m_bEnableOffice2007r3 = true;
	themeSwitcherBar->Create(NULL, CWnd::FromHandlePermanent(parentWindow));
	themeSwitcherBar->ThemeSwitcherInit();

	// send WM_SIZE to parent, so the bar gets visible
	RECT rect;
	::GetWindowRect(parentWindow, &rect);
	::SendMessage(parentWindow, WM_SIZE, SIZE_RESTORED, MAKELPARAM(rect.right - rect.left, rect.bottom - rect.top));

	// return object pointer as HANDLE
	return (HANDLE)themeSwitcherBar;
}

extern "C" __declspec(dllexport) void WINAPI UISalThemeSwitcherBarDestroy(HANDLE themeSwitcherBarHandle)
{
	// verify pointer
	if (themeSwitcherBarHandle != NULL)
	{
		// cast to object pointer and delete it
		CExtThemeSwitcherToolControlBar* themeSwitcherBar = (CExtThemeSwitcherToolControlBar*)themeSwitcherBarHandle;
		HWND parentWindow = themeSwitcherBar->GetParent()->m_hWnd;
		themeSwitcherBar->DestroyWindow();

		// send WM_SIZE to parent, so the bar gets updated
		RECT rect;
		::GetWindowRect(parentWindow, &rect);
		::SendMessage(parentWindow, WM_SIZE, SIZE_RESTORED, MAKELPARAM(rect.right - rect.left, rect.bottom - rect.top));
	}

	return;
}
