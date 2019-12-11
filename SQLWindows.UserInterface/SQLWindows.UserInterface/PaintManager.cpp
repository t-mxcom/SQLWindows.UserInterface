#include "stdafx.h"
#include "Prof-UIS.h"

extern "C" __declspec(dllexport) COLORREF WINAPI UISalPaintManagerGetColor(int colorIndex)
{
	// use global Paint Manager
	CExtPaintManager* paintManager = g_PaintManager.GetPM();
	if (paintManager != NULL)
	{
		COLORREF test = paintManager->GetColor(colorIndex);
		return paintManager->GetColor(colorIndex);
	}
	return 0;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalPaintManagerSetColor(int colorIndex, COLORREF color)
{
	// use global Paint Manager
	CExtPaintManager* paintManager = g_PaintManager.GetPM();
	if (paintManager != NULL)
	{
		COLORREF previousColor = paintManager->GetColor(colorIndex);
		paintManager->InstallColor(color, colorIndex);
		return previousColor;
	}
	return 0;
}

extern "C" __declspec(dllexport) HPALETTE WINAPI UISalPaintManagerGetPalette()
{
	// use global Paint Manager
	CExtPaintManager* paintManager = g_PaintManager.GetPM();
	if (paintManager != NULL)
	{
		// get palette
		return (HPALETTE)paintManager->m_PaletteWide.GetSafeHandle();
	}
	return 0;
}

