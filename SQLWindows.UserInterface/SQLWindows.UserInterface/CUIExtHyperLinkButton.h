#if (!defined __SQLWUI_UIEXTHYPERLINKBUTTON_H)
#define __SQLWUI_UIEXTHYPERLINKBUTTON_H

#include "Prof-UIS.h"

#if (!defined __EXT_MFC_DEF_H)
	#include <ExtMfcDef.h>
#endif

#if _MSC_VER > 1000
#pragma once
#endif

//////////////////////////////////////////////////////////////////////////////
// CUIExtHyperLinkButton constants
#define	UIEXTHYPERLINKBUTTON_CLICK_CONTINUE		0	// continue handling the click
#define	UIEXTHYPERLINKBUTTON_CLICK_CANCEL		-1	// cancel handling the click

class CUIExtHyperLinkButton : public CExtHyperLinkButton
{
public:
	CUIExtHyperLinkButton(HWND messageWindow, UINT message, UINT controlID);
protected:
	virtual void _OnClick(bool bSelectAny, bool bSeparatedDropDownClicked);

private:
	HWND m_hWndMessage;		// handle of the message receiving window
	UINT m_uiMessage;		// number of message to be sent on click
	UINT m_uiControlID;		// ID of the control
};

#endif
