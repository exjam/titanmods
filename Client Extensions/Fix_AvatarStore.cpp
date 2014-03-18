#include "main.h"
#include "Controls.h"

void __stdcall HideShop(){
	if(CTDialog* dlgAvatarStore = IT_MGR::Instance()->FindDlg(DLG_TYPE_AVATARSTORE)){
		if(dlgAvatarStore->IsVision())
			dlgAvatarStore->Hide();
	}
}

void __declspec(naked) ASMHideShop(){
	static int jRet = 0x004F2A6C;
	_asm {
		PUSHAD
		CALL HideShop
		POPAD
		MOV EAX, DWORD PTR DS:[ESI+0x4]
		MOV CL, BYTE PTR DS:[EAX+0x6]
		JMP jRet
	}
}

void __declspec(naked) ASMCanOpenShop(){
	static int jRet = 0x004DE844;
	static int jFail = 0x004DE90E;
	_asm {
		CMP EAX, 9
		JL jOut
		CMP EAX, 11
		JG jOut
		JMP jRet
jOut:
		JMP jFail
	}
}

HookOnLoad(0x004DE83B, ASMCanOpenShop, 4);
HookOnLoad(0x004F2A66, ASMHideShop, 1);