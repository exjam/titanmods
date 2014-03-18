#include "CObjAVT.h"

t_ObjTAG CObjAVT::Get_TYPE() { return CallMemberFunction<CObjAVT, t_ObjTAG>(0x10008590, this); }
char* CObjAVT::Get_NAME() { return CallMemberFunction<CObjAVT, char*>(0x100085B0, this); }
bool CObjAVT::Make_gsv_ADD_OBJECT(classPACKET* pCPacket) { return CallMemberFunction<CObjAVT, bool, classPACKET*>(0x1006D750, this, pCPacket); }
short CObjAVT::GetCur_ATK_SPD() { return CallMemberFunction<CObjAVT, short>(0x100085E0, this); }
float CObjAVT::GetCur_MOVE_SPEED() { return CallMemberFunction<CObjAVT, float>(0x10008620, this); }
unsigned char CObjAVT::GetCur_MOVE_MODE() { return CallMemberFunction<CObjAVT, unsigned char>(0x10008660, this); }
unsigned char CObjAVT::GetCur_RIDE_MODE() { return CallMemberFunction<CObjAVT, unsigned char>(0x100086A0, this); }
short CObjAVT::GetCur_PartITEM(short nPartIdx) { return CallMemberFunction<CObjAVT, short, short>(0x100086C0, this, nPartIdx); }
void CObjAVT::SetCur_PartITEM(short nPartIdx, tagITEM& sITEM) { return CallMemberFunction<CObjAVT, void, short, tagITEM&>(0x10008700, this, nPartIdx, sITEM); }
int CObjAVT::GetCur_R_WEAPON() { return CallMemberFunction<CObjAVT, int>(0x10008740, this); }
int CObjAVT::GetCur_L_WEAPON() { return CallMemberFunction<CObjAVT, int>(0x10008780, this); }
int CObjAVT::GetCur_PET_BODY() { return CallMemberFunction<CObjAVT, int>(0x100087B0, this); }
unsigned long CObjAVT::GetCur_IngStatusFLAG() { return CallMemberFunction<CObjAVT, unsigned long>(0x100087E0, this); }
int CObjAVT::GetCur_AbilityValue(unsigned short nType) { return CallMemberFunction<CObjAVT, int, unsigned short>(0x10008820, this, nType); }
int CObjAVT::GetCur_MaxHP() { return CallMemberFunction<CObjAVT, int>(0x10008870, this); }
int CObjAVT::GetCur_MaxMP() { return CallMemberFunction<CObjAVT, int>(0x100088B0, this); }
int CObjAVT::GetCur_ATK() { return CallMemberFunction<CObjAVT, int>(0x100088F0, this); }
int CObjAVT::GetCur_DEF() { return CallMemberFunction<CObjAVT, int>(0x10008930, this); }
int CObjAVT::GetCur_RES() { return CallMemberFunction<CObjAVT, int>(0x10008970, this); }
int CObjAVT::GetCur_HIT() { return CallMemberFunction<CObjAVT, int>(0x100089B0, this); }
int CObjAVT::GetCur_AVOID() { return CallMemberFunction<CObjAVT, int>(0x100089F0, this); }
int CObjAVT::GetCur_CRITICAL() { return CallMemberFunction<CObjAVT, int>(0x10008A30, this); }
int CObjAVT::GetCur_FUEL() { return CallMemberFunction<CObjAVT, int>(0x1006CF20, this); }
void CObjAVT::SubCur_FUEL(short nValue) { return CallMemberFunction<CObjAVT, void, short>(0x1006CE50, this, nValue); }
short CObjAVT::GetCur_RACE() { return CallMemberFunction<CObjAVT, short>(0x10008A70, this); }
void CObjAVT::SetCur_SEX(char cValue) { return CallMemberFunction<CObjAVT, void, char>(0x1006C840, this, cValue); }
void CObjAVT::SetCur_TeamNO(int iTeamNO) { return CallMemberFunction<CObjAVT, void, int>(0x10008A90, this, iTeamNO); }
void CObjAVT::SetCur_UNION(char cValue) { return CallMemberFunction<CObjAVT, void, char>(0x1006C890, this, cValue); }
void CObjAVT::SetCur_JoHapPOINT(unsigned char btUnionIDX, short nValue) { return CallMemberFunction<CObjAVT, void, unsigned char, short>(0x1006C750, this, btUnionIDX, nValue); }
void CObjAVT::AddCur_EXP(int iExp) { return CallMemberFunction<CObjAVT, void, int>(0x10008AB0, this, iExp); }
void CObjAVT::UpdateCur_Ability() { return CallMemberFunction<CObjAVT, void>(0x10008B00, this); }
CAI_OBJ* CObjAVT::Get_CALLER() { return CallMemberFunction<CObjAVT, CAI_OBJ*>(0x10008B30, this); }
bool CObjAVT::Is_ALLIED(CAI_OBJ* pDestOBJ) { return CallMemberFunction<CObjAVT, bool, CAI_OBJ*>(0x1006C910, this, pDestOBJ); }
bool CObjAVT::SkillChk_ACTIVE(short nSkillIDX) { return CallMemberFunction<CObjAVT, bool, short>(0x10008B70, this, nSkillIDX); }
void CObjAVT::SkillUse_ABILITY(short nSkillIDX) { return CallMemberFunction<CObjAVT, void, short>(0x10008BE0, this, nSkillIDX); }
void CObjAVT::Recv_ITEM(short nItemNO, short iDupCnt) { return CallMemberFunction<CObjAVT, void, short, short>(0x10008C40, this, nItemNO, iDupCnt); }
int CObjAVT::Get_CON() { return CallMemberFunction<CObjAVT, int>(0x10008CF0, this); }
int CObjAVT::GetAdd_RecoverHP() { return CallMemberFunction<CObjAVT, int>(0x10008D20, this); }
int CObjAVT::GetAdd_RecoverMP() { return CallMemberFunction<CObjAVT, int>(0x10008D40, this); }
void CObjAVT::Check_PerFRAME(unsigned long dwPassTIME) { return CallMemberFunction<CObjAVT, void, unsigned long>(0x1006F1B0, this, dwPassTIME); }
short CObjAVT::Get_WeightRATE() { return CallMemberFunction<CObjAVT, short>(0x10008D60, this); }
int CObjAVT::GetANI_Stop() { return CallMemberFunction<CObjAVT, int>(0x10008D80, this); }
int CObjAVT::GetANI_Move() { return CallMemberFunction<CObjAVT, int>(0x10008DD0, this); }
int CObjAVT::GetANI_Attack() { return CallMemberFunction<CObjAVT, int>(0x10008E20, this); }
int CObjAVT::GetANI_Die() { return CallMemberFunction<CObjAVT, int>(0x10008E70, this); }
int CObjAVT::GetANI_Hit() { return CallMemberFunction<CObjAVT, int>(0x10008EC0, this); }
int CObjAVT::GetANI_Casting() { return CallMemberFunction<CObjAVT, int>(0x10008F10, this); }
int CObjAVT::GetANI_Skill() { return CallMemberFunction<CObjAVT, int>(0x10008FA0, this); }
int CObjAVT::GetANI_Sitting() { return CallMemberFunction<CObjAVT, int>(0x10009030, this); }
int CObjAVT::GetANI_Standing() { return CallMemberFunction<CObjAVT, int>(0x10009050, this); }
int CObjAVT::GetANI_Sit() { return CallMemberFunction<CObjAVT, int>(0x10009070, this); }
int CObjAVT::Get_R_WEAPON() { return CallMemberFunction<CObjAVT, int>(0x10009090, this); }
int CObjAVT::Get_L_WEAPON() { return CallMemberFunction<CObjAVT, int>(0x100090B0, this); }
int CObjAVT::Get_PET_BODY() { return CallMemberFunction<CObjAVT, int>(0x100090D0, this); }
int CObjAVT::Def_AttackRange() { return CallMemberFunction<CObjAVT, int>(0x100090F0, this); }
bool CObjAVT::SetCMD_TOGGLE(unsigned char btTYPE, bool bForce) { return CallMemberFunction<CObjAVT, bool, unsigned char, bool>(0x1006EBD0, this, btTYPE, bForce); }
short CObjAVT::Get_nAttackSPEED() { return CallMemberFunction<CObjAVT, short>(0x10009110, this); }
float CObjAVT::Get_MoveSPEED() { return CallMemberFunction<CObjAVT, float>(0x10009180, this); }
int CObjAVT::Get_AttackRange(short nSkillIDX) { return CallMemberFunction<CObjAVT, int, short>(0x1006CF80, this, nSkillIDX); }
bool CObjAVT::IsFemale() { return CallMemberFunction<CObjAVT, bool>(0x100091F0, this); }
short CObjAVT::IsMagicDAMAGE() { return CallMemberFunction<CObjAVT, short>(0x10009210, this); }
tagMOTION* CObjAVT::Get_MOTION(short nActionIdx) { return CallMemberFunction<CObjAVT, tagMOTION*, short>(0x1006DBC0, this, nActionIdx); }
short CObjAVT::Get_WEIGHT() { return CallMemberFunction<CObjAVT, short>(0x10009260, this); }
int CObjAVT::Get_LEVEL() { return CallMemberFunction<CObjAVT, int>(0x100092A0, this); }
int CObjAVT::Get_EXP() { return CallMemberFunction<CObjAVT, int>(0x100092D0, this); }
int CObjAVT::Get_JOB() { return CallMemberFunction<CObjAVT, int>(0x10009300, this); }
__int64 CObjAVT::Get_MONEY() { return CallMemberFunction<CObjAVT, __int64>(0x10009330, this); }
int CObjAVT::Get_INT() { return CallMemberFunction<CObjAVT, int>(0x10009360, this); }
int CObjAVT::Get_CHARM() { return CallMemberFunction<CObjAVT, int>(0x10009390, this); }
int CObjAVT::Get_SENSE() { return CallMemberFunction<CObjAVT, int>(0x100093C0, this); }
unsigned char CObjAVT::Get_MoveMODE() { return CallMemberFunction<CObjAVT, unsigned char>(0x100093F0, this); }
unsigned char CObjAVT::Get_RideMODE() { return CallMemberFunction<CObjAVT, unsigned char>(0x10009440, this); }
int CObjAVT::Get_GiveEXP() { return CallMemberFunction<CObjAVT, int>(0x10009460, this); }
int CObjAVT::Get_AbilityValue(unsigned short wType) { return CallMemberFunction<CObjAVT, int, unsigned short>(0x1006D110, this, wType); }
int CObjAVT::Get_HP() { return CallMemberFunction<CObjAVT, int>(0x10009480, this); }
int CObjAVT::Get_MP() { return CallMemberFunction<CObjAVT, int>(0x100094B0, this); }
void CObjAVT::Set_HP(int iHP) { return CallMemberFunction<CObjAVT, void, int>(0x100094E0, this, iHP); }
void CObjAVT::Set_MP(int iMP) { return CallMemberFunction<CObjAVT, void, int>(0x10009520, this, iMP); }
int CObjAVT::Add_HP(int iValue) { return CallMemberFunction<CObjAVT, int, int>(0x10009560, this, iValue); }
int CObjAVT::Add_MP(int iValue) { return CallMemberFunction<CObjAVT, int, int>(0x100095A0, this, iValue); }
int CObjAVT::Sub_HP(int iValue) { return CallMemberFunction<CObjAVT, int, int>(0x100095E0, this, iValue); }
int CObjAVT::Sub_MP(int iValue) { return CallMemberFunction<CObjAVT, int, int>(0x10009620, this, iValue); }
void CObjAVT::Add_STAMINA(short nV) { return CallMemberFunction<CObjAVT, void, short>(0x10009660, this, nV); }
void CObjAVT::Add_MONEY(short nV) { return CallMemberFunction<CObjAVT, void, short>(0x100096A0, this, nV); }
void CObjAVT::Clear_SummonCNT() { return CallMemberFunction<CObjAVT, void>(0x100096E0, this); }
void CObjAVT::Add_SummonCNT(short nV) { return CallMemberFunction<CObjAVT, void, short>(0x10009700, this, nV); }
void CObjAVT::Sub_SummonCNT(short nV) { return CallMemberFunction<CObjAVT, void, short>(0x10009730, this, nV); }
short CObjAVT::Get_SummonCNT() { return CallMemberFunction<CObjAVT, short>(0x10009760, this); }
short CObjAVT::Max_SummonCNT() { return CallMemberFunction<CObjAVT, short>(0x10009780, this); }
int CObjAVT::GetCur_SummonCNT() { return CallMemberFunction<CObjAVT, int>(0x100097B0, this); }
short CObjAVT::GetOri_WalkSPEED() { return CallMemberFunction<CObjAVT, short>(0x100097D0, this); }
short CObjAVT::GetOri_RunSPEED() { return CallMemberFunction<CObjAVT, short>(0x100097F0, this); }
short CObjAVT::GetOri_ATKSPEED() { return CallMemberFunction<CObjAVT, short>(0x10009810, this); }
int CObjAVT::GetOri_ATK() { return CallMemberFunction<CObjAVT, int>(0x10009830, this); }
int CObjAVT::GetOri_DEF() { return CallMemberFunction<CObjAVT, int>(0x10009860, this); }
int CObjAVT::GetOri_RES() { return CallMemberFunction<CObjAVT, int>(0x10009890, this); }
int CObjAVT::GetOri_HIT() { return CallMemberFunction<CObjAVT, int>(0x100098C0, this); }
int CObjAVT::GetOri_AVOID() { return CallMemberFunction<CObjAVT, int>(0x100098F0, this); }
int CObjAVT::GetOri_CRITICAL() { return CallMemberFunction<CObjAVT, int>(0x10009920, this); }
int CObjAVT::GetOri_MaxHP() { return CallMemberFunction<CObjAVT, int>(0x10009950, this); }
int CObjAVT::GetOri_MaxMP() { return CallMemberFunction<CObjAVT, int>(0x10009980, this); }
int CObjAVT::Save_Damage(int iAttackerIDX, int iDamage) { return CallMemberFunction<CObjAVT, int, int, int>(0x1006E8A0, this, iAttackerIDX, iDamage); }
void CObjAVT::Dec_WeaponLife() { return CallMemberFunction<CObjAVT, void>(0x1006E6B0, this); }
void CObjAVT::Dec_EngineLife() { return CallMemberFunction<CObjAVT, void>(0x1006CCC0, this); }
void CObjAVT::Stamp_AttackTIME() { return CallMemberFunction<CObjAVT, void>(0x1006CE10, this); }
short CObjAVT::Get_PatHP_MODE() { return CallMemberFunction<CObjAVT, short>(0x100099B0, this); }
void CObjAVT::Set_PatHP_MODE(short nV) { return CallMemberFunction<CObjAVT, void, short>(0x100099D0, this, nV); }
void CObjAVT::ClanINIT(unsigned long dwClanID, int iClanPOS) { return CallMemberFunction<CObjAVT, void, unsigned long, int>(0x10004C90, this, dwClanID, iClanPOS); }
char* CObjAVT::GetClanNAME() { return CallMemberFunction<CObjAVT, char*>(0x10012D20, this); }
void CObjAVT::SetClanNAME(char* szName) { return CallMemberFunction<CObjAVT, void, char*>(0x10004D60, this, szName); }
unsigned long CObjAVT::GetClanID() { return CallMemberFunction<CObjAVT, unsigned long>(0x10004D90, this); }
void CObjAVT::SetClanID(unsigned long dwClanID) { return CallMemberFunction<CObjAVT, void, unsigned long>(0x10004DB0, this, dwClanID); }
unsigned long CObjAVT::GetClanMARK() { return 0; }
void CObjAVT::SetClanMARK(unsigned long dwMark) { return CallMemberFunction<CObjAVT, void, unsigned long>(0x10004DD0, this, dwMark); }
unsigned char CObjAVT::GetClanPOS() { return CallMemberFunction<CObjAVT, unsigned char>(0x10004DF0, this); }
void CObjAVT::SetClanPOS(int iPos) { return CallMemberFunction<CObjAVT, void, int>(0x10004E10, this, iPos); }
unsigned char CObjAVT::GetClanLEVEL() { return CallMemberFunction<CObjAVT, unsigned char>(0x1000CFA0, this); }
void CObjAVT::SetClanLEVEL(short nLev) { return CallMemberFunction<CObjAVT, void, short>(0x10004E30, this, nLev); }
int CObjAVT::GetClanSCORE() { return CallMemberFunction<CObjAVT, int>(0x1000CFC0, this); }
void CObjAVT::SetClanSCORE(int iScore) { return CallMemberFunction<CObjAVT, void, int>(0x10004E50, this, iScore); }
int CObjAVT::GetClanCONTRIBUTE() { return CallMemberFunction<CObjAVT, int>(0x1000CFE0, this); }
void CObjAVT::SetClanCONTRIBUTE(int iCon) { return CallMemberFunction<CObjAVT, void, int>(0x10004E70, this, iCon); }
__int64 CObjAVT::GetClanMONEY() { return CallMemberFunction<CObjAVT, __int64>(0x1000D000, this); }
void CObjAVT::SetClanMONEY(__int64 biM) { return CallMemberFunction<CObjAVT, void, __int64>(0x10004E90, this, biM); }
short CObjAVT::GetClanUserCNT() { return CallMemberFunction<CObjAVT, short>(0x1000D030, this); }
void CObjAVT::SetClanUserCNT(short nC) { return CallMemberFunction<CObjAVT, void, short>(0x10004EC0, this, nC); }
int CObjAVT::GetClanRATE() { return 0; }
void CObjAVT::SetClanRATE(int iR) { return CallMemberFunction<CObjAVT, void, int>(0x10004EF0, this, iR); }
bool CObjAVT::Is_ClanMASTER() { return CallMemberFunction<CObjAVT, bool>(0x10009A00, this); }
CObjAVT::CObjAVT() {};
CObjAVT::~CObjAVT() {};
void CObjAVT::Set_NAME(char* szName) { return CallMemberFunction<CObjAVT, void, char*>(0x10009A40, this, szName); }
void CObjAVT::Set_LEVEL(int iValue) { return CallMemberFunction<CObjAVT, void, int>(0x10010C90, this, iValue); }
tagITEM CObjAVT::Get_EquipITEM(short Var1) { return tagITEM(); }
short CObjAVT::GetPartITEM(short nPartIdx) { return CallMemberFunction<CObjAVT, short, short>(0x10009A70, this, nPartIdx); }
void CObjAVT::SetPartITEM(short nEquipInvIDX) { return CallMemberFunction<CObjAVT, void, short>(0x1006F120, this, nEquipInvIDX); }
void CObjAVT::SetPartITEM(short nPartIdx, tagITEM& sITEM) { return CallMemberFunction<CObjAVT, void, short, tagITEM&>(0x10009AA0, this, nPartIdx, sITEM); }
void CObjAVT::SetRideITEM(short nRideInvIDX) { return CallMemberFunction<CObjAVT, void, short>(0x1006EFA0, this, nRideInvIDX); }
short CObjAVT::GetPsv_ATKSPEED() { return CallMemberFunction<CObjAVT, short>(0x10009BC0, this); }
void CObjAVT::UpdateAbility() { return CallMemberFunction<CObjAVT, void>(0x10009BE0, this); }
void CObjAVT::Update_SPEED() { return CallMemberFunction<CObjAVT, void>(0x1006DEE0, this); }
void CObjAVT::Resurrection(short nSkillIDX) { return CallMemberFunction<CObjAVT, void, short>(0x1006E310, this, nSkillIDX); }
char* CObjAVT::Get_StoreTITLE() { return 0; }
bool CObjAVT::Send_gsv_HP_REPLY(int Var1, int Var2) { return 0; }
bool CObjAVT::Send_gsv_SET_ITEM_LIFE(short Var1, short Var2) { return 0; }
bool CObjAVT::Send_gsv_SPEED_CHANGED(bool Var1) { return 0; }
bool CObjAVT::Send_gsv_SETEXP(unsigned short Var1) { return 0; }
void CObjAVT::Set_TargetIDX(int iTargetIndex, bool bCheckHP) { return CallMemberFunction<CObjAVT, void, int, bool>(0x1006DD80, this, iTargetIndex, bCheckHP); }
void CObjAVT::Set_PenalEXP(unsigned char btAddPercent) { return CallMemberFunction<CObjAVT, void, unsigned char>(0x10010CD0, this, btAddPercent); }
void CObjAVT::Cancel_PenalEXP(unsigned char btPercent) { return CallMemberFunction<CObjAVT, void, unsigned char>(0x10012D50, this, btPercent); }
bool CObjAVT::Send_gsv_GODDNESS_MODE(unsigned char btOnOff) { return CallMemberFunction<CObjAVT, bool, unsigned char>(0x1006DCF0, this, btOnOff); }
bool CObjAVT::Add_Goddess() { return CallMemberFunction<CObjAVT, bool>(0x1006E570, this); }
bool CObjAVT::Del_Goddess() { return CallMemberFunction<CObjAVT, bool>(0x1006E450, this); }
void CObjAVT::Cal_AruaAtkSPD() { return CallMemberFunction<CObjAVT, void>(0x1006C820, this); }
void CObjAVT::Cal_AruaRunSPD() { return CallMemberFunction<CObjAVT, void>(0x1006CC30, this); }
void CObjAVT::Cal_AruaMaxHP() { return CallMemberFunction<CObjAVT, void>(0x1006CBA0, this); }
void CObjAVT::Cal_AruaMaxMP() { return CallMemberFunction<CObjAVT, void>(0x1006CB10, this); }
void CObjAVT::Cal_AruaATTACK() { return CallMemberFunction<CObjAVT, void>(0x1006CA80, this); }
void CObjAVT::Cal_AruaHIT() { return CallMemberFunction<CObjAVT, void>(0x1006C800, this); }
void CObjAVT::Cal_AruaAVOID() { return CallMemberFunction<CObjAVT, void>(0x1006C7E0, this); }
void CObjAVT::Cal_AruaCRITICAL() { return CallMemberFunction<CObjAVT, void>(0x1006C9F0, this); }
void CObjAVT::Cal_AruaRES() { return CallMemberFunction<CObjAVT, void>(0x1006C970, this); }
bool CObjAVT::Is_CartDriver() { return CallMemberFunction<CObjAVT, bool>(0x10009C90, this); }
bool CObjAVT::Is_CartGuest() { return CallMemberFunction<CObjAVT, bool>(0x10009CF0, this); }
void CObjAVT::UpdateCartGuest() { return CallMemberFunction<CObjAVT, void>(0x1006E240, this); }



