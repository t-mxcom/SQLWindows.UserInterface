#include "stdafx.h"

// constants
#define	UISAL_SALRUNTIME_CDLLI51			L"cdlli51.dll"
#define	UISAL_SALRUNTIME_CDLLI52			L"cdlli52.dll"
#define	UISAL_SALRUNTIME_CDLLI60			L"cdlli60.dll"
#define	UISAL_SALRUNTIME_CDLLI61			L"cdlli61.dll"
#define	UISAL_SALRUNTIME_SALSETFIELDEDIT	"SalSetFieldEdit"

// types
typedef BOOL (WINAPI* SalSetFieldEditPtr)(HWND, BOOL);

// global variables
HMODULE						cdlliHandle = NULL;
SalSetFieldEditPtr			SalSetFieldEdit = NULL;

BOOL GetSalRuntimeHandle()
{
	// if a handle was found before, nothing more to do, else search for the runtime module
	if (cdlliHandle == NULL)
	{
		// try cdlli51.dll
		cdlliHandle = ::GetModuleHandleW(UISAL_SALRUNTIME_CDLLI51);
	}
	else if (cdlliHandle == NULL)
	{
		// try cdlli52.dll
		cdlliHandle = ::GetModuleHandleW(UISAL_SALRUNTIME_CDLLI52);
	}
	else if (cdlliHandle == NULL)
	{
		// try cdlli60.dll
		cdlliHandle = ::GetModuleHandleW(UISAL_SALRUNTIME_CDLLI60);
	}
	else if (cdlliHandle == NULL)
	{
		// try cdlli61.dll
		cdlliHandle = ::GetModuleHandleW(UISAL_SALRUNTIME_CDLLI61);
	}

	return (cdlliHandle != NULL);
}

BOOL DynamicSalFunctionAccess(const char* functionName, void** functionPtr)
{
	// if the function pointer was found before, do nothing
	if ((*functionPtr) == NULL)
	{
		// load the function only, if a runtime module was found
		if (GetSalRuntimeHandle())
		{
			// load the function pointer
			(*functionPtr) = ::GetProcAddress(cdlliHandle, functionName);
		}
	}

	return ((*functionPtr) != NULL);
}


BOOL DSalSetFieldEdit(HWND fieldHandle, BOOL fieldEdit)
{
	// ensure, that the function is available
	BOOL result = FALSE;
	if (DynamicSalFunctionAccess(UISAL_SALRUNTIME_SALSETFIELDEDIT, (void**)&SalSetFieldEdit))
	{
		// call the function
		result = SalSetFieldEdit(fieldHandle, fieldEdit);
	}

	return result;
}