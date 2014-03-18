#include "main.h"
#include "PvP.h"
#include "Achievements.h"
#include "CustomAvatarData.h"
#include <SHO_GS\CLIB_GameSRV.h>


#define	FLAG_ING_BAD	(	FLAG_ING_POISONED		| FLAG_ING_DEC_MOV_SPEED| FLAG_ING_DEC_ATK_SPEED	\
						  | FLAG_ING_DEC_APOWER		| FLAG_ING_DEC_DPOWER	| FLAG_ING_DEC_RES			\
						  | FLAG_ING_DEC_HIT		| FLAG_ING_DEC_CRITICAL | FLAG_ING_DEC_AVOID		\
						  |	FLAG_ING_DUMB			| FLAG_ING_SLEEP		| FLAG_ING_FAINTING	)		\

bool __stdcall OnDeath(CGameOBJ* victim, CGameOBJ* killer){
	AchievementOnKill(victim, killer);

	if(!AreDuelling(victim, killer)) return false;

	CustomAvatarData* data = CustomAvatarData::Get(victim);
	if(data->pDuel.mIsDead == false){
		data->pDuel.mIsDead = true;

		classUSER* vusr = static_cast<classUSER*>(victim);
		vusr->m_IngSTATUS.UpdateIngSTATUS(vusr, 57, 30, 1, 0, 0);
	}

	return true;
}

void __declspec(naked) ASMOnDeathHook(){
	static int retAddr = 0x1006ACAD;
	static int retAddrOver = 0x1006B041;
	static int callAddr = 0x1000C550;
	_asm {
		MOV EAX, DWORD PTR SS:[EBP+0x8]
		MOV ECX, DWORD PTR SS:[EBP-0x10]
		PUSH ECX
		PUSH EAX
		CALL OnDeath
		TEST AL, AL
		JE jNORMAL

		JMP retAddrOver
jNORMAL:
		MOV ECX, DWORD PTR SS:[EBP-0x10]
		CALL callAddr
		JMP retAddr
	}
}

HookOnLoad(0x1006ACA5, ASMOnDeathHook, 3);