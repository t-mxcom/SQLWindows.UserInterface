#include "stdafx.h"

#if (!defined __SQLWUI_UIEXTPAGENAVIGATORWND_H)
	#include "CUIExtPageNavigatorWnd.h"
#endif

#include "TeamDeveloperConstants.h"

CUIExtPageNavigatorWnd::CUIExtPageNavigatorWnd(HWND messageWindow, UINT message, UINT controlID) :
		CExtPageNavigatorWnd(),
		m_hWndMessage(messageWindow),
		m_uiMessage(message),
		m_uiControlID(controlID)
{
	// set the message receiver
	// g_nMsgSelectionNotification = message;
	m_hWndNotificationReceiver = messageWindow;
}
