#include "stdafx.h"
#include "Prof-UIS.h"

#define	UISAL_BACKGROUND_WINDOWPROC		L"SQLWindows.UserInterface|Background WindowProc"
#define	UISAL_BACKGROUND_IMAGE			L"SQLWindows.UserInterface|Background Image"
#define	UISAL_BACKGROUND_IMAGESIZE		L"SQLWindows.UserInterface|Background Image Size"
#define	UISAL_BACKGROUND_ISMDICLIENT	L"SQLWindows.UserInterface|Is MDIClient"

LRESULT CALLBACK uiSalBackgroundWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

extern "C" __declspec(dllexport) void WINAPI UISalBackgroundSetImage(HWND window, HBITMAP image)
{
	// set image handle to window
	::SetPropW(window, UISAL_BACKGROUND_IMAGE, (HANDLE)image);

	// get size of image if specified
	if (image != NULL)
	{
		// get bitmap information
		BITMAP bitmap;
		::GetObjectW(image, (int)sizeof(bitmap), (LPVOID)&bitmap);

		// set size information
		::SetPropW(window, UISAL_BACKGROUND_IMAGESIZE, (HANDLE)MAKELONG(bitmap.bmWidth, bitmap.bmHeight));
	}
	else
	{
		// reset bitmap information
		::SetPropW(window, UISAL_BACKGROUND_IMAGESIZE, (HANDLE)NULL);
	}

	// test, if the window is the MDIClient
	WCHAR windowClassName[MAX_PATH];
	::GetClassNameW(window, windowClassName, (int)_countof(windowClassName));
	if (wcscmp(windowClassName, L"MDIClient") == 0)
	{
		// mark window as MDIClient
		::SetPropW(window, UISAL_BACKGROUND_ISMDICLIENT, (HANDLE)TRUE);
	}

	// subclass window, if it isn't yet
	WNDPROC windowProc = (WNDPROC)::GetPropW(window, UISAL_BACKGROUND_WINDOWPROC);
	if (windowProc == NULL)
	{
		// do subclassing
		windowProc = (WNDPROC)::GetWindowLongPtrW(window, GWL_WNDPROC);
		::SetPropW(window, UISAL_BACKGROUND_WINDOWPROC, (HANDLE)windowProc);
		::SetWindowLongPtrW(window, GWL_WNDPROC, (LONG_PTR)uiSalBackgroundWindowProc);
	}

	// repaint the window
	::InvalidateRect(window, NULL, TRUE);
}

LRESULT CALLBACK uiSalBackgroundWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// get previous windowproc
	WNDPROC windowProc = (WNDPROC)::GetPropW(hwnd, UISAL_BACKGROUND_WINDOWPROC);
	BOOL isMDIClient = (BOOL)::GetPropW(hwnd, UISAL_BACKGROUND_ISMDICLIENT);

	// process messages
	switch (uMsg)
	{
	case WM_ERASEBKGND:
		{
			// paint the background
			HBITMAP image = (HBITMAP)::GetPropW(hwnd, UISAL_BACKGROUND_IMAGE);
			if (image != NULL)
			{
				// get additional information
				DWORD imageSize = (DWORD)::GetPropW(hwnd, UISAL_BACKGROUND_IMAGESIZE);

				// create device context
				HDC dcWindow = (HDC)wParam;
				HDC dcImage = ::CreateCompatibleDC(dcWindow);
				HBITMAP bitmapPrevious = (HBITMAP)::SelectObject(dcImage, image);

				// get target window size
				RECT rectWindow;
				::GetClientRect(hwnd, &rectWindow);

				// stretch bitmap over whole background
				::SetStretchBltMode(dcWindow, STRETCH_HALFTONE);
				::StretchBlt(
					dcWindow,
					rectWindow.left, rectWindow.top, rectWindow.right, rectWindow.bottom,
					dcImage,
					0, 0, LOWORD(imageSize), HIWORD(imageSize),
					SRCCOPY);

				// release objects
				::SelectObject(dcImage, bitmapPrevious);
				::DeleteDC(dcImage);

				// no further painting
				return 0;
			}
			else if (isMDIClient)
			{
				// painting will be performed in WM_PAINT, so no background erasing should be done
				return 0;
			}

			break;
		}

	case WM_PAINT:
		{
			// only perform this painting, if the window is the MDIClient
			if (isMDIClient)
			{
				// paint the background
				HBITMAP image = (HBITMAP)::GetPropW(hwnd, UISAL_BACKGROUND_IMAGE);

				if (image == NULL)
				{
					// create device context
					CWnd* pWnd = CWnd::FromHandle(hwnd);
					CPaintDC dc(pWnd);
					if (!g_PaintManager->PaintDocumentClientAreaBkgnd(dc, pWnd))
					{
						CRect rcClient;
						::GetClientRect(hwnd, &rcClient);
						dc.FillSolidRect(&rcClient, g_PaintManager->GetColor(CExtPaintManager::CLR_3DFACE_OUT));
					}

					return (LRESULT)TRUE;
				}
			}
			break;
		}
	case WM_VSCROLL:
	case WM_HSCROLL:
		// invalidate window if scrolled
		if (LOWORD(lParam) == SB_THUMBTRACK)
		{
			// only thumb is tracked, no invalidation required
			break;
		}
	case WM_SIZE:
		// invalidate window
		::InvalidateRect(hwnd, NULL, TRUE);
		break;
	}

	// process WM_NCDESTROY message
	if (uMsg == WM_NCDESTROY)
	{
		// unsubclass window
		::SetWindowLongPtrW(hwnd, GWL_WNDPROC, (LONG_PTR)windowProc);

		// remove window properties
		::SetPropW(hwnd, UISAL_BACKGROUND_WINDOWPROC, NULL);
	}

	// call previous windowproc
	return ((windowProc != NULL) ?
		::CallWindowProcW(windowProc, hwnd, uMsg, wParam, lParam) :
		::DefWindowProcW(hwnd, uMsg, wParam, lParam));
}
