#include "main.h"
#include "PvP.h"
#include "..\Shared\Code.hpp"
#include "..\Shared\RunOnLoad.hpp"
#include <SHO_GS\CObjMNG.h>
#include <SHO_GS\CZoneTHREAD.h>
#include <SHO_GS\CZoneFILE.h>

void ASMPkHack();
extern STBVALUE** g_TblZONE;

unsigned char _stdcall IsPKable(classUSER* user, unsigned short targetid){
	CObjCHAR* targetObj = g_pObjMGR->Get_CharOBJ(targetid, true);	// CheckHP = true -> no dead mobs plx :D
	if(!targetObj) return false;
	if(!targetObj->IsUSER()) return true;

	classUSER* target = static_cast<classUSER*>(targetObj);
	CustomAvatarData* userData = CustomAvatarData::Get(user);
	CustomAvatarData* targetData = CustomAvatarData::Get(targetObj);

	if(targetData->pDuel.mInDuel || userData->pDuel.mInDuel){
		if(!targetData->pDuel.mIsDead && !userData->pDuel.mIsDead){
			if(targetData->pDuel.mRequestID == user->Get_INDEX() && userData->pDuel.mRequestID == target->Get_INDEX())
				return true;
		}

		return false;
	}

	return g_TblZONE[target->m_nZoneNO][18].GetINT() != PVP_CANT;
}

unsigned char _stdcall CanDoSkill(classUSER* user, unsigned short targetid, short skill){
	CGameOBJ* targetObj = g_pObjMGR->Get_CharOBJ(targetid, false);	// CheckHP = true -> no dead mobs plx :D
	if(targetObj == NULL || !targetObj->IsUSER() || user == targetObj)
		return true;

	classUSER* target = static_cast<classUSER*>(targetObj);

	CustomAvatarData* targetData = CustomAvatarData::Get(targetObj);
	CustomAvatarData* userData = CustomAvatarData::Get(user);
	if(targetData->pDuel.mInDuel || userData->pDuel.mInDuel){
		if(!targetData->pDuel.mIsDead && !userData->pDuel.mIsDead){
			if(targetData->pDuel.mRequestID == user->Get_INDEX() && userData->pDuel.mRequestID == target->Get_INDEX()){
				if(!target->m_IngSTATUS.IsSET(0x40000000))
					return true;
			}
		}

		return false;
	}

	short zone = user->m_nZoneNO;
	return !(zone >= 70 && skill >= 1841 && skill <= 1845);
}

bool _stdcall CanSelfSkill(classUSER* user, short skill){
	if(!user) return false;

	short zone = user->m_nZoneNO;
	if(zone >= 70 && skill >= 1841 && skill <= 1845)
		return false;
	
	return user->Do_SelfSKILL(skill);
}

void __declspec(naked) ASMPkHack(){
	static int  retAtk = 0x1007A335;
	static int  retFail = 0x1007A328;
	_asm {
		MOVZX EDX,WORD PTR DS:[ECX+0x6]
		PUSH EDX // push target

		PUSH EDX // arg target

		MOV EDX,DWORD PTR SS:[EBP-0x4]
		PUSH EDX // arg  this

		CALL IsPKable
		TEST AL, AL

		POP EDX // pop target
		MOV ESI,ESP
		JE failor
		JMP retAtk
failor:
		JMP retFail
	}
}

void __declspec(naked) ASMPkSkillHack(){
	static int  retAtk = 0x1007CE5D;
	static int  retFail = 0x1007CE66;
	_asm {
		PUSHAD

		PUSH ECX							// skill idx

		MOV EDX,DWORD PTR SS:[EBP+0x8]
		MOVZX EAX,WORD PTR DS:[EDX+0x6]
		PUSH EAX							// id

		MOV ECX,DWORD PTR SS:[EBP-0x4]		// this
		PUSH ECX
		CALL CanDoSkill
		TEST AL, AL

		POPAD

		JE SkipAttack

		PUSH ECX  
		MOV EDX,DWORD PTR SS:[EBP+0x8]
		MOVZX EAX,WORD PTR DS:[EDX+0x6]

		JMP retAtk
SkipAttack:
		MOV AL, 0
		JMP retFail
	}
}

void __declspec(naked) ASMSelfSkill(){
	static int  jret = 0x1007D126;

	_asm {
		PUSH ECX							// skill idx
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		PUSH ECX							// classUSER
		CALL CanSelfSkill
		JMP jret
	}
}

HookOnLoad(0x1007A32F,ASMPkHack, 1);
HookOnLoad(0x1007CE55, ASMPkSkillHack, 3);
HookOnLoad(0x1007D11D, ASMSelfSkill, 4);
