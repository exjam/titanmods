#include "CZoneLIST.h"

CZoneLIST::CZoneLIST(const CZoneLIST& Var1) { }
CZoneLIST::CZoneLIST() {};
CZoneLIST::~CZoneLIST() {};
void CZoneLIST::Set_WorldVAR(short nVarIDX, short nValue) { return CallMemberFunction<CZoneLIST, void, short, short>(0x10092CB0, this, nVarIDX, nValue); }
void CZoneLIST::Add_LocalNPC(CObjNPC* pObjNPC) { return CallMemberFunction<CZoneLIST, void, CObjNPC*>(0x100923F0, this, pObjNPC); }
CObjNPC* CZoneLIST::Get_LocalNPC(int iNpcNO) { return CallMemberFunction<CZoneLIST, CObjNPC*, int>(0x10091CC0, this, iNpcNO); }
CObjVAR* CZoneLIST::Get_NpcVAR(int iNpcNO) { return CallMemberFunction<CZoneLIST, CObjVAR*, int>(0x1000D330, this, iNpcNO); }
void CZoneLIST::Add_EventOBJ(CObjEVENT* pObjEVENT) { return CallMemberFunction<CZoneLIST, void, CObjEVENT*>(0x10092370, this, pObjEVENT); }
CObjEVENT* CZoneLIST::Get_EventOBJ(short nZoneNO, unsigned long HashKEY) { return CallMemberFunction<CZoneLIST, CObjEVENT*, short, unsigned long>(0x100920E0, this, nZoneNO, HashKEY); }
void CZoneLIST::Init_NpcObjVAR(short nNpcIDX, unsigned char* pVAR) { return CallMemberFunction<CZoneLIST, void, short, unsigned char*>(0x10091C80, this, nNpcIDX, pVAR); }
void CZoneLIST::Init_EventObjVAR(unsigned long HashID, unsigned char* pVAR) { return CallMemberFunction<CZoneLIST, void, unsigned long, unsigned char*>(0x10091BE0, this, HashID, pVAR); }
bool CZoneLIST::InitZoneLIST(char* szBaseDIR) { return CallMemberFunction<CZoneLIST, bool, char*>(0x10092D00, this, szBaseDIR); }
void CZoneLIST::FreeZoneLIST() { return CallMemberFunction<CZoneLIST, void>(0x10092500, this); }
bool CZoneLIST::IsAgitZONE(short nZoneNO) { return CallMemberFunction<CZoneLIST, bool, short>(0x10091D10, this, nZoneNO); }
bool CZoneLIST::IsValidZONE(short nZoneNO) { return CallMemberFunction<CZoneLIST, bool, short>(0x1000EF20, this, nZoneNO); }
short CZoneLIST::GetZoneCNT() { return CallMemberFunction<CZoneLIST, short>(0x100112E0, this); }
short CZoneLIST::GetSectorSIZE(short nZoneNO) { return CallMemberFunction<CZoneLIST, short, short>(0x10011300, this, nZoneNO); }
CZoneTHREAD* CZoneLIST::GetZONE(short nZoneNO) { return CallMemberFunction<CZoneLIST, CZoneTHREAD*, short>(0x10091AD0, this, nZoneNO); }
tagEVENTPOS* CZoneLIST::Add_EventPOS(unsigned long HashKEY, short nZoneNO, char* szPosName, float fXPos, float fYPos) { return CallMemberFunction<CZoneLIST, tagEVENTPOS*, unsigned long, short, char*, float, float>(0x10091FE0, this, HashKEY, nZoneNO, szPosName, fXPos, fYPos); }
tagEVENTPOS* CZoneLIST::Get_EventPOS(short nZoneNO, char* szPosName) { return CallMemberFunction<CZoneLIST, tagEVENTPOS*, short, char*>(0x10091B20, this, nZoneNO, szPosName); }
void CZoneLIST::Send_gsv_ANNOUNCE_CHAT(t_PACKET* pSendPacket) { return CallMemberFunction<CZoneLIST, void, t_PACKET*>(0x100929E0, this, pSendPacket); }
void CZoneLIST::Send_gsv_ANNOUNCE_CHAT(char* szMessage, char* szAccount) { return CallMemberFunction<CZoneLIST, void, char*, char*>(0x10092A60, this, szMessage, szAccount); }
void CZoneLIST::Send_gsv_ANNOUNCE_CHAT(short nZoneNO, char* szMessage, char* szAccount) { return CallMemberFunction<CZoneLIST, void, short, char*, char*>(0x10092B50, this, nZoneNO, szMessage, szAccount); }
void CZoneLIST::Send_gsv_ANNOUNCE_CHAT(CObjVAR* pObjVAR, char* szMessage) { return CallMemberFunction<CZoneLIST, void, CObjVAR*, char*>(0x10092C50, this, pObjVAR, szMessage); }
void CZoneLIST::Set_PK_FLAG(CAI_OBJ* pChar, unsigned char btOnOff) { return CallMemberFunction<CZoneLIST, void, CAI_OBJ*, unsigned char>(0x10093060, this, pChar, btOnOff); }
void CZoneLIST::Set_PK_FLAG(short nZoneNO, unsigned char btOnOff) { return CallMemberFunction<CZoneLIST, void, short, unsigned char>(0x100930E0, this, nZoneNO, btOnOff); }
bool CZoneLIST::Do_QuestTrigger(short nZoneNO, short nTeamNO, unsigned long HashKEY) { return CallMemberFunction<CZoneLIST, bool, short, short, unsigned long>(0x10091F80, this, nZoneNO, nTeamNO, HashKEY); }
void CZoneLIST::Toggle_RegenSYSTEM(short nZoneNO) { return CallMemberFunction<CZoneLIST, void, short>(0x10091DC0, this, nZoneNO); }
void CZoneLIST::Toggle_RegenSYSTEM(CAI_OBJ* pChar) { return CallMemberFunction<CZoneLIST, void, CAI_OBJ*>(0x10091E80, this, pChar); }
void CZoneLIST::Toggle_RegenSYSTEM(CGameOBJ* pObj) { return CallMemberFunction<CZoneLIST, void, CGameOBJ*>(0x10091F40, this, pObj); }
void CZoneLIST::Set_RegenSYSTEM(short nZoneNO, unsigned char btOnOff) { return CallMemberFunction<CZoneLIST, void, short, unsigned char>(0x10091D70, this, nZoneNO, btOnOff); }
void CZoneLIST::Set_RegenSYSTEM(CAI_OBJ* pChar, unsigned char btOnOff) { return CallMemberFunction<CZoneLIST, void, CAI_OBJ*, unsigned char>(0x10091E10, this, pChar, btOnOff); }
void CZoneLIST::Set_RegenSYSTEM(CGameOBJ* pObj, unsigned char btOnOff) { return CallMemberFunction<CZoneLIST, void, CGameOBJ*, unsigned char>(0x10091EF0, this, pObj, btOnOff); }
CObjMOB* CZoneLIST::RegenCharacter(short nZoneNO, float fCenterX, float fCenterY, int iRange, int iIndex, int iCount, int iTeamNO) { return CallMemberFunction<CZoneLIST, CObjMOB*, short, float, float, int, int, int, int>(0x10092490, this, nZoneNO, fCenterX, fCenterY, iRange, iIndex, iCount, iTeamNO); }
CZoneLIST* CZoneLIST::Instance() { return CallStaticFunction<0x100922D0, CZoneLIST*>(); }
CZoneLIST* CZoneLIST::GetInstance() { return CallStaticFunction<0x10091D00, CZoneLIST*>(); }
void CZoneLIST::Destroy() { return CallStaticFunction<0x10092970, void>(); }



