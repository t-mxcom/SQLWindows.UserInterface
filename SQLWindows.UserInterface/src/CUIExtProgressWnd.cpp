#include "stdafx.h"

#if (!defined __SQLWINUI_UIEXTPROGRESSWND_H)
	#include "CUIExtProgressWnd.h"
#endif

void CUIExtProgressWnd::SetColorProgressBarFrom(COLORREF color)
{
	m_clrProgressBarFrom = color;
}
COLORREF CUIExtProgressWnd::GetColorProgressBarFrom()
{
	return m_clrProgressBarFrom;
}
void CUIExtProgressWnd::SetColorProgressBarTo(COLORREF color)
{
	m_clrProgressBarTo = color;
}
COLORREF CUIExtProgressWnd::GetColorProgressBarTo()
{
	return m_clrProgressBarTo;
}
void CUIExtProgressWnd::SetColorBackgroundArea(COLORREF color)
{
	m_clrBackgroundArea = color;
}
COLORREF CUIExtProgressWnd::GetColorBackgroundArea()
{
	return m_clrBackgroundArea;
}
void CUIExtProgressWnd::SetColorBorderLeftTop(COLORREF color)
{
	m_clrBorderLT = color;
}
COLORREF CUIExtProgressWnd::GetColorBorderLeftTop()
{
	return m_clrBorderLT;
}
void CUIExtProgressWnd::SetColorBorderRightBottom(COLORREF color)
{
	m_clrBorderRB = color;
}
COLORREF CUIExtProgressWnd::GetColorBorderRightBottom()
{
	return m_clrBorderRB;
}
void CUIExtProgressWnd::SetEnlightColorProgressBarFrom(double enlight)
{
	m_lfEnlightClrProgressBarFrom = enlight;
}
double CUIExtProgressWnd::GetEnlightColorProgressBarFrom()
{
	return m_lfEnlightClrProgressBarFrom;
}
void CUIExtProgressWnd::SetEnlightColorProgressBarTo(double enlight)
{
	m_lfEnlightClrProgressBarTo = enlight;
}
double CUIExtProgressWnd::GetEnlightColorProgressBarTo()
{
	return m_lfEnlightClrProgressBarTo;
}
void CUIExtProgressWnd::SetSizeBorderSpace(int x, int y)
{
	m_sizeBorderSpace.cx = x;
	m_sizeBorderSpace.cy = y;
}
int CUIExtProgressWnd::GetSizeBorderSpaceX()
{
	return m_sizeBorderSpace.cx;
}
int CUIExtProgressWnd::GetSizeBorderSpaceY()
{
	return m_sizeBorderSpace.cy;
}
void CUIExtProgressWnd::SetSizeDistanceBetweenBlocks(int x, int y)
{
	m_sizeDistanceBetweenBlocks.cx = x;
	m_sizeDistanceBetweenBlocks.cy = y;
}
int CUIExtProgressWnd::GetSizeDistanceBetweenBlocksX()
{
	return m_sizeDistanceBetweenBlocks.cx;
}
int CUIExtProgressWnd::GetSizeDistanceBetweenBlocksY()
{
	return m_sizeDistanceBetweenBlocks.cy;
}
void CUIExtProgressWnd::SetSizeBlockScaleFactorH(int x, int y)
{
	m_sizeBlockScaleFactorH.cx = x;
	m_sizeBlockScaleFactorH.cy = y;
}
int CUIExtProgressWnd::GetSizeBlockScaleFactorHX()
{
	return m_sizeBlockScaleFactorH.cx;
}
int CUIExtProgressWnd::GetSizeBlockScaleFactorHY()
{
	return m_sizeBlockScaleFactorH.cy;
}
void CUIExtProgressWnd::SetSizeBlockScaleFactorV(int x, int y)
{
	m_sizeBlockScaleFactorV.cx = x;
	m_sizeBlockScaleFactorV.cy = y;
}
int CUIExtProgressWnd::GetSizeBlockScaleFactorVX()
{
	return m_sizeBlockScaleFactorV.cx;
}
int CUIExtProgressWnd::GetSizeBlockScaleFactorVY()
{
	return m_sizeBlockScaleFactorV.cy;
}
void CUIExtProgressWnd::SetHasBorder(bool border)
{
	m_bHasBorder = border;
}
bool CUIExtProgressWnd::GetHasBorder()
{
	return m_bHasBorder;
}
void CUIExtProgressWnd::SetHorizontalGradientBars(bool gradient)
{
	m_bHorizontalGradientBars = gradient;
}
bool CUIExtProgressWnd::GetHorizontalGradientBars()
{
	return m_bHorizontalGradientBars;
}
void CUIExtProgressWnd::SetImmediateUpdating(bool updating)
{
	m_bImmediateUpdating = updating;
}
bool CUIExtProgressWnd::GetImmediateUpdating()
{
	return m_bImmediateUpdating;
}
void CUIExtProgressWnd::SetUsePaintManager(bool use)
{
	m_bUsePaintManager = use;
}
bool CUIExtProgressWnd::GetUsePaintManager()
{
	return m_bUsePaintManager;
}
