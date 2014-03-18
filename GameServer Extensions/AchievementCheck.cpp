#include "main.h"
#include "SendMessage.h"
#include <SHO_GS\classPACKET.h>
#include <SHO_GS\CPacket.h>
#include <SHO_GS\CObjMOB.h>
#include <SHO_GS\CZoneTHREAD.h>

AchievementList gAchievementList;

template<class T> bool CheckOperator(Achievement::Condition::Op op, T value1, T value2){
	switch(op){
		case Achievement::Condition::OP_EQ:
			return (value1 == value2);
		case Achievement::Condition::OP_NE:
			return (value1 != value2);
		case Achievement::Condition::OP_GT:
			return (value1 > value2);
		case Achievement::Condition::OP_GE:
			return (value1 >= value2);
		case Achievement::Condition::OP_LT:
			return (value1 < value2);
		case Achievement::Condition::OP_LE:
			return (value1 <= value2);
	}

	return false;
}

void UnlockAchievement(classUSER* user, Achievement* ach){
	CustomAvatarData* data = CustomAvatarData::Get(user);
	data->mAchievements.SetAchievement(ach->mID, true);

	if(classPACKET* cpak = Packet_AllocNLock()){
		CPacket* pak = (CPacket*)cpak;
		pak->CreateNew(PAK_ACHIEVEMENT);
		pak->Add<char>(ACHIEVEMENT_UNLOCKED);
		pak->Add<unsigned short>(user->Get_INDEX());
		pak->Add<int>(ach->mID);
		if(CZoneTHREAD* pZONE = user->GetZONE())
			pZONE->SendPacketToSectors(user, cpak);

		Packet_ReleaseNUnlock(cpak);
	}

	SendMSG(user, CHAT_TYPE_ALL, String("%1 has unlocked '%2' achievement.").arg(user->Get_NAME()).arg(ach->mName ), true, 0xFFFEBD13 );
}

void AchievementOnTrigger(classUSER* user, unsigned int hash, int result){
	CustomAvatarData* data = CustomAvatarData::Get(user);
	for(unsigned int i = 0; i < gAchievementList.mAll.Size(); ++i){
		Achievement* ach = gAchievementList.mAll[i];
		if(data->mAchievements.HasAchievement(ach->mID)) continue;

		for(unsigned int j = 0; j < ach->mConditions.Size(); ++j){
			Achievement::Condition* cond = ach->mConditions[j];
			if(cond->mType != Achievement::Condition::AC_TRIGGER) continue;
			if(cond->mValID != hash) continue;

			UnlockAchievement(user, ach);
			break;
		}
	}
}

void AchievementOnKill(CGameOBJ* pVICTIM, CGameOBJ* pKILLER){
	if(pKILLER->Get_TYPE() != OBJ_AVATAR) return;

	classUSER* pUSER = static_cast<classUSER*>(pKILLER);
	CustomAvatarData* data = CustomAvatarData::Get(pUSER);
	int mobID = 0;

	if(pVICTIM->Get_TYPE() == OBJ_MOB){
		CObjMOB* mob = static_cast<CObjMOB*>(pVICTIM);
		mobID = mob->Get_CharNO();
	}

	for(unsigned int i = 0; i < gAchievementList.mMonster.Size(); ++i){
		Achievement* ach = gAchievementList.mMonster[i];
		if(data->mAchievements.HasAchievement(ach->mID)) continue;

		for(unsigned int j = 0; j < ach->mConditions.Size(); ++j){
			Achievement::Condition* cond = ach->mConditions[j];
			if(cond->mType != Achievement::Condition::AC_KILL) continue;
			if(pVICTIM->Get_TYPE() == OBJ_MOB){
				if(cond->mValID != mobID)
					continue;
			}else if(pVICTIM->Get_TYPE() == OBJ_AVATAR){
				if(cond->mValID != 9999)  continue;
				char* name = pVICTIM->Get_NAME();
				if(strncmp(name, "[GM]", 4) != 0 && strncmp(name, "[DEV]", 5) != 0)
					continue;
			}else
				continue;

			UnlockAchievement(pUSER, ach);
			break;
		}
	}

	for(unsigned int i = 0; i < gAchievementList.mPvp.Size(); ++i){
		Achievement* ach = gAchievementList.mPvp[i];
		if(data->mAchievements.HasAchievement(ach->mID)) continue;

		for(unsigned int j = 0; j < ach->mConditions.Size(); ++j){
			Achievement::Condition* cond = ach->mConditions[j];
			if(cond->mType != Achievement::Condition::AC_KILL) continue;
			if(pVICTIM->Get_TYPE() != OBJ_AVATAR) continue;

			if(cond->mValID == 9997){
				//9997= kill a player ranked 10 or above
				classUSER* pPlayer = static_cast<classUSER*>(pVICTIM);
				CustomAvatarData* vicData = CustomAvatarData::Get(pPlayer);
				if(vicData->mData.mPvPRank < 10) continue;
			}else if(cond->mValID == 9998){
				//9998= kill all 2nd job classes
				classUSER* pPlayer = static_cast<classUSER*>(pVICTIM);
				int job = pPlayer->Get_JOB();
					 if(job == 121) data->mKilledClasses[0] = 1;
				else if(job == 122) data->mKilledClasses[1] = 1;
				else if(job == 221) data->mKilledClasses[2] = 1;
				else if(job == 222) data->mKilledClasses[3] = 1;
				else if(job == 321) data->mKilledClasses[4] = 1;
				else if(job == 322) data->mKilledClasses[5] = 1;
				else if(job == 421) data->mKilledClasses[6] = 1;
				else if(job == 422) data->mKilledClasses[7] = 1;

				bool fail = false;
				for(int i = 0; i < 8; ++i)
					if(data->mKilledClasses[i] != 1)
						fail = true;

				if(fail) continue;
			}else
				continue;

			UnlockAchievement(pUSER, ach);
			break;
		}
	}
}

#define ACHV_CHECK_PER_FRAME_COUNT 3

void AchievementCheck(classUSER* user, CustomAvatarData* data){
	unsigned int maxCheckIdx = data->mChkAchvIdx + ACHV_CHECK_PER_FRAME_COUNT;
	if(maxCheckIdx > gAchievementList.mAll.Size()) maxCheckIdx = gAchievementList.mAll.Size();

	for(unsigned int i = data->mChkAchvIdx; i < maxCheckIdx; ++i){
		Achievement* ach = gAchievementList.mAll[i];
		if(data->mAchievements.HasAchievement(ach->mID)) continue;
		int validCount = 0;
		for(unsigned int j = 0; j < ach->mConditions.Size(); ++j){
			Achievement::Condition* cond = ach->mConditions[j];
			switch(cond->mType){
				case Achievement::Condition::AC_ITEM:
				{
					int type = cond->mValID / 1000;
					int id = cond->mValID % 1000;
					int count = 0;

					for(unsigned int i = 0; i < 139; ++i){
						//tagITEM* item = &user->m_Inventory.m_ItemLIST[i];
						tagITEM* item = (tagITEM*)(((char*)user) + 0x8D9 + i*14);
						if(item->GetTYPE() != type) continue;
						if(item->GetItemNO() != id) continue;
						count += item->GetQuantity();
						if((type >= 10 && type <= 12) && (count < cond->mValCount)) continue;
						++validCount;
						break;
					}

					break;
				}
			
				case Achievement::Condition::AC_FLAG:
				{
					if(user->m_Quests.Get_SWITCH(cond->mValID)) ++validCount;
					break;
				}

				case Achievement::Condition::AC_STAT:
				{
					int value = user->Get_AbilityValue(cond->mValID);
					validCount += CheckOperator<int>(cond->mOp, value, cond->mValCount)?1:0;
					break;
				}

				case Achievement::Condition::AC_SKILL:
				{
					for(unsigned int i = 0; i < 0x78; ++i){
						if(user->m_Skills.m_nSkillINDEX[i] != cond->mValID) continue;
						++validCount;
						break;
					}
					break;
				}

				case Achievement::Condition::AC_GRADE:
				{
					if(!user->GetClanID()) continue;
					int level = user->GetClanLEVEL();
					validCount += CheckOperator<int>(cond->mOp, level, cond->mValCount)?1:0;
					break;
				}

				case Achievement::Condition::AC_RANK:
				{
					if(!user->GetClanID()) continue;
					int pos = user->GetClanPOS();
					validCount += CheckOperator<int>(cond->mOp, pos, cond->mValCount)?1:0;
					break;
				}

				case Achievement::Condition::AC_FUNDS:
				{
					if(!user->GetClanID()) continue;
					__int64 pos = user->GetClanMONEY();
					validCount += CheckOperator<__int64>(cond->mOp, pos, cond->mValCount)?1:0;
					break;
				}
			}
		}

		if(validCount < ach->mRequire) continue;
		UnlockAchievement(user, ach);
	}

	data->mChkAchvIdx = maxCheckIdx;
	if(data->mChkAchvIdx >= gAchievementList.mAll.Size()) data->mChkAchvIdx = 0;
}
