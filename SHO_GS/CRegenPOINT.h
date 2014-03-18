////////////////////////////////////////////////////////////////////////
///////  CRegenPOINT  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CRegenPOINT_H
#define CRegenPOINT_H
#include "SHO_GS.h"

class TGAMESERVER_API CRegenPOINT   { 
public: 
  CZoneTHREAD* m_pZONE;
  unsigned long m_dwCheckTIME;
  int m_iBasicCNT;
  int m_iTacticsCNT;
  tagREGENMOB* m_pBasicMOB;
  tagREGENMOB* m_pTacticsMOB;
  int m_iInterval;
  int m_iLimitCNT;
  int m_iTacticsPOINT;
  int m_iLiveCNT;
  int m_iCurTactics;
  float m_fXPos;
  float m_fYPos;
  int m_iRange;
  CRegenPOINT(CZoneTHREAD* pZONE, float fXPos, float fYPos);
  ~CRegenPOINT();
  void RegenCharacter(int iIndex, int iCount);
  bool Load(_iobuf* fp);
  void ClearCharacter(CObjCHAR* pCharOBJ);
  void Proc(unsigned long dwCurTIME);
  void AddLiveCNT();
  void SubLiveCNT();
  int GetLiveCNT();
  void Reset();
};

#endif

