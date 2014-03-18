#include "main.h"
#include <TRose/CStore.h>
// Store Union = 0x006971B0

static int gCurrentUnionShop;

void __declspec(naked) ASMPointShop(){
	static int jNormal = 0x0045D2C8;
	static int jShop = 0x0045D2F6;
	_asm {
		MOV DWORD PTR DS:[EBX+0x10],ECX
		MOV gCurrentUnionShop, ECX
		JLE SHORT lblPointShop
		MOV EDX,DWORD PTR DS:[0x6936A8]

		MOVSX EDX,BYTE PTR DS:[EDX+0x555]	// Edx = player union, restoring overwritten code
		CMP ECX, 0x07						// Ecx = shop union
		JE lblPointShop
		JMP jNormal
lblPointShop:		
		JMP jShop
	};
}

HookOnLoad(0x0045D2B6, ASMPointShop, 0);

// Custom errors
void __declspec(naked) ASMShopError(){
	static int jRet = 0x004934E5;
	_asm {
		CMP BYTE PTR DS:[0x6971B0], 7
		JE CustomERROR
		PUSH 0x0FC	// 252: More Union Points..
		JMP jRet
	CustomERROR:
		PUSH 0x0FE	// 254: More PvP Points..
		JMP jRet
	}
}

void __declspec(naked) ASMShopError2(){
	static int jRet = 0x00453784;
	_asm {
		CMP BYTE PTR DS:[0x6971B0], 7
		JE CustomERROR
		PUSH 0x0FC	// 252: More Union Points..
		JMP jRet
	CustomERROR:
		PUSH 0x0FE	// 254: More PvP Points..
		JMP jRet
	}
}

HookOnLoad(0x0049339F, ASMShopError, 0);
HookOnLoad(0x00453768, ASMShopError2, 0);

// Which union id to get/set points -> NPC unionid instead of player's
void __stdcall GetShopUnionID(){
	unsigned char npcUnion[] = { 0x0D, 0xB0, 0x71, 0x69 };
	Code::Write(0x00453744, npcUnion, 4);
	Code::Write(0x0049337B, npcUnion, 4);
	Code::Write(0x004933D0, npcUnion, 4);
	Code::Write(0x00453AE6, npcUnion, 4);

	unsigned char npcUnion2[] = { 0x15, 0xB0, 0x71, 0x69 };
	Code::Write(0x004933B1, npcUnion2, 4);
	Code::Write(0x00453B07, npcUnion2, 4);
}

RunOnLoad(GetShopUnionID);

void _stdcall SetShopStats(tagBaseITEM& inItem){
	if(!gCurrentUnionShop) return;

	if(inItem.m_cType >= 1 && inItem.m_cType <= 6){
		inItem.m_nGEM_OP = 1;
		inItem.m_bIsAppraisal = 0;
	}else if(inItem.m_cType >= 8 && inItem.m_cType <= 9){
		inItem.m_bHasSocket = 1;
		inItem.m_bIsAppraisal = 1;
	}
}

/*
004D0E9F   8B4F 02          MOV ECX,DWORD PTR DS:[EDI+2]
004D0EA2   C1E9 1A          SHR ECX,1A
004D0EA5   F6C1 01          TEST CL,1
*/

static _declspec(naked) void ASMSetShopStats(){
	static int jRET = 0x0045D4EF;
	_asm {
		LEA ECX,DWORD PTR SS:[ESP+0x10]
		PUSH ECX
		CALL SetShopStats

		LEA ECX,DWORD PTR SS:[ESP+0x10]
		PUSH ECX
		JMP jRET
	};
}

HookOnLoad(0x0045D4EA, ASMSetShopStats, 0);

//00440A5C     68 FB000000    PUSH 0FB
//When it says "Union Points: %d" change to "PvP Points: %d" :D

int _stdcall GetPvpShopPointStr(){
	if(CStore::Instance()->GetUnionNo() == 7)
		return 255;
	else
		return 251;
}

static _declspec(naked) void ASMPvPShopPointsDisplay(){
	static int jRET = 0x00440A61;
	_asm {
		CALL GetPvpShopPointStr
		MOV ECX, DWORD PTR DS:[0x69397C]
		PUSH EAX
		JMP jRET
	};
}

HookOnLoad(0x00440A5C, ASMPvPShopPointsDisplay, 0);