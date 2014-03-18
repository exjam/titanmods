////////////////////////////////////////////////////////////////////////
///////  classTHREAD  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef classTHREAD_H
#define classTHREAD_H
#include "SHO_GS.h"

class TGAMESERVER_API classTHREAD   { 
public: 
  
  bool m_bSuspended;
  bool m_bFinished;
  void* m_hThread;
  unsigned int ThreadID;
  bool Terminated;
  classTHREAD();	
  classTHREAD(bool bCreateSuspended);
  virtual ~classTHREAD();
  unsigned long Suspend();
  unsigned long Resume();
  void Terminate();
  int WaitFor();
  bool IsFinished();
  void SetSuspended(bool bValue);
  int SetPriority(int iPriority);
  virtual void Execute();
};

#endif

