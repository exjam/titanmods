#ifndef MAIN_H
#define MAIN_H

#undef VER_CLIENT

#include <SHO_GS\SHO_GS.h>
#include "..\Shared\AchievementList.hpp"
#include "..\Shared\AchievementData.hpp"
#include "..\Shared\DataTYPE.hpp"
#include "..\Shared\Console.hpp"
#include "..\Shared\RunOnLoad.hpp"
#include "CustomAvatarData.h"
#include <SHO_GS\STB.h>

class CPacket;


extern CThreadGUILD* g_pThreadGUILD;
extern CUserLIST* g_pUserLIST;
extern CZoneLIST* g_pZoneLIST;
extern CLIB_GameSRV* g_pServer;
extern CPartyBUFF* g_pPartyBUFF;
extern GS_CThreadSQL* g_pThreadSQL;
extern GS_CThreadLOG* g_pThreadLOG;
extern CObjMNG* g_pObjMGR;
extern CQuestDATA* g_pQuestDATA;

extern bool gFreeze;
extern bool gInitDone;
extern bool gHasLoaded;

extern char* gStats[];

extern Array<char*> gFilter;

float Distance(CVec2 p1, CVec2 p2);

#endif