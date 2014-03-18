#include "GS_CThreadLOG.h"

char* GS_CThreadLOG::MakeItemDESC(CStrVAR* pStrVAR, tagITEM* pITEM, int iItmePrice, int iDupCnt, int iMoneyAmout, unsigned long dwTradeMoney, int iTradeCnt) { return CallMemberFunction<GS_CThreadLOG, char*, CStrVAR*, tagITEM*, int, int, int, unsigned long, int>(0x100657D0, this, pStrVAR, pITEM, iItmePrice, iDupCnt, iMoneyAmout, dwTradeMoney, iTradeCnt); }
char* GS_CThreadLOG::GetItemINFO(tagITEM* pITEM, int iItmePrice, int iDupCnt, int iMoneyAmout, unsigned long dwTradeMoney, int iTradeCnt) { return CallMemberFunction<GS_CThreadLOG, char*, tagITEM*, int, int, int, unsigned long, int>(0x10066750, this, pITEM, iItmePrice, iDupCnt, iMoneyAmout, dwTradeMoney, iTradeCnt); }
bool GS_CThreadLOG::When_LogInOrOut(classUSER* pUSER, unsigned char btType) { return CallMemberFunction<GS_CThreadLOG, bool, classUSER*, unsigned char>(0x10065A30, this, pUSER, btType); }
bool GS_CThreadLOG::When_DeletedITEM(CObjITEM* pItemOBJ) { return CallMemberFunction<GS_CThreadLOG, bool, CObjITEM*>(0x10065BD0, this, pItemOBJ); }
bool GS_CThreadLOG::Check_ItemLogFilter(tagITEM* pITEM, short nQuantity, __int64 biZuly) { return CallMemberFunction<GS_CThreadLOG, bool, tagITEM*, short, __int64>(0x10064750, this, pITEM, nQuantity, biZuly); }
bool GS_CThreadLOG::When_TagItemLOG(int iAction, classUSER* pSourAVT, tagITEM* pItem, short nQuantity, __int64 biTradeZuly, classUSER* pDestAVT, bool bForce) { return CallMemberFunction<GS_CThreadLOG, bool, int, classUSER*, tagITEM*, short, __int64, classUSER*, bool>(0x10066220, this, iAction, pSourAVT, pItem, nQuantity, biTradeZuly, pDestAVT, bForce); }
bool GS_CThreadLOG::When_ObjItemLOG(int iAction, classUSER* pSourAVT, CObjITEM* pItemOBJ) { return CallMemberFunction<GS_CThreadLOG, bool, int, classUSER*, CObjITEM*>(0x10065EF0, this, iAction, pSourAVT, pItemOBJ); }
bool GS_CThreadLOG::When_CreateOrDestroyITEM(classUSER* pSourAVT, tagITEM* pOutItem, tagITEM* pUseItem, short nUseCNT, unsigned char btMakeOrBreak, unsigned char btSucOrFail) { return CallMemberFunction<GS_CThreadLOG, bool, classUSER*, tagITEM*, tagITEM*, short, unsigned char, unsigned char>(0x100653E0, this, pSourAVT, pOutItem, pUseItem, nUseCNT, btMakeOrBreak, btSucOrFail); }
bool GS_CThreadLOG::When_DieBY(CObjCHAR* pKillOBJ, classUSER* pDeadAVT) { return CallMemberFunction<GS_CThreadLOG, bool, CObjCHAR*, classUSER*>(0x10065280, this, pKillOBJ, pDeadAVT); }
bool GS_CThreadLOG::When_LevelUP(classUSER* pSourAVT, int iGetEXP) { return CallMemberFunction<GS_CThreadLOG, bool, classUSER*, int>(0x10065150, this, pSourAVT, iGetEXP); }
bool GS_CThreadLOG::When_QuestLOG(classUSER* pSourAVT, int iQuestIDX, unsigned char btLogType) { return CallMemberFunction<GS_CThreadLOG, bool, classUSER*, int, unsigned char>(0x10064FA0, this, pSourAVT, iQuestIDX, btLogType); }
bool GS_CThreadLOG::When_LearnSKILL(classUSER* pSourAVT, short nSkillIDX) { return CallMemberFunction<GS_CThreadLOG, bool, classUSER*, short>(0x10065030, this, pSourAVT, nSkillIDX); }
bool GS_CThreadLOG::When_UpgradeITEM(classUSER* pSourAVT, tagITEM* pEquipITEM, unsigned char btBeforeGrade, unsigned char btResult) { return CallMemberFunction<GS_CThreadLOG, bool, classUSER*, tagITEM*, unsigned char, unsigned char>(0x10064BC0, this, pSourAVT, pEquipITEM, btBeforeGrade, btResult); }
bool GS_CThreadLOG::When_GemmingITEM(classUSER* pSourAVT, tagITEM* pEquipITEM, tagITEM* pJewelITEM, unsigned char btGemming, unsigned char btSuccess) { return CallMemberFunction<GS_CThreadLOG, bool, classUSER*, tagITEM*, tagITEM*, unsigned char, unsigned char>(0x10064D20, this, pSourAVT, pEquipITEM, pJewelITEM, btGemming, btSuccess); }
bool GS_CThreadLOG::When_ChangeUNION(classUSER* pSourAVT, int iBeforeUnion, int iNewUnion) { return CallMemberFunction<GS_CThreadLOG, bool, classUSER*, int, int>(0x10064730, this, pSourAVT, iBeforeUnion, iNewUnion); }
bool GS_CThreadLOG::When_PointUNION(classUSER* pSourAVT, int iCurUnion, int iCurPoint, int iNewPoint) { return CallMemberFunction<GS_CThreadLOG, bool, classUSER*, int, int, int>(0x10064710, this, pSourAVT, iCurUnion, iCurPoint, iNewPoint); }
bool GS_CThreadLOG::When_CheatCODE(classUSER* pSourAVT, char* szCode) { return CallMemberFunction<GS_CThreadLOG, bool, classUSER*, char*>(0x100649B0, this, pSourAVT, szCode); }
bool GS_CThreadLOG::When_ItemHACKING(classUSER* pSourAVT, tagITEM* pHackITEM, char* szLogType) { return CallMemberFunction<GS_CThreadLOG, bool, classUSER*, tagITEM*, char*>(0x100667A0, this, pSourAVT, pHackITEM, szLogType); }
bool GS_CThreadLOG::When_BackUP(classUSER* pSourAVT, char* szBackUpType) { return CallMemberFunction<GS_CThreadLOG, bool, classUSER*, char*>(0x10064A50, this, pSourAVT, szBackUpType); }
bool GS_CThreadLOG::When_gs_CLAN(classUSER* pSourAVT, char* szLogType, unsigned char btSucType) { return CallMemberFunction<GS_CThreadLOG, bool, classUSER*, char*, unsigned char>(0x100648B0, this, pSourAVT, szLogType, btSucType); }
bool GS_CThreadLOG::When_ChangeABILITY(classUSER* pSourAVT, unsigned char btAbilityTYPE, short nUsedBPOINT) { return CallMemberFunction<GS_CThreadLOG, bool, classUSER*, unsigned char, short>(0x100646F0, this, pSourAVT, btAbilityTYPE, nUsedBPOINT); }
GS_CThreadLOG::GS_CThreadLOG() {};
GS_CThreadLOG::~GS_CThreadLOG() {};



