#include "main.h"
#include "Achievements.h"
#include "SkillBar2.h"
#include "PvP.h"
#include "DuelInvite.h"
#include "Appearance.h"

#include <TRose\MakeDialogsHook.h>
#include <TRose\StringManager.h>

int gQuesticonGUI = 0;
int gUnlockedGUI = 0;
int gBossGUI = 0;
int gPageGID = 0;
int gFlagRedGUI = 0;

void __stdcall MakeDialog(){
#ifdef TEST_SERVER
	unsigned char* ptr = *((unsigned char**)0x693504);
	ptr[0x55] = 1;
#endif

	gAchieveDialog = new CTAchievements();
	gAchieveDialog->Create("DlgAchievements");
	IT_MGR::Instance()->AppendDlg(DLG_TYPE_ACHIEVEMENTS, gAchieveDialog, gAchieveDialog->GetControlID());

	gPvPDialog = new CTPvP();
	gPvPDialog->Create("DlgPVP");
	IT_MGR::Instance()->AppendDlg(DLG_TYPE_PVP, gPvPDialog, gPvPDialog->GetControlID());
	gPvPDialog->InitGameList();

	gPvPInstance = new CTPvPInstance();
	gPvPInstance->Create("DlgPVPInstance");
	IT_MGR::Instance()->AppendDlg(DLG_TYPE_PVPINSTANCE, gPvPInstance, gPvPInstance->GetControlID());

	gSkillBar2 = new SkillBar2(DLG_TYPE_SKILLBAR2);
	gSkillBar2->Create("DlgQuickBar");
	IT_MGR::Instance()->AppendDlg(DLG_TYPE_SKILLBAR2, gSkillBar2, gSkillBar2->GetControlID());

	gDuelInvite = new CTDuelInvite();
	gDuelInvite->Create("DlgDuel");
	IT_MGR::Instance()->AppendDlg(DLG_TYPE_DUELINVITE, gDuelInvite, gDuelInvite->GetControlID());

	gAppearDialog = new CTAppearance();
	gAppearDialog->Create("DlgChangeAvatar");
	IT_MGR::Instance()->AppendDlg(DLG_TYPE_APPEARANCE, gAppearDialog, gAppearDialog->GetControlID());

	FixAspectRatio();

	gQuesticonGUI = CResourceMgr::GetInstance()->GetImageNID(IMAGE_RES_UI, "QUEST_EMOTICON_POSSIBLE") - 1;
	gUnlockedGUI = CResourceMgr::GetInstance()->GetImageNID(IMAGE_RES_UI, "RRA_UNLOCKED");
	gBossGUI = CResourceMgr::GetInstance()->GetImageNID(IMAGE_RES_UI, "DUNGEONBOSS_HP_BOX");
	gPageGID = CResourceMgr::GetInstance()->GetImageNID(IMAGE_RES_UI, "UI21_NUMBER_1");
	gFlagRedGUI = CResourceMgr::GetInstance()->GetImageNID(IMAGE_RES_UI, "UI_PVP_FLAGRED"); 
}

void __stdcall DoMakeDialogHook(){
	MakeDialogHook::Apply(&MakeDialog);
}

RunOnLoad(DoMakeDialogHook);

const char* _stdcall GetIconGUI(int dlgID){
	if(dlgID == DLG_TYPE_PVP)
		return "UI_PVP_ICON";

	return 0;
}

int _stdcall GetIconLabel(int dlgID) {
	if(dlgID == DLG_TYPE_PVP)
		return 921;

	return 0;
}

static _declspec(naked) void ASMIconize(){
	static int jmpRet = 0x004D0353;
	static int jmpNew = 0x004D04D6;
	_asm {
		MOV EAX, DWORD PTR SS:[ESP+0x8]
		PUSH EAX
		CALL GetIconGUI
		TEST EAX, EAX
		JE normal

		MOV EBP, DWORD PTR SS:[ESP+0x68]
		PUSH EBP
		CALL GetIconGUI
			
		PUSH EAX    
		PUSH EBX
		CALL DWORD PTR DS:[0x62E670]
		MOV ECX, EAX
		CALL DWORD PTR DS:[0x62E6D0]

		MOV ECX, DWORD PTR DS:[0x693504]        
		MOV EDX, DWORD PTR DS:[ECX+0x78]
		PUSH EBX
		PUSH EDX
		PUSH -1
		MOV ESI, EAX

		PUSH EBP
		CALL GetIconLabel

		PUSH EAX

		JMP jmpNew
normal:
		MOV EBP, DWORD PTR SS:[ESP+0x68]
		LEA EAX, DWORD PTR SS:[EBP-0x5]
		JMP jmpRet
	};
}

HookOnLoad(0x004D034C, ASMIconize, 2);

int _stdcall MenuOpenDialog(int buttonID){
	if(buttonID == 17)
		return DLG_TYPE_ACHIEVEMENTS;

	if(buttonID == 20)
		return DLG_TYPE_PVP;

	return buttonID;
}

static _declspec(naked) void ASMAddMenuOption(){
	static int jmpRet = 0x004AD515;
	static int jmpNew = 0x004AD582;
	_asm {
		MOV EAX, DWORD PTR SS:[ESP+0x4]
		PUSH ESI
		MOV ESI, ECX

		MOV ECX, EAX
		PUSH ECX
		CALL MenuOpenDialog
		CMP EAX, ECX
		JNZ CustomMenu
		MOV ECX, ESI
		JMP jmpRet
CustomMenu:
		PUSH -1
		PUSH -1
		PUSH 1
		PUSH EAX
		JMP jmpNew
	};
}

HookOnLoad(0x004AD510, ASMAddMenuOption, 0);

void ResetGUI(){
	((CTabbedPane*)ControlInWindow(DLG_TYPE_COMMUNITY, 20))->SetSelectedIndex(2);
	((CTButton*)ControlInPane(DLG_TYPE_COMMUNITY, 20, 3, 79))->SetText("Refresh");

	gStatusText[0] = "Online";
	gStatusText[1] = StringManager::Instance()->GetString(494);
	gStatusText[2] = StringManager::Instance()->GetString(495);
	gStatusText[3] = StringManager::Instance()->GetString(496);
	gStatusText[4] = StringManager::Instance()->GetString(497);
	gStatusText[5] = StringManager::Instance()->GetString(498);
	gStatusText[6] = "Offline";

	if(CTComboBox* comboBox = (CTComboBox*)ControlInPane(DLG_TYPE_COMMUNITY, 20, 2, 53)){
		comboBox->ClearItem();
		comboBox->AddItem(String(" %1").arg(gStatusText[0]).Str());
		comboBox->AddItem(String(" %1").arg(gStatusText[1]).Str());
		comboBox->AddItem(String(" %1").arg(gStatusText[2]).Str());
		comboBox->AddItem(String(" %1").arg(gStatusText[3]).Str());
		comboBox->AddItem(String(" %1").arg(gStatusText[4]).Str());
		comboBox->AddItem(String(" %1").arg(gStatusText[5]).Str());
		comboBox->AddItem(String(" %1").arg(gStatusText[6]).Str());
		comboBox->SetSelectedItem(0);
	}

	if(CTComboBox* comboBox = (CTComboBox*)ControlInPane(DLG_TYPE_OPTION, 20, 4, 176)){
		comboBox->ClearItem();
		comboBox->AddItem("Small");
		comboBox->AddItem("Medium");
		comboBox->AddItem("Large");
		comboBox->SetSelectedItem(gOptions.mFontSize);
	}

	if(gOptions.mQuestIconEnable)
		((CTCheckBox*)ControlInPane(DLG_TYPE_OPTION, 20, 1, optQuestIcons))->SetCheck();

	if(gOptions.mFarZoom)
		((CTCheckBox*)ControlInPane(DLG_TYPE_OPTION, 20, 0, optZoom))->SetCheck();

	if(gOptions.mAntiAliasingEnable)
		((CTCheckBox*)ControlInPane(DLG_TYPE_OPTION, 20, 0, optAntiAliasing))->SetCheck();
		
	if(CTCheckBox* checkbox = (CTCheckBox*)ControlInPane(DLG_TYPE_OPTION, 20, 0, optSkillBar2)){
		if(gOptions.mSkillBarEnable)
			checkbox->SetCheck();
		else
			checkbox->SetUncheck();
	}

	if(CTRadioBox* radiobox = ((CTRadioBox*)ControlInPane(DLG_TYPE_OPTION, 20, 2, optDuelBox))){
		if(gOptions.mAllowDuel)
			radiobox->SetPressedButton(optDuelYes);
		else
			radiobox->SetPressedButton(optDuelNo);
	}

	gStatus = 0;
	gSkillBar2->mLoaded = false;
	gSkillBar2->Show();
}

void PopupFatalError(const char* errorMessage){
	if(MessageBoxA(gThisWND , errorMessage, "TitanROSE GUI Error", 0x00000000L | 0x00000010L) == 1)
		exit(0);
}

CWinCtrl* ControlInWindow(int window, int controlID){
	CTDialog* dialog = IT_MGR::Instance()->FindDlg(window);

	if(!dialog)
		PopupFatalError(String("Dialog not found! (%1)").arg(window));

	CWinCtrl* control = dialog->Find(controlID);		

	if(!control)
		PopupFatalError(String("Control not found! (%1:%2)").arg(window).arg(controlID));

	return control;
}

CWinCtrl* ControlInPane(int window, int pane, int tab, int controlID){
	CTDialog* dialog = IT_MGR::Instance()->FindDlg(window);	

	if(!dialog)
		PopupFatalError(String("Dialog not found! (%1)").arg(window));

	CTabbedPane* tabbedPane = (CTabbedPane*)dialog->Find(pane);		

	if(!tabbedPane)
		PopupFatalError(String("Pane not found! (%1:%2)").arg(window).arg(pane));

	CJContainer* container = (CJContainer*)tabbedPane->GetTabContainer(tab);

	if(!container)
		PopupFatalError(String("Container not found! (%1:%2:%3)").arg(window).arg(pane).arg(tab));

	CWinCtrl* control = container->Find(controlID);

	if(!control)
		PopupFatalError(String("Control not found! (%1:%2:%3:%4)").arg(window).arg(pane).arg(tab).arg(controlID));

	return control;
}

void _stdcall WriteVersion(){
	drawFont(GameDATA->m_hFONT[FONT_NORMAL_OUTLINE], true, 0,0, 0xFFFFFFFF, gVersion);
	drawFont(GameDATA->m_hFONT[FONT_NORMAL_OUTLINE], true, 0,  16, 0xFFFFFFFF, "www.TitanRose.com");
#ifdef DEBUG_MODE
	drawFont(GameDATA->m_hFONT[FONT_NORMAL_OUTLINE], true, 0, 32, 0xFFFFFFFF, "DEBUG_MODE");
#endif
}
void __declspec(naked) ASMWriteVersion(){
	static int jmpRet = 0x00499F6C;
	_asm {
		CALL WriteVersion
		JMP jmpRet
	}
}

HookOnLoad(0x00499F43, ASMWriteVersion, 36)