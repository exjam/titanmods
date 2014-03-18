#include "CObjVAR.h"

CObjVAR::CObjVAR() {};
void CObjVAR::InitObjVAR() { return CallMemberFunction<CObjVAR, void>(0x10015D30, this); }
bool CObjVAR::VSend_gsv_CHAT(char* Var0) { return CallMemberFunction<CObjVAR, bool, char*>(0x10015D80, this, Var0); }
bool CObjVAR::VSend_gsv_SHOUT(char* Var0) { return CallMemberFunction<CObjVAR, bool, char*>(0x10015DA0, this, Var0); }
void CObjVAR::VSend_gsv_ANNOUNCE_CHAT(char* Var0) { return CallMemberFunction<CObjVAR, void, char*>(0x10015DC0, this, Var0); }
void CObjVAR::VSet_SHOW(unsigned char btShowMode) { return CallMemberFunction<CObjVAR, void, unsigned char>(0x10015DE0, this, btShowMode); }
short CObjVAR::VGetCur_ZoneNO() { return 0; }
float CObjVAR::VGetCur_XPOS() { return 0; }
float CObjVAR::VGetCur_YPOS() { return 0; }
int CObjVAR::VGetCur_ZoneTIME() { return 0; }
short CObjVAR::Get_ObjVAR(unsigned char btVarIDX) { return CallMemberFunction<CObjVAR, short, unsigned char>(0x1000CF70, this, btVarIDX); }
void CObjVAR::Set_ObjVAR(unsigned char btVarIDX, short nValue) { return CallMemberFunction<CObjVAR, void, unsigned char, short>(0x10015E00, this, btVarIDX, nValue); }
void CObjVAR::Set_NextTRIGGER(int iRemainSec, unsigned long HashNextTrigger) { return CallMemberFunction<CObjVAR, void, int, unsigned long>(0x10015E30, this, iRemainSec, HashNextTrigger); }
bool CObjVAR::ProcVAR(unsigned long dwPassTIME) { return CallMemberFunction<CObjVAR, bool, unsigned long>(0x10015E70, this, dwPassTIME); }



