#include "CObjAI.h"

CZoneTHREAD* CObjAI::GetCur_ZONE() { return CallMemberFunction<CObjAI, CZoneTHREAD*>(0x10007330, this); }
bool CObjAI::IsInRANGE(CObjCHAR* Var1, int Var2) { return 0; }
void CObjAI::ActionEVENT(int Var1) { return; }
void CObjAI::Adjust_HEIGHT() { return; }
int CObjAI::GetCurrentFrame() { return 0; }
bool CObjAI::Set_MOTION(short Var1, float Var2, float Var3, bool Var4) { return 0; }
int CObjAI::GetANI_Stop() { return 0; }
int CObjAI::GetANI_Die() { return 0; }
int CObjAI::GetANI_Hit() { return 0; }
int CObjAI::GetANI_Move() { return 0; }
int CObjAI::GetANI_Attack() { return 0; }
int CObjAI::GetANI_Casting() { return 0; }
int CObjAI::GetANI_Skill() { return 0; }
int CObjAI::GetANI_Sitting() { return CallMemberFunction<CObjAI, int>(0x10011E10, this); }
int CObjAI::GetANI_Standing() { return CallMemberFunction<CObjAI, int>(0x10011E50, this); }
int CObjAI::GetANI_Sit() { return CallMemberFunction<CObjAI, int>(0x10011E90, this); }
int CObjAI::Def_AttackRange() { return 0; }
int CObjAI::Get_R_WEAPON() { return 0; }
bool CObjAI::Attack_START(CObjCHAR* Var1) { return 0; }
bool CObjAI::Skill_START(CObjCHAR* Var1) { return 0; }
bool CObjAI::Casting_START(CObjCHAR* Var1) { return 0; }
void CObjAI::Casting_END() { return; }
bool CObjAI::ToggleRunMODE() { return CallMemberFunction<CObjAI, bool>(0x10007360, this); }
bool CObjAI::ToggleSitMODE() { return CallMemberFunction<CObjAI, bool>(0x10007380, this); }
int CObjAI::Get_CON() { return CallMemberFunction<CObjAI, int>(0x10011ED0, this); }
int CObjAI::GetAdd_RecoverHP() { return CallMemberFunction<CObjAI, int>(0x10011EF0, this); }
int CObjAI::GetAdd_RecoverMP() { return CallMemberFunction<CObjAI, int>(0x10011F10, this); }
short CObjAI::GetPsv_ATKSPEED() { return CallMemberFunction<CObjAI, short>(0x10011F30, this); }
short CObjAI::Get_nAttackSPEED() { return 0; }
float CObjAI::Get_MoveSPEED() { return 0; }
int CObjAI::Get_AttackRange(short Var1) { return 0; }
float CObjAI::Get_SCALE() { return 0; }
int CObjAI::Get_HP() { return 0; }
int CObjAI::Get_MP() { return 0; }
int CObjAI::Get_MaxHP() { return 0; }
int CObjAI::Get_MaxMP() { return 0; }
short CObjAI::Get_WeightRATE() { return CallMemberFunction<CObjAI, short>(0x10011F50, this); }
unsigned long CObjAI::GetIngDurationStateFLAG() { return 0; }
short CObjAI::GetIngDurationStateSKILL(eING_TYPE Var1) { return 0; }
void CObjAI::Set_HP(int iHP) { return CallMemberFunction<CObjAI, void, int>(0x10011F70, this, iHP); }
void CObjAI::Set_MP(int iMP) { return CallMemberFunction<CObjAI, void, int>(0x10011F90, this, iMP); }
bool CObjAI::SetCMD_ATTACK(int iServerTarget) { return CallMemberFunction<CObjAI, bool, int>(0x10078820, this, iServerTarget); }
bool CObjAI::SkillChk_ACTIVE(short Var0) { return CallMemberFunction<CObjAI, bool, short>(0x10011FB0, this, Var0); }
void CObjAI::SkillUse_ABILITY(short Var0) { return CallMemberFunction<CObjAI, void, short>(0x10011FD0, this, Var0); }
bool CObjAI::SetCMD_SIT() { return CallMemberFunction<CObjAI, bool>(0x10077CD0, this); }
bool CObjAI::SetCMD_STAND() { return CallMemberFunction<CObjAI, bool>(0x10077C50, this); }
bool CObjAI::SetCMD_MOVE(CVec2& PosFROM, CVec2& PosTO, int iServerTarget) { return CallMemberFunction<CObjAI, bool, CVec2&, CVec2&, int>(0x10078D90, this, PosFROM, PosTO, iServerTarget); }
void CObjAI::SetCMD_DIE() { return CallMemberFunction<CObjAI, void>(0x10078030, this); }
bool CObjAI::SetCMD_Skill2SELF(short nSkillIDX) { return CallMemberFunction<CObjAI, bool, short>(0x10077B30, this, nSkillIDX); }
bool CObjAI::SetCMD_Skill2OBJ(int iServerTarget, short nSkillIDX) { return CallMemberFunction<CObjAI, bool, int, short>(0x10078600, this, iServerTarget, nSkillIDX); }
bool CObjAI::SetCMD_Skill2POS(CVec2& PosGOTO, short nSkillIDX) { return CallMemberFunction<CObjAI, bool, CVec2&, short>(0x10077F40, this, PosGOTO, nSkillIDX); }
void CObjAI::Do_CreatedAI() { return CallMemberFunction<CObjAI, void>(0x100073A0, this); }
void CObjAI::Do_StopAI() { return CallMemberFunction<CObjAI, void>(0x100073C0, this); }
void CObjAI::Do_AttackMoveAI(CObjCHAR* pTarget) { return CallMemberFunction<CObjAI, void, CObjCHAR*>(0x100073E0, this, pTarget); }
void CObjAI::Do_DamagedAI(CObjCHAR* pTarget, int iDamage) { return CallMemberFunction<CObjAI, void, CObjCHAR*, int>(0x10007400, this, pTarget, iDamage); }
void CObjAI::Do_KillAI(CObjCHAR* pTarget, int iDamage) { return CallMemberFunction<CObjAI, void, CObjCHAR*, int>(0x10007420, this, pTarget, iDamage); }
void CObjAI::Do_DeadAI(CObjCHAR* pTarget, int iDamage) { return CallMemberFunction<CObjAI, void, CObjCHAR*, int>(0x10007440, this, pTarget, iDamage); }
void CObjAI::Do_DeadEvent(CObjCHAR* pTarget) { return CallMemberFunction<CObjAI, void, CObjCHAR*>(0x10007460, this, pTarget); }
bool CObjAI::Is_SameTYPE(int iType) { return CallMemberFunction<CObjAI, bool, int>(0x10007480, this, iType); }
bool CObjAI::Is_TauntSTATUS(int Var1) { return 0; }
bool CObjAI::SetCMD_STOP() { return CallMemberFunction<CObjAI, bool>(0x10077BA0, this); }
bool CObjAI::SetCMD_MOVE2D(float fPosX, float fPosY, unsigned char btRunMODE) { return CallMemberFunction<CObjAI, bool, float, float, unsigned char>(0x10078EE0, this, fPosX, fPosY, btRunMODE); }
void CObjAI::SetCMD_RUNnATTACK(int iTargetObjTAG) { return CallMemberFunction<CObjAI, void, int>(0x100074C0, this, iTargetObjTAG); }
bool CObjAI::Send_gsv_SKILL_CANCEL(unsigned char Var1) { return 0; }
short CObjAI::Get_PatHP_MODE() { return CallMemberFunction<CObjAI, short>(0x10011FF0, this); }
void CObjAI::Set_PatHP_MODE(short nV) { return CallMemberFunction<CObjAI, void, short>(0x10012010, this, nV); }
bool CObjAI::Set_CurMOTION(tagMOTION* pMotion) { return CallMemberFunction<CObjAI, bool, tagMOTION*>(0x10077DA0, this, pMotion); }
bool CObjAI::Chg_CurMOTION(tagMOTION* pMotion) { return CallMemberFunction<CObjAI, bool, tagMOTION*>(0x10077D50, this, pMotion); }
void CObjAI::Start_MOVE(float fSpeed) { return CallMemberFunction<CObjAI, void, float>(0x10078BE0, this, fSpeed); }
void CObjAI::Restart_MOVE(CVec2& PosGOTO) { return CallMemberFunction<CObjAI, void, CVec2&>(0x10078F80, this, PosGOTO); }
void CObjAI::Start_ATTACK(CObjCHAR* pTarget) { return CallMemberFunction<CObjAI, void, CObjCHAR*>(0x10078370, this, pTarget); }
bool CObjAI::Is_Attack() { return 0; }
bool CObjAI::Is_Stop() { return CallMemberFunction<CObjAI, bool>(0x100109E0, this); }
char CObjAI::Do_SKILL(int iServerTarget, CObjCHAR* pTarget) { return CallMemberFunction<CObjAI, char, int, CObjCHAR*>(0x100780C0, this, iServerTarget, pTarget); }
bool CObjAI::Goto_TARGET(CObjCHAR* pTarget, int iRange) { return CallMemberFunction<CObjAI, bool, CObjCHAR*, int>(0x100790F0, this, pTarget, iRange); }
bool CObjAI::Goto_POSITION(int iRange) { return CallMemberFunction<CObjAI, bool, int>(0x10078CD0, this, iRange); }
int CObjAI::ProcCMD_SIT() { return CallMemberFunction<CObjAI, int>(0x10077EC0, this); }
int CObjAI::ProcCMD_STOP() { return CallMemberFunction<CObjAI, int>(0x10077E60, this); }
int CObjAI::ProcCMD_MOVE() { return CallMemberFunction<CObjAI, int>(0x10079520, this); }
int CObjAI::ProcCMD_PICK_ITEM() { return CallMemberFunction<CObjAI, int>(0x100790B0, this); }
int CObjAI::ProcCMD_ATTACK() { return CallMemberFunction<CObjAI, int>(0x10079310, this); }
int CObjAI::ProcCMD_Skill2SELF() { return CallMemberFunction<CObjAI, int>(0x100785B0, this); }
int CObjAI::ProcCMD_Skill2POSITION() { return CallMemberFunction<CObjAI, int>(0x10079020, this); }
int CObjAI::ProcCMD_Skill2OBJECT() { return CallMemberFunction<CObjAI, int>(0x10079160, this); }
short CObjAI::Get_RecoverHP(short nRecoverMODE) { return CallMemberFunction<CObjAI, short, short>(0x100129B0, this, nRecoverMODE); }
short CObjAI::Get_RecoverMP(short nRecoverMODE) { return CallMemberFunction<CObjAI, short, short>(0x10012A30, this, nRecoverMODE); }
short CObjAI::Get_ActiveSKILL() { return CallMemberFunction<CObjAI, short>(0x10004160, this); }
void CObjAI::Del_ActiveSKILL() { return CallMemberFunction<CObjAI, void>(0x10010A10, this); }
CObjAI::CObjAI() {};
CObjAI::~CObjAI() {};
bool CObjAI::ProcMotionFrame() { return CallMemberFunction<CObjAI, bool>(0x10077A20, this); }
void CObjAI::Set_STATE(unsigned short wState) { return CallMemberFunction<CObjAI, void, unsigned short>(0x10012030, this, wState); }
unsigned short CObjAI::Get_STATE() { return CallMemberFunction<CObjAI, unsigned short>(0x10012050, this); }
unsigned short CObjAI::Get_COMMAND() { return CallMemberFunction<CObjAI, unsigned short>(0x10012AB0, this); }
void CObjAI::Set_COMMAND(unsigned short wCommand) { return CallMemberFunction<CObjAI, void, unsigned short>(0x10010A40, this, wCommand); }
float CObjAI::Get_MoveAniSPEED() { return CallMemberFunction<CObjAI, float>(0x10012070, this); }
void CObjAI::Reset_MoveVEC() { return CallMemberFunction<CObjAI, void>(0x100789C0, this); }
float CObjAI::Cal_AtkAniSPEED(short nRightWeaponItemNO) { return CallMemberFunction<CObjAI, float, short>(0x10077DE0, this, nRightWeaponItemNO); }
float CObjAI::Cal_RunAniSPEED(short nCmPerSec) { return CallMemberFunction<CObjAI, float, short>(0x10012AD0, this, nCmPerSec); }
int CObjAI::Get_TAG() { return CallMemberFunction<CObjAI, int>(0x10007540, this); }
int CObjAI::Get_ObjTYPE() { return CallMemberFunction<CObjAI, int>(0x10007570, this); }
bool CObjAI::Is_AVATAR() { return CallMemberFunction<CObjAI, bool>(0x100120B0, this); }
int CObjAI::Get_PercentHP() { return CallMemberFunction<CObjAI, int>(0x100075B0, this); }
CAI_OBJ* CObjAI::Get_TARGET(bool bCheckHP) { return CallMemberFunction<CObjAI, CAI_OBJ*, bool>(0x10007650, this, bCheckHP); }
void CObjAI::Set_TargetObjIDX(int iTargetOBJ) { return CallMemberFunction<CObjAI, void, int>(0x10007680, this, iTargetOBJ); }



