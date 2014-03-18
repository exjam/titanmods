////////////////////////////////////////////////////////////////////////
///////  CZoneFILE  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CZoneFILE_H
#define CZoneFILE_H
#include "SHO_GS.h"
#include "classTHREAD.h"
#include "classHASH.h"

class TGAMESERVER_API CZoneFILE  : public classTHREAD   { 
public: 
  classHASH<tagEVENTPOS *>* m_pPosLIST;
  unsigned long m_HashKeyRevivePOS;
  void ReadObjINFO(_iobuf* fp, long lOffset, int iLumpType, short nMapXIDX, short nMapYIDX);
  char* GetMapFILE(short nMapX, short nMapY);
  void LoadMAP(char* szFileName, short nMapXIDX, short nMapYIDX);
  void LoadMOV(char* szFileName, short nMapXIDX, short nMapYIDX);
  void ReadZoneINFO(_iobuf* fp, long lOffset);
  void ReadEventObjINFO(_iobuf* fp, long lOffset);
  bool ReadECONOMY(_iobuf* fp, long lOffset);
  short GridCountPerPatchAXIS();
  short nPatch_SIZE();
  short nGrid_SIZE();
  unsigned long m_HashJoinTRIGGER;
  unsigned long m_HashKillTRIGGER;
  unsigned long m_HashDeadTRIGGER;
  CStrVAR m_ZoneDIR;
  CStrVAR m_MapFileName;
  short m_nMinMapX;
  short m_nMinMapY;
  short m_nMaxMapX;
  short m_nMaxMapY;
  short m_nZoneNO;
  CVec2 m_PosSTART;
  CVec2 m_PosREVIVE;
  CVec2* m_pAgitPOS;
  int m_iAgitCNT;
  short m_nDayTimeFROM;
  short m_nDayTimeTO;
  int m_iSectorXCnt;
  int m_iSectorYCnt;
  CStrVAR m_StrVAR;
  CZoneSECTOR** m_ppSECTOR;
  C1BITARRAY* m_ppMoveATTR[0x800];
  short m_nSectorSIZE;
  int m_iSectorLIMIT;
  virtual CZoneTHREAD* GetZonePTR();
  virtual bool Add_RegenPOINT(_iobuf* Var1, float Var2, float Var3);
  virtual bool Load_Economy(_iobuf* Var1);
  short m_nGridPerPATCH;
  short m_nPatchSIZE;
  short m_nGridSIZE;
  int m_iIsDungeon;
  CZoneFILE();
  CZoneFILE(bool CreateSuspended);
  virtual ~CZoneFILE();
  bool LoadZONE(char* szBaseDIR, short nZoneNO);
  void FreeZONE();
  short Get_SectorSIZE();
  CVec2 Get_StartPOS();
  CVec2 Get_StartRevivePOS();
  CVec2 Get_RevivePOS(CVec2 PosCUR);
  CVec2 Get_AgitPOS(unsigned long dwClanID);
  bool IsMovablePOS(int iXPos, int iYPos);
  unsigned char Is_DAY();
  char* Get_NAME();
  short Get_ZoneNO();
  int Get_SectorXCNT();
  int Get_SectorYCNT();
  unsigned long Get_HashJoinTRIGGER();
  unsigned long Get_HashKillTRIGGER();
  unsigned long Get_HashDeadTRIGGER();
  CStrVAR* GetStrVAR();
};

#endif

