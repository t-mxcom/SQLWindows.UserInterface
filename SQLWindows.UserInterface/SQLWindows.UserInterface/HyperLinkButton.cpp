#include "stdafx.h"
#include "Prof-UIS.h"
#include "CUIExtHyperLinkButton.h"

extern "C" __declspec(dllexport) HWND WINAPI UISalHyperLinkButtonCreate(HWND parentWindow, HWND messageWindow, UINT message, UINT controlID, int x, int y, int width, int height, DWORD windowStyle, LPCWSTR title, LPCWSTR url)
{
	// access parent window
	CWnd* parentWindowClass = NULL;
	if (parentWindow != NULL)
	{
		parentWindowClass = CWnd::FromHandlePermanent(parentWindow);
	}

	// create Hyper Link Button
	RECT rect;
	rect.left = x;
	rect.top = y;
	rect.right = x + width;
	rect.bottom = y + height;
	windowStyle = ((windowStyle == 0) ? WS_CHILD | WS_VISIBLE : 0);
	CUIExtHyperLinkButton* hyperLinkButton = new CUIExtHyperLinkButton(messageWindow, message, controlID);
	hyperLinkButton->Create(title, windowStyle, rect, parentWindowClass, controlID);
	hyperLinkButton->m_strURL.SetString(url);

	return hyperLinkButton->GetSafeHwnd();
}
 
extern "C" __declspec(dllexport) COLORREF WINAPI UISalHyperLinkButtonGetTextColorVisited(HWND hyperLinkButtonHandle)
{
	// access Hyper Link Button
	CUIExtHyperLinkButton* extButton = (CUIExtHyperLinkButton*)CUIExtHyperLinkButton::FromHandlePermanent(hyperLinkButtonHandle);
	if (extButton != NULL)
	{
		return extButton->GetTextColorVisited();
	}

	return -1;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalHyperLinkButtonSetTextColorVisited(HWND hyperLinkButtonHandle, COLORREF textColorVisited)
{
	// variables
	COLORREF previousTextColorVisited = 0;

	// access Hyper Link Button
	CUIExtHyperLinkButton* extButton = (CUIExtHyperLinkButton*)CUIExtHyperLinkButton::FromHandlePermanent(hyperLinkButtonHandle);
	if (extButton != NULL)
	{
		// get previous text color
		previousTextColorVisited = extButton->GetTextColorVisited();
		extButton->m_bAllowVisited = TRUE;
		extButton->SetTextColorVisited(textColorVisited);
	}

	return previousTextColorVisited;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalHyperLinkButtonGetTextUnderline(HWND hyperLinkButtonHandle)
{
	// access Hyper Link Button
	CUIExtHyperLinkButton* extButton = (CUIExtHyperLinkButton*)CUIExtHyperLinkButton::FromHandlePermanent(hyperLinkButtonHandle);
	if (extButton != NULL)
	{
		return extButton->GetTextUnderline();
	}

	return -1;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalHyperLinkButtonSetTextUnderline(HWND hyperLinkButtonHandle, BOOL textUnderline)
{
	// variables
	BOOL previousTextUnderline = FALSE;

	// access Hyper Link Button
	CUIExtHyperLinkButton* extButton = (CUIExtHyperLinkButton*)CUIExtHyperLinkButton::FromHandlePermanent(hyperLinkButtonHandle);
	if (extButton != NULL)
	{
		// get previous text underline
		previousTextUnderline = extButton->GetTextUnderline();
		extButton->SetTextUnderline(textUnderline);
	}

	return previousTextUnderline;
}
