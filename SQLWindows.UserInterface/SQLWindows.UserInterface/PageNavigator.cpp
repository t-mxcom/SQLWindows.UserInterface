#include "stdafx.h"
#include "Prof-UIS.h"
#include "CUIExtPageNavigatorWnd.h"

extern "C" __declspec(dllexport) HWND WINAPI UISalPageNavigatorCreate(HWND parentWindow, HWND messageWindow, UINT message, UINT controlID, int x, int y, int width, int height, DWORD windowStyle)
{
	// access parent window
	CWnd* parentWindowClass = NULL;
	if (parentWindow != NULL)
	{
		parentWindowClass = CWnd::FromHandlePermanent(parentWindow);
	}

	// If requested, adjust size
	if ((width == -1) || (height == -1))
	{
		// Calculate size of parent windows's client rect
		RECT parentWindowRect;
		::GetClientRect(parentWindow, &parentWindowRect);

		// Adjust sizes
		if (width == -1)
		{
			// Adjust start position and size
			x = 0;
			width = parentWindowRect.right - parentWindowRect.left;
		}
		if (height == -1)
		{
			// Adjust start position and size
			y = 0;
			height = parentWindowRect.bottom - parentWindowRect.top;
		}
	}

	// create Page Navigator
	CUIExtPageNavigatorWnd* pageNavigator = new CUIExtPageNavigatorWnd(messageWindow, message, controlID);
	windowStyle = ((windowStyle == 0) ? WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS : 0);
	RECT rect;
	rect.left = x;
	rect.top = y;
	rect.right = x + width;
	rect.bottom = y + height;
	pageNavigator->Create(parentWindowClass, rect, controlID, windowStyle, NULL);

	return ((pageNavigator == NULL) ? NULL : pageNavigator->GetSafeHwnd());
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorEnableSplitter(HWND pageNavigatorWindow, BOOL enable, BOOL update)
{
	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		return extPageNavigator->EnableSplitter(enable, update);
	}

	return FALSE;
}

extern "C" __declspec(dllexport) int WINAPI UISalPageNavigatorHitTest(HWND pageNavigatorWindow, int x, int y)
{
	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		POINT ptHitTest;
		ptHitTest.x = x;
		ptHitTest.y = y;
		return extPageNavigator->HitTest(ptHitTest);
	}

	return __EPNWH_NOWHERE;
}

extern "C" __declspec(dllexport) HANDLE WINAPI UISalPageNavigatorHitTestItem(HWND pageNavigatorWindow, int x, int y)
{
	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		POINT ptHitTest;
		ptHitTest.x = x;
		ptHitTest.y = y;
		return (HANDLE)extPageNavigator->HitTestItem(ptHitTest);
	}

	return NULL;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorIsSplitterEnabled(HWND pageNavigatorWindow)
{
	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		return extPageNavigator->IsSplitterEnabled();
	}

	return FALSE;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorIsSplitterVisible(HWND pageNavigatorWindow)
{
	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		return extPageNavigator->IsSplitterVisible();
	}

	return FALSE;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorItemEnabledGet(HWND pageNavigatorWindow, int itemIndex)
{
	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		return extPageNavigator->ItemEnabledGet((LONG)itemIndex);
	}

	return FALSE;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorItemEnabledSet(HWND pageNavigatorWindow, int itemIndex, BOOL enabled, BOOL persistent, BOOL update)
{
	// variables
	BOOL previousEnabledState = FALSE;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		previousEnabledState = extPageNavigator->ItemEnabledGet((LONG)itemIndex);
		extPageNavigator->ItemEnabledSet((LONG)itemIndex, enabled, persistent, update);
	}

	return previousEnabledState;
}

extern "C" __declspec(dllexport) HANDLE WINAPI UISalPageNavigatorItemFindParam(HWND pageNavigatorWindow, LPARAM lParam, int itemIndexStart)
{
	// variables
	HANDLE itemHandle = NULL;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		itemHandle = (HANDLE)extPageNavigator->ItemFind(lParam, (LONG)itemIndexStart);
	}

	return itemHandle;
}

extern "C" __declspec(dllexport) HANDLE WINAPI UISalPageNavigatorItemFindText(HWND pageNavigatorWindow, LPCWSTR text, int itemIndexStart)
{
	// variables
	HANDLE itemHandle = NULL;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		itemHandle = (HANDLE)extPageNavigator->ItemFind(text, (LONG)itemIndexStart);
	}

	return itemHandle;
}

extern "C" __declspec(dllexport) int WINAPI UISalPageNavigatorItemGetCollapsedCount(HWND pageNavigatorWindow)
{
	// variables
	int collapsedCount = -1;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		collapsedCount = extPageNavigator->ItemGetCollapsedCount();
	}

	return collapsedCount;
}

extern "C" __declspec(dllexport) int WINAPI UISalPageNavigatorItemGetCount(HWND pageNavigatorWindow)
{
	// variables
	int itemCount = -1;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		itemCount = extPageNavigator->ItemGetCount();
	}

	return itemCount;
}

extern "C" __declspec(dllexport) int WINAPI UISalPageNavigatorItemGetEnabledCount(HWND pageNavigatorWindow)
{
	// variables
	int enabledCount = -1;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		enabledCount = extPageNavigator->ItemGetEnabledCount();
	}

	return enabledCount;
} // extern "C" __declspec(dllexport) int WINAPI UISalPageNavigatorItemGetEnabledCount(HWND pageNavigatorWindow)

extern "C" __declspec(dllexport) int WINAPI UISalPageNavigatorItemGetExpandedCount(HWND pageNavigatorWindow)
{
	// variables
	int expandedCount = -1;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		expandedCount = extPageNavigator->ItemGetExpandedCount();
	}

	return expandedCount;
}

extern "C" __declspec(dllexport) int WINAPI UISalPageNavigatorItemGetIndexOf(HWND pageNavigatorWindow, HANDLE itemHandle)
{
	// variables
	int itemIndex = -1;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		itemIndex = extPageNavigator->ItemGetIndexOf((CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle);
	}

	return itemIndex;
}

extern "C" __declspec(dllexport) HANDLE WINAPI UISalPageNavigatorItemGetPressed(HWND pageNavigatorWindow)
{
	// variables
	HANDLE itemPressed = NULL;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		itemPressed = extPageNavigator->ItemGetPressed();
	}

	return itemPressed;
}

extern "C" __declspec(dllexport) int WINAPI UISalPageNavigatorItemGetVisibleCount(HWND pageNavigatorWindow)
{
	// variables
	int visibleCount = -1;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		visibleCount = extPageNavigator->ItemGetVisibleCount();
	}

	return visibleCount;
}

extern "C" __declspec(dllexport) HANDLE WINAPI UISalPageNavigatorItemInsert(HWND pageNavigatorWindow, int index, LPCWSTR text, HICON iconExpanded, HICON iconCollapsed, DWORD data, BOOL update)
{
	// variables
	HANDLE itemHandle = NULL;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		itemHandle = (HANDLE)extPageNavigator->ItemInsert((LONG)index, text, iconExpanded, iconCollapsed, data, update);
	}

	return itemHandle;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorItemMove(HWND pageNavigatorWindow, int itemIndex, int itemNewIndex, BOOL persistent, BOOL update)
{
	// variables
	BOOL result = FALSE;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		result = extPageNavigator->ItemMove((LONG)itemIndex, (LONG)itemNewIndex, persistent, update);
	}

	return result;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorItemRemove(HWND pageNavigatorWindow, int itemIndex, BOOL update)
{
	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		extPageNavigator->ItemRemove((LONG)itemIndex, update);
	}

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorItemRemoveAll(HWND pageNavigatorWindow, BOOL update)
{
	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		extPageNavigator->ItemRemoveAll(update);
	}

	return;
}

extern "C" __declspec(dllexport) int WINAPI UISalPageNavigatorItemSetExpandedCount(HWND pageNavigatorWindow, int expandedCount)
{
	// variables
	int previousExpandedCount = -1;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		previousExpandedCount = extPageNavigator->ItemGetExpandedCount();
		extPageNavigator->ItemSetExpandedCount(expandedCount);
	}

	return previousExpandedCount;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorItemsSwap(HWND pageNavigatorWindow, int itemIndex1, int itemIndex2, BOOL persistent, BOOL update)
{
	// variables
	BOOL result = FALSE;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		result = extPageNavigator->ItemsSwap((LONG)itemIndex1, (LONG)itemIndex2, persistent, update);
	}

	return result;
}

extern "C" __declspec(dllexport) int WINAPI UISalPageNavigatorMinPageAreaHeightGet(HWND pageNavigatorWindow)
{
	// variables
	int minPageAreaHeight = -1;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		minPageAreaHeight = extPageNavigator->MinPageAreaHeightGet();
	}

	return minPageAreaHeight;
}

extern "C" __declspec(dllexport) int WINAPI UISalPageNavigatorMinPageAreaHeightSet(HWND pageNavigatorWindow, int minPageAreaHeight)
{
	// variables
	int previousMinPageAreaHeight = -1;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		previousMinPageAreaHeight = extPageNavigator->MinPageAreaHeightGet();
		extPageNavigator->MinPageAreaHeightSet(minPageAreaHeight);
	}

	return previousMinPageAreaHeight;
}

extern "C" __declspec(dllexport) int WINAPI UISalPageNavigatorSelectionGet(HWND pageNavigatorWindow)
{
	// variables
	int selection = -1;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		selection = extPageNavigator->SelectionGet();
	}

	return selection;
}

extern "C" __declspec(dllexport) int WINAPI UISalPageNavigatorSelectionSetIndex(HWND pageNavigatorWindow, int itemIndex)
{
	// variables
	int previousSelection = -1;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		previousSelection = extPageNavigator->SelectionGet();
		extPageNavigator->SelectionSet((LONG)itemIndex);
	}

	return previousSelection;
}

extern "C" __declspec(dllexport) int WINAPI UISalPageNavigatorSelectionSetHandle(HWND pageNavigatorWindow, HANDLE itemHandle)
{
	// variables
	int previousSelection = -1;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		previousSelection = extPageNavigator->SelectionGet();
		extPageNavigator->SelectionSet((CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle);
	}

	return previousSelection;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorShowSplitter(HWND pageNavigatorWindow, BOOL show, BOOL update)
{
	// variables
	BOOL previousVisible = FALSE;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		previousVisible = extPageNavigator->ShowSplitter(show, update);
	}

	return previousVisible;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorStateLoad(HWND pageNavigatorWindow, LPCWSTR company, LPCWSTR product, LPCWSTR profile, BOOL persistent, HKEY keyRoot)
{
	// variables
	BOOL result = FALSE;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		result = extPageNavigator->StateLoad(company, product, profile, persistent, keyRoot);
	}

	return result;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorStateReset(HWND pageNavigatorWindow, BOOL persistent)
{
	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		extPageNavigator->StateReset(persistent);
	}

	return;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorStateSave(HWND pageNavigatorWindow, LPCWSTR company, LPCWSTR product, LPCWSTR profile, HKEY keyRoot)
{
	// variables
	BOOL result = FALSE;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		result = extPageNavigator->StateSave(company, product, profile, keyRoot);
	}

	return result;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorUpdateWindow(HWND pageNavigatorWindow, BOOL update)
{
	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		extPageNavigator->UpdatePageNavigatorWnd(update);
	}

	return;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorShowConfigButton(HWND pageNavigatorWindow, BOOL show, BOOL update)
{
	// variables
	BOOL previousVisible = FALSE;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		previousVisible = extPageNavigator->ShowConfigButton(show, update);
	}

	return previousVisible;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorIsConfigButtonVisible(HWND pageNavigatorWindow)
{
	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		return extPageNavigator->IsConfigButtonVisible();
	}

	return FALSE;
}

extern "C" __declspec(dllexport) HANDLE WINAPI UISalPageNavigatorItemPaneGetPressed(HWND pageNavigatorWindow)
{
	// variables
	HANDLE itemPressed = NULL;

	// access page navigator
	CUIExtPageNavigatorWnd* extPageNavigator = (CUIExtPageNavigatorWnd*)CUIExtPageNavigatorWnd::FromHandlePermanent(pageNavigatorWindow);
	if (extPageNavigator != NULL)
	{
		itemPressed = (HANDLE)extPageNavigator->ItemPaneGetPressed();
	}

	return itemPressed;
}


extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorPageItemTextGet(HANDLE itemHandle, LPWSTR text, DWORD textSize)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	__EXT_MFC_SAFE_LPCTSTR itemText = pageItem->TextGet();
	wcscpy_s(text, textSize, itemText);

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorPageItemTextSet(HANDLE itemHandle, LPCWSTR text)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	pageItem->TextSet(text);

	return;
}

extern "C" __declspec(dllexport) LPARAM WINAPI UISalPageNavigatorPageItemLParamGet(HANDLE itemHandle)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	return pageItem->LParamGet();
}

extern "C" __declspec(dllexport) LPARAM WINAPI UISalPageNavigatorPageItemLParamSet(HANDLE itemHandle, LPARAM param)
{
	// variables
	LPARAM previousParam = 0;

	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	previousParam = pageItem->LParamGet();
	pageItem->LParamSet(param);
	return previousParam;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorPageItemTooltipGet(HANDLE itemHandle, LPWSTR tooltip, DWORD tooltipSize)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	__EXT_MFC_SAFE_LPCTSTR itemTooltip = pageItem->TooltipGet();
	wcscpy_s(tooltip, tooltipSize, itemTooltip);

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorPageItemTooltipSet(HANDLE itemHandle, LPCWSTR tooltip)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	pageItem->TooltipSet(tooltip);

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorPageItemIconGetSize(HANDLE itemHandle, BOOL expanded, LONG* width, LONG* height)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	CSize size = pageItem->IconGetSize(expanded);
	*width = size.cx;
	*height = size.cy;

	return;
}

extern "C" __declspec(dllexport) HICON WINAPI UISalPageNavigatorPageItemIconGetHandle(HANDLE itemHandle, BOOL expanded)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	CExtCmdIcon* iconPtr = pageItem->IconGetPtr(expanded);
	return iconPtr->ExtractHICON();
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorPageItemIconSet(HANDLE itemHandle, HICON icon, BOOL expanded)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	pageItem->IconSet(icon, expanded);
	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorPageItemShow(HANDLE itemHandle)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	pageItem->Show();
	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorPageItemHide(HANDLE itemHandle)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	pageItem->Hide();
	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorPageItemVisibleSet(HANDLE itemHandle, BOOL visible)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	if (visible)
	{
		pageItem->Show();
	}
	else
	{
		pageItem->Hide();
	}
	return;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorPageItemEnabledGet(HANDLE itemHandle)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	return pageItem->EnabledGet();
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorPageItemEnabledSet(HANDLE itemHandle, BOOL enabled, BOOL persistent)
{
	// variables
	BOOL previousEnabled = FALSE;

	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	previousEnabled = pageItem->EnabledGet();
	pageItem->EnabledSet(enabled, persistent);
	return previousEnabled;
}

extern "C" __declspec(dllexport) HANDLE WINAPI UISalPageNavigatorPageItemHitTestPane(HANDLE itemHandle, int x, int y)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	POINT point;
	point.x = x;
	point.y = y;
	return (HANDLE)pageItem->HitTestPane(point);
}

extern "C" __declspec(dllexport) HANDLE WINAPI UISalPageNavigatorPageItemPaneInsert(HANDLE itemHandle, HWND paneWindow, int index, LPCWSTR text, int height, BOOL update)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	return (HANDLE)pageItem->PaneInsert(paneWindow, index, text, height, update);
}

extern "C" __declspec(dllexport) HANDLE WINAPI UISalPageNavigatorPageItemPaneGetHandle(HANDLE itemHandle, int index)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	return (HANDLE)pageItem->PaneGetInfo((LONG)index);
}

extern "C" __declspec(dllexport) int WINAPI UISalPageNavigatorPageItemPaneGetCount(HANDLE itemHandle)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	return (int)pageItem->PaneGetCount();
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorPageItemPaneRemove(HANDLE itemHandle, int index, BOOL update)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	return pageItem->PaneRemove((LONG)index, update);
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorPageItemPaneRemoveAll(HANDLE itemHandle, BOOL update)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	return pageItem->PaneRemoveAll(update);
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorPageItemPaneExpand(HANDLE itemHandle, int index, int expandType, BOOL update)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	return pageItem->PaneExpand((LONG)index, (CUIExtPageNavigatorWnd::ITEM_PANE_INFO::e_ExpandType_t)expandType, update);
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorPageItemPaneIsExpanded(HANDLE itemHandle, int index)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	return pageItem->PaneIsExpanded((LONG)index);
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorPageItemPaneExpandableGet(HANDLE itemHandle, int index)
{
	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	return pageItem->PaneExpandableGet((LONG)index);
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorPageItemPaneExpandableSet(HANDLE itemHandle, int index, BOOL expandable)
{
	// variables
	BOOL previousExpandable = FALSE;

	// access page navigator item
	CUIExtPageNavigatorWnd::PAGE_ITEM_INFO* pageItem = (CUIExtPageNavigatorWnd::PAGE_ITEM_INFO*)itemHandle;

	// call the function
	previousExpandable = pageItem->PaneExpandableGet((LONG)index);
	pageItem->PaneExpandableSet((LONG)index, expandable);
	return previousExpandable;
}

extern "C" __declspec(dllexport) HWND WINAPI UISalPageNavigatorPaneItemGetSafeHwnd(HANDLE paneItemHandle)
{
	// access page navigator pane item
	CUIExtPageNavigatorWnd::ITEM_PANE_INFO* paneItem = (CUIExtPageNavigatorWnd::ITEM_PANE_INFO*)paneItemHandle;

	// call the function
	return paneItem->GetSafeHwnd();
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorPaneItemTextGet(HANDLE paneItemHandle, LPWSTR text, DWORD textSize)
{
	// access page navigator pane item
	CUIExtPageNavigatorWnd::ITEM_PANE_INFO* paneItem = (CUIExtPageNavigatorWnd::ITEM_PANE_INFO*)paneItemHandle;

	// call the function
	__EXT_MFC_SAFE_LPCTSTR itemText = paneItem->TextGet();
	wcscpy_s(text, textSize, itemText);

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorPaneItemTextSet(HANDLE paneItemHandle, LPCWSTR text)
{
	// access page navigator pane item
	CUIExtPageNavigatorWnd::ITEM_PANE_INFO* paneItem = (CUIExtPageNavigatorWnd::ITEM_PANE_INFO*)paneItemHandle;

	// call the function
	paneItem->TextSet(text);

	return;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorPaneItemExpand(HANDLE paneItemHandle, int expandType, BOOL update)
{
	// access page navigator pane item
	CUIExtPageNavigatorWnd::ITEM_PANE_INFO* paneItem = (CUIExtPageNavigatorWnd::ITEM_PANE_INFO*)paneItemHandle;

	// call the function
	return paneItem->Expand((CUIExtPageNavigatorWnd::ITEM_PANE_INFO::e_ExpandType_t)expandType, update);
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorPaneItemIsExpanded(HANDLE paneItemHandle)
{
	// access page navigator pane item
	CUIExtPageNavigatorWnd::ITEM_PANE_INFO* paneItem = (CUIExtPageNavigatorWnd::ITEM_PANE_INFO*)paneItemHandle;

	// call the function
	return paneItem->IsExpanded();
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorPaneItemExpandableGet(HANDLE paneItemHandle)
{
	// access page navigator pane item
	CUIExtPageNavigatorWnd::ITEM_PANE_INFO* paneItem = (CUIExtPageNavigatorWnd::ITEM_PANE_INFO*)paneItemHandle;

	// call the function
	return paneItem->ExpandableGet();
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalPageNavigatorPaneItemExpandableSet(HANDLE paneItemHandle, BOOL expandable)
{
	// variables
	BOOL previousExpandable = FALSE;

	// access page navigator pane item
	CUIExtPageNavigatorWnd::ITEM_PANE_INFO* paneItem = (CUIExtPageNavigatorWnd::ITEM_PANE_INFO*)paneItemHandle;

	// call the function
	previousExpandable = paneItem->ExpandableGet();
	paneItem->ExpandableSet(expandable);
	return previousExpandable;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorPaneItemRectGet(HANDLE paneItemHandle, LONG* x, LONG* y, LONG* width, LONG* height)
{
	// access page navigator pane item
	CUIExtPageNavigatorWnd::ITEM_PANE_INFO* paneItem = (CUIExtPageNavigatorWnd::ITEM_PANE_INFO*)paneItemHandle;

	// call the function
	CRect rect = paneItem->ItemRectGet();
	*x = rect.left;
	*y = rect.top;
	*width = rect.right - rect.left;
	*height = rect.bottom - rect.top;

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorPaneItemRectSet(HANDLE paneItemHandle, LONG x, LONG y, LONG width, LONG height)
{
	// access page navigator pane item
	CUIExtPageNavigatorWnd::ITEM_PANE_INFO* paneItem = (CUIExtPageNavigatorWnd::ITEM_PANE_INFO*)paneItemHandle;

	// call the function
	paneItem->ItemRectSet((int)x, (int)y, (int)(x + width), (int)(y + height));

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorPaneItemRectSetEmpty(HANDLE paneItemHandle)
{
	// access page navigator pane item
	CUIExtPageNavigatorWnd::ITEM_PANE_INFO* paneItem = (CUIExtPageNavigatorWnd::ITEM_PANE_INFO*)paneItemHandle;

	// call the function
	paneItem->ItemRectSetEmpty();

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorPaneItemCaptionRectGet(HANDLE paneItemHandle, LONG* x, LONG* y, LONG* width, LONG* height)
{
	// access page navigator pane item
	CUIExtPageNavigatorWnd::ITEM_PANE_INFO* paneItem = (CUIExtPageNavigatorWnd::ITEM_PANE_INFO*)paneItemHandle;

	// call the function
	CRect rect = paneItem->CaptionRectGet();
	*x = rect.left;
	*y = rect.top;
	*width = rect.right - rect.left;
	*height = rect.bottom - rect.top;

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorPaneItemCaptionRectSet(HANDLE paneItemHandle, LONG x, LONG y, LONG width, LONG height)
{
	// access page navigator pane item
	CUIExtPageNavigatorWnd::ITEM_PANE_INFO* paneItem = (CUIExtPageNavigatorWnd::ITEM_PANE_INFO*)paneItemHandle;

	// call the function
	paneItem->CaptionRectSet((int)x, (int)y, (int)(x + width), (int)(y + height));

	return;
}

extern "C" __declspec(dllexport) void WINAPI UISalPageNavigatorPaneItemCaptionRectSetEmpty(HANDLE paneItemHandle)
{
	// access page navigator pane item
	CUIExtPageNavigatorWnd::ITEM_PANE_INFO* paneItem = (CUIExtPageNavigatorWnd::ITEM_PANE_INFO*)paneItemHandle;

	// call the function
	paneItem->CaptionRectSetEmpty();

	return;
}

extern "C" __declspec(dllexport) int WINAPI UISalPageNavigatorPaneItemHeightGet(HANDLE paneItemHandle)
{
	// access page navigator pane item
	CUIExtPageNavigatorWnd::ITEM_PANE_INFO* paneItem = (CUIExtPageNavigatorWnd::ITEM_PANE_INFO*)paneItemHandle;

	// call the function
	return paneItem->HeightGet();
}

extern "C" __declspec(dllexport) int WINAPI UISalPageNavigatorPaneItemHeightSet(HANDLE paneItemHandle, int height)
{
	// variables
	int previousHeight = -1;

	// access page navigator pane item
	CUIExtPageNavigatorWnd::ITEM_PANE_INFO* paneItem = (CUIExtPageNavigatorWnd::ITEM_PANE_INFO*)paneItemHandle;

	// call the function
	previousHeight = paneItem->HeightGet();
	paneItem->HeightSet(height);
	return previousHeight;
}

extern "C" __declspec(dllexport) LPARAM WINAPI UISalPageNavigatorPaneItemLParamGet(HANDLE paneItemHandle)
{
	// access page navigator pane item
	CUIExtPageNavigatorWnd::ITEM_PANE_INFO* paneItem = (CUIExtPageNavigatorWnd::ITEM_PANE_INFO*)paneItemHandle;

	// call the function
	return paneItem->LParamGet();
}

extern "C" __declspec(dllexport) LPARAM WINAPI UISalPageNavigatorPaneItemLParamSet(HANDLE paneItemHandle, LPARAM param)
{
	// variables
	LPARAM previousParam = 0;

	// access page navigator pane item
	CUIExtPageNavigatorWnd::ITEM_PANE_INFO* paneItem = (CUIExtPageNavigatorWnd::ITEM_PANE_INFO*)paneItemHandle;

	// call the function
	previousParam = paneItem->LParamGet();
	paneItem->LParamSet(param);
	return previousParam;
}
