////////////////////////////////////////////////////////////////////////
///////  IOCPSocketSERVER  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef IOCPSocketSERVER_H
#define IOCPSocketSERVER_H
#include "SHO_GS.h"
#include "CCriticalSection.h"
#include "CIOCP.h"
#include "CIPv4Addr.h"
#include "CIndexARRAY.h"
#include "classListBLOCK.h"

#include "CSLList.h"
#include "CDLList.h"
#include <Inaddr.h>
class IOCPSocketAcceptTHREAD;
class IOCPSocketWorkerTHREAD;
class iocpSOCKET;

class TGAMESERVER_API IOCPSocketSERVER  : public CCriticalSection   { 
public: 
  CIOCP m_IOCP;
  unsigned long m_dwWorkerThreadCNT;
  unsigned long m_dwMaxSocketCNT;
  CStrVAR m_ServerName;
  CIPv4Addr m_RefuseIP;
  IOCPSocketAcceptTHREAD* m_pAcceptTHREAD;
  IOCPSocketWorkerTHREAD** m_ppWorkerTHREAD;
  CIndexARRAY<iocpSOCKET *>* m_pSocketIDX;
  classListBLOCK<tagBlockDATA>* m_pBlockingIP;
  CSLList<tagAtkIP> m_AttackLIST;
  CDLList<iocpSOCKET *> m_SocketLIST;
  bool m_bManageSocketVerify;
  IOCPSocketSERVER();
  IOCPSocketSERVER(char* szName, unsigned char btMulCPU, char cAddCPU, bool bManageSocketVerify);
  virtual ~IOCPSocketSERVER();
  bool Add_RefuseIP(char* Var1, char* Var2);
  char* GetServerNAME();
  virtual iocpSOCKET* AllocClientSOCKET();
  virtual void InitClientSOCKET(iocpSOCKET* pCLIENT);
  virtual void FreeClientSOCKET(iocpSOCKET* Var1);
  virtual void ClosedClientSOCKET(iocpSOCKET* Var1);
  void LockLIST();
  void UnlockLIST();
  iocpSOCKET* GetSOCKET(int iSocketIDX);
  bool New_SOCKET(unsigned int hSocket, sockaddr_in& SockADDR);
  iocpSOCKET* Del_SOCKET(int iSocketIDX);
  void On_TRUE(_OVERLAPPED* lpOverlapped, unsigned long dwCompletionKey, unsigned long dwBytesIO);
  void On_FALSE(_OVERLAPPED* lpOverlapped, unsigned long dwCompletionKey);
  int GetUsedSocketCNT();
  bool Active(int iListenTCPPortNO, unsigned long dwMaxSocketCount, int iKeepAliveSec);
  void Shutdown();
  void ShutdownSOCKET();
  bool StartACCEPT(int iListenTCPPortNO, int iKeepAliveSec);
  void ShutdownACCEPT();
  void StartWORKER();
  void ShutdownWORKER();
  unsigned long GetMaxSocketCOUNT();
  void CloseIdleSCOKET(unsigned long dwIdleMilliSec);
};

#endif