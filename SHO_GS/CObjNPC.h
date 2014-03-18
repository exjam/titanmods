////////////////////////////////////////////////////////////////////////
///////  CObjNPC  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CObjNPC_H
#define CObjNPC_H
#include "SHO_GS.h"
#include "CObjVAR.h"
#include "CObjMOB.h"

class TGAMESERVER_API CObjNPC  : public CObjVAR  , public CObjMOB   { 
public: 
  bool Send_gsv_SET_EVENT_STATUS();
  virtual t_ObjTAG Get_TYPE();
  virtual bool Make_gsv_ADD_OBJECT(classPACKET* pCPacket);
  virtual bool VSend_gsv_CHAT(char* szMsg);
  virtual bool VSend_gsv_SHOUT(char* szMsg);
  virtual void VSend_gsv_ANNOUNCE_CHAT(char* szMsg);
  virtual void VSet_SHOW(unsigned char btShowMode);
  virtual short VGetCur_ZoneNO();
  virtual float VGetCur_XPOS();
  virtual float VGetCur_YPOS();
  virtual int VGetCur_ZoneTIME();
  virtual void Set_ObjVAR(unsigned char btVarIDX, short nValue);
  virtual void Set_NextTRIGGER(int iRemainSec, unsigned long HashNextTrigger);
  virtual void Set_TRIGGER(unsigned long HashNextTrigger);
  float m_fModelDIR;
  bool m_bShow;
  CObjNPC();
  virtual ~CObjNPC();
  virtual void Do_CreatedAI();
  virtual void Do_AttackMoveAI(CObjCHAR* pTarget);
  virtual void Do_KillAI(CObjCHAR* pTarget, int iDamage);
  virtual void Do_DeadAI(CObjCHAR* pTarget, int iDamage);
  virtual void Do_DeadEvent(CObjCHAR* pTarget);
  void Set_DIR(float fDIR);
  bool Get_SellITEM(short nSellTAB, short nSellCOL, tagITEM& OutITEM);
  virtual int Proc();
};

#endif

