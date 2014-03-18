#include "CObjMNG.h"

CObjMNG::CObjMNG(int iMaxGameObject) {};
CObjMNG::~CObjMNG() {};
CGameOBJ* CObjMNG::Get_OBJECT(unsigned short wIndex) { return CallMemberFunction<CObjMNG, CGameOBJ*, unsigned short>(0x1009D910, this, wIndex); }
CObjCHAR* CObjMNG::Get_CharOBJ(unsigned short wIndex, bool bCheckHP) { return CallMemberFunction<CObjMNG, CObjCHAR*, unsigned short, bool>(0x1009D9C0, this, wIndex, bCheckHP); }
CObjITEM* CObjMNG::Get_ItemOBJ(unsigned short wIndex) { return CallMemberFunction<CObjMNG, CObjITEM*, unsigned short>(0x1009D960, this, wIndex); }
classUSER* CObjMNG::Get_UserOBJ(unsigned long dwIndex) { return CallMemberFunction<CObjMNG, classUSER*, unsigned long>(0x1009DA40, this, dwIndex); }
CGameOBJ* CObjMNG::Get_GameOBJ(unsigned short wIndex, t_ObjTAG ObjTYPE) { return CallMemberFunction<CObjMNG, CGameOBJ*, unsigned short, t_ObjTAG>(0x1009DAC0, this, wIndex, ObjTYPE); }
CGameOBJ* CObjMNG::Get_ClientOBJECT(unsigned short wIndex) { return CallMemberFunction<CObjMNG, CGameOBJ*, unsigned short>(0x100120E0, this, wIndex); }
CObjCHAR* CObjMNG::Get_ClientCharOBJ(unsigned short wIndex, bool bCheckHP) { return CallMemberFunction<CObjMNG, CObjCHAR*, unsigned short, bool>(0x10010EB0, this, wIndex, bCheckHP); }
int CObjMNG::Get_ClientObjectIndex(int iServerObject) { return CallMemberFunction<CObjMNG, int, int>(0x10012110, this, iServerObject); }



