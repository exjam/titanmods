#include "GS_CThreadSQL.h"

bool GS_CThreadSQL::ConvertBasicETC() { return CallMemberFunction<GS_CThreadSQL, bool>(0x10093130, this); }
bool GS_CThreadSQL::Run_SqlPACKET(tagQueryDATA* pSqlPACKET) { return CallMemberFunction<GS_CThreadSQL, bool, tagQueryDATA*>(0x100980B0, this, pSqlPACKET); }
bool GS_CThreadSQL::Proc_LOAD_ZONE_DATA(int iZoneNO) { return CallMemberFunction<GS_CThreadSQL, bool, int>(0x10093D80, this, iZoneNO); }
bool GS_CThreadSQL::Proc_SAVE_ZONE_DATA(int iZoneNO, sql_ZONE_DATA* pSqlZONE) { return CallMemberFunction<GS_CThreadSQL, bool, int, sql_ZONE_DATA*>(0x10093C50, this, iZoneNO, pSqlZONE); }
bool GS_CThreadSQL::Proc_LOAD_OBJVAR(tagQueryDATA* pSqlPACKET) { return CallMemberFunction<GS_CThreadSQL, bool, tagQueryDATA*>(0x100937F0, this, pSqlPACKET); }
bool GS_CThreadSQL::Proc_SAVE_OBJVAR(tagQueryDATA* pSqlPACKET) { return CallMemberFunction<GS_CThreadSQL, bool, tagQueryDATA*>(0x100936E0, this, pSqlPACKET); }
bool GS_CThreadSQL::Proc_SAVE_WORLDVAR(sql_ZONE_DATA* pSqlZONE) { return CallMemberFunction<GS_CThreadSQL, bool, sql_ZONE_DATA*>(0x10093420, this, pSqlZONE); }
bool GS_CThreadSQL::Proc_cli_MEMO(tagQueryDATA* pSqlPACKET) { return CallMemberFunction<GS_CThreadSQL, bool, tagQueryDATA*>(0x10096180, this, pSqlPACKET); }
bool GS_CThreadSQL::Proc_cli_CHAR_LIST(tagQueryDATA* pSqlPACKET) { return CallMemberFunction<GS_CThreadSQL, bool, tagQueryDATA*>(0x10095500, this, pSqlPACKET); }
bool GS_CThreadSQL::Proc_cli_SELECT_CHAR(tagQueryDATA* pSqlPACKET) { return CallMemberFunction<GS_CThreadSQL, bool, tagQueryDATA*>(0x10097390, this, pSqlPACKET); }
bool GS_CThreadSQL::Proc_cli_CREATE_CHAR(tagQueryDATA* pSqlPACKET) { return CallMemberFunction<GS_CThreadSQL, bool, tagQueryDATA*>(0x10096820, this, pSqlPACKET); }
bool GS_CThreadSQL::Proc_cli_DELETE_CHAR(tagQueryDATA* pSqlPACKET) { return CallMemberFunction<GS_CThreadSQL, bool, tagQueryDATA*>(0x10095270, this, pSqlPACKET); }
bool GS_CThreadSQL::Proc_cli_BANK_LIST_REQ(tagQueryDATA* pSqlPACKET) { return CallMemberFunction<GS_CThreadSQL, bool, tagQueryDATA*>(0x10094D70, this, pSqlPACKET); }
bool GS_CThreadSQL::Proc_cli_MALL_ITEM_REQ(tagQueryDATA* pSqlPACKET) { return CallMemberFunction<GS_CThreadSQL, bool, tagQueryDATA*>(0x10094BB0, this, pSqlPACKET); }
void GS_CThreadSQL::Clear_LoginTABLE() { return CallMemberFunction<GS_CThreadSQL, void>(0x10094110, this); }
void GS_CThreadSQL::Add_LoginACCOUNT(char* szAccount) { return CallMemberFunction<GS_CThreadSQL, void, char*>(0x10094070, this, szAccount); }
void GS_CThreadSQL::Sub_LoginACCOUNT(char* szAccount) { return CallMemberFunction<GS_CThreadSQL, void, char*>(0x10093FE0, this, szAccount); }
void GS_CThreadSQL::Execute() { return CallMemberFunction<GS_CThreadSQL, void>(0x10096F30, this); }
GS_CThreadSQL::GS_CThreadSQL() {};
GS_CThreadSQL::~GS_CThreadSQL() {};
void GS_CThreadSQL::Set_EVENT() { return CallMemberFunction<GS_CThreadSQL, void>(0x10001C40, this); }
bool GS_CThreadSQL::IO_ZoneDATA(CZoneTHREAD* pZONE, bool bSave) { return CallMemberFunction<GS_CThreadSQL, bool, CZoneTHREAD*, bool>(0x10094AA0, this, pZONE, bSave); }
bool GS_CThreadSQL::IO_NpcObjDATA(CObjNPC* pObjNPC, bool bSave) { return CallMemberFunction<GS_CThreadSQL, bool, CObjNPC*, bool>(0x10094920, this, pObjNPC, bSave); }
bool GS_CThreadSQL::IO_EventObjDATA(CObjEVENT* pObjEVENT, bool bSave) { return CallMemberFunction<GS_CThreadSQL, bool, CObjEVENT*, bool>(0x10094800, this, pObjEVENT, bSave); }
bool GS_CThreadSQL::Save_WorldVAR(unsigned char* pVarBUFF, short nBuffLEN) { return CallMemberFunction<GS_CThreadSQL, bool, unsigned char*, short>(0x10093150, this, pVarBUFF, nBuffLEN); }
bool GS_CThreadSQL::Load_WORLDVAR(unsigned char* pVarBUFF, short nBuffLEN) { return CallMemberFunction<GS_CThreadSQL, bool, unsigned char*, short>(0x10093510, this, pVarBUFF, nBuffLEN); }
bool GS_CThreadSQL::Add_SqlPacketWithACCOUNT(classUSER* pUSER, t_PACKET* pPacket) { return CallMemberFunction<GS_CThreadSQL, bool, classUSER*, t_PACKET*>(0x10094A50, this, pUSER, pPacket); }
bool GS_CThreadSQL::Add_SqlPacketWithAVATAR(classUSER* pUSER, t_PACKET* pPacket) { return CallMemberFunction<GS_CThreadSQL, bool, classUSER*, t_PACKET*>(0x10093220, this, pUSER, pPacket); }
bool GS_CThreadSQL::Add_BackUpUSER(classUSER* pUSER, unsigned char btLogOutMODE) { return CallMemberFunction<GS_CThreadSQL, bool, classUSER*, unsigned char>(0x10093A40, this, pUSER, btLogOutMODE); }
bool GS_CThreadSQL::Sql_TEST() { return CallMemberFunction<GS_CThreadSQL, bool>(0x10093280, this); }
bool GS_CThreadSQL::IsWaiting() { return CallMemberFunction<GS_CThreadSQL, bool>(0x10001C70, this); }
int GS_CThreadSQL::WaitUserCNT() { return CallMemberFunction<GS_CThreadSQL, int>(0x10001C90, this); }
bool GS_CThreadSQL::UpdateUserRECORD(classUSER* pUSER) { return CallMemberFunction<GS_CThreadSQL, bool, classUSER*>(0x10094190, this, pUSER); }



