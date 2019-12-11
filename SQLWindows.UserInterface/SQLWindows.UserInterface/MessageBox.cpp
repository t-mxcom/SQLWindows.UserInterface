#include "stdafx.h"
#define INCLUDE_EXTMSGBOX
#include "Prof-UIS.h"

extern "C" __declspec(dllexport) int WINAPI UISalMessageBoxEx(HWND parentWindow, LPCWSTR message, LPCWSTR caption, UINT style, UINT helpID, LPCWSTR uniqueID, UINT extendedStyle, UINT timeout, BOOL buttonsDisabledDuringTimeout, HICON icon)
{
	// prepare icon if HICON was passed
	CExtBitmap* customIcon = NULL;
	if (icon != NULL)
	{
		// create object
		customIcon = new CExtBitmap();
		customIcon->AssignFromHICON(icon, false);
	}

	// create message box object
	CExtMsgBox* messageBox = new CExtMsgBox(
		parentWindow,
		message,
		caption,
		style,
		helpID,
		uniqueID,
		extendedStyle);

	// show message box
	int result = messageBox->DoMsgBox(
		parentWindow,
		message,
		caption,
		style,
		helpID,
		uniqueID,
		extendedStyle,
		timeout,
		buttonsDisabledDuringTimeout,
		customIcon);
	delete messageBox;
	messageBox = NULL;

	// free icon object if created
	if (customIcon != NULL)
	{
		// free object
		delete customIcon;
	}

	return (DWORD)result;
}
