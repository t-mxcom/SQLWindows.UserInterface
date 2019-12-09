#include "stdafx.h"
#include "Prof-UIS.h"

class UISalExtTabMdiWnd : public CExtTMDBS<CExtTabMdiWnd>
{
protected:
	//virtual void OnTabWndSyncVisibility()
	//{
	//	// if tab items found, show tab bar, else hide it
	//	bool showTab = (ItemGetCount() > 0);
	//	ShowWindow(showTab ? SW_SHOW : SW_HIDE);
	//	CExtTMDBS<CExtTabMdiWnd>::OnTabWndSyncVisibility();
	//} // virtual void OnTabWndSyncVisibility()

	//virtual void OnTabWndItemInsert(
	//	LONG nItemIndex,
	//	TAB_ITEM_INFO * pTii
	//	)
	//{
	//	// update visibility
	//	OnTabWndSyncVisibility();

	//	// update parent window
	//	UpdateParentFrame();
	//} // virtual void OnTabWndItemInsert( ...

private:
	//void UpdateParentFrame()
	//{
	//	CFrameWnd* parentWindow = GetParentFrame();
	//	if (NULL != parentWindow)
	//	{
	//		parentWindow->RecalcLayout();
	//	} // if (NULL != parentWindow)
	//} // void UpdateParentFrame()
};

extern "C" __declspec(dllexport) int WINAPI UISalMDIWindowsListShow(HWND mdiFrameHandle, HWND parentWindowHandle)
{
	// access parent window
	CWnd* parentWindow = ((parentWindowHandle == NULL) ? NULL : CWnd::FromHandlePermanent(parentWindowHandle));

	CExtMdiWindowsListDlg mdiWindowsList(mdiFrameHandle, parentWindow);
	return (int)mdiWindowsList.DoModal();
}

extern "C" __declspec(dllexport) HANDLE WINAPI UISalMDIWindowsTabBarCreate(HWND parentWindow)
{
	// access mdi frame window
	CExtNCW<CMDIFrameWnd>* mdiFrameWindow = (CExtNCW<CMDIFrameWnd>*)CWnd::FromHandlePermanent(parentWindow);

	// create mdi windows tab bar
	UISalExtTabMdiWnd* tab = new UISalExtTabMdiWnd();
	tab->Create(
		mdiFrameWindow,
		CRect(0, 0, 0, 0),
		UINT(__EXT_MFC_IDC_STATIC),
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS,
		__ETWS_ORIENT_TOP | __ETWS_AUTOHIDE_SCROLL | __ETWS_SHOW_BTN_TAB_LIST | __ETWS_ENABLED_BTN_TAB_LIST);
	tab->ModifyTabWndStyleEx(0, __ETWS_EX_CLOSE_ON_TABS, true);
	//tab->UpdateWindow();

	mdiFrameWindow->RecalcLayout();

	return (HANDLE)tab;
}

extern "C" __declspec(dllexport) void WINAPI UISalMDIWindowsTabBarDestroy(HANDLE tabBarHandle)
{
	// verify pointer
	if (tabBarHandle != NULL)
	{
		// cast to object pointer and delete it
		UISalExtTabMdiWnd* tab = (UISalExtTabMdiWnd*)tabBarHandle;
		HWND parentWindow = tab->GetParent()->m_hWnd;
		tab->DestroyWindow();

		// send WM_SIZE to parent, so the bar gets updated
		RECT rect;
		::GetWindowRect(parentWindow, &rect);
		::SendMessage(parentWindow, WM_SIZE, SIZE_RESTORED, MAKELPARAM(rect.right - rect.left, rect.bottom - rect.top));
	}

	return;
}
