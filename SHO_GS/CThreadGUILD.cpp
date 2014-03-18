#include "CThreadGUILD.h"

bool CThreadGUILD::Run_SqlPACKET(tagQueryDATA* pSqlPACKET) { return CallMemberFunction<CThreadGUILD, bool, tagQueryDATA*>(0x10005260, this, pSqlPACKET); }
void CThreadGUILD::Test_add(char* pGuildName, char* pGuildDesc) { return CallMemberFunction<CThreadGUILD, void, char*, char*>(0x100A2650, this, pGuildName, pGuildDesc); }
void CThreadGUILD::Test_del(char* pGuildName) { return CallMemberFunction<CThreadGUILD, void, char*>(0x100A2470, this, pGuildName); }
void CThreadGUILD::Execute() { return CallMemberFunction<CThreadGUILD, void>(0x100A6390, this); }
bool CThreadGUILD::Run_GuildPACKET(tagCLAN_CMD* pGuildCMD) { return CallMemberFunction<CThreadGUILD, bool, tagCLAN_CMD*>(0x100A53A0, this, pGuildCMD); }
CClan* CThreadGUILD::Query_CreateCLAN(int iSocketIDX, t_PACKET* pPacket) { return CallMemberFunction<CThreadGUILD, CClan*, int, t_PACKET*>(0x100A2E00, this, iSocketIDX, pPacket); }
bool CThreadGUILD::Query_DeleteCLAN(char* szClanName) { return CallMemberFunction<CThreadGUILD, bool, char*>(0x100A42B0, this, szClanName); }
CThreadGUILD::CThreadGUILD(unsigned int uiInitDataCNT, unsigned int uiIncDataCNT) {};
CThreadGUILD::~CThreadGUILD() {};
void CThreadGUILD::Set_EVENT() { return CallMemberFunction<CThreadGUILD, void>(0x10005280, this); }
bool CThreadGUILD::Add_ClanCMD(unsigned char btCMD, int iSocketIDX, t_PACKET* pPacket, char* szCharName) { return CallMemberFunction<CThreadGUILD, bool, unsigned char, int, t_PACKET*, char*>(0x100A2BC0, this, btCMD, iSocketIDX, pPacket, szCharName); }
bool CThreadGUILD::Query_LoginClanMember(char* szCharName, int iSenderSockIDX) { return CallMemberFunction<CThreadGUILD, bool, char*, int>(0x100A52A0, this, szCharName, iSenderSockIDX); }
bool CThreadGUILD::Query_InsertClanMember(char* szCharName, unsigned long dwClanID, int iClanPos) { return CallMemberFunction<CThreadGUILD, bool, char*, unsigned long, int>(0x100A1A50, this, szCharName, dwClanID, iClanPos); }
bool CThreadGUILD::Query_DeleteClanMember(char* szCharName) { return CallMemberFunction<CThreadGUILD, bool, char*>(0x100A2290, this, szCharName); }
bool CThreadGUILD::Query_AdjustClanMember(char* szCharName, int iAdjContr, int iAdjPos) { return CallMemberFunction<CThreadGUILD, bool, char*, int, int>(0x100A18B0, this, szCharName, iAdjContr, iAdjPos); }
bool CThreadGUILD::Query_UpdateClanMOTD(unsigned long dwClanID, char* szMessage) { return CallMemberFunction<CThreadGUILD, bool, unsigned long, char*>(0x100A1720, this, dwClanID, szMessage); }
bool CThreadGUILD::Query_UpdateClanSLOGAN(unsigned long dwClanID, char* szMessage) { return CallMemberFunction<CThreadGUILD, bool, unsigned long, char*>(0x100A1590, this, dwClanID, szMessage); }
bool CThreadGUILD::Query_UpdateClanDATA(char* szField, t_PACKET* pPacket) { return CallMemberFunction<CThreadGUILD, bool, char*, t_PACKET*>(0x100A1FB0, this, szField, pPacket); }
bool CThreadGUILD::Query_UpdateClanBINARY(unsigned long dwClanID, unsigned char* pDATA, unsigned int uiSize) { return CallMemberFunction<CThreadGUILD, bool, unsigned long, unsigned char*, unsigned int>(0x100A13D0, this, dwClanID, pDATA, uiSize); }
unsigned short CThreadGUILD::Query_UpdateClanMARK(CClan* pClan, unsigned short wMarkCRC, unsigned char* pDATA, unsigned int uiSize) { return CallMemberFunction<CThreadGUILD, unsigned short, CClan*, unsigned short, unsigned char*, unsigned int>(0x100A1D00, this, pClan, wMarkCRC, pDATA, uiSize); }
void CThreadGUILD::Login_GuildUSER(char* Var1, unsigned long Var2, int Var3) { return; }
CClan* CThreadGUILD::Find_CLAN(unsigned long dwClanID) { return CallMemberFunction<CThreadGUILD, CClan*, unsigned long>(0x100A1C00, this, dwClanID); }
CClan* CThreadGUILD::Load_CLAN(unsigned long dwClanID) { return CallMemberFunction<CThreadGUILD, CClan*, unsigned long>(0x100A30C0, this, dwClanID); }
bool CThreadGUILD::Create(classUSER* Var1, char* Var2) { return 0; }



