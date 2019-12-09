#include "stdafx.h"
#include "Prof-UIS.h"

extern "C" __declspec(dllexport) BOOL WINAPI UISalLabelGetFontBold(HWND labelHandle)
{
	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		return extLabel->GetFontBold();
	}

	return FALSE;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalLabelSetFontBold(HWND labelHandle, BOOL bold)
{
	// variables
	BOOL previousFontBold = FALSE;

	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		// get previous value
		previousFontBold = extLabel->GetFontBold();

		// set new value
		extLabel->SetFontBold((bool)bold);
	}

	return previousFontBold;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalLabelGetFontItalic(HWND labelHandle)
{
	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		return extLabel->GetFontItalic();
	}

	return FALSE;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalLabelSetFontItalic(HWND labelHandle, BOOL italic)
{
	// variables
	BOOL previousFontItalic = FALSE;

	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		// get previous value
		previousFontItalic = extLabel->GetFontItalic();

		// set new value
		extLabel->SetFontItalic((bool)italic);
	}

	return previousFontItalic;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalLabelGetFontUnderline(HWND labelHandle)
{
	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		return extLabel->GetFontUnderline();
	}

	return FALSE;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalLabelSetFontUnderline(HWND labelHandle, BOOL underline)
{
	// variables
	BOOL previousFontUnderline = FALSE;

	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		// get previous value
		previousFontUnderline = extLabel->GetFontUnderline();

		// set new value
		extLabel->SetFontUnderline((bool)underline);
	}

	return previousFontUnderline;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalLabelGetFontStrikeOut(HWND labelHandle)
{
	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		return extLabel->GetFontStrikeOut();
	}

	return FALSE;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalLabelSetFontStrikeOut(HWND labelHandle, BOOL strikeOut)
{
	// variables
	BOOL previousFontStrikeOut = FALSE;

	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		// get previous value
		previousFontStrikeOut = extLabel->GetFontStrikeOut();

		// set new value
		extLabel->SetFontStrikeOut((bool)strikeOut);
	}

	return previousFontStrikeOut;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalLabelGetBkColor(HWND labelHandle)
{
	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		return extLabel->GetBkColor();
	}

	return -1;
}

extern "C" __declspec(dllexport) DWORD WINAPI UISalLabelSetBkColor(HWND labelHandle, COLORREF bkColor)
{
	// variables
	COLORREF previousBkColor = -1;

	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		// get previous value
		previousBkColor = extLabel->GetBkColor();

		// set new value
		extLabel->SetBkColor(bkColor);
	}

	return previousBkColor;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalLabelGetTextColor(HWND labelHandle, BOOL enabled)
{
	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		return extLabel->GetTextColor((bool)enabled);
	}

	return -1;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalLabelSetTextColor(HWND labelHandle, BOOL enabled, COLORREF textColor)
{
	// variables
	COLORREF previousTextColor = -1;

	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		// get previous value
		previousTextColor = extLabel->GetTextColor((bool)enabled);

		// set new value
		extLabel->SetTextColor((bool)enabled, (COLORREF)textColor);
	}

	return previousTextColor;
}

extern "C" __declspec(dllexport) int WINAPI UISalLabelGetImageMode(HWND labelHandle)
{
	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		return (int)extLabel->GetImageMode();
	}

	return -1;
}

extern "C" __declspec(dllexport) int WINAPI UISalLabelSetImageMode(HWND labelHandle, int imageMode)
{
	// variables
	int previousImageMode = -1;

	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		// get previous value
		previousImageMode = (int)extLabel->GetImageMode();

		// set new value
		extLabel->SetImageMode((CExtLabel::e_ImageMode_t)imageMode);
	}

	return previousImageMode;
}

extern "C" __declspec(dllexport) HANDLE WINAPI UISalLabelGetBitmapHANDLE(HWND labelHandle)
{
	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		return (HANDLE)extLabel->GetBitmapEx();
	}

	return NULL;
}

extern "C" __declspec(dllexport) void WINAPI UISalLabelSetBitmapHANDLE(HWND labelHandle, HANDLE bitmap)
{
	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		// use HANDLE as CExtBitmap*
		extLabel->SetBitmapEx((CExtBitmap*)bitmap);
	}

	return;
}

extern "C" __declspec(dllexport) HBITMAP WINAPI UISalLabelGetBitmapHBITMAP(HWND labelHandle)
{
	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		// create bitmap
		CExtBitmap* bitmap = extLabel->GetBitmapEx();
		if (bitmap != NULL)
		{
			return bitmap->CreateBitmap(false);
		} // if (bitmap != NULL)
	}

	return NULL;
}

extern "C" __declspec(dllexport) void WINAPI UISalLabelSetBitmapHBITMAP(HWND labelHandle, HBITMAP bitmap, BOOL useAlphaChannel)
{
	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		// create CExtBitmap* from HBITMAP
		CExtBitmap extBitmap;
		extBitmap.FromBitmap(bitmap, false, (useAlphaChannel ? false : true));
		extLabel->SetBitmapEx(&extBitmap);
	}

	return;
}

extern "C" __declspec(dllexport) HICON WINAPI UISalLabelGetBitmapHICON(HWND labelHandle, BOOL replaceSystemColors, COLORREF transparentColor)
{
	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		// create HICON
		CExtBitmap* bitmap = extLabel->GetBitmapEx();
		if (bitmap != NULL)
		{
			return bitmap->CreateHICON((bool)replaceSystemColors, transparentColor);
		}
	}

	return NULL;
}

extern "C" __declspec(dllexport) void WINAPI UISalLabelSetBitmapHICON(HWND labelHandle, HICON icon, BOOL lowColorMode)
{
	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		// create CExtBitmap* from HICON
		CExtBitmap extBitmap;
		extBitmap.AssignFromHICON(icon, lowColorMode);
		extLabel->SetBitmapEx(&extBitmap);
	}

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalLabelSetTooltipText(HWND labelHandle, LPCWSTR tooltipText)
{
	// this only works from TD 6.0 upward
#ifdef LabelSupportsTooltip
	// access label
	CExtLabel* extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	if (extLabel == NULL)
	{
		__EXT_SUBCLASS_PROFUISCTRL(labelHandle, CExtLabel);
		extLabel = (CExtLabel*)CExtLabel::FromHandlePermanent(labelHandle);
	}
	if (extLabel != NULL)
	{
		// set tooltip text
		extLabel->SetTooltipText(tooltipText);
	}
#endif

	return;
}
