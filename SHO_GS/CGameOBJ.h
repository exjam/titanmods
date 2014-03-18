////////////////////////////////////////////////////////////////////////
///////  CGameOBJ  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CGameOBJ_H
#define CGameOBJ_H
#include "SHO_GS.h"

class TGAMESERVER_API CGameOBJ   { 
public: 
  CZoneTHREAD* m_pZONE;
  int m_iIndex;
  CVec2 m_PosCUR;
  tagPOINTS m_PosSECTOR;
  CZoneSECTOR* m_pGroupSECTOR;
  classDLLNODE<CGameOBJ *> m_ZoneNODE;
  classDLLNODE<CGameOBJ *> m_SectorNODE;
  CGameOBJ();
  virtual ~CGameOBJ();
  void Init_GameOBJ();
  virtual t_ObjTAG Get_TYPE();
  virtual char* Get_NAME();
  virtual int Proc();
  virtual int Get_TEAM();
  int Get_INDEX();
  void ResetSECTOR(short nSectorSize);
  bool IsA(t_ObjTAG Obj_TYPE);
  bool IsITEM();
  bool IsCNST();
  bool IsNPC();
  bool IsCHAR();
  bool IsUSER();
  bool IsNEIGHBOR(CGameOBJ* pObj);
  CZoneTHREAD* GetZONE();
  void SetZONE(CZoneTHREAD* pZONE);
  int GetCur_ZoneTIME();
  int GetCur_WorldTIME();
  virtual void Set_TargetObjIDX(int Var0);
  virtual bool SendPacket(classPACKET* Var0);
  virtual bool Send_gsv_JOIN_ZONE(CZoneTHREAD* Var0);
  virtual void Update_OwnerObjIDX(classUSER* Var0);
  virtual bool Make_gsv_ADD_OBJECT(classPACKET* Var1);
  virtual bool Make_gsv_SUB_OBJECT(classPACKET* pCPacket);
};

#endif

