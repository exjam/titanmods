////////////////////////////////////////////////////////////////////////
///////  CCriticalSection  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CCriticalSection_H
#define CCriticalSection_H
#include "SHO_GS.h"

class TGAMESERVER_API CCriticalSection   { 
public: 
  _RTL_CRITICAL_SECTION m_CS;
  CCriticalSection();
  CCriticalSection(unsigned long dwSpinCount);
  virtual ~CCriticalSection();
  void Lock();
  void Unlock();
  void* GetOwningThread();
};

#endif

