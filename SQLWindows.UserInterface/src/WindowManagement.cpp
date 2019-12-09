#include "stdafx.h"
#include "Prof-UIS.h"

// forward declaration
HWND uiSalGetChildWindowWithIDOrClassName(HWND window, LONG id, LPCWSTR className);

extern "C" __declspec(dllexport) void WINAPI UISalSubclassChildWindows(HWND window)
{
	// let Prof-UI subclass all child windows
	SubclassChildControls(window);
}

extern "C" __declspec(dllexport) HWND WINAPI UISalGetMDIClient(HWND window)
{
	// find "MDIClient"
	return uiSalGetChildWindowWithIDOrClassName(window, 0xe900, L"MDIClient");
}

extern "C" __declspec(dllexport) HWND WINAPI UISalGetDockBarTop(HWND window)
{
	// find dock bar
	return uiSalGetChildWindowWithIDOrClassName(window, 0xe81b, NULL);
}

extern "C" __declspec(dllexport) HWND WINAPI UISalGetDockBarLeft(HWND window)
{
	// find dock bar
	return uiSalGetChildWindowWithIDOrClassName(window, 0xe81c, NULL);
}

extern "C" __declspec(dllexport) HWND WINAPI UISalGetDockBarRight(HWND window)
{
	// find dock bar
	return uiSalGetChildWindowWithIDOrClassName(window, 0xe81d, NULL);
}

extern "C" __declspec(dllexport) HWND WINAPI UISalGetDockBarBottom(HWND window)
{
	// find dock bar
	return uiSalGetChildWindowWithIDOrClassName(window, 0xe81e, NULL);
}

extern "C" __declspec(dllexport) HWND WINAPI UISalGetRibbonBar(HWND window)
{
	// step one, get top dock bar
	HWND dockBar = UISalGetDockBarTop(window);

	// step two, get control bar inside
	return uiSalGetChildWindowWithIDOrClassName(dockBar, 0xe805, NULL);
}

HWND uiSalGetChildWindowWithIDOrClassName(HWND window, LONG id, LPCWSTR className)
{
	// variables
	HWND child;

	// try to find window by id
	child = ::GetDlgItem(window, id);

	// if no window found, try by id
	if (child == NULL)
	{
		// find window by name
		HWND child = ::GetWindow(window, GW_CHILD);
		while (child != NULL)
		{
			// verify class name
			if (className != NULL)
			{
				// get classname of the window
				wchar_t windowClassName[MAX_PATH];
				::GetClassNameW(child, windowClassName, (int)_countof(windowClassName));
				if (_wcsicmp(windowClassName, className) == 0)
				{
					// window found
					break;
				}
			}

			// get next window
			child = ::GetWindow(child, GW_HWNDNEXT);
		}
	}

	return child;
}