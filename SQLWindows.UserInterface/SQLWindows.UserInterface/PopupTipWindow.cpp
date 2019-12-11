#include "stdafx.h"
#include "Prof-UIS.h"

extern "C" __declspec(dllexport) HANDLE WINAPI UISalPopupTipWindowCreate(LPCWSTR text, HICON icon, int style)
{
	// create a new popup window
	CExtPopupMenuTipWnd* popupMenuTipWindow = new CExtPopupMenuTipWnd();

	// if passed, set additional data
	if (text != NULL)
	{
		popupMenuTipWindow->SetText(text);
	}
	if (icon != NULL)
	{
		popupMenuTipWindow->SetIcon(icon);
	}
	if (style != 0)
	{
		popupMenuTipWindow->SetTipStyle((CExtPopupMenuTipWnd::e_tip_style_t)style);
	}

	return (HANDLE)popupMenuTipWindow;
}

extern "C" __declspec(dllexport) void WINAPI UISalPopupTipWindowDestroy(HANDLE popupTipWindow)
{
	// access popup tip window
	CExtPopupMenuTipWnd* popupMenuTipWindow = (CExtPopupMenuTipWnd*)popupTipWindow;

	// destroy the object
	delete popupMenuTipWindow;

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalPopupTipWindowGetText(HANDLE popupTipWindow, LPWSTR text, DWORD textSize)
{
	// access popup tip window
	CExtPopupMenuTipWnd* popupMenuTipWindow = (CExtPopupMenuTipWnd*)popupTipWindow;

	// get text
	__EXT_MFC_SAFE_LPCTSTR tipText = popupMenuTipWindow->GetText();
	wcscpy_s(text, textSize, tipText);

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalPopupTipWindowSetText(HANDLE popupTipWindow, LPCWSTR text)
{
	// access popup tip window
	CExtPopupMenuTipWnd* popupMenuTipWindow = (CExtPopupMenuTipWnd*)popupTipWindow;

	// set text
	popupMenuTipWindow->SetText(text);

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalPopupTipWindowSetIcon(HANDLE popupTipWindow, HICON icon)
{
	// access popup tip window
	CExtPopupMenuTipWnd* popupMenuTipWindow = (CExtPopupMenuTipWnd*)popupTipWindow;

	// set icon
	popupMenuTipWindow->SetIcon(icon);

	return;
}

extern "C" __declspec(dllexport) int WINAPI UISalPopupTipWindowGetTipStyle(HANDLE popupTipWindow)
{
	// access popup tip window
	CExtPopupMenuTipWnd* popupMenuTipWindow = (CExtPopupMenuTipWnd*)popupTipWindow;

	// get style
	return (int)popupMenuTipWindow->GetTipStyle();
}

extern "C" __declspec(dllexport) int WINAPI UISalPopupTipWindowSetTipStyle(HANDLE popupTipWindow, int style)
{
	// variables
	int previousStyle = 0;

	// access popup tip window
	CExtPopupMenuTipWnd* popupMenuTipWindow = (CExtPopupMenuTipWnd*)popupTipWindow;

	// get and set style
	previousStyle = (int)popupMenuTipWindow->GetTipStyle();
	popupMenuTipWindow->SetTipStyle((CExtPopupMenuTipWnd::e_tip_style_t)style);

	return previousStyle;
}

extern "C" __declspec(dllexport) int WINAPI UISalPopupTipWindowGetShadowSize(HANDLE popupTipWindow)
{
	// access popup tip window
	CExtPopupMenuTipWnd* popupMenuTipWindow = (CExtPopupMenuTipWnd*)popupTipWindow;

	// get shadow size
	return popupMenuTipWindow->GetShadowSize();
}

extern "C" __declspec(dllexport) int WINAPI UISalPopupTipWindowSetShadowSize(HANDLE popupTipWindow, int shadowSize)
{
	// variables
	int previousShadowSize = 0;

	// access popup tip window
	CExtPopupMenuTipWnd* popupMenuTipWindow = (CExtPopupMenuTipWnd*)popupTipWindow;

	// get and set shadow size
	previousShadowSize = popupMenuTipWindow->GetShadowSize();
	popupMenuTipWindow->SetShadowSize(shadowSize);

	return previousShadowSize;
}

extern "C" __declspec(dllexport) void WINAPI UISalPopupTipWindowShow(HANDLE popupTipWindow, HWND parentWindow, int x, int y, int width, int height, BOOL noDelay)
{
	// access popup tip window
	CExtPopupMenuTipWnd* popupMenuTipWindow = (CExtPopupMenuTipWnd*)popupTipWindow;

	// get object for parent window
	CWnd* parentWindowObject = CWnd::FromHandlePermanent(parentWindow);

	// auto detect rectangle for exclusion
	CRect rectObject(x, y, x + width, y + height);
	if ((x == 0) && (y == 0) && (width == 0) && (height == 0))
	{
		parentWindowObject->GetWindowRect(rectObject);
	}

	// show the tip window
	popupMenuTipWindow->Show(CWnd::FromHandlePermanent(parentWindow), rectObject, noDelay);

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalPopupTipWindowHide(HANDLE popupTipWindow)
{
	// access popup tip window
	CExtPopupMenuTipWnd* popupMenuTipWindow = (CExtPopupMenuTipWnd*)popupTipWindow;

	// hide the tip window
	popupMenuTipWindow->Hide();

	return;
}
