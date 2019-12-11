#include "stdafx.h"
#include "Prof-UIS.h"
#include "CUIExtSpinWnd.h"

#define	UISAL_SPINCONTROL_NOTIFICATION		0x8001
#define	UISAL_SPINCONTROL_WINDOWPROC		L"SQLWindows.UserInterface|Spin Control WindowProc"
void uiSalActivateSpinControlHandler(HWND handlerWindow);
LRESULT CALLBACK uiSalSpinControlWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

extern "C" __declspec(dllexport) HWND WINAPI UISalSpinControlCreate(HWND parentWindow, HWND buddyWindow, UINT message, UINT controlID, int x, int y, int width, int height, DWORD windowStyle)
{
	// get parent window object
	CWnd* parentWindowClass = NULL;
	if (parentWindow != NULL)
	{
		parentWindowClass = CWnd::FromHandlePermanent(parentWindow);
	}

	// activate handler for parent window
	uiSalActivateSpinControlHandler(parentWindow);

	// use the default message, if 0 was passed
	if (message == 0)
	{
		message = UISAL_SPINCONTROL_NOTIFICATION;
	}

	// create Spin Control
	RECT rect;
	rect.left = x;
	rect.top = y;
	rect.right = x + width;
	rect.bottom = y + height;
	windowStyle = ((windowStyle == 0) ? WS_CHILD | WS_VISIBLE : windowStyle);
	CUIExtSpinWnd* spinWnd = new CUIExtSpinWnd(message);
	spinWnd->Create(windowStyle, rect, parentWindowClass, controlID);

	// if passed, define buddy window
	if (buddyWindow != NULL)
	{
		// get buddy window object
		CWnd* buddyWindowClass = CWnd::FromHandlePermanent(buddyWindow);
		spinWnd->SetBuddy(buddyWindowClass);
	}

	return spinWnd->GetSafeHwnd();
}
 
extern "C" __declspec(dllexport) void WINAPI UISalSpinControlGetAccelerationInfo(HWND spinControl, int* infoCount, UINT* timeSeconds, UINT* increment)
{
	// access spin control
	CUIExtSpinWnd* spinWnd = (CUIExtSpinWnd*)CUIExtSpinWnd::FromHandlePermanent(spinControl);
	if (spinWnd != NULL)
	{
		// perform action only, if infoCount passed
		if (infoCount != NULL)
		{
			// create buffers
			UDACCEL* accel = new UDACCEL[(*infoCount)];
			UINT accelCount = spinWnd->GetAccel(
				(*infoCount),
				accel);

			// return information
			(*infoCount) = accelCount;
			for (int infoIndex = 0; infoIndex < (int)accelCount; infoIndex++)
			{
				if (timeSeconds != NULL)
				{
					timeSeconds[infoIndex] = accel[infoIndex].nSec;
				}
				if (increment != NULL)
				{
					increment[infoIndex] = accel[infoIndex].nInc;
				}
			}

			// free memory
			delete[] accel;
		}
	}
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalSpinControlSetAccelerationInfo(HWND spinControl, int infoCount, UINT* timeSeconds, UINT* increment)
{
	// access spin control
	BOOL result = FALSE;
	CUIExtSpinWnd* spinWnd = (CUIExtSpinWnd*)CUIExtSpinWnd::FromHandlePermanent(spinControl);
	if (spinWnd != NULL)
	{
		// create buffers
		UDACCEL* accel = new UDACCEL[infoCount];
		for (int infoIndex = 0; infoIndex < infoCount; infoIndex++)
		{
			if (timeSeconds != NULL)
			{
				accel[infoIndex].nSec = timeSeconds[infoIndex];
			}
			if (increment != NULL)
			{
				accel[infoIndex].nInc = increment[infoIndex];
			}
		}

		// set information
		result = spinWnd->SetAccel(
			infoCount,
			accel);

		// free memory
		delete[] accel;
	}

	return result;
}

extern "C" __declspec(dllexport) UINT WINAPI UISalSpinControlGetBase(HWND spinControl)
{
	// access spin control
	UINT result = 0;
	CUIExtSpinWnd* spinWnd = (CUIExtSpinWnd*)CUIExtSpinWnd::FromHandlePermanent(spinControl);
	if (spinWnd != NULL)
	{
		// get information
		result = spinWnd->GetBase();
	}

	return result;
}

extern "C" __declspec(dllexport) int WINAPI UISalSpinControlSetBase(HWND spinControl, int base)
{
	// access spin control
	int result = 0;
	CUIExtSpinWnd* spinWnd = (CUIExtSpinWnd*)CUIExtSpinWnd::FromHandlePermanent(spinControl);
	if (spinWnd != NULL)
	{
		// set information
		result = spinWnd->SetBase(base);
	}

	return result;
}

extern "C" __declspec(dllexport) HWND WINAPI UISalSpinControlGetBuddy(HWND spinControl)
{
	// access spin control
	HWND result = NULL;
	CUIExtSpinWnd* spinWnd = (CUIExtSpinWnd*)CUIExtSpinWnd::FromHandlePermanent(spinControl);
	if (spinWnd != NULL)
	{
		// get information
		CWnd* buddyWindowClass = spinWnd->GetBuddy();
		if (buddyWindowClass != NULL)
		{
			result = buddyWindowClass->GetSafeHwnd();
		}
	}

	return result;
}

extern "C" __declspec(dllexport) HWND WINAPI UISalSpinControlSetBuddy(HWND spinControl, HWND buddy)
{
	// access spin control
	HWND result = NULL;
	CUIExtSpinWnd* spinWnd = (CUIExtSpinWnd*)CUIExtSpinWnd::FromHandlePermanent(spinControl);
	if (spinWnd != NULL)
	{
		// set information
		CWnd* buddyClass = CWnd::FromHandlePermanent(buddy);
		CWnd* buddyWindowClass = spinWnd->SetBuddy(buddyClass);
		if (buddyWindowClass != NULL)
		{
			result = buddyWindowClass->GetSafeHwnd();
		}
	}

	return result;
}

extern "C" __declspec(dllexport) int WINAPI UISalSpinControlGetPos(HWND spinControl)
{
	// access spin control
	int result = NULL;
	CUIExtSpinWnd* spinWnd = (CUIExtSpinWnd*)CUIExtSpinWnd::FromHandlePermanent(spinControl);
	if (spinWnd != NULL)
	{
		// get information
		result = spinWnd->GetPos32(NULL);
	}

	return result;
}

extern "C" __declspec(dllexport) int WINAPI UISalSpinControlSetPos(HWND spinControl, int pos)
{
	// access spin control
	int result = NULL;
	CUIExtSpinWnd* spinWnd = (CUIExtSpinWnd*)CUIExtSpinWnd::FromHandlePermanent(spinControl);
	if (spinWnd != NULL)
	{
		// get information
		result = spinWnd->SetPos32(pos);
	}

	return result;
}

extern "C" __declspec(dllexport) void WINAPI UISalSpinControlGetRange(HWND spinControl, int* lower, int* upper)
{
	// access spin control
	CUIExtSpinWnd* spinWnd = (CUIExtSpinWnd*)CUIExtSpinWnd::FromHandlePermanent(spinControl);
	if (spinWnd != NULL)
	{
		// get information
		int rangeLower, rangeUpper;
		spinWnd->GetRange32(rangeLower, rangeUpper);
		if (lower != NULL)
		{
			(*lower) = rangeLower;
		}
		if (upper != NULL)
		{
			(*upper) = rangeUpper;
		}
	}
}

extern "C" __declspec(dllexport) void WINAPI UISalSpinControlSetRange(HWND spinControl, int lower, int upper)
{
	// access spin control
	CUIExtSpinWnd* spinWnd = (CUIExtSpinWnd*)CUIExtSpinWnd::FromHandlePermanent(spinControl);
	if (spinWnd != NULL)
	{
		// set information
		spinWnd->SetRange32(lower, upper);
	}
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalSpinControlGetBkColor(HWND spinControl)
{
	// access spin control
	COLORREF result = 0;
	CUIExtSpinWnd* spinWnd = (CUIExtSpinWnd*)CUIExtSpinWnd::FromHandlePermanent(spinControl);
	if (spinWnd != NULL)
	{
		// get information
		result = spinWnd->GetBkColor();
	}

	return result;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalSpinControlSetBkColor(HWND spinControl, COLORREF bkColor)
{
	// access spin control
	COLORREF result = 0;
	CUIExtSpinWnd* spinWnd = (CUIExtSpinWnd*)CUIExtSpinWnd::FromHandlePermanent(spinControl);
	if (spinWnd != NULL)
	{
		// get information
		result = spinWnd->GetBkColor();

		// set information
		spinWnd->SetBkColor(bkColor);
	}

	return result;
}

void uiSalActivateSpinControlHandler(HWND handlerWindow)
{
	// only if a window handle was passed
	if (::IsWindow(handlerWindow))
	{
		// verify, if the handler is already activated
		WNDPROC handlerProc = (WNDPROC)::GetPropW(handlerWindow, UISAL_SPINCONTROL_WINDOWPROC);
		if (handlerProc == NULL)
		{
			// subclass the window
			WNDPROC windowProc = (WNDPROC)::GetWindowLongPtrW(handlerWindow, GWL_WNDPROC);
			::SetPropW(handlerWindow, UISAL_SPINCONTROL_WINDOWPROC, (HANDLE)windowProc);
			::SetWindowLongPtrW(handlerWindow, GWL_WNDPROC, (LONG_PTR)uiSalSpinControlWindowProc);
		}
	}
}

LRESULT CALLBACK uiSalSpinControlWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// get previous windowproc
	WNDPROC windowProc = (WNDPROC)::GetPropW(hwnd, UISAL_SPINCONTROL_WINDOWPROC);

	// handle spin control notifications
	if ((uMsg == WM_NOTIFY) && (lParam != 0))
	{
		// decode notification information
		NMHDR* nmHdr = (NMHDR*)lParam;
		if (nmHdr->code == UDN_DELTAPOS)
		{
			// access sender
			CUIExtSpinWnd* spinWnd = (CUIExtSpinWnd*)CUIExtSpinWnd::FromHandlePermanent(nmHdr->hwndFrom);
			if (spinWnd != NULL)
			{
				// decode spin control notification information
				NMUPDOWN* nmUpDown = (NMUPDOWN*)lParam;
				LRESULT result = spinWnd->SendNotification(nmUpDown->iPos, nmUpDown->iDelta);

				// if the change is allowed, set field edit and send SAM_AnyEdit
				if (result == 0)
				{
					// notify the datafield
					spinWnd->ManageFieldEdit();
				}

				return result;
			}
		}
	}

	// process WM_NCDESTROY message
	if (uMsg == WM_NCDESTROY)
	{
		// unsubclass window
		::SetWindowLongPtrW(hwnd, GWL_WNDPROC, (LONG_PTR)windowProc);

		// remove window properties
		::SetPropW(hwnd, UISAL_SPINCONTROL_WINDOWPROC, NULL);
	}

	// call previous windowproc
	return ((windowProc != NULL) ?
		::CallWindowProcW(windowProc, hwnd, uMsg, wParam, lParam) :
		::DefWindowProcW(hwnd, uMsg, wParam, lParam));
}
