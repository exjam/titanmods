#include "main.h"
#include "TRose\Game.h"
#include "Controls.h"
#include "Network.h"
#include "DuelInvite.h"
#include <TRose\CObjCHAR.h>

enum {
	COMMON_COMMAND_ADD_FRIEND	= 8,
	COMMON_COMMAND_SELFTARGET   = 13,
	COMMON_COMMAND_DUEL   = 27,
};

void __stdcall SkillAction(int skillID){
	switch(skillID){
	case COMMON_COMMAND_SELFTARGET:
		{
			CUserInputState* inputState = CUserInputState::Instance();
			CGameOBJ* self = CObjMGR::GetSelf();

			if(inputState && self)
				inputState->m_iCurrentTarget = self->m_nIndex;
		}
		break;
	case COMMON_COMMAND_ADD_FRIEND:
		IT_MGR::Instance()->OpenDialog(DLG_TYPE_ADDFRIEND, false);
		break;
	case COMMON_COMMAND_DUEL:
		{
			CUserInputState* inputState = CUserInputState::Instance();
			if (!inputState) return;

			CObjCHAR* object = CObjMGR::Instance()->Get_CharOBJ(inputState->m_iCurrentTarget, true);

			if(object && object->GetTYPE() == OBJ_AVATAR){
				gDuelInvite->Hide();
				IT_MGR::Instance()->OpenDialog(DLG_TYPE_DUELINVITE, false);
			}
		}
		break;
	}
}

void __declspec(naked) ASMCustomSkill(){
	static int jmpOut = 0x0043F1EB;
	_asm {
		MOV ECX, DWORD PTR DS:[EAX+EDX*4]
		MOV EAX, DWORD PTR DS:[ECX+0x18]
		PUSHAD
		PUSH EAX
		CALL SkillAction
		POPAD
		JMP jmpOut
	}
}

HookOnLoad(0x0043F1E5, ASMCustomSkill, 1);