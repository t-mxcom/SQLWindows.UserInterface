#include "stdafx.h"
#include "Prof-UIS.h"

extern "C" __declspec(dllexport) DWORD WINAPI UISalGroupBoxGetStyle(HWND groupBoxHandle)
{
	// get access to Group Box control
	CExtGroupBox* extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	if (extGroupBox == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(groupBoxHandle, CExtGroupBox);
		extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	}
	if (extGroupBox != NULL)
	{
		return (DWORD)extGroupBox->GetStyle();
	}

	return 0;
}

extern "C" __declspec(dllexport) DWORD WINAPI UISalGroupBoxSetStyle(HWND groupBoxHandle, DWORD style)
{
	// Variables
	DWORD previousStyle = 0;

	// get access to Group Box control
	CExtGroupBox* extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	if (extGroupBox == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(groupBoxHandle, CExtGroupBox);
		extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	}
	if (extGroupBox != NULL)
	{
		previousStyle = (DWORD)extGroupBox->GetStyle();
		extGroupBox->SetStyle((CExtGroupBox::e_style_t)style);
	}

	return previousStyle;
}

extern "C" __declspec(dllexport) int WINAPI UISalGroupBoxGetTextAlign(HWND groupBoxHandle)
{
	// get access to Group Box control
	CExtGroupBox* extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	if (extGroupBox == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(groupBoxHandle, CExtGroupBox);
		extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	}
	if (extGroupBox != NULL)
	{
		return (int)extGroupBox->GetTextAlign();
	}

	return 0;
}

extern "C" __declspec(dllexport) int WINAPI UISalGroupBoxSetTextAlign(HWND groupBoxHandle, int textAlign)
{
	// Variables
	int previousTextAlign = 0;

	// get access to Group Box control
	CExtGroupBox* extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	if (extGroupBox == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(groupBoxHandle, CExtGroupBox);
		extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	}
	if (extGroupBox != NULL)
	{
		previousTextAlign = (int)extGroupBox->GetTextAlign();
		extGroupBox->SetTextAlign((CExtGroupBox::e_text_align_t)textAlign);
	}

	return previousTextAlign;
}

extern "C" __declspec(dllexport) int WINAPI UISalGroupBoxGetCaptionHeaderHeight(HWND groupBoxHandle)
{
	// get access to Group Box control
	CExtGroupBox* extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	if (extGroupBox == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(groupBoxHandle, CExtGroupBox);
		extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	}
	if (extGroupBox != NULL)
	{
		return extGroupBox->GetCaptionHeaderHeight();
	}

	return 0;
}

extern "C" __declspec(dllexport) int WINAPI UISalGroupBoxSetCaptionHeaderHeight(HWND groupBoxHandle, int captionHeaderHeight)
{
	// Variables
	DWORD previousCaptionHeaderHeight = 0;

	// get access to Group Box control
	CExtGroupBox* extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	if (extGroupBox == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(groupBoxHandle, CExtGroupBox);
		extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	}
	if (extGroupBox != NULL)
	{
		previousCaptionHeaderHeight = extGroupBox->GetCaptionHeaderHeight();
		extGroupBox->SetCaptionHeaderHeight(captionHeaderHeight);
	}

	return previousCaptionHeaderHeight;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalGroupBoxGetBkColor(HWND groupBoxHandle)
{
	// get access to Group Box control
	CExtGroupBox* extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	if (extGroupBox == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(groupBoxHandle, CExtGroupBox);
		extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	}
	if (extGroupBox != NULL)
	{
		return extGroupBox->GetBkColor();
	}

	return (COLORREF)-1;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalGroupBoxSetBkColor(HWND groupBoxHandle, COLORREF bkColor)
{
	// Variables
	COLORREF previousBkColor = 0;

	// get access to Group Box control
	CExtGroupBox* extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	if (extGroupBox == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(groupBoxHandle, CExtGroupBox);
		extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	}
	if (extGroupBox != NULL)
	{
		previousBkColor = extGroupBox->GetBkColor();
		extGroupBox->SetBkColor(bkColor);
	}

	return previousBkColor;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalGroupBoxGetTextColor(HWND groupBoxHandle, BOOL enabled)
{
	// get access to Group Box control
	CExtGroupBox* extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	if (extGroupBox == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(groupBoxHandle, CExtGroupBox);
		extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	}
	if (extGroupBox != NULL)
	{
		return extGroupBox->GetTextColor(enabled);
	}

	return (COLORREF)-1;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalGroupBoxSetTextColor(HWND groupBoxHandle, BOOL enabled, COLORREF textColor)
{
	// Variables
	COLORREF previousTextColor = 0;

	// get access to Group Box control
	CExtGroupBox* extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	if (extGroupBox == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(groupBoxHandle, CExtGroupBox);
		extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	}
	if (extGroupBox != NULL)
	{
		previousTextColor = extGroupBox->GetTextColor(enabled);
		extGroupBox->SetTextColor(textColor, enabled);
	}

	return previousTextColor;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalGroupBoxGetFrameColor(HWND groupBoxHandle, BOOL enabled)
{
	// get access to Group Box control
	CExtGroupBox* extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	if (extGroupBox == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(groupBoxHandle, CExtGroupBox);
		extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	}
	if (extGroupBox != NULL)
	{
		return extGroupBox->GetFrameColor(enabled);
	}

	return (COLORREF)-1;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalGroupBoxSetFrameColor(HWND groupBoxHandle, BOOL enabled, COLORREF frameColor)
{
	// Variables
	COLORREF previousTextColor = 0;

	// get access to Group Box control
	CExtGroupBox* extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	if (extGroupBox == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(groupBoxHandle, CExtGroupBox);
		extGroupBox = (CExtGroupBox*)CExtGroupBox::FromHandlePermanent(groupBoxHandle);
	}
	if (extGroupBox != NULL)
	{
		previousTextColor = extGroupBox->GetFrameColor(enabled);
		extGroupBox->SetFrameColor(frameColor, enabled);
	}

	return previousTextColor;
}

