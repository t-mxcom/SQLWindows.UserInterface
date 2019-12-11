#include "stdafx.h"
#include "Prof-UIS.h"

extern "C" __declspec(dllexport) HWND WINAPI UISalPropertyGridCreate(HWND parentWindow, UINT controlID, int x, int y, int width, int height, DWORD windowStyle, DWORD windowExStyle)
{
	// access parent window
	CWnd* parentWindowClass = NULL;
	if (parentWindow != NULL)
	{
		parentWindowClass = CWnd::FromHandlePermanent(parentWindow);
	}

	// create Property Grid
	CExtPropertyGridCtrl* propertyGrid = new CExtPropertyGridCtrl();
	windowStyle = ((windowStyle == 0) ? __EXT_PROPERTY_GRID_CTRL_WND_STYLES_DEFAULT : 0);
	windowExStyle = ((windowExStyle == 0) ? __EXT_PROPERTY_GRID_CTRL_WND_EX_STYLES_DEFAULT : 0);
	propertyGrid->Create(parentWindowClass, controlID, CRect(x, y, width, height), windowStyle, windowExStyle);

	return propertyGrid->GetSafeHwnd();
}
