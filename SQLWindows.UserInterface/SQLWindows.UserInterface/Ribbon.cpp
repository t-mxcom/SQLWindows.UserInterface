#include "stdafx.h"
#include "Prof-UIS.h"

CExtRibbonNodeFile * _InitRibbon_FileMenu();

extern "C" __declspec(dllexport) BOOL WINAPI UISalRibbonSetAutoHideMode(HWND ribbonHandle, BOOL autoHideMode)
{
	// variables
	BOOL previousAutoHideMode = FALSE;

	// access ribbon bar
	CExtRibbonBar* ribbonBar = (CExtRibbonBar*)CExtRibbonBar::FromHandlePermanent(ribbonHandle);
	if (ribbonBar != NULL)
	{
		// get previous mode
		previousAutoHideMode = ribbonBar->Ribbon_AutoHideModeEnabledGet();
		ribbonBar->Ribbon_AutoHideModeEnabledSet(autoHideMode);

		DWORD style = ribbonBar->GetStyle();
		ribbonBar->m_dwStyle = style;

		CExtRibbonNode* ribbonNode = new CExtRibbonNode();
		// ribbonNode->InsertNode(NULL, ribbonBar->Ribbon_GetRootNode());
		ribbonNode->InsertNode(NULL, _InitRibbon_FileMenu());
		ribbonBar->SetButtons(ribbonNode);
	}

	return previousAutoHideMode;
}

CExtRibbonNodeFile * _InitRibbon_FileMenu()
{
	CExtRibbonNodeFile * pRibbonNodeFile = new CExtRibbonNodeFile;
	pRibbonNodeFile->CmdKeyTipSet( new CExtCustomizeCmdKeyTip( __EXT_MFC_SAFE_TCHAR( _T('F') ) ), false );
	pRibbonNodeFile->m_keyTipOptionsButton.KeyCodeAdd( DWORD('T') );
	pRibbonNodeFile->m_keyTipExitButton.KeyCodeAdd( DWORD('X') );
	CExtCustomizeCmdScreenTip * pCmdScreenTip = new CExtCustomizeCmdScreenTip;
	pCmdScreenTip->CaptionMainSet( _T("Application Button") );
	pCmdScreenTip->TextMainSet( _T("Click here to open, save or print,\nand to see everything else you can\ndo with the document.") );
	pRibbonNodeFile->CmdScreenTipAttach( pCmdScreenTip );

	CExtRibbonNode * pNodeFileNew =
		new CExtRibbonNode(
			1,
			1,
			NULL,
			__ECTN_BIG_ACCENT_IN_MENU,
			NULL,
			_T("&New...")
			);
	pNodeFileNew->CmdKeyTipSet( new CExtCustomizeCmdKeyTip( __EXT_MFC_SAFE_TCHAR( _T('N') ) ), false );
	pCmdScreenTip = new CExtCustomizeCmdScreenTip;
	pCmdScreenTip->TextMainSet( _T("New") );
	pNodeFileNew->CmdScreenTipAttach( pCmdScreenTip );
	pRibbonNodeFile->InsertNode( NULL, pNodeFileNew );

	return pRibbonNodeFile;
}