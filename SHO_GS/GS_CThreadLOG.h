////////////////////////////////////////////////////////////////////////
///////  GS_CThreadLOG  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef GS_CThreadLOG_H
#define GS_CThreadLOG_H
#include "SHO_GS.h"
#include "CThreadLOG.h"

enum Item_Log {
	ITEMLOG_TO_BANK = 1,
	ITEMLOG_FROM_BANK = 2,
	ITEMLOG_TO_NPC = 3,
	ITEMLOG_FROM_NPC = 4,
	ITEMLOG_VEND = 5,
	ITEMLOG_TRADE_GIVE = 6,
	ITEMLOG_TRADE_GET = 7,
	ITEMLOG_DROP = 8,
	ITEMLOG_PICKUP = 9,
	ITEMLOG_DELETE = 10,
	ITEMLOG_UNION = 12,
	ITEMLOG_QUICKSWAP = 13,
	ITEMLOG_QUICKSWAP_DROP = 14,
	ITEMLOG_BANK_MONEY_DEPOSIT = 15,
	ITEMLOG_BANK_MONEY_TAKE = 16,
};

class TGAMESERVER_API GS_CThreadLOG  : public CThreadLOG   { 
public: 
  char* MakeItemDESC(CStrVAR* pStrVAR, tagITEM* pITEM, int iItmePrice, int iDupCnt, int iMoneyAmout, unsigned long dwTradeMoney, int iTradeCnt);
  char* GetItemINFO(tagITEM* pITEM, int iItmePrice, int iDupCnt, int iMoneyAmout, unsigned long dwTradeMoney, int iTradeCnt);
  bool When_LogInOrOut(classUSER* pUSER, unsigned char btType);
  bool When_DeletedITEM(CObjITEM* pItemOBJ);
  bool Check_ItemLogFilter(tagITEM* pITEM, short nQuantity, __int64 biZuly);
  bool When_TagItemLOG(int iAction, classUSER* pSourAVT, tagITEM* pItem, short nQuantity, __int64 biTradeZuly, classUSER* pDestAVT, bool bForce);
  bool When_ObjItemLOG(int iAction, classUSER* pSourAVT, CObjITEM* pItemOBJ);
  bool When_CreateOrDestroyITEM(classUSER* pSourAVT, tagITEM* pOutItem, tagITEM* pUseItem, short nUseCNT, unsigned char btMakeOrBreak, unsigned char btSucOrFail);
  bool When_DieBY(CObjCHAR* pKillOBJ, classUSER* pDeadAVT);
  bool When_LevelUP(classUSER* pSourAVT, int iGetEXP);
  bool When_QuestLOG(classUSER* pSourAVT, int iQuestIDX, unsigned char btLogType);
  bool When_LearnSKILL(classUSER* pSourAVT, short nSkillIDX);
  bool When_UpgradeITEM(classUSER* pSourAVT, tagITEM* pEquipITEM, unsigned char btBeforeGrade, unsigned char btResult);
  bool When_GemmingITEM(classUSER* pSourAVT, tagITEM* pEquipITEM, tagITEM* pJewelITEM, unsigned char btGemming, unsigned char btSuccess);
  bool When_ChangeUNION(classUSER* pSourAVT, int iBeforeUnion, int iNewUnion);
  bool When_PointUNION(classUSER* pSourAVT, int iCurUnion, int iCurPoint, int iNewPoint);
  bool When_CheatCODE(classUSER* pSourAVT, char* szCode);
  bool When_ItemHACKING(classUSER* pSourAVT, tagITEM* pHackITEM, char* szLogType);
  bool When_BackUP(classUSER* pSourAVT, char* szBackUpType);
  bool When_gs_CLAN(classUSER* pSourAVT, char* szLogType, unsigned char btSucType);
  bool When_ChangeABILITY(classUSER* pSourAVT, unsigned char btAbilityTYPE, short nUsedBPOINT);
  GS_CThreadLOG();
  virtual ~GS_CThreadLOG();
};

#endif

