#include "main.h"
#include "..\Shared\Code.hpp"
#include "..\Shared\RunOnLoad.hpp"
#include <SHO_GS\classUSER.h>
#include <SHO_GS\CZoneTHREAD.h>

/*
spawn protect: can skill but can't kill by using skills
*/

bool _stdcall IsInvincible(CObjCHAR* player){
	if(!player->IsUSER())
		return false;

	if(gFreeze){
		player->Set_HP(player->Get_MaxHP());
		return true;
	}

	classUSER* user = static_cast<classUSER*>(player);
	if(user->m_STORE.m_bActive == true){
		CustomAvatarData* data = CustomAvatarData::Get(user);
		clock_t dt = clock() - data->mShopOPEN;
		if(dt < 60000) 
			return false;

		if(user->m_IngSTATUS.IsSubSET(FLAG_SUB_STORE_MODE) == false) 
			return false;
		
		short iZoneNO = user->m_nZoneNO;
		if(iZoneNO == 1 || iZoneNO == 2 || iZoneNO == 51)
			return true;
	}

	return false;
}

static _declspec(naked) void ASMShopProtection(){
	static int jDAMAGE = 0x1006AC6B;
	static int jINVINC = 0x1006AC30;
	static int cIsSubSet = 0x10010AC0;
	_asm {
		CALL cIsSubSet	
		TEST EAX, EAX
		JNZ isSAFE

		MOV ECX,DWORD PTR SS:[EBP+0x8]
		PUSH ECX
		CALL IsInvincible
		TEST AL, AL
		JNZ isSAFE
		JMP jDAMAGE
isSAFE:
		JMP jINVINC
	}
}

HookOnLoad(0x1006AC27, ASMShopProtection, 4);
