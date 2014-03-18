#include "CGameOBJ.h"


CGameOBJ::CGameOBJ() {};
CGameOBJ::~CGameOBJ() {};
void CGameOBJ::Init_GameOBJ() { return CallMemberFunction<CGameOBJ, void>(0x10067E00, this); }
t_ObjTAG CGameOBJ::Get_TYPE() { return CallMemberFunction<CGameOBJ, t_ObjTAG>(0x10011AD0, this); }
char* CGameOBJ::Get_NAME() { return CallMemberFunction<CGameOBJ, char*>(0x100107A0, this); }
int CGameOBJ::Proc() { return CallMemberFunction<CGameOBJ, int>(0x10011AF0, this); }
int CGameOBJ::Get_TEAM() { return CallMemberFunction<CGameOBJ, int>(0x100107C0, this); }
int CGameOBJ::Get_INDEX() { return CallMemberFunction<CGameOBJ, int>(0x100070E0, this); }
void CGameOBJ::ResetSECTOR(short nSectorSize) { return CallMemberFunction<CGameOBJ, void, short>(0x10067DA0, this, nSectorSize); }
bool CGameOBJ::IsA(t_ObjTAG Obj_TYPE) { return CallMemberFunction<CGameOBJ, bool, t_ObjTAG>(0x1000C490, this, Obj_TYPE); }
bool CGameOBJ::IsITEM() { return CallMemberFunction<CGameOBJ, bool>(0x1000C4D0, this); }
bool CGameOBJ::IsCNST() { return 0; }
bool CGameOBJ::IsNPC() { return CallMemberFunction<CGameOBJ, bool>(0x100130A0, this); }
bool CGameOBJ::IsCHAR() { return CallMemberFunction<CGameOBJ, bool>(0x1000C510, this); }
bool CGameOBJ::IsUSER() { return CallMemberFunction<CGameOBJ, bool>(0x1000C550, this); }
bool CGameOBJ::IsNEIGHBOR(CGameOBJ* pObj) { return CallMemberFunction<CGameOBJ, bool, CGameOBJ*>(0x10013110, this, pObj); }
CZoneTHREAD* CGameOBJ::GetZONE() { return CallMemberFunction<CGameOBJ, CZoneTHREAD*>(0x10004020, this); }
void CGameOBJ::SetZONE(CZoneTHREAD* pZONE) { return CallMemberFunction<CGameOBJ, void, CZoneTHREAD*>(0x10014B90, this, pZONE); }
int CGameOBJ::GetCur_ZoneTIME() { return CallMemberFunction<CGameOBJ, int>(0x10067F80, this); }
int CGameOBJ::GetCur_WorldTIME() { return CallMemberFunction<CGameOBJ, int>(0x10067F50, this); }
void CGameOBJ::Set_TargetObjIDX(int __formal) { return CallMemberFunction<CGameOBJ, void, int>(0x100107E0, this, __formal); }
bool CGameOBJ::SendPacket(classPACKET* __formal) { return CallMemberFunction<CGameOBJ, bool, classPACKET*>(0x10010800, this, __formal); }
bool CGameOBJ::Send_gsv_JOIN_ZONE(CZoneTHREAD* __formal) { return CallMemberFunction<CGameOBJ, bool, CZoneTHREAD*>(0x10010820, this, __formal); }
void CGameOBJ::Update_OwnerObjIDX(classUSER* __formal) { return CallMemberFunction<CGameOBJ, void, classUSER*>(0x10007100, this, __formal); }
bool CGameOBJ::Make_gsv_ADD_OBJECT(classPACKET* Var1) { return 0; }
bool CGameOBJ::Make_gsv_SUB_OBJECT(classPACKET* pCPacket) { return CallMemberFunction<CGameOBJ, bool, classPACKET*>(0x10067E90, this, pCPacket); }



