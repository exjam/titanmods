////////////////////////////////////////////////////////////////////////
///////  CObjVAR  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CObjVAR_H
#define CObjVAR_H
#include "SHO_GS.h"

class TGAMESERVER_API CObjVAR   { 
public: 
  CObjVAR();
  void InitObjVAR();
  virtual bool VSend_gsv_CHAT(char* Var0);
  virtual bool VSend_gsv_SHOUT(char* Var0);
  virtual void VSend_gsv_ANNOUNCE_CHAT(char* Var0);
  virtual void VSet_SHOW(unsigned char btShowMode);
  virtual short VGetCur_ZoneNO();
  virtual float VGetCur_XPOS();
  virtual float VGetCur_YPOS();
  virtual int VGetCur_ZoneTIME();
  short Get_ObjVAR(unsigned char btVarIDX);
  virtual void Set_ObjVAR(unsigned char btVarIDX, short nValue);
  virtual void Set_NextTRIGGER(int iRemainSec, unsigned long HashNextTrigger);
  bool ProcVAR(unsigned long dwPassTIME);
};

#endif

