#include "main.h"
#include "..\Shared\Code.hpp"
#include "..\Shared\RunOnLoad.hpp"

struct MapWarps{
	unsigned int mMapID;
	unsigned int mWarpCount;
	unsigned int* mWarps;
};

unsigned int gMapWarpCount;
MapWarps* gMapWarpList[200];

void ASMWarpHack();

void __stdcall WarpHackFix(){
	FILE* fh;
	fopen_s(&fh, "warps", "rb");
	if(!fh){
		MessageBoxA(NULL, "Error loading warps!", "TitanGame DLL Error", 0);
		return;
	}
	
	memset(gMapWarpList, 0, sizeof(MapWarps*) * 200);

	fread(&gMapWarpCount, 4, 1, fh);
	for(unsigned int i = 0; i < gMapWarpCount; i++){
		MapWarps* map = new MapWarps();
				
		fread(&map->mMapID, 4, 1, fh);
		fread(&map->mWarpCount, 4, 1, fh);
		map->mWarps = new unsigned int[map->mWarpCount];
		for(unsigned int j = 0; j < map->mWarpCount; j++)
			fread(&map->mWarps[j], 4, 1, fh);

		gMapWarpList[map->mMapID] = map;
	}

	fclose(fh);

	Code::JmpHook(0x1008BFAB, &ASMWarpHack, 0);
}

RunOnLoad(WarpHackFix);

dword __stdcall CppWarpHack(unsigned int mapid, unsigned int warp){
	MapWarps* map = gMapWarpList[mapid];
	if(map == NULL) return 0;

	warp = warp & 0xFFFF;
	for(unsigned int i = 0; i < map->mWarpCount; i++){
		if(map->mWarps[i] == warp)
			return 1;
	}

	return 0;
}

void __declspec(naked) ASMWarpHack(){
	static int returnWarpHack = 0x1008BFB0;

	_asm{
		MOV EAX, DWORD PTR SS:[ESP+0x4]
		PUSH ECX
		ADD ECX, 0x0A0
		MOV ECX, DWORD PTR DS:[ECX+0x4]
		MOVSX ECX, WORD PTR DS:[ECX+0x50]
		MOV DX, WORD PTR DS:[EAX+0x6]

		PUSH EDX
		PUSH ECX
		CALL CppWarpHack
		CMP EAX, 0
		JE failed

		MOV DX, 0xE8
		XOR EAX, EAX
		POP ECX
		JMP returnWarpHack

failed:
		XOR EAX,EAX
		XOR ECX,ECX
jump0:
		MOV EAX, DWORD PTR DS:[ESP+ECX]
		CMP EAX, 0x1008F950
		JE jump1
		ADD ECX, 0x4
		JMP jump0
jump1:
		ADD ESP, ECX
		MOV EBX, DWORD PTR DS:[ESP+0x168]
		MOV EDI, ESP
		ADD EDI, 0x74
		MOV EBP, ESP
		ADD EBP, 0x28
		MOV ESI, ESP
		ADD ESI, 0x8
		XOR EAX, EAX
		MOV ECX, 0x1
		RETN 4
	}
}
