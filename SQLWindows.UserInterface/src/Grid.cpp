#include "stdafx.h"
#include "Prof-UIS.h"

extern "C" __declspec(dllexport) int WINAPI UISalGridSetFrozenColumnCountLeft(HWND gridHandle, LONG frozenColumnCount)
{
	// access grid class
	LONG previousFrozenColumnCount = -1;
	CExtGridBaseWnd* extGrid = (CExtGridBaseWnd*)CExtGridBaseWnd::FromHandlePermanent(gridHandle);
	if (extGrid != NULL)
	{
		previousFrozenColumnCount = extGrid->FrozenColumnCountLeftGet();
		extGrid->FrozenColumnCountLeftSet(frozenColumnCount, true);
	}

	return previousFrozenColumnCount;
}

extern "C" __declspec(dllexport) int WINAPI UISalGridSetFrozenColumnCountRight(HWND gridHandle, LONG frozenColumnCount)
{
	// access grid class
	LONG previousFrozenColumnCount = -1;
	CExtGridBaseWnd* extGrid = (CExtGridBaseWnd*)CExtGridBaseWnd::FromHandlePermanent(gridHandle);
	if (extGrid != NULL)
	{
		previousFrozenColumnCount = extGrid->FrozenColumnCountRightGet();
		extGrid->FrozenColumnCountRightSet(frozenColumnCount, true);
	}

	return previousFrozenColumnCount;
}

extern "C" __declspec(dllexport) int WINAPI UISalGridSetFrozenRowCountTop(HWND gridHandle, LONG frozenRowCount)
{
	// access grid class
	LONG previousFrozenRowCount = -1;
	CExtGridBaseWnd* extGrid = (CExtGridBaseWnd*)CExtGridBaseWnd::FromHandlePermanent(gridHandle);
	if (extGrid != NULL)
	{
		previousFrozenRowCount = extGrid->FrozenRowCountTopGet();
		extGrid->FrozenRowCountTopSet(frozenRowCount, true);
	}

	return previousFrozenRowCount;
}

extern "C" __declspec(dllexport) int WINAPI UISalGridSetFrozenRowCountBottom(HWND gridHandle, LONG frozenRowCount)
{
	// access grid class
	LONG previousFrozenRowCount = -1;
	CExtGridBaseWnd* extGrid = (CExtGridBaseWnd*)CExtGridBaseWnd::FromHandlePermanent(gridHandle);
	if (extGrid != NULL)
	{
		previousFrozenRowCount = extGrid->FrozenRowCountBottomGet();
		extGrid->FrozenRowCountBottomSet(frozenRowCount, true);
	}

	return previousFrozenRowCount;
}
