#include "stdafx.h"
#include "Prof-UIS.h"

// constants
#define	CONTROLBAR_CLASSNAME							"CExtControlBar"
#define	CONTROLBAR_AUTOHIDEBUTTON_CLASSNAME				"CExtBarNcAreaButtonAutoHide"
#define	CONTROLBAR_CLOSEBUTTON_CLASSNAME				"CExtBarNcAreaButtonClose"
#define	CONTROLBAR_EXPANDBUTTON_CLASSNAME				"CExtBarNcAreaButtonExpand"
#define	CONTROLBAR_MENUBUTTON_CLASSNAME					"CExtBarNcAreaButtonMenu"

// forward declaration of functions
CExtControlBar* uiSalGetControlBarObject(HWND controlBarHandle);
CExtBarNcAreaButton* uiSalGetBarNcAreaButtonObject(CExtControlBar* controlBar, LPCSTR buttonClassName);
bool uiSalRemoveBarNcAreaButtonObject(CExtControlBar* controlBar, LPCSTR buttonClassName);
bool uiSalIsDerivedFrom(CRuntimeClass* runtimeClass, LPCSTR className);

extern "C" __declspec(dllexport) BOOL WINAPI UISalControlBarAppearInDockSiteControlBarPopupMenu(HWND controlBarHandle, BOOL appearInDockSiteControlBarPopupMenu)
{
	// get object
	CExtControlBar* controlBar = uiSalGetControlBarObject(controlBarHandle);
	if (controlBar == NULL) { return FALSE; }

	// change the value
	BOOL previousAppearInDockSiteControlBarPopupMenu = controlBar->m_bAppearInDockSiteControlBarPopupMenu;
	controlBar->m_bAppearInDockSiteControlBarPopupMenu = appearInDockSiteControlBarPopupMenu;
	return previousAppearInDockSiteControlBarPopupMenu;
}

extern "C" __declspec(dllexport) void WINAPI UISalControlBarToggleDocking(HWND controlBarHandle)
{
	// get object
	CExtControlBar* controlBar = uiSalGetControlBarObject(controlBarHandle);
	if (controlBar != NULL)
	{
		// toggle docking
		controlBar->ToggleDocking();
	}
}

extern "C" __declspec(dllexport) void WINAPI UISalControlBarRemoveAllButtons(HWND controlBarHandle)
{
	// get object
	CExtControlBar* controlBar = uiSalGetControlBarObject(controlBarHandle);
	if (controlBar != NULL)
	{
		// remove all buttons
		controlBar->NcButtons_RemoveAll();
	}
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalControlBarIsAutoHideButtonPresent(HWND controlBarHandle)
{
	// get object
	BOOL result = FALSE;
	CExtControlBar* controlBar = uiSalGetControlBarObject(controlBarHandle);
	if (controlBar != NULL)
	{
		// check AutoHide button
		CExtBarNcAreaButton* button = uiSalGetBarNcAreaButtonObject(controlBar, CONTROLBAR_AUTOHIDEBUTTON_CLASSNAME);
		result = (button != NULL);
	}

	return result;
}

extern "C" __declspec(dllexport) void WINAPI UISalControlBarRemoveAutoHideButton(HWND controlBarHandle)
{
	// get object
	CExtControlBar* controlBar = uiSalGetControlBarObject(controlBarHandle);
	if (controlBar != NULL)
	{
		// remove AutoHide button
		uiSalRemoveBarNcAreaButtonObject(controlBar, CONTROLBAR_AUTOHIDEBUTTON_CLASSNAME);
	}
}

extern "C" __declspec(dllexport) void WINAPI UISalControlBarEnableAutoHideButton(HWND controlBarHandle, BOOL enable)
{
	// get object
	CExtControlBar* controlBar = uiSalGetControlBarObject(controlBarHandle);
	if (controlBar != NULL)
	{
		// enable AutoHide button
		CExtBarNcAreaButton* button = uiSalGetBarNcAreaButtonObject(controlBar, CONTROLBAR_AUTOHIDEBUTTON_CLASSNAME);
		if (button != NULL)
		{
			button->DisabledSet((enable ? false : true));
		}
	}
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalControlBarIsCloseButtonPresent(HWND controlBarHandle)
{
	// get object
	BOOL result = FALSE;
	CExtControlBar* controlBar = uiSalGetControlBarObject(controlBarHandle);
	if (controlBar != NULL)
	{
		// check Close button
		CExtBarNcAreaButton* button = uiSalGetBarNcAreaButtonObject(controlBar, CONTROLBAR_CLOSEBUTTON_CLASSNAME);
		result = (button != NULL);
	}

	return result;
}

extern "C" __declspec(dllexport) void WINAPI UISalControlBarRemoveCloseButton(HWND controlBarHandle)
{
	// get object
	CExtControlBar* controlBar = uiSalGetControlBarObject(controlBarHandle);
	if (controlBar != NULL)
	{
		// remove Close button
		uiSalRemoveBarNcAreaButtonObject(controlBar, CONTROLBAR_CLOSEBUTTON_CLASSNAME);
	}
}

extern "C" __declspec(dllexport) void WINAPI UISalControlBarEnableCloseButton(HWND controlBarHandle, BOOL enable)
{
	// get object
	CExtControlBar* controlBar = uiSalGetControlBarObject(controlBarHandle);
	if (controlBar != NULL)
	{
		// enable Close button
		CExtBarNcAreaButton* button = uiSalGetBarNcAreaButtonObject(controlBar, CONTROLBAR_CLOSEBUTTON_CLASSNAME);
		if (button != NULL)
		{
			button->DisabledSet((enable ? false : true));
		}
	}
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalControlBarIsExpandButtonPresent(HWND controlBarHandle)
{
	// get object
	BOOL result = FALSE;
	CExtControlBar* controlBar = uiSalGetControlBarObject(controlBarHandle);
	if (controlBar != NULL)
	{
		// check Expand button
		CExtBarNcAreaButton* button = uiSalGetBarNcAreaButtonObject(controlBar, CONTROLBAR_EXPANDBUTTON_CLASSNAME);
		result = (button != NULL);
	}

	return result;
}

extern "C" __declspec(dllexport) void WINAPI UISalControlBarRemoveExpandButton(HWND controlBarHandle)
{
	// get object
	CExtControlBar* controlBar = uiSalGetControlBarObject(controlBarHandle);
	if (controlBar != NULL)
	{
		// remove Expand button
		uiSalRemoveBarNcAreaButtonObject(controlBar, CONTROLBAR_EXPANDBUTTON_CLASSNAME);
	}
}

extern "C" __declspec(dllexport) void WINAPI UISalControlBarEnableExpandButton(HWND controlBarHandle, BOOL enable)
{
	// get object
	CExtControlBar* controlBar = uiSalGetControlBarObject(controlBarHandle);
	if (controlBar != NULL)
	{
		// enable Expand button
		CExtBarNcAreaButton* button = uiSalGetBarNcAreaButtonObject(controlBar, CONTROLBAR_EXPANDBUTTON_CLASSNAME);
		if (button != NULL)
		{
			button->DisabledSet((enable ? false : true));
		}
	}
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalControlBarIsMenuButtonPresent(HWND controlBarHandle)
{
	// get object
	BOOL result = FALSE;
	CExtControlBar* controlBar = uiSalGetControlBarObject(controlBarHandle);
	if (controlBar != NULL)
	{
		// check Menu button
		CExtBarNcAreaButton* button = uiSalGetBarNcAreaButtonObject(controlBar, CONTROLBAR_MENUBUTTON_CLASSNAME);
		result = (button != NULL);
	}

	return result;
}

extern "C" __declspec(dllexport) void WINAPI UISalControlBarRemoveMenuButton(HWND controlBarHandle)
{
	// get object
	CExtControlBar* controlBar = uiSalGetControlBarObject(controlBarHandle);
	if (controlBar != NULL)
	{
		// remove Menu button
		uiSalRemoveBarNcAreaButtonObject(controlBar, CONTROLBAR_MENUBUTTON_CLASSNAME);
	}
}

extern "C" __declspec(dllexport) void WINAPI UISalControlBarEnableMenuButton(HWND controlBarHandle, BOOL enable)
{
	// get object
	CExtControlBar* controlBar = uiSalGetControlBarObject(controlBarHandle);
	if (controlBar != NULL)
	{
		// enable Menu button
		CExtBarNcAreaButton* button = uiSalGetBarNcAreaButtonObject(controlBar, CONTROLBAR_MENUBUTTON_CLASSNAME);
		if (button != NULL)
		{
			button->DisabledSet((enable ? false : true));
		}
	}
}






CExtControlBar* uiSalGetControlBarObject(HWND controlBarHandle)
{
	// try to find the according CExtControlBar object
	HWND windowToVerify = controlBarHandle;
	while (windowToVerify != NULL)
	{
		// get window object
		CWnd* window = CWnd::FromHandlePermanent(windowToVerify);
		if (window == NULL) { return NULL; }

		// now determine object name
		CRuntimeClass* runtimeClass = window->GetRuntimeClass();
		if (uiSalIsDerivedFrom(runtimeClass, CONTROLBAR_CLASSNAME))
		{
			// object found
			return (CExtControlBar*)CExtControlBar::FromHandlePermanent(windowToVerify);
		}

		// step up to parent window
		windowToVerify = ::GetAncestor(windowToVerify, GA_PARENT);
	}

	// object not found
	return NULL;
}

CExtBarNcAreaButton* uiSalGetBarNcAreaButtonObject(CExtControlBar* controlBar, LPCSTR buttonClassName)
{
	// find button object
	CExtBarNcAreaButton* result = NULL;
	if (controlBar != NULL)
	{
		// enumerate all existing buttons
		INT buttonCount = controlBar->NcButtons_GetCount();
		for (INT buttonIndex = 0; buttonIndex < buttonCount; buttonIndex++)
		{
			// get button and detect type
			CExtBarNcAreaButton* button = controlBar->NcButtons_GetAt(buttonIndex);
			if (button != NULL)
			{
				// detect type
				CRuntimeClass* runtimeClass = button->GetRuntimeClass();
				if (uiSalIsDerivedFrom(runtimeClass, buttonClassName))
				{
					// button found
					result = button;
					break;
				}
			}
		}
	}

	return result;
}

bool uiSalRemoveBarNcAreaButtonObject(CExtControlBar* controlBar, LPCSTR buttonClassName)
{
	// find button object
	bool result = false;
	if (controlBar != NULL)
	{
		// enumerate all existing buttons
		INT buttonCount = controlBar->NcButtons_GetCount();
		for (INT buttonIndex = 0; buttonIndex < buttonCount; buttonIndex++)
		{
			// get button and detect type
			CExtBarNcAreaButton* button = controlBar->NcButtons_GetAt(buttonIndex);
			if (button != NULL)
			{
				// detect type
				CRuntimeClass* runtimeClass = button->GetRuntimeClass();
				if (uiSalIsDerivedFrom(runtimeClass, buttonClassName))
				{
					// button found
					controlBar->NcButtons_RemoveAt(buttonIndex);
					result = true;
					break;
				}
			}
		}
	}

	return result;
}

bool uiSalIsDerivedFrom(CRuntimeClass* runtimeClass, LPCSTR className)
{
	// check class hierarchy
	bool result = false;
	while ((runtimeClass != NULL) && (runtimeClass->m_pfnGetBaseClass != NULL))
	{
		// test for className
		if (strcmp(runtimeClass->m_lpszClassName, className) == 0)
		{
			// class found
			result = true;
			break;
		}

		// get base class
		runtimeClass = runtimeClass->m_pfnGetBaseClass();
	}

	return result;
}
