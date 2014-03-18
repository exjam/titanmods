////////////////////////////////////////////////////////////////////////
///////  CZoneSECTOR  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CZoneSECTOR_H
#define CZoneSECTOR_H
#include "SHO_GS.h"

class TGAMESERVER_API CZoneSECTOR   { 
public: 
  static int m_iSectorCNT;//static, [000CBA58][0003:00002A58];
  classDLLIST<CGameOBJ *> m_ObjLIST;
  classDLLNODE<CGameOBJ *>* m_pObjNODE;
  void LockSector();
  void UnlockSector();
  static int GetSectorCount();
  int m_iCenterX;
  int m_iCenterY;
  CZoneSECTOR(const CZoneSECTOR& Var1);
  CZoneSECTOR();
  ~CZoneSECTOR();
  void SetCenterPOS(int iCenterX, int iCenterY);
  void InsToSEC(CGameOBJ* pObj);
  void DelFromSEC(CGameOBJ* pObj);
  virtual classDLLNODE<CGameOBJ *>* FindFirstCHAR(CGameOBJ* Var1);
  virtual classDLLNODE<CGameOBJ *>* FindNextCHAR(classDLLNODE<CGameOBJ *>* Var1, CGameOBJ* Var2);
  virtual void SendPacketToSECTOR(classPACKET* Var1, CGameOBJ* Var2);
  virtual void SendTeamPacketToSECTOR(classPACKET* Var1, int Var2, CGameOBJ* Var3);
  virtual void SendAddUserPacket(classUSER* Var1, classPACKET* Var2);
  virtual void SendSubUserPacket(classUSER* Var1, classPACKET* Var2);
};

#endif

