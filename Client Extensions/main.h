#define WIN32_LEAN_AND_MEAN
#define DEBUG_MODE
//#define TEST_SERVER

#include <windows.h>
#include <stdio.h>
#include <vector>

#include <TRose\Hash.h>

#include "..\Shared\AchievementList.hpp"
#include "..\Shared\AchievementData.hpp"
#include "..\Shared\Templates.hpp"
#include "..\Shared\Console.hpp"
#include "..\Shared\RunOnLoad.hpp"
#include "..\Shared\DataTYPE.hpp"
#include <TRose\zz_interface.h>

#include <TRose\Game.h>
#include <TRose\DrawImpl.h>
#include <TRose\RoseAPI.h>
#include <TRose\CObjMGR.h>
#include <TRose\CGameOBJ.h>
#include <TRose\CTERRAIN.h>
#include <TRose\D3DMatrix.h>
#include <TGameCtrl\WinCtrl.h>
#include <TGameCtrl\TCommand.h>
#include <TGameCtrl\ResourceMGR.h>

#pragma comment(lib,"ws2_32.lib")

/*
1.30 = PvP update TS
1.31 = PvP update Public
1.32 = PvP update Public 2 fix
1.33 = Fix minimap
1.34 = Bracket instances
*/
const char gConfig[] = "./Sevenhearts.ini";

#ifndef TEST_SERVER
const char gVersion[] = "TitanProtect v1.35";
#else
const char gVersion[] = "TitanProtect v1.35 [ Test Server ]";
#endif

void RunQuestIconScript();
void LoadQuestIconScript(char* path);
void SetFont(int fontSize);
void OnQuestTrigger(unsigned long hash);
void ResetGUI();
void FixAspectRatio();
void PopulateStatusList();
void SetContribution(char* characterName, int points);
void RefreshPartyList();
void PwntHaxBbq();
void EnableWallhack();
void ApplyZoom(bool enabled);
void StartAppearance();

extern bool gIsActive;

void LoadAchievementList();
extern AchievementList gAchievementList;
extern AchievementData gAchievementData;

class CTAchievements;
extern CTAchievements* gAchieveDialog;

class CTAppearance;
extern CTAppearance* gAppearDialog;

class CTPvP;
extern CTPvP* gPvPDialog;

class CTPvPInstance;
extern CTPvPInstance* gPvPInstance;

class SkillBar2;
extern SkillBar2* gSkillBar2;

class CTDuelInvite;
extern CTDuelInvite* gDuelInvite;

struct CMousePos {
	union {
		struct {
			unsigned short x;
			unsigned short y;
		};
		long mousePos;
	};
};


// ARGB
enum Colours {
	COLOUR_RED = 0xFFFF0020,
	COLOUR_ORANGE = 0xFFFFA500,
	COLOUR_GREEN = 0xFF96FF78,
	COLOUR_BLUE = 0xFF0000FF,
	COLOUR_YELLOW = 0xFFFFFF00,
	COLOUR_PURPLE = 0xFFA020F0,
	COLOUR_WHITE = 0xFFFFFFFF,
	COLOUR_BABYBLUE = 0xFF5AD6D0,
	COLOUR_BABYRED = 0xFFFF7373,
};

static inline int GetSTBValue(int stbIndex, int row, int column){
	unsigned char* valPtr = *(unsigned char**)(0x695AF4 + stbIndex*4);
	valPtr = *(unsigned char**)(valPtr + 0x20);
	valPtr = *(unsigned char**)(valPtr + (row * 4));
	return *(int*)(valPtr + (column * 4));
}

static inline int GetSTBValueP(unsigned char* stbptr, int row, int column){
	unsigned char* valPtr = stbptr;
	valPtr = *(unsigned char**)(valPtr + 0x20);
	valPtr = *(unsigned char**)(valPtr + (row * 4));
	return *(int*)(valPtr + (column * 4));
}

int inline GetBuffType(int buffSkill){
	return *(dword*)((*(dword*)((*(dword*)(0x6998F4)) + (buffSkill*4))) + 0x2C);
}

struct Options {
	int mFontSize;
	char mQuestIconEnable;
	char mAntiAliasingEnable;
	char mFarZoom;
	char mAllowDuel;
	int mSkillBarX;
	int mSkillBarY;
	int mSkillBarEnable;
	int mSkillBarType;
	int mSkillBarPage;
	List<char*> mUsernames;
};

static void ResetTransform(float x, float y){
	D3DMATRIX matrix;
	D3DXMatrixTranslation(&matrix, x, y, 0.0f);
	setTransformSprite(&matrix.m[0][0]);
}

static void ResetTransform(float x, float y, float z){
	D3DMATRIX matrix;
	D3DXMatrixTranslation(&matrix, x, y, z);
	setTransformSprite(&matrix.m[0][0]);
}

extern char* gStats[];
extern int gStatus;
extern Options gOptions;
extern const char* gStatusText[7];
extern HWND gThisWND;
extern char gLastWhisperer[32];

extern clock_t gWallHackStart;
extern bool gWallHaxEnabled;

static enum ControlIDs {
	optSkillBar2 = 175,
	optFontSize = 176,
	optQuestIcons = 177,
	optAntiAliasing = 178,
	optZoom = 179,
	optDuelBox = 85,
	optDuelYes = 86,
	optDuelNo = 87,
};

enum t_CharPART {
	BODY_PART_FACE = 0,						
	BODY_PART_HAIR = 1,
	BODY_PART_HELMET = 2,
	BODY_PART_ARMOR = 3,					
	BODY_PART_GAUNTLET = 4,
	BODY_PART_BOOTS = 5,
	BODY_PART_GOGGLE = 6,
	BODY_PART_KNAPSACK = 7,
	BODY_PART_WEAPON_R = 8,					
	BODY_PART_WEAPON_L = 9,	
	MAX_BODY_PART = 10
};

enum EXTERNALUI {
	EUI_LOGIN = 0,
	EUI_SELECT_AVATA,
	EUI_SELECT_SERVER,
	EUI_CREATE_AVATA,
	EUI_WARNING,
	EUI_MAX,
};

/*
	static StringManager* Instance(){
		return **reinterpret_cast<StringManager***>(0x69397C);
	}
	MOV ECX,DWORD PTR DS:[0x69397C]
	MOV ECX,DWORD PTR DS:[ECX]

	static StringManager* Instance(){
		return *reinterpret_cast<StringManager**>(0x69397C);
	}
	MOV ECX,DWORD PTR DS:[0x69397C]

	static StringManager* Instance(){
		return reinterpret_cast<StringManager*>(0x69397C);
	}
	MOV ECX, 0x69397C
*/