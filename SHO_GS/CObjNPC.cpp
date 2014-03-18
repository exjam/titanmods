#include "CObjNPC.h"

bool CObjNPC::Send_gsv_SET_EVENT_STATUS() { return CallMemberFunction<CObjNPC, bool>(0x10057630, this); }
t_ObjTAG CObjNPC::Get_TYPE() { return CallMemberFunction<CObjNPC, t_ObjTAG>(0x10015F00, this); }
bool CObjNPC::Make_gsv_ADD_OBJECT(classPACKET* pCPacket) { return CallMemberFunction<CObjNPC, bool, classPACKET*>(0x10056860, this, pCPacket); }
bool CObjNPC::VSend_gsv_CHAT(char* szMsg) { return CallMemberFunction<CObjNPC, bool, char*>(0x10015F20, this, szMsg); }
bool CObjNPC::VSend_gsv_SHOUT(char* szMsg) { return CallMemberFunction<CObjNPC, bool, char*>(0x10015F60, this, szMsg); }
void CObjNPC::VSend_gsv_ANNOUNCE_CHAT(char* szMsg) { return CallMemberFunction<CObjNPC, void, char*>(0x10015FA0, this, szMsg); }
void CObjNPC::VSet_SHOW(unsigned char btShowMode) { return CallMemberFunction<CObjNPC, void, unsigned char>(0x10057500, this, btShowMode); }
short CObjNPC::VGetCur_ZoneNO() { return CallMemberFunction<CObjNPC, short>(0x10056450, this); }
float CObjNPC::VGetCur_XPOS() { return CallMemberFunction<CObjNPC, float>(0x10015FE0, this); }
float CObjNPC::VGetCur_YPOS() { return CallMemberFunction<CObjNPC, float>(0x10016000, this); }
int CObjNPC::VGetCur_ZoneTIME() { return CallMemberFunction<CObjNPC, int>(0x10016020, this); }
void CObjNPC::Set_ObjVAR(unsigned char btVarIDX, short nValue) { return CallMemberFunction<CObjNPC, void, unsigned char, short>(0x10016050, this, btVarIDX, nValue); }
void CObjNPC::Set_NextTRIGGER(int iRemainSec, unsigned long HashNextTrigger) { return CallMemberFunction<CObjNPC, void, int, unsigned long>(0x100160D0, this, iRemainSec, HashNextTrigger); }
void CObjNPC::Set_TRIGGER(unsigned long HashNextTrigger) { return CallMemberFunction<CObjNPC, void, unsigned long>(0x10016100, this, HashNextTrigger); }
CObjNPC::CObjNPC() {};
CObjNPC::~CObjNPC() {};
void CObjNPC::Do_CreatedAI() { return CallMemberFunction<CObjNPC, void>(0x10016140, this); }
void CObjNPC::Do_AttackMoveAI(CObjCHAR* pTarget) { return CallMemberFunction<CObjNPC, void, CObjCHAR*>(0x10016160, this, pTarget); }
void CObjNPC::Do_KillAI(CObjCHAR* pTarget, int iDamage) { return CallMemberFunction<CObjNPC, void, CObjCHAR*, int>(0x10016180, this, pTarget, iDamage); }
void CObjNPC::Do_DeadAI(CObjCHAR* pTarget, int iDamage) { return CallMemberFunction<CObjNPC, void, CObjCHAR*, int>(0x100161A0, this, pTarget, iDamage); }
void CObjNPC::Do_DeadEvent(CObjCHAR* pTarget) { return CallMemberFunction<CObjNPC, void, CObjCHAR*>(0x100161C0, this, pTarget); }
void CObjNPC::Set_DIR(float fDIR) { return CallMemberFunction<CObjNPC, void, float>(0x10014810, this, fDIR); }
bool CObjNPC::Get_SellITEM(short nSellTAB, short nSellCOL, tagITEM& OutITEM) { return CallMemberFunction<CObjNPC, bool, short, short, tagITEM&>(0x10056CB0, this, nSellTAB, nSellCOL, OutITEM); }
int CObjNPC::Proc() { return CallMemberFunction<CObjNPC, int>(0x10058280, this); }



