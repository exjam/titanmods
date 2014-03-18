#include "main.h"
#include "pvp.h"

#include <SHO_GS\classUSER.h>
#include <SHO_GS\classPACKET.h>
#include <SHO_GS\CPacket.h>
#include <SHO_GS\CObjNPC.h>
#include <SHO_GS\CObjCHAR.h>
#include <SHO_GS\CZoneTHREAD.h>
#include <SHO_GS\CZoneLIST.h>

Array<NpcCmd*> gNpcVars;
Array<PvPQuest*> gPvPQuests;

void InitVarList() {
	Log(MSG_INFO, "Init Vars");

	// Npc var stuff
	gNpcVars.PushBack(new NpcCmd(DRAGON_HUNT, 0, false, 2025));
	gNpcVars.PushBack(new NpcCmd(DRAGON_HUNT, 1, false, 2033));
	gNpcVars.PushBack(new NpcCmd(DRAGON_HUNT, 2, false, 2015));

	gNpcVars.PushBack(new NpcCmd(CONQUEST, 0, false, 2043));
	gNpcVars.PushBack(new NpcCmd(CONQUEST, 0, true, 2044, 74));

	gNpcVars.PushBack(new NpcCmd(CTF, 0, false,	2080));
	gNpcVars.PushBack(new NpcCmd(CTF, 1, false,	2081));
	gNpcVars.PushBack(new NpcCmd(CTF, 2, false,	2082));
	gNpcVars.PushBack(new NpcCmd(CTF, 3, false,	2083));

	gNpcVars.PushBack(new NpcCmd(KOTH, 0, false, 2085));
	gNpcVars.PushBack(new NpcCmd(KOTH, 0, true,  2086, 80));
	gNpcVars.PushBack(new NpcCmd(KOTH, 1, false, 2095));
	gNpcVars.PushBack(new NpcCmd(KOTH, 1, true,  2096, 81));
	gNpcVars.PushBack(new NpcCmd(KOTH, 2, false, 2105));
	gNpcVars.PushBack(new NpcCmd(KOTH, 2, true,  2106, 82));
	gNpcVars.PushBack(new NpcCmd(KOTH, 3, false, 2115));
	gNpcVars.PushBack(new NpcCmd(KOTH, 3, true,  2116, 83));

	// Quest stuff
	gPvPQuests.PushBack(new PvPQuest(500, 501, 40, "DH", 1, 2025));
	gPvPQuests.PushBack(new PvPQuest(502, 503, 41, "DH", 2, 2033));
	gPvPQuests.PushBack(new PvPQuest(504, 505, 42, "DH", 3, 2015));

	gPvPQuests.PushBack(new PvPQuest(510, 511, 45, "CQ", 1, 2043));

	gPvPQuests.PushBack(new PvPQuest(520, 521, 50, "CTF", 1, 2080));
	gPvPQuests.PushBack(new PvPQuest(522, 523, 52, "CTF", 2, 2081));
	gPvPQuests.PushBack(new PvPQuest(524, 525, 53, "CTF", 3, 2082));
	gPvPQuests.PushBack(new PvPQuest(526, 527, 55, "CTF", 4, 2083));

	gPvPQuests.PushBack(new PvPQuest(530, 531, 47, "KH", 1, 2085));
	gPvPQuests.PushBack(new PvPQuest(532, 533, 48, "KH", 2, 2095));
	gPvPQuests.PushBack(new PvPQuest(534, 535, 49, "KH", 3, 2105));
	gPvPQuests.PushBack(new PvPQuest(536, 537, 54, "KH", 4, 2115));
}

AllVARS::AllVARS(unsigned int game, unsigned int instance, bool score, int npcid)
	: mGame(game), mInstance(instance), mScore(score ? 1 : 0)
{
	CObjNPC* npc = g_pZoneLIST->Get_LocalNPC(npcid);
	for(int i = 0; i < 10; ++i)
		mValues[i] = npc ? npc->Get_ObjVAR(i) : 0;
}

void __stdcall Send_PvP_Vars_Login(classUSER* user){
	if(!g_pZoneLIST) return;

	classPACKET* cpak = Packet_AllocNLock();
	if(!cpak) return;

	CPacket* pak = (CPacket*)cpak;
	pak->CreateNew(PAK_NPCVARALL);
	pak->Add<int>(gNpcVars.Size());

	for(unsigned int i = 0; i < gNpcVars.Size(); ++i){
		NpcCmd* pCmd = gNpcVars[i];
		pak->Add<AllVARS>(AllVARS(pCmd->mGame, pCmd->mInstance, pCmd->mScore, pCmd->mNpc));
	}

	user->SendPacket(cpak);
	Packet_ReleaseNUnlock(cpak);
}

void _stdcall SendVars(CObjNPC* npc, short value, short var){
	if(!g_pZoneLIST) return;
	if(!gInitDone) return;

	classPACKET* cpak = Packet_AllocNLock();
	if(!cpak) return;

	int npcid = npc->m_nCharIdx;
	for(unsigned int i = 0; i < gNpcVars.Size(); ++i){
		NpcCmd* pCmd = gNpcVars[i];
		if(pCmd->mNpc != npcid) continue;

		if(var == 0 && (value == 0 || value == 1))
			ClearPvpIpList(npcid);

		CPacket* pak = (CPacket*)cpak;
		pak->CreateNew(PAK_NPCVAR);
		pak->Add<OneVAR>(OneVAR(pCmd->mGame, pCmd->mInstance, pCmd->mScore, var, value));

		if(pCmd->mScore == true && value != 0){
			CZoneTHREAD* zone = g_pZoneLIST->GetZONE(pCmd->mZone);
			if(zone)
				zone->SendPacketToZONE((t_PACKET*)cpak);
		}else{
			for(int i = 1; i <= g_pZoneLIST->GetZoneCNT(); ++i){
				CZoneTHREAD* zone = g_pZoneLIST->GetZONE(i);
				if(!zone) continue;
				zone->SendPacketToZONE((t_PACKET*)cpak);
			}
		}
	}

	Packet_ReleaseNUnlock(cpak);
}

/*		Only update NPC vars to the players when the value has changed.		*/
static _declspec(naked) void ASMSetVarOverwrite(){
	static int jRETN = 0x100160BD;
	static int cCallGet = 0x1000CF70;
	static int cCallSet = 0x10015E00;
	static int cNpcEventSend = 0x10057630;
	_asm {
		MOVZX EAX,BYTE PTR SS:[EBP+0x8]

		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x4]                         
		CALL cCallGet                  

		MOVZX EAX, AX
		MOVZX ECX, WORD PTR SS:[EBP+0xC]
		CMP EAX,ECX
		JE jExit			// Exit, value didn't change.

		MOVZX EAX,BYTE PTR SS:[EBP+0x8]
		PUSH ECX                                             
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x4]                         
		CALL cCallSet                

		MOVZX EAX,BYTE PTR SS:[EBP+0x8]
		TEST EAX, EAX
		JNZ jSendToPlayers

		// Idx == 0
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		CALL cNpcEventSend
		JMP jSendToPlayers

jSendToPlayers:
		// Idx != 0
		MOVZX EAX,BYTE PTR SS:[EBP+0x8]
		PUSH EAX
		MOVZX EAX,WORD PTR SS:[EBP+0xC] // val
		PUSH EAX
		MOV EAX,DWORD PTR SS:[EBP-0x4]	// npc
		ADD EAX, 0x34
		PUSH EAX
		CALL SendVars
		JMP jRETN
jExit:
		JMP jRETN
	};
}

HookOnLoad(0x10016068, ASMSetVarOverwrite, 20);