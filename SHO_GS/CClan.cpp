#include "CClan.h"

CClan::CClan() {};
CClan::~CClan() {};
void CClan::Init(char* szName, char* szDesc, unsigned long dwClanID, unsigned short wMark1, unsigned short wMark2, unsigned char* pClanBIN, unsigned short wMarkCRC, short nMarkDataLen, unsigned char* pClanMARK) { return CallMemberFunction<CClan, void, char*, char*, unsigned long, unsigned short, unsigned short, unsigned char*, unsigned short, short, unsigned char*>(0x10004FD0, this, szName, szDesc, dwClanID, wMark1, wMark2, pClanBIN, wMarkCRC, nMarkDataLen, pClanMARK); }
void CClan::Free() { return CallMemberFunction<CClan, void>(0x10005110, this); }
int CClan::GetUserLimitCNT() { return CallMemberFunction<CClan, int>(0x10005180, this); }
int CClan::GetPositionLimitCNT(int iPos) { return CallMemberFunction<CClan, int, int>(0x100051A0, this, iPos); }
void CClan::Disband() { return CallMemberFunction<CClan, void>(0x100A41F0, this); }
bool CClan::LogIn_ClanUSER(char* szCharName, int iSenderSockIDX, int iContribute) { return CallMemberFunction<CClan, bool, char*, int, int>(0x100A5090, this, szCharName, iSenderSockIDX, iContribute); }
bool CClan::LogOut_ClanUSER(char* szCharName) { return CallMemberFunction<CClan, bool, char*>(0x100A4FC0, this, szCharName); }
bool CClan::Send_SetCLAN(unsigned char btCMD, classUSER* pMember) { return CallMemberFunction<CClan, bool, unsigned char, classUSER*>(0x100A3DE0, this, btCMD, pMember); }
bool CClan::Send_MemberSTATUS(CClanUSER* pClanUser, unsigned char btResult) { return CallMemberFunction<CClan, bool, CClanUSER*, unsigned char>(0x100A40F0, this, pClanUser, btResult); }
bool CClan::Insert_MEMBER(unsigned char btResult, classUSER* pMember, int iClanPos, char* szMaster) { return CallMemberFunction<CClan, bool, unsigned char, classUSER*, int, char*>(0x100A49B0, this, btResult, pMember, iClanPos, szMaster); }
bool CClan::Delete_MEMBER(unsigned long HashCommander, char* szCharName, unsigned char btCMD, char* szKicker) { return CallMemberFunction<CClan, bool, unsigned long, char*, unsigned char, char*>(0x100A3C30, this, HashCommander, szCharName, btCMD, szKicker); }
bool CClan::Update_MEMBER() { return CallMemberFunction<CClan, bool>(0x100A1CB0, this); }
bool CClan::Adjust_MEMBER(unsigned long HashCommander, char* szCharName, int iAdjContr, int iAdjPos, char* szMaster, int iMaxPos, int iMinPos, bool bCheckPosLimit) { return CallMemberFunction<CClan, bool, unsigned long, char*, int, int, char*, int, int, bool>(0x100A46F0, this, HashCommander, szCharName, iAdjContr, iAdjPos, szMaster, iMaxPos, iMinPos, bCheckPosLimit); }
unsigned long CClan::GetCurAbsSEC() { return CallMemberFunction<CClan, unsigned long>(0x100A1CD0, this); }
unsigned char CClan::FindClanSKILL(short nSkillNo1, short nSkillNo2) { return CallMemberFunction<CClan, unsigned char, short, short>(0x100A2A00, this, nSkillNo1, nSkillNo2); }
bool CClan::AddClanSKILL(short nSkillNo) { return CallMemberFunction<CClan, bool, short>(0x100A4DF0, this, nSkillNo); }
bool CClan::DelClanSKILL(short nSkillNo) { return CallMemberFunction<CClan, bool, short>(0x100A4C80, this, nSkillNo); }
bool CClan::SetClanMARK(unsigned char* pMarkData, short nDataLen, unsigned short wMarkCRC16, classUSER* pReqUSER) { return CallMemberFunction<CClan, bool, unsigned char*, short, unsigned short, classUSER*>(0x100A37C0, this, pMarkData, nDataLen, wMarkCRC16, pReqUSER); }
void CClan::SetJOBnLEV(unsigned long HashCHAR, char* szCharName, short nJob, short nLev) { return CallMemberFunction<CClan, void, unsigned long, char*, short, short>(0x100A3FC0, this, HashCHAR, szCharName, nJob, nLev); }
void CClan::SendRoster(int iSenderSockIDX) { return CallMemberFunction<CClan, void, int>(0x100A3A90, this, iSenderSockIDX); }
void CClan::Send_UpdateInfo() { return CallMemberFunction<CClan, void>(0x100A44A0, this); }
void CClan::SendPacketToMEMBER(classPACKET* pCPacket) { return CallMemberFunction<CClan, void, classPACKET*>(0x100A2940, this, pCPacket); }
bool CClan::Send_wsv_CLAN_COMMAND(unsigned char btCMD) { return CallMemberFunction<CClan, bool, unsigned char>(0x100A39D0, this, btCMD); }
bool CClan::Send_wsv_CLANMARK_REG_TIME(classUSER* pMember) { return CallMemberFunction<CClan, bool, classUSER*>(0x100A36E0, this, pMember); }



