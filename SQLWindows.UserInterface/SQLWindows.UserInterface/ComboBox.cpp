#include "stdafx.h"
#include "Prof-UIS.h"

// internal function to support multi column ComboBoxes
void uiSalComboBoxEnsureStyle(HWND comboBoxHandle)
{
	// enable CBS_OWNERDRAWFIXED style
	LONG style = ::GetWindowLongW(comboBoxHandle, GWL_STYLE);
	if ((style & CBS_OWNERDRAWFIXED) == 0)
	{
		style |= CBS_OWNERDRAWFIXED;
		::SetWindowLongW(comboBoxHandle, GWL_STYLE, style);
	}
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalComboBoxGetAutoComplete(HWND comboBoxHandle)
{
	// get access to ComboBox
	CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
	if (extComboBox != NULL)
	{
		return extComboBox->m_bEnableAutoComplete;
	}

	return FALSE;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalComboBoxSetAutoComplete(HWND comboBoxHandle, BOOL autoComplete)
{
	// variables
	BOOL previousAutoComplete = FALSE;

	// get access to ComboBox
	CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
	if (extComboBox != NULL)
	{
		// read previous value
		previousAutoComplete = extComboBox->m_bEnableAutoComplete;

		// set new value
		extComboBox->m_bEnableAutoComplete = autoComplete;
	}

	return previousAutoComplete;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalComboBoxGetUseCaseSensitiveAutoComplete(HWND comboBoxHandle)
{
	// variables
	BOOL useCaseSensitiveAutoComplete = FALSE;

#ifdef ComboBoxSupportsCaseSensitiveAutoComplete
	// get access to ComboBox
	CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
	if (extComboBox != NULL)
	{
		useCaseSensitiveAutoComplete = extComboBox->m_bUseCaseSensitiveAutoComplete;
	}
#endif

	return useCaseSensitiveAutoComplete;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalComboBoxSetUseCaseSensitiveAutoComplete(HWND comboBoxHandle, BOOL useCaseSensitiveAutoComplete)
{
	// variables
	BOOL previousUseCaseSensitiveAutoComplete = FALSE;

#ifdef ComboBoxSupportsCaseSensitiveAutoComplete
	// get access to ComboBox
	CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
	if (extComboBox != NULL)
	{
		// read previous value
		previousUseCaseSensitiveAutoComplete = extComboBox->m_bUseCaseSensitiveAutoComplete;

		// set new value
		extComboBox->m_bUseCaseSensitiveAutoComplete = useCaseSensitiveAutoComplete;
	}
#endif

	return previousUseCaseSensitiveAutoComplete;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalComboBoxGetAutoFilter(HWND comboBoxHandle)
{
	// get access to ComboBox
	CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
	if (extComboBox != NULL)
	{
		return extComboBox->m_bEnableAutoFilter;
	}

	return FALSE;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalComboBoxSetAutoFilter(HWND comboBoxHandle, BOOL autoFilter)
{
	// variables
	BOOL previousAutoFilter = FALSE;

	// get access to ComboBox
	CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
	if (extComboBox != NULL)
	{
		// read previous value
		previousAutoFilter = extComboBox->m_bEnableAutoFilter;

		// set new value
		extComboBox->m_bEnableAutoFilter = autoFilter;
	}

	return previousAutoFilter;
}

extern "C" __declspec(dllexport) void WINAPI UISalComboBoxShowFilterPopupList(HWND comboBoxHandle, LPCWSTR filterText)
{
	// get access to ComboBox
	CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
	if (extComboBox != NULL)
	{
		// call method
		CExtSafeString safeFilterText;
		safeFilterText = filterText;
		extComboBox->ShowFilterPopupList(safeFilterText);
	}
}

extern "C" __declspec(dllexport) void WINAPI UISalComboBoxGetFilterPopupListSize(HWND comboBoxHandle, LONG* width, LONG* height)
{
	// get access to ComboBox
	CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
	if (extComboBox != NULL)
	{
		// get size
		CSize filterPopupListSize = extComboBox->GetFilterPopupListSize();
		*width = filterPopupListSize.cx;
		*height = filterPopupListSize.cy;
	}
}

extern "C" __declspec(dllexport) void WINAPI UISalComboBoxSetFilterPopupListSize(HWND comboBoxHandle, LONG width, LONG height)
{
	// get access to ComboBox
	CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
	if (extComboBox != NULL)
	{
		// set size
		CSize filterPopupListSize;
		filterPopupListSize.cx = width;
		filterPopupListSize.cy = height;
		extComboBox->SetFilterPopupListSize(filterPopupListSize);
	}
}

extern "C" __declspec(dllexport) HANDLE WINAPI UISalComboBoxItemGet(HWND comboBoxHandle, LONG item)
{
	// variables
	HANDLE itemHandle = NULL;

	// get access to ComboBox
	CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
	if (extComboBox != NULL)
	{
		// read value
		itemHandle = (HANDLE)extComboBox->LbItemGet(item);
	}

	return itemHandle;
}

extern "C" __declspec(dllexport) LONG WINAPI UISalComboBoxColumnWidthGet(HWND comboBoxHandle, LONG columnNumber)
{
	// variables
	LONG columnWidth = 0;

	// get access to ComboBox
	CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
	if (extComboBox != NULL)
	{
		// read value
		columnWidth = extComboBox->LbColumnWidthGet(columnNumber);
	}

	return columnWidth;
}

extern "C" __declspec(dllexport) LONG WINAPI UISalComboBoxColumnWidthSet(HWND comboBoxHandle, LONG columnNumber, LONG width)
{
	// variables
	LONG previousColumnWidth = TRUE;

	// ensure ComboBox style
	uiSalComboBoxEnsureStyle(comboBoxHandle);

	// get access to ComboBox
	CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
	if (extComboBox != NULL)
	{
		// read previous value
		previousColumnWidth = extComboBox->LbColumnWidthGet(columnNumber);

		// set new value
		extComboBox->LbColumnWidthSet(columnNumber, width);
	}

	return previousColumnWidth;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalComboBoxItemIsEnabled(HWND comboBoxHandle, LONG item)
{
	// variables
	BOOL itemEnabled = TRUE;

	// get access to ComboBox
	CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
	if (extComboBox != NULL)
	{
		// read value
		itemEnabled = extComboBox->LbItemIsEnabled(item);
	}

	return itemEnabled;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalComboBoxItemEnable(HWND comboBoxHandle, LONG item, BOOL enable)
{
	// variables
	BOOL previousItemEnable = TRUE;

	// ensure ComboBox style
	uiSalComboBoxEnsureStyle(comboBoxHandle);

	// get access to ComboBox
	CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
	if (extComboBox != NULL)
	{
		// read previous value
		previousItemEnable = extComboBox->LbItemIsEnabled(item);

		// set new value
		extComboBox->LbItemEnable(item, enable);
	}

	return previousItemEnable;
}

extern "C" __declspec(dllexport) int WINAPI UISalComboBoxItemCellInsert(HWND comboBoxHandle, HANDLE itemHandle, LPCWSTR itemText, int position)
{
	// variables
	int newCellIndex = -1;

	// ensure, that an item handle was passed
	if (itemHandle != NULL)
	{
		// ensure ComboBox style
		uiSalComboBoxEnsureStyle(comboBoxHandle);

		// get access to ComboBox
		CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
		if (extComboBox != NULL)
		{
			// insert cell
			CExtComboBox::LB_ITEM* item = (CExtComboBox::LB_ITEM*)itemHandle;
			newCellIndex = item->LbItemCellInsert(itemText, position);
		}
	}

	return newCellIndex;
}

extern "C" __declspec(dllexport) BOOL WINAPI UISalComboBoxItemCellRemove(HWND comboBoxHandle, HANDLE itemHandle, LONG cell)
{
	// variables
	BOOL cellRemoved = FALSE;

	// ensure, that an item handle was passed
	if (itemHandle != NULL)
	{
		// ensure ComboBox style
		uiSalComboBoxEnsureStyle(comboBoxHandle);

		// get access to ComboBox
		CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
		if (extComboBox != NULL)
		{
			// remove cell
			CExtComboBox::LB_ITEM* item = (CExtComboBox::LB_ITEM*)itemHandle;
			cellRemoved = item->LbItemCellRemove(cell);
		}
	}

	return cellRemoved;
}

extern "C" __declspec(dllexport) HANDLE WINAPI UISalComboBoxItemCellGet(HWND comboBoxHandle, HANDLE itemHandle, LONG cell)
{
	// variables
	HANDLE cellHandle = NULL;

	// ensure, that an item handle was passed
	if (itemHandle != NULL)
	{
		// ensure ComboBox style
		uiSalComboBoxEnsureStyle(comboBoxHandle);

		// get access to ComboBox
		CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
		if (extComboBox != NULL)
		{
			// get cell handle
			CExtComboBox::LB_ITEM* item = (CExtComboBox::LB_ITEM*)itemHandle;
			cellHandle = (HANDLE)item->LbItemCellGet(cell);
		}
	}

	return cellHandle;
}

extern "C" __declspec(dllexport) int WINAPI UISalComboBoxItemCellGetIndexOf(HWND comboBoxHandle, HANDLE itemHandle, HANDLE cellHandle)
{
	// variables
	int cellIndex = -1;

	// ensure, that an item handle and a cell handle was passed
	if ((itemHandle != NULL) && (cellHandle != NULL))
	{
		// ensure ComboBox style
		uiSalComboBoxEnsureStyle(comboBoxHandle);

		// get access to ComboBox
		CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
		if (extComboBox != NULL)
		{
			// get cell handle
			CExtComboBox::LB_ITEM* item = (CExtComboBox::LB_ITEM*)itemHandle;
			CExtComboBox::LB_ITEM::CELL* cell = (CExtComboBox::LB_ITEM::CELL*)cellHandle;
			cellIndex = item->LbItemCellGetIndexOf(cell);
		}
	}

	return cellIndex;
}

extern "C" __declspec(dllexport) int WINAPI UISalComboBoxItemCellGetCount(HWND comboBoxHandle, HANDLE itemHandle)
{
	// variables
	int cellCount = -1;

	// ensure, that an item handle was passed
	if (itemHandle != NULL)
	{
		// ensure ComboBox style
		uiSalComboBoxEnsureStyle(comboBoxHandle);

		// get access to ComboBox
		CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
		if (extComboBox != NULL)
		{
			// get cell count
			CExtComboBox::LB_ITEM* item = (CExtComboBox::LB_ITEM*)itemHandle;
			cellCount = item->LbItemCellGetCount();
		}
	}

	return cellCount;
}

extern "C" __declspec(dllexport) LONG WINAPI UISalComboBoxCellGetLParam(HWND comboBoxHandle, HANDLE cellHandle)
{
	// variables
	LONG cellLParam = 0;

	// ensure, that a cell handle was passed
	if (cellHandle != NULL)
	{
		// ensure ComboBox style
		uiSalComboBoxEnsureStyle(comboBoxHandle);

		// get access to ComboBox
		CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
		if (extComboBox != NULL)
		{
			// get cell LParam
			CExtComboBox::LB_ITEM::CELL* cell = (CExtComboBox::LB_ITEM::CELL*)cellHandle;
			cellLParam = cell->m_nLParam;
		}
	}

	return cellLParam;
}

extern "C" __declspec(dllexport) LONG WINAPI UISalComboBoxCellSetLParam(HWND comboBoxHandle, HANDLE cellHandle, LONG cellLParam)
{
	// variables
	LONG previousCellLParam = 0;

	// ensure, that a cell handle was passed
	if (cellHandle != NULL)
	{
		// ensure ComboBox style
		uiSalComboBoxEnsureStyle(comboBoxHandle);

		// get access to ComboBox
		CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
		if (extComboBox != NULL)
		{
			// get and set cell LParam
			CExtComboBox::LB_ITEM::CELL* cell = (CExtComboBox::LB_ITEM::CELL*)cellHandle;
			previousCellLParam = cell->m_nLParam;
			cell->m_nLParam = cellLParam;
		}
	}

	return previousCellLParam;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalComboBoxCellGetColorText(HWND comboBoxHandle, HANDLE cellHandle)
{
	// variables
	COLORREF cellColorText = RGB(0, 0, 0);

	// ensure, that a cell handle was passed
	if (cellHandle != NULL)
	{
		// ensure ComboBox style
		uiSalComboBoxEnsureStyle(comboBoxHandle);

		// get access to ComboBox
		CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
		if (extComboBox != NULL)
		{
			// get cell text color
			CExtComboBox::LB_ITEM::CELL* cell = (CExtComboBox::LB_ITEM::CELL*)cellHandle;
			cellColorText = cell->m_clrText;
		}
	}

	return cellColorText;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalComboBoxCellSetColorText(HWND comboBoxHandle, HANDLE cellHandle, COLORREF cellColorText)
{
	// variables
	COLORREF previousCellColorText = 0;

	// ensure, that a cell handle was passed
	if (cellHandle != NULL)
	{
		// ensure ComboBox style
		uiSalComboBoxEnsureStyle(comboBoxHandle);

		// get access to ComboBox
		CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
		if (extComboBox != NULL)
		{
			// get and set cell text color
			CExtComboBox::LB_ITEM::CELL* cell = (CExtComboBox::LB_ITEM::CELL*)cellHandle;
			previousCellColorText = cell->m_clrText;
			cell->m_clrText = cellColorText;
		}
	}

	return previousCellColorText;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalComboBoxCellGetColorBackground(HWND comboBoxHandle, HANDLE cellHandle)
{
	// variables
	COLORREF cellColorBackground = RGB(0, 0, 0);

	// ensure, that a cell handle was passed
	if (cellHandle != NULL)
	{
		// ensure ComboBox style
		uiSalComboBoxEnsureStyle(comboBoxHandle);

		// get access to ComboBox
		CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
		if (extComboBox != NULL)
		{
			// get cell background color
			CExtComboBox::LB_ITEM::CELL* cell = (CExtComboBox::LB_ITEM::CELL*)cellHandle;
			cellColorBackground = cell->m_clrBack;
		}
	}

	return cellColorBackground;
}

extern "C" __declspec(dllexport) COLORREF WINAPI UISalComboBoxCellSetColorBackground(HWND comboBoxHandle, HANDLE cellHandle, COLORREF cellColorBackground)
{
	// variables
	COLORREF previousCellColorBackground = 0;

	// ensure, that a cell handle was passed
	if (cellHandle != NULL)
	{
		// ensure ComboBox style
		uiSalComboBoxEnsureStyle(comboBoxHandle);

		// get access to ComboBox
		CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
		if (extComboBox != NULL)
		{
			// get and set cell background color
			CExtComboBox::LB_ITEM::CELL* cell = (CExtComboBox::LB_ITEM::CELL*)cellHandle;
			previousCellColorBackground = cell->m_clrBack;
			cell->m_clrBack = cellColorBackground;
		}
	}

	return previousCellColorBackground;
}

extern "C" __declspec(dllexport) void WINAPI UISalComboBoxCellGetText(HWND comboBoxHandle, HANDLE cellHandle, LPWSTR text, DWORD textSize)
{
	// ensure, that a cell handle was passed
	if (cellHandle != NULL)
	{
		// ensure ComboBox style
		uiSalComboBoxEnsureStyle(comboBoxHandle);

		// get access to ComboBox
		CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
		if (extComboBox != NULL)
		{
			// get cell text
			CExtComboBox::LB_ITEM::CELL* cell = (CExtComboBox::LB_ITEM::CELL*)cellHandle;
			wcsncpy(text, cell->m_sItemText, textSize);
		}
	}
}

extern "C" __declspec(dllexport) void WINAPI UISalComboBoxCellSetText(HWND comboBoxHandle, HANDLE cellHandle, LPCWSTR text)
{
	// ensure, that a cell handle was passed
	if (cellHandle != NULL)
	{
		// ensure ComboBox style
		uiSalComboBoxEnsureStyle(comboBoxHandle);

		// get access to ComboBox
		CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
		if (extComboBox != NULL)
		{
			// set cell text
			CExtComboBox::LB_ITEM::CELL* cell = (CExtComboBox::LB_ITEM::CELL*)cellHandle;
			cell->m_sItemText = text;
		}
	}
}

extern "C" __declspec(dllexport) void WINAPI UISalComboBoxCellSet(HWND comboBoxHandle, HANDLE cellHandle, LPCWSTR text, COLORREF cellColorText, COLORREF cellColorBackground, LONG cellLParam)
{
	// ensure, that a cell handle was passed
	if (cellHandle != NULL)
	{
		// ensure ComboBox style
		uiSalComboBoxEnsureStyle(comboBoxHandle);

		// get access to ComboBox
		CExtComboBox* extComboBox = (CExtComboBox*)CExtComboBox::FromHandlePermanent(comboBoxHandle);
		if (extComboBox != NULL)
		{
			// set cell information
			CExtComboBox::LB_ITEM::CELL* cell = (CExtComboBox::LB_ITEM::CELL*)cellHandle;
			cell->m_sItemText = text;
			cell->m_clrText = cellColorText;
			cell->m_clrBack = cellColorBackground;
			cell->m_nLParam = cellLParam;
		}
	}
}
