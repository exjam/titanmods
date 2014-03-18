#include "CObjSUMMON.h"

CObjSUMMON::CObjSUMMON() {};
int CObjSUMMON::Proc() { return CallMemberFunction<CObjSUMMON, int>(0x10058310, this); }
void CObjSUMMON::SetCallerOBJ(int iOwnerOBJ, unsigned long HashOwnerOBJ, int iOwnerLEVEL, short nSkillIDX, CObjCHAR* pOwnerAVT) { return CallMemberFunction<CObjSUMMON, void, int, unsigned long, int, short, CObjCHAR*>(0x10056E70, this, iOwnerOBJ, HashOwnerOBJ, iOwnerLEVEL, nSkillIDX, pOwnerAVT); }
int CObjSUMMON::GetCallerUsrIDX() { return CallMemberFunction<CObjSUMMON, int>(0x10014260, this); }
int CObjSUMMON::GetCallerObjIDX() { return CallMemberFunction<CObjSUMMON, int>(0x10014280, this); }
unsigned long CObjSUMMON::GetCallerHASH() { return CallMemberFunction<CObjSUMMON, unsigned long>(0x100142A0, this); }
short CObjSUMMON::GetSummonedSkillIDX() { return CallMemberFunction<CObjSUMMON, short>(0x100142C0, this); }
int CObjSUMMON::Get_LEVEL() { return CallMemberFunction<CObjSUMMON, int>(0x100142E0, this); }
int CObjSUMMON::GetOri_ATK() { return CallMemberFunction<CObjSUMMON, int>(0x10014300, this); }
int CObjSUMMON::GetOri_HIT() { return CallMemberFunction<CObjSUMMON, int>(0x10014320, this); }
int CObjSUMMON::GetOri_DEF() { return CallMemberFunction<CObjSUMMON, int>(0x10014340, this); }
int CObjSUMMON::GetOri_RES() { return CallMemberFunction<CObjSUMMON, int>(0x10014360, this); }
int CObjSUMMON::GetOri_AVOID() { return CallMemberFunction<CObjSUMMON, int>(0x10014380, this); }
CObjSUMMON::~CObjSUMMON() {};



