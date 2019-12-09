#if defined(_TD51)
	#include "../ProfUI/inc.51/Prof-UIS.h"
	#ifdef INCLUDE_EXTMSGBOX
		#include "ExtMsgBox.h"
	#endif
#elif defined(_TD52SP1)
	#include "../ProfUI/inc.52.sp1/Prof-UIS.h"
	#ifdef INCLUDE_EXTMSGBOX
		#include "ExtMsgBox.h"
	#endif
#elif defined(_TD52SP2)
	#include "../ProfUI/inc.52.sp2/Prof-UIS.h"
	#ifdef INCLUDE_EXTMSGBOX
		#include "ExtMsgBox.h"
	#endif
#elif defined(_TD60RTM)
	#include "../ProfUI/inc.60.rtm/Prof-UIS.h"
	#define	ComboBoxSupportsCaseSensitiveAutoComplete
	#define TabIsCExtTabPageContainerWnd
	#define LabelSupportsTooltip
#elif defined(_TD60SP2)
	#include "../ProfUI/inc.60.sp2/Prof-UIS.h"
	#define	ComboBoxSupportsCaseSensitiveAutoComplete
	#define TabIsCExtTabPageContainerWnd
	#define LabelSupportsTooltip
#elif defined(_TD60SP3)
	#include "../ProfUI/inc.60.sp3/Prof-UIS.h"
	#define	ComboBoxSupportsCaseSensitiveAutoComplete
	#define TabIsCExtTabPageContainerWnd
	#define LabelSupportsTooltip
#elif defined(_TD60SP5)
	#include "../ProfUI/inc.60.sp5/Prof-UIS.h"
	#define	ComboBoxSupportsCaseSensitiveAutoComplete
	#define TabIsCExtTabPageContainerWnd
	#define LabelSupportsTooltip
#elif defined(_TD61RTM)
	#include "../ProfUI/inc.61.rtm/Prof-UIS.h"
	#define	ComboBoxSupportsCaseSensitiveAutoComplete
	#define TabIsCExtTabPageContainerWnd
	#define LabelSupportsTooltip
#elif defined(_TD61SP3R)
	#include "../ProfUI/inc.61.sp3r/Prof-UIS.h"
	#define	ComboBoxSupportsCaseSensitiveAutoComplete
	#define TabIsCExtTabPageContainerWnd
	#define LabelSupportsTooltip
#elif defined(_TD61SP4)
	#include "../ProfUI/inc.61.sp4/Prof-UIS.h"
	#define	ComboBoxSupportsCaseSensitiveAutoComplete
	#define TabIsCExtTabPageContainerWnd
	#define LabelSupportsTooltip
#elif defined(_TD61SP5)
	#include "../ProfUI/inc.61.sp5/Prof-UIS.h"
	#define	ComboBoxSupportsCaseSensitiveAutoComplete
	#define TabIsCExtTabPageContainerWnd
	#define LabelSupportsTooltip
#elif defined(_TD62RTM)
	#include "../ProfUI/inc.62.rtm/Prof-UIS.h"
	#define	ComboBoxSupportsCaseSensitiveAutoComplete
	#define TabIsCExtTabPageContainerWnd
	#define LabelSupportsTooltip
#elif defined(_TD62SP1)
	#include "../ProfUI/inc.62.sp1/Prof-UIS.h"
	#define	ComboBoxSupportsCaseSensitiveAutoComplete
	#define TabIsCExtTabPageContainerWnd
	#define LabelSupportsTooltip
#elif defined(_TD63RTM)
	#include "../ProfUI/inc.63.rtm/Prof-UIS.h"
	#define	ComboBoxSupportsCaseSensitiveAutoComplete
	#define TabIsCExtTabPageContainerWnd
	#define LabelSupportsTooltip
#elif defined(_TD63SP1)
	#include "../ProfUI/inc.63.sp1/Prof-UIS.h"
	#define	ComboBoxSupportsCaseSensitiveAutoComplete
	#define TabIsCExtTabPageContainerWnd
	#define LabelSupportsTooltip
#endif
