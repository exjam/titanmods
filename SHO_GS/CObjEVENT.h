////////////////////////////////////////////////////////////////////////
///////  CObjEVENT  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CObjEVENT_H
#define CObjEVENT_H
#include "SHO_GS.h"
#include "CObjVAR.h"
#include "CGameOBJ.h"

class TGAMESERVER_API CObjEVENT  : public CObjVAR  , public CGameOBJ   { 
public: 
  char m_cMapX;
  char m_cMapY;
  unsigned short m_wMapEventID;
  unsigned long m_HashID;
  bool Send_gsv_SET_EVENT_STATUS();
  CObjEVENT(const CObjEVENT& Var1);
  CObjEVENT();
  virtual ~CObjEVENT();
  virtual t_ObjTAG Get_TYPE();
  virtual bool Make_gsv_ADD_OBJECT(classPACKET* pCPacket);
  virtual short VGetCur_ZoneNO();
  virtual float VGetCur_XPOS();
  virtual float VGetCur_YPOS();
  virtual int VGetCur_ZoneTIME();
  virtual void Set_ObjVAR(unsigned char btVarIDX, short nValue);
  unsigned long Get_ID();
  bool Init(CZoneTHREAD* pZONE, char cMapX, char cMapY, float fWorldX, float fWorldY, unsigned short wMapEventID);
  virtual int Proc();
};

#endif

