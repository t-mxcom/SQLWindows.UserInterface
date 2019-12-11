#if (!defined __SQLWUI_UIEXTPAGENAVIGATORWND_H)
#define __SQLWUI_UIEXTPAGENAVIGATORWND_H

#include "Prof-UIS.h"

#if (!defined __EXT_MFC_DEF_H)
	#include <ExtMfcDef.h>
#endif

#if _MSC_VER > 1000
#pragma once
#endif

//////////////////////////////////////////////////////////////////////////////
// CUIExtPageNavigatorWnd constants

class CUIExtPageNavigatorWnd : public CExtPageNavigatorWnd
{
public:
	CUIExtPageNavigatorWnd(HWND messageWindow, UINT message, UINT controlID);
protected:

private:
	HWND m_hWndMessage;		// handle of the message receiving window
	UINT m_uiMessage;		// number of message to be sent on click
	UINT m_uiControlID;		// ID of the control
};

#endif
