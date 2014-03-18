////////////////////////////////////////////////////////////////////////
///////  CIngSTATUS  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CIngSTATUS_H
#define CIngSTATUS_H
#include "SHO_GS.h"

#pragma pack(push, 2)
class TGAMESERVER_API CIngSTATUS   { 
public: 
  unsigned long m_dwIngStatusFLAG;
  struct tagIngPOTION   { 
	public: 
		unsigned long m_dwTotTIME;
		unsigned long m_dwAccTIME;
		short m_nAccVALUE;
		short m_nTotVALUE;
};
  tagIngPOTION m_POTION[0x3];
  short m_nTICKs[0x24];
  short m_nIngSKILL[0x24];
  short m_nAdjVALUE[0x24];
  short m_nIngSTBIdx[0x24];
  int m_iTargetOBJ[0x24];
  unsigned long m_dwAccTIME;
  short Proc_IngPOTION(tagIngPOTION* pPOTION, unsigned long dwPassTIME);
  union {
		short m_nAruaVALUE[0x9];
		struct {
			short m_nAruaAtkSPD;
			short m_nAruaRunSPD;
			short m_nAruaCRITICAL;
			short m_nAruaMaxHP;
			short m_nAruaMaxMP;
			short m_nAruaRcvHP;
			short m_nAruaRcvMP;
			short m_nAruaRES;
			short m_nAruaATK;
		};
};
  short Inc_MAX_HP();
  short Inc_MAX_MP();
  short Inc_RUN_SPEED();
  short Dec_RUN_SPEED();
  short Inc_ATK_SPEED();
  short Dec_ATK_SPEED();
  short Adj_RUN_SPEED();
  short Adj_ATK_SPEED();
  short Adj_APOWER();
  short Adj_DPOWER();
  short Adj_RES();
  short Adj_HIT();
  short Adj_CRITICAL();
  short Adj_AVOID();
  unsigned long m_dwSubStatusFLAG;
  void SetSubFLAG(unsigned long dwFLAG);
  void ClearSubFLAG(unsigned long dwFLAG);
  unsigned long IsSubSET(unsigned long dwCheckFLAG);
  void ToggleSubFLAG(unsigned long dwFLAG);
  void DelArua();
  void Reset(bool bFirst);
  void ClearALL(unsigned long Var1);
  void ClearAllGOOD();
  unsigned long IsSET(unsigned long dwCheckFLAG);
  unsigned long GetFLAGs();
  short GetSkillIDX(eING_TYPE eTYPE);
  void SetFLAG(unsigned long dwIngFLAG);
  void ClearStatusFLAG(unsigned long dwIngFLAG);
  void ClearSTATUS(eING_TYPE IngType);
  void ClearStatusIfENABLED(eING_TYPE IngType);
  void ExpireSTATUS(eING_TYPE IngType);
  bool IsTauntSTATUS(int iAttackObjIDX, CZoneTHREAD* pCurZone);
  bool IsIgnoreSTATUS();
  bool IsEnableApplay(short nIngStbIDX, short nAdjValue);
  bool IsEnableApplayITEM(short nIngStbIDX);
  unsigned long UpdateIngSTATUS(CObjCHAR* pCharOBJ, short nIngStbIDX, short nTick, short nAdjVALUE, short nSkillIDX, int iTargetObjIDX);
  void UpdateIngPOTION(short nIngStbIDX, short nTotValue, short nAdjPerSEC);
  unsigned long Proc(CObjCHAR* pCharOBJ, unsigned long dwPassTIME);
};
#pragma pack(pop)

#endif

