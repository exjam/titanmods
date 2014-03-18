#include "CObjITEM.h"

CObjITEM::~CObjITEM() {};
t_ObjTAG CObjITEM::Get_TYPE() { return CallMemberFunction<CObjITEM, t_ObjTAG>(0x10010840, this); }
void CObjITEM::InitItemOBJ(classUSER* pDropper, CVec2& PosCUR, tagPOINTS& PosSEC, tagITEM& sITEM, classUSER* pOwner, bool bActive, CParty* pOwnerPARTY) { return CallMemberFunction<CObjITEM, void, classUSER*, CVec2&, tagPOINTS&, tagITEM&, classUSER*, bool, CParty*>(0x10058540, this, pDropper, PosCUR, PosSEC, sITEM, pOwner, bActive, pOwnerPARTY); }
void CObjITEM::SetACTIVE() { return CallMemberFunction<CObjITEM, void>(0x10058410, this); }
void CObjITEM::Update_OwnerObjIDX(classUSER* pUSER) { return CallMemberFunction<CObjITEM, void, classUSER*>(0x100584F0, this, pUSER); }
bool CObjITEM::Make_gsv_ADD_OBJECT(classPACKET* pCPacket) { return CallMemberFunction<CObjITEM, bool, classPACKET*>(0x10058450, this, pCPacket); }
bool CObjITEM::Is_FREE() { return CallMemberFunction<CObjITEM, bool>(0x10010860, this); }
bool CObjITEM::Check_PrivateRIGHT(int iTryObjIDX) { return CallMemberFunction<CObjITEM, bool, int>(0x100108B0, this, iTryObjIDX); }
bool CObjITEM::Check_PartyRIGHT(CParty* pTryPARTY) { return CallMemberFunction<CObjITEM, bool, CParty*>(0x100108E0, this, pTryPARTY); }
int CObjITEM::Proc() { return CallMemberFunction<CObjITEM, int>(0x10058740, this); }
CObjITEM::CObjITEM() {};



