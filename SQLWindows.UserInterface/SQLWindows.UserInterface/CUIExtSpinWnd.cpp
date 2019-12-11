#include "stdafx.h"

#if (!defined __SQLWUI_UIEXTSPINWND_H)
	#include "CUIExtSpinWnd.h"
#endif

#include "TeamDeveloperConstants.h"
#include "DynamicSalAPI.h"

CUIExtSpinWnd::CUIExtSpinWnd(UINT message) :
		CExtSpinWnd(),
		m_uiMessage(message)
{
}

LRESULT CUIExtSpinWnd::SendNotification(int position, int delta)
{
	// send the message to the buddy control
	LRESULT result = 0;
	CWnd* buddy = this->GetBuddy();
	if (buddy != NULL)
	{
		result = buddy->SendMessage(m_uiMessage, (WPARAM)position, (LPARAM)delta);
	}

	return result;
}

void CUIExtSpinWnd::ManageFieldEdit()
{
	// get buddy
	CWnd* buddy = this->GetBuddy();
	if (buddy != NULL)
	{
		// set field edit
		DSalSetFieldEdit(buddy->GetSafeHwnd(), TRUE);

		// send SAM_AnyEdit
		buddy->PostMessageW(SAM_AnyEdit, 0, 0);
	}
}
