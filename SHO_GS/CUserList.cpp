#include "CUserLIST.h"

void CUserLIST::InitData(classUSER* pData) { return CallMemberFunction<CUserLIST, void, classUSER*>(0x100A0730, this, pData); }
void CUserLIST::FreeData(classUSER* pData) { return CallMemberFunction<CUserLIST, void, classUSER*>(0x100A0700, this, pData); }
CUserLIST::CUserLIST() { }
CUserLIST::CUserLIST(unsigned int uiInitDataCNT, unsigned int uiIncDataCNT) {};
CUserLIST::~CUserLIST() {};
void CUserLIST::DeleteUSER(classUSER* pUSER, unsigned char btLogOutMODE) { return CallMemberFunction<CUserLIST, void, classUSER*, unsigned char>(0x100A1170, this, pUSER, btLogOutMODE); }
bool CUserLIST::SendPacketToSocketIDX(int iClientSocketIDX, classPACKET* pCPacket) { return CallMemberFunction<CUserLIST, bool, int, classPACKET*>(0x100A02F0, this, iClientSocketIDX, pCPacket); }
void CUserLIST::Send_wsv_CREATE_CHAR(int iSocketIDX, unsigned char btResult) { return CallMemberFunction<CUserLIST, void, int, unsigned char>(0x100A0FA0, this, iSocketIDX, btResult); }
void CUserLIST::Send_wsv_MEMO(int iSocketIDX, unsigned char btTYPE, short nMemoCNT) { return CallMemberFunction<CUserLIST, void, int, unsigned char, short>(0x100A0F10, this, iSocketIDX, btTYPE, nMemoCNT); }
void CUserLIST::Send_wsv_GUILD_COMMAND(int iSocketIDX, unsigned char btResult, char* szStr) { return CallMemberFunction<CUserLIST, void, int, unsigned char, char*>(0x100A0080, this, iSocketIDX, btResult, szStr); }
classUSER* CUserLIST::Find_CHAR(char* szCharName) { return CallMemberFunction<CUserLIST, classUSER*, char*>(0x100A0150, this, szCharName); }
bool CUserLIST::Add_CHAR(classUSER* pUSER) { return CallMemberFunction<CUserLIST, bool, classUSER*>(0x100A0260, this, pUSER); }
classUSER* CUserLIST::Find_ACCOUNT(char* szAccount) { return CallMemberFunction<CUserLIST, classUSER*, char*>(0x100A0610, this, szAccount); }
bool CUserLIST::Add_ACCOUNT(int iSocketIDX, t_PACKET* pRecvPket, char* szAccount) { return CallMemberFunction<CUserLIST, bool, int, t_PACKET*, char*>(0x100A0CE0, this, iSocketIDX, pRecvPket, szAccount); }
classUSER* CUserLIST::Find_IP(char* szIP) { return CallMemberFunction<CUserLIST, classUSER*, char*>(0x100A0550, this, szIP); }
void CUserLIST::Send_zws_ACCOUNT_LIST(CClientSOCKET* pSrvSocket, bool bSendToGUMS) { return CallMemberFunction<CUserLIST, void, CClientSOCKET*, bool>(0x100A0AB0, this, pSrvSocket, bSendToGUMS); }
void CUserLIST::Send_cli_STRESS_TEST(classPACKET* pCPacket) { return CallMemberFunction<CUserLIST, void, classPACKET*>(0x100A00C0, this, pCPacket); }
void CUserLIST::Save_AllUSER() { return CallMemberFunction<CUserLIST, void>(0x100A04D0, this); }
int CUserLIST::Get_AccountCNT() { return CallMemberFunction<CUserLIST, int>(0x10011360, this); }
bool CUserLIST::Kick_ACCOUNT(char* szAccount) { return CallMemberFunction<CUserLIST, bool, char*>(0x100A07C0, this, szAccount); }
unsigned long CUserLIST::Get_LevelUpTRIGGER(short nLevel) { return CallMemberFunction<CUserLIST, unsigned long, short>(0x10011390, this, nLevel); }
void CUserLIST::Add_NullZONE(classDLLNODE<CGameOBJ *>* pUserNODE) { return CallMemberFunction<CUserLIST, void, classDLLNODE<CGameOBJ *>*>(0x1000AEC0, this, pUserNODE); }
void CUserLIST::Sub_NullZONE(classDLLNODE<CGameOBJ *>* pUserNODE) { return CallMemberFunction<CUserLIST, void, classDLLNODE<CGameOBJ *>*>(0x1000AF10, this, pUserNODE); }
void CUserLIST::Check_SocketALIVE() { return CallMemberFunction<CUserLIST, void>(0x100A0FF0, this); }
iocpSOCKET* CUserLIST::AllocClientSOCKET() { return CallMemberFunction<CUserLIST, iocpSOCKET*>(0x1000AF60, this); }
void CUserLIST::FreeClientSOCKET(iocpSOCKET* pCLIENT) { return CallMemberFunction<CUserLIST, void, iocpSOCKET*>(0x1000AFB0, this, pCLIENT); }
void CUserLIST::ClosedClientSOCKET(iocpSOCKET* pCLIENT) { return CallMemberFunction<CUserLIST, void, iocpSOCKET*>(0x1000AFF0, this, pCLIENT); }



