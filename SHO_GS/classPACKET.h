////////////////////////////////////////////////////////////////////////
///////  classPACKET  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef classPACKET_H
#define classPACKET_H
#include "SHO_GS.h"

class TGAMESERVER_API classPACKET   { 
public: 
  t_PACKETHEADER m_HEADER;
  unsigned char m_pDATA[0x400];
  long m_lRefCnt;
  unsigned short m_wPacketLEN;
  classPACKET();
  ~classPACKET();
  void SetRefCnt(long lRefCnt);
  long IncRefCnt();
  long DecRefCnt();
  int GetRefCnt();
  unsigned short GetLength();
  void SetLength(unsigned short wLen);
  char* GetStringPtr(short* pOffset);
  unsigned char* GetDataPtr(short* pOffset, short nSize);
  bool AppendString(char* pStr);
  bool AppendData(void* pData, short nLen);
};

#endif