#include <windows.h>
#include "main.h"
#include "CrashChecker.h"
#include "Achievements.h"
#include "AI.h"
#include "..\Shared\RunOnLoad.hpp"
#include "..\Shared\Console.hpp"
#include <ExLIB\Directory.hpp>
#include <iostream>

BOOL WINAPI TrapCtrlHandler(DWORD dwCtrlType){
	switch(dwCtrlType){
		case CTRL_C_EVENT:
		case CTRL_CLOSE_EVENT:
		case CTRL_BREAK_EVENT:
			Log(MSG_WARNING,"Never use the console to shutdown!");
			if(gFreeze) EnablePackets();
			else BlockPackets();
			break;
		default:
			return FALSE;
	}
	return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved){
	switch(dwReason){
		case DLL_PROCESS_ATTACH:
		{
			CreateConsole();
			SetConsoleCtrlHandler(TrapCtrlHandler, TRUE);
			
			char strExePath[MAX_PATH];
			GetModuleFileName(NULL, strExePath, MAX_PATH);
			String path = GetDirectoryOfFile(strExePath) + "\\achievements.xml";
			gAchievementList.LoadXML(path);
			Log(MSG_INFO, "%i Achievements loaded.", gAchievementList.mAll.Size());
			
			Log(MSG_INFO, "Running startup functions...");
			RunList::Instance().RunFunctions();

			Log(MSG_INFO, "Applying hooks...");
			HookList::Instance().ApplyHooks();

			Log(MSG_INFO, "Applying code changes...");
			WriteList::Instance().ApplyWrites();

			Log(MSG_INFO, "TitanROSE modifications loaded");
			return TRUE;
		}

		case DLL_PROCESS_DETACH:
			return TRUE;
	};

	return TRUE;
}

CLIB_GameSRV* g_pServer;
CPartyBUFF* g_pPartyBUFF;
CUserLIST* g_pUserLIST;
CZoneLIST* g_pZoneLIST;
CObjMNG* g_pObjMGR;
GS_CThreadSQL* g_pThreadSQL;
GS_CThreadLOG* g_pThreadLOG;
CThreadGUILD* g_pThreadGUILD;
CQuestDATA* g_pQuestDATA;

STBVALUE** g_TblZONE;
STBVALUE** g_TblSTATUS;

#include <SHO_GS\CLIB_GameSRV.h>
#include <SHO_GS\CZoneLIST.h>

bool gHasLoaded = false;

void _stdcall RunAfterLoad() {
	g_pServer		=	CLIB_GameSRV::GetInstance();		//(CLIB_GameSRV*)*((char**)0x100CB8B0);
	g_pPartyBUFF	=	(CPartyBUFF*)*((char**)0x100CB8B4);
	g_pZoneLIST		=	CZoneLIST::GetInstance();			//(CZoneLIST*)*((char**)0x100CB8C0);
	g_pUserLIST		=	(CUserLIST*)*((char**)0x100CBA1C);
	g_pObjMGR		=	(CObjMNG*)*((char**)0x100CBA24);
	g_pThreadSQL	=	(GS_CThreadSQL*)*((char**)0x100CBA30);
	g_pThreadLOG	=	(GS_CThreadLOG*)*((char**)0x100CBA34);
	g_pThreadGUILD	=	(CThreadGUILD*)*((char**)0x100CBA3C);
	g_pQuestDATA	=   (CQuestDATA*)(0x100CC040);

	g_TblZONE		=	(STBVALUE**)*((char**)0x100CBFDC);	// 0x100CBFDC - 0x20 (m_ppDATA)
	g_TblSTATUS		=	(STBVALUE**)*((char**)0x100CBF2C);

	InitVarList();
	CleanAllPvpNpcs();
	gHasLoaded = true;
	StartZoneCrashThread();
}

void __declspec(naked) HookLoadVariables(){
	static int retAddr = 0x100ABA4B;
	_asm {
		PUSHAD
		CALL RunAfterLoad
		POPAD
		MOV AL,1
		MOV ECX,DWORD PTR SS:[EBP-0xC]
		JMP retAddr
	}
}

HookOnLoad(0x100ABA46, HookLoadVariables, 0);