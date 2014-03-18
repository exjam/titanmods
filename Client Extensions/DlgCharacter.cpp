#include "main.h"
#include <TRose\RoseAPI.h>
#include <TRose\CObjMGR.h>
#include <TRose\CGameOBJ.h>

#include <TRose\IT_MGR.h>
#include <TRose\DrawImpl.h>
#include "PvP.h"

void _stdcall DrawUp(){
	CGameOBJ* self = CObjMGR::GetSelf();
	if (!self) return;

	::drawFontf(GameDATA->m_hFONT[FONT_NORMAL_BOLD], true, 43, 138, COLOUR_WHITE, "%d",  self->GetStat(81));		
	::drawFontf(GameDATA->m_hFONT[FONT_NORMAL_BOLD], true, 43, 183, COLOUR_WHITE, "%d",  self->GetStat(83));		
	::drawFontf(GameDATA->m_hFONT[FONT_NORMAL_BOLD], true, 146, 138, COLOUR_WHITE, "%d", self->GetStat(84));		
	::drawFontf(GameDATA->m_hFONT[FONT_NORMAL_BOLD], true, 146, 183, COLOUR_WHITE, "%d", self->GetStat(85));		
}

static _declspec(naked) void ASMUnionPoints(){
	static int retAddr = 0x004A5B80;
	_asm {		
		CALL DrawUp      
		JMP retAddr
	};
}

HookOnLoad(0x004A5B1B, ASMUnionPoints, 0);

void _stdcall DrawRank(){
	if(GetRank() == 0)
		::drawFontf(GameDATA->m_hFONT[FONT_NORMAL], true, 59, 130, COLOUR_RED, "%s", "Unranked");
	else
		::drawFontf(GameDATA->m_hFONT[FONT_NORMAL], true, 59, 130, COLOUR_YELLOW, "%s (%i)", gGameRank[GetRank()], GetRank());
}

static _declspec(naked) void ASMDrawRank(){
	static int retAddr = 0x004A5706;
	_asm {		
		CALL ESI
		ADD ESP,0x24
		CALL DrawRank
		JMP retAddr
	};
}

HookOnLoad(0x004A5701, ASMDrawRank, 0);