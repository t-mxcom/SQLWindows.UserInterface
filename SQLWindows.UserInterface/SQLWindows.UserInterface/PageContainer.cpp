#include "stdafx.h"
#include "Prof-UIS.h"

extern "C" __declspec(dllexport) HWND WINAPI UISalPageContainerCreate(HWND parentWindow, UINT controlID, int x, int y, int width, int height, DWORD pageContainerStyle, DWORD windowStyle)
{
	// access parent window
	CWnd* parentWindowClass = NULL;
	if (parentWindow != NULL)
	{
		parentWindowClass = CWnd::FromHandlePermanent(parentWindow);
	}

	// create Page Container
	CExtPageContainerWnd* pageContainer = new CExtPageContainerWnd();
	pageContainerStyle = ((pageContainerStyle == 0) ? __EPCWS_STYLES_DEFAULT : 0);
	windowStyle = ((windowStyle == 0) ? WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS : 0);
	pageContainer->Create(parentWindowClass, controlID, CRect(x, y, width, height), pageContainerStyle, windowStyle, NULL);

	// test
	/*
	if (pageContainer != NULL)
	{
		HWND page = NULL;
		pageContainer->PageInsert(page, -1, L"Page 1", NULL, false, 0, true, false, false);
		pageContainer->PageInsert(page, -1, L"Page 2", NULL, false, 0, false, false, false);
		pageContainer->PageInsert(page, -1, L"Page 3", NULL, false, 0, false, false, true);
	}
	*/

	return ((pageContainer == NULL) ? NULL : pageContainer->GetSafeHwnd());
}
