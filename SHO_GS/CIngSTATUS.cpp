#include "CIngSTATUS.h"

short CIngSTATUS::Proc_IngPOTION(CIngSTATUS::tagIngPOTION* pPOTION, unsigned long dwPassTIME) { return CallMemberFunction<CIngSTATUS, short, CIngSTATUS::tagIngPOTION*, unsigned long>(0x100AC050, this, pPOTION, dwPassTIME); }
short CIngSTATUS::Inc_MAX_HP() { return CallMemberFunction<CIngSTATUS, short>(0x100076C0, this); }
short CIngSTATUS::Inc_MAX_MP() { return CallMemberFunction<CIngSTATUS, short>(0x100076F0, this); }
short CIngSTATUS::Inc_RUN_SPEED() { return CallMemberFunction<CIngSTATUS, short>(0x10013190, this); }
short CIngSTATUS::Dec_RUN_SPEED() { return CallMemberFunction<CIngSTATUS, short>(0x100131B0, this); }
short CIngSTATUS::Inc_ATK_SPEED() { return CallMemberFunction<CIngSTATUS, short>(0x100131D0, this); }
short CIngSTATUS::Dec_ATK_SPEED() { return CallMemberFunction<CIngSTATUS, short>(0x100131F0, this); }
short CIngSTATUS::Adj_RUN_SPEED() { return CallMemberFunction<CIngSTATUS, short>(0x10007720, this); }
short CIngSTATUS::Adj_ATK_SPEED() { return CallMemberFunction<CIngSTATUS, short>(0x10007760, this); }
short CIngSTATUS::Adj_APOWER() { return CallMemberFunction<CIngSTATUS, short>(0x10007790, this); }
short CIngSTATUS::Adj_DPOWER() { return CallMemberFunction<CIngSTATUS, short>(0x100077D0, this); }
short CIngSTATUS::Adj_RES() { return CallMemberFunction<CIngSTATUS, short>(0x10007810, this); }
short CIngSTATUS::Adj_HIT() { return CallMemberFunction<CIngSTATUS, short>(0x10007840, this); }
short CIngSTATUS::Adj_CRITICAL() { return CallMemberFunction<CIngSTATUS, short>(0x10007870, this); }
short CIngSTATUS::Adj_AVOID() { return CallMemberFunction<CIngSTATUS, short>(0x100078B0, this); }
void CIngSTATUS::SetSubFLAG(unsigned long dwFLAG) { return CallMemberFunction<CIngSTATUS, void, unsigned long>(0x10010A60, this, dwFLAG); }
void CIngSTATUS::ClearSubFLAG(unsigned long dwFLAG) { return CallMemberFunction<CIngSTATUS, void, unsigned long>(0x10010A90, this, dwFLAG); }
unsigned long CIngSTATUS::IsSubSET(unsigned long dwCheckFLAG) { return CallMemberFunction<CIngSTATUS, unsigned long, unsigned long>(0x10010AC0, this, dwCheckFLAG); }
void CIngSTATUS::ToggleSubFLAG(unsigned long dwFLAG) { return CallMemberFunction<CIngSTATUS, void, unsigned long>(0x10010AE0, this, dwFLAG); }
void CIngSTATUS::DelArua() { return CallMemberFunction<CIngSTATUS, void>(0x10012B10, this); }
void CIngSTATUS::Reset(bool bFirst) { return CallMemberFunction<CIngSTATUS, void, bool>(0x100078E0, this, bFirst); }
void CIngSTATUS::ClearALL(unsigned long Var1) { return; }
void CIngSTATUS::ClearAllGOOD() { return CallMemberFunction<CIngSTATUS, void>(0x10012B50, this); }
unsigned long CIngSTATUS::IsSET(unsigned long dwCheckFLAG) { return CallMemberFunction<CIngSTATUS, unsigned long, unsigned long>(0x10010B30, this, dwCheckFLAG); }
unsigned long CIngSTATUS::GetFLAGs() { return CallMemberFunction<CIngSTATUS, unsigned long>(0x10004180, this); }
short CIngSTATUS::GetSkillIDX(eING_TYPE eTYPE) { return CallMemberFunction<CIngSTATUS, short, eING_TYPE>(0x10007970, this, eTYPE); }
void CIngSTATUS::SetFLAG(unsigned long dwIngFLAG) { return CallMemberFunction<CIngSTATUS, void, unsigned long>(0x100121A0, this, dwIngFLAG); }
void CIngSTATUS::ClearStatusFLAG(unsigned long dwIngFLAG) { return CallMemberFunction<CIngSTATUS, void, unsigned long>(0x10010B50, this, dwIngFLAG); }
void CIngSTATUS::ClearSTATUS(eING_TYPE IngType) { return CallMemberFunction<CIngSTATUS, void, eING_TYPE>(0x10010B80, this, IngType); }
void CIngSTATUS::ClearStatusIfENABLED(eING_TYPE IngType) { return CallMemberFunction<CIngSTATUS, void, eING_TYPE>(0x10010BD0, this, IngType); }
void CIngSTATUS::ExpireSTATUS(eING_TYPE IngType) { return CallMemberFunction<CIngSTATUS, void, eING_TYPE>(0x10013210, this, IngType); }
bool CIngSTATUS::IsTauntSTATUS(int iAttackObjIDX, CZoneTHREAD* pCurZone) { return CallMemberFunction<CIngSTATUS, bool, int, CZoneTHREAD*>(0x100ACC30, this, iAttackObjIDX, pCurZone); }
bool CIngSTATUS::IsIgnoreSTATUS() { return CallMemberFunction<CIngSTATUS, bool>(0x10010C40, this); }
bool CIngSTATUS::IsEnableApplay(short nIngStbIDX, short nAdjValue) { return CallMemberFunction<CIngSTATUS, bool, short, short>(0x100AC230, this, nIngStbIDX, nAdjValue); }
bool CIngSTATUS::IsEnableApplayITEM(short nIngStbIDX) { return CallMemberFunction<CIngSTATUS, bool, short>(0x100AC2D0, this, nIngStbIDX); }
unsigned long CIngSTATUS::UpdateIngSTATUS(CObjCHAR* pCharOBJ, short nIngStbIDX, short nTick, short nAdjVALUE, short nSkillIDX, int iTargetObjIDX) { return CallMemberFunction<CIngSTATUS, unsigned long, CObjCHAR*, short, short, short, short, int>(0x100AC950, this, pCharOBJ, nIngStbIDX, nTick, nAdjVALUE, nSkillIDX, iTargetObjIDX); }
void CIngSTATUS::UpdateIngPOTION(short nIngStbIDX, short nTotValue, short nAdjPerSEC) { return CallMemberFunction<CIngSTATUS, void, short, short, short>(0x100AC130, this, nIngStbIDX, nTotValue, nAdjPerSEC); }
unsigned long CIngSTATUS::Proc(CObjCHAR* pCharOBJ, unsigned long dwPassTIME) { return CallMemberFunction<CIngSTATUS, unsigned long, CObjCHAR*, unsigned long>(0x100AC370, this, pCharOBJ, dwPassTIME); }



