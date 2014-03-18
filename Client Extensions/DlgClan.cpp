#include "main.h"
#include "Controls.h"
#include "TRose\CodeHook.h"

class CTAcceptLeaveClan : public CTCommand {
public:
	CTAcceptLeaveClan(){}
	virtual ~CTAcceptLeaveClan(){}
	virtual bool Exec(CTObject* object){
		static int call1 = 0x004FCBE0;
		static int call2 = 0x00451D00;
		static int call3 = 0x00451B60;
		static int call4 = 0x00467320;
		_asm {
			MOV ECX,DWORD PTR DS:[0x699920]
			PUSH 0
			PUSH 7
			ADD ECX, 0x3C
			CALL call1
			CALL call2
			MOV ECX, EAX
			CALL call3
			MOV ECX, DWORD PTR DS:[0x6936A8]
			CALL call4
		};

		return true;
	}
};

void __stdcall ShowClanLeaveBox(){
	CTCommand* command = new CTAcceptLeaveClan();
	IT_MGR::Instance()->OpenMsgBox("Do you really want to leave this clan?", MsgBox::BT_OKCANCEL, true, 0, command, NULL, 0);
}

static _declspec(naked) void ASMCleanLeavePopup(){
	static int jmpRet = 0x004A2213;
	_asm {		
		ADD ESP, 4
		CALL ShowClanLeaveBox
		JMP jmpRet
	};
}

HookOnLoad(0x004A1D32, ASMCleanLeavePopup, 1);