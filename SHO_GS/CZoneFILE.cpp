#include "CZoneFILE.h"

void CZoneFILE::ReadObjINFO(_iobuf* fp, long lOffset, int iLumpType, short nMapXIDX, short nMapYIDX) { return CallMemberFunction<CZoneFILE, void, _iobuf*, long, int, short, short>(0x10062C50, this, fp, lOffset, iLumpType, nMapXIDX, nMapYIDX); }
char* CZoneFILE::GetMapFILE(short nMapX, short nMapY) { return CallMemberFunction<CZoneFILE, char*, short, short>(0x10061F10, this, nMapX, nMapY); }
void CZoneFILE::LoadMAP(char* szFileName, short nMapXIDX, short nMapYIDX) { return CallMemberFunction<CZoneFILE, void, char*, short, short>(0x10063560, this, szFileName, nMapXIDX, nMapYIDX); }
void CZoneFILE::LoadMOV(char* szFileName, short nMapXIDX, short nMapYIDX) { return CallMemberFunction<CZoneFILE, void, char*, short, short>(0x10061B50, this, szFileName, nMapXIDX, nMapYIDX); }
void CZoneFILE::ReadZoneINFO(_iobuf* fp, long lOffset) { return CallMemberFunction<CZoneFILE, void, _iobuf*, long>(0x10062110, this, fp, lOffset); }
void CZoneFILE::ReadEventObjINFO(_iobuf* fp, long lOffset) { return CallMemberFunction<CZoneFILE, void, _iobuf*, long>(0x10062830, this, fp, lOffset); }
bool CZoneFILE::ReadECONOMY(_iobuf* fp, long lOffset) { return CallMemberFunction<CZoneFILE, bool, _iobuf*, long>(0x10061FB0, this, fp, lOffset); }
short CZoneFILE::GridCountPerPatchAXIS() { return CallMemberFunction<CZoneFILE, short>(0x10014830, this); }
short CZoneFILE::nPatch_SIZE() { return 0; }
short CZoneFILE::nGrid_SIZE() { return CallMemberFunction<CZoneFILE, short>(0x10014850, this); }
CZoneTHREAD* CZoneFILE::GetZonePTR() { return 0; }
bool CZoneFILE::Add_RegenPOINT(_iobuf* Var1, float Var2, float Var3) { return 0; }
bool CZoneFILE::Load_Economy(_iobuf* Var1) { return 0; }
CZoneFILE::CZoneFILE() { }
CZoneFILE::CZoneFILE(bool CreateSuspended) {};
CZoneFILE::~CZoneFILE() {};
bool CZoneFILE::LoadZONE(char* szBaseDIR, short nZoneNO) { return CallMemberFunction<CZoneFILE, bool, char*, short>(0x10063720, this, szBaseDIR, nZoneNO); }
void CZoneFILE::FreeZONE() { return CallMemberFunction<CZoneFILE, void>(0x10061D10, this); }
short CZoneFILE::Get_SectorSIZE() { return CallMemberFunction<CZoneFILE, short>(0x10014D10, this); }
CVec2 CZoneFILE::Get_StartPOS() { return CallMemberFunction<CZoneFILE, CVec2>(0x1000E580, this); }
CVec2 CZoneFILE::Get_StartRevivePOS() { return CallMemberFunction<CZoneFILE, CVec2>(0x1000E5B0, this); }
CVec2 CZoneFILE::Get_RevivePOS(CVec2 PosCUR) { return CallMemberFunction<CZoneFILE, CVec2, CVec2>(0x100624D0, this, PosCUR); }
CVec2 CZoneFILE::Get_AgitPOS(unsigned long dwClanID) { return CallMemberFunction<CZoneFILE, CVec2, unsigned long>(0x10010F00, this, dwClanID); }
bool CZoneFILE::IsMovablePOS(int iXPos, int iYPos) { return CallMemberFunction<CZoneFILE, bool, int, int>(0x100042D0, this, iXPos, iYPos); }
unsigned char CZoneFILE::Is_DAY() { return CallMemberFunction<CZoneFILE, unsigned char>(0x10062BD0, this); }
char* CZoneFILE::Get_NAME() { return CallMemberFunction<CZoneFILE, char*>(0x10004340, this); }
short CZoneFILE::Get_ZoneNO() { return CallMemberFunction<CZoneFILE, short>(0x10004380, this); }
int CZoneFILE::Get_SectorXCNT() { return CallMemberFunction<CZoneFILE, int>(0x10014D30, this); }
int CZoneFILE::Get_SectorYCNT() { return CallMemberFunction<CZoneFILE, int>(0x10014D50, this); }
unsigned long CZoneFILE::Get_HashJoinTRIGGER() { return CallMemberFunction<CZoneFILE, unsigned long>(0x10010F40, this); }
unsigned long CZoneFILE::Get_HashKillTRIGGER() { return CallMemberFunction<CZoneFILE, unsigned long>(0x10010F60, this); }
unsigned long CZoneFILE::Get_HashDeadTRIGGER() { return CallMemberFunction<CZoneFILE, unsigned long>(0x10010F80, this); }
CStrVAR* CZoneFILE::GetStrVAR() { return CallMemberFunction<CZoneFILE, CStrVAR*>(0x10010FA0, this); }



