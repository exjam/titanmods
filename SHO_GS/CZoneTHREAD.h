////////////////////////////////////////////////////////////////////////
///////  CZoneTHREAD  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CZoneTHREAD_H
#define CZoneTHREAD_H
#include "SHO_GS.h"
#include "CZoneFILE.h"
#include "classSLLIST.h"
#include "classDLLIST.h"
#include "CCriticalSection.h"
#include "CEconomy.h"
#include "CDXHPC.h"

class TGAMESERVER_API CZoneTHREAD  : public CZoneFILE   { 
public: 
  classEVENT* m_pEvent;
  CDXHPC m_Timer;
  unsigned long m_dwCurrentTIME;
  unsigned long m_dwTimeGetTIME;
  unsigned long m_dwCurAbsSEC;
  bool m_bEnableREGEN;
  classDLLIST<CRegenPOINT *> m_RegenLIST;
  CCriticalSection m_csZoneMobCALLED;
  classSLLIST<tagCalledMOB> m_MobCALLED;
  CCriticalSection m_csZoneObjWAIT;
  classDLLIST<CGameOBJ *> m_ObjWAIT;
  classDLLIST<CGameOBJ *> m_ObjLIST;
  CCriticalSection m_csPacketLIST;
  classSLLIST<classPACKET *> m_ToSendPacketLIST;
  classSLLIST<classPACKET *> m_SendingPacketLIST;
  long m_lMaxUSER;
  long m_lUserCNT;
  bool m_bEndExecuteFunc;
  unsigned long m_dwGlobalFLAGS;
  int m_iFindSecIDX;
  int m_iFindDistance;
  CVec2 m_FindPOS;
  tagPOINTS m_FindSECTOR;
  classDLLNODE<CGameOBJ *>* m_pFindObjNODE;
  CGameOBJ* m_pObjFINDER;
  void DeleteZoneOBJ();
  CCriticalSection m_csTriggerLIST;
  classSLLIST<tagZoneTRIGGER> m_TriggerLIST;
  void Proc_ZoneTRIGGER();
  virtual CZoneTHREAD* GetZonePTR();
  virtual bool Add_RegenPOINT(_iobuf* fp, float fPosX, float fPosY);
  virtual bool Load_Economy(_iobuf* fp);
  virtual void Execute();
  CEconomy m_Economy;
  void* m_pListITEM;
  CZoneTHREAD();
  CZoneTHREAD(bool CreateSuspended);
  virtual ~CZoneTHREAD();
  int Get_UserCNT();
  void Inc_UserCNT();
  void Dec_UserCNT();
  bool Add_OBJECT(CGameOBJ* pObj);
  bool Add_DIRECT(CGameOBJ* pObj);
  void Sub_DIRECT(CGameOBJ* pObj, bool bSubFromREGEN);
  CZoneSECTOR* GetSECTOR(int iSectorX, int iSectorY);
  bool UpdateSECTOR(CObjCHAR* pCHAR);
  CObjMOB* RegenMOB(float fCenterX, float fCenterY, int iRange, int iIndex, int iCount, int iTeamNO);
  void RegenCharacter(CRegenPOINT* pRegen, int iIndex, int iCount);
  CObjMOB* RegenCharacter(float fCenterX, float fCenterY, int iRange, int iIndex, int iCount, int iTeamNO, bool bImmediate);
  bool RegenCharacter(CObjMOB* pNewMOB, float fCenterX, float fCenterY, int iRange, int iIndex, int iTeamNO);
  void SendPacketToSectors(CGameOBJ* pGameObj, classPACKET* pCPacket);
  void SendTeamPacketToSectors(CGameOBJ* pGameObj, classPACKET* pCPacket, int iTeamNO);
  bool AddObjectToSector(CGameOBJ* pObj, unsigned char btUpdateFLAG);
  void SubObjectFromSector(CGameOBJ* pObj, char cUpdateFLAG);
  bool Init(char* szBaseDIR, short nZoneNO);
  bool Free();
  int Get_ItemBuyPRICE(short nItemTYPE, short nItemNO, short nBuySkillVALUE);
  int Get_ItemSellPRICE(tagITEM& sITEM, short nSellSkillVALUE);
  int Get_EconomyVAR(short nVarIDX);
  unsigned long GetPassTIME();
  unsigned long GetCurrentTIME();
  unsigned long GetTimeGetTIME();
  unsigned long GetCurAbsSEC();
  unsigned long GetEconomyTIME();
  unsigned long GetGlobalFLAG();
  int GetGameObjCNT();
  void BuyITEMs(tagITEM& sITEM);
  void SellITEMs(tagITEM* pITEM, int iQuantity);
  bool SendShout(CGameOBJ* pGameOBJ, classPACKET* pCPacket, int iTeamNo);
  bool SendPacketToZONE(t_PACKET* pSendPacket);
  void Send_EconomyDATA();
  void Send_GLOBAL_FLAG();
  unsigned long Toggle_PK_FLAG();
  void Set_PK_FLAG(unsigned char btOnOff);
  CObjCHAR* FindFirstCHAR(CObjCHAR* pCenterCHAR, int iDistance, CGameOBJ* pObjFINDER);
  CObjCHAR* FindFirstCHAR(CVec2& PosCENTER, int iDistance, CGameOBJ* pObjFINDER);
  CObjCHAR* FindNextCHAR();
  void Kill_AllMOB(classUSER* pUSER);
  bool Toggle_REGEN();
  void Set_REGEN(bool bEnableRegen);
  void Reset_REGEN();
  short GetRegenPointCNT();
  short GetRegenPointMOB(short nIndex, classUSER* pUSER);
  CRegenPOINT* GetRegenPOINT(short nIndex);
  short CallRegenPointMOB(short nIndex);
  short GetNearstRegenPOINT(CVec2& PosCENTER);
  void Do_QuestTrigger(short nTeamNO, unsigned long HashKEY);
};

#endif

