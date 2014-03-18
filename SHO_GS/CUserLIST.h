////////////////////////////////////////////////////////////////////////
///////  CUserLIST  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CUserLIST_H
#define CUserLIST_H
#include "SHO_GS.h"
#include "IOCPSocketSERVER.h"
#include "CDataPOOL.h"
#include "CCriticalSection.h"


class TGAMESERVER_API CUserLIST  : public IOCPSocketSERVER  , public CDataPOOL<classUSER>   { 
public: 
  CCriticalSection m_csHashACCOUNT;
  CCriticalSection m_csHashCHAR;
  CCriticalSection m_csNullZONE;
  classHASH<classUSER *>* m_pHashACCOUNT;
  classHASH<classUSER *>* m_pHashCHAR;
  classDLLIST<CGameOBJ *> m_NullZoneLIST;
  int m_iUserCNT;
  void InitData(classUSER* pData);
  void FreeData(classUSER* pData);
  unsigned long m_HashLevelUpTRIGGER[0xC8];
  CUserLIST();
  CUserLIST(unsigned int uiInitDataCNT, unsigned int uiIncDataCNT);
  virtual ~CUserLIST();
  void DeleteUSER(classUSER* pUSER, unsigned char btLogOutMODE);
  bool SendPacketToSocketIDX(int iClientSocketIDX, classPACKET* pCPacket);
  void Send_wsv_CREATE_CHAR(int iSocketIDX, unsigned char btResult);
  void Send_wsv_MEMO(int iSocketIDX, unsigned char btTYPE, short nMemoCNT);
  void Send_wsv_GUILD_COMMAND(int iSocketIDX, unsigned char btResult, char* szStr);
  classUSER* Find_CHAR(char* szCharName);
  bool Add_CHAR(classUSER* pUSER);
  classUSER* Find_ACCOUNT(char* szAccount);
  bool Add_ACCOUNT(int iSocketIDX, t_PACKET* pRecvPket, char* szAccount);
  classUSER* Find_IP(char* szIP);
  void Send_zws_ACCOUNT_LIST(CClientSOCKET* pSrvSocket, bool bSendToGUMS);
  void Send_cli_STRESS_TEST(classPACKET* pCPacket);
  void Save_AllUSER();
  int Get_AccountCNT();
  bool Kick_ACCOUNT(char* szAccount);
  unsigned long Get_LevelUpTRIGGER(short nLevel);
  void Add_NullZONE(classDLLNODE<CGameOBJ *>* pUserNODE);
  void Sub_NullZONE(classDLLNODE<CGameOBJ *>* pUserNODE);
  void Check_SocketALIVE();
  virtual iocpSOCKET* AllocClientSOCKET();
  virtual void FreeClientSOCKET(iocpSOCKET* pCLIENT);
  virtual void ClosedClientSOCKET(iocpSOCKET* pCLIENT);
};

#endif

