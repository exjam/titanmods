////////////////////////////////////////////////////////////////////////
///////  iocpSOCKET  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef iocpSOCKET_H
#define iocpSOCKET_H
#include "SHO_GS.h"

#include "CCriticalSection.h"
#include "classDLLIST.h"
#include "CDLList.h"

class TGAMESERVER_API iocpSOCKET   { 
public: 
  
  ePacketRECV Recv_Continue(tagIO_DATA* pRecvDATA);
  bool Send_Continue(tagIO_DATA* pSendDATA);
  CCriticalSection m_csSOCKET;
  CCriticalSection m_csSendQ;
  CCriticalSection m_csRecvQ;
  classDLLIST<tagIO_DATA> m_SendList;
  bool m_bWritable;
  classDLLIST<tagIO_DATA> m_RecvList;
  unsigned long m_dwCheckTIME;
  void CloseSocket();
  unsigned int m_Socket;
  int m_iSocketIDX;
  CStrVAR m_IP;
  unsigned long m_HashKeyIP;
  bool m_bVerified;
  int m_pSockNODE;
  unsigned long m_dwConnTIME;
  iocpSOCKET(const iocpSOCKET& Var1);
  iocpSOCKET();
  virtual ~iocpSOCKET();
  void LockSOCKET();
  void UnlockSOCKET();
  void Init_SCOKET();
  unsigned int Get_SOCKET();
  char* Get_IP();
  unsigned long Get_CheckTIME();
  void Clear_LIST();
  ePacketRECV Recv_Start();
  ePacketRECV Recv_Complete(tagIO_DATA* pRecvDATA);
  bool Send_Start(classPACKET* pCPacket);
  bool Send_Complete(tagIO_DATA* pSendDATA);
  virtual bool Recv_Done(tagIO_DATA* pRecvDATA);
  virtual bool HandlePACKET(t_PACKETHEADER* Var1);
  virtual unsigned short E_SendP(t_PACKETHEADER* pPacket);
  virtual unsigned short D_RecvH(t_PACKETHEADER* pPacket);
  virtual short D_RecvB(t_PACKETHEADER* pPacket);
  virtual unsigned short P_Length(t_PACKETHEADER* pPacket);
  classDLLNODE<tagIO_DATA>* Alloc_RecvIODATA();
  static void Free_RecvIODATA(tagIO_DATA* pRecvDATA);
  classDLLNODE<tagIO_DATA>* Alloc_SendIODATA(classPACKET* pCPacket);
  static void Free_SendIODATA(tagIO_DATA* pSendDATA);
    };
#endif