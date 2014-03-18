#include "main.h"
#include "pvp.h"
#include "AI.h"

#include <SHO_GS\classUSER.h>
#include <SHO_GS\classPACKET.h>
#include <SHO_GS\CPacket.h>
#include <SHO_GS\CObjNPC.h>
#include <SHO_GS\CObjEVENT.h>
#include <SHO_GS\CObjCHAR.h>
#include <SHO_GS\CZoneTHREAD.h>
#include <SHO_GS\CZoneLIST.h>

#include <SHO_GS\CLIB_GameSRV.h>

bool gInitDone = false;

CtfAI* gCtfAI[] = { NULL, NULL, NULL, NULL };
KothAI* gKothAI[] = { NULL, NULL, NULL, NULL };

void RunAIP(short ZoneNO){
	if(!gInitDone) return;

	gCtfAI[0]->Execute(ZoneNO);
	gCtfAI[1]->Execute(ZoneNO);
	gCtfAI[2]->Execute(ZoneNO);
	gCtfAI[3]->Execute(ZoneNO);

	gKothAI[0]->Execute(ZoneNO);
	gKothAI[1]->Execute(ZoneNO);
	gKothAI[2]->Execute(ZoneNO);
	gKothAI[3]->Execute(ZoneNO);
}

void CleanAllPvpNpcs() {
	Log(MSG_INFO, "Init CustomAI");

	gCtfAI[0] = new CtfAI(1, 77, 2080, 520, 521, 52,  0, 30, 32);
	gCtfAI[1] = new CtfAI(2, 78, 2081, 522, 523, 12, 20, 50, 52);
	gCtfAI[2] = new CtfAI(3, 79, 2082, 524, 525, 32, 40, 10, 12);
	gCtfAI[3] = new CtfAI(4, 84, 2083, 526, 527, 32, 40, 10, 12);

	gKothAI[0] = new KothAI(80, 2085, 2086, 42,  2, 10, 40);
	gKothAI[1] = new KothAI(81, 2095, 2096,  2, 22, 30,  0);
	gKothAI[2] = new KothAI(82, 2105, 2106, 22, 42, 50, 20);
	gKothAI[3] = new KothAI(83, 2115, 2116, 42,  2, 20, 40);

	for(unsigned int i = 0; i < gNpcVars.Size(); ++i){
		NpcCmd* pCmd = gNpcVars[i];
		if(!g_pZoneLIST) continue;

		CObjNPC* npc = g_pZoneLIST->Get_LocalNPC(pCmd->mNpc);
		if(!npc) continue;

		for(unsigned int a = 0; a <= 10; ++a)
			npc->Set_ObjVAR(a, 0);
	}
	
	if(CObjNPC* npc = g_pZoneLIST->Get_LocalNPC(2016))
		for(unsigned int a = 0; a <= 10; ++a)
			npc->Set_ObjVAR(a, 0);

	if(CObjNPC* npc = g_pZoneLIST->Get_LocalNPC(2026))
		for(unsigned int a = 0; a <= 10; ++a)
			npc->Set_ObjVAR(a, 0);

	if(CObjNPC* npc = g_pZoneLIST->Get_LocalNPC(2034))
		for(unsigned int a = 0; a <= 10; ++a)
			npc->Set_ObjVAR(a, 0);

	gInitDone = true;
}
