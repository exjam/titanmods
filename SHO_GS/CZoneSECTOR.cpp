#include "CZoneSECTOR.h"

void CZoneSECTOR::LockSector() { return CallMemberFunction<CZoneSECTOR, void>(0x10016860, this); }
void CZoneSECTOR::UnlockSector() { return CallMemberFunction<CZoneSECTOR, void>(0x10016880, this); }
int CZoneSECTOR::GetSectorCount() { return CallStaticFunction<int>(0x10014D00); }
CZoneSECTOR::CZoneSECTOR(const CZoneSECTOR& Var1) { }
CZoneSECTOR::CZoneSECTOR() {};
CZoneSECTOR::~CZoneSECTOR() {};
void CZoneSECTOR::SetCenterPOS(int iCenterX, int iCenterY) { return CallMemberFunction<CZoneSECTOR, void, int, int>(0x1004F010, this, iCenterX, iCenterY); }
void CZoneSECTOR::InsToSEC(CGameOBJ* pObj) { return CallMemberFunction<CZoneSECTOR, void, CGameOBJ*>(0x1004F560, this, pObj); }
void CZoneSECTOR::DelFromSEC(CGameOBJ* pObj) { return CallMemberFunction<CZoneSECTOR, void, CGameOBJ*>(0x1004F510, this, pObj); }
classDLLNODE<CGameOBJ *>* CZoneSECTOR::FindFirstCHAR(CGameOBJ* Var1) { return 0; }
classDLLNODE<CGameOBJ *>* CZoneSECTOR::FindNextCHAR(classDLLNODE<CGameOBJ *>* Var1, CGameOBJ* Var2) { return 0; }
void CZoneSECTOR::SendPacketToSECTOR(classPACKET* Var1, CGameOBJ* Var2) { return 0; }
void CZoneSECTOR::SendTeamPacketToSECTOR(classPACKET* Var1, int Var2, CGameOBJ* Var3) { return 0; }
void CZoneSECTOR::SendAddUserPacket(classUSER* Var1, classPACKET* Var2) { return 0; }
void CZoneSECTOR::SendSubUserPacket(classUSER* Var1, classPACKET* Var2) { return 0; }



