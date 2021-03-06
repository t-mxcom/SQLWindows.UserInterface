.head 0 +  Application Description: *Filename:	      SQLWindows.UserInterface.ComboBox.apl
*Description:	User interface enhancement for Unify Team Developer
*Version:		2.00
*Date:		2009-04-07
*Author:		Markus Eßmayr
*LastChange:	2011-09-19 - added functions to support multi column combo boxes
*Copyright:	Copyright © 2009-2011 sqlwindows.userinterface@t-mx.com
*Comments:	2011-09-19 - added functions to support multi column combo boxes
.data CLASSPROPSSIZE
0000: 3A00
.enddata
.data CLASSPROPS
0000: 4400420047005F00 50004C0041005900 4200410043004B00 5F00470055004900
0020: 4400000000001000 3CBCD1AB89A23547 B10E249D18BE7E4A 0000
.enddata
.head 1 -  Outline Version - 4.0.37
.head 1 +  Design-time Settings
.data VIEWINFO
0000: 6F00000001000000 FFFF01000D004347 5458566965775374 6174650400010000
0020: 0000000000A70000 002C000000020000 0003000000FFFFFF FFFFFFFFFFFCFFFF
0040: FFE1FFFFFFFFFFFF FF000000007C0200 004D010000010000 0001000000010000
0060: 00FFFEFF0F410070 0070006C00690063 006100740069006F 006E004900740065
0080: 006D0000000000
.enddata
.data DT_MAKERUNDLG
0000: 0A00001000000000 FFFEFF00FFFEFF22 5200410043004F00 4E002E0053005100
0020: 4C00570069006E00 64006F0077007300 2E00550073006500 720049006E007400
0040: 6500720066006100 630065002E006500 78006500FFFEFF22 5200410043004F00
0060: 4E002E0053005100 4C00570069006E00 64006F0077007300 2E00550073006500
0080: 720049006E007400 6500720066006100 630065002E006400 6C006C00FFFEFF22
00A0: 5200410043004F00 4E002E0053005100 4C00570069006E00 64006F0077007300
00C0: 2E00550073006500 720049006E007400 6500720066006100 630065002E006100
00E0: 7000630000000101 010064000000FFFE FF00FFFEFF00FFFE FF00000000000000
0100: 00000000FFFEFF22 5200410043004F00 4E002E0053005100 4C00570069006E00
0120: 64006F0077007300 2E00550073006500 720049006E007400 6500720066006100
0140: 630065002E006100 70006400FFFEFF22 5200410043004F00 4E002E0053005100
0160: 4C00570069006E00 64006F0077007300 2E00550073006500 720049006E007400
0180: 6500720066006100 630065002E006400 6C006C00FFFEFF22 5200410043004F00
01A0: 4E002E0053005100 4C00570069006E00 64006F0077007300 2E00550073006500
01C0: 720049006E007400 6500720066006100 630065002E006100 7000630000000101
01E0: 010064000000FFFE FF22520041004300 4F004E002E005300 51004C0057006900
0200: 6E0064006F007700 73002E0055007300 6500720049006E00 7400650072006600
0220: 6100630065002E00 610070006C00FFFE FF22520041004300 4F004E002E005300
0240: 51004C0057006900 6E0064006F007700 73002E0055007300 6500720049006E00
0260: 7400650072006600 6100630065002E00 64006C006C00FFFE FF22520041004300
0280: 4F004E002E005300 51004C0057006900 6E0064006F007700 73002E0055007300
02A0: 6500720049006E00 7400650072006600 6100630065002E00 6100700063000000
02C0: 0101010064000000 FFFEFF2252004100 43004F004E002E00 530051004C005700
02E0: 69006E0064006F00 770073002E005500 7300650072004900 6E00740065007200
0300: 6600610063006500 2E00650078006500 FFFEFF2252004100 43004F004E002E00
0320: 530051004C005700 69006E0064006F00 770073002E005500 7300650072004900
0340: 6E00740065007200 6600610063006500 2E0064006C006C00 FFFEFF2252004100
0360: 43004F004E002E00 530051004C005700 69006E0064006F00 770073002E005500
0380: 7300650072004900 6E00740065007200 6600610063006500 2E00610070006300
03A0: 0000010101006400 0000FFFEFF225200 410043004F004E00 2E00530051004C00
03C0: 570069006E006400 6F00770073002E00 5500730065007200 49006E0074006500
03E0: 7200660061006300 65002E0064006C00 6C00FFFEFF225200 410043004F004E00
0400: 2E00530051004C00 570069006E006400 6F00770073002E00 5500730065007200
0420: 49006E0074006500 7200660061006300 65002E0064006C00 6C00FFFEFF225200
0440: 410043004F004E00 2E00530051004C00 570069006E006400 6F00770073002E00
0460: 5500730065007200 49006E0074006500 7200660061006300 65002E0061007000
0480: 6300000001010100 64000000FFFEFF22 5200410043004F00 4E002E0053005100
04A0: 4C00570069006E00 64006F0077007300 2E00550073006500 720049006E007400
04C0: 6500720066006100 630065002E006400 6C006C00FFFEFF22 5200410043004F00
04E0: 4E002E0053005100 4C00570069006E00 64006F0077007300 2E00550073006500
0500: 720049006E007400 6500720066006100 630065002E006400 6C006C00FFFEFF22
0520: 5200410043004F00 4E002E0053005100 4C00570069006E00 64006F0077007300
0540: 2E00550073006500 720049006E007400 6500720066006100 630065002E006100
0560: 7000630000000101 0100640000000000 0000FFFEFF00FFFE FF00FFFEFF00FFFE
0580: FF00FFFEFF00FFFE FF00000000000000 0000FFFEFF00FFFE FF00FFFEFF000000
05A0: 0000000100000001 00000001FFFEFF00 0100000000000000 FFFEFF0001000010
05C0: 0000000000000000 000000000D000D00
.enddata
.head 2 -  Outline Window State: Normal
.head 2 +  Outline Window Location and Size
.data VIEWINFO
0000: 6600040003002D00 0000000000000000 0000B71E5D0E0500 1D00FFFF4D61696E
0020: 0000000000000000 0000000000000000 0000003B00010000 00000000000000E9
0040: 1E800A00008600FF FF496E7465726E61 6C2046756E637469 6F6E730000000000
0060: 0000000000000000 0000000000003200 0100000000000000 0000E91E800A0000
0080: DF00FFFF56617269 61626C6573000000 0000000000000000 0000000000000000
00A0: 3000010000000000 00000000F51E100D 0000F400FFFF436C 6173736573000000
00C0: 0000000000000000 0000000000000000
.enddata
.data VIEWSIZE
0000: D000
.enddata
.head 3 -  Left: 0.0"
.head 3 -  Top: 0.0"
.head 3 -  Width:  8.013"
.head 3 -  Height: 4.969"
.head 2 +  Options Box Location
.data VIEWINFO
0000: D4180909B80B1A00
.enddata
.data VIEWSIZE
0000: 0800
.enddata
.head 3 -  Visible? Yes
.head 3 -  Left: 4.15"
.head 3 -  Top: 1.885"
.head 3 -  Width:  3.8"
.head 3 -  Height: 2.073"
.head 2 +  Class Editor Location
.head 3 -  Visible? No
.head 3 -  Left: 0.575"
.head 3 -  Top: 0.094"
.head 3 -  Width:  5.063"
.head 3 -  Height: 2.719"
.head 2 +  Tool Palette Location
.head 3 -  Visible? No
.head 3 -  Left: 6.388"
.head 3 -  Top: 0.729"
.head 2 -  Fully Qualified External References? Yes
.head 2 -  Reject Multiple Window Instances? No
.head 2 -  Enable Runtime Checks Of External References? Yes
.head 2 -  Use Release 4.0 Scope Rules? No
.head 2 -  Edit Fields Read Only On Disable? No
.head 1 -  Libraries
.head 1 +  Global Declarations
.head 2 +  Window Defaults
.head 3 +  Tool Bar
.head 4 -  Display Style? Etched
.head 4 -  Font Name: Microsoft Sans Serif
.head 4 -  Font Size: System Default
.head 4 -  Font Enhancement: System Default
.head 4 -  Text Color: System Default
.head 4 -  Background Color: System Default
.head 3 +  Form Window
.head 4 -  Display Style? Etched
.head 4 -  Font Name: Microsoft Sans Serif
.head 4 -  Font Size: System Default
.head 4 -  Font Enhancement: System Default
.head 4 -  Text Color: System Default
.head 4 -  Background Color: System Default
.head 3 +  Dialog Box
.head 4 -  Display Style? Etched
.head 4 -  Font Name: Microsoft Sans Serif
.head 4 -  Font Size: System Default
.head 4 -  Font Enhancement: System Default
.head 4 -  Text Color: System Default
.head 4 -  Background Color: System Default
.head 3 +  Top Level Table Window
.head 4 -  Font Name: Microsoft Sans Serif
.head 4 -  Font Size: System Default
.head 4 -  Font Enhancement: System Default
.head 4 -  Text Color: System Default
.head 4 -  Background Color: System Default
.head 3 +  Data Field
.head 4 -  Font Name: Use Parent
.head 4 -  Font Size: Use Parent
.head 4 -  Font Enhancement: Use Parent
.head 4 -  Text Color: Use Parent
.head 4 -  Background Color: Use Parent
.head 3 +  Multiline Field
.head 4 -  Font Name: Use Parent
.head 4 -  Font Size: Use Parent
.head 4 -  Font Enhancement: Use Parent
.head 4 -  Text Color: Use Parent
.head 4 -  Background Color: Use Parent
.head 3 +  Spin Field
.head 4 -  Font Name: Use Parent
.head 4 -  Font Size: Use Parent
.head 4 -  Font Enhancement: Use Parent
.head 4 -  Text Color: Use Parent
.head 4 -  Background Color: Use Parent
.head 3 +  Background Text
.head 4 -  Font Name: Use Parent
.head 4 -  Font Size: Use Parent
.head 4 -  Font Enhancement: Use Parent
.head 4 -  Text Color: Use Parent
.head 4 -  Background Color: Use Parent
.head 3 +  Pushbutton
.head 4 -  Font Name: Use Parent
.head 4 -  Font Size: Use Parent
.head 4 -  Font Enhancement: Use Parent
.head 3 +  Radio Button
.head 4 -  Font Name: Use Parent
.head 4 -  Font Size: Use Parent
.head 4 -  Font Enhancement: Use Parent
.head 4 -  Text Color: Use Parent
.head 4 -  Background Color: Use Parent
.head 3 +  Check Box
.head 4 -  Font Name: Use Parent
.head 4 -  Font Size: Use Parent
.head 4 -  Font Enhancement: Use Parent
.head 4 -  Text Color: Use Parent
.head 4 -  Background Color: Use Parent
.head 3 +  Option Button
.head 4 -  Font Name: Use Parent
.head 4 -  Font Size: Use Parent
.head 4 -  Font Enhancement: Use Parent
.head 3 +  Group Box
.head 4 -  Font Name: Use Parent
.head 4 -  Font Size: Use Parent
.head 4 -  Font Enhancement: Use Parent
.head 4 -  Text Color: Use Parent
.head 4 -  Background Color: Use Parent
.head 3 +  Child Table Window
.head 4 -  Font Name: Use Parent
.head 4 -  Font Size: Use Parent
.head 4 -  Font Enhancement: Use Parent
.head 4 -  Text Color: Use Parent
.head 4 -  Background Color: Use Parent
.head 3 +  List Box
.head 4 -  Font Name: Use Parent
.head 4 -  Font Size: Use Parent
.head 4 -  Font Enhancement: Use Parent
.head 4 -  Text Color: Use Parent
.head 4 -  Background Color: Use Parent
.head 3 +  Combo Box
.head 4 -  Font Name: Use Parent
.head 4 -  Font Size: Use Parent
.head 4 -  Font Enhancement: Use Parent
.head 4 -  Text Color: Use Parent
.head 4 -  Background Color: Use Parent
.head 3 +  Line
.head 4 -  Line Color: Use Parent
.head 3 +  Frame
.head 4 -  Border Color: Use Parent
.head 4 -  Background Color: Use Parent
.head 3 +  Picture
.head 4 -  Border Color: Use Parent
.head 4 -  Background Color: Use Parent
.head 3 +  Date Time Picker
.head 4 -  Text Color: Use Parent
.head 4 -  Background Color: Use Parent
.head 3 +  Child Grid Window
.head 4 -  Font Name: Use Parent
.head 4 -  Font Size: Use Parent
.head 4 -  Font Enhancement: Use Parent
.head 4 -  Text Color: Use Parent
.head 4 -  Background Color: Use Parent
.head 2 +  Formats
.head 3 -  Number: 0'%'
.head 3 -  Number: #0
.head 3 -  Number: ###000
.head 3 -  Number: ###000;'($'###000')'
.head 3 -  Date/Time: hh:mm:ss AMPM
.head 3 -  Date/Time: M/d/yy
.head 3 -  Date/Time: MM-dd-yy
.head 3 -  Date/Time: dd-MMM-yyyy
.head 3 -  Date/Time: MMM d, yyyy
.head 3 -  Date/Time: MMM d, yyyy hh:mm AMPM
.head 3 -  Date/Time: MMMM d, yyyy hh:mm AMPM
.head 2 +  External Functions
.head 3 +  Library name: SQLWindows.UserInterface.dll
.head 4 -  ThreadSafe: No
.head 4 -  ! UIComboBox
.head 4 +  Function: UISalComboBoxGetAutoComplete
.head 5 -  Description: Gets the enabled state of the auto complete feature.
*Returns: TRUE - auto complete enabled, FALSE - auto complete not enabled
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Boolean: BOOL
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 4 +  Function: UISalComboBoxSetAutoComplete
.head 5 -  Description: Sets the enabled state of the auto complete feature.
*Returns: Previous enabled state of the auto complete feature.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Boolean: BOOL
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Boolean: BOOL
.head 7 -  ! Enable (TRUE) or disable (FALSE) the auto complete feature
.head 4 +  Function: UISalComboBoxGetUseCaseSensitiveAutoComplete
.head 5 -  Description: Gets the enabled state of the case sensitive auto complete feature.
*Returns: TRUE - case sensitive aauto complete enabled, FALSE - case sensitive aauto complete not enabled
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Boolean: BOOL
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 4 +  Function: UISalComboBoxSetUseCaseSensitiveAutoComplete
.head 5 -  Description: Sets the enabled state of the case sensitive auto complete feature.
*Returns: Previous enabled state of the case sensitive auto complete feature.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Boolean: BOOL
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Boolean: BOOL
.head 7 -  ! Enable (TRUE) or disable (FALSE) the case sensitive auto complete feature
.head 4 +  Function: UISalComboBoxGetAutoFilter
.head 5 -  Description: Gets the enabled state of the auto filter feature.
*Returns: TRUE - auto filter enabled, FALSE - auto filter not enabled
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Boolean: BOOL
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 4 +  Function: UISalComboBoxSetAutoFilter
.head 5 -  Description: Sets the auto filter state.
*Returns: Previous auto filter state.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Boolean: BOOL
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box window
.head 6 +  Boolean: BOOL
.head 7 -  ! New auto filter state
.head 4 +  Function: UISalComboBoxShowFilterPopupList
.head 5 -  Description: Displays the filter popup list.
*Returns: Nothing
.head 5 -  Export Ordinal: 0
.head 5 -  Returns
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 4 +  Function: UISalComboBoxGetFilterPopupListSize
.head 5 -  Description: Gets the size of the filter popup list.
*Returns: Nothing
.head 5 -  Export Ordinal: 0
.head 5 -  Returns
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Receive Number: LPLONG
.head 7 -  ! [out] Width of the list
.head 6 +  Receive Number: LPLONG
.head 7 -  ! [out] Height of the list
.head 4 +  Function: UISalComboBoxSetFilterPopupListSize
.head 5 -  Description: Sets the size of the filter popup list.
*Returns: Nothing
.head 5 -  Export Ordinal: 0
.head 5 -  Returns
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: LONG
.head 7 -  ! [in] Width of the list
.head 6 +  Number: LONG
.head 7 -  ! [in] Height of the list
.head 4 +  Function: UISalComboBoxItemGet
.head 5 -  Description: Gets the handle to an item.
*Returns: Handle to the item.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Number: HANDLE
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: LONG
.head 7 -  ! [in] Item index
.head 4 +  Function: UISalComboBoxColumnWidthGet
.head 5 -  Description: Gets the width of a column.
*Returns: Width of the column.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Number: LONG
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: LONG
.head 7 -  ! [in] Column number
.head 4 +  Function: UISalComboBoxColumnWidthSet
.head 5 -  Description: Sets the width of a column.
*Returns: Previous width of the column.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Number: LONG
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: LONG
.head 7 -  ! [in] Column number
.head 6 +  Number: LONG
.head 7 -  ! [in] Column width
.head 4 +  Function: UISalComboBoxItemIsEnabled
.head 5 -  Description: Get the enabled state of a specific item.
*Returns: Enable state of the item.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Boolean: BOOL
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: LONG
.head 7 -  ! Item
.head 4 +  Function: UISalComboBoxItemEnable
.head 5 -  Description: Enable or disable a specific item in the Combo Box.
*Returns: Previous enable state of the item.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Boolean: BOOL
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: LONG
.head 7 -  ! Item
.head 6 +  Boolean: BOOL
.head 7 -  ! Enable (TRUE) or disable (FALSE) the item
.head 4 +  Function: UISalComboBoxItemCellInsert
.head 5 -  Description: Insert a cell to an item.
*Returns: Cell index.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Number: INT
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: HANDLE
.head 7 -  ! [in] Item handle.
.head 6 +  String: LPCWSTR
.head 7 -  ! [in] Cell text.
.head 6 +  Number: INT
.head 7 -  ! [in] Cell position. (-1 appends the cell to the end)
.head 4 +  Function: UISalComboBoxItemCellRemove
.head 5 -  Description: Removes a cell from an item.
*Returns: TRUE - Cell was removed, FALSE - Cell was not removed.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Boolean: BOOL
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: HANDLE
.head 7 -  ! [in] Item handle.
.head 6 +  Number: LONG
.head 7 -  ! [in] Cell index.
.head 4 +  Function: UISalComboBoxItemCellGet
.head 5 -  Description: Gets the handle to a cell.
*Returns: Handle to the cell.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Number: HANDLE
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: HANDLE
.head 7 -  ! [in] Item handle.
.head 6 +  Number: LONG
.head 7 -  ! [in] Cell index
.head 4 +  Function: UISalComboBoxItemCellGetIndexOf
.head 5 -  Description: Gets the index of a cell.
*Returns: Index to the cell.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Number: INT
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: HANDLE
.head 7 -  ! [in] Item handle.
.head 6 +  Number: HANDLE
.head 7 -  ! [in] Cell handle.
.head 4 +  Function: UISalComboBoxItemCellGetCount
.head 5 -  Description: Gets the nomber of cells.
*Returns: Number of cells.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Number: INT
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: HANDLE
.head 7 -  ! [in] Item handle.
.head 4 +  Function: UISalComboBoxCellGetLParam
.head 5 -  Description: Gets the assigned number of a cell.
*Returns: Assigned number of the cell.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Number: LONG
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: HANDLE
.head 7 -  ! [in] Cell handle.
.head 4 +  Function: UISalComboBoxCellSetLParam
.head 5 -  Description: Sets the assigned number of a cell.
*Returns: Previously assigned number of the cell.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Number: LONG
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: HANDLE
.head 7 -  ! [in] Cell handle.
.head 6 +  Number: LONG
.head 7 -  ! [in] Number to assign to the cell.
.head 4 +  Function: UISalComboBoxCellGetColorText
.head 5 -  Description: Gets the text color of a cell.
*Returns: Text color of the cell.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Number: DWORD
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: HANDLE
.head 7 -  ! [in] Cell handle.
.head 4 +  Function: UISalComboBoxCellSetColorText
.head 5 -  Description: Sets the text color of a cell.
*Returns: Previous text color of the cell.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Number: DWORD
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: HANDLE
.head 7 -  ! [in] Cell handle.
.head 6 +  Number: DWORD
.head 7 -  ! [in] Text color of the cell.
.head 4 +  Function: UISalComboBoxCellGetColorBackground
.head 5 -  Description: Gets the background color of a cell.
*Returns: Background color of the cell.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Number: DWORD
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: HANDLE
.head 7 -  ! [in] Cell handle.
.head 4 +  Function: UISalComboBoxCellSetColorBackground
.head 5 -  Description: Sets the background color of a cell.
*Returns: Previous background color of the cell.
.head 5 -  Export Ordinal: 0
.head 5 +  Returns
.head 6 -  Number: DWORD
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: HANDLE
.head 7 -  ! [in] Cell handle.
.head 6 +  Number: DWORD
.head 7 -  ! [in] Background color of the cell.
.head 4 +  Function: UISalComboBoxCellGetText
.head 5 -  Description: Gets the text of a cell.
*Returns: Nothing.
.head 5 -  Export Ordinal: 0
.head 5 -  Returns
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: HANDLE
.head 7 -  ! [in] Cell handle.
.head 6 +  Receive String: LPWSTR
.head 7 -  ! [out] Text of the cell.
.head 6 +  Number: DWORD
.head 7 -  ! [in] Size of the text bufer.
.head 4 +  Function: UISalComboBoxCellSetText
.head 5 -  Description: Sets the text of a cell.
*Returns: Nothing.
.head 5 -  Export Ordinal: 0
.head 5 -  Returns
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: HANDLE
.head 7 -  ! [in] Cell handle.
.head 6 +  String: LPCWSTR
.head 7 -  ! [in] Text of the cell.
.head 4 +  Function: UISalComboBoxCellSet
.head 5 -  Description: Sets all available information of a cell.
*Returns: Nothing.
.head 5 -  Export Ordinal: 0
.head 5 -  Returns
.head 5 +  Parameters
.head 6 +  Window Handle: HWND
.head 7 -  ! Handle of the combo box
.head 6 +  Number: HANDLE
.head 7 -  ! [in] Cell handle.
.head 6 +  String: LPCWSTR
.head 7 -  ! [in] Text of the cell.
.head 6 +  Number: DWORD
.head 7 -  ! [in] Text color of the cell.
.head 6 +  Number: DWORD
.head 7 -  ! [in] Background color of the cell.
.head 6 +  Number: LONG
.head 7 -  ! [in] Number to assign to the cell.
.head 2 +  Constants
.data CCDATA
0000: 3000000000000000 0000000000000000 0000000000000000 0000000000000000
0020: 0000000000000000
.enddata
.data CCSIZE
0000: 2800
.enddata
.head 3 -  System
.head 3 -  User
.head 3 -  Enumerations
.head 2 -  Resources
.head 2 -  Variables
.head 2 -  Internal Functions
.head 2 -  Named Menus
.head 2 +  Class Definitions
.head 3 +  Combo Box Class: UIComboBox
.head 4 -  Window Location and Size
.head 5 -  Left:
.head 5 -  Top:
.head 5 -  Width:  Class Default
.head 5 -  Width Editable? Class Default
.head 5 -  Height: Class Default
.head 5 -  Height Editable? Class Default
.head 4 -  Visible? Class Default
.head 4 -  Editable? Class Default
.head 4 -  String Type: Class Default
.head 4 -  Maximum Data Length: Class Default
.head 4 -  Sorted? Class Default
.head 4 -  Always Show List? Class Default
.head 4 -  Vertical Scroll? Class Default
.head 4 -  Font Name: Class Default
.head 4 -  Font Size: Class Default
.head 4 -  Font Enhancement: Class Default
.head 4 -  Text Color: Class Default
.head 4 -  Background Color: Class Default
.head 4 -  Input Mask: Class Default
.head 4 -  List in Tool Palette? Yes
.head 4 -  Property Template:
.head 4 -  Class DLL Name:
.head 4 -  Description: Provides additional functionality to control combo box appearance and behaviour.
.head 4 -  Derived From
.head 4 -  Class Variables
.head 4 -  Instance Variables
.head 4 +  Functions
.head 5 +  Function: ItemEnable
.head 6 -  Description: Enable or disable a specific item in the Combo Box.
*Returns: Previous enable state of the item.
.head 6 +  Returns
.head 7 -  Boolean:
.head 6 +  Parameters
.head 7 +  Number: item
.head 8 -  ! Item
.head 7 +  Boolean: enable
.head 8 -  ! Enable (TRUE) or disable (FALSE) the item
.head 6 -  Static Variables
.head 6 -  Local variables
.head 6 +  Actions
.head 7 -  Return UISalComboBoxItemEnable( hWndItem, item, enable )
.head 5 +  Function: SetAutoFilter
.head 6 -  Description: Sets the auto filter state.
*Returns: Previous auto filter state.
.head 6 +  Returns
.head 7 -  Boolean:
.head 6 +  Parameters
.head 7 +  Boolean: autoFilterState
.head 8 -  ! New auto filter state
.head 6 -  Static Variables
.head 6 -  Local variables
.head 6 +  Actions
.head 7 -  ! Set auto filter state
.head 7 -  Return UISalComboBoxSetAutoFilter( hWndItem, autoFilterState )
.head 4 -  List Initialization
.head 4 -  Message Actions
.head 2 +  Default Classes
.head 3 -  MDI Window: cBaseMDI
.head 3 -  Form Window:
.head 3 -  Dialog Box:
.head 3 -  Table Window:
.head 3 -  Quest Window:
.head 3 -  Data Field:
.head 3 -  Spin Field:
.head 3 -  Multiline Field:
.head 3 -  Pushbutton:
.head 3 -  Radio Button:
.head 3 -  Option Button:
.head 3 -  Child Grid:
.head 3 -  Check Box:
.head 3 -  Child Table:
.head 3 -  Quest Child Window: cQuickDatabase
.head 3 -  List Box:
.head 3 -  Combo Box:
.head 3 -  Picture:
.head 3 -  Vertical Scroll Bar:
.head 3 -  Horizontal Scroll Bar:
.head 3 -  Column:
.head 3 -  Background Text:
.head 3 -  Group Box:
.head 3 -  Line:
.head 3 -  Frame:
.head 3 -  Custom Control:
.head 3 -  ActiveX:
.head 3 -  Date Picker:
.head 3 -  Date Time Picker:
.head 3 -  Tab Bar:
.head 2 -  Application Actions
