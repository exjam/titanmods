////////////////////////////////////////////////////////////////////////
///////  CIOCP  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CIOCP_H
#define CIOCP_H
#include "SHO_GS.h"

class TGAMESERVER_API CIOCP   { 
public: 
  void* m_hIOCP;
  CIOCP();
  ~CIOCP();
  void* GetHANDLE();
  bool OpenPort(unsigned long dwWorkerThreadCNT);
  void ClosePort();
  bool LinkPort(void* hFileHandle, unsigned long ulCompletionKey);
};

#endif

