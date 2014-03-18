#include "CWorldVAR.h"

CWorldVAR::CWorldVAR() {};
void CWorldVAR::Inc_WorldTIME(bool bWorldServer) { return CallMemberFunction<CWorldVAR, void, bool>(0x10001D20, this, bWorldServer); }
void CWorldVAR::Reset_WorldVAR(unsigned char* pVAR) { return CallMemberFunction<CWorldVAR, void, unsigned char*>(0x100043A0, this, pVAR); }
int CWorldVAR::Get_WorldVAR(short nVarIDX) { return CallMemberFunction<CWorldVAR, int, short>(0x10001E00, this, nVarIDX); }
void CWorldVAR::Set_WorldVAR(short nVarIDX, short nValue) { return CallMemberFunction<CWorldVAR, void, short, short>(0x10004480, this, nVarIDX, nValue); }
bool CWorldVAR::Save_WorldVAR() { return CallMemberFunction<CWorldVAR, bool>(0x1000EF00, this); }



