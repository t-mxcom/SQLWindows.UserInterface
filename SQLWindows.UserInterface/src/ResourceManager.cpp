#include "stdafx.h"
#include "Prof-UIS.h"

extern "C" __declspec(dllexport) WORD WINAPI UISalResourceManagerSetDesiredLangId(WORD langId, BOOL allowCustomLang)
{
	WORD previousLangId = g_ResourceManager->GetLangIdDesired();

	// if necessary and activated, allow custom lang
	if ((!g_ResourceManager->IsCustomLangAllowed()) && (allowCustomLang))
	{
		g_ResourceManager->AllowCustomLang(true);
	}
	if (g_ResourceManager->IsCustomLangAllowed())
	{
		// set the desired language
		g_ResourceManager->SetLangIdDesired(langId);
	}

	return previousLangId;
}
