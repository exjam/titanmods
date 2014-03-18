#include "main.h"
#include "TRose\CodeHook.h"
#include "PvP.h"

#define FLAG_ING_HIDDEN	0x06000000

#define	IMG_ENEMY		73
#define	IMG_INVISIBLE	64
#define IMG_RED			73
#define IMG_BLUE		74
#define IMG_REDFLAG		75
#define IMG_BLUEFLAG	76

static unsigned int __stdcall ParseStatus(CGameOBJ* player, int team){
	if(!CanShowPVP()){
		int gameTeam = player->GetGameTeam();
		bool hasFlag = player->GetHasFlag();

		if(gameTeam == 1){			
			if(hasFlag)
				return IMG_REDFLAG;

			return IMG_RED;
		}

		if(gameTeam == 2){	
			if(hasFlag)
				return IMG_BLUEFLAG;

			return IMG_BLUE;
		}

		return 1;
	}

	if(team == CObjMGR::GetSelf()->GetTeam())
		return 1;

	if((player->GetStatusFlags() & FLAG_ING_HIDDEN))
		return IMG_INVISIBLE;
	
	return IMG_ENEMY;
}


/*
	Hides invisible characters on the minimap
*/
static _declspec(naked) void ASMMiniMap(){
	static int jmpNormal = 0x004B1079;
	static int jmpSameTeam = 0x004B1095;
	_asm {		
		SUB EDI, 0x20
		
		PUSH EAX
		PUSH EDI								//  Other Obj
		CALL ParseStatus	

		ADD EDI, 0x20
		CMP EAX, 1

		JE SameTeam

		FLD DWORD PTR SS:[ESP+0x14]
		PUSH EAX								//	iGraphicsID 
		JMP jmpNormal
SameTeam:
		JMP jmpSameTeam
	};
}

HookOnLoad(0x004B106B, ASMMiniMap, 1);