#include "stdafx.h"
#include "Prof-UIS.h"
#include "CUIExtProgressWnd.h"

extern "C" __declspec(dllexport) HWND WINAPI UISalProgressBarCreate(HWND parentWindow, UINT controlID, int x, int y, int width, int height, DWORD windowStyle)
{
	// get parent window
	CWnd* parentWindowClass = NULL;
	if (parentWindow != NULL)
	{
		parentWindowClass = CWnd::FromHandlePermanent(parentWindow);
	}

	// create ProgressBar
	RECT rect;
	rect.left = x;
	rect.top = y;
	rect.right = x + width;
	rect.bottom = y + height;
	windowStyle = ((windowStyle == 0) ? WS_CHILD | WS_VISIBLE : windowStyle);
	CUIExtProgressWnd* progressWnd = new CUIExtProgressWnd();
	progressWnd->Create(windowStyle, rect, parentWindowClass, controlID);

	return progressWnd->GetSafeHwnd();
}

// default CProgressCtrl functions
extern "C" __declspec(dllexport) int WINAPI UISalProgressBarGetPos(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetPos();
	}

	return -1;
}

extern "C" __declspec(dllexport) void WINAPI UISalProgressBarGetRange(HWND progressBarHandle, int* lower, int* upper)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		int barLower = 0, barUpper = 0;
		progressWnd->GetRange(barLower, barUpper);
		
		if (lower != NULL)
		{
			(*lower) = barLower;
		}
		if (upper != NULL)
		{
			(*upper) = barUpper;
		}
	}

	return;
}

extern "C" __declspec(dllexport) int WINAPI UISalProgressBarOffsetPos(HWND progressBarHandle, int pos)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->OffsetPos(pos);
	}

	return -1;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalProgressBarSetBkColor(HWND progressBarHandle, COLORREF color)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->SetBkColor(color);
	}

	return -1;
}

extern "C" __declspec(dllexport) int WINAPI UISalProgressBarSetPos(HWND progressBarHandle, int pos)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->SetPos(pos);
	}

	return -1;
}

extern "C" __declspec(dllexport) void WINAPI UISalProgressBarSetRange(HWND progressBarHandle, short lower, short upper)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		progressWnd->SetRange(lower, upper);
	}

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalProgressBarSetRange32(HWND progressBarHandle, int lower, int upper)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		progressWnd->SetRange32(lower, upper);
	}

	return;
}

extern "C" __declspec(dllexport) int WINAPI UISalProgressBarSetStep(HWND progressBarHandle, int step)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->SetStep(step);
	}

	return -1;
}

extern "C" __declspec(dllexport) int WINAPI UISalProgressBarStepIt(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->StepIt();
	}

	return -1;
}

// additional CUIExtProgressWnd functions
extern "C" __declspec(dllexport) COLORREF UISalProgressBarSetColorProgressBarFrom(HWND progressBarHandle, COLORREF color)
{
	// access ProgressBar
	COLORREF previousColor = -1;
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		// query previous color
		previousColor = progressWnd->GetColorProgressBarFrom();
		progressWnd->SetColorProgressBarFrom(color);
	}

	return previousColor;
}

extern "C" __declspec(dllexport) COLORREF UISalProgressBarGetColorProgressBarFrom(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetColorProgressBarFrom();
	}

	return -1;
}

extern "C" __declspec(dllexport) COLORREF UISalProgressBarSetColorProgressBarTo(HWND progressBarHandle, COLORREF color)
{
	// access ProgressBar
	COLORREF previousColor = -1;
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		// query previous color
		previousColor = progressWnd->GetColorProgressBarTo();
		progressWnd->SetColorProgressBarTo(color);
	}

	return previousColor;
}

extern "C" __declspec(dllexport) COLORREF UISalProgressBarGetColorProgressBarTo(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetColorProgressBarTo();
	}

	return -1;
}

extern "C" __declspec(dllexport) COLORREF UISalProgressBarSetColorBackgroundArea(HWND progressBarHandle, COLORREF color)
{
	// access ProgressBar
	COLORREF previousColor = -1;
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		// query previous color
		previousColor = progressWnd->GetColorBackgroundArea();
		progressWnd->SetColorBackgroundArea(color);
	}

	return previousColor;
}

extern "C" __declspec(dllexport) COLORREF UISalProgressBarGetColorBackgroundArea(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetColorBackgroundArea();
	}

	return -1;
}

extern "C" __declspec(dllexport) COLORREF UISalProgressBarSetColorBorderLeftTop(HWND progressBarHandle, COLORREF color)
{
	// access ProgressBar
	COLORREF previousColor = -1;
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		// query previous color
		previousColor = progressWnd->GetColorBorderLeftTop();
		progressWnd->SetColorBorderLeftTop(color);
	}

	return previousColor;
}

extern "C" __declspec(dllexport) COLORREF UISalProgressBarGetColorBorderLeftTop(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetColorBorderLeftTop();
	}

	return -1;
}

extern "C" __declspec(dllexport) COLORREF UISalProgressBarSetColorBorderRightBottom(HWND progressBarHandle, COLORREF color)
{
	// access ProgressBar
	COLORREF previousColor = -1;
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		// query previous color
		previousColor = progressWnd->GetColorBorderRightBottom();
		progressWnd->SetColorBorderRightBottom(color);
	}

	return previousColor;
}

extern "C" __declspec(dllexport) COLORREF UISalProgressBarGetColorBorderRightBottom(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetColorBorderRightBottom();
	}

	return -1;
}

extern "C" __declspec(dllexport) double UISalProgressBarSetEnlightColorProgressBarFrom(HWND progressBarHandle, double enlight)
{
	// access ProgressBar
	double previousEnlight = -1;
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		// query previous enlightment
		previousEnlight = progressWnd->GetEnlightColorProgressBarFrom();
		progressWnd->SetEnlightColorProgressBarFrom(enlight);
	}

	return previousEnlight;
}

extern "C" __declspec(dllexport) double UISalProgressBarGetEnlightColorProgressBarFrom(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetEnlightColorProgressBarFrom();
	}

	return -1;
}

extern "C" __declspec(dllexport) double UISalProgressBarSetEnlightColorProgressBarTo(HWND progressBarHandle, double enlight)
{
	// access ProgressBar
	double previousEnlight = -1;
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		// query previous enlightment
		previousEnlight = progressWnd->GetEnlightColorProgressBarTo();
		progressWnd->SetEnlightColorProgressBarTo(enlight);
	}

	return previousEnlight;
}

extern "C" __declspec(dllexport) double UISalProgressBarGetEnlightColorProgressBarTo(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetEnlightColorProgressBarTo();
	}

	return -1;
}

extern "C" __declspec(dllexport) void UISalProgressBarSetSizeBorderSpace(HWND progressBarHandle, int x, int y)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		progressWnd->SetSizeBorderSpace(x, y);
	}
}

extern "C" __declspec(dllexport) int UISalProgressBarGetSizeBorderSpaceX(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetSizeBorderSpaceX();
	}

	return -1;
}

extern "C" __declspec(dllexport) int UISalProgressBarGetSizeBorderSpaceY(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetSizeBorderSpaceY();
	}

	return -1;
}

extern "C" __declspec(dllexport) void UISalProgressBarSetSizeDistanceBetweenBlocks(HWND progressBarHandle, int x, int y)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		progressWnd->SetSizeDistanceBetweenBlocks(x, y);
	}
}

extern "C" __declspec(dllexport) int UISalProgressBarGetSizeDistanceBetweenBlocksX(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetSizeDistanceBetweenBlocksX();
	}

	return -1;
}

extern "C" __declspec(dllexport) int UISalProgressBarGetSizeDistanceBetweenBlocksY(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetSizeDistanceBetweenBlocksY();
	}

	return -1;
}

extern "C" __declspec(dllexport) void UISalProgressBarSetSizeBlockScaleFactorH(HWND progressBarHandle, int x, int y)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		progressWnd->SetSizeBlockScaleFactorH(x, y);
	}
}

extern "C" __declspec(dllexport) int UISalProgressBarGetSizeBlockScaleFactorHX(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetSizeBlockScaleFactorHX();
	}

	return -1;
}

extern "C" __declspec(dllexport) int UISalProgressBarGetSizeBlockScaleFactorHY(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetSizeBlockScaleFactorHY();
	}

	return -1;
}

extern "C" __declspec(dllexport) void UISalProgressBarSetSizeBlockScaleFactorV(HWND progressBarHandle, int x, int y)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		progressWnd->SetSizeBorderSpace(x, y);
	}
}

extern "C" __declspec(dllexport) int UISalProgressBarGetSizeBlockScaleFactorVX(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetSizeBlockScaleFactorVX();
	}

	return -1;
}

extern "C" __declspec(dllexport) int UISalProgressBarGetSizeBlockScaleFactorVY(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetSizeBlockScaleFactorVY();
	}

	return -1;
}

extern "C" __declspec(dllexport) BOOL UISalProgressBarSetHasBorder(HWND progressBarHandle, BOOL border)
{
	// access ProgressBar
	bool previousBorder = false;
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		// query previous border
		previousBorder = progressWnd->GetHasBorder();
		progressWnd->SetHasBorder(border);
	}

	return (BOOL)previousBorder;
}

extern "C" __declspec(dllexport) BOOL UISalProgressBarGetHasBorder(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetHasBorder();
	}

	return FALSE;
}

extern "C" __declspec(dllexport) BOOL UISalProgressBarSetHorizontalGradientBars(HWND progressBarHandle, BOOL gradient)
{
	// access ProgressBar
	bool previousGradient = false;
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		// query previous gradient
		previousGradient = progressWnd->GetHorizontalGradientBars();
		progressWnd->SetHorizontalGradientBars(gradient);
	}

	return (BOOL)previousGradient;
}

extern "C" __declspec(dllexport) BOOL UISalProgressBarGetHorizontalGradientBars(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetHorizontalGradientBars();
	}

	return FALSE;
}

extern "C" __declspec(dllexport) BOOL UISalProgressBarSetImmediateUpdating(HWND progressBarHandle, BOOL updating)
{
	// access ProgressBar
	bool previousUpdating = false;
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		// query previous updating
		previousUpdating = progressWnd->GetImmediateUpdating();
		progressWnd->SetImmediateUpdating(updating);
	}

	return (BOOL)previousUpdating;
}

extern "C" __declspec(dllexport) BOOL UISalProgressBarGetImmediateUpdating(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetImmediateUpdating();
	}

	return FALSE;
}

extern "C" __declspec(dllexport) BOOL UISalProgressBarSetUsePaintManager(HWND progressBarHandle, BOOL use)
{
	// access ProgressBar
	bool previousUse = false;
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		// query previous use of paint manager
		previousUse = progressWnd->GetUsePaintManager();
		progressWnd->SetUsePaintManager(use);
	}

	return (BOOL)previousUse;
}

extern "C" __declspec(dllexport) BOOL UISalProgressBarGetUsePaintManager(HWND progressBarHandle)
{
	// access ProgressBar
	CUIExtProgressWnd* progressWnd = (CUIExtProgressWnd*)CUIExtProgressWnd::FromHandlePermanent(progressBarHandle);
	if (progressWnd != NULL)
	{
		return progressWnd->GetUsePaintManager();
	}

	return FALSE;
}
