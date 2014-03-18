////////////////////////////////////////////////////////////////////////
///////  CObjITEM  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CObjITEM_H
#define CObjITEM_H
#include "SHO_GS.h"
#include "CGameOBJ.h"

class TGAMESERVER_API CObjITEM  : public CGameOBJ   { 
public: 
  CParty* m_pOwnerPARTY;
  unsigned long m_dwOwnerDBID;
  tagITEM m_ITEM;
  int m_iOwnerObjIDX;
  int m_iRemainTIME;
  bool m_bDropperIsUSER;
  CStrVAR m_DropperACCOUNT;
  CStrVAR m_DropperNAME;
  CStrVAR m_DropperIP;
  unsigned long m_dwDropperDBID;
  unsigned long m_dwDropperClanID;
  virtual ~CObjITEM();
  virtual t_ObjTAG Get_TYPE();
  void InitItemOBJ(classUSER* pDropper, CVec2& PosCUR, tagPOINTS& PosSEC, tagITEM& sITEM, classUSER* pOwner, bool bActive, CParty* pOwnerPARTY);
  void SetACTIVE();
  virtual void Update_OwnerObjIDX(classUSER* pUSER);
  virtual bool Make_gsv_ADD_OBJECT(classPACKET* pCPacket);
  bool Is_FREE();
  bool Check_PrivateRIGHT(int iTryObjIDX);
  bool Check_PartyRIGHT(CParty* pTryPARTY);
  virtual int Proc();
  CObjITEM();
};

#endif

