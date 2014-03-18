#include "main.h"
#include <TRose\CodeHook.h>
#include "SkillBar2.h"
#include "Controls.h"

Options gOptions;
HNODE gSmallOutlineFont;

void SetFont(int fontSize){
	const char* fontName = "Verdana";

	int smallFont = fontSize - 1;
	int largeFont = fontSize + 1;

	::unloadFont(GameDATA->m_hFONT[FONT_NORMAL]); 
	GameDATA->m_hFONT[FONT_NORMAL] = ::loadFont("Normal_Font", fontName, 0, fontSize, 0, 0, 255, 255, 255, 255);
	::unloadFont(GameDATA->m_hFONT[FONT_NORMAL_BOLD]); 
	GameDATA->m_hFONT[FONT_NORMAL_BOLD] = ::loadFont("Normal_Font_B", fontName, 0, fontSize, 1, 0, 255, 255, 255, 255);
	::unloadFont(GameDATA->m_hFONT[FONT_NORMAL_OUTLINE]); 
	GameDATA->m_hFONT[FONT_NORMAL_OUTLINE] = loadFontOutline("Normal_Font_Outline", fontName, 0, fontSize, 0, 0, 1, D3DCOLOR_ARGB(255, 255, 255, 255), D3DCOLOR_ARGB(255, 0, 0, 0));
	
	::unloadFont(GameDATA->m_hFONT[FONT_LARGE]); 
	GameDATA->m_hFONT[FONT_LARGE] = ::loadFont("Large_Font", fontName, 0, largeFont, 0, 0, 255, 255, 255, 255);
	::unloadFont( GameDATA->m_hFONT[FONT_LARGE_BOLD]); 
	GameDATA->m_hFONT[FONT_LARGE_BOLD] = ::loadFont("Large_Font_B", fontName, 0, largeFont, 1, 0, 255, 255, 255, 255);

	::unloadFont(GameDATA->m_hFONT[FONT_SMALL]); 
	GameDATA->m_hFONT[FONT_SMALL] = ::loadFont("Small_Font", fontName, 0, smallFont, 0, 0, 255, 255, 255, 255);
	::unloadFont(GameDATA->m_hFONT[FONT_SMALL_BOLD]); 
	GameDATA->m_hFONT[FONT_SMALL_BOLD] = ::loadFont("Small_Font_B", fontName, 0, smallFont, 1, 0, 255, 255, 255, 255);

	if(gSmallOutlineFont)
		::unloadFont(gSmallOutlineFont);

	gSmallOutlineFont = loadFontOutline("Small_Font_Outline", fontName, 0, 8, 0, 0, 1, D3DCOLOR_ARGB(255, 255, 255, 255), D3DCOLOR_ARGB(255, 0, 0, 0));
}

void ApplyZoom(bool enabled){
	gOptions.mFarZoom = enabled;

	if(enabled){
		Code::Write<unsigned char>(0x004060D9, 0x2C);
		Code::Write<unsigned char>(0x00406102, 0x2C);
	}else{
		Code::Write<unsigned char>(0x004060D9, 0x28);
		Code::Write<unsigned char>(0x00406102, 0x28);
	}
}

void _stdcall UpdateOptions(){
	if(CTCheckBox* checkbox = (CTCheckBox*)ControlInPane(DLG_TYPE_OPTION, 20, 0, optSkillBar2))
		gOptions.mSkillBarEnable = checkbox->IsCheck();

	if(CTCheckBox* checkbox = (CTCheckBox*)ControlInPane(DLG_TYPE_OPTION, 20, 0, optZoom))
		ApplyZoom(checkbox->IsCheck());

	if(CTComboBox* comboBox = (CTComboBox*)ControlInPane(DLG_TYPE_OPTION, 20, 4, optFontSize)){
		int fontSize = comboBox->GetSelectedItemID();

		if(gOptions.mFontSize != fontSize){
			if(fontSize < 0 || fontSize > 2) 
				fontSize = 1;

			gOptions.mFontSize = fontSize;
			SetFont(9 + fontSize);
		}
	}

	if(CTCheckBox* checkbox = (CTCheckBox*)ControlInPane(DLG_TYPE_OPTION, 20, 0, optAntiAliasing)){
		if(gOptions.mAntiAliasingEnable != (char)checkbox->IsCheck()){
			gOptions.mAntiAliasingEnable = checkbox->IsCheck();

			if(gOptions.mAntiAliasingEnable == 1) 
				setFullSceneAntiAliasing(2);
			else
				setFullSceneAntiAliasing(0);

			resetScreen();
		}
	}

	if(CTCheckBox* checkbox = (CTCheckBox*)ControlInPane(DLG_TYPE_OPTION, 20, 1, optQuestIcons))
		gOptions.mQuestIconEnable = checkbox->IsCheck();	

	if(CTRadioBox* radiobox = (CTRadioBox*)ControlInPane(DLG_TYPE_OPTION, 20, 2, optDuelBox)){
		switch(radiobox->GetPressedButtonID()) {
		case optDuelYes:
			gOptions.mAllowDuel = 1;
			break;
		case optDuelNo:
			gOptions.mAllowDuel = 0;
			break;
		default:
			break;
		}
	}
}

static _declspec(naked) void ASMChangeOption(){
	static int jRet = 0x004B46CA;
	static int cOriginal = 0x004B4500;
	_asm {
		CALL cOriginal
		PUSHAD
		CALL UpdateOptions
		POPAD
		JMP jRet
	};
}

HookOnLoad(0x004B46C5, ASMChangeOption, 0);