////////////////////////////////////////////////////////////////////////
///////  CSyncIdxARRAY<T>  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CSyncIdxARRAY_H
#define CSyncIdxARRAY_H
#include "SHO_GS.h"
#include "CIndexARRAY.h"
#include "CGameOBJ.h"

template <typename T>
class TGAMESERVER_API CSyncIdxARRAY : public CIndexARRAY<CGameOBJ *>   { 
public:
  public: _RTL_CRITICAL_SECTION m_csIndex;
  public: virtual void Lock();
  public: virtual void Unlock();
};

#endif