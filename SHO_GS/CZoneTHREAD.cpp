#include "CZoneTHREAD.h"

void CZoneTHREAD::DeleteZoneOBJ() { return CallMemberFunction<CZoneTHREAD, void>(0x10060DF0, this); }
void CZoneTHREAD::Proc_ZoneTRIGGER() { return CallMemberFunction<CZoneTHREAD, void>(0x10061200, this); }
CZoneTHREAD* CZoneTHREAD::GetZonePTR() { return CallMemberFunction<CZoneTHREAD, CZoneTHREAD*>(0x10014D70, this); }
bool CZoneTHREAD::Add_RegenPOINT(_iobuf* fp, float fPosX, float fPosY) { return CallMemberFunction<CZoneTHREAD, bool, _iobuf*, float, float>(0x1005ED80, this, fp, fPosX, fPosY); }
bool CZoneTHREAD::Load_Economy(_iobuf* fp) { return CallMemberFunction<CZoneTHREAD, bool, _iobuf*>(0x1005F010, this, fp); }
void CZoneTHREAD::Execute() { return CallMemberFunction<CZoneTHREAD, void>(0x10061360, this); }
CZoneTHREAD::CZoneTHREAD() { }
CZoneTHREAD::CZoneTHREAD(bool CreateSuspended) {};
CZoneTHREAD::~CZoneTHREAD() {};
int CZoneTHREAD::Get_UserCNT() { return CallMemberFunction<CZoneTHREAD, int>(0x10010FE0, this); }
void CZoneTHREAD::Inc_UserCNT() { return CallMemberFunction<CZoneTHREAD, void>(0x10011000, this); }
void CZoneTHREAD::Dec_UserCNT() { return CallMemberFunction<CZoneTHREAD, void>(0x100110E0, this); }
bool CZoneTHREAD::Add_OBJECT(CGameOBJ* pObj) { return CallMemberFunction<CZoneTHREAD, bool, CGameOBJ*>(0x1005F340, this, pObj); }
bool CZoneTHREAD::Add_DIRECT(CGameOBJ* pObj) { return CallMemberFunction<CZoneTHREAD, bool, CGameOBJ*>(0x10060540, this, pObj); }
void CZoneTHREAD::Sub_DIRECT(CGameOBJ* pObj, bool bSubFromREGEN) { return CallMemberFunction<CZoneTHREAD, void, CGameOBJ*, bool>(0x10060460, this, pObj, bSubFromREGEN); }
CZoneSECTOR* CZoneTHREAD::GetSECTOR(int iSectorX, int iSectorY) { return CallMemberFunction<CZoneTHREAD, CZoneSECTOR*, int, int>(0x1005F050, this, iSectorX, iSectorY); }
bool CZoneTHREAD::UpdateSECTOR(CObjCHAR* pCHAR) { return CallMemberFunction<CZoneTHREAD, bool, CObjCHAR*>(0x10060B00, this, pCHAR); }
CObjMOB* CZoneTHREAD::RegenMOB(float fCenterX, float fCenterY, int iRange, int iIndex, int iCount, int iTeamNO) { return CallMemberFunction<CZoneTHREAD, CObjMOB*, float, float, int, int, int, int>(0x1005FCE0, this, fCenterX, fCenterY, iRange, iIndex, iCount, iTeamNO); }
void CZoneTHREAD::RegenCharacter(CRegenPOINT* pRegen, int iIndex, int iCount) { return CallMemberFunction<CZoneTHREAD, void, CRegenPOINT*, int, int>(0x1005FB20, this, pRegen, iIndex, iCount); }
CObjMOB* CZoneTHREAD::RegenCharacter(float fCenterX, float fCenterY, int iRange, int iIndex, int iCount, int iTeamNO, bool bImmediate) { return CallMemberFunction<CZoneTHREAD, CObjMOB*, float, float, int, int, int, int, bool>(0x10060340, this, fCenterX, fCenterY, iRange, iIndex, iCount, iTeamNO, bImmediate); }
bool CZoneTHREAD::RegenCharacter(CObjMOB* pNewMOB, float fCenterX, float fCenterY, int iRange, int iIndex, int iTeamNO) { return CallMemberFunction<CZoneTHREAD, bool, CObjMOB*, float, float, int, int, int>(0x1005FE40, this, pNewMOB, fCenterX, fCenterY, iRange, iIndex, iTeamNO); }
void CZoneTHREAD::SendPacketToSectors(CGameOBJ* pGameObj, classPACKET* pCPacket) { return CallMemberFunction<CZoneTHREAD, void, CGameOBJ*, classPACKET*>(0x1005EF10, this, pGameObj, pCPacket); }
void CZoneTHREAD::SendTeamPacketToSectors(CGameOBJ* pGameObj, classPACKET* pCPacket, int iTeamNO) { return CallMemberFunction<CZoneTHREAD, void, CGameOBJ*, classPACKET*, int>(0x1005ED60, this, pGameObj, pCPacket, iTeamNO); }
bool CZoneTHREAD::AddObjectToSector(CGameOBJ* pObj, unsigned char btUpdateFLAG) { return CallMemberFunction<CZoneTHREAD, bool, CGameOBJ*, unsigned char>(0x10060110, this, pObj, btUpdateFLAG); }
void CZoneTHREAD::SubObjectFromSector(CGameOBJ* pObj, char cUpdateFLAG) { return CallMemberFunction<CZoneTHREAD, void, CGameOBJ*, char>(0x1005FF20, this, pObj, cUpdateFLAG); }
bool CZoneTHREAD::Init(char* szBaseDIR, short nZoneNO) { return CallMemberFunction<CZoneTHREAD, bool, char*, short>(0x10061950, this, szBaseDIR, nZoneNO); }
bool CZoneTHREAD::Free() { return CallMemberFunction<CZoneTHREAD, bool>(0x100605F0, this); }
int CZoneTHREAD::Get_ItemBuyPRICE(short nItemTYPE, short nItemNO, short nBuySkillVALUE) { return CallMemberFunction<CZoneTHREAD, int, short, short, short>(0x10011160, this, nItemTYPE, nItemNO, nBuySkillVALUE); }
int CZoneTHREAD::Get_ItemSellPRICE(tagITEM& sITEM, short nSellSkillVALUE) { return CallMemberFunction<CZoneTHREAD, int, tagITEM&, short>(0x100111A0, this, sITEM, nSellSkillVALUE); }
int CZoneTHREAD::Get_EconomyVAR(short nVarIDX) { return CallMemberFunction<CZoneTHREAD, int, short>(0x100144B0, this, nVarIDX); }
unsigned long CZoneTHREAD::GetPassTIME() { return CallMemberFunction<CZoneTHREAD, unsigned long>(0x100111E0, this); }
unsigned long CZoneTHREAD::GetCurrentTIME() { return CallMemberFunction<CZoneTHREAD, unsigned long>(0x1000E5E0, this); }
unsigned long CZoneTHREAD::GetTimeGetTIME() { return CallMemberFunction<CZoneTHREAD, unsigned long>(0x10011210, this); }
unsigned long CZoneTHREAD::GetCurAbsSEC() { return CallMemberFunction<CZoneTHREAD, unsigned long>(0x100144F0, this); }
unsigned long CZoneTHREAD::GetEconomyTIME() { return CallMemberFunction<CZoneTHREAD, unsigned long>(0x10011230, this); }
unsigned long CZoneTHREAD::GetGlobalFLAG() { return CallMemberFunction<CZoneTHREAD, unsigned long>(0x10011250, this); }
int CZoneTHREAD::GetGameObjCNT() { return CallMemberFunction<CZoneTHREAD, int>(0x100163F0, this); }
void CZoneTHREAD::BuyITEMs(tagITEM& sITEM) { return CallMemberFunction<CZoneTHREAD, void, tagITEM&>(0x10011270, this, sITEM); }
void CZoneTHREAD::SellITEMs(tagITEM* pITEM, int iQuantity) { return CallMemberFunction<CZoneTHREAD, void, tagITEM*, int>(0x100112A0, this, pITEM, iQuantity); }
bool CZoneTHREAD::SendShout(CGameOBJ* pGameOBJ, classPACKET* pCPacket, int iTeamNo) { return CallMemberFunction<CZoneTHREAD, bool, CGameOBJ*, classPACKET*, int>(0x1005F0E0, this, pGameOBJ, pCPacket, iTeamNo); }
bool CZoneTHREAD::SendPacketToZONE(t_PACKET* pSendPacket) { return CallMemberFunction<CZoneTHREAD, bool, t_PACKET*>(0x10060CD0, this, pSendPacket); }
void CZoneTHREAD::Send_EconomyDATA() { return CallMemberFunction<CZoneTHREAD, void>(0x10061110, this); }
void CZoneTHREAD::Send_GLOBAL_FLAG() { return CallMemberFunction<CZoneTHREAD, void>(0x10061080, this); }
unsigned long CZoneTHREAD::Toggle_PK_FLAG() { return CallMemberFunction<CZoneTHREAD, unsigned long>(0x100618E0, this); }
void CZoneTHREAD::Set_PK_FLAG(unsigned char btOnOff) { return CallMemberFunction<CZoneTHREAD, void, unsigned char>(0x10061B00, this, btOnOff); }
CObjCHAR* CZoneTHREAD::FindFirstCHAR(CObjCHAR* pCenterCHAR, int iDistance, CGameOBJ* pObjFINDER) { return CallMemberFunction<CZoneTHREAD, CObjCHAR*, CObjCHAR*, int, CGameOBJ*>(0x1005F9C0, this, pCenterCHAR, iDistance, pObjFINDER); }
CObjCHAR* CZoneTHREAD::FindFirstCHAR(CVec2& PosCENTER, int iDistance, CGameOBJ* pObjFINDER) { return CallMemberFunction<CZoneTHREAD, CObjCHAR*, CVec2&, int, CGameOBJ*>(0x1005FA40, this, PosCENTER, iDistance, pObjFINDER); }
CObjCHAR* CZoneTHREAD::FindNextCHAR() { return CallMemberFunction<CZoneTHREAD, CObjCHAR*>(0x1005F760, this); }
void CZoneTHREAD::Kill_AllMOB(classUSER* pUSER) { return CallMemberFunction<CZoneTHREAD, void, classUSER*>(0x100619B0, this, pUSER); }
bool CZoneTHREAD::Toggle_REGEN() { return CallMemberFunction<CZoneTHREAD, bool>(0x1000EE10, this); }
void CZoneTHREAD::Set_REGEN(bool bEnableRegen) { return CallMemberFunction<CZoneTHREAD, void, bool>(0x1000EE50, this, bEnableRegen); }
void CZoneTHREAD::Reset_REGEN() { return CallMemberFunction<CZoneTHREAD, void>(0x1005EEB0, this); }
short CZoneTHREAD::GetRegenPointCNT() { return CallMemberFunction<CZoneTHREAD, short>(0x1005ED30, this); }
short CZoneTHREAD::GetRegenPointMOB(short nIndex, classUSER* pUSER) { return CallMemberFunction<CZoneTHREAD, short, short, classUSER*>(0x10060930, this, nIndex, pUSER); }
CRegenPOINT* CZoneTHREAD::GetRegenPOINT(short nIndex) { return CallMemberFunction<CZoneTHREAD, CRegenPOINT*, short>(0x1005EC80, this, nIndex); }
short CZoneTHREAD::CallRegenPointMOB(short nIndex) { return CallMemberFunction<CZoneTHREAD, short, short>(0x10060790, this, nIndex); }
short CZoneTHREAD::GetNearstRegenPOINT(CVec2& PosCENTER) { return CallMemberFunction<CZoneTHREAD, short, CVec2&>(0x1005F670, this, PosCENTER); }
void CZoneTHREAD::Do_QuestTrigger(short nTeamNO, unsigned long HashKEY) { return CallMemberFunction<CZoneTHREAD, void, short, unsigned long>(0x1005EE40, this, nTeamNO, HashKEY); }



