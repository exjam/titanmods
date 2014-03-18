#include "main.h"
#include "pvp.h"
#include "AI.h"

void CtfAI::DoAI() {
	if(!g_pServer) return;
	if(!g_pZoneLIST) return;

	CObjNPC* npc = g_pZoneLIST->Get_LocalNPC(mNPC);
	CZoneTHREAD* zone = g_pZoneLIST->GetZONE(mZone);

	CObjEVENT* red = g_pZoneLIST->Get_EventOBJ(mZone, StrToHashKey(String("%1@34x33_1").arg(mZone)));
	CObjEVENT* blue = g_pZoneLIST->Get_EventOBJ(mZone, StrToHashKey(String("%1@32x31_2").arg(mZone)));

	if(!npc || !zone || !red || !blue) return;

	SYSTEMTIME timeInfo;
    GetLocalTime(&timeInfo);
	
	// Cleanup vars
	if(timeInfo.wMinute >= mTimeCleanup && timeInfo.wMinute <= mTimeCleanup + 1){
		npc->Set_ObjVAR(VAR_STATUS, GAME_STATUS_CLOSED);
		npc->Set_ObjVAR(VAR_SCORE_RED, 0);
		npc->Set_ObjVAR(VAR_SCORE_BLUE, 0);
		npc->Set_ObjVAR(VAR_3, 0);
		npc->Set_ObjVAR(VAR_4, 0);
		npc->Set_ObjVAR(VAR_PLAYERS_RED, 0);
		npc->Set_ObjVAR(VAR_PLAYERS_BLUE, 0);
		npc->Set_ObjVAR(VAR_WINNER, 0);

		red->Set_ObjVAR(VAR_STATUS, FLAG_HIDE);
		blue->Set_ObjVAR(VAR_STATUS, FLAG_HIDE);

		mDoShout = 0;
    }

	// OPEN SIGNUPS
	if(timeInfo.wMinute >= mTimeOpen && timeInfo.wMinute <= mTimeOpen + 1 && npc->Get_ObjVAR(VAR_STATUS) == GAME_STATUS_CLOSED){
		npc->Set_ObjVAR(VAR_STATUS, GAME_STATUS_SIGNUP);
		npc->Set_ObjVAR(VAR_SCORE_RED, 0);
		npc->Set_ObjVAR(VAR_SCORE_BLUE, 0);
		npc->Set_ObjVAR(VAR_3, 0);
		npc->Set_ObjVAR(VAR_4, 0);
		npc->Set_ObjVAR(VAR_PLAYERS_RED, 0);
		npc->Set_ObjVAR(VAR_PLAYERS_BLUE, 0);
		npc->Set_ObjVAR(VAR_WINNER, 0);

		mDoShout = 0;
    }

	// Check if the flag carriers are still ingame
	// When there's a winner -> dont check
	if(npc->Get_ObjVAR(VAR_STATUS) == GAME_STATUS_PROGRESS && npc->Get_ObjVAR(VAR_WINNER) == 0){
		bool redFound = false;
		bool blueFound = false;
		bool redHidden = false;
		bool blueHidden = false;

		if(red->Get_ObjVAR(VAR_STATUS) == FLAG_HIDE) redHidden = true;
		if(blue->Get_ObjVAR(VAR_STATUS) == FLAG_HIDE) blueHidden = true;
		
		if(redHidden || blueHidden){
			for(auto itr = zone->m_ObjLIST.m_pHEAD; itr; itr = itr->m_pNEXT){
				CGameOBJ* obj = itr->DATA;
				if(!obj) continue;
				if(!obj->IsUSER()) continue;

				classUSER* user = (classUSER*)obj;
				if(user->Get_HP() <= 0) continue;
				if(!user->m_Quests.Get_SWITCH(51)) continue;
				
				unsigned char qRed = user->Quest_GetRegistered(mQuestRed);
				unsigned char qBlue = user->Quest_GetRegistered(mQuestBlue);
				if(qRed < 10 && user->m_Quests.m_QUEST[qRed].GetRemainTIME() > 0)
					blueFound = true;

				if(qBlue < 10 && user->m_Quests.m_QUEST[qBlue].GetRemainTIME() > 0)
					redFound = true;
			}
		}

		if(blueHidden && !blueFound)
			blue->Set_ObjVAR(VAR_STATUS, FLAG_SHOW);

		if(redHidden && !redFound)
			red->Set_ObjVAR(VAR_STATUS, FLAG_SHOW);
	}

	// FULL -> Open warps, Spawn FLAGS, Set PK and Clear Vars (Already done so at signups, just to be sure (server maintenances))
	if(npc->Get_ObjVAR(VAR_STATUS) == GAME_STATUS_FULL){
		red->Set_ObjVAR(VAR_STATUS, FLAG_SHOW);
		blue->Set_ObjVAR(VAR_STATUS, FLAG_SHOW);

		npc->Set_ObjVAR(VAR_SCORE_RED, 0);
		npc->Set_ObjVAR(VAR_SCORE_BLUE, 0);
		npc->Set_ObjVAR(VAR_WINNER, 0);

		zone->Set_PK_FLAG(1);

		npc->Set_ObjVAR(VAR_STATUS, GAME_STATUS_PROGRESS);

		mDoShout = 0;
	}

	// WINNAR -> turn off PK, hide flags, execute reward and teleports // vars will clean up at :32
	if(npc->Get_ObjVAR(VAR_WINNER) == TEAM_RED){
		if(!mDoShout){
			g_pServer->Send_ANNOUNCE(mZone, "Red team has won the match, you will be rewarded and warped out.");

			zone->Do_QuestTrigger(10, StrToHashKey(String("CTF-%1-RedWin").arg(mID)));
			zone->Do_QuestTrigger(11, StrToHashKey(String("CTF-%1-BlueLose").arg(mID)));

			zone->Set_PK_FLAG(0);

			red->Set_ObjVAR(VAR_STATUS, FLAG_HIDE);
			blue->Set_ObjVAR(VAR_STATUS, FLAG_HIDE);
		}

		mDoShout++;
	}

	if(npc->Get_ObjVAR(VAR_WINNER) == TEAM_BLUE){
		if(!mDoShout){
			g_pServer->Send_ANNOUNCE(mZone, "Blue team has won the match, you will be rewarded and warped out.");

			zone->Do_QuestTrigger(10, StrToHashKey(String("CTF-%1-RedLose").arg(mID)));
			zone->Do_QuestTrigger(11, StrToHashKey(String("CTF-%1-BlueWin").arg(mID)));

			zone->Set_PK_FLAG(0);

			red->Set_ObjVAR(VAR_STATUS, FLAG_HIDE);
			blue->Set_ObjVAR(VAR_STATUS, FLAG_HIDE);
		}

		mDoShout++;
	}

	// CANCEL, vars will clean up at :32
	if(timeInfo.wMinute >= mTimeCancel && timeInfo.wMinute <= mTimeCancel + 1 && npc->Get_ObjVAR(VAR_STATUS) == GAME_STATUS_SIGNUP){
		npc->Set_ObjVAR(VAR_STATUS, GAME_STATUS_CANCEL);
		npc->Set_ObjVAR(VAR_PLAYERS_RED, 0);
		npc->Set_ObjVAR(VAR_PLAYERS_BLUE, 0);
    }

	// Game is over, time ran out
	if(timeInfo.wMinute >= mTimeOver && timeInfo.wMinute <= mTimeOver + 1 && npc->Get_ObjVAR(VAR_STATUS) == GAME_STATUS_PROGRESS){
		if(!mDoShout){
			g_pServer->Send_ANNOUNCE(mZone, "Time's up! Nobody won the match..");

			zone->Do_QuestTrigger(10, StrToHashKey(String("CTF-%1-ZoneJoin3").arg(mID)));
			zone->Do_QuestTrigger(11, StrToHashKey(String("CTF-%1-ZoneJoin4").arg(mID)));

			npc->Set_ObjVAR(VAR_STATUS, GAME_STATUS_CLOSED);

			zone->Set_PK_FLAG(0);

			red->Set_ObjVAR(VAR_STATUS, FLAG_HIDE);
			blue->Set_ObjVAR(VAR_STATUS, FLAG_HIDE);
		}

		mDoShout++;
    }
}
