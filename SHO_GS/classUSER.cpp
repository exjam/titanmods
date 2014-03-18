#include "classUSER.h"

short classUSER::GuildCMD(char* szCMD) { return CallMemberFunction<classUSER, short, char*>(0x1008CB00, this, szCMD); }
short classUSER::Parse_CheatCODE(char* szCode) { return CallMemberFunction<classUSER, short, char*>(0x1008D6E0, this, szCode); }
short classUSER::Check_CheatCODE(char* szCode) { return CallMemberFunction<classUSER, short, char*>(0x1008E4E0, this, szCode); }
bool classUSER::Do_SelfSKILL(short nSkillIDX) { return CallMemberFunction<classUSER, bool, short>(0x1007AFE0, this, nSkillIDX); }
bool classUSER::Do_TargetSKILL(int iTargetObject, short nSkillIDX) { return CallMemberFunction<classUSER, bool, int, short>(0x1007AEC0, this, iTargetObject, nSkillIDX); }
bool classUSER::Is_SelfSKILL(short nSkillIDX) { return CallMemberFunction<classUSER, bool, short>(0x100797D0, this, nSkillIDX); }
bool classUSER::Is_TargetSKILL(short nSkillIDX) { return CallMemberFunction<classUSER, bool, short>(0x10079750, this, nSkillIDX); }
bool classUSER::Use_pITEM(tagITEM* pITEM) { return CallMemberFunction<classUSER, bool, tagITEM*>(0x10080140, this, pITEM); }
bool classUSER::Use_InventoryITEM(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10089940, this, pPacket); }
classPACKET* classUSER::Init_gsv_SET_MONEYnINV(unsigned short wType) { return CallMemberFunction<classUSER, classPACKET*, unsigned short>(0x100800E0, this, wType); }
bool classUSER::Send_gsv_SET_MONEYnINV(classPACKET* pCPacket) { return CallMemberFunction<classUSER, bool, classPACKET*>(0x1007AE30, this, pCPacket); }
bool classUSER::Send_gsv_USE_ITEM(short nItemNO, short nInvIDX) { return CallMemberFunction<classUSER, bool, short, short>(0x10080380, this, nItemNO, nInvIDX); }
bool classUSER::Send_gsv_JOIN_ZONE(CZoneTHREAD* pZONE) { return CallMemberFunction<classUSER, bool, CZoneTHREAD*>(0x10089660, this, pZONE); }
bool classUSER::Send_gsv_LEVELUP(short nLevelDIFF) { return CallMemberFunction<classUSER, bool, short>(0x100893E0, this, nLevelDIFF); }
bool classUSER::Check_WarpPayment(short nZoneNO) { return CallMemberFunction<classUSER, bool, short>(0x1007FA50, this, nZoneNO); }
short classUSER::Proc_TELEPORT(short nZoneNO, CVec2& PosWARP, bool bSkipPayment) { return CallMemberFunction<classUSER, short, short, CVec2&, bool>(0x10089130, this, nZoneNO, PosWARP, bSkipPayment); }
bool classUSER::Send_gsv_ADJUST_POS(bool bOnlySelf) { return CallMemberFunction<classUSER, bool, bool>(0x1007F940, this, bOnlySelf); }
bool classUSER::Send_gsv_CREATE_ITEM_REPLY(unsigned char btResult, short nStepORInvIDX, float* pProcPOINT, tagITEM* pOutItem) { return CallMemberFunction<classUSER, bool, unsigned char, short, float*, tagITEM*>(0x1007E670, this, btResult, nStepORInvIDX, pProcPOINT, pOutItem); }
bool classUSER::Send_gsv_STORE_TRADE_REPLY(unsigned char btResult) { return CallMemberFunction<classUSER, bool, unsigned char>(0x1007E980, this, btResult); }
bool classUSER::Send_gsv_QUEST_REPLY(unsigned char btResult, unsigned char btSlot, int iQuestID) { return CallMemberFunction<classUSER, bool, unsigned char, unsigned char, int>(0x1007C850, this, btResult, btSlot, iQuestID); }
bool classUSER::Send_gsv_SET_INV_ONLY(unsigned char btInvIDX, tagITEM* pITEM, unsigned short wType) { return CallMemberFunction<classUSER, bool, unsigned char, tagITEM*, unsigned short>(0x1007F040, this, btInvIDX, pITEM, wType); }
bool classUSER::Send_gsv_SET_TWO_INV_ONLY(unsigned short wType, unsigned char btInvIdx1, tagITEM* pITEM1, unsigned char btInvIdx2, tagITEM* pITEM2) { return CallMemberFunction<classUSER, bool, unsigned short, unsigned char, tagITEM*, unsigned char, tagITEM*>(0x1007EF70, this, wType, btInvIdx1, pITEM1, btInvIdx2, pITEM2); }
bool classUSER::Send_gsv_P_STORE_OPENED() { return CallMemberFunction<classUSER, bool>(0x1007D860, this); }
bool classUSER::Send_gsv_LOGOUT_REPLY(unsigned short wWaitSec) { return CallMemberFunction<classUSER, bool, unsigned short>(0x100805F0, this, wWaitSec); }
bool classUSER::Send_gsv_CHARSTATE_CHANGE(unsigned long dwFLAG) { return CallMemberFunction<classUSER, bool, unsigned long>(0x1007B240, this, dwFLAG); }
bool classUSER::Recv_cli_ALIVE() { return CallMemberFunction<classUSER, bool>(0x10080AA0, this); }
bool classUSER::Recv_cli_STRESS_TEST(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x100798D0, this, pPacket); }
short classUSER::Recv_cli_RELAY_REPLY(t_PACKET* pPacket) { return CallMemberFunction<classUSER, short, t_PACKET*>(0x1008CAA0, this, pPacket); }
bool classUSER::Recv_cli_JOIN_SERVER_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x100890D0, this, pPacket); }
bool classUSER::Recv_cli_CREATE_CHAR(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007AD60, this, pPacket); }
bool classUSER::Recv_cli_DELETE_CHAR(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007ACA0, this, pPacket); }
bool classUSER::Recv_cli_CHAR_LIST(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007ADF0, this, pPacket); }
bool classUSER::Recv_cli_SET_VAR_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007EE80, this, pPacket); }
bool classUSER::Recv_cli_JOIN_ZONE(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10088F40, this, pPacket); }
short classUSER::Recv_cli_REVIVE_REQ(unsigned char btReviveTYPE, bool bApplyPenalty, bool bSkipPayment) { return CallMemberFunction<classUSER, short, unsigned char, bool, bool>(0x1008C690, this, btReviveTYPE, bApplyPenalty, bSkipPayment); }
bool classUSER::Recv_cli_SET_REVIVE_POS() { return CallMemberFunction<classUSER, bool>(0x10079AA0, this); }
bool classUSER::Recv_cli_TOGGLE(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10088EF0, this, pPacket); }
bool classUSER::Recv_cli_SET_MOTION(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007EDE0, this, pPacket); }
short classUSER::Recv_cli_CHAT(t_PACKET* pPacket) { return CallMemberFunction<classUSER, short, t_PACKET*>(0x1008E7E0, this, pPacket); }
short classUSER::Recv_cli_SHOUT(t_PACKET* pPacket) { return CallMemberFunction<classUSER, short, t_PACKET*>(0x1008E6F0, this, pPacket); }
bool classUSER::Recv_cli_WHISPER(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10088D90, this, pPacket); }
short classUSER::Recv_cli_PARTY_CHAT(t_PACKET* pPacket) { return CallMemberFunction<classUSER, short, t_PACKET*>(0x1008E5B0, this, pPacket); }
void classUSER::LogCHAT(const char* szMSG, const char* pDestCHAR, const char* szMsgTYPE) { return CallMemberFunction<classUSER, void, const char*, const char*, const char*>(0x10079650, this, szMSG, pDestCHAR, szMsgTYPE); }
short classUSER::Recv_cli_ALLIED_CHAT(t_PACKET* pPacket) { return CallMemberFunction<classUSER, short, t_PACKET*>(0x1008EB40, this, pPacket); }
short classUSER::Recv_cli_ALLIED_SHOUT(t_PACKET* pPacket) { return CallMemberFunction<classUSER, short, t_PACKET*>(0x1008E990, this, pPacket); }
bool classUSER::Recv_cli_STOP(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10079880, this, pPacket); }
bool classUSER::Recv_cli_ATTACK(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007A1F0, this, pPacket); }
bool classUSER::Recv_cli_DAMAGE(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10079860, this, pPacket); }
bool classUSER::Recv_cli_MOUSECMD(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007A090, this, pPacket); }
bool classUSER::Recv_cli_SET_WEIGHT_RATE(unsigned char btWeightRate, bool bSend2Around) { return CallMemberFunction<classUSER, bool, unsigned char, bool>(0x1007EC70, this, btWeightRate, bSend2Around); }
bool classUSER::Recv_cli_CANTMOVE(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10088BB0, this, pPacket); }
bool classUSER::Recv_cli_SETPOS(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10088AB0, this, pPacket); }
bool classUSER::Send_gsv_CHANGE_SKIN(unsigned short wAbilityTYPE, int iValue) { return CallMemberFunction<classUSER, bool, unsigned short, int>(0x1007EBB0, this, wAbilityTYPE, iValue); }
bool classUSER::Recv_cli_DROP_ITEM(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10085540, this, pPacket); }
bool classUSER::Send_gsv_EQUIP_ITEM(short nEquipInvIDX, tagITEM* pEquipITEM) { return CallMemberFunction<classUSER, bool, short, tagITEM*>(0x1007EA00, this, nEquipInvIDX, pEquipITEM); }
bool classUSER::Change_EQUIP_ITEM(short nEquipInvIDX, short nWeaponInvIDX) { return CallMemberFunction<classUSER, bool, short, short>(0x10088550, this, nEquipInvIDX, nWeaponInvIDX); }
bool classUSER::Recv_cli_EQUIP_ITEM(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1008C5B0, this, pPacket); }
bool classUSER::Recv_cli_ASSEMBLE_RIDE_ITEM(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10088120, this, pPacket); }
bool classUSER::Recv_cli_STORE_TRADE_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10087650, this, pPacket); }
bool classUSER::Recv_cli_USE_ITEM(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1008C470, this, pPacket); }
bool classUSER::Recv_cli_SET_HOTICON(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007E8A0, this, pPacket); }
bool classUSER::Send_gsv_SET_BULLET(unsigned char btShotTYPE) { return CallMemberFunction<classUSER, bool, unsigned char>(0x1007E760, this, btShotTYPE); }
bool classUSER::Recv_cli_SET_BULLET(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10087070, this, pPacket); }
bool classUSER::Recv_cli_CREATE_ITEM_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10085A10, this, pPacket); }
bool classUSER::Send_gsv_ITEM_RESULT_REPORT(unsigned char btReport, unsigned char btItemType, short nItemNo) { return CallMemberFunction<classUSER, bool, unsigned char, unsigned char, short>(0x1007E5A0, this, btReport, btItemType, nItemNo); }
bool classUSER::Recv_cli_ITEM_RESULT_REPORT(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1008C4F0, this, pPacket); }
bool classUSER::Recv_cli_HP_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10079FD0, this, pPacket); }
bool classUSER::Recv_cli_GET_FIELDITEM_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1008C230, this, pPacket); }
bool classUSER::Recv_cli_MOVE_ZULY(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007E350, this, pPacket); }
bool classUSER::Recv_cli_MOVE_ITEM(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007D980, this, pPacket); }
bool classUSER::Recv_cli_BANK_LIST_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10085210, this, pPacket); }
short classUSER::Recv_cli_TELEPORT_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, short, t_PACKET*>(0x1008BFB0, this, pPacket); }
bool classUSER::Recv_cli_USE_BPOINT_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10084FE0, this, pPacket); }
bool classUSER::Recv_cli_SKILL_LEVELUP_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007D180, this, pPacket); }
bool classUSER::Recv_cli_SELF_SKILL(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007CEC0, this, pPacket); }
bool classUSER::Recv_cli_TARGET_SKILL(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007CC10, this, pPacket); }
bool classUSER::Recv_cli_POSITION_SKILL(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007C8F0, this, pPacket); }
bool classUSER::Recv_cli_TRADE_P2P(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1008B8B0, this, pPacket); }
bool classUSER::Recv_cli_TRADE_P2P_ITEM(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10084A80, this, pPacket); }
bool classUSER::Recv_cli_SET_WISHITEM(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10079D80, this, pPacket); }
classPACKET* classUSER::Init_gsv_P_STORE_RESULT(unsigned short wObjectIDX) { return CallMemberFunction<classUSER, classPACKET*, unsigned short>(0x1007D460, this, wObjectIDX); }
bool classUSER::Send_gsv_P_STORE_RESULT(unsigned short wObjectIDX, unsigned char btResult) { return CallMemberFunction<classUSER, bool, unsigned short, unsigned char>(0x1007D3D0, this, wObjectIDX, btResult); }
bool classUSER::Recv_cli_P_STORE_OPEN(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x100843F0, this, pPacket); }
bool classUSER::Recv_cli_P_STORE_CLOSE(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007D770, this, pPacket); }
bool classUSER::Recv_cli_P_STORE_LIST_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007D4C0, this, pPacket); }
bool classUSER::Recv_cli_P_STORE_BUY_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10083E80, this, pPacket); }
bool classUSER::Recv_cli_P_STORE_SELL_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10083850, this, pPacket); }
bool classUSER::Recv_cli_QUEST_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1008B7E0, this, pPacket); }
bool classUSER::Recv_cli_PARTY_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1008B370, this, pPacket); }
bool classUSER::Recv_cli_PARTY_REPLY(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1008D480, this, pPacket); }
bool classUSER::Recv_cli_APPRAISAL_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x100833B0, this, pPacket); }
bool classUSER::Recv_cli_USE_ITEM_TO_REPAIR(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x100830F0, this, pPacket); }
bool classUSER::Recv_cli_REPAIR_FROM_NPC(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10082E70, this, pPacket); }
bool classUSER::Send_wsv_MESSENGER(unsigned char Var1, char* Var2) { return 0; }
bool classUSER::Recv_cli_MESSENGER(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10079730, this, pPacket); }
bool classUSER::Send_tag_MCMD_HEADER(unsigned char btCMD, char* szStr) { return CallMemberFunction<classUSER, bool, unsigned char, char*>(0x1007C720, this, btCMD, szStr); }
bool classUSER::Recv_cli_MCMD_APPEND_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10082D70, this, pPacket); }
bool classUSER::Recv_cli_MESSENGER_CHAT(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10079710, this, pPacket); }
bool classUSER::Send_gsv_CRAFT_ITEM_RESULT(unsigned char btRESULT) { return CallMemberFunction<classUSER, bool, unsigned char>(0x1007C690, this, btRESULT); }
classPACKET* classUSER::Init_gsv_CRAFT_ITEM_REPLY() { return CallMemberFunction<classUSER, classPACKET*>(0x1007C650, this); }
void classUSER::Send_gsv_CRAFT_ITEM_REPLY(classPACKET* pCPacket, unsigned char btRESULT, unsigned char btOutCNT) { return CallMemberFunction<classUSER, void, classPACKET*, unsigned char, unsigned char>(0x1007AA80, this, pCPacket, btRESULT, btOutCNT); }
bool classUSER::Proc_CRAFT_GEMMING_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10082B30, this, pPacket); }
bool classUSER::Proc_CRAFT_BREAKUP_REQ(t_PACKET* pPacket, bool bUseMP) { return CallMemberFunction<classUSER, bool, t_PACKET*, bool>(0x10082230, this, pPacket, bUseMP); }
bool classUSER::Proc_RENEWAL_CRAFT_BREAKUP_REQ(t_PACKET* pPacket, unsigned char btType) { return CallMemberFunction<classUSER, bool, t_PACKET*, unsigned char>(0x10081990, this, pPacket, btType); }
bool classUSER::Proc_CRAFT_UPGRADE_REQ(t_PACKET* pPacket, bool bUseMP) { return CallMemberFunction<classUSER, bool, t_PACKET*, bool>(0x10080F80, this, pPacket, bUseMP); }
bool classUSER::Recv_cli_CRAFT_ITEM_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1008B0D0, this, pPacket); }
bool classUSER::Recv_cli_PARTY_RULE(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10080ED0, this, pPacket); }
bool classUSER::Proc_CRAFT_DRILL_SOCKET(t_PACKET* pPacket, unsigned char btType) { return CallMemberFunction<classUSER, bool, t_PACKET*, unsigned char>(0x10081750, this, pPacket, btType); }
bool classUSER::Recv_cli_CLAN_COMMAND(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007BCC0, this, pPacket); }
bool classUSER::Recv_cli_CLAN_CHAT(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x100796A0, this, pPacket); }
bool classUSER::Recv_mon_SERVER_LIST_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007C5C0, this, pPacket); }
bool classUSER::Recv_mon_SERVER_STATUS_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007C530, this, pPacket); }
bool classUSER::Recv_mon_SERVER_ANNOUNCE(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1008B020, this, pPacket); }
bool classUSER::Recv_ost_SERVER_USERLOGOUT(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007C460, this, pPacket); }
bool classUSER::Send_gsv_SERVER_USERLOGOUT_REPLY(const char* szAccount, bool bLogOuted) { return CallMemberFunction<classUSER, bool, const char*, bool>(0x1007C3C0, this, szAccount, bLogOuted); }
bool classUSER::Recv_ost_SERVER_ZONEINFO(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007C130, this, pPacket); }
bool classUSER::Send_gsv_SERVER_ZONEINFO_REPLY() { return CallMemberFunction<classUSER, bool>(0x1007BF70, this); }
bool classUSER::Recv_ost_SERVER_USERINFO(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007C310, this, pPacket); }
bool classUSER::Send_gsv_SERVER_USERINFO_REPLY(const char* szACCOUNT, classUSER* pUSER) { return CallMemberFunction<classUSER, bool, const char*, classUSER*>(0x1007C160, this, szACCOUNT, pUSER); }
bool classUSER::Recv_ost_SERVER_CHGUSER(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10080C90, this, pPacket); }
bool classUSER::Send_gsv_SERVER_CHGUSER_REPLY(classUSER* pUSER, unsigned long dwSTATUS, unsigned long dwCMD) { return CallMemberFunction<classUSER, bool, classUSER*, unsigned long, unsigned long>(0x10080AE0, this, pUSER, dwSTATUS, dwCMD); }
bool classUSER::Recv_ost_SERVER_MOVECHR(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1008AF40, this, pPacket); }
bool classUSER::Send_gsv_SERVER_MOVECHR_REPLY(classUSER* pUSER, short nZoneNO, short nX, short nY) { return CallMemberFunction<classUSER, bool, classUSER*, short, short, short>(0x1008AD30, this, pUSER, nZoneNO, nX, nY); }
bool classUSER::Recv_ost_SERVER_ZONEANNOUNCE(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10080D50, this, pPacket); }
bool classUSER::Recv_ost_SERVER_IPSEARCH(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007BEC0, this, pPacket); }
bool classUSER::Send_gsv_SERVER_IPSEARCH_REPLY(classUSER* pUSER) { return CallMemberFunction<classUSER, bool, classUSER*>(0x1007BDE0, this, pUSER); }
bool classUSER::Recv_cli_MALL_ITEM_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007A7D0, this, pPacket); }
bool classUSER::Recv_cli_CLANMARK_SET(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007B130, this, pPacket); }
bool classUSER::Recv_cli_CLANMARK_REQ(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007B0F0, this, pPacket); }
bool classUSER::Recv_cli_CLANMARK_REG_TIME(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007B0B0, this, pPacket); }
bool classUSER::Recv_cli_CART_RIDE(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007B3F0, this, pPacket); }
bool classUSER::Send_gsv_CART_RIDE(unsigned char btType, unsigned short wSourObjIdx, unsigned short wDestObjIdx, bool bSendToSector) { return CallMemberFunction<classUSER, bool, unsigned char, unsigned short, unsigned short, bool>(0x1007B300, this, btType, wSourObjIdx, wDestObjIdx, bSendToSector); }
bool classUSER::Send_wsv_CLANMARK_REPLY(unsigned long dwClanID, unsigned short wMarkCRC, unsigned char* pMarkData, short nDataLen) { return CallMemberFunction<classUSER, bool, unsigned long, unsigned short, unsigned char*, short>(0x100807F0, this, dwClanID, wMarkCRC, pMarkData, nDataLen); }
void classUSER::Save_ItemToFILED(tagITEM& sDropITEM, int iRemainTime) { return CallMemberFunction<classUSER, void, tagITEM&, int>(0x10080660, this, sDropITEM, iRemainTime); }
bool classUSER::Pick_ITEM(CObjITEM* pITEM) { return CallMemberFunction<classUSER, bool, CObjITEM*>(0x10085370, this, pITEM); }
bool classUSER::Send_gsv_SET_HPnMP(unsigned char btApply) { return CallMemberFunction<classUSER, bool, unsigned char>(0x100804F0, this, btApply); }
bool classUSER::Send_wsv_CHATROOM(unsigned char btCMD, unsigned short wUserID, char* szSTR) { return CallMemberFunction<classUSER, bool, unsigned char, unsigned short, char*>(0x10080430, this, btCMD, wUserID, szSTR); }
bool classUSER::Recv_cli_SELECT_CHAR(t_PACKET* pPacket, bool bFirstZONE, unsigned char btRunMODE, unsigned char btRideMODE) { return CallMemberFunction<classUSER, bool, t_PACKET*, bool, unsigned char, unsigned char>(0x1007ADA0, this, pPacket, bFirstZONE, btRunMODE, btRideMODE); }
bool classUSER::Send_gsv_GM_COMMAND(char* szAccount, unsigned char btCMD, unsigned short wBlockTIME) { return CallMemberFunction<classUSER, bool, char*, unsigned char, unsigned short>(0x10080040, this, szAccount, btCMD, wBlockTIME); }
bool classUSER::Send_gsv_TELEPORT_REPLY(CVec2& PosWARP, short nZoneNO) { return CallMemberFunction<classUSER, bool, CVec2&, short>(0x1007FBB0, this, PosWARP, nZoneNO); }
bool classUSER::Send_gsv_INVENTORYnQUEST_DATA() { return CallMemberFunction<classUSER, bool>(0x1007FD30, this); }
bool classUSER::Send_srv_JOIN_SERVER_REPLY(t_PACKET* pRecvPket, char* szAccount) { return CallMemberFunction<classUSER, bool, t_PACKET*, char*>(0x1007FEA0, this, pRecvPket, szAccount); }
bool classUSER::Send_gsv_CHECK_NPC_EVENT(short nNpcIDX) { return CallMemberFunction<classUSER, bool, short>(0x1008A0A0, this, nNpcIDX); }
bool classUSER::Send_gsv_SETEXP(unsigned short wFromObjIDX) { return CallMemberFunction<classUSER, bool, unsigned short>(0x1007FC80, this, wFromObjIDX); }
bool classUSER::Send_gsv_HP_REPLY(int iObjectIDX, int iHP) { return CallMemberFunction<classUSER, bool, int, int>(0x1007F710, this, iObjectIDX, iHP); }
bool classUSER::Send_gsv_WHISPER(char* szFromAccount, const char* szMessage) { return CallMemberFunction<classUSER, bool, char*, const char*>(0x1007F670, this, szFromAccount, szMessage); }
unsigned char classUSER::Send_gsv_SKILL_LEARN_REPLY(short nSkillIDX, bool bCheckCOND) { return CallMemberFunction<classUSER, unsigned char, short, bool>(0x1007F7A0, this, nSkillIDX, bCheckCOND); }
bool classUSER::Send_gsv_TRADE_P2P(int iObjectIDX, unsigned char btResult, char cTradeSLOT) { return CallMemberFunction<classUSER, bool, int, unsigned char, char>(0x1007F5D0, this, iObjectIDX, btResult, cTradeSLOT); }
bool classUSER::Send_gsv_TRADE_P2P_ITEM(char cTradeSLOT, tagITEM& sITEM) { return CallMemberFunction<classUSER, bool, char, tagITEM&>(0x1007F530, this, cTradeSLOT, sITEM); }
bool classUSER::Send_gsv_BANK_ITEM_LIST(bool bNewBank) { return CallMemberFunction<classUSER, bool, bool>(0x1007F2A0, this, bNewBank); }
bool classUSER::Send_gsv_BANK_LIST_REPLY(unsigned char btReply) { return CallMemberFunction<classUSER, bool, unsigned char>(0x1007F210, this, btReply); }
bool classUSER::Send_gsv_PARTY_REQ(int iObjectIDXorTAG, unsigned char btReq) { return CallMemberFunction<classUSER, bool, int, unsigned char>(0x1007F180, this, iObjectIDXorTAG, btReq); }
bool classUSER::Send_gsv_PARTY_REPLY(int iObjectIDXorTAG, unsigned char btReply) { return CallMemberFunction<classUSER, bool, int, unsigned char>(0x1007F0F0, this, iObjectIDXorTAG, btReply); }
bool classUSER::Send_gsv_RELAY_REQ(unsigned short wRelayTYPE, short nZoneGOTO, CVec2& PosGOTO) { return CallMemberFunction<classUSER, bool, unsigned short, short, CVec2&>(0x1007EEC0, this, wRelayTYPE, nZoneGOTO, PosGOTO); }
bool classUSER::Send_gsv_SET_MONEYONLY(unsigned short wType) { return CallMemberFunction<classUSER, bool, unsigned short>(0x1007FFA0, this, wType); }
bool classUSER::Send_BulltCOUNT() { return CallMemberFunction<classUSER, bool>(0x100875E0, this); }
bool classUSER::Send_gsv_SET_ITEM_LIFE(short nInvIDX, short nLife) { return CallMemberFunction<classUSER, bool, short, short>(0x1007C7C0, this, nInvIDX, nLife); }
bool classUSER::Send_gsv_SPEED_CHANGED(bool bUpdateSpeed) { return CallMemberFunction<classUSER, bool, bool>(0x10087FE0, this, bUpdateSpeed); }
bool classUSER::Do_QuestTRIGGER(unsigned long HashTRIGGER, short nSelectReward) { return CallMemberFunction<classUSER, bool, unsigned long, short>(0x10083680, this, HashTRIGGER, nSelectReward); }
bool classUSER::Send_wsv_CLAN_COMMAND(unsigned char btCMD) { return CallMemberFunction<classUSER, bool, unsigned char>(0x1007BBE0, this, btCMD); }
bool classUSER::Send_wsv_RESULT_CLAN_SET(char* szClanName) { return CallMemberFunction<classUSER, bool, char*>(0x1007B5F0, this, szClanName); }
bool classUSER::Send_gsv_BILLING_MESSAGE(unsigned char btMsgType, char* szMsg) { return CallMemberFunction<classUSER, bool, unsigned char, char*>(0x1007BB20, this, btMsgType, szMsg); }
bool classUSER::Send_gsv_BILLING_MESSAGE_EXT(unsigned short wMsgType, unsigned long dwPayType, unsigned long* pPlayFlag, char* szMsg) { return CallMemberFunction<classUSER, bool, unsigned short, unsigned long, unsigned long*, char*>(0x1007BA60, this, wMsgType, dwPayType, pPlayFlag, szMsg); }
bool classUSER::Send_gsv_BILLING_MESSAGE2(unsigned char btType, char cFunctionType, unsigned long dwPayFlag) { return CallMemberFunction<classUSER, bool, unsigned char, char, unsigned long>(0x1007B9C0, this, btType, cFunctionType, dwPayFlag); }
bool classUSER::Send_srv_ERROR(unsigned short wErrCODE) { return CallMemberFunction<classUSER, bool, unsigned short>(0x1007BD50, this, wErrCODE); }
bool classUSER::Check_ItemEventMSG(tagITEM& sITEM) { return CallMemberFunction<classUSER, bool, tagITEM&>(0x10079840, this, sITEM); }
bool classUSER::Send_srv_CHECK_AUTH() { return CallMemberFunction<classUSER, bool>(0x100796F0, this); }
bool classUSER::Recv_cli_CHECK_AUTH(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x100796D0, this, pPacket); }
bool classUSER::Recv_cli_SCREEN_SHOT_TIME(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x1007B990, this, pPacket); }
bool classUSER::Send_gsv_SCREEN_SHOT_TIME() { return CallMemberFunction<classUSER, bool>(0x1007B890, this); }
bool classUSER::Recv_cli_SUMMON_CMD(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x10079670, this, pPacket); }
bool classUSER::Add_MoneyNSend(int iAmount, unsigned short wType) { return CallMemberFunction<classUSER, bool, int, unsigned short>(0x10009DD0, this, iAmount, wType); }
bool classUSER::Add_ExpNSend(int iExp) { return CallMemberFunction<classUSER, bool, int>(0x10009E20, this, iExp); }
bool classUSER::Add_ItemNSend(tagITEM& sITEM) { return CallMemberFunction<classUSER, bool, tagITEM&>(0x10009E60, this, sITEM); }
bool classUSER::Add_SkillNSend(short nSkillIDX) { return CallMemberFunction<classUSER, bool, short>(0x10009F00, this, nSkillIDX); }
bool classUSER::Sub_SkillNSend(short nSkillIDX) { return CallMemberFunction<classUSER, bool, short>(0x10009F40, this, nSkillIDX); }
bool classUSER::Send_gsv_SET_ABILITY(unsigned short wPacketType, unsigned short wAbilityType, int iValue) { return CallMemberFunction<classUSER, bool, unsigned short, unsigned short, int>(0x1000A010, this, wPacketType, wAbilityType, iValue); }
void classUSER::Add_AbilityValueNSend(unsigned short wType, int iValue) { return CallMemberFunction<classUSER, void, unsigned short, int>(0x1000A130, this, wType, iValue); }
bool classUSER::Set_AbilityValueNSend(unsigned short wType, int iValue) { return CallMemberFunction<classUSER, bool, unsigned short, int>(0x1000A180, this, wType, iValue); }
bool classUSER::Quest_CHANGE_SPEED() { return CallMemberFunction<classUSER, bool>(0x1000A1D0, this); }
bool classUSER::Quest_IsPartyLEADER() { return CallMemberFunction<classUSER, bool>(0x1000A220, this); }
int classUSER::Quest_GetPartyLEVEL() { return CallMemberFunction<classUSER, int>(0x1000A2B0, this); }
int classUSER::Quest_PartyMemberCNT() { return CallMemberFunction<classUSER, int>(0x1000A340, this); }
int classUSER::Quest_GetZoneNO() { return CallMemberFunction<classUSER, int>(0x1000A3B0, this); }
int classUSER::Quest_DistanceFrom(int iX, int iY, int iZ) { return CallMemberFunction<classUSER, int, int, int, int>(0x1000A3D0, this, iX, iY, iZ); }
bool classUSER::Reward_WARP(int iZoneNO, CVec2& PosGOTO) { return CallMemberFunction<classUSER, bool, int, CVec2&>(0x10080970, this, iZoneNO, PosGOTO); }
void classUSER::SetCur_JOB(short nValue) { return CallMemberFunction<classUSER, void, short>(0x1000A450, this, nValue); }
bool classUSER::Set_TeamNoFromUNIQUE() { return CallMemberFunction<classUSER, bool>(0x10079C30, this); }
bool classUSER::Set_TeamNoFromClanIDX() { return CallMemberFunction<classUSER, bool>(0x10079BC0, this); }
bool classUSER::Set_TeamNoFromPartyIDX() { return CallMemberFunction<classUSER, bool>(0x100798F0, this); }
bool classUSER::Set_RevivePOS(int iXPos, int iYPos) { return CallMemberFunction<classUSER, bool, int, int>(0x10079B60, this, iXPos, iYPos); }
char* classUSER::Get_StoreTITLE() { return CallMemberFunction<classUSER, char*>(0x1000A4E0, this); }
bool classUSER::Check_TradeITEM() { return CallMemberFunction<classUSER, bool>(0x10079DE0, this); }
void classUSER::RemoveTradeItemFromINV(classUSER* pTradeUSER, classPACKET* pCPacket) { return CallMemberFunction<classUSER, void, classUSER*, classPACKET*>(0x1007AAF0, this, pTradeUSER, pCPacket); }
void classUSER::AddTradeItemToINV(classUSER* pTradeUSER, classPACKET* pCPacket) { return CallMemberFunction<classUSER, void, classUSER*, classPACKET*>(0x10084E40, this, pTradeUSER, pCPacket); }
classUSER::classUSER(const classUSER& Var1) { }
classUSER::classUSER() {};
classUSER::~classUSER() {};
bool classUSER::SendPacket(classPACKET* pCPacket) { return CallMemberFunction<classUSER, bool, classPACKET*>(0x1000A500, this, pCPacket); }
bool classUSER::SendPacketToPARTY(classPACKET* pCPacket) { return CallMemberFunction<classUSER, bool, classPACKET*>(0x1000A530, this, pCPacket); }
bool classUSER::SendPacketIfPARTY(classPACKET* pCPacket) { return CallMemberFunction<classUSER, bool, classPACKET*>(0x1000A5A0, this, pCPacket); }
bool classUSER::SendPacketToPartyExceptME(classPACKET* pCPacket) { return CallMemberFunction<classUSER, bool, classPACKET*>(0x1000A600, this, pCPacket); }
bool classUSER::SendPacketToTARGET(CObjCHAR* pAtkCHAR, classPACKET* pCPacket) { return CallMemberFunction<classUSER, bool, CObjCHAR*, classPACKET*>(0x1000A660, this, pAtkCHAR, pCPacket); }
char* classUSER::Get_ACCOUNT() { return CallMemberFunction<classUSER, char*>(0x100019D0, this); }
unsigned short classUSER::Get_AccountLEN() { return CallMemberFunction<classUSER, unsigned short>(0x10001A00, this); }
void classUSER::Set_ACCOUNT(char* szAccount) { return CallMemberFunction<classUSER, void, char*>(0x1000A710, this, szAccount); }
char* classUSER::Get_MD5PW() { return CallMemberFunction<classUSER, char*>(0x1000A740, this); }
bool classUSER::Check_PartyJoinLEVEL(int iUserLEV, int iAverageLEV, int iPartyLEV) { return CallMemberFunction<classUSER, bool, int, int, int>(0x10010E40, this, iUserLEV, iAverageLEV, iPartyLEV); }
void classUSER::InitUSER() { return CallMemberFunction<classUSER, void>(0x1000A760, this); }
void classUSER::FreeUSER() { return CallMemberFunction<classUSER, void>(0x1000AA40, this); }
bool classUSER::Recv_Done(tagIO_DATA* pRecvDATA) { return CallMemberFunction<classUSER, bool, tagIO_DATA*>(0x10079980, this, pRecvDATA); }
bool classUSER::HandleWorldPACKET() { return CallMemberFunction<classUSER, bool>(0x1007B700, this); }
bool classUSER::HandlePACKET(t_PACKETHEADER* pPacketHeader) { return CallMemberFunction<classUSER, bool, t_PACKETHEADER*>(0x1008D110, this, pPacketHeader); }
int classUSER::Proc_ZonePACKET(t_PACKET* pPacket) { return CallMemberFunction<classUSER, int, t_PACKET*>(0x1008ED90, this, pPacket); }
bool classUSER::IsHacking(char* szDesc, char* szFile, int iLine) { return CallMemberFunction<classUSER, bool, char*, char*, int>(0x1007B180, this, szDesc, szFile, iLine); }
void classUSER::Add_EXP(int iGetExp, bool bApplyStamina, unsigned short wFromObjIDX) { return CallMemberFunction<classUSER, void, int, bool, unsigned short>(0x1008A3E0, this, iGetExp, bApplyStamina, wFromObjIDX); }
bool classUSER::Dead(CObjCHAR* pKiller) { return CallMemberFunction<classUSER, bool, CObjCHAR*>(0x1008A180, this, pKiller); }
CParty* classUSER::GetPARTY() { return CallMemberFunction<classUSER, CParty*>(0x1000AAF0, this); }
void classUSER::CloseNETWORK() { return CallMemberFunction<classUSER, void>(0x1000AB10, this); }
unsigned long classUSER::Get_RIGHT() { return CallMemberFunction<classUSER, unsigned long>(0x1000AB40, this); }
unsigned long classUSER::Get_CharHASH() { return CallMemberFunction<classUSER, unsigned long>(0x1000AB60, this); }
bool classUSER::Chk_ShotITEM(unsigned char btShotCnt) { return CallMemberFunction<classUSER, bool, unsigned char>(0x1000AB80, this, btShotCnt); }
bool classUSER::Dec_ShotITEM(unsigned char btShotCnt) { return CallMemberFunction<classUSER, bool, unsigned char>(0x1000ABD0, this, btShotCnt); }
void classUSER::Set_ShotITEM() { return CallMemberFunction<classUSER, void>(0x1000E320, this); }
void classUSER::Set_ShotITEM(t_eSHOT eShotTYPE) { return CallMemberFunction<classUSER, void, t_eSHOT>(0x1000E2B0, this, eShotTYPE); }
void classUSER::Set_ItemSN(tagITEM& sInITEM) { return CallMemberFunction<classUSER, void, tagITEM&>(0x1000AD00, this, sInITEM); }
bool classUSER::CheckClanCreateCondition(char cStep) { return CallMemberFunction<classUSER, bool, char>(0x1007A370, this, cStep); }
bool classUSER::Send_gsv_ADJ_CLAN_VAR(unsigned char btVarType, int iValue) { return CallMemberFunction<classUSER, bool, unsigned char, int>(0x100808A0, this, btVarType, iValue); }
void classUSER::IncClanLEVEL() { return CallMemberFunction<classUSER, void>(0x1008A960, this); }
void classUSER::AddClanSCORE(int iScore) { return CallMemberFunction<classUSER, void, int>(0x1008A8D0, this, iScore); }
void classUSER::AddClanCONTRIBUTE(int Var1) { return; }
void classUSER::AddClanMONEY(int iMoney) { return CallMemberFunction<classUSER, void, int>(0x1008A920, this, iMoney); }
unsigned char classUSER::FindClanSKILL(short nSkillNo1, short nSkillNo2) { return CallMemberFunction<classUSER, unsigned char, short, short>(0x10079C80, this, nSkillNo1, nSkillNo2); }
bool classUSER::AddClanSKILL(short nSkillNo) { return CallMemberFunction<classUSER, bool, short>(0x1008A9F0, this, nSkillNo); }
bool classUSER::DelClanSKILL(short nSkillNo) { return CallMemberFunction<classUSER, bool, short>(0x1008A9A0, this, nSkillNo); }
bool classUSER::Add_SrvRecvPacket(t_PACKET* pPacket) { return CallMemberFunction<classUSER, bool, t_PACKET*>(0x100799F0, this, pPacket); }
int classUSER::ProcLogOUT() { return CallMemberFunction<classUSER, int>(0x1008AA60, this); }
int classUSER::Proc() { return CallMemberFunction<classUSER, int>(0x1008F7A0, this); }
unsigned short classUSER::E_SendP(t_PACKETHEADER* pPacket) { return CallMemberFunction<classUSER, unsigned short, t_PACKETHEADER*>(0x1000ADB0, this, pPacket); }
unsigned short classUSER::D_RecvH(t_PACKETHEADER* pPacket) { return CallMemberFunction<classUSER, unsigned short, t_PACKETHEADER*>(0x1000ADE0, this, pPacket); }
short classUSER::D_RecvB(t_PACKETHEADER* pPacket) { return CallMemberFunction<classUSER, short, t_PACKETHEADER*>(0x1000AE20, this, pPacket); }
unsigned short classUSER::P_Length(t_PACKETHEADER* pPacket) { return CallMemberFunction<classUSER, unsigned short, t_PACKETHEADER*>(0x1000AE50, this, pPacket); }
unsigned long classUSER::A_Cheater() { return CallMemberFunction<classUSER, unsigned long>(0x10052ED0, this); }
unsigned long classUSER::B_Cheater() { return CallMemberFunction<classUSER, unsigned long>(0x10052E80, this); }
unsigned long classUSER::C_Cheater() { return CallMemberFunction<classUSER, unsigned long>(0x10052E10, this); }
unsigned long classUSER::GM_Cheater() { return CallMemberFunction<classUSER, unsigned long>(0x10052E30, this); }
unsigned long classUSER::TWGM_Cheater() { return CallMemberFunction<classUSER, unsigned long>(0x10052DF0, this); }
short classUSER::Cheat_where(CStrVAR* pStrVAR, char* pArg1, char* pArg2, char* szCode) { return CallMemberFunction<classUSER, short, CStrVAR*, char*, char*, char*>(0x10054A40, this, pStrVAR, pArg1, pArg2, szCode); }
short classUSER::Cheat_account(char* pArg1, char* szCode) { return CallMemberFunction<classUSER, short, char*, char*>(0x100549A0, this, pArg1, szCode); }
short classUSER::Cheat_move(char* pArg1, char* pArg2, char* szCode) { return CallMemberFunction<classUSER, short, char*, char*, char*>(0x10055CC0, this, pArg1, pArg2, szCode); }
short classUSER::Cheat_mm(short nZoneNO, char* pArg2, char* pArg3) { return CallMemberFunction<classUSER, short, short, char*, char*>(0x10055B70, this, nZoneNO, pArg2, pArg3); }
short classUSER::Cheat_npc(CStrVAR* pStrVAR, CObjNPC* pNPC, int iNpcIDX, char* pArg2, char* pArg3, char* pArg4) { return CallMemberFunction<classUSER, short, CStrVAR*, CObjNPC*, int, char*, char*, char*>(0x100555D0, this, pStrVAR, pNPC, iNpcIDX, pArg2, pArg3, pArg4); }
short classUSER::Cheat_add(char* pArg1, char* pArg2, char* pArg3, char* szCode) { return CallMemberFunction<classUSER, short, char*, char*, char*, char*>(0x10055140, this, pArg1, pArg2, pArg3, szCode); }
short classUSER::Cheat_del(CStrVAR* pStrVAR, char* pArg1, char* pArg2, char* pArg3) { return CallMemberFunction<classUSER, short, CStrVAR*, char*, char*, char*>(0x10054DF0, this, pStrVAR, pArg1, pArg2, pArg3); }
short classUSER::Cheat_get(CStrVAR* pStrVAR, char* pArg1, char* pArg2, char* szCode) { return CallMemberFunction<classUSER, short, CStrVAR*, char*, char*, char*>(0x10053B40, this, pStrVAR, pArg1, pArg2, szCode); }
short classUSER::Cheat_out(char* pArg1, char* pArg2, char* szCode) { return CallMemberFunction<classUSER, short, char*, char*, char*>(0x100547F0, this, pArg1, pArg2, szCode); }
short classUSER::Cheat_shut(char* pArg1, char* pArg2, char* pArg3, char* szCode) { return CallMemberFunction<classUSER, short, char*, char*, char*, char*>(0x100546E0, this, pArg1, pArg2, pArg3, szCode); }
short classUSER::Cheat_call(char* pArg1, char* pArg2, char* szCode) { return CallMemberFunction<classUSER, short, char*, char*, char*>(0x100548D0, this, pArg1, pArg2, szCode); }
short classUSER::Cheat_item(char* pArg1, char* pArg2, char* pArg3, char* pArg4) { return CallMemberFunction<classUSER, short, char*, char*, char*, char*>(0x10053860, this, pArg1, pArg2, pArg3, pArg4); }
short classUSER::Cheat_mon(char* pArg1, char* pArg2) { return CallMemberFunction<classUSER, short, char*, char*>(0x100537B0, this, pArg1, pArg2); }
short classUSER::Cheat_mon2(char* pArg1, char* pArg2, char* pArg3, char* pArg4) { return CallMemberFunction<classUSER, short, char*, char*, char*, char*>(0x100536A0, this, pArg1, pArg2, pArg3, pArg4); }
short classUSER::Cheat_damage(char* pArg1, char* pArg2, char* pArg3) { return CallMemberFunction<classUSER, short, char*, char*, char*>(0x10055F10, this, pArg1, pArg2, pArg3); }
short classUSER::Cheat_quest(CStrVAR* pStrVAR, char* pArg1) { return CallMemberFunction<classUSER, short, CStrVAR*, char*>(0x100535B0, this, pStrVAR, pArg1); }
short classUSER::Cheat_set(classUSER* pUSER, char* pArg1, char* pArg2, char* pArg3) { return CallMemberFunction<classUSER, short, classUSER*, char*, char*, char*>(0x10052F20, this, pUSER, pArg1, pArg2, pArg3); }
short classUSER::Cheat_toggle(CStrVAR* pStrVAR, char* pArg1) { return CallMemberFunction<classUSER, short, CStrVAR*, char*>(0x10055D90, this, pStrVAR, pArg1); }
short classUSER::Cheat_regen(CStrVAR* pStrVAR, char* pArg1, char* pArg2) { return CallMemberFunction<classUSER, short, CStrVAR*, char*, char*>(0x10054B70, this, pStrVAR, pArg1, pArg2); }
short classUSER::Cheat_speed(char* pArg1) { return CallMemberFunction<classUSER, short, char*>(0x10052D60, this, pArg1); }



