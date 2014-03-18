////////////////////////////////////////////////////////////////////////
///////  CObjMNG  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CObjMNG_H
#define CObjMNG_H
#include "SHO_GS.h"
#include "CSyncIdxARRAY.h"

class TGAMESERVER_API CObjMNG  : public CSyncIdxARRAY<CGameOBJ *>   { 
public: 
  CObjMNG(int iMaxGameObject);
  virtual ~CObjMNG();
  CGameOBJ* Get_OBJECT(unsigned short wIndex);
  CObjCHAR* Get_CharOBJ(unsigned short wIndex, bool bCheckHP);
  CObjITEM* Get_ItemOBJ(unsigned short wIndex);
  classUSER* Get_UserOBJ(unsigned long dwIndex);
  CGameOBJ* Get_GameOBJ(unsigned short wIndex, t_ObjTAG ObjTYPE);
  CGameOBJ* Get_ClientOBJECT(unsigned short wIndex);
  CObjCHAR* Get_ClientCharOBJ(unsigned short wIndex, bool bCheckHP);
  int Get_ClientObjectIndex(int iServerObject);
};

#endif

