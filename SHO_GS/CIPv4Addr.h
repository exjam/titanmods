////////////////////////////////////////////////////////////////////////
///////  CIPv4Addr  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CIPv4Addr_H
#define CIPv4Addr_H
#include "SHO_GS.h"
#include "classDLLIST.h"

struct tagIP4ADDR   { 
	public: unsigned long m_ulMIN;
	public: unsigned long m_ulMAX;
};

class TGAMESERVER_API CIPv4Addr   { 
public: 
  classDLLIST<tagIP4ADDR> m_LIST[0x100];
  ~CIPv4Addr();
  bool Add(char* szIPFrom, char* szIPTo);
  bool Find(char* szIPAddr);
  bool Find(in_addr& inADDR);
  CIPv4Addr();
};

#endif

