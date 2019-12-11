#include "stdafx.h"
#include "Prof-UIS.h"

CExtStatusControlBar* uiSalGetStatusBarObject(HWND statusBarContainingWindowHandle);

extern "C" __declspec(dllexport) BOOL WINAPI UISalStatusBarAddPane(HWND statusBarContainingWindowHandle, UINT id, int index)
{
	// get object first
	CExtStatusControlBar* statusBar = uiSalGetStatusBarObject(statusBarContainingWindowHandle);
	if (statusBar != NULL)
	{
		// add pane
		BOOL result = (BOOL)statusBar->AddPane(id, index);
		statusBar->SetPaneText(0, L"Das ist ein Test", TRUE);
		statusBar->WidthFromContent(0);
		statusBar->SetTipText(0, L"Das ist der Tooltip");
		statusBar->AddPane(id + 1, index + 2);
		statusBar->SetPaneBackgroundAccent(index + 3, CExtStatusControlBar::__ESPBA_DARK);
		statusBar->SetPaneTextColor(index + 2, TRUE, RGB(255, 255, 0));
		statusBar->SetPaneBkColor(index + 2, RGB(0, 0, 100));
		return result;
	}

	return FALSE;
}

CExtStatusControlBar* uiSalGetStatusBarObject(HWND statusBarContainingWindowHandle)
{
	// see, if the status bar is a child of the window
	HWND statusBar = ::GetDlgItem(statusBarContainingWindowHandle, 0x7ff1);
	if (statusBar == NULL)
	{
		// try with parent window
		statusBarContainingWindowHandle = ::GetAncestor(statusBarContainingWindowHandle, GA_PARENT);
		statusBar = ::GetDlgItem(statusBarContainingWindowHandle, 0x7ff1);
	}

	// now get the object if possible
	if (statusBar != NULL)
	{
		// return object
		return (CExtStatusControlBar*)CExtStatusControlBar::FromHandlePermanent(statusBar);
	}

	return NULL;
}