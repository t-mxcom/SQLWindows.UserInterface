#include "stdafx.h"
#include "Prof-UIS.h"

extern "C" __declspec(dllexport) void WINAPI Menu_CheckHandle(HWND mdiWindow)
{
	CWinApp* winApp = ::AfxGetApp();
	if (winApp != NULL)
	{
		::MessageBox(NULL, winApp->m_pszAppName, TEXT(""), MB_OK);
	}
	CWnd* mainWnd = ::AfxGetMainWnd();
	if (mainWnd != NULL)
	{
		mainWnd->MessageBox(TEXT("mainWnd"), TEXT(""), MB_OK);
	}
	CWnd* windowObject = CWnd::FromHandlePermanent(mdiWindow);
	if (windowObject != NULL)
	{
		if (windowObject->IsKindOf(RUNTIME_CLASS(CWnd))) { windowObject->MessageBox(TEXT("CWnd"), TEXT(""), MB_OK); }
		if (windowObject->IsKindOf(RUNTIME_CLASS(CExtControlBar))) { windowObject->MessageBox(TEXT("CExtControlBar"), TEXT(""), MB_OK); }
		if (windowObject->IsKindOf(RUNTIME_CLASS(CExtMenuControlBar))) { windowObject->MessageBox(TEXT("CExtMenuControlBar"), TEXT(""), MB_OK); }
		CRuntimeClass* runtimeClass = windowObject->GetRuntimeClass();
		::MessageBoxA(NULL, runtimeClass->m_lpszClassName, "", MB_OK);
	}

	return;
}

