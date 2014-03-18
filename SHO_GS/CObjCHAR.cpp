#include "CObjCHAR.h"

void CObjCHAR::Adjust_HEIGHT() { return CallMemberFunction<CObjCHAR, void>(0x10007990, this); }
bool CObjCHAR::SendPacketToUSER(CObjCHAR* Var1, classPACKET* Var2) { return 0; }
bool CObjCHAR::Send_gsv_STOP() { return CallMemberFunction<CObjCHAR, bool>(0x10069FF0, this); }
bool CObjCHAR::Send_gsv_MOUSECMD(int iTargetObject) { return CallMemberFunction<CObjCHAR, bool, int>(0x10069F10, this, iTargetObject); }
bool CObjCHAR::Send_gsv_MOVE() { return CallMemberFunction<CObjCHAR, bool>(0x10069E20, this); }
bool CObjCHAR::Send_gsv_ATTACK(int iTargetObject) { return CallMemberFunction<CObjCHAR, bool, int>(0x10069D50, this, iTargetObject); }
bool CObjCHAR::Send_gsv_DAMAGE2Sector(int iAttackObject, unsigned short wDamage, CObjITEM* pDropITEM) { return CallMemberFunction<CObjCHAR, bool, int, unsigned short, CObjITEM*>(0x10069670, this, iAttackObject, wDamage, pDropITEM); }
bool CObjCHAR::Send_gsv_DAMAGE2Target(CObjCHAR* pAtkOBJ, unsigned short wDamage) { return CallMemberFunction<CObjCHAR, bool, CObjCHAR*, unsigned short>(0x100695C0, this, pAtkOBJ, wDamage); }
bool CObjCHAR::Send_gsv_TOGGLE(unsigned char btTYPE, bool bUpdateSpeed) { return CallMemberFunction<CObjCHAR, bool, unsigned char, bool>(0x10069C80, this, btTYPE, bUpdateSpeed); }
bool CObjCHAR::Send_gsv_SELF_SKILL(short nSkillIDX, short nNpcSkillMotion) { return CallMemberFunction<CObjCHAR, bool, short, short>(0x10069BD0, this, nSkillIDX, nNpcSkillMotion); }
bool CObjCHAR::Send_gsv_TARGET_SKILL(short nSkillIDX, short nNpcSkillMotion) { return CallMemberFunction<CObjCHAR, bool, short, short>(0x10069AD0, this, nSkillIDX, nNpcSkillMotion); }
bool CObjCHAR::Send_gsv_POSITION_SKILL(short nSkillIDX) { return CallMemberFunction<CObjCHAR, bool, short>(0x10069A20, this, nSkillIDX); }
void CObjCHAR::Init_ADD_CHAR(classPACKET* pCPacket) { return CallMemberFunction<CObjCHAR, void, classPACKET*>(0x100687B0, this, pCPacket); }
void CObjCHAR::Add_ADJ_STATUS(classPACKET* pCPacket) { return CallMemberFunction<CObjCHAR, void, classPACKET*>(0x100685A0, this, pCPacket); }
void CObjCHAR::Send_gsv_RESULT_OF_SKILL(short nSkillIDX) { return CallMemberFunction<CObjCHAR, void, short>(0x10069220, this, nSkillIDX); }
bool CObjCHAR::Send_gsv_EFFECT_OF_SKILL(int iSpellOBJ, short nSkillIDX, unsigned char btResult, short nSpellerINT) { return CallMemberFunction<CObjCHAR, bool, int, short, unsigned char, short>(0x100694D0, this, iSpellOBJ, nSkillIDX, btResult, nSpellerINT); }
bool CObjCHAR::Send_gsv_DAMAGE_OF_SKILL(int iSpellOBJ, short nSkillIDX, unsigned short wDamage, unsigned char btResult, short nSpellerINT, CObjITEM* pDropITEM) { return CallMemberFunction<CObjCHAR, bool, int, short, unsigned short, unsigned char, short, CObjITEM*>(0x100692B0, this, iSpellOBJ, nSkillIDX, wDamage, btResult, nSpellerINT, pDropITEM); }
bool CObjCHAR::Send_gsv_SET_MOTION(unsigned short wValue, short nMotionNO) { return CallMemberFunction<CObjCHAR, bool, unsigned short, short>(0x10069820, this, wValue, nMotionNO); }
bool CObjCHAR::Send_gsv_CLEAR_STATUS(unsigned long dwClearedFLAG) { return CallMemberFunction<CObjCHAR, bool, unsigned long>(0x100698E0, this, dwClearedFLAG); }
unsigned char CObjCHAR::Apply_DAMAGE(CObjCHAR* pTarget, uniDAMAGE& sDamage, CObjITEM** ppOutITEM, bool bDropItem) { return CallMemberFunction<CObjCHAR, unsigned char, CObjCHAR*, uniDAMAGE&, CObjITEM**, bool>(0x1006AB30, this, pTarget, sDamage, ppOutITEM, bDropItem); }
CAI_OBJ* CObjCHAR::AI_FindFirstOBJ(int iDistance) { return CallMemberFunction<CObjCHAR, CAI_OBJ*, int>(0x10069070, this, iDistance); }
CAI_OBJ* CObjCHAR::AI_FindFirstOBJ(CVec2& PosCENTER, int iDistance) { return CallMemberFunction<CObjCHAR, CAI_OBJ*, CVec2&, int>(0x10069100, this, PosCENTER, iDistance); }
CAI_OBJ* CObjCHAR::AI_FindNextOBJ() { return CallMemberFunction<CObjCHAR, CAI_OBJ*>(0x10069010, this); }
void CObjCHAR::Give_DAMAGE(CObjCHAR* pTarget, uniDAMAGE sDamage, bool bDropItem) { return CallMemberFunction<CObjCHAR, void, CObjCHAR*, uniDAMAGE, bool>(0x1006B8A0, this, pTarget, sDamage, bDropItem); }
bool CObjCHAR::Send_gsv_CHAT(char* szMsg) { return CallMemberFunction<CObjCHAR, bool, char*>(0x1006A160, this, szMsg); }
bool CObjCHAR::Send_gsv_SHOUT(char* szMsg) { return CallMemberFunction<CObjCHAR, bool, char*>(0x1006A0B0, this, szMsg); }
void CObjCHAR::Send_gsv_ANNOUNCE_CHAT(char* szMsg) { return CallMemberFunction<CObjCHAR, void, char*>(0x1006B2E0, this, szMsg); }
bool CObjCHAR::Send_gsv_ALLIED_CHAT(char* Var1) { return 0; }
bool CObjCHAR::Send_gsv_ALLIED_SHOUT(char* Var1) { return 0; }
CObjCHAR::CObjCHAR() {};
CObjCHAR::~CObjCHAR() {};
void CObjCHAR::CloseNETWORK() { return CallMemberFunction<CObjCHAR, void>(0x10012BE0, this); }
bool CObjCHAR::SendPacketToPARTY(classPACKET* pCPacket) { return CallMemberFunction<CObjCHAR, bool, classPACKET*>(0x10012C00, this, pCPacket); }
bool CObjCHAR::SendPacketIfPARTY(classPACKET* pCPacket) { return CallMemberFunction<CObjCHAR, bool, classPACKET*>(0x10012C20, this, pCPacket); }
bool CObjCHAR::SendPacketToPartyExceptME(classPACKET* pCPacket) { return CallMemberFunction<CObjCHAR, bool, classPACKET*>(0x10012C40, this, pCPacket); }
bool CObjCHAR::SendPacketToPartyExecpNearUSER(classPACKET* pCPacket) { return CallMemberFunction<CObjCHAR, bool, classPACKET*>(0x100079B0, this, pCPacket); }
bool CObjCHAR::SendPacketToTARGET(CObjCHAR* Var1, classPACKET* Var2) { return 0; }
bool CObjCHAR::Send_gsv_SET_HPnMP(unsigned char btApply) { return CallMemberFunction<CObjCHAR, bool, unsigned char>(0x10012C60, this, btApply); }
bool CObjCHAR::Run_EVENT() { return CallMemberFunction<CObjCHAR, bool>(0x100079D0, this); }
bool CObjCHAR::Check_EVENT(CGameOBJ* pSourOBJ, short nEventIDX) { return CallMemberFunction<CObjCHAR, bool, CGameOBJ*, short>(0x100079F0, this, pSourOBJ, nEventIDX); }
unsigned long CObjCHAR::Get_AICheckTIME(int iIDX) { return CallMemberFunction<CObjCHAR, unsigned long, int>(0x10007A10, this, iIDX); }
void CObjCHAR::Set_AICheckTIME(int iIDX, unsigned long lCheckTIME) { return CallMemberFunction<CObjCHAR, void, int, unsigned long>(0x10007A30, this, iIDX, lCheckTIME); }
bool CObjCHAR::IsFemale() { return 0; }
short CObjCHAR::IsMagicDAMAGE() { return 0; }
int CObjCHAR::GetCallerUsrIDX() { return CallMemberFunction<CObjCHAR, int>(0x10007A50, this); }
int CObjCHAR::GetCallerObjIDX() { return CallMemberFunction<CObjCHAR, int>(0x10007A70, this); }
unsigned long CObjCHAR::GetCallerHASH() { return CallMemberFunction<CObjCHAR, unsigned long>(0x10007A90, this); }
short CObjCHAR::GetSummonedSkillIDX() { return CallMemberFunction<CObjCHAR, short>(0x10007AB0, this); }
tagMOTION* CObjCHAR::Get_MOTION(short Var1) { return 0; }
int CObjCHAR::Get_HP() { return CallMemberFunction<CObjCHAR, int>(0x10013240, this); }
int CObjCHAR::Get_MP() { return CallMemberFunction<CObjCHAR, int>(0x10013260, this); }
void CObjCHAR::Set_HP(int iHP) { return CallMemberFunction<CObjCHAR, void, int>(0x10013280, this, iHP); }
void CObjCHAR::Set_MP(int iMP) { return CallMemberFunction<CObjCHAR, void, int>(0x100132A0, this, iMP); }
int CObjCHAR::Add_HP(int iAdd) { return CallMemberFunction<CObjCHAR, int, int>(0x100132C0, this, iAdd); }
int CObjCHAR::Add_MP(int iAdd) { return CallMemberFunction<CObjCHAR, int, int>(0x10013340, this, iAdd); }
int CObjCHAR::Sub_HP(int iSub) { return CallMemberFunction<CObjCHAR, int, int>(0x100133C0, this, iSub); }
int CObjCHAR::Sub_MP(int iSub) { return CallMemberFunction<CObjCHAR, int, int>(0x10013410, this, iSub); }
void CObjCHAR::Add_STAMINA(short Var0) { return CallMemberFunction<CObjCHAR, void, short>(0x10013460, this, Var0); }
void CObjCHAR::Add_MONEY(short Var0) { return CallMemberFunction<CObjCHAR, void, short>(0x10013480, this, Var0); }
short CObjCHAR::Get_WEIGHT() { return 0; }
int CObjCHAR::Get_LEVEL() { return 0; }
int CObjCHAR::Get_GiveEXP() { return 0; }
void CObjCHAR::Add_EXP(int iExp, bool bApplyStamina) { return CallMemberFunction<CObjCHAR, void, int, bool>(0x10007AD0, this, iExp, bApplyStamina); }
int CObjCHAR::Get_AbilityValue(unsigned short Var1) { return 0; }
int CObjCHAR::Get_EXP() { return CallMemberFunction<CObjCHAR, int>(0x100134A0, this); }
int CObjCHAR::Get_JOB() { return CallMemberFunction<CObjCHAR, int>(0x100134C0, this); }
unsigned long CObjCHAR::Get_RIGHT() { return CallMemberFunction<CObjCHAR, unsigned long>(0x10012C80, this); }
__int64 CObjCHAR::Get_MONEY() { return CallMemberFunction<CObjCHAR, __int64>(0x100134E0, this); }
int CObjCHAR::Get_INT() { return 0; }
int CObjCHAR::Get_CHARM() { return 0; }
int CObjCHAR::Get_SENSE() { return 0; }
unsigned char CObjCHAR::Get_MoveMODE() { return 0; }
unsigned char CObjCHAR::Get_RideMODE() { return 0; }
int CObjCHAR::GetOri_MaxHP() { return 0; }
int CObjCHAR::GetOri_MaxMP() { return 0; }
short CObjCHAR::GetOri_WalkSPEED() { return 0; }
short CObjCHAR::GetOri_RunSPEED() { return 0; }
short CObjCHAR::GetOri_ATKSPEED() { return 0; }
int CObjCHAR::GetOri_ATK() { return 0; }
int CObjCHAR::GetOri_DEF() { return 0; }
int CObjCHAR::GetOri_RES() { return 0; }
int CObjCHAR::GetOri_HIT() { return 0; }
int CObjCHAR::GetOri_AVOID() { return 0; }
int CObjCHAR::GetOri_CRITICAL() { return 0; }
int CObjCHAR::Save_Damage(int Var1, int Var2) { return 0; }
void CObjCHAR::Dec_WeaponLife() { return CallMemberFunction<CObjCHAR, void>(0x10013500, this); }
void CObjCHAR::Dec_EngineLife() { return CallMemberFunction<CObjCHAR, void>(0x10013520, this); }
classUSER* CObjCHAR::Give_EXP() { return CallMemberFunction<CObjCHAR, classUSER*>(0x10007AF0, this); }
unsigned long CObjCHAR::Get_CharHASH() { return CallMemberFunction<CObjCHAR, unsigned long>(0x10012CA0, this); }
void CObjCHAR::Clear_SummonCNT() { return CallMemberFunction<CObjCHAR, void>(0x10013540, this); }
void CObjCHAR::Add_SummonCNT(short nV) { return CallMemberFunction<CObjCHAR, void, short>(0x10013560, this, nV); }
void CObjCHAR::Sub_SummonCNT(short nV) { return CallMemberFunction<CObjCHAR, void, short>(0x10013580, this, nV); }
short CObjCHAR::Get_SummonCNT() { return CallMemberFunction<CObjCHAR, short>(0x100135A0, this); }
short CObjCHAR::Max_SummonCNT() { return CallMemberFunction<CObjCHAR, short>(0x100135C0, this); }
void CObjCHAR::Add_ToTargetLIST(CObjAVT* pAVTChar) { return CallMemberFunction<CObjCHAR, void, CObjAVT*>(0x10007B10, this, pAVTChar); }
void CObjCHAR::Sub_FromTargetLIST(CObjAVT* pAVTChar) { return CallMemberFunction<CObjCHAR, void, CObjAVT*>(0x10007B30, this, pAVTChar); }
CParty* CObjCHAR::GetPARTY() { return CallMemberFunction<CObjCHAR, CParty*>(0x10012CC0, this); }
CGuild* CObjCHAR::GetGUILD() { return CallMemberFunction<CObjCHAR, CGuild*>(0x10007B50, this); }
bool CObjCHAR::Chk_ShotITEM(unsigned char btShotCnt) { return CallMemberFunction<CObjCHAR, bool, unsigned char>(0x10012CE0, this, btShotCnt); }
bool CObjCHAR::Dec_ShotITEM(unsigned char btShotCnt) { return CallMemberFunction<CObjCHAR, bool, unsigned char>(0x10012D00, this, btShotCnt); }
unsigned short CObjCHAR::Get_ATTRIBUTE() { return CallMemberFunction<CObjCHAR, unsigned short>(0x10007B70, this); }
void CObjCHAR::Stamp_AttackTIME() { return CallMemberFunction<CObjCHAR, void>(0x100135E0, this); }
bool CObjCHAR::Dead(CObjCHAR* pKiller) { return CallMemberFunction<CObjCHAR, bool, CObjCHAR*>(0x10068440, this, pKiller); }
int CObjCHAR::Proc() { return CallMemberFunction<CObjCHAR, int>(0x1006C200, this); }
void CObjCHAR::UpdateCartGuest() { return CallMemberFunction<CObjCHAR, void>(0x10013600, this); }
bool CObjCHAR::Skill_IsPassFilter(CObjCHAR* pTarget, short nSkillIDX) { return CallMemberFunction<CObjCHAR, bool, CObjCHAR*, short>(0x100680A0, this, pTarget, nSkillIDX); }
void CObjCHAR::Skill_ChangeIngSTATUS(CObjCHAR* pTarget) { return CallMemberFunction<CObjCHAR, void, CObjCHAR*>(0x1006A6A0, this, pTarget); }
unsigned char CObjCHAR::Skill_ApplyIngSTATUS(short nSkillIDX, CObjCHAR* pSpeller) { return CallMemberFunction<CObjCHAR, unsigned char, short, CObjCHAR*>(0x10068AB0, this, nSkillIDX, pSpeller); }
bool CObjCHAR::Skill_DamageToAROUND(CVec2& PosCENTER) { return CallMemberFunction<CObjCHAR, bool, CVec2&>(0x1006B650, this, PosCENTER); }
CVec2 CObjCHAR::Get_GotoPOSITION() { return CVec2(); }
CVec2 CObjCHAR::Get_CurPOSITION() { return CVec2(); }
CVec2 CObjCHAR::Get_BornPOSITION() { return CVec2(); }
short CObjCHAR::Get_nAttackSPEED() { return CallMemberFunction<CObjCHAR, short>(0x10007B90, this); }
float CObjCHAR::Get_MoveSPEED() { return CallMemberFunction<CObjCHAR, float>(0x10007C10, this); }
int CObjCHAR::Get_ATK() { return CallMemberFunction<CObjCHAR, int>(0x10007CD0, this); }
int CObjCHAR::Get_DEF() { return CallMemberFunction<CObjCHAR, int>(0x10007D50, this); }
int CObjCHAR::Get_RES() { return CallMemberFunction<CObjCHAR, int>(0x10007DD0, this); }
int CObjCHAR::Get_HIT() { return CallMemberFunction<CObjCHAR, int>(0x10007E50, this); }
int CObjCHAR::Get_AVOID() { return CallMemberFunction<CObjCHAR, int>(0x10007ED0, this); }
int CObjCHAR::Get_CRITICAL() { return CallMemberFunction<CObjCHAR, int>(0x10007F50, this); }
int CObjCHAR::Get_MaxHP() { return CallMemberFunction<CObjCHAR, int>(0x10007FD0, this); }
int CObjCHAR::Get_MaxMP() { return CallMemberFunction<CObjCHAR, int>(0x10008020, this); }
int CObjCHAR::GetCurrentFrame() { return CallMemberFunction<CObjCHAR, int>(0x10008070, this); }
unsigned long CObjCHAR::GetCurAbsSEC() { return CallMemberFunction<CObjCHAR, unsigned long>(0x100688A0, this); }
void CObjCHAR::Move(float Var1, CVec2& Var2) { return; }
void CObjCHAR::Command_MOVE(float Var1, float Var2, float Var3) { return; }
void CObjCHAR::ActionEVENT(int iActionIDX) { return CallMemberFunction<CObjCHAR, void, int>(0x10067FF0, this, iActionIDX); }
int CObjCHAR::RealProc(unsigned long dwPassTIME) { return CallMemberFunction<CObjCHAR, int, unsigned long>(0x1006BA60, this, dwPassTIME); }
void CObjCHAR::Proc_IngSTATUS(unsigned long dwPassTime) { return CallMemberFunction<CObjCHAR, void, unsigned long>(0x1006A360, this, dwPassTime); }
t_ObjTAG CObjCHAR::Get_CharObjTAG() { return CallMemberFunction<CObjCHAR, t_ObjTAG>(0x10008090, this); }
int CObjCHAR::Get_EconomyVAR(short nVarIDX) { return CallMemberFunction<CObjCHAR, int, short>(0x10068FD0, this, nVarIDX); }
int CObjCHAR::Get_WorldVAR(short nVarIDX) { return CallMemberFunction<CObjCHAR, int, short>(0x10068A80, this, nVarIDX); }
void CObjCHAR::Set_EconomyVAR(short nVarIDX, int iValue) { return CallMemberFunction<CObjCHAR, void, short, int>(0x10068080, this, nVarIDX, iValue); }
void CObjCHAR::Set_WorldVAR(short nVarIDX, int iValue) { return CallMemberFunction<CObjCHAR, void, short, int>(0x10068030, this, nVarIDX, iValue); }
void CObjCHAR::Add_DAMAGE(unsigned short wDamage) { return CallMemberFunction<CObjCHAR, void, unsigned short>(0x100080D0, this, wDamage); }
unsigned long CObjCHAR::Get_MagicSTATUS() { return CallMemberFunction<CObjCHAR, unsigned long>(0x10008190, this); }
int CObjCHAR::Get_TeamNO() { return CallMemberFunction<CObjCHAR, int>(0x100081C0, this); }
int CObjCHAR::Get_TEAM() { return CallMemberFunction<CObjCHAR, int>(0x100081E0, this); }
unsigned char CObjCHAR::Is_DAY() { return CallMemberFunction<CObjCHAR, unsigned char>(0x10068A50, this); }
int CObjCHAR::Get_ZoneTIME() { return CallMemberFunction<CObjCHAR, int>(0x10008220, this); }
int CObjCHAR::Get_WorldTIME() { return CallMemberFunction<CObjCHAR, int>(0x10008250, this); }
bool CObjCHAR::Create_PET(int iCharIDX, float fPosX, float fPosY, int iRange, unsigned char btSetOwner, bool bImmediate) { return CallMemberFunction<CObjCHAR, bool, int, float, float, int, unsigned char, bool>(0x1006A290, this, iCharIDX, fPosX, fPosY, iRange, btSetOwner, bImmediate); }
CAI_OBJ* CObjCHAR::Find_LocalNPC(int iNpcNO) { return CallMemberFunction<CObjCHAR, CAI_OBJ*, int>(0x100688E0, this, iNpcNO); }
float CObjCHAR::Get_SCALE() { return CallMemberFunction<CObjCHAR, float>(0x10008280, this); }
int CObjCHAR::Get_CharNO() { return CallMemberFunction<CObjCHAR, int>(0x100082A0, this); }
int CObjCHAR::Get_RANDOM(int iMod) { return CallMemberFunction<CObjCHAR, int, int>(0x100082C0, this, iMod); }
float CObjCHAR::Get_CurXPOS() { return CallMemberFunction<CObjCHAR, float>(0x100082F0, this); }
float CObjCHAR::Get_CurYPOS() { return CallMemberFunction<CObjCHAR, float>(0x10008310, this); }
float CObjCHAR::Get_BornXPOS() { return CallMemberFunction<CObjCHAR, float>(0x10008330, this); }
float CObjCHAR::Get_BornYPOS() { return CallMemberFunction<CObjCHAR, float>(0x10008350, this); }
void CObjCHAR::Special_ATTACK() { return CallMemberFunction<CObjCHAR, void>(0x10008370, this); }
float CObjCHAR::Get_MoveDISTANCE() { return CallMemberFunction<CObjCHAR, float>(0x10008390, this); }
float CObjCHAR::Get_DISTANCE(CAI_OBJ* pObj) { return CallMemberFunction<CObjCHAR, float, CAI_OBJ*>(0x10008410, this, pObj); }
int CObjCHAR::Get_DISTANCE(CVec2& Pos) { return CallMemberFunction<CObjCHAR, int, CVec2&>(0x100083D0, this, Pos); }
bool CObjCHAR::SetCMD_STOP() { return CallMemberFunction<CObjCHAR, bool>(0x1006AAF0, this); }
bool CObjCHAR::SetCMD_MOVE2D(float fPosX, float fPosY, unsigned char btRunMODE) { return CallMemberFunction<CObjCHAR, bool, float, float, unsigned char>(0x1006B1F0, this, fPosX, fPosY, btRunMODE); }
bool CObjCHAR::SetCMD_ATTACK(int iTargetObject) { return CallMemberFunction<CObjCHAR, bool, int>(0x1006AA60, this, iTargetObject); }
bool CObjCHAR::SetCMD_Skill2SELF(short nSkillIDX) { return CallMemberFunction<CObjCHAR, bool, short>(0x1006A9D0, this, nSkillIDX); }
bool CObjCHAR::SetCMD_Skill2OBJ(int iTargetObjIDX, short nSkillIDX) { return CallMemberFunction<CObjCHAR, bool, int, short>(0x1006A950, this, iTargetObjIDX, nSkillIDX); }
bool CObjCHAR::SetCMD_Skill2POS(CVec2& PosGOTO, short nSkillIDX) { return CallMemberFunction<CObjCHAR, bool, CVec2&, short>(0x1006A8D0, this, PosGOTO, nSkillIDX); }
bool CObjCHAR::Is_TauntSTATUS(int iTargetObject) { return CallMemberFunction<CObjCHAR, bool, int>(0x10008470, this, iTargetObject); }
unsigned long CObjCHAR::GetIngDurationStateFLAG() { return CallMemberFunction<CObjCHAR, unsigned long>(0x100084B0, this); }
short CObjCHAR::GetIngDurationStateSKILL(eING_TYPE eTYPE) { return CallMemberFunction<CObjCHAR, short, eING_TYPE>(0x100084E0, this, eTYPE); }
bool CObjCHAR::SetCMD_MOVE(CVec2& PosCUR, CVec2& PosTO, int iTargetObjIDX) { return CallMemberFunction<CObjCHAR, bool, CVec2&, CVec2&, int>(0x1006B290, this, PosCUR, PosTO, iTargetObjIDX); }
bool CObjCHAR::IsInRANGE(CObjCHAR* pT, int iRange) { return CallMemberFunction<CObjCHAR, bool, CObjCHAR*, int>(0x10008510, this, pT, iRange); }
bool CObjCHAR::Set_MOTION(short nActionIdx, float fMoveSpeed, float fAniSpeed, bool bAttackMotion) { return CallMemberFunction<CObjCHAR, bool, short, float, float, bool>(0x100684D0, this, nActionIdx, fMoveSpeed, fAniSpeed, bAttackMotion); }
void CObjCHAR::Move_COMPLETED() { return; }
bool CObjCHAR::Send_gsv_SKILL_CANCEL(unsigned char btWhy) { return CallMemberFunction<CObjCHAR, bool, unsigned char>(0x1006A200, this, btWhy); }
void CObjCHAR::Skill_START_03_04_05(CObjCHAR* pTarget) { return CallMemberFunction<CObjCHAR, void, CObjCHAR*>(0x1006B4F0, this, pTarget); }
void CObjCHAR::Skill_START_10_11(CObjCHAR* pTarget) { return CallMemberFunction<CObjCHAR, void, CObjCHAR*>(0x1006A490, this, pTarget); }
void CObjCHAR::Skill_START_19(CObjCHAR* pTarget) { return CallMemberFunction<CObjCHAR, void, CObjCHAR*>(0x1006B340, this, pTarget); }
bool CObjCHAR::Skill_START(CObjCHAR* pTarget) { return CallMemberFunction<CObjCHAR, bool, CObjCHAR*>(0x1006BD40, this, pTarget); }
bool CObjCHAR::Attack_START(CObjCHAR* pTarget) { return CallMemberFunction<CObjCHAR, bool, CObjCHAR*>(0x1006BC50, this, pTarget); }
bool CObjCHAR::Casting_START(CObjCHAR* pTarget) { return CallMemberFunction<CObjCHAR, bool, CObjCHAR*>(0x10069180, this, pTarget); }
void CObjCHAR::Casting_END() { return CallMemberFunction<CObjCHAR, void>(0x10008570, this); }



