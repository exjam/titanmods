#include "main.h"
#include <SHO_GS\GS_CThreadSQL.h>
#include <SHO_GS\classSQL.h>
#include <SHO_GS\CObjITEM.h>
#include <SHO_GS\GS_CThreadLOG.h>

extern STBVALUE** g_TblZONE;

//////////////////////////////////////////////////////////////
//						New Logs							//
//////////////////////////////////////////////////////////////
void LogDuel(int type, classUSER* winner, classUSER* loser, int bet){
	if(!winner || !loser) return;
	if(!g_pThreadLOG) return;
	char* zone = g_TblZONE[winner->m_nZoneNO][0].GetSTR();

	g_pThreadLOG->m_csSQL.Lock();
	String Query = String("INSERT INTO GS_DuelLog (Type, Winner, WinnerID, Loser, LoserID, Reward, Location) VALUES (%1, '%2', %3, '%4', %5, %6, '%7')") 
		.arg(type).arg(winner->Get_NAME()).arg(winner->m_dwDBID).arg(loser->Get_NAME()).arg(loser->m_dwDBID).arg(bet).arg(zone);

	g_pThreadLOG->Add_QueryString(Query);
	g_pThreadLOG->m_csSQL.Unlock();
}

enum {
	STAT_LOG_SERIALIZE = 0,
	STAT_LOG_GEMMING = 1,
	STAT_LOG_UNGEMMING = 2,
	STAT_LOG_UPGRADE = 3,
};

// Works
void _stdcall StatLog(tagITEM* item, int type){
	if(!item) return;
	if(!g_pThreadLOG) return;
	
	g_pThreadLOG->m_csSQL.Lock();
	String Query = String("INSERT INTO GS_SerialLog (dwSerial,iLogTYPE,iType,iID,iStat,iRefine,iSlot,iDura) VALUES (%1, %2, %3, %4, %5, %6, %7, %8)")
		.arg(item->m_iSN)
		.arg(type)
		.arg(item->GetTYPE())
		.arg(item->GetItemNO())
		.arg(item->GetOption())
		.arg(item->GetGrade())
		.arg(item->HasSocket())
		.arg(item->GetDurability());
	g_pThreadLOG->Add_QueryString(Query);
	g_pThreadLOG->m_csSQL.Unlock();
}

// Works
void _stdcall StatLogGem(tagITEM* item, tagITEM* gem, int type){
	if(!item) return;
	if(!g_pThreadLOG) return;

	int stat = 0;
	if(type == STAT_LOG_GEMMING)
		stat = gem->GetItemNO();

	g_pThreadLOG->m_csSQL.Lock();
	String Query = String("INSERT INTO GS_SerialLog (dwSerial,iLogTYPE,iType,iID,iStat,iRefine,iSlot,iDura) VALUES (%1, %2, %3, %4, %5, %6, %7, %8)")
		.arg(item->m_iSN)
		.arg(type)
		.arg(item->GetTYPE())
		.arg(item->GetItemNO())
		.arg(stat)
		.arg(item->GetGrade())
		.arg(item->HasSocket())
		.arg(item->GetDurability());
	g_pThreadLOG->Add_QueryString(Query);
	g_pThreadLOG->m_csSQL.Unlock();
}

// Works
static _declspec(naked) void ASMSerialLog(){
	static int jRETN = 0x1000AD9E;
	_asm {
		MOV ECX,DWORD PTR DS:[EAX+0x1E88]
		MOV DWORD PTR DS:[EDX+0xA],ECX
		MOV EDX,DWORD PTR SS:[EBP+0x8]
		PUSH STAT_LOG_SERIALIZE
		PUSH EDX
		CALL StatLog
		JMP jRETN
	}
}

HookOnLoad(0x1000AD95, ASMSerialLog, 4);

// Works
static _declspec(naked) void ASMGemmingLog(){
	static int jRETN = 0x10064F72;
	static int callSQL = 0x100AF190;
	_asm {
		CALL callSQL
		MOVZX EAX,BYTE PTR SS:[EBP+0x14]	// gemming
		TEST AL, AL
		JE Gemming
		MOV EAX, STAT_LOG_UNGEMMING
		JMP Done
Gemming:
		MOV EAX, STAT_LOG_GEMMING
		JMP Done
Done:
		PUSH EAX
		MOV EAX,DWORD PTR SS:[EBP+0x10]
		PUSH EAX
		MOV EAX,DWORD PTR SS:[EBP+0xC]
		PUSH EAX
		CALL StatLogGem
		JMP jRETN
	}
}

HookOnLoad(0x10064F6D, ASMGemmingLog, 0);

// Works
static _declspec(naked) void ASMUpgradeLog(){
	static int jRETN = 0x10064CF3;
	static int callSQL = 0x100AF190;
	_asm {
		CALL callSQL
		PUSH STAT_LOG_UPGRADE
		MOV EAX,DWORD PTR SS:[EBP+0x0C]
		PUSH EAX
		CALL StatLog
		JMP jRETN
	}
}

HookOnLoad(0x10064CEE, ASMUpgradeLog, 0);

//////////////////////////////////////////////////////////////
//						Log Fixes							//
//////////////////////////////////////////////////////////////
// Pickup log didn't generate a serial if serial=0
static _declspec(naked) void ASMPickupSerialLog(){
	static int jRETN = 0x100854A9;
	static int callSERIAL = 0x1000AD00;
	_asm {
		MOV ESI,DWORD PTR SS:[ESP]
		CALL callSERIAL
		MOV EAX,DWORD PTR DS:[ESI+0x6]
		MOV ECX,DWORD PTR DS:[ESI+0xA]
		MOV EDX,DWORD PTR SS:[EBP+0x8]
		MOV DWORD PTR DS:[EDX+0x42], EAX
		MOV DWORD PTR DS:[EDX+0x46], ECX
		JMP jRETN
	};
}

HookOnLoad(0x100854A4, ASMPickupSerialLog, 0);

//////////////////////////////////////////////////////////////
//						Extra Logs							//
//////////////////////////////////////////////////////////////

// Works
void _stdcall BankLog(classUSER* user, __int64 value, int type){
	if(!g_pThreadLOG) return;
	g_pThreadLOG->When_TagItemLOG(type, user, 0, 0, value, 0, true);
}

// Works
static _declspec(naked) void ASMDepositMoney(){
	static int jRETN = 0x1007E43C;
	_asm {
		PUSH ITEMLOG_BANK_MONEY_DEPOSIT

		MOV ECX,DWORD PTR SS:[EBP+0x8]
		MOV EDX,DWORD PTR DS:[ECX+0x7]
		MOV EAX,DWORD PTR DS:[ECX+0xB]
		PUSH EAX
		PUSH EDX

		MOV EAX,DWORD PTR SS:[EBP-0x4]
		PUSH EAX
		CALL BankLog

		MOV EAX,DWORD PTR SS:[EBP-0x4]
		MOV ECX,DWORD PTR SS:[EBP+0x8]
		JMP jRETN
	}
}

HookOnLoad(0x1007E436, ASMDepositMoney, 1);

// Works
static _declspec(naked) void ASMTakeMoney(){
	static int jRETN = 0x1007E4C4;
	_asm {
		PUSH ITEMLOG_BANK_MONEY_TAKE

		MOV ECX,DWORD PTR SS:[EBP+0x8]
		MOV EDX,DWORD PTR DS:[ECX+0x7]
		MOV EAX,DWORD PTR DS:[ECX+0xB]
		PUSH EAX
		PUSH EDX

		MOV EAX,DWORD PTR SS:[EBP-0x4]
		PUSH EAX
		CALL BankLog

		MOV EAX,DWORD PTR SS:[EBP-0x4]
		MOV ECX,DWORD PTR SS:[EBP+0x8]
		JMP jRETN
	}
}

HookOnLoad(0x1007E4BE, ASMTakeMoney, 1);
