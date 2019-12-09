#if (!defined __SQLWINUI_UIEXTPROGRESSWND_H)
#define __SQLWINUI_UIEXTPROGRESSWND_H

#include "Prof-UIS.h"

#if (!defined __EXT_MFC_DEF_H)
	#include <ExtMfcDef.h>
#endif // __EXT_MFC_DEF_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//////////////////////////////////////////////////////////////////////////////
// CUIExtHyperLinkButton constants
#define	UIEXTHYPERLINKBUTTON_CLICK_CONTINUE		0	// continue handling the click
#define	UIEXTHYPERLINKBUTTON_CLICK_CANCEL		-1	// cancel handling the click

class CUIExtProgressWnd : public CExtProgressWnd
{
public:
	void SetColorProgressBarFrom(COLORREF color);
	COLORREF GetColorProgressBarFrom();
	void SetColorProgressBarTo(COLORREF color);
	COLORREF GetColorProgressBarTo();
	void SetColorBackgroundArea(COLORREF color);
	COLORREF GetColorBackgroundArea();
	void SetColorBorderLeftTop(COLORREF color);
	COLORREF GetColorBorderLeftTop();
	void SetColorBorderRightBottom(COLORREF color);
	COLORREF GetColorBorderRightBottom();
	void SetEnlightColorProgressBarFrom(double enlight);
	double GetEnlightColorProgressBarFrom();
	void SetEnlightColorProgressBarTo(double enlight);
	double GetEnlightColorProgressBarTo();
	void SetSizeBorderSpace(int x, int y);
	int GetSizeBorderSpaceX();
	int GetSizeBorderSpaceY();
	void SetSizeDistanceBetweenBlocks(int x, int y);
	int GetSizeDistanceBetweenBlocksX();
	int GetSizeDistanceBetweenBlocksY();
	void SetSizeBlockScaleFactorH(int x, int y);
	int GetSizeBlockScaleFactorHX();
	int GetSizeBlockScaleFactorHY();
	void SetSizeBlockScaleFactorV(int x, int y);
	int GetSizeBlockScaleFactorVX();
	int GetSizeBlockScaleFactorVY();
	void SetHasBorder(bool border);
	bool GetHasBorder();
	void SetHorizontalGradientBars(bool gradient);
	bool GetHorizontalGradientBars();
	void SetImmediateUpdating(bool updating);
	bool GetImmediateUpdating();
	void SetUsePaintManager(bool use);
	bool GetUsePaintManager();
}; // class CUIExtProgressWnd

#endif // (!defined __SQLWINUI_UIEXTPROGRESSWND_H)
