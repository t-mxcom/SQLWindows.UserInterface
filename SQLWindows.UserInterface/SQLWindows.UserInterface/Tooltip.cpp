#include "stdafx.h"
#include "SQLWindows.UserInterface.h"
#include "Prof-UIS.h"

// constants
#define	UISAL_THEMEDTIP_OBJECT			L"SQLWindows.UserInterface|Themed Tip Object"

// declare global data
HWND	InitialTooltipControl = NULL;
WNDPROC	OriginalTooltipWndProc = NULL;

// forward declaration of functions
LRESULT CALLBACK uiSalTooltipWndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);
CExtPopupMenuTipWnd* uiSalGetThemedTip(HWND replacedTooltip);
void uiSalDestroyThemedTip(HWND replacedTooltip);

extern "C" __declspec(dllexport) BOOL WINAPI UISalTooltipEnableGlobalTheming()
{
	// if the global theming is already enabled, do nothing
	if ((::IsWindow(InitialTooltipControl)) && (!::IsBadCodePtr((FARPROC)OriginalTooltipWndProc)))
	{
		// global theming already enabled
		return TRUE;
	}

	// create initial tooltip control
	InitialTooltipControl = ::CreateWindowExW(NULL, TOOLTIPS_CLASSW, NULL,
		WS_POPUP | TTS_ALWAYSTIP,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL,
		Global_ModuleHandle, NULL);
	if (InitialTooltipControl == NULL)
	{
		// error creating initial tooltip control
		return FALSE;
	}

	// install the subclass
	OriginalTooltipWndProc = (WNDPROC)::GetClassLongPtrW(InitialTooltipControl, GCLP_WNDPROC);
	DWORD setClassLongResult = ::SetClassLongPtrW(InitialTooltipControl, GCLP_WNDPROC, (LONG)uiSalTooltipWndProc);

	return (setClassLongResult != 0);
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalTooltipDisableGlobalTheming()
{
	// if the global theming is already disabled, do nothing
	if ((!::IsWindow(InitialTooltipControl)) || (::IsBadCodePtr((FARPROC)OriginalTooltipWndProc)))
	{
		// global theming already disabled
		return TRUE;
	}

	// uninstall the subclass
	::SetClassLongPtrW(InitialTooltipControl, GCLP_WNDPROC, (LONG)OriginalTooltipWndProc);
	OriginalTooltipWndProc = NULL;

	// destroy initial tooltip control
	::DestroyWindow(InitialTooltipControl);
	InitialTooltipControl = NULL;

	return TRUE;
}

LRESULT CALLBACK uiSalTooltipWndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// variables
	LRESULT result = 0;
	CExtPopupMenuTipWnd* themedTip = NULL;

	// handle several messages
	switch (msg)
	{
	case WM_DESTROY:
		// destroy the assigned themed tip object
		uiSalDestroyThemedTip(wnd);
		break;
	}

	// call original window procedure
	if (OriginalTooltipWndProc != NULL)
	{
		result = ::CallWindowProcW(OriginalTooltipWndProc, wnd, msg, wParam, lParam);
	}
	else
	{
		result = ::DefWindowProcW(wnd, msg, wParam, lParam);
	}

	// handle several messages
	switch (msg)
	{
	case WM_MOVE:
		themedTip = uiSalGetThemedTip(wnd);
		if (themedTip != NULL)
		{
			themedTip->SetWindowPos(
				NULL,
				(int)(short) LOWORD(lParam),
				(int)(short) HIWORD(lParam),
				0, 0,
				SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
		}
		break;

	case WM_STYLECHANGING:
		// forward the changings to the themed tip
		themedTip = uiSalGetThemedTip(wnd);
		if (themedTip != NULL)
		{
			::SetWindowLongW(
				themedTip->GetSafeHwnd(),
				(int)wParam,
				((STYLESTRUCT*)lParam)->styleNew);
		}
		break;

	case WM_WINDOWPOSCHANGED:
	case WM_WINDOWPOSCHANGING:
		// forward the changings to the themed tip
		themedTip = uiSalGetThemedTip(wnd);
		if (themedTip != NULL)
		{
			// forward the window size and position
			WINDOWPOS* windowPos = (WINDOWPOS*)lParam;
			if (windowPos != NULL)
			{
				themedTip->SetWindowPos(
					NULL,
					windowPos->x, windowPos->y,
					windowPos->cx, windowPos->cy,
					windowPos->flags);
			}

			// if the window gets shown, get the text information
			if ((windowPos->flags & SWP_SHOWWINDOW) == SWP_SHOWWINDOW)
			{
				/*
				// get the text from the original tooltip
				LRESULT textSize = ::SendMessageW(wnd, WM_GETTEXTLENGTH, 0, 0) + 1;
				WCHAR* text = new WCHAR[textSize];
				::ZeroMemory(text, sizeof(WCHAR) * textSize);
				::SendMessageW(wnd, WM_GETTEXT, (WPARAM)textSize, (LPARAM)text);

				// set the text for the themed tip
				themedTip->SetText(text);

				// free the memory
				delete[] text;

				// show the themed tip
				RECT tipRect;
				::ZeroMemory(&tipRect, sizeof(tipRect));
				themedTip->Show(
					NULL,
					tipRect);
					*/
			}
			else if ((windowPos->flags & SWP_HIDEWINDOW) == SWP_HIDEWINDOW)
			{
				// hide the themed tip
				themedTip->Hide();
			}
		}
		break;

	case WM_PAINT:
		// tooltip painted itself, now transform our themed tip
		themedTip = uiSalGetThemedTip(wnd);
		if (themedTip != NULL)
		{
			// get the tooltip location and size
			RECT tipRect;
			::GetWindowRect(wnd, &tipRect);
			themedTip->MoveWindow(
				tipRect.left, tipRect.top,
				tipRect.right - tipRect.left, tipRect.bottom - tipRect.top);

			// get the text from the original tooltip
			LRESULT textSize = ::SendMessageW(wnd, WM_GETTEXTLENGTH, 0, 0) + 1;
			WCHAR* text = new WCHAR[textSize];
			::ZeroMemory(text, sizeof(WCHAR) * textSize);
			::SendMessageW(wnd, WM_GETTEXT, (WPARAM)textSize, (LPARAM)text);

			// set the text for the themed tip
			themedTip->SetText(text);

			// free the memory
			delete[] text;

			// show the themed tip
			::ZeroMemory(&tipRect, sizeof(tipRect));
			themedTip->Show(
				NULL,
				tipRect);
		}
		break;
	}

	return result;
}

CExtPopupMenuTipWnd* uiSalGetThemedTip(HWND replacedTooltip)
{
	// verify, if the tooltip already has a themed tip assigned
	CExtPopupMenuTipWnd* themedTip = (CExtPopupMenuTipWnd*)::GetPropW(replacedTooltip, UISAL_THEMEDTIP_OBJECT);
	if (themedTip == NULL)
	{
		// create a new object
		themedTip = new CExtPopupMenuTipWnd();
		themedTip->SetTipStyle(CExtPopupMenuTipWnd::__ETS_RECTANGLE_NO_ICON);
		themedTip->Hide();
		::SetPropW(replacedTooltip, UISAL_THEMEDTIP_OBJECT, (HANDLE)themedTip);
	}

	return themedTip;
}

void uiSalDestroyThemedTip(HWND replacedTooltip)
{
	// verify, if the tooltip already has a themed tip assigned
	CExtPopupMenuTipWnd* themedTip = uiSalGetThemedTip(replacedTooltip);
	if (themedTip != NULL)
	{
		// destroy the object
		delete themedTip;
		::SetPropW(replacedTooltip, UISAL_THEMEDTIP_OBJECT, (HANDLE)NULL);
	}
}
