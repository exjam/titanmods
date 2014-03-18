////////////////////////////////////////////////////////////////////////
///////  CZoneLIST  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CZoneLIST_H
#define CZoneLIST_H
#include "SHO_GS.h"
#include "CWorldVAR.h"
#include "classHASH.h"

class TGAMESERVER_API CZoneLIST  : public CWorldVAR   { 
public: 
  classHASH<tagEVENTPOS *> m_PosLIST;
  classHASH<CObjEVENT *> m_EventOBJECT;
  short m_nZoneCNT;
  CZoneTHREAD** m_ppThreadZONE;
  bool* m_pValidZONE;
  short* m_pSectorSIZE;
  CZoneLIST(const CZoneLIST& Var1);
  CZoneLIST();
  ~CZoneLIST();
  CObjNPC** m_ppNpcLIST;
  virtual void Set_WorldVAR(short nVarIDX, short nValue);
  void Add_LocalNPC(CObjNPC* pObjNPC);
  CObjNPC* Get_LocalNPC(int iNpcNO);
  CObjVAR* Get_NpcVAR(int iNpcNO);
  void Add_EventOBJ(CObjEVENT* pObjEVENT);
  CObjEVENT* Get_EventOBJ(short nZoneNO, unsigned long HashKEY);
  void Init_NpcObjVAR(short nNpcIDX, unsigned char* pVAR);
  void Init_EventObjVAR(unsigned long HashID, unsigned char* pVAR);
  bool InitZoneLIST(char* szBaseDIR);
  void FreeZoneLIST();
  bool IsAgitZONE(short nZoneNO);
  bool IsValidZONE(short nZoneNO);
  short GetZoneCNT();
  short GetSectorSIZE(short nZoneNO);
  CZoneTHREAD* GetZONE(short nZoneNO);
  tagEVENTPOS* Add_EventPOS(unsigned long HashKEY, short nZoneNO, char* szPosName, float fXPos, float fYPos);
  tagEVENTPOS* Get_EventPOS(short nZoneNO, char* szPosName);
  void Send_gsv_ANNOUNCE_CHAT(t_PACKET* pSendPacket);
  void Send_gsv_ANNOUNCE_CHAT(char* szMessage, char* szAccount);
  void Send_gsv_ANNOUNCE_CHAT(short nZoneNO, char* szMessage, char* szAccount);
  void Send_gsv_ANNOUNCE_CHAT(CObjVAR* pObjVAR, char* szMessage);
  void Set_PK_FLAG(CAI_OBJ* pChar, unsigned char btOnOff);
  void Set_PK_FLAG(short nZoneNO, unsigned char btOnOff);
  bool Do_QuestTrigger(short nZoneNO, short nTeamNO, unsigned long HashKEY);
  void Toggle_RegenSYSTEM(short nZoneNO);
  void Toggle_RegenSYSTEM(CAI_OBJ* pChar);
  void Toggle_RegenSYSTEM(CGameOBJ* pObj);
  void Set_RegenSYSTEM(short nZoneNO, unsigned char btOnOff);
  void Set_RegenSYSTEM(CAI_OBJ* pChar, unsigned char btOnOff);
  void Set_RegenSYSTEM(CGameOBJ* pObj, unsigned char btOnOff);
  CObjMOB* RegenCharacter(short nZoneNO, float fCenterX, float fCenterY, int iRange, int iIndex, int iCount, int iTeamNO);
  static CZoneLIST* m_pCZoneLIST;//static, [000CBA54][0003:00002A54];
  static CZoneLIST* Instance();
  static CZoneLIST* GetInstance();
  static void Destroy();
};

#endif

