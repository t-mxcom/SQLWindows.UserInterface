#include "stdafx.h"
#include "Prof-UIS.h"

extern "C" __declspec(dllexport) void WINAPI UISalEditSetCueBanner(HWND editHandle, LPCWSTR cueBannerText)
{
	// get access to Edit control
	CExtEdit* extEdit = (CExtEdit*)CExtEdit::FromHandlePermanent(editHandle);
	if (extEdit != NULL)
	{
		extEdit->SetCueBanner(cueBannerText);
	}

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalEditSetTooltipText(HWND editHandle, LPCWSTR tooltipText)
{
	// get access to Edit control
	CExtEdit* extEdit = (CExtEdit*)CExtEdit::FromHandlePermanent(editHandle);
	if (extEdit != NULL)
	{
		extEdit->SetTooltipText(new CExtSafeString(tooltipText), TRUE);
	}

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalEditEnableTooltip(HWND editHandle, BOOL enable)
{
	// get access to Edit control
	CExtEdit* extEdit = (CExtEdit*)CExtEdit::FromHandlePermanent(editHandle);
	if (extEdit != NULL)
	{
		extEdit->ActivateTooltip(enable);
	}

	return;
}
