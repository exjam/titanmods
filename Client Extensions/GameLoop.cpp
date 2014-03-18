#include "main.h"
#include "Network.h"
#include "PvP.h"
#include "Controls.h"
#include <TRose\CallCharLuaFunc.hpp>
#include <TRose\CObjCHAR.h>

clock_t gLastUpdate;

void RunBossScript();
void RunScoreDisplay();
void RunAchievementPopup();
void RunDuelCountdown();

Achievement* gNewAchievement = NULL;
volatile int gDrawAchievementPopup = 0;

extern short gFlagRedStatus;
extern short gFlagBlueStatus;

PvPInstance* gCurrentInstance = 0;
int gDuelCountdown = -1;
clock_t gDuelStart;

extern HNODE gSmallOutlineFont;

void __stdcall MainLoop(){
	FixAspectRatio();

	gCurrentInstance = HasGameQuest();
	if(gCurrentInstance && !CanShowPVP()){
		RunBossScript();
		RunScoreDisplay();
	}

	if(gNewAchievement)
		RunAchievementPopup();

	clock_t dt = clock() - gLastUpdate;
	if(dt < 2000) return;

	gLastUpdate = clock();
	RunQuestIconScript();
}

void RunDuelCountdown(){
	clock_t dt = clock() - gDuelStart;
	gDuelCountdown = (dt / 1000);

	if(gDuelCountdown >= 0 && gDuelCountdown <= 10){
		int y = (getScreenHeight() / 4);
		int x = (getScreenWidth() / 2);

		int timer = CResourceMgr::GetInstance()->GetImageNID(IMAGE_RES_UI, "TIMER_0");
		ResetTransform(0, 0);
		DrawImpl::Instance()->Draw2D(x, y, IMAGE_RES_UI, timer + (10 - gDuelCountdown), 0xFFFFFFFF);
	} else
		gDuelCountdown = -1;
}

void RunScoreDisplay(){
	ResetTransform(0, 0);

	int centerX = (getScreenWidth() / 2);
	int centerY = (getScreenHeight() / 2);
	
	switch(gCurrentInstance->mGame->mType){
		case DRAGON_HUNT:
			return;
		case CONQUEST:
			{
				for(int i = 0; i < 4; ++i){
					int icon = 0;

					if(gCurrentInstance->mData[i] == 0)
						icon = 14;
					else if(gCurrentInstance->mData[i] == 3)
						icon = 24 + i;
					else if(gCurrentInstance->mData[i] == 4)
						icon = 18 + i;

					DrawImpl::Instance()->Draw2D(centerX + ((i - 2) * 22), 55, IMAGE_RES_TARGETMARK, icon, 0xFFFFFFFF);
					ResetTransform(0, 0);
				}
			}
			break;
		case KOTH:
			{
				int icon = 0;

				if(gCurrentInstance->mData[0] == 0)
					icon = 14;
				else if(gCurrentInstance->mData[0] == 3)
					icon = 13;
				else if(gCurrentInstance->mData[0] == 4)
					icon = 12;

				DrawImpl::Instance()->Draw2D(centerX - 10, 55, IMAGE_RES_TARGETMARK, icon, 0xFFFFFFFF);
				ResetTransform(0, 0);
			}
			break;
		case CTF:
			{
				int red = gFlagRedGUI;
				int blue = gFlagRedGUI + 1;

				if(gFlagRedStatus == 0)
					red += 2;

				if(gFlagBlueStatus == 0)
					blue += 2;
		
				DrawImpl::Instance()->Draw2D(centerX - 100, 60, IMAGE_RES_UI, red, 0xFFFFFFFF);
				ResetTransform(0, 0);

				DrawImpl::Instance()->Draw2D(centerX + 50, 60, IMAGE_RES_UI, blue, 0xFFFFFFFF);
				ResetTransform(0, 0);
			}
			break;
	}

	SIZE sizeRed = ::getFontTextExtent(GameDATA->m_hFONT[FONT_NORMAL_OUTLINE], "Red: ");
	SIZE sizeBlue = ::getFontTextExtent(GameDATA->m_hFONT[FONT_NORMAL_OUTLINE], "Blue: ");
	SIZE fullSizeRed = ::getFontTextExtent(GameDATA->m_hFONT[FONT_NORMAL_OUTLINE], String("Red: %1").arg(gCurrentInstance->mScoreRed));
	SIZE fullSizeBlue = ::getFontTextExtent(GameDATA->m_hFONT[FONT_NORMAL_OUTLINE], String("Blue: %1").arg(gCurrentInstance->mScoreBlue));

	drawFont(GameDATA->m_hFONT[FONT_NORMAL_OUTLINE], 1, centerX - (fullSizeRed.cx / 2), 80, 0xFFFF5555, "Red:");
	drawFont(GameDATA->m_hFONT[FONT_NORMAL_OUTLINE], 1, centerX - (fullSizeBlue.cx / 2), 82 + sizeRed.cy, 0xFF77AAFF, "Blue:");

	drawFont(GameDATA->m_hFONT[FONT_NORMAL_OUTLINE], 1, centerX - (fullSizeRed.cx / 2) + sizeRed.cx, 80, 0xFFFFFFFF, String("%1").arg(gCurrentInstance->mScoreRed));
	drawFont(GameDATA->m_hFONT[FONT_NORMAL_OUTLINE], 1, centerX - (fullSizeBlue.cx / 2) + sizeBlue.cx, 82 + sizeRed.cy, 0xFFFFFFFF, String("%1").arg(gCurrentInstance->mScoreBlue));
}

void RunBossScript(){
	int bossIcon = gCurrentInstance->mGame->mBossIcon;
	if(!bossIcon) return;

	int monsterID1;

	if(gCurrentInstance->mID == 1)
		monsterID1 = 2029;
	else if(gCurrentInstance->mID == 2)
		monsterID1 = 2037;
	else if(gCurrentInstance->mID == 3)
		monsterID1 = 2019;

	for(int i = 1; i <= 65535; i++){
		CObjCHAR* boss = CObjMGR::Instance()->Get_ClientCharOBJ(i, false);

		if(!boss || ((boss->GetCharNO() != monsterID1) && (boss->GetCharNO() != (monsterID1 + 1))))
			continue;

		if(boss->GetCharNO() == monsterID1) 
			bossIcon++;

		int hp = boss->GetHP();
		if(hp <= 0) continue;

		int maximumHP = boss->GetMaxHP();
		float percentage = (100.0f * hp / maximumHP);
		int leftPosition = 235 + 20;
		int topPosition = 75;

		tagRECT pos;
		SetRect(&pos, leftPosition + 56, topPosition + 19, leftPosition + 309, topPosition + 42);

		ResetTransform(0, 0);
		DrawImpl::Instance()->Draw2DW(leftPosition + 56.0f, topPosition + 19.0f, 0.0f, 260, IMAGE_RES_UI, gBossGUI);
		ResetTransform(0, 0);
		DrawImpl::Instance()->Draw2DW(leftPosition + 58.0f, topPosition + 22.0f, 0.0f, 249 * hp / maximumHP, IMAGE_RES_UI, gBossGUI + 1);		
		ResetTransform(0, 0);
		DrawImpl::Instance()->Draw2D(leftPosition, topPosition, IMAGE_RES_UI, bossIcon, 0xFFFFFFFF);
		ResetTransform(0, 0);
		drawFont(GameDATA->m_hFONT[FONT_NORMAL_OUTLINE], 1, &pos, 0xFFFFFFFF, DT_CENTER | DT_VCENTER, String("%1%2").arg(percentage).arg("%"));

		return;
	}
}

void RunAchievementPopup(){
	static int alpha;

	if(gDrawAchievementPopup == 2){
		alpha = 0xFFFF;
		gDrawAchievementPopup = 1;
	}

	if(alpha > 0){
		const char* nameText = gNewAchievement->mName;
		const char* descText = gNewAchievement->mDescription;

		int drawIcon = gNewAchievement->mIcon;
		int drawX = (getScreenWidth() / 2) - (388 / 2);
		int fade = (alpha & 0xFF);
		int colour = fade << 24 | 0xFFFFFF;

		ResetTransform(0,0);
		DrawImpl::Instance()->Draw2D(drawX, 70, IMAGE_RES_UI, gUnlockedGUI, colour);
		ResetTransform(0,0);
		DrawImpl::Instance()->Draw2D(drawX + 2, 70 + 3, IMAGE_RES_ITEM, drawIcon, colour);
		ResetTransform(0,0);

		tagRECT pos;
		colour = fade << 24 | 0xFFFF00;
		SetRect(&pos, drawX + 43, 75, drawX + 357, 91);
		drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, colour, 1, nameText);

		colour = fade << 24 | 0xFFFFFF;
		SetRect(&pos, drawX + 43, 97, drawX + 357, 114);
		drawFont(GameDATA->m_hFONT[FONT_SMALL], 1, &pos, colour, 1, descText);

		if(alpha > 0xFF){
			alpha -= 0x200;
			if(alpha < 0xFF) alpha = 0xFF;
		}else
			alpha -= 4;
	}else
		gDrawAchievementPopup = 0;
}

void __declspec(naked) ASMDrawUIHook(){
	static int call1 = 0x004FE4C0;
	static int jmpret = 0x00420292;
	_asm {
		PUSHAD
		CALL MainLoop
		POPAD
		CALL call1
		JMP jmpret
	}
}

HookOnLoad(0x0042028D, ASMDrawUIHook, 0);

void _stdcall NameBoxRank(CGameOBJ* player){
	if(CanShowPVP()) return;

	String rank =  String("%1").arg(player->GetRank());
	SIZE nameSize = getFontTextExtent(GameDATA->m_hFONT[FONT_NORMAL_OUTLINE], player->GetName());
	SIZE rankSize = getFontTextExtent(gSmallOutlineFont, rank);

	RECT rt = { -1 - rankSize.cx, 0, nameSize.cx , nameSize.cy };
	::drawFont(gSmallOutlineFont, true, &rt, D3DCOLOR_ARGB(255, 255, 255, 0), DT_LEFT | DT_VCENTER , rank);
}

void __declspec(naked) ASMNameBoxRank(){
	static int jRet = 0x00487FA2;
	_asm {
	    MOV AL, BYTE PTR SS:[ESP+0x9C]
		PUSHAD
		PUSH ESI
		CALL NameBoxRank
		POPAD
		JMP jRet
	};
}

HookOnLoad(0x00487F9B, ASMNameBoxRank, 2);

bool CanShowPVP(){
	return CTERRAIN::Instance()->m_nZoneNO < 70;
}