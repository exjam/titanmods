#include "CRegenPOINT.h"

CRegenPOINT::CRegenPOINT(CZoneTHREAD* pZONE, float fXPos, float fYPos) {};
CRegenPOINT::~CRegenPOINT() {};
void CRegenPOINT::RegenCharacter(int iIndex, int iCount) { return CallMemberFunction<CRegenPOINT, void, int, int>(0x10016A00, this, iIndex, iCount); }
bool CRegenPOINT::Load(_iobuf* fp) { return CallMemberFunction<CRegenPOINT, bool, _iobuf*>(0x1004E6F0, this, fp); }
void CRegenPOINT::ClearCharacter(CObjCHAR* pCharOBJ) { return CallMemberFunction<CRegenPOINT, void, CObjCHAR*>(0x1004E6D0, this, pCharOBJ); }
void CRegenPOINT::Proc(unsigned long dwCurTIME) { return CallMemberFunction<CRegenPOINT, void, unsigned long>(0x1004EAE0, this, dwCurTIME); }
void CRegenPOINT::AddLiveCNT() { return CallMemberFunction<CRegenPOINT, void>(0x10014D90, this); }
void CRegenPOINT::SubLiveCNT() { return CallMemberFunction<CRegenPOINT, void>(0x10014DC0, this); }
int CRegenPOINT::GetLiveCNT() { return CallMemberFunction<CRegenPOINT, int>(0x10016420, this); }
void CRegenPOINT::Reset() { return CallMemberFunction<CRegenPOINT, void>(0x10014DF0, this); }



