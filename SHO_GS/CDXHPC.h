////////////////////////////////////////////////////////////////////////
///////  CDXHPC  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CDXHPC_H
#define CDXHPC_H
#include "SHO_GS.h"

class TGAMESERVER_API CDXHPC   { 
public: 
  unsigned long m_dwTmpTIME;
  unsigned long m_dwCheckTIME;
  unsigned long m_dwLastTIME;
  _LARGE_INTEGER m_freq;
  _LARGE_INTEGER m_restart;
  _LARGE_INTEGER m_current;
  _LARGE_INTEGER m_excess;
  _LARGE_INTEGER m_tmpcurrent;
  CDXHPC();
  virtual ~CDXHPC();
  int Start();
  unsigned long GetValue();
  void Wait(unsigned long dwMilliSecs);
  unsigned long Reset();
  unsigned long GetCheckTime();
  unsigned long GetCurrentTIME();
  unsigned long GetPassTIME();
};

#endif

