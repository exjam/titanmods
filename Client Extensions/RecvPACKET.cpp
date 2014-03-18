#include "main.h"
#include "Achievements.h"
#include "PvP.h"
#include "PartyList.h"
#include "Network.h"
#include "CTReplyDuel.h"
#include <TRose\CallCharLuaFunc.hpp>
#include <TRose\CObjMGR.h>
#include <TRose\StringManager.h>
#include <TRose\UIMediator.h>
#include <TRose\CMAP.h>
#include <TRose\IT_MGR.h>
#include <TRose\CTERRAIN.h>
#include <TRose\CObjCHAR.h>

enum{
	MSGTYPE_NONE,
	MSGTYPE_RECV_TRADE_REQ,
	MSGTYPE_RECV_PARTY_REQ,
	MSGTYPE_RECV_CLANJOIN_REQ,
	MSGTYPE_RECV_CART_RIDE_REQ,
	MSGTYPE_RECV_DUEL_REQ,
};

enum {
	DUEL_REQ,
	DUEL_REPLY,
	DUEL_END,

	DUEL_DENY = 0,
	DUEL_ACCEPT = 1,
	DUEL_BUSY = 2,
};

char* gDuelModes[] = { 
	"Best of 1",
	"Best of 3",
	"Best of 5",
};

extern Achievement* gNewAchievement;
extern volatile int gDrawAchievementPopup;
extern bool gInDuel;
int gRangeObjectID = 0;
short gFlagRedStatus = 0;
short gFlagBlueStatus = 0;

void Recv_srv_ACHIEVEMENT(){
	char flag = gRecvPacket->Get<char>(0);
	if(flag == ACHIEVEMENT_LOAD){
		LoadAchievementList();
		gAchievementData = gRecvPacket->Get<AchievementData>(1);
		gAchieveDialog->mWonCount = 0;

		for(int i = 0; i < 32 * 8; ++i)
			gAchieveDialog->mWonCount += gAchievementData.HasAchievement(i) ? 1 : 0;
	}else if(flag == ACHIEVEMENT_UNLOCKED){
		unsigned short objectID = CObjMGR::Instance()->Get_ClientObjectIndex(gRecvPacket->Get<unsigned short>(1));
		Call_Char_Lua_Func(objectID, "SE_Achievement");
		if (objectID != CObjMGR::GetSelf()->m_nIndex) return;

		Achievement* achievement = gAchievementList.GetByID(gRecvPacket->Get<int>(3));
		if(!achievement) return;
		
		IT_MGR::Instance()->AppendChatMsg(String("You have unlocked '%1' achievement.").arg(achievement->mName), CHAT_TYPE_QUESTREWARD);

		gAchievementData.SetAchievement(achievement->mID, true);
		gAchieveDialog->mWonCount += 1;
		gNewAchievement = achievement;
		gDrawAchievementPopup = 2;
	}
}

void Recv_srv_RIDE(bool joinZone){
	if(joinZone){	
		if(gRecvPacket->Get<byte>(22) != 2) return;

		int previousType = -1;	
		int type = 1337;

		for(int i = 0; i < 4; ++i){
			tagPartITEM part = gRecvPacket->Get<tagPartITEM>(90 + (i * 4));
			if(part.m_nItemNo == 0)	continue;

			type = GetSTBValue(14, part.m_nItemNo, 16);

			if(previousType != -1 && type != previousType){
				gRecvPacket->Set<byte>(22, 1);
				return;
			}

			previousType = type;
		}
	}else{				
		if(gRecvPacket->Get<byte>(2) != 4) return;

		CObjCHAR* other = CObjMGR::Instance()->Get_ClientCharOBJ(gRecvPacket->Get<short>(0), false);

		if(!other){
			gRecvPacket->Reset();
			return;
		}

		tagPartITEM* cartparts = other->GetCartParts();

		if(!cartparts){
			gRecvPacket->Reset();
			return;
		}

		int previousType = -1;	
		int type = 1337;

		for(int i = 0; i < 4; ++i){
			if(cartparts[i].m_nItemNo == 0)	continue;
			type = GetSTBValue(14, cartparts[i].m_nItemNo, 16);

			if(previousType != -1 && type != previousType){
				gRecvPacket->Reset();
				return;
			}

			previousType = type;
		}
	}
}

void Recv_srv_PVP(bool fromLogin){
	if(fromLogin){
		int instanceCount = gRecvPacket->Get<int>(0);
		int packetIndex = 4;

		for(int i = 0; i < instanceCount; ++i, packetIndex += sizeof(AllVARS)){
			AllVARS variables = gRecvPacket->Get<AllVARS>(packetIndex);

			PvPGame* game = gGameList->at(variables.mGame);
			if(!game) continue;

			PvPInstance* instance = game->mInstanceList->at(variables.mInstance);
			if(!instance) continue;

			if(game->mType == CTF){
				instance->mScoreRed = variables.mValues[1];
				instance->mScoreBlue = variables.mValues[2];
			}

			if(!variables.mScore){
				instance->mStatus = variables.mValues[0];
				instance->mPlayersRed = variables.mValues[5];
				instance->mPlayersBlue = variables.mValues[6];

				if(instance->mStatus < 0 || instance->mStatus > 4)
					instance->mStatus = 0;
			}else{
				instance->mData[0] = variables.mValues[3];
				instance->mData[1] = variables.mValues[4];
				instance->mData[2] = variables.mValues[5];
				instance->mData[3] = variables.mValues[6];
				instance->mScoreRed = variables.mValues[7];
				instance->mScoreBlue = variables.mValues[8];
			}
		}
	}else{ 
		OneVAR variable = gRecvPacket->Get<OneVAR>(0);

		PvPGame* game = gGameList->at(variable.mGame);
		if(!game) return;

		PvPInstance* instance = game->mInstanceList->at(variable.mInstance);
		if(!instance) return;

		short variableType = variable.mVariable;
		short value = variable.mValue;

		if(game->mType == CTF) {
			if(variableType == 1)
				instance->mScoreRed = value;

			if(variableType == 2) 
				instance->mScoreBlue = value;
		}

		if(!variable.mSignupOrScore){
			if(variableType == 0){
				instance->mStatus = value;
				if(PvPInstance* currentInstance = HasGameQuest()){
					if(currentInstance == instance){
						if(value == 4)
							IT_MGR::Instance()->OpenMsgBox(String("%1 Instance %2 has been cancelled.").arg(instance->mGame->mName).arg(instance->mID).Str(), MsgBox::BT_OK, false, 0, NULL, NULL, 0);

						if(value == 3){
							IT_MGR::Instance()->AppendChatMsg(String("%1 Instance %2 has started.").arg(instance->mGame->mName).arg(instance->mID).Str(), CHAT_TYPE_WHISPER, 0xFFFFBCAC);		
							IT_MGR::Instance()->AppendChatMsg(String("%1 Instance %2 has started.").arg(instance->mGame->mName).arg(instance->mID).Str(), CHAT_TYPE_WHISPER, 0xFFFFBCAC);		
							IT_MGR::Instance()->AppendChatMsg(String("%1 Instance %2 has started.").arg(instance->mGame->mName).arg(instance->mID).Str(), CHAT_TYPE_WHISPER, 0xFFFFBCAC);		
						}
					}
				}
			}else if(variableType == 5)
				instance->mPlayersRed = value;
			else if(variableType == 6)
				instance->mPlayersBlue = value;
		}else{
			switch(variableType){
				case 3:
					instance->mData[0] = value;
					break;
				case 4:
					instance->mData[1] = value;
					break;
				case 5:
					instance->mData[2] = value;
					break;
				case 6:
					instance->mData[3] = value;
					break;
				case 7:
					instance->mScoreRed = value;
					break;
				case 8:
					instance->mScoreBlue = value;
					break;
			}
		}

		if(instance->mStatus < 0 || instance->mStatus > 4)
			instance->mStatus = 0;
	}
}

void Recv_srv_WHISPER(){
	char* sender = gRecvPacket->GetString(0);
	char* message = gRecvPacket->GetString(strlen(sender) + 1);

	if(!_strcmpi(sender, "SERVER")){
		IT_MGR::Instance()->AppendChatMsg(message, CHAT_TYPE_SYSTEM);
		gRecvPacket->Reset(); 
	}else if(!_strcmpi(sender, "SERVER1")){
		IT_MGR::Instance()->AppendChatMsg(message, CHAT_TYPE_WHISPER);
		gRecvPacket->Reset(); 
	}else if(!_strcmpi(sender, "[BOX]SERVER")){
		IT_MGR::Instance()->OpenMsgBox(message, MsgBox::BT_OK, true, 0, NULL, NULL, 0);
		gRecvPacket->Reset(); 
	}else
		strcpy_s(gLastWhisperer, sender);
}

void Recv_srv_MESSAGE(){
	byte type = gRecvPacket->Get<byte>(0);
	char* message = gRecvPacket->GetString(1);
	unsigned int forceColour = gRecvPacket->Get<unsigned int>(2 + strlen(message));
	unsigned short objectID = gRecvPacket->Get<unsigned short>(6 + strlen(message));

	if(CObjCHAR* object = CObjMGR::Instance()->Get_ClientCharOBJ(objectID, 0)){
		if(type == CHAT_TYPE_MAX)
			IT_MGR::Instance()->OpenMsgBox(message, MsgBox::BT_OK, true, 0, NULL, NULL, 0);
		else
			IT_MGR::Instance()->AppendChatMsg(message, type, forceColour);
	}
}

void Recv_srv_ALLY(){
	short characterID = gRecvPacket->Get<short>(0);
	char* sender = gRecvPacket->GetString(2);
	char* message = gRecvPacket->GetString(strlen(sender) + 3);

	IT_MGR::Instance()->AppendChatMsg(String("[ALLY]%1>%2").arg(sender).arg(message), CHAT_TYPE_ALLIED, D3DCOLOR_ARGB(255, 139, 228, 112));
	UIMediator::Instance()->AddChatMsg(characterID, message);
}

void Recv_srv_CONTRIBUTION(){
	SetContribution(gRecvPacket->GetString(4), gRecvPacket->Get<int>(0));
}

void Recv_srv_BUFF(){
	CObjCHAR* other = NULL;

	if(gRecvPacket->Get<word>(2) == gClientID)
		other = CObjMGR::Instance()->Get_ClientCharOBJ(gRecvPacket->Get<word>(0), 0);
	else if(gRecvPacket->Get<word>(0) == gClientID)
		other = CObjMGR::Instance()->Get_ClientCharOBJ(gRecvPacket->Get<word>(2), 0);

	if (!other) return;

	const char* actionName;
	const char* playerName = other->GetName();

	int buffType = GetBuffType(gRecvPacket->Get<word>(4) & 0x0FFF);	

	if(buffType == 30)
		actionName = "muted";
	else if(buffType == 32)
		actionName = "stunned";
	else if(buffType == 39)
		actionName = "removed buffs from";
	else
		return;

	char buffer[128];

	if(gRecvPacket->Get<word>(0) != gClientID)
		sprintf_s(buffer, 128, "You have successfully %s %s.", actionName, playerName);
	else
		sprintf_s(buffer, 128, "%s %s you.", playerName, actionName);

	IT_MGR::Instance()->AppendChatMsg(buffer, CHAT_TYPE_SYSTEM);
}

void Recv_srv_VENDMESSAGE(){	
	tagBaseITEM item; 
	item.m_wHeader = gRecvPacket->Get<unsigned short>(0);
	item.m_dwBody = gRecvPacket->Get<unsigned int>(2);
	__int64 zulie =  gRecvPacket->Get<__int64>(6);
	int buySell =  gRecvPacket->Get<unsigned char>(14);
	char* name = gRecvPacket->GetString(15);
	int quantity = 1;

	const char* itemName = StringManager::Instance()->GetItemName(item.m_cType, item.m_nItemNo);

	if(!itemName)
		itemName = "Unknown";

	String fullName = itemName;

	if(item.m_cType >= 10 && item.m_cType <= 13){
		quantity = item.m_uiQuantity;
	}else{
		unsigned short refine = item.m_cGrade;
		unsigned short stat = item.m_nGEM_OP;
		unsigned short appraised = item.m_bIsAppraisal;

		if(refine)
			fullName.Append(String("(%1)").arg(refine));

		if(stat >= 1 && stat <= 367 && appraised == 1)
			fullName.Append(String(" [%1]").arg(gStats[stat - 1]));

		if(appraised == 0)
			fullName.Append(" [Item Appraisal]");
	}

	if(fullName.Length()){
		if(buySell == 0)
			IT_MGR::Instance()->AppendChatMsg(String("Bought: %1x %2 for %3z from %4.").arg(quantity).arg(fullName).arg(zulie).arg(name).Str(), CHAT_TYPE_WHISPER);
		else
			IT_MGR::Instance()->AppendChatMsg(String("Sold: %1x %2 for %3z to %4.").arg(quantity).arg(fullName).arg(zulie).arg(name).Str(), CHAT_TYPE_WHISPER);

		fullName.Erase(1, 1);
	}
}

void Recv_srv_PARTYLIST(){
	unsigned char type = gRecvPacket->Get<unsigned char>(0);

	if(type == PAK_PARTY_ADD){
		CTListItemParty* partyItem = new CTListItemParty();
		partyItem->mParty = gRecvPacket->Get<CPartyData>(1);
		partyItem->mParty.mLeaderName = _strdup(gRecvPacket->GetString(13));

		((CZListBox*)ControlInPane(DLG_TYPE_COMMUNITY, 20, 3, 76))->Add(partyItem);
	}else if(type == PAK_PARTY_MODE){
		if (CTCheckBox* partyModeCheck = (CTCheckBox*)IT_MGR::Instance()->FindDlg(DLG_TYPE_PARTYOPTION)->Find(41))
		{
			if (gRecvPacket->Get<unsigned char>(1) == PARTY_PRIVATE)
				partyModeCheck->SetCheck();
			else
				partyModeCheck->SetUncheck();
		}
	}else if(type == PAK_PARTY_CLEAR) 
		((CZListBox*)ControlInPane(DLG_TYPE_COMMUNITY, 20, 3, 76))->Clear();
}

void DeleteDuelRANGE(){
	if(CGameOBJ* object = CObjMGR::Instance()->Get_OBJECT(gRangeObjectID))
		object->RemoveFromScene(true);
}

void SpawnDuelRange(float centerX, float centerY){
	DeleteDuelRANGE();

	CMAP* map = CTERRAIN::Instance()->GetMapPtrByWorldCoordinates(centerX, centerY);
	if(!map) return;

	D3DVECTOR pos;
	D3DXQUATERNION rotate;
	D3DVECTOR scale;

	pos.x = centerX;
	pos.y = centerY;
	pos.z = map->GetHEIGHT(centerX, centerY);

	scale.x = 1.0f;
	scale.y = 1.0f;
	scale.z = 1.0f;

	rotate.w = 1.0f;
	rotate.x = 0.0f;
	rotate.y = 0.0f;
	rotate.z = 0.0f;

	gRangeObjectID = CObjMGR::Instance()->Add_FixedEvent(123, 14, "EMPTY", "EMPTY", &pos, &rotate, &scale);

	if(!map->AddObject(gRangeObjectID, &pos, &rotate, &scale)) return;

	if (CGameOBJ* object = CObjMGR::Instance()->Get_OBJECT(gRangeObjectID))
		object->InsertToScene();
}

void Recv_srv_PLAYERDATA(){
	word objectID = gRecvPacket->Get<word>(0);
	NewData data = gRecvPacket->Get<NewData>(2);

	CObjCHAR* player = CObjMGR::Instance()->Get_ClientCharOBJ(objectID, false);
	if(!player) return;

	if(!player->m_Special)
		player->m_Special = new NewData(data);
	else{
		player->m_Special->mCtfFlag = data.mCtfFlag;
		player->m_Special->mGameTeam = data.mGameTeam;
		player->m_Special->mPvPRank = data.mPvPRank;
		player->m_Special->mDuelEnemy = data.mDuelEnemy;
	}

	if(data.mScale > 0.0f){
		if(HNODE character = ::findNode(player->GetName()))
			::setScale(character, data.mScale, data.mScale, data.mScale);
	}

	if(gInDuel){
		if(gClientID == data.mDuelEnemy){
			SpawnDuelRange(data.mDuelCenterX, data.mDuelCenterY);
			gDuelCountdown = 0;
			gDuelStart = clock();

			if(CUserInputState* inputState = CUserInputState::Instance())
				inputState->m_iCurrentTarget = player->m_nIndex;
		}
	}

	if(!CanShowPVP() && data.mGameTeam){
		data.mArmor.m_cGrade = 0;
		data.mBoots.m_cGrade = 0;
		data.mHelmet.m_cGrade = 0;
		data.mGauntlet.m_cGrade = 0;
		data.mBack.m_cGrade = 0;

		data.mHelmet.m_nItemNo = 0;
		data.mGauntlet.m_nItemNo = 0;

		if(data.mGameTeam == 1){
			data.mArmor.m_nItemNo = 171;
			data.mBoots.m_nItemNo = 171;
			data.mBack.m_nItemNo = (data.mCtfFlag) ? 6 : 0;
		}else if(data.mGameTeam == 2){
			data.mArmor.m_nItemNo = 174;
			data.mBoots.m_nItemNo = 174;
			data.mBack.m_nItemNo = (data.mCtfFlag) ? 5 : 0;
		}
	}

	player->SetPartTagItem(BODY_PART_HELMET, data.mHelmet);	
	player->SetPartTagItem(BODY_PART_GAUNTLET, data.mGauntlet);
	player->SetPartTagItem(BODY_PART_KNAPSACK, data.mBack);
	player->SetPartTagItem(BODY_PART_ARMOR, data.mArmor);
	player->SetPartTagItem(BODY_PART_BOOTS, data.mBoots);

	if(!player->IsPersonalStoreMode())
		player->Update(false);
}

void Recv_srv_DUEL(){
	byte type = gRecvPacket->Get<byte>(0);

	if(type == DUEL_REQ){
		int requestID = gRecvPacket->Get<int>(1);
		int zulie = gRecvPacket->Get<int>(5);
		char* name = gRecvPacket->GetString(9);
		short mode = gRecvPacket->Get<short>(10 + strlen(name));
		char* modeString = gDuelModes[mode];

		if(IT_MGR::Instance()->FindMsgBox(MSGTYPE_RECV_DUEL_REQ) || (gOptions.mAllowDuel == false)){ // busy
			Packet* pak = new Packet(PAK_DUEL);
			pak->Add<byte>(DUEL_REPLY);
			pak->Add<int>(requestID);
			pak->Add<byte>(DUEL_BUSY);
			SendPacket::Instance()->Send(pak);
			delete pak;
		}else{
			CTCommand* acceptCommand = new CTReplyDuel(requestID, DUEL_ACCEPT, zulie);
			CTCommand* denyCommand = new CTReplyDuel(requestID, DUEL_DENY, zulie);
			IT_MGR::Instance()->OpenMsgBox(String("%1 has requested a '%2' duel for %3 zulie.").arg(name).arg(gDuelModes[mode]).arg(zulie).Str(), MsgBox::BT_OKCANCEL, false, 0, acceptCommand, denyCommand, MSGTYPE_RECV_DUEL_REQ);
		}
	}else if(type == DUEL_REPLY){
		byte reply = gRecvPacket->Get<byte>(1);
		char* name = gRecvPacket->GetString(2);

		if(reply == DUEL_ACCEPT){
			IT_MGR::Instance()->AppendChatMsg(String("You are now in a duel with %1").arg(name).Str(), CHAT_TYPE_WHISPER);
			gInDuel = true;
		}else if(reply == DUEL_DENY)
			IT_MGR::Instance()->OpenMsgBox(String("%1 denied your duel request").arg(name).Str(), MsgBox::BT_OK, true, 0, NULL, NULL, 0);
		else if(reply == DUEL_BUSY)
			IT_MGR::Instance()->OpenMsgBox(String("%1 cannot receive your request.").arg(name).Str(), MsgBox::BT_OK, true, 0, NULL, NULL, 0);
	}else if(type == DUEL_END){
		gInDuel = false;
		DeleteDuelRANGE();
	}
}

bool _stdcall isDuelEnemy(CGameOBJ* object, bool previous){
	return previous || !object || gClientID == object->GetDuelEnemy();
}

void __declspec(naked) ASMDuelEnemy(){
	static int  jRet = 0x004095C1;
	static int  cCall = 0x00408A50;
	_asm {
		CALL cCall
		NEG AL
		SBB AL, AL
		INC AL

		PUSH EAX
		SUB ESI, 0x20
		PUSH ESI
		CALL isDuelEnemy

		JMP jRet
	}
}

HookOnLoad(0x004095B6, ASMDuelEnemy, 0);

void __declspec(naked) ASMIsPVPZone(){
	static int  jOver = 0x00430B6B;
	static int  jRet = 0x00430B45;
	_asm {
		MOVZX EAX, gInDuel
		TEST EAX, EAX
		JE jNORMAL
		JMP jOver
jNORMAL:
		MOV EAX, DWORD PTR DS:[0x695B30]
		JMP jRet
	}
}

HookOnLoad(0x00430B40, ASMIsPVPZone, 0);

void Recv_srv_FLAG(){
	gFlagRedStatus = gRecvPacket->Get<short>(0);
	gFlagBlueStatus = gRecvPacket->Get<short>(2); 
}