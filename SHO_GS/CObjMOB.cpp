#include "CObjMOB.h"

t_ObjTAG CObjMOB::Get_TYPE() { return CallMemberFunction<CObjMOB, t_ObjTAG>(0x10013620, this); }
char* CObjMOB::Get_NAME() { return CallMemberFunction<CObjMOB, char*>(0x10013640, this); }
bool CObjMOB::Make_gsv_ADD_OBJECT(classPACKET* pCPacket) { return CallMemberFunction<CObjMOB, bool, classPACKET*>(0x10056C20, this, pCPacket); }
CAI_OBJ* CObjMOB::Get_CALLER() { return CallMemberFunction<CObjMOB, CAI_OBJ*>(0x10056B40, this); }
bool CObjMOB::SetCMD_Skill2SELF(short nSkillIDX, short nMotion) { return CallMemberFunction<CObjMOB, bool, short, short>(0x10057CA0, this, nSkillIDX, nMotion); }
bool CObjMOB::SetCMD_Skill2OBJ(int iTargetObjIDX, short nSkillIDX, short nMotion) { return CallMemberFunction<CObjMOB, bool, int, short, short>(0x10057C10, this, iTargetObjIDX, nSkillIDX, nMotion); }
void CObjMOB::Run_AWAY(int iDistance) { return CallMemberFunction<CObjMOB, void, int>(0x100564A0, this, iDistance); }
void CObjMOB::Drop_ITEM(short nDropITEM, unsigned char btToOwner) { return CallMemberFunction<CObjMOB, void, short, unsigned char>(0x10057890, this, nDropITEM, btToOwner); }
bool CObjMOB::Change_CHAR(int iCharIDX) { return CallMemberFunction<CObjMOB, bool, int>(0x100576E0, this, iCharIDX); }
void CObjMOB::Set_EMOTION(short nEmotionIDX) { return CallMemberFunction<CObjMOB, void, short>(0x10057820, this, nEmotionIDX); }
int CObjMOB::GetANI_Stop() { return CallMemberFunction<CObjMOB, int>(0x10013680, this); }
int CObjMOB::GetANI_Move() { return CallMemberFunction<CObjMOB, int>(0x100136A0, this); }
int CObjMOB::GetANI_Attack() { return CallMemberFunction<CObjMOB, int>(0x100136D0, this); }
int CObjMOB::GetANI_Die() { return CallMemberFunction<CObjMOB, int>(0x100136F0, this); }
int CObjMOB::GetANI_Hit() { return CallMemberFunction<CObjMOB, int>(0x10013710, this); }
int CObjMOB::GetANI_Skill() { return CallMemberFunction<CObjMOB, int>(0x10013730, this); }
int CObjMOB::GetANI_Etc() { return 0; }
int CObjMOB::GetANI_Casting() { return CallMemberFunction<CObjMOB, int>(0x10013750, this); }
int CObjMOB::Get_R_WEAPON() { return CallMemberFunction<CObjMOB, int>(0x10013770, this); }
int CObjMOB::Def_AttackRange() { return CallMemberFunction<CObjMOB, int>(0x100137B0, this); }
int CObjMOB::GetCallerObjIDX() { return CallMemberFunction<CObjMOB, int>(0x100137F0, this); }
bool CObjMOB::SendPacketToTARGET(CObjCHAR* pAtkCHAR, classPACKET* pCPacket) { return CallMemberFunction<CObjMOB, bool, CObjCHAR*, classPACKET*>(0x100567D0, this, pAtkCHAR, pCPacket); }
int CObjMOB::Get_AttackRange(short nSkillIDX) { return CallMemberFunction<CObjMOB, int, short>(0x100563B0, this, nSkillIDX); }
bool CObjMOB::IsFemale() { return CallMemberFunction<CObjMOB, bool>(0x10013810, this); }
short CObjMOB::IsMagicDAMAGE() { return CallMemberFunction<CObjMOB, short>(0x10013830, this); }
tagMOTION* CObjMOB::Get_MOTION(short nActionIdx) { return CallMemberFunction<CObjMOB, tagMOTION*, short>(0x10013870, this, nActionIdx); }
classUSER* CObjMOB::Give_EXP() { return CallMemberFunction<CObjMOB, classUSER*>(0x10057D30, this); }
int CObjMOB::Save_Damage(int iAttackerIDX, int iDamage) { return CallMemberFunction<CObjMOB, int, int, int>(0x10056580, this, iAttackerIDX, iDamage); }
bool CObjMOB::Dead(CObjCHAR* pKiller) { return CallMemberFunction<CObjMOB, bool, CObjCHAR*>(0x10056930, this, pKiller); }
short CObjMOB::Get_WEIGHT() { return CallMemberFunction<CObjMOB, short>(0x100138A0, this); }
int CObjMOB::Get_LEVEL() { return CallMemberFunction<CObjMOB, int>(0x100138C0, this); }
int CObjMOB::Get_GiveEXP() { return CallMemberFunction<CObjMOB, int>(0x10013900, this); }
int CObjMOB::Get_AbilityValue(unsigned short wType) { return CallMemberFunction<CObjMOB, int, unsigned short>(0x10056110, this, wType); }
int CObjMOB::Get_INT() { return CallMemberFunction<CObjMOB, int>(0x10013940, this); }
int CObjMOB::Get_CHARM() { return CallMemberFunction<CObjMOB, int>(0x10013980, this); }
int CObjMOB::Get_SENSE() { return CallMemberFunction<CObjMOB, int>(0x100139A0, this); }
unsigned char CObjMOB::Get_MoveMODE() { return CallMemberFunction<CObjMOB, unsigned char>(0x100139E0, this); }
unsigned char CObjMOB::Get_RideMODE() { return CallMemberFunction<CObjMOB, unsigned char>(0x10013A00, this); }
short CObjMOB::GetOri_WalkSPEED() { return CallMemberFunction<CObjMOB, short>(0x10013A20, this); }
short CObjMOB::GetOri_RunSPEED() { return CallMemberFunction<CObjMOB, short>(0x10013A60, this); }
short CObjMOB::GetOri_ATKSPEED() { return CallMemberFunction<CObjMOB, short>(0x10013AA0, this); }
int CObjMOB::GetOri_ATK() { return CallMemberFunction<CObjMOB, int>(0x10013AE0, this); }
int CObjMOB::GetOri_DEF() { return CallMemberFunction<CObjMOB, int>(0x10013B20, this); }
int CObjMOB::GetOri_RES() { return CallMemberFunction<CObjMOB, int>(0x10013B60, this); }
int CObjMOB::GetOri_HIT() { return CallMemberFunction<CObjMOB, int>(0x10013BA0, this); }
int CObjMOB::GetOri_AVOID() { return CallMemberFunction<CObjMOB, int>(0x10013BE0, this); }
int CObjMOB::GetOri_CRITICAL() { return CallMemberFunction<CObjMOB, int>(0x10013C20, this); }
int CObjMOB::GetOri_MaxHP() { return CallMemberFunction<CObjMOB, int>(0x10013C40, this); }
int CObjMOB::GetOri_MaxMP() { return CallMemberFunction<CObjMOB, int>(0x10013C60, this); }
bool CObjMOB::Make_gsv_SUB_OBJECT(classPACKET* pCPacket) { return CallMemberFunction<CObjMOB, bool, classPACKET*>(0x10056AF0, this, pCPacket); }
void CObjMOB::Add_ToTargetLIST(CObjAVT* pAVTChar) { return CallMemberFunction<CObjMOB, void, CObjAVT*>(0x10056780, this, pAVTChar); }
void CObjMOB::Sub_FromTargetLIST(CObjAVT* pAVTChar) { return CallMemberFunction<CObjMOB, void, CObjAVT*>(0x10056730, this, pAVTChar); }
unsigned short CObjMOB::Get_ATTRIBUTE() { return CallMemberFunction<CObjMOB, unsigned short>(0x10013C80, this); }
CObjMOB::CObjMOB() {};
CObjMOB::~CObjMOB() {};
bool CObjMOB::Init(CZoneTHREAD* pZONE, short nCharIdx, float fXPos, float fYPos, int iTeamNO, CRegenPOINT* pRegenPOINT, short nQuestIDX) { return CallMemberFunction<CObjMOB, bool, CZoneTHREAD*, short, float, float, int, CRegenPOINT*, short>(0x10057210, this, pZONE, nCharIdx, fXPos, fYPos, iTeamNO, pRegenPOINT, nQuestIDX); }
int CObjMOB::Proc() { return CallMemberFunction<CObjMOB, int>(0x10058340, this); }
int CObjMOB::Get_AiVAR(short nVarIdx) { return CallMemberFunction<CObjMOB, int, short>(0x10013E00, this, nVarIdx); }
void CObjMOB::Set_AiVAR(short nVarIdx, int iValue) { return CallMemberFunction<CObjMOB, void, short, int>(0x10013E30, this, nVarIdx, iValue); }
void CObjMOB::LockTargetLIST() { return CallMemberFunction<CObjMOB, void>(0x10015EC0, this); }
void CObjMOB::UnlockTargetLIST() { return CallMemberFunction<CObjMOB, void>(0x10015EE0, this); }
void CObjMOB::Do_CreatedAI() { return CallMemberFunction<CObjMOB, void>(0x10013EA0, this); }
void CObjMOB::Do_StopAI() { return CallMemberFunction<CObjMOB, void>(0x10013EF0, this); }
void CObjMOB::Do_AttackMoveAI(CObjCHAR* pTarget) { return CallMemberFunction<CObjMOB, void, CObjCHAR*>(0x10013F50, this, pTarget); }
void CObjMOB::Do_DamagedAI(CObjCHAR* pTarget, int iDamage) { return CallMemberFunction<CObjMOB, void, CObjCHAR*, int>(0x10013FC0, this, pTarget, iDamage); }
void CObjMOB::Do_KillAI(CObjCHAR* pTarget, int iDamage) { return CallMemberFunction<CObjMOB, void, CObjCHAR*, int>(0x10014090, this, pTarget, iDamage); }
void CObjMOB::Do_DeadAI(CObjCHAR* pTarget, int iDamage) { return CallMemberFunction<CObjMOB, void, CObjCHAR*, int>(0x10014100, this, pTarget, iDamage); }
unsigned long CObjMOB::Get_AICheckTIME(int iIDX) { return CallMemberFunction<CObjMOB, unsigned long, int>(0x10014160, this, iIDX); }
void CObjMOB::Set_AICheckTIME(int iIDX, unsigned long lCheckTIME) { return CallMemberFunction<CObjMOB, void, int, unsigned long>(0x10014190, this, iIDX, lCheckTIME); }



