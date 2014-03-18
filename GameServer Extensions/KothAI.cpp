#include "main.h"
#include "pvp.h"
#include "AI.h"

void KothAI::DoAI(){
	if(!g_pServer) return;
	if(!g_pZoneLIST) return;
	
	CObjNPC* npc = g_pZoneLIST->Get_LocalNPC(mNPC);
	CZoneTHREAD* zone = g_pZoneLIST->GetZONE(mZone);
	if(!npc || !zone) return;

	SYSTEMTIME timeInfo;
    GetLocalTime(&timeInfo);
	
	// Cleanup vars
	if(timeInfo.wMinute >= mTimeCleanup && timeInfo.wMinute <= mTimeCleanup + 1){
		npc->Set_ObjVAR(VAR_STATUS, GAME_STATUS_CLOSED);
		npc->Set_ObjVAR(VAR_SCORE_RED, 5);
		mDoShout = 0;
    }

	// OPEN SIGNUPS
	if(timeInfo.wMinute >= mTimeOpen && timeInfo.wMinute <= mTimeOpen + 1 && npc->Get_ObjVAR(VAR_STATUS) == GAME_STATUS_CLOSED){
		npc->Set_ObjVAR(VAR_STATUS, GAME_STATUS_SIGNUP);
		npc->Set_ObjVAR(VAR_SCORE_RED, 1);
		mDoShout = 0;
    }

	// CANCEL, vars will clean up at :42
	if(timeInfo.wMinute >= mTimeCancel && timeInfo.wMinute <= mTimeCancel + 1 && npc->Get_ObjVAR(VAR_STATUS) == GAME_STATUS_SIGNUP){
		npc->Set_ObjVAR(VAR_STATUS, GAME_STATUS_CANCEL);
		npc->Set_ObjVAR(VAR_PLAYERS_RED, 0);
		npc->Set_ObjVAR(VAR_PLAYERS_BLUE, 0);
    }

	// Game is over, time ran out
	if(timeInfo.wMinute >= mTimeOver && timeInfo.wMinute <= mTimeOver + 1 && npc->Get_ObjVAR(VAR_STATUS) == GAME_STATUS_PROGRESS){
		if(!mDoShout){
			g_pServer->Send_ANNOUNCE(mZone, "Time's up! Nobody won the match..");
			zone->Do_QuestTrigger(10, StrToHashKey(String("%1-TOR").arg(mQuest)));
			zone->Do_QuestTrigger(11, StrToHashKey(String("%1-TOB").arg(mQuest)));
			npc->Set_ObjVAR(VAR_STATUS, GAME_STATUS_CLOSED);
			zone->Set_PK_FLAG(0);
		}

		mDoShout++;
    }
}
