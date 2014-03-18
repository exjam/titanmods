#include "main.h"
#include "AI.h"
#include "CrashChecker.h"
#include "..\Shared\RunOnLoad.hpp"
#include <SHO_GS\classUSER.h>
#include <SHO_GS\CZoneTHREAD.h>
#include <SHO_GS\CZoneLIST.h>
#include <SHO_GS\GS_CThreadLOG.h>
#include <SHO_GS\GS_CThreadSQL.h>
#include <SHO_GS\CLIB_GameSRV.h>
#include <SHO_GS\CUserLIST.h>

bool gFreeze = false;
clock_t gZoneCheckTimes[200];

void DoExit() {
	Log(MSG_INFO, ">>DoExit");
	for(unsigned long i=0; i<g_pUserLIST->GetMaxSocketCOUNT(); i++){
		classUSER* user = (classUSER*)g_pUserLIST->GetSOCKET(i);
		if(!user) continue;

		CustomAvatarData* data = CustomAvatarData::Get(user);
		if(data->pDuel.mInDuel){
			__int64 money = user->GetCur_MONEY();
			user->Add_CurMONEY(data->pDuel.mZulie);
			data->pDuel.Reset();
			Log(MSG_INFO, "Returned zulie to %s : %I64d -> %I64d", user->Get_NAME(), money, user->GetCur_MONEY());
		}
		
		g_pThreadSQL->UpdateUserRECORD(user);	// Force update first incase a map crashed and it never executes.
		user->m_dwTimeToLogOUT = 0;
		user->m_btWishLogOutMODE = 3;
	}

	BlockPackets();
	Log(MSG_INFO, "<<DoExit");
}

void BlockPackets() {
	Code::NOP((unsigned char*)0x1008F941, 15);
	gFreeze = true; 
	Log(MSG_INFO,"Packets Blocked!");
}

void EnablePackets(){
	static unsigned char code[15] = { 0x52, 0x8B, 0x4D, 0xFC, 0x81, 0xE9, 0xA0, 0x00, 0x00, 0x00, 0xE8, 0x40, 0xF4, 0xFF, 0xFF, } ;
	Code::Write(0x1008F941, code, 15);
	gFreeze = false;
	Log(MSG_INFO,"Packets Enabled!");
}

void CheckZones() {
	Log(MSG_INFO,"Start CheckZones()"); 
	memset(gZoneCheckTimes, 0, sizeof(clock_t)*200);

	do {
		Sleep(3000);
		if(!g_pZoneLIST) continue;
		if(gFreeze) continue;

		int cnt = g_pZoneLIST->GetZoneCNT();
		for(int i = 1; i <= cnt; ++i){
			if(!gHasLoaded) continue;
			if(!g_pZoneLIST->GetZONE(i)) continue;

			if(gZoneCheckTimes[i] == 0)
				gZoneCheckTimes[i] = clock();

			clock_t dt = clock() - gZoneCheckTimes[i];
			if(dt <= 60 * CLOCKS_PER_SEC) continue;

			CZoneTHREAD* pZone = g_pZoneLIST->GetZONE(i);
			Log(MSG_INFO, "[CRASH] Map %i, Players (%i): ", i, pZone->m_lUserCNT);
			g_pServer->Send_ANNOUNCE(0, "Server Down - Please contact a [DEV]");
			DoExit();
			break;
		}
	}while(gHasLoaded == true);

	Log(MSG_INFO,"Exit CheckZones()"); 
}

void StartZoneCrashThread(){
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&CheckZones, 0, 0, 0);
}

void _stdcall UpdateTime(CZoneTHREAD* zone){
	short id = zone->Get_ZoneNO();
	if(id >= 200) return;
	RunAIP(id);
	gZoneCheckTimes[id] = clock();
}

void __declspec(naked) ASMZoneCheck(){
	static int RetJmp = 0x1006144F;
	_asm {
		MOV ECX,DWORD PTR SS:[EBP-0x4]

		PUSHAD
		PUSH ECX
		CALL UpdateTime
		POPAD

		ADD ECX,0x20A8

		JMP RetJmp
	}
}

HookOnLoad(0x10061446, ASMZoneCheck, 4);

void _stdcall LogError(classUSER* player, char* error){
	Log(MSG_ERROR, "ODBC Error: %s[%i,%i] : %s", player->Get_NAME(), player->Get_LEVEL(), player->Get_JOB(), error);
}

void __declspec(naked) ASMPlayerSaveFail() {
	static int RetJmp = 0x100946A7;
	static int CheckESP = 0x1004A910;
	_asm {
		CALL CheckESP

		PUSHAD
		MOV ECX, DWORD PTR SS:[EBP+0x8]
		PUSH EAX
		PUSH ECX
		CALL LogError
		POPAD

		JMP RetJmp
	}
}

HookOnLoad(0x100946A2, ASMPlayerSaveFail, 0);

void _stdcall OnShutdown() {
	if(!gHasLoaded) 
		return;

	gHasLoaded = false;
	gInitDone = false;
	
	Log(MSG_INFO, "OnShutdown");
	DoExit();
}

void __declspec(naked) ASMOnShutdown() {
	static int RetJmp = 0x100A9751;
	_asm {
		PUSHAD
		CALL OnShutdown
		POPAD
		MOV ECX,0xA
		JMP RetJmp
	}
}

HookOnLoad(0x100A974C, ASMOnShutdown, 0);
