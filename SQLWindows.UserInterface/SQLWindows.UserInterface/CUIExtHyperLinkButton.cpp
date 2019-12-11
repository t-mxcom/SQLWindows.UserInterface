#include "stdafx.h"

#if (!defined __SQLWUI_UIEXTHYPERLINKBUTTON_H)
	#include "CUIExtHyperLinkButton.h"
#endif

#include "TeamDeveloperConstants.h"

CUIExtHyperLinkButton::CUIExtHyperLinkButton(HWND messageWindow, UINT message, UINT controlID) :
		CExtHyperLinkButton(),
		m_hWndMessage(messageWindow),
		m_uiMessage(message),
		m_uiControlID(controlID)
{
}

void CUIExtHyperLinkButton::_OnClick(bool bSelectAny, bool bSeparatedDropDownClicked)
{
	// send SAM_Click to window
	LRESULT lresult = ::SendMessageW(m_hWndMessage, m_uiMessage, 0, 0);
	if (lresult == UIEXTHYPERLINKBUTTON_CLICK_CANCEL)
	{
		// no click handling
		return;
	}

	CExtHyperLinkButton::_OnClick(bSelectAny, bSeparatedDropDownClicked);
	m_bVisited = TRUE;
}
