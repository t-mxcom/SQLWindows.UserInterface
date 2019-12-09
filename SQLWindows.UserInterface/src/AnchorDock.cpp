#include "stdafx.h"
#include "Prof-UIS.h"

#define	UISAL_RESIZING_OBJECT			L"SQLWindows.UserInterface|Resizing Object"
#define	UISAL_RESIZING_WINDOWNAME		L"SQLWindows.UserInterface|Resizing Window"
#define	UISAL_RESIZING_WINDOWPROC		L"SQLWindows.UserInterface|Resizing WindowProc"
#define	UISAL_RESIZING_ATTACHEDWINDOW	L"SQLWindows.UserInterface|Attached Window"
#define	UISAL_MESSAGE_SIZE_NAME			L"SQLWindows.UserInterface|Size Changed"
DWORD	uisal_Message_Size = 0;

CExtWA<CExtNCW<CWnd>>* uiSalGetResizingObject(HWND resizingWindow);
LRESULT CALLBACK uiSalResizingWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

extern "C" __declspec(dllexport) BOOL WINAPI UISalResizingAddAnchor(HWND resizingWindow, HWND control, int left, int top, int right, int bottom)
{
	// register size message if not done
	if (uisal_Message_Size == 0)
	{
		// register
		uisal_Message_Size = ::RegisterWindowMessageW(UISAL_MESSAGE_SIZE_NAME);
	}

	// if no parent window is specified, get parent from control
	if (resizingWindow == NULL)
	{
		resizingWindow = ::GetParent(control);
	}

	// set parent window style to reduce flicker
	LONG style = ::GetWindowLong(resizingWindow, GWL_STYLE);
	style |= WS_CLIPCHILDREN;
	::SetWindowLong(resizingWindow, GWL_STYLE, style);

	// access window object
	BOOL result = FALSE;
	CWnd* windowObject = CWnd::FromHandlePermanent(resizingWindow);
	if (windowObject != NULL)
	{
		// get resizing object
		CExtWA<CExtNCW<CWnd>>* resizingObject = uiSalGetResizingObject(resizingWindow);

		// temporarily change control parent, so AddAnchor adds the anchor
		HWND originalParent = ::GetParent(control);
		::SetParent(control, resizingObject->GetSafeHwnd());

		// set the anchor
		result = resizingObject->AddAnchor(control, CSize(left, top), CSize(right, bottom));

		// restore the controls parent
		::SetParent(control, originalParent);
	}

	return result;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalResizingRemoveAnchor(HWND resizingWindow, HWND control)
{
	// access window object
	BOOL result = FALSE;
	CWnd* windowObject = CWnd::FromHandlePermanent(resizingWindow);
	if (windowObject != NULL)
	{
		// get resizing object
		CExtWA<CExtNCW<CWnd>>* resizingObject = uiSalGetResizingObject(resizingWindow);
		result = resizingObject->RemoveAnchor(control);
	}

	return result;
}

CExtWA<CExtNCW<CWnd>>* uiSalGetResizingObject(HWND resizingWindow)
{
	// detect, if window is a docking toolbar
	BOOL dockingToolbar = FALSE;
#if defined(_TD52SP1) || defined(_TD52SP2)
	CWnd* window = CWnd::FromHandlePermanent(resizingWindow);
	if (window != NULL)
	{
		// now determine object name
		CRuntimeClass* runtimeClass = window->GetRuntimeClass();
		while ((runtimeClass != NULL) && (runtimeClass->m_pfnGetBaseClass != NULL))
		{
			// compare the class name
			if (runtimeClass->m_lpszClassName != NULL)
			{
				if (strcmp(runtimeClass->m_lpszClassName, "CUfcDockingDlg") == 0)
				{
					// it's a docking toolbar
					dockingToolbar = TRUE;
					break;
				}
			}

			// get base class
			runtimeClass = runtimeClass->m_pfnGetBaseClass();
		}
	}
#endif

	// access window object
	CExtWA<CExtNCW<CWnd>>* resizingObject = NULL;
	CWnd* windowObject = CWnd::FromHandlePermanent(resizingWindow);
	if (windowObject != NULL)
	{
		// if resizing window is a dialog, resizing is supported
		if ((windowObject->IsKindOf(RUNTIME_CLASS(CDialog))) && (!dockingToolbar))
		{
			resizingObject = (CExtWA<CExtNCW<CWnd>>*)windowObject;
		}
		else if (windowObject->IsKindOf(RUNTIME_CLASS(CWnd)))
		{
			// else, we have to create our own resizing window
			resizingObject = (CExtWA<CExtNCW<CWnd>>*)::GetPropW(resizingWindow, UISAL_RESIZING_OBJECT);
			if (resizingObject == NULL)
			{
				// create a new object
				resizingObject = new CExtWA<CExtNCW<CWnd>>();
				::SetPropW(resizingWindow, UISAL_RESIZING_OBJECT, (HANDLE)resizingObject);
				RECT resizingObjectSize = { 0, 0, 0, 0 };
				// windowObject->GetWindowRect(&resizingObjectSize);
				windowObject->GetClientRect(&resizingObjectSize);
				resizingObject->Create(
					L"STATIC",
					UISAL_RESIZING_WINDOWNAME,
					/* WS_CHILD | */ WS_CLIPSIBLINGS | WS_CLIPCHILDREN | SS_LEFTNOWORDWRAP | WS_POPUP,
					resizingObjectSize,
					windowObject,
					0,
					NULL);

				// remember attached window
				::SetPropW(resizingObject->GetSafeHwnd(), UISAL_RESIZING_ATTACHEDWINDOW, (HANDLE)resizingWindow);

				// subclass resizing window
				WNDPROC windowProc = (WNDPROC)::GetWindowLongPtrW(resizingWindow, GWL_WNDPROC);
				::SetPropW(resizingWindow, UISAL_RESIZING_WINDOWPROC, (HANDLE)windowProc);
				::SetWindowLongPtrW(resizingWindow, GWL_WNDPROC, (LONG_PTR)uiSalResizingWindowProc);
			}
		}
	}

	return resizingObject;
}

LRESULT CALLBACK uiSalResizingWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// get previous windowproc
	WNDPROC windowProc = (WNDPROC)::GetPropW(hwnd, UISAL_RESIZING_WINDOWPROC);

	// get resizing object
	CExtWA<CExtNCW<CWnd>>* resizingObject = (CExtWA<CExtNCW<CWnd>>*)::GetPropW(hwnd, UISAL_RESIZING_OBJECT);

	// process WM_SIZE message
	if (uMsg == WM_SIZE)
	{
		// post a message to process the size change
		::PostMessageW(hwnd, uisal_Message_Size, 0, 0);
	}

	if ((uMsg == uisal_Message_Size) || (uMsg == WM_MOVE))
	{
		// lock the update in the attached window
		// ::LockWindowUpdate(hwnd);

		// resize the resizing object window
		RECT clientRect;
		::GetClientRect(hwnd, &clientRect);
		// ::GetWindowRect(hwnd, &clientRect);
		resizingObject->SetWindowPos(NULL,
			clientRect.left, clientRect.top,
			clientRect.right - clientRect.left, clientRect.bottom - clientRect.top, SWP_NOZORDER | SWP_NOACTIVATE);

		// do window update
		// ::LockWindowUpdate(NULL);
	}

	// process WM_NCDESTROY message
	if (uMsg == WM_NCDESTROY)
	{
		// unsubclass window
		::SetWindowLongPtrW(hwnd, GWL_WNDPROC, (LONG_PTR)windowProc);

		// free resizing object
		delete resizingObject;

		// remove window properties
		::SetPropW(hwnd, UISAL_RESIZING_OBJECT, NULL);
		::SetPropW(hwnd, UISAL_RESIZING_WINDOWPROC, NULL);
	}

	// call previous windowproc
	return ((windowProc != NULL) ?
		::CallWindowProcW(windowProc, hwnd, uMsg, wParam, lParam) :
		::DefWindowProcW(hwnd, uMsg, wParam, lParam));
}