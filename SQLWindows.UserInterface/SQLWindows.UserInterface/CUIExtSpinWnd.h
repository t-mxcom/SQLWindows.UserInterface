#if (!defined __SQLWUI_UIEXTSPINWND_H)
#define __SQLWUI_UIEXTSPINWND_H

#include "Prof-UIS.h"

#if (!defined __EXT_MFC_DEF_H)
	#include <ExtMfcDef.h>
#endif

#if _MSC_VER > 1000
#pragma once
#endif

//////////////////////////////////////////////////////////////////////////////
// CUIExtSpinWnd constants

class CUIExtSpinWnd : public CExtSpinWnd
{
public:
	CUIExtSpinWnd(UINT message);

	LRESULT SendNotification(int position, int delta);
	void ManageFieldEdit();
protected:

private:
	UINT m_uiMessage;		// number of message to be sent on value changes
};

#endif
