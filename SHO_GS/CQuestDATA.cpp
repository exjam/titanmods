#include "CQuestDATA.h"

void CQuestDATA::LoadQuestTrigger(_iobuf* fpIN, unsigned int uiTriggerCNT, char* szFileName) { return CallMemberFunction<CQuestDATA, void, _iobuf*, unsigned int, char*>(0x1009B810, this, fpIN, uiTriggerCNT, szFileName); }
bool CQuestDATA::LoadDATA(char* szFileName) { return CallMemberFunction<CQuestDATA, bool, char*>(0x1009C140, this, szFileName); }
bool CQuestDATA::LoadQuestTable(char* szQuestFile, char* szQuestListSTB, char* szBaseDIR, char* szQuestLangSTB, int iLangCol) { return CallMemberFunction<CQuestDATA, bool, char*, char*, char*, char*, int>(0x1009C9D0, this, szQuestFile, szQuestListSTB, szBaseDIR, szQuestLangSTB, iLangCol); }
bool CQuestDATA::LoadQuestTable() { return CallMemberFunction<CQuestDATA, bool>(0x1009C2D0, this); }
void CQuestDATA::Free() { return CallMemberFunction<CQuestDATA, void>(0x1009C0A0, this); }
CQuestDATA::CQuestDATA(const CQuestDATA& Var1) { }
CQuestDATA::CQuestDATA() {};
CQuestDATA::~CQuestDATA() {};
eQST_RESULT CQuestDATA::CheckQUEST(CUserDATA* pUSER, unsigned long HashQuest, bool bDoReward, int iEventNpcIDX, CGameOBJ* pCallOBJ, short nSelectReward) { return CallMemberFunction<CQuestDATA, eQST_RESULT, CUserDATA*, unsigned long, bool, int, CGameOBJ*, short>(0x100997F0, this, pUSER, HashQuest, bDoReward, iEventNpcIDX, pCallOBJ, nSelectReward); }
CQuestTRIGGER* CQuestDATA::GetQuest(unsigned long HashQuest) { return CallMemberFunction<CQuestDATA, CQuestTRIGGER*, unsigned long>(0x10001EE0, this, HashQuest); }
void CQuestDATA::CheckAllQuest(CUserDATA* pUSER) { return CallMemberFunction<CQuestDATA, void, CUserDATA*>(0x10098CB0, this, pUSER); }
bool CQuestDATA::IsEnable() { return CallMemberFunction<CQuestDATA, bool>(0x10016530, this); }
void CQuestDATA::ToggleEnable() { return CallMemberFunction<CQuestDATA, void>(0x10016550, this); }
long CQuestDATA::GetRefCNT() { return CallMemberFunction<CQuestDATA, long>(0x10016580, this); }



