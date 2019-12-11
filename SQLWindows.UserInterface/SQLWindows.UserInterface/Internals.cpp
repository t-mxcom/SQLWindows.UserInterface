#include "stdafx.h"
#include "Prof-UIS.h"

extern "C" __declspec(dllexport) void WINAPI UISalValidateHandle(HANDLE handle)
{
	// convert handle to object and see if it is one
	CObject* object = (CObject*)handle;
	if (object == NULL) { return; }

	// now determine object name
	CRuntimeClass* runtimeClass = object->GetRuntimeClass();
	while ((runtimeClass != NULL) && (runtimeClass->m_pfnGetBaseClass != NULL))
	{
		// get base class
		runtimeClass = runtimeClass->m_pfnGetBaseClass();
	}
}

extern "C" __declspec(dllexport) void WINAPI UISalValidateWindow(HWND hwnd)
{
	// Test: apply Theme to Vis-ComboBox -> Crash
	// CExtComboBox* extComboBox = new CExtComboBox();
	// BOOL subclassed = extComboBox->SubclassWindow(hwnd);

	// get window object
	CWnd* window = CWnd::FromHandlePermanent(hwnd);
	if (window == NULL) { return; }

	// now determine object name
	CRuntimeClass* runtimeClass = window->GetRuntimeClass();
	while ((runtimeClass != NULL) && (runtimeClass->m_pfnGetBaseClass != NULL))
	{
		// get base class
		runtimeClass = runtimeClass->m_pfnGetBaseClass();
	}
}
