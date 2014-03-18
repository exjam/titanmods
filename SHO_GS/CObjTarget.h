////////////////////////////////////////////////////////////////////////
///////  CObjTARGET  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CObjTARGET_H
#define CObjTARGET_H
#include "SHO_GS.h"

class TGAMESERVER_API CObjTARGET   { 
public: 
  int m_iServerTarget;
  CAI_OBJ* Get_TargetOBJ(bool bCheckHP);
  int Get_TargetIDX();
  virtual void Set_TargetIDX(int iTargetIndex, bool bHP);
  virtual CZoneTHREAD* GetCur_ZONE();
  CObjTARGET();
};

#endif

