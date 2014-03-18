#include "CUserDATA.h"

int CUserDATA::GetPassiveSkillValue(short nAbilityTYPE) { return CallMemberFunction<CUserDATA, int, short>(0x10006AB0, this, nAbilityTYPE); }
void CUserDATA::AddPassiveSkillValue(short nAbilityTYPE, short nValue) { return CallMemberFunction<CUserDATA, void, short, short>(0x100121D0, this, nAbilityTYPE, nValue); }
short CUserDATA::GetPassiveSkillRate(short nAbilityTYPE) { return CallMemberFunction<CUserDATA, short, short>(0x10012210, this, nAbilityTYPE); }
void CUserDATA::AddPassiveSkillRate(short nAbilityTYPE, short nRate) { return CallMemberFunction<CUserDATA, void, short, short>(0x10012240, this, nAbilityTYPE, nRate); }
void CUserDATA::Cal_AddAbility() { return CallMemberFunction<CUserDATA, void>(0x10073450, this); }
void CUserDATA::Cal_AddAbility(tagITEM& sITEM, short nItemTYPE) { return CallMemberFunction<CUserDATA, void, tagITEM&, short>(0x10071B00, this, sITEM, nItemTYPE); }
void CUserDATA::Cal_AddPatAbility(tagITEM& Var1, short Var2) { return; }
void CUserDATA::Cal_RecoverHP() { return CallMemberFunction<CUserDATA, void>(0x10071DA0, this); }
void CUserDATA::Cal_RecoverMP() { return CallMemberFunction<CUserDATA, void>(0x10071D30, this); }
int CUserDATA::Cal_MaxHP() { return CallMemberFunction<CUserDATA, int>(0x10076430, this); }
int CUserDATA::Cal_MaxMP() { return CallMemberFunction<CUserDATA, int>(0x100730A0, this); }
int CUserDATA::Cal_HIT() { return CallMemberFunction<CUserDATA, int>(0x10075D60, this); }
int CUserDATA::Cal_DEFENCE() { return CallMemberFunction<CUserDATA, int>(0x100728F0, this); }
int CUserDATA::Cal_RESIST() { return CallMemberFunction<CUserDATA, int>(0x10072D30, this); }
int CUserDATA::Cal_MaxWEIGHT() { return CallMemberFunction<CUserDATA, int>(0x10072F60, this); }
int CUserDATA::Cal_AvoidRATE() { return CallMemberFunction<CUserDATA, int>(0x10076290, this); }
int CUserDATA::Cal_CRITICAL() { return CallMemberFunction<CUserDATA, int>(0x100760D0, this); }
short CUserDATA::GetPassiveSkillAttackPower(int iCurAP, short nRightWeaponItemNo) { return CallMemberFunction<CUserDATA, short, int, short>(0x10070FE0, this, iCurAP, nRightWeaponItemNo); }
short CUserDATA::GetPassiveSkillAttackSpeed(float fCurSpeed, short nRightWeaponItemNo) { return CallMemberFunction<CUserDATA, short, float, short>(0x10071130, this, fCurSpeed, nRightWeaponItemNo); }
float CUserDATA::Cal_RunSPEED() { return CallMemberFunction<CUserDATA, float>(0x100744B0, this); }
void CUserDATA::Cal_BattleAbility() { return CallMemberFunction<CUserDATA, void>(0x10076AF0, this); }
int CUserDATA::Cal_ATTACK() { return CallMemberFunction<CUserDATA, int>(0x10074740, this); }
short CUserDATA::GetCur_HP() { return CallMemberFunction<CUserDATA, short>(0x10006AE0, this); }
short CUserDATA::GetCur_MP() { return CallMemberFunction<CUserDATA, short>(0x10006B00, this); }
short CUserDATA::GetCur_WEIGHT() { return CallMemberFunction<CUserDATA, short>(0x10006B20, this); }
int CUserDATA::GetCur_LEVEL() { return CallMemberFunction<CUserDATA, int>(0x10006B40, this); }
int CUserDATA::GetDef_ATK() { return CallMemberFunction<CUserDATA, int>(0x10006B60, this); }
int CUserDATA::GetDef_DEF() { return CallMemberFunction<CUserDATA, int>(0x10006B80, this); }
int CUserDATA::GetDef_RES() { return CallMemberFunction<CUserDATA, int>(0x10006BA0, this); }
int CUserDATA::GetDef_HIT() { return CallMemberFunction<CUserDATA, int>(0x10006BC0, this); }
int CUserDATA::GetDef_AVOID() { return CallMemberFunction<CUserDATA, int>(0x10006BE0, this); }
int CUserDATA::GetDef_CRITICAL() { return CallMemberFunction<CUserDATA, int>(0x10006C00, this); }
int CUserDATA::GetCur_BIRTH() { return 0; }
int CUserDATA::GetCur_RANK() { return CallMemberFunction<CUserDATA, int>(0x10012710, this); }
int CUserDATA::GetCur_JOHAP() { return CallMemberFunction<CUserDATA, int>(0x10010470, this); }
int CUserDATA::GetCur_FAME() { return CallMemberFunction<CUserDATA, int>(0x10012730, this); }
int CUserDATA::GetCur_JOB() { return CallMemberFunction<CUserDATA, int>(0x10006C20, this); }
int CUserDATA::GetCur_EXP() { return CallMemberFunction<CUserDATA, int>(0x10006C40, this); }
int CUserDATA::GetCur_BonusPOINT() { return CallMemberFunction<CUserDATA, int>(0x10003C90, this); }
int CUserDATA::GetCur_SkillPOINT() { return CallMemberFunction<CUserDATA, int>(0x10003CB0, this); }
unsigned char CUserDATA::GetCur_HeadSIZE() { return CallMemberFunction<CUserDATA, unsigned char>(0x10012750, this); }
unsigned char CUserDATA::GetCur_BodySIZE() { return CallMemberFunction<CUserDATA, unsigned char>(0x10012770, this); }
int CUserDATA::GetDef_STR() { return CallMemberFunction<CUserDATA, int>(0x10012280, this); }
int CUserDATA::GetDef_DEX() { return CallMemberFunction<CUserDATA, int>(0x100122A0, this); }
int CUserDATA::GetDef_INT() { return CallMemberFunction<CUserDATA, int>(0x10006C60, this); }
int CUserDATA::GetDef_CON() { return CallMemberFunction<CUserDATA, int>(0x10006C80, this); }
int CUserDATA::GetDef_CHARM() { return CallMemberFunction<CUserDATA, int>(0x10006CA0, this); }
int CUserDATA::GetDef_SENSE() { return CallMemberFunction<CUserDATA, int>(0x10006CC0, this); }
void CUserDATA::SetDef_STR(short nValue) { return CallMemberFunction<CUserDATA, void, short>(0x100122C0, this, nValue); }
void CUserDATA::SetDef_DEX(short nValue) { return CallMemberFunction<CUserDATA, void, short>(0x100122E0, this, nValue); }
void CUserDATA::SetDef_INT(short nValue) { return CallMemberFunction<CUserDATA, void, short>(0x10012300, this, nValue); }
void CUserDATA::SetDef_CON(short nValue) { return CallMemberFunction<CUserDATA, void, short>(0x10012320, this, nValue); }
void CUserDATA::SetDef_CHARM(short nValue) { return CallMemberFunction<CUserDATA, void, short>(0x10012340, this, nValue); }
void CUserDATA::SetDef_SENSE(short nValue) { return CallMemberFunction<CUserDATA, void, short>(0x10012360, this, nValue); }
int CUserDATA::GetCur_STR() { return CallMemberFunction<CUserDATA, int>(0x10012380, this); }
int CUserDATA::GetCur_DEX() { return CallMemberFunction<CUserDATA, int>(0x100123C0, this); }
int CUserDATA::GetCur_INT() { return CallMemberFunction<CUserDATA, int>(0x10006CE0, this); }
int CUserDATA::GetCur_CON() { return CallMemberFunction<CUserDATA, int>(0x10006D20, this); }
int CUserDATA::GetCur_CHARM() { return CallMemberFunction<CUserDATA, int>(0x10006D60, this); }
int CUserDATA::GetCur_SENSE() { return CallMemberFunction<CUserDATA, int>(0x10006DA0, this); }
int CUserDATA::GetCur_SaveMP() { return CallMemberFunction<CUserDATA, int>(0x10012400, this); }
int CUserDATA::GetCur_DropRATE() { return CallMemberFunction<CUserDATA, int>(0x10012790, this); }
void CUserDATA::Cal_DropRATE() { return CallMemberFunction<CUserDATA, void>(0x10012470, this); }
int CUserDATA::GetMax_SummonCNT() { return CallMemberFunction<CUserDATA, int>(0x10006DE0, this); }
int CUserDATA::GetCur_JoHapPOINT(char btUnionIDX) { return CallMemberFunction<CUserDATA, int, char>(0x10010490, this, btUnionIDX); }
void CUserDATA::SetCur_JoHapPOINT(unsigned char Var1, short Var2) { return; }
void CUserDATA::AddCur_JoHapPOINT(unsigned char btUnionIDX, short nValue) { return CallMemberFunction<CUserDATA, void, unsigned char, short>(0x100124F0, this, btUnionIDX, nValue); }
void CUserDATA::SubCur_JoHapPOINT(unsigned char btUnionIDX, short nValue) { return CallMemberFunction<CUserDATA, void, unsigned char, short>(0x100104E0, this, btUnionIDX, nValue); }
int CUserDATA::GetCur_FameB() { return CallMemberFunction<CUserDATA, int>(0x100127B0, this); }
int CUserDATA::GetCur_FameG() { return CallMemberFunction<CUserDATA, int>(0x100127D0, this); }
void CUserDATA::AddClanSCORE(int Var1) { return; }
short CUserDATA::GetDef_MaxHP() { return CallMemberFunction<CUserDATA, short>(0x10006E10, this); }
short CUserDATA::GetDef_MaxMP() { return CallMemberFunction<CUserDATA, short>(0x10006E30, this); }
short CUserDATA::GetCur_MaxWEIGHT() { return 0; }
int CUserDATA::GetCur_MAG() { return 0; }
int CUserDATA::GetTot_DEF_DURABITY() { return CallMemberFunction<CUserDATA, int>(0x10012560, this); }
int CUserDATA::GetTot_DEF_GRADE() { return CallMemberFunction<CUserDATA, int>(0x10012580, this); }
float CUserDATA::GetCur_RateUseMP() { return CallMemberFunction<CUserDATA, float>(0x100125A0, this); }
void CUserDATA::SetCur_MONEY(__int64 iMoney) { return CallMemberFunction<CUserDATA, void, __int64>(0x10010550, this, iMoney); }
__int64 CUserDATA::GetCur_MONEY() { return CallMemberFunction<CUserDATA, __int64>(0x10006E50, this); }
void CUserDATA::Add_CurMONEY(int iMoney) { return CallMemberFunction<CUserDATA, void, int>(0x10003CD0, this, iMoney); }
void CUserDATA::Sub_CurMONEY(int iMoney) { return CallMemberFunction<CUserDATA, void, int>(0x10010580, this, iMoney); }
void CUserDATA::SetCur_HP(short nValue) { return CallMemberFunction<CUserDATA, void, short>(0x10070460, this, nValue); }
void CUserDATA::SetCur_MP(short nValue) { return CallMemberFunction<CUserDATA, void, short>(0x10006E80, this, nValue); }
int CUserDATA::AddCur_HP(short nValue) { return CallMemberFunction<CUserDATA, int, short>(0x10006EA0, this, nValue); }
int CUserDATA::AddCur_MP(short nValue) { return CallMemberFunction<CUserDATA, int, short>(0x10006F20, this, nValue); }
int CUserDATA::SubCur_HP(short nValue) { return CallMemberFunction<CUserDATA, int, short>(0x10006FA0, this, nValue); }
int CUserDATA::SubCur_MP(short nValue) { return CallMemberFunction<CUserDATA, int, short>(0x10006FF0, this, nValue); }
void CUserDATA::SetCur_FAME(char cValue) { return CallMemberFunction<CUserDATA, void, char>(0x100163B0, this, cValue); }
void CUserDATA::SetCur_UNION(char Var1) { return; }
void CUserDATA::SetCur_RANK(char Var1) { return; }
char CUserDATA::GetCur_FACE() { return CallMemberFunction<CUserDATA, char>(0x100127F0, this); }
void CUserDATA::SetCur_FACE(char cValue) { return CallMemberFunction<CUserDATA, void, char>(0x100125C0, this, cValue); }
char CUserDATA::GetCur_HAIR() { return CallMemberFunction<CUserDATA, char>(0x10012810, this); }
void CUserDATA::SetCur_HAIR(char cValue) { return CallMemberFunction<CUserDATA, void, char>(0x100125E0, this, cValue); }
void CUserDATA::SetCur_JOB(short nValue) { return CallMemberFunction<CUserDATA, void, short>(0x10012830, this, nValue); }
void CUserDATA::SetCur_LEVEL(unsigned short wValue) { return CallMemberFunction<CUserDATA, void, unsigned short>(0x100105C0, this, wValue); }
void CUserDATA::SetCur_EXP(long lValue) { return CallMemberFunction<CUserDATA, void, long>(0x10010610, this, lValue); }
void CUserDATA::SetCur_BonusPOINT(short nValue) { return CallMemberFunction<CUserDATA, void, short>(0x10003D10, this, nValue); }
void CUserDATA::SetCur_SkillPOINT(short nValue) { return CallMemberFunction<CUserDATA, void, short>(0x10012600, this, nValue); }
tagITEM CUserDATA::Get_EquipITEM(unsigned short wEquipIDX) { return CallMemberFunction<CUserDATA, tagITEM, unsigned short>(0x10012620, this, wEquipIDX); }
tagITEM* CUserDATA::Get_EquipItemPTR(unsigned short wEquipIDX) { return CallMemberFunction<CUserDATA, tagITEM*, unsigned short>(0x10012670, this, wEquipIDX); }
tagITEM CUserDATA::Get_InventoryITEM(t_InvTYPE Var1, unsigned short Var2) { return tagITEM(); }
tagITEM CUserDATA::Get_InventoryITEM(unsigned short wTotalListIndex) { return CallMemberFunction<CUserDATA, tagITEM, unsigned short>(0x100126A0, this, wTotalListIndex); }
short CUserDATA::Add_CatchITEM(short nListRealNO, tagITEM& sITEM) { return CallMemberFunction<CUserDATA, short, short, tagITEM&>(0x10073A30, this, nListRealNO, sITEM); }
short CUserDATA::Add_ITEM(short nListRealNO, tagITEM& sITEM) { return CallMemberFunction<CUserDATA, short, short, tagITEM&>(0x10073AB0, this, nListRealNO, sITEM); }
short CUserDATA::Add_ITEM(tagITEM& sITEM) { return CallMemberFunction<CUserDATA, short, tagITEM&>(0x10007040, this, sITEM); }
void CUserDATA::Sub_ITEM(short nListRealNO, tagITEM& sITEM) { return CallMemberFunction<CUserDATA, void, short, tagITEM&>(0x10073A70, this, nListRealNO, sITEM); }
void CUserDATA::Set_ITEM(short nListRealNO, tagITEM& sITEM) { return CallMemberFunction<CUserDATA, void, short, tagITEM&>(0x10073AF0, this, nListRealNO, sITEM); }
void CUserDATA::ClearITEM(unsigned short wListRealNO) { return CallMemberFunction<CUserDATA, void, unsigned short>(0x10010630, this, wListRealNO); }
void CUserDATA::SetCur_SEX(char Var1) { return; }
short CUserDATA::GetCur_RACE() { return 0; }
short CUserDATA::GetCur_ATK_SPD() { return 0; }
float CUserDATA::GetCur_MOVE_SPEED() { return 0; }
int CUserDATA::GetCur_ATK() { return 0; }
int CUserDATA::GetCur_DEF() { return 0; }
int CUserDATA::GetCur_RES() { return 0; }
int CUserDATA::GetCur_HIT() { return 0; }
int CUserDATA::GetCur_AVOID() { return 0; }
int CUserDATA::GetCur_CRITICAL() { return 0; }
int CUserDATA::GetCur_MaxHP() { return 0; }
int CUserDATA::GetCur_MaxMP() { return 0; }
void CUserDATA::UpdateCur_Ability() { return; }
unsigned char CUserDATA::GetCur_MOVE_MODE() { return CallMemberFunction<CUserDATA, unsigned char>(0x10012850, this); }
int CUserDATA::GetCur_FUEL() { return 0; }
void CUserDATA::SubCur_FUEL(short Var1) { return; }
void CUserDATA::SetCur_TeamNO(int Var1) { return; }
void CUserDATA::SetCur_PK_FLAG(short nValue) { return CallMemberFunction<CUserDATA, void, short>(0x100126F0, this, nValue); }
short CUserDATA::GetCur_PK_FLAG() { return CallMemberFunction<CUserDATA, short>(0x10012870, this); }
short CUserDATA::GetCur_STAMINA() { return CallMemberFunction<CUserDATA, short>(0x1000E1D0, this); }
void CUserDATA::SetCur_STAMINA(short nValue) { return CallMemberFunction<CUserDATA, void, short>(0x1000E1F0, this, nValue); }
void CUserDATA::AddCur_STAMINA(short nValue) { return CallMemberFunction<CUserDATA, void, short>(0x10007080, this, nValue); }
void CUserDATA::AddCur_EXP(int Var0) { return CallMemberFunction<CUserDATA, void, int>(0x10012890, this, Var0); }
void CUserDATA::AddCur_BonusPOINT(short nValue) { return CallMemberFunction<CUserDATA, void, short>(0x10003D30, this, nValue); }
void CUserDATA::AddCur_SkillPOINT(short nValue) { return CallMemberFunction<CUserDATA, void, short>(0x10003D60, this, nValue); }
void CUserDATA::SubCur_BounsPOINT(short Var1) { return; }
void CUserDATA::SubCur_SkillPOINT(short Var1) { return; }
bool CUserDATA::Set_AbilityValue(unsigned short nType, int iValue) { return CallMemberFunction<CUserDATA, bool, unsigned short, int>(0x100717C0, this, nType, iValue); }
void CUserDATA::Add_AbilityValue(unsigned short wType, int iValue) { return CallMemberFunction<CUserDATA, void, unsigned short, int>(0x10071540, this, wType, iValue); }
int CUserDATA::GetCur_SummonCNT() { return 0; }
int CUserDATA::GetCur_AbilityValue(unsigned short Var1) { return 0; }
bool CUserDATA::Use_ITEM(unsigned short Var1) { return 0; }
bool CUserDATA::Set_EquipITEM(short nEquipIDX, tagITEM& sITEM) { return CallMemberFunction<CUserDATA, bool, short, tagITEM&>(0x10074330, this, nEquipIDX, sITEM); }
bool CUserDATA::Check_PatEquipCondition(tagITEM& sITEM, short nEquipIdx) { return CallMemberFunction<CUserDATA, bool, tagITEM&, short>(0x10071370, this, sITEM, nEquipIdx); }
bool CUserDATA::Check_EquipCondition(tagITEM& sITEM, short nEquipIdx) { return CallMemberFunction<CUserDATA, bool, tagITEM&, short>(0x10072600, this, sITEM, nEquipIdx); }
bool CUserDATA::Check_JobCollection(short nClassStbIDX) { return CallMemberFunction<CUserDATA, bool, short>(0x10071480, this, nClassStbIDX); }
void CUserDATA::SetCur_PartITEM(short Var1, tagITEM& Var2) { return; }
short CUserDATA::GetCur_PartITEM(short Var1) { return 0; }
int CUserDATA::Get_NeedEXP(int iLevel) { return CallMemberFunction<CUserDATA, int, int>(0x10010670, this, iLevel); }
short CUserDATA::Get_NeedPoint2AbilityUP(short BasicAbilityType) { return CallMemberFunction<CUserDATA, short, short>(0x100106A0, this, BasicAbilityType); }
short CUserDATA::Get_NeedPoint2SkillUP(short nSkillSLOT) { return CallMemberFunction<CUserDATA, short, short>(0x10070BE0, this, nSkillSLOT); }
int CUserDATA::GetCur_R_WEAPON() { return 0; }
int CUserDATA::GetCur_L_WEAPON() { return 0; }
int CUserDATA::GetCur_PET_BODY() { return 0; }
unsigned long CUserDATA::GetCur_IngStatusFLAG() { return 0; }
short CUserDATA::Skill_FindEmptySlot(short nSkillIDX) { return CallMemberFunction<CUserDATA, short, short>(0x10070690, this, nSkillIDX); }
short CUserDATA::Skill_FindLearnedLevel(short nSkillIDX) { return CallMemberFunction<CUserDATA, short, short>(0x10070620, this, nSkillIDX); }
short CUserDATA::Skill_FindLearnedSlot(short nSkillIDX) { return CallMemberFunction<CUserDATA, short, short>(0x10070550, this, nSkillIDX); }
int CUserDATA::Skill_GetAbilityValue(short nAbilityType) { return CallMemberFunction<CUserDATA, int, short>(0x100722A0, this, nAbilityType); }
int CUserDATA::Skill_ToUseAbilityVALUE(short nSkillIDX, short nPropertyIDX) { return CallMemberFunction<CUserDATA, int, short, short>(0x100712F0, this, nSkillIDX, nPropertyIDX); }
bool CUserDATA::Skill_UseAbilityValue(short nSkillIDX) { return CallMemberFunction<CUserDATA, bool, short>(0x10072450, this, nSkillIDX); }
bool CUserDATA::Skill_CheckJOB(short nSkillIDX) { return CallMemberFunction<CUserDATA, bool, short>(0x100721D0, this, nSkillIDX); }
bool CUserDATA::Skill_CheckLearnedSKILL(short nSkillIDX) { return CallMemberFunction<CUserDATA, bool, short>(0x10071220, this, nSkillIDX); }
bool CUserDATA::Skill_CheckNeedABILITY(short nSkillIDX) { return CallMemberFunction<CUserDATA, bool, short>(0x10074250, this, nSkillIDX); }
unsigned char CUserDATA::Skill_LearnCondition(short nSkillIDX) { return CallMemberFunction<CUserDATA, unsigned char, short>(0x10077950, this, nSkillIDX); }
unsigned char CUserDATA::Skill_LevelUpCondition(short nCurLevelSkillIDX, short nNextLevelSkillIDX) { return CallMemberFunction<CUserDATA, unsigned char, short, short>(0x10077860, this, nCurLevelSkillIDX, nNextLevelSkillIDX); }
bool CUserDATA::Skill_ActionCondition(short nSkillIDX) { return CallMemberFunction<CUserDATA, bool, short>(0x10073FC0, this, nSkillIDX); }
unsigned char CUserDATA::Skill_LEARN(short nSkillSLOT, short nSkillIDX, bool bSubPOINT) { return CallMemberFunction<CUserDATA, unsigned char, short, short, bool>(0x10077220, this, nSkillSLOT, nSkillIDX, bSubPOINT); }
bool CUserDATA::Skill_DELETE(short nSkillSLOT, short nSkillIDX) { return CallMemberFunction<CUserDATA, bool, short, short>(0x10070500, this, nSkillSLOT, nSkillIDX); }
void CUserDATA::InitPassiveSkill() { return CallMemberFunction<CUserDATA, void>(0x10070CD0, this); }
short CUserDATA::GetBuySkillVALUE() { return CallMemberFunction<CUserDATA, short>(0x10010720, this); }
short CUserDATA::GetSellSkillVALUE() { return CallMemberFunction<CUserDATA, short>(0x10010750, this); }
bool CUserDATA::Quest_IsPartyLEADER() { return 0; }
int CUserDATA::Quest_GetPartyLEVEL() { return 0; }
int CUserDATA::Quest_GetZoneNO() { return 0; }
int CUserDATA::Quest_DistanceFrom(int Var1, int Var2, int Var3) { return 0; }
int CUserDATA::Quest_PartyMemberCNT() { return 0; }
unsigned char CUserDATA::Quest_GetRegistered(int iQuestIDX) { return CallMemberFunction<CUserDATA, unsigned char, int>(0x10070B70, this, iQuestIDX); }
bool CUserDATA::Quest_Append(unsigned char btSlot, int iQuestIDX) { return CallMemberFunction<CUserDATA, bool, unsigned char, int>(0x100709C0, this, btSlot, iQuestIDX); }
short CUserDATA::Quest_Append(int iQuestIDX) { return CallMemberFunction<CUserDATA, short, int>(0x10070A50, this, iQuestIDX); }
bool CUserDATA::Quest_Delete(unsigned char btSLOT, int iQuestID) { return CallMemberFunction<CUserDATA, bool, unsigned char, int>(0x100708D0, this, btSLOT, iQuestID); }
bool CUserDATA::Quest_Delete(int iQuestIDX) { return CallMemberFunction<CUserDATA, bool, int>(0x10070940, this, iQuestIDX); }
tagITEM* CUserDATA::Quest_FindEquipITEM(unsigned short wEquipIDX) { return CallMemberFunction<CUserDATA, tagITEM*, unsigned short>(0x1000CC50, this, wEquipIDX); }
tagITEM* CUserDATA::Quest_FindITEM(tagITEM& sFindITEM) { return CallMemberFunction<CUserDATA, tagITEM*, tagITEM&>(0x1000CCA0, this, sFindITEM); }
bool CUserDATA::Quest_SubITEM(tagITEM& sSubITEM) { return CallMemberFunction<CUserDATA, bool, tagITEM&>(0x10073F60, this, sSubITEM); }
short CUserDATA::Quest_GetEpisodeVAR(unsigned short wVarIDX) { return CallMemberFunction<CUserDATA, short, unsigned short>(0x1000CD10, this, wVarIDX); }
short CUserDATA::Quest_GetJobVAR(unsigned short wVarIDX) { return CallMemberFunction<CUserDATA, short, unsigned short>(0x1000CD60, this, wVarIDX); }
short CUserDATA::Quest_GetUnionVAR(unsigned short wVarIDX) { return CallMemberFunction<CUserDATA, short, unsigned short>(0x1000CDB0, this, wVarIDX); }
short CUserDATA::Quest_GetPlanetVAR(unsigned short wVarIDX) { return CallMemberFunction<CUserDATA, short, unsigned short>(0x1000CE00, this, wVarIDX); }
void CUserDATA::Quest_SetEpisodeVAR(unsigned short wI, short nV) { return CallMemberFunction<CUserDATA, void, unsigned short, short>(0x1000CE40, this, wI, nV); }
void CUserDATA::Quest_SetJobVAR(unsigned short wI, short nV) { return CallMemberFunction<CUserDATA, void, unsigned short, short>(0x1000CE70, this, wI, nV); }
void CUserDATA::Quest_SetUnionVAR(unsigned short wI, short nV) { return CallMemberFunction<CUserDATA, void, unsigned short, short>(0x1000CEA0, this, wI, nV); }
void CUserDATA::Quest_SetPlanetVAR(unsigned short wI, short nV) { return CallMemberFunction<CUserDATA, void, unsigned short, short>(0x1000CED0, this, wI, nV); }
bool CUserDATA::Reward_WARP(int Var1, tPOINTF& Var2) { return 0; }
bool CUserDATA::Quest_CHANGE_SPEED() { return CallMemberFunction<CUserDATA, bool>(0x100128B0, this); }
bool CUserDATA::Add_MoneyNSend(int iAmount, unsigned short wType) { return CallMemberFunction<CUserDATA, bool, int, unsigned short>(0x100128D0, this, iAmount, wType); }
bool CUserDATA::Add_ExpNSend(int iExp) { return CallMemberFunction<CUserDATA, bool, int>(0x100128F0, this, iExp); }
bool CUserDATA::Add_ItemNSend(tagITEM& sITEM) { return CallMemberFunction<CUserDATA, bool, tagITEM&>(0x10012910, this, sITEM); }
bool CUserDATA::Add_SkillNSend(short nSkillIDX) { return CallMemberFunction<CUserDATA, bool, short>(0x10012930, this, nSkillIDX); }
bool CUserDATA::Sub_SkillNSend(short nSkillIDX) { return CallMemberFunction<CUserDATA, bool, short>(0x10012950, this, nSkillIDX); }
bool CUserDATA::Set_AbilityValueNSend(unsigned short nType, int iValue) { return CallMemberFunction<CUserDATA, bool, unsigned short, int>(0x10012970, this, nType, iValue); }
void CUserDATA::Add_AbilityValueNSend(unsigned short wType, int iValue) { return CallMemberFunction<CUserDATA, void, unsigned short, int>(0x10012990, this, wType, iValue); }
bool CUserDATA::Reward_InitSKILL() { return CallMemberFunction<CUserDATA, bool>(0x10073DD0, this); }
bool CUserDATA::Reward_InitSTATUS() { return CallMemberFunction<CUserDATA, bool>(0x10070760, this); }
bool CUserDATA::Reward_ITEM(tagITEM& sITEM, unsigned char btRewardToParty, unsigned char btQuestSLOT) { return CallMemberFunction<CUserDATA, bool, tagITEM&, unsigned char, unsigned char>(0x10072050, this, sITEM, btRewardToParty, btQuestSLOT); }
bool CUserDATA::Reward_ABILITY(bool bSetOrAdj, int iType, int iValue, unsigned char btRewardToParty) { return CallMemberFunction<CUserDATA, bool, bool, int, int, unsigned char>(0x10070480, this, bSetOrAdj, iType, iValue, btRewardToParty); }
bool CUserDATA::Reward_CalEXP(unsigned char btEquation, int iBaseValue, unsigned char btRewardToParty) { return CallMemberFunction<CUserDATA, bool, unsigned char, int, unsigned char>(0x10071FE0, this, btEquation, iBaseValue, btRewardToParty); }
bool CUserDATA::Reward_CalMONEY(unsigned char btEquation, int iBaseValue, unsigned char btRewardToParty, short nDupCNT) { return CallMemberFunction<CUserDATA, bool, unsigned char, int, unsigned char, short>(0x10071F60, this, btEquation, iBaseValue, btRewardToParty, nDupCNT); }
bool CUserDATA::Reward_CalITEM(unsigned char btEquation, int iBaseValue, unsigned char btRewardToParty, int iItemSN, short nItemOP, unsigned char btQuestSLOT) { return CallMemberFunction<CUserDATA, bool, unsigned char, int, unsigned char, int, short, unsigned char>(0x10073BA0, this, btEquation, iBaseValue, btRewardToParty, iItemSN, nItemOP, btQuestSLOT); }
void CUserDATA::Cal_AruaATTACK() { return; }
void CUserDATA::Cal_AruaHIT() { return; }
void CUserDATA::Cal_AruaAVOID() { return; }
void CUserDATA::Cal_AruaCRITICAL() { return; }
void CUserDATA::Cal_AruaMaxHP() { return; }
void CUserDATA::Cal_AruaMaxMP() { return; }
void CUserDATA::Cal_AruaRunSPD() { return; }
short CUserDATA::Get_WeightRATE() { return 0; }
void CUserDATA::Apply_2ndJob_Ability() { return CallMemberFunction<CUserDATA, void>(0x10070440, this); }
CUserDATA::CUserDATA(const CUserDATA& Var1) { }
CUserDATA::CUserDATA() {};



