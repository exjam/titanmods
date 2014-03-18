#include "GS_CThreadMALL.h"

bool GS_CThreadMALL::Send_gsv_MALL_ITEM_REPLAY(classUSER* pUSER, unsigned char btType, unsigned char btData) { return CallMemberFunction<GS_CThreadMALL, bool, classUSER*, unsigned char, unsigned char>(0x10090CA0, this, pUSER, btType, btData); }
bool GS_CThreadMALL::Give_MallITEM(tagQueryDATA* pSqlPACKET, unsigned char btMallInvIDX, short nDupCnt) { return CallMemberFunction<GS_CThreadMALL, bool, tagQueryDATA*, unsigned char, short>(0x10091290, this, pSqlPACKET, btMallInvIDX, nDupCnt); }
bool GS_CThreadMALL::Bring_MallITEM(tagQueryDATA* pSqlPACKET, unsigned char btMallInvIDX, short nDupCnt) { return CallMemberFunction<GS_CThreadMALL, bool, tagQueryDATA*, unsigned char, short>(0x10090D20, this, pSqlPACKET, btMallInvIDX, nDupCnt); }
bool GS_CThreadMALL::List_MallITEM(int iScoketIDX, char* szAccount) { return CallMemberFunction<GS_CThreadMALL, bool, int, char*>(0x100915F0, this, iScoketIDX, szAccount); }
bool GS_CThreadMALL::Run_SqlPACKET(tagQueryDATA* pSqlPACKET) { return CallMemberFunction<GS_CThreadMALL, bool, tagQueryDATA*>(0x10091A20, this, pSqlPACKET); }
void GS_CThreadMALL::Execute() { return CallMemberFunction<GS_CThreadMALL, void>(0x10090AC0, this); }
GS_CThreadMALL::GS_CThreadMALL() {};
GS_CThreadMALL::~GS_CThreadMALL() {};
bool GS_CThreadMALL::Add_SqlPacketWithACCOUNT(classUSER* pUSER, t_PACKET* pPacket) { return CallMemberFunction<GS_CThreadMALL, bool, classUSER*, t_PACKET*>(0x10090C50, this, pUSER, pPacket); }
bool GS_CThreadMALL::Add_SqlPacketWithAVATAR(classUSER* pUSER, t_PACKET* pPacket) { return CallMemberFunction<GS_CThreadMALL, bool, classUSER*, t_PACKET*>(0x10090980, this, pUSER, pPacket); }



