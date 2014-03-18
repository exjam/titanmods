#include "CObjTARGET.h"

CAI_OBJ* CObjTARGET::Get_TargetOBJ(bool bCheckHP) { return CallMemberFunction<CObjTARGET, CAI_OBJ*, bool>(0x10078B30, this, bCheckHP); }
int CObjTARGET::Get_TargetIDX() { return CallMemberFunction<CObjTARGET, int>(0x10011DC0, this); }
void CObjTARGET::Set_TargetIDX(int iTargetIndex, bool bHP) { return CallMemberFunction<CObjTARGET, void, int, bool>(0x10007310, this, iTargetIndex, bHP); }
CZoneTHREAD* CObjTARGET::GetCur_ZONE() { return 0; }
CObjTARGET::CObjTARGET() {};



