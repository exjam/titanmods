#include "main.h"
#include "Controls.h"
#include <TRose\ExternalUILobby.h>

void __stdcall LoginShow(){
	CExternalUIManager* euiManager = CExternalUILobby::Instance()->GetExternalUIManager();
	CTDialog* dlgLogin = euiManager->GetEUI(EUI_LOGIN);
	
	if(CTComboBox* comboBox = (CTComboBox*)dlgLogin->Find(6)){
		for(List<char*>::Iterator username = gOptions.mUsernames.begin(); username != gOptions.mUsernames.end(); ++username)
			comboBox->AddItem(String(" %1").arg(*username).Str());

		comboBox->SetSelectedItem(-1);
	}
}

void __declspec(naked) ASMLoginShow(){
	static int jRet = 0x00499A35;
	_asm {
		PUSHAD
		CALL LoginShow
		POPAD
		MOV EAX, DWORD PTR DS:[0x00695B38]
		JMP jRet
	}
}

HookOnLoad(0x00499A30, ASMLoginShow, 0);

void __stdcall LoginProcess(){
	CExternalUIManager* euiManager = CExternalUILobby::Instance()->GetExternalUIManager();
	CTDialog* dlgLogin = euiManager->GetEUI(EUI_LOGIN);
	
	if(CTComboBox* comboBox = (CTComboBox*)dlgLogin->Find(6)){
		if(comboBox->GetSelectedItemID() != -1) {
			if(CTEditBox* editBox = (CTEditBox*)dlgLogin->Find(2)){
				String username(comboBox->GetSelectedItem());

				editBox->clear_text();
				editBox->AppendText(username.SubStr(1, username.Length() - 1));
			}

			comboBox->SetSelectedItem(-1);
		}
	}
}

void __declspec(naked) ASMLoginProcess(){
	static int jRet = 0x0049A085;
	_asm {
		PUSHAD
		CALL LoginProcess
		POPAD
		POP EBX
		POP EDI
		POP ESI
		MOV EAX, EBP
		JMP jRet
	}
}

HookOnLoad(0x0049A080, ASMLoginProcess, 0);

void __stdcall SuccessfulLogin(){
	CExternalUIManager* euiManager = CExternalUILobby::Instance()->GetExternalUIManager();
	CTDialog* dlgLogin = euiManager->GetEUI(EUI_LOGIN);

	if(CTCheckBox* checkBox = (CTCheckBox*)dlgLogin->Find(10)){
		if(!checkBox->IsCheck())
			return;
	}
		
	if(CTEditBox* editBox = (CTEditBox*)dlgLogin->Find(2)){
		for(List<char*>::Iterator username = gOptions.mUsernames.begin(); username != gOptions.mUsernames.end(); ++username){
			if(strcmp(*username, editBox->get_text()) == 0)
				return;
		}

		char* username = new char[17];
		strncpy(username, editBox->get_text(), 16);

		gOptions.mUsernames.push_back(username);
	}
}

void __declspec(naked) ASMSuccessfulLogin(){
	static int jRet = 0x00499D92;
	_asm {
		PUSHAD
		CALL SuccessfulLogin
		POPAD
		MOV ECX, DWORD PTR SS:[ESP+0x14]
		POP EDI
		JMP jRet
	}
}

HookOnLoad(0x00499D8D, ASMSuccessfulLogin, 0);