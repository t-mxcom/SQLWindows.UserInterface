#include "stdafx.h"
#include "Prof-UIS.h"

// declare method to get a CExtTabWnd object
CExtTabWnd* GetCExtTabWndFromHWND(HWND tabBarHandle)
{
	// result
	CExtTabWnd* tabWnd = NULL;

	// get the correct object
#ifndef TabIsCExtTabPageContainerWnd
	tabWnd = (CExtTabWnd*)CExtTabWnd::FromHandlePermanent(tabBarHandle);
#else
	// get a CExtTabPageContainerWnd object first
	CExtTabPageContainerWnd* tabPageContainerWnd = (CExtTabPageContainerWnd*)CExtTabPageContainerWnd::FromHandlePermanent(tabBarHandle);
	if (tabPageContainerWnd != NULL)
	{
		// get the CExtTabWnd object
		tabWnd = tabPageContainerWnd->GetSafeTabWindow();
	}
#endif

	return tabWnd;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalTabBarItemEnsureVisible(HWND tabBarHandle, int itemIndex, BOOL updateTabBar)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->ItemEnsureVisible(itemIndex, updateTabBar);
	}

	return FALSE;
}

extern "C" __declspec(dllexport) int WINAPI UISalTabBarItemFindByLParam(HWND tabBarHandle, LPARAM searchLParam, int itemIndexStartSearch, BOOL includeVisible, BOOL includeInvisible)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->ItemFindByLParam(searchLParam, itemIndexStartSearch, includeVisible, includeInvisible);
	}

	return -1;
}

extern "C" __declspec(dllexport) int WINAPI UISalTabBarItemFindByStyle(HWND tabBarHandle, DWORD itemStyleInclude, DWORD itemStyleExclude, int itemIndexStartSearch)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->ItemFindByStyle(itemStyleInclude, itemStyleExclude, itemIndexStartSearch);
	}

	return -1;
}

extern "C" __declspec(dllexport) int WINAPI UISalTabBarItemGetCount(HWND tabBarHandle)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->ItemGetCount();
	}

	return -1;
}

extern "C" __declspec(dllexport) int WINAPI UISalTabBarItemGetVisibleCount(HWND tabBarHandle)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->ItemGetVisibleCount();
	}

	return -1;
}

extern "C" __declspec(dllexport) int WINAPI UISalTabBarItemHitTest(HWND tabBarHandle, int x, int y)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		POINT ptHitTest;
		ptHitTest.x = x;
		ptHitTest.y = y;
		return tabWnd->ItemHitTest(ptHitTest);
	}

	return __ETWH_NOWHERE;
}

extern "C" __declspec(dllexport) HICON WINAPI UISalTabBarItemIconGet(HWND tabBarHandle, int itemIndex, BOOL replaceSystemColors, COLORREF transparentColor)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		CExtCmdIcon itemIcon = tabWnd->ItemIconGet(itemIndex);
		return itemIcon.ExtractHICON(replaceSystemColors, transparentColor);
	}

	return NULL;
}

extern "C" __declspec(dllexport) void WINAPI UISalTabBarItemIconSet(HWND tabBarHandle, int itemIndex, HICON icon, BOOL forceLowColorMode, BOOL updateTabBar)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		tabWnd->ItemIconSet(itemIndex, icon, TRUE, updateTabBar);
	}

	return;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalTabBarItemInsert(HWND tabBarHandle, LPCWSTR text, HICON icon, DWORD style, int index, LPARAM lParam, BOOL updateTabBar)
{
	// get Tab Bar object
	CExtTabWnd::TAB_ITEM_INFO* itemInfo = NULL;
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		itemInfo = tabWnd->ItemInsert(text, icon, TRUE, style, index, lParam, updateTabBar);
	}

	return (itemInfo != NULL);
}

extern "C" __declspec(dllexport) LPARAM WINAPI UISalTabBarItemLParamGet(HWND tabBarHandle, int itemIndex)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->ItemLParamGet(itemIndex);
	}

	return 0;
}

extern "C" __declspec(dllexport) LPARAM WINAPI UISalTabBarItemLParamSet(HWND tabBarHandle, int itemIndex, LPARAM lParam)
{
	// variables
	LPARAM previousLParam = 0;

	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		previousLParam = tabWnd->ItemLParamGet(itemIndex);
		tabWnd->ItemLParamSet(itemIndex, lParam);
	}

	return previousLParam;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalTabBarItemMove(HWND tabBarHandle, int itemIndex, int itemIndexNew, BOOL updateTabBar)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->ItemMove(itemIndex, itemIndexNew, updateTabBar);
	}

	return FALSE;
}

extern "C" __declspec(dllexport) int WINAPI UISalTabBarItemRemove(HWND tabBarHandle, int itemIndex, int itemCount, BOOL updateTabBar)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->ItemRemove(itemIndex, itemCount, updateTabBar);
	}

	return -1;
}

extern "C" __declspec(dllexport) void WINAPI UISalTabBarItemRemoveAll(HWND tabBarHandle, BOOL updateTabBar)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		tabWnd->ItemRemoveAll(updateTabBar);
	}

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalTabBarItemRemoveGroup(HWND tabBarHandle, int itemIndex, int* firstItemRemoved, int* countItemsRemoved, BOOL updateTabBar)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		tabWnd->ItemRemoveGroup(itemIndex, (LONG*)firstItemRemoved, (LONG*)countItemsRemoved, updateTabBar);
	}

	return;
}

extern "C" __declspec(dllexport) DWORD WINAPI UISalTabBarItemStyleGet(HWND tabBarHandle, int itemIndex)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->ItemStyleGet(itemIndex);
	}

	return 0;
}

extern "C" __declspec(dllexport) DWORD WINAPI UISalTabBarItemStyleModify(HWND tabBarHandle, int itemIndex, DWORD styleRemove, DWORD styleAdd, BOOL updateTabBar)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->ItemStyleModify(itemIndex, styleRemove, styleAdd, updateTabBar);
	}

	return 0;
}

extern "C" __declspec(dllexport) int WINAPI UISalTabBarItemTextGet(HWND tabBarHandle, int itemIndex, LPWSTR itemText, int itemTextSize)
{
	// check parameters
	if (itemText == NULL) { return -1; }
	::ZeroMemory(itemText, itemTextSize * sizeof(WCHAR));

	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		LPCWSTR itemTextPtr = tabWnd->ItemTextGet(itemIndex);
		if (itemTextPtr != NULL)
		{
			wcsncpy_s(itemText, itemTextSize, itemTextPtr, itemTextSize - 1);
			return (int)wcslen(itemTextPtr);
		}
	}

	return -1;
}

extern "C" __declspec(dllexport) void WINAPI UISalTabBarItemTextSet(HWND tabBarHandle, int itemIndex, LPCWSTR itemText, BOOL updateTabBar)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		tabWnd->ItemTextSet(itemIndex, itemText, updateTabBar);
	}

	return;
}

extern "C" __declspec(dllexport) int WINAPI UISalTabBarItemTooltipTextGet(HWND tabBarHandle, int itemIndex, LPWSTR tooltipText, int tooltipTextSize)
{
	// check parameters
	if (tooltipText == NULL) { return -1; }
	::ZeroMemory(tooltipText, tooltipTextSize * sizeof(WCHAR));

	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		LPCWSTR tooltipTextPtr = tabWnd->ItemTooltipTextGet(itemIndex);
		if (tooltipTextPtr != NULL)
		{
			wcsncpy_s(tooltipText, tooltipTextSize, tooltipTextPtr, tooltipTextSize - 1);
			return (int)wcslen(tooltipTextPtr);
		}
	}

	return -1;
}

extern "C" __declspec(dllexport) void WINAPI UISalTabBarItemTooltipTextSet(HWND tabBarHandle, int itemIndex, LPCWSTR tooltipText, BOOL updateTabBar)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		tabWnd->ItemTooltipTextSet(itemIndex, tooltipText, updateTabBar);
	}

	return;
}

extern "C" __declspec(dllexport) DWORD WINAPI UISalTabBarModifyTabWndStyle(HWND tabBarHandle, DWORD styleRemove, DWORD styleAdd, BOOL updateTabBar)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->ModifyTabWndStyle(styleRemove, styleAdd, updateTabBar);
	}

	return 0;
}

extern "C" __declspec(dllexport) DWORD WINAPI UISalTabBarModifyTabWndStyleEx(HWND tabBarHandle, DWORD styleRemove, DWORD styleAdd, BOOL updateTabBar)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->ModifyTabWndStyleEx(styleRemove, styleAdd, updateTabBar);
	}

	return 0;
}

extern "C" __declspec(dllexport) DWORD WINAPI UISalTabBarOrientationGet(HWND tabBarHandle)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->OrientationGet();
	}

	return 0;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalTabBarOrientationIsHorizontal(HWND tabBarHandle)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->OrientationIsHorizontal();
	}

	return FALSE;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalTabBarOrientationIsVertical(HWND tabBarHandle)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->OrientationIsVertical();
	}

	return FALSE;
}

extern "C" __declspec(dllexport) DWORD WINAPI UISalTabBarOrientationSet(HWND tabBarHandle, DWORD orientation, BOOL updateTabBar)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->OrientationSet(orientation, updateTabBar);
	}

	return 0;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalTabBarSelectionBoldGet(HWND tabBarHandle)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->SelectionBoldGet();
	}

	return FALSE;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalTabBarSelectionBoldSet(HWND tabBarHandle, BOOL selectionBold, BOOL updateTabBar)
{
	// variables
	BOOL previousSelectionBold = FALSE;

	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		previousSelectionBold = tabWnd->SelectionBoldGet();
		tabWnd->SelectionBoldSet(selectionBold, updateTabBar);
	}

	return previousSelectionBold;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalTabBarSelectionDelay(HWND tabBarHandle, int itemIndex, DWORD delay)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->SelectionDelay(itemIndex, delay);
	}

	return FALSE;
}

extern "C" __declspec(dllexport) int WINAPI UISalTabBarSelectionGet(HWND tabBarHandle)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->SelectionGet();
	}

	return -1;
}

extern "C" __declspec(dllexport) int WINAPI UISalTabBarSelectionSet(HWND tabBarHandle, int itemIndex, BOOL ensureVisible, BOOL updateTabBar)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->SelectionSet(itemIndex, ensureVisible, updateTabBar);
	}

	return -1;
}

extern "C" __declspec(dllexport) void WINAPI UISalTabBarUpdateTabWnd(HWND tabBarHandle, BOOL immediate)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		tabWnd->UpdateTabWnd(immediate);
	}

	return;
}

// Version 2.0
extern "C" __declspec(dllexport) BOOL WINAPI UISalTabBarItemEnabledGet(HWND tabBarHandle, int itemIndex)
{
	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		return tabWnd->ItemEnabledGet((LONG)itemIndex);
	}

	return FALSE;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalTabBarItemEnabledSet(HWND tabBarHandle, int itemIndex, BOOL enabled, BOOL updateTabBar)
{
	// variables
	BOOL previousEnabled = FALSE;

	// get Tab Bar object
	CExtTabWnd* tabWnd = GetCExtTabWndFromHWND(tabBarHandle);
	if (tabWnd != NULL)
	{
		previousEnabled = tabWnd->ItemEnabledGet((LONG)itemIndex);
		tabWnd->ItemEnabledSet((LONG)itemIndex, (bool)enabled, (bool)updateTabBar);
	}

	return previousEnabled;
}
