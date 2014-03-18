#include "main.h"
#include "PvP.h"

char* gGameStatus[] = { 
	"Closed",
	"Signups",
	"Full",
	"In Progress",
	"Cancelled" 
};

char* gGameRank[] = { 
	"Unranked",
	"Novice",
	"Fighter",
	"Pathfinder",
	"Trooper", 
	"Brute",
	"Berserker",
	"Overlord",
	"Phoenix",
	"Marquis", 
	"Veteran",
	"Centurion",
	"Magestic",
	"Legend",
	"Titan", 
};

List<PvPGame*>* gGameList;
bool gAllowPartChange = true;

int GetRank(){
	CGameOBJ* self = CObjMGR::GetSelf();
	if(!self) return 0;

	int wins = self->GetStat(86);

	if(wins < 1)   return 0;
	if(wins < 3)   return 1;
	if(wins < 7)   return 2;
	if(wins < 15)  return 3;
	if(wins < 30)  return 4;
	if(wins < 55)  return 5;
	if(wins < 90)  return 6;
	if(wins < 135) return 7;
	if(wins < 190) return 8;
	if(wins < 255) return 9;
	if(wins < 325) return 10;
	if(wins < 400) return 11;
	if(wins < 490) return 12;
	if(wins < 600) return 13;

	return 14;
}

PvPInstance* HasGameQuest(){
	for(unsigned int i = 0; i < gGameList->size(); i++){
		PvPGame* gameItem = gGameList->at(i);

		for(unsigned int a = 0; a < gameItem->mInstanceList->size(); a++){
			PvPInstance* instance = gameItem->mInstanceList->at(a);

			if(instance->HasFlag())
				return instance;
		}
	}

	return 0;
}

PvPGame* InitDragonHunt(int instances){
	PvPGame* game = new PvPGame();
	game->mType			= DRAGON_HUNT;
	game->mName			= "Dragon Hunt";
	game->mJoinRed		= "DH-%1-Red";		
	game->mJoinBlue		= "DH-%1-Blue";		
	game->mCheckRed		= "DH-%1-RedG";		
	game->mCheckBlue	= "DH-%1-BlueG";	
	game->mGiveUp		= "DH-%1-RedC";		
	game->mQuestFlag	= "DH-%1-Empty";
	game->mJoinBattle	= "DH-%1-RedGo";	
	game->mMapID		= 70;
	game->mBossIcon		= CResourceMgr::GetInstance()->GetImageNID(IMAGE_RES_UI, "DUNGEONBOSS_HEAD_A"); // 719 - 720
	game->mMaxPlayers	= 7;
	game->mIcon			= 85;
	game->mInstanceList = new List<PvPInstance*>;

	for(int i = 0; i < instances; i++)
		game->mInstanceList->push_back(new PvPInstance(i + 1, game));

	return game;
}

PvPGame* InitConquest(int instances){
	PvPGame* game = new PvPGame();
	game->mType			= CONQUEST;
	game->mName			= "Crystal Conquest";
	game->mJoinRed		= "CQ-%1-Red";		
	game->mJoinBlue		= "CQ-%1-Blue";		
	game->mCheckRed		= "CQ-%1-RedG";		
	game->mCheckBlue	= "CQ-%1-BlueG";	
	game->mGiveUp		= "CQ-%1-RedC";		
	game->mQuestFlag	= "CQ-%1-Empty";
	game->mJoinBattle   = "CQ-%1-RedGo";	
	game->mMapID		= 74;
	game->mBossIcon		= 0;
	game->mMaxPlayers	= 20;
	game->mIcon			= 86;
	game->mInstanceList = new List<PvPInstance*>;

	for(int i = 0; i < instances; i++)
		game->mInstanceList->push_back(new PvPInstance(i + 1, game));

	return game;
}

PvPGame* InitCTF(int instances){
	PvPGame* game = new PvPGame();
	game->mType			= CTF;
	game->mName			= "Capture the Flag";
	game->mJoinRed		= "CTF-%1-Red";		
	game->mJoinBlue		= "CTF-%1-Blue";		
	game->mCheckRed		= "CTF-%1-RedG";		
	game->mCheckBlue	= "CTF-%1-BlueG";	
	game->mGiveUp		= "CTF-%1-RedC";		
	game->mQuestFlag	= "CTF-%1-Empty";
	game->mJoinBattle   = "CTF-%1-RedGo";	
	game->mMapID		= 77;
	game->mBossIcon		= 0;
	game->mMaxPlayers	= 10;
	game->mIcon			= 87;
	game->mInstanceList = new List<PvPInstance*>;

	for(int i = 0; i < instances; i++)
		game->mInstanceList->push_back(new PvPInstance(i + 1, game));

	return game;
}

PvPGame* InitKOTH(int instances){
	PvPGame* game = new PvPGame();
	game->mType			= KOTH;
	game->mName			= "King of the Hill";
	game->mJoinRed		= "KH-%1-Red";		
	game->mJoinBlue		= "KH-%1-Blue";		
	game->mCheckRed		= "KH-%1-RedG";		
	game->mCheckBlue	= "KH-%1-BlueG";	
	game->mGiveUp		= "KH-%1-RedC";		
	game->mQuestFlag	= "KH-%1-Empty";
	game->mJoinBattle   = "KH-%1-RedGo";	
	game->mMapID		= 80;
	game->mBossIcon		= 0;
	game->mMaxPlayers	= 6;
	game->mIcon			= 89;
	game->mInstanceList = new List<PvPInstance*>;

	for(int i = 0; i < instances; i++)
		game->mInstanceList->push_back(new PvPInstance(i + 1, game));

	return game;
}

bool _stdcall CanSetParts(int itemType){
	if(!CanShowPVP() && itemType != 8 && itemType != 9){
		Code::NOP((unsigned char*)0x004F1B0E, 7);
		return false;
	}

	unsigned char enableParts[] = { 0x89, 0x94, 0x8E, 0x94, 0x04, 0x0, 0x0 };
	Code::Write(0x004F1B0E, enableParts, 7);

	return true;
}

void _declspec(naked) ASMCanSetParts(){
	static int jRet = 0x00469025;
	static int jOver = 0x00469069;
	_asm {
		MOV EAX, DWORD PTR SS:[ESP+0x4]
		PUSHAD
		PUSH EAX
		CALL CanSetParts
		TEST AL, AL
		POPAD
		JE JmpOVER
		PUSH EBX
		MOV EBX, DWORD PTR SS:[ESP+0x8]
		JMP jRet
JmpOVER:
		JMP jOver
	};
}

HookOnLoad(0x00469020, ASMCanSetParts, 0);