#include "main.h"
#include "Controls.h"
#include <TRose\RoseAPI.h>
#include <ExLIB\Directory.hpp>
#include <iostream>

AchievementList gAchievementList;
AchievementData gAchievementData;

char* gStats[] = {"MaxHP +5","MaxMP +5","Str +1","Dex +1","Int +1","Con +1","Cha +1","Sen +1","MaxHP +10","MaxMP +10","Atk Power +2","Str +1 MaxHP +5","Dex +1 MaxHP +5","Int +1 MaxMP +5","Con +1 MaxHP +5","Def +2","Accuracy +2","MaxHP +15","MaxMP +15","Str +1 Sen +1","Str +1 Con +1","Dex +1 Sen +1","Dex +1 Con +1","Int +1 Sen +1","Int +1 Con +1","Con +6 Sen +5","Cha +1 Con +1","Cha +1 Int +1","Str +2","Dex +2","Int +2","Con +2","Cha +2","Sen +2","Atk Power +3","Str +1 Atk Power +2","Dex +1 Atk Power +2","Int +1 Atk Power +2","Con +1 Atk Power +2","Def +3","Accuracy +3","Magic Res +3","Dodge Rate +3","Atk Power +2 Def +2","Con +1 HP Recovery +1","Sen +1 HP Recovery +1","Str +7 Dex +7","Str +2 Con +1","Str +2 MaxHP +10","Dex +2 Con +1","Dex +2 MaxHP +10","Int +2 Con +1","Int +2 MaxHP +10","Con +2 MaxHP +10","Sen +2 MaxHP +10","Atk Power +3 MaxHP +30","MaxHP +20","MaxMP +20","Str +3","Dex +3","Int +3","Con +3","Cha +3","Sen +3","Def +2 MaxHP +15","Cri +3","Sen +2 Dodge Rate +2","Dex +2 HP Recovery +1","Int +2 MP Recovery +1","Con +2 MP Recovery +1","Cha +2 HP Recovery +1","Atk Power +5","Str +2 Atk Power +3","Dex +2 Atk Power +3","Con +2 Atk Power +15","Sen +2 Atk Power +3","Str +2 Cri +2","Dex +2 Cri +2","Int +2 Cri +2","Con +2 Cri +2","Str +3 MaxHP +10","Dex +3 MaxHP +10","Int +3 MaxMP +10","Con +3 MaxMP +30","Con +3 MaxHP +10","MaxHP +25","MaxMP +25","Def +5","Accuracy +5","Magic Res +5","Dodge Rate +5","Str +4","Dex +4","Int +4","Con +4","Cha +4","Sen +4","Sen +3 MaxHP +15","Str +3 Sen +2","Str +3 Con +2","Str +3 Atk Power +15","Dex +3 Sen +2","Dex +3 Con +2","Dex +3 Atk Power +3","Int +3 Sen +2","Int +3 Con +2","Int +3 Atk Power +3","Con +3 Sen +2","Con +3 Atk Power +3","Cha +3 Int +2","Sen +2 Accuracy +4","MaxHP +30","MaxMP +30","Dex +4 Dodge Rate +2","Int +2 MP Consumption +5","Con +4 Dodge Rate +2","Sen +4 Dodge Rate +2","Atk Power +7","Str +5","Dex +5","Int +5","Con +5","Cha +5","Sen +5","Cri +5","Str +4 MaxHP +15","Dex +4 MaxHP +15","Int +4 MaxMP +15","Con +4 MaxHP +15","Sen +4 MaxHP +15","Cha +3 Sen +3","Cha +2 Magic Res +5","Sen +3 Accuracy +4","Str +4 Dex +2","Atk Power +5 MaxHP +20","Def +7 Magic Res +14","Def +7","Accuracy +7","Magic Res +7","Dodge Rate +7","Atk Power +5 Accuracy +4","Con +3 MP Consumption +2","Sen +3 MP Consumption +2","Def +5 MaxHP +20","Magic Res +5 MaxMP +20","Dodge Rate +5 MaxHP +20","Def +7 MaxHP +5","Atk Power +8","Cha +4 Atk Power +4","MaxHP +35","MaxMP +35","Str +3 Accuracy +5","Dex +3 Accuracy +20","Int +3 Accuracy +5","Str +4 Cri +3","Dex +4 Cri +3","Int +4 Cri +3","Con +4 Cri +3","Cha +4 Cri +3","Str +6","Dex +6","Int +6","Con +6","Cha +6","Sen +6","Str +4 Atk Power +5","Dex +4 Atk Power +5","Int +4 Atk Power +15","Con +4 Atk Power +5","Int +4 MP Consumption +2","Def +8","Accuracy +8","Magic Res +8","Dodge Rate +8","Def +5 Dodge Rate +5","Str +5 MaxHP +20","Dex +5 MaxHP +20","Int +5 MaxHP +20","Con +5 MaxHP +20","Str +4 Accuracy +5","Int +4 Accuracy +5","Cha +4 Def +5","Sen +4 Magic Res +5","MaxHP +40","MaxMP +40","Str +7","Dex +7","Int +7","Con +7","Cha +7","Sen +7","Cri +7","Str +5 Atk Power +20","Dex +5 Atk Power +5","Int +5 Atk Power +5","Con +5 Atk Power +5","Str +5 HP Recovery +2","Dex +5 HP Recovery +2","Int +5 MP Recovery +2","Con +5 HP Recovery +2","Accuracy +9","Magic Res +9","Atk Power +10","Atk Power +7 Def +5","Str +5 Def +5","Dex +5 Dodge Rate +5","Con +5 Dodge Rate +5","Atk Power +8 MaxHP +25","Dex +7 MaxMP +15","Int +7 MaxMP +50","Con +7 MaxMP +15","MaxHP +45","MaxMP +45","Sen +4 Accuracy +7","Atk Power +7 Accuracy +6","Sen +5 Dodge Rate +6","Def +10","Accuracy +10","Magic Res +10","Dodge Rate +10","Str +6 MaxHP +25","Dex +6 MaxHP +25","Int +6 MaxMP +25","Con +6 MaxHP +25","Str +8","Dex +8","Int +8","Con +8","Sen +8","Def +10 MaxHP +6","Str +6 Def +5","Sen +6 Accuracy +5","Atk Power +7 Cri +5","Def +8 MaxHP +50","Accuracy +8 MaxHP +25","Magic Res +8 MaxMP +25","Str +7 MaxHP +20","Dex +7 MaxHP +20","Int +7 MaxHP +20","Cha +5 HP Recovery +3","Sen +7 MaxMP +20","Atk Power +12","Sen +7 MaxHP +25","Def +7 Magic Res +7","MaxHP +50","MaxMP +50","Str +6 Cri +5","Dex +6 Cri +5","Dex +6 Con +5","Int +6 Con +5","Con +6 Cri +5","Str +9","Int +9","Con +9","Sen +6 MP Consumption +3","Atk Power +10 Def +5","Int +5 MP Consumption +4","Cha +5 MP Consumption +4","Def +12","Accuracy +12","Magic Res +12","Dodge Rate +12","Atk Power +8 Accuracy +8","Atk Power +12 MaxHP +20","Accuracy +10 Dodge Rate +5","Magic Res +10 Dodge Rate +5","Str +10","Dex +10","Int +10","Con +10","Sen +10","Cri +10","Def +8 Magic Res +8","Con +6 MP Consumption +4","Atk Power +10 Accuracy +7","Atk Power +14","Def +13","Accuracy +10 Cri +5","Atk Power +10 Cri +20","Def +12 MaxHP +20","Accuracy +12 MaxHP +20","Magic Res +12 MaxHP +20","Dodge Rate +12 MaxHP +20","Def +10 Dodge Rate +7","Atk Power +15","MaxHP +60","Sen +8 Accuracy +8","Con +8 Atk Power +10","Cri +12","Def +15","Accuracy +15","Magic Res +15","Dodge Rate +15","Str +8 Accuracy +10","Dex +8 Accuracy +10","Int +8 MP Consumption +5","MaxHP +70","Cri +15","Atk Power +15 Accuracy +15","Atk Power +15 Cri +15","Garnet [1]","Garnet [2]","Garnet [3]","Garnet [4]","Garnet [5]","Garnet [6]","Garnet [7]","Garnet [8]","Garnet [9]","Garnet [10]", "Ruby [1]","Ruby [2]","Ruby [3]","Ruby [4]","Ruby [5]","Ruby [6]","Ruby [7]","Ruby [8]","Ruby [9]","Ruby [10]","Sapphire [1]","Sapphire [2]","Sapphire [3]","Sapphire [4]","Sapphire [5]","Sapphire [6]","Sapphire [7]","Sapphire [8]","Sapphire [9]","Sapphire [10]","Topaz [1]","Topaz [2]","Topaz [3]","Topaz [4]","Topaz [5]","Topaz [6]","Topaz [7]","Topaz [8]","Topaz [9]","Topaz [10]","Emerald [1]","Emerald [2]","Emerald [3]","Emerald [4]","Emerald [5]","Emerald [6]","Emerald [7]","Emerald [8]","Emerald [9]","Emerald [10]","Peridot [1]","Peridot [2]","Peridot [3]","Peridot [4]","Peridot [5]","Peridot [6]","Peridot [7]","Peridot [8]","Peridot [9]","Peridot [10]","Diamond [1]","Diamond [2]","Diamond [3]","Diamond [4]","Diamond [5]","Diamond [6]","Diamond [7]","Diamond [8]","Diamond [9]","Diamond [10]"};

void OnQuestTrigger(unsigned long Hash){
}

void SetCheckSum(unsigned char* newCheckSum){
	DWORD oldProtect = 0;
	unsigned char* checksum = (unsigned char*)0x0062F830;

	VirtualProtect(checksum, 256, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy(checksum, newCheckSum, 256);
	VirtualProtect(checksum, 256, oldProtect, &oldProtect);
}

void LoadAchievementList(){
	static bool loaded = false;
	if(loaded) return;
	loaded = true;

	gAchievementList.LoadXML("3DDATA\\CONTROL\\RES\\DATA2.RP");
}

BOOL WINAPI TrapCtrlHandler(DWORD dwCtrlType){
	switch(dwCtrlType){
		case CTRL_C_EVENT:
		case CTRL_CLOSE_EVENT:
		case CTRL_BREAK_EVENT:
			Log(MSG_WARNING,"Never use the console to shutdown!");
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
#ifdef DEBUG_MODE
			CreateConsole();
#endif
			SetConsoleCtrlHandler( TrapCtrlHandler, TRUE );
			LoadQuestIconScript("3DDATA\\CONTROL\\RES\\DATA1.RP");
			SetCheckSum(NewTitanCheckSum);

			RunList::Instance().RunFunctions();
			HookList::Instance().ApplyHooks();
			WriteList::Instance().ApplyWrites();

			Log(MSG_DEBUG, "TRUE");
			return TRUE;
		}
		case DLL_PROCESS_DETACH:
			return TRUE;
	};

	return TRUE;
}

void _stdcall DeleteNewData(CGameOBJ* object){
	if(object->GetTYPE() == 8 || object->GetTYPE() == 9){
		if((int)object->m_Special > 0x1000)
			SAFE_DELETE(object->m_Special);
	}
}

void __declspec(naked) ASMDelGameOBJ(){
	static int jRet = 0x0047A167;
	_asm {
		PUSHAD
		PUSH ESI
		CALL DeleteNewData
		POPAD

		MOV ECX, ESI
		CALL DWORD PTR DS:[EAX+0x1C]

		JMP jRet
	}
}

HookOnLoad(0x0047A162, ASMDelGameOBJ, 0);