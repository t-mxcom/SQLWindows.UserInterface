#include <stdafx.h>
#include "Prof-UIS.h"

extern "C" __declspec(dllexport) int WINAPI UISalButtonGetTextAlignment(HWND buttonHandle)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		return extButton->GetTextAlignment();
	}

	return -1;
}

extern "C" __declspec(dllexport) int WINAPI UISalButtonSetTextAlignment(HWND buttonHandle, int alignment)
{
	// variables
	int previousAlignment = 0;

	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		// read previous alignment
		previousAlignment = extButton->GetTextAlignment();

#ifndef _TD51
		// reset text icon relation
		extButton->SetTextIconRelation(CExtPaintManager::__IMAGE_TEXT_RELATION_NOSET);
#endif

		extButton->SetTextAlignment(alignment);
	}

	return previousAlignment;
}

extern "C" __declspec(dllexport) int WINAPI UISalButtonGetIconAlignment(HWND buttonHandle)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		return extButton->GetIconAlignment();
	}

	return -1;
}

extern "C" __declspec(dllexport) int WINAPI UISalButtonSetIconAlignment(HWND buttonHandle, int alignment)
{
	// variables
	int previousAlignment = 0;

	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		// read previous alignment
		previousAlignment = extButton->GetIconAlignment();

#ifndef _TD51
		// reset text icon relation
		extButton->SetTextIconRelation(CExtPaintManager::__IMAGE_TEXT_RELATION_NOSET);
#endif

		extButton->SetIconAlignment(alignment);
	}

	return previousAlignment;
}

extern "C" __declspec(dllexport) void WINAPI UISalButtonSetTooltipText(HWND buttonHandle, LPCWSTR tooltipText)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		extButton->SetTooltipText(new CExtSafeString(tooltipText), TRUE);
	}

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalButtonEnableTooltip(HWND buttonHandle, BOOL enable)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		extButton->ActivateTooltip(enable);
	}

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalButtonSetCursor(HWND buttonHandle, int cursor)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		extButton->SetBtnCursor(cursor);
	}

	return;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalButtonGetDrawBorder(HWND buttonHandle)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		return extButton->GetDrawBorder();
	}

	return FALSE;
}

extern "C" __declspec(dllexport) void WINAPI UISalButtonSetDrawBorder(HWND buttonHandle, BOOL drawBorder)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		extButton->SetDrawBorder(drawBorder);
	}

	return;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalButtonGetDrawFocusRect(HWND buttonHandle)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		return extButton->GetDrawFocusRect();
	}

	return FALSE;
}

extern "C" __declspec(dllexport) void WINAPI UISalButtonSetDrawFocusRect(HWND buttonHandle, BOOL drawFocusRect)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		extButton->SetDrawFocusRect(drawFocusRect);
	}

	return;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalButtonGetTextColorDisabled(HWND buttonHandle)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		return extButton->GetTextColorDisabled();
	}

	return 0;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalButtonSetTextColorDisabled(HWND buttonHandle, COLORREF textColor)
{
	// variables
	COLORREF previousTextColor = 0;

	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		previousTextColor = extButton->GetTextColorDisabled();
		extButton->SetTextColorDisabled(textColor);
	}

	return previousTextColor;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalButtonGetTextColorNormal(HWND buttonHandle)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		return extButton->GetTextColorNormal();
	}

	return 0;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalButtonSetTextColorNormal(HWND buttonHandle, COLORREF textColor)
{
	// variables
	COLORREF previousTextColor = 0;

	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		previousTextColor = extButton->GetTextColorNormal();
		extButton->SetTextColorNormal(textColor);
	}

	return previousTextColor;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalButtonGetTextColorHover(HWND buttonHandle)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		return extButton->GetTextColorHover();
	}

	return 0;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalButtonSetTextColorHover(HWND buttonHandle, COLORREF textColor)
{
	// variables
	COLORREF previousTextColor = 0;

	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		previousTextColor = extButton->GetTextColorHover();
		extButton->SetTextColorHover(textColor);
	}

	return previousTextColor;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalButtonGetTextColorPressed(HWND buttonHandle)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		return extButton->GetTextColorPressed();
	}

	return 0;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalButtonSetTextColorPressed(HWND buttonHandle, COLORREF textColor)
{
	// variables
	COLORREF previousTextColor = 0;

	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		previousTextColor = extButton->GetTextColorPressed();
		extButton->SetTextColorPressed(textColor);
	}

	return previousTextColor;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalButtonGetBkColor(HWND buttonHandle)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		return extButton->GetBkColor();
	}

	return 0;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalButtonSetBkColor(HWND buttonHandle, COLORREF bkColor)
{
	// variables
	COLORREF previousBkColor = 0;

	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		previousBkColor = extButton->GetBkColor();
		extButton->SetBkColor(bkColor);
	}

	return previousBkColor;
}

extern "C" __declspec(dllexport) void WINAPI UISalButtonGetTextMargins(HWND buttonHandle, int* left, int* top, int* right, int* bottom)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		int marginLeft, marginTop, marginRight, marginBottom;
		extButton->GetTextMargins(marginLeft, marginTop, marginRight, marginBottom);

		// return margin values
		if (left != NULL) { (*left) = marginLeft; }
		if (top != NULL) { (*top) = marginTop; }
		if (right != NULL) { (*right) = marginRight; }
		if (bottom != NULL) { (*bottom) = marginBottom; }
	}

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalButtonSetTextMargins(HWND buttonHandle, int left, int top, int right, int bottom)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		extButton->SetTextMargins(left, top, right, bottom);
	}

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalButtonGetIconMargins(HWND buttonHandle, int* left, int* top, int* right, int* bottom)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		int marginLeft, marginTop, marginRight, marginBottom;
		extButton->GetIconMargins(marginLeft, marginTop, marginRight, marginBottom);

		// return margin values
		if (left != NULL) { (*left) = marginLeft; }
		if (top != NULL) { (*top) = marginTop; }
		if (right != NULL) { (*right) = marginRight; }
		if (bottom != NULL) { (*bottom) = marginBottom; }
	}

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalButtonSetIconMargins(HWND buttonHandle, int left, int top, int right, int bottom)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		extButton->SetIconMargins(left, top, right, bottom);
	}

	return;
}

extern "C" __declspec(dllexport) int WINAPI UISalButtonGetFocusMode(HWND buttonHandle)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		return extButton->GetFocusMode();
	}

	return -1;
}

extern "C" __declspec(dllexport) int WINAPI UISalButtonSetFocusMode(HWND buttonHandle, int focusMode)
{
	// variables
	int previousFocusMode = 0;

	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		previousFocusMode = extButton->GetFocusMode();
		extButton->SetFocusMode(focusMode);
	}

	return previousFocusMode;
}

extern "C" __declspec(dllexport) void WINAPI UISalButtonSetIcon(HWND buttonHandle, HICON iconIn, HICON iconOut, HICON iconDisabled, HICON iconPressed)
{
	// access button object
	CExtButton* extButton = (CExtButton*)CExtButton::FromHandlePermanent(buttonHandle);
	if (extButton != NULL)
	{
		extButton->SetIcon(iconIn, iconOut, iconDisabled, iconPressed);
	}

	return;
}
