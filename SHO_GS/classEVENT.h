////////////////////////////////////////////////////////////////////////
///////  classEVENT  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef classEVENT_H
#define classEVENT_H
#include "SHO_GS.h"

class TGAMESERVER_API classEVENT   { 
public: 
  void* m_Event;
  classEVENT();
  classEVENT(_SECURITY_ATTRIBUTES* lpEventAttributes, int bManualReset, int bInitialState, const char* lpName);
  virtual ~classEVENT();
  unsigned long WaitFor(unsigned long dwMilliseconds);
  void SetEvent();
  void ResetEvent();
};

#endif