#include "STB.h"

STBDATA::STBDATA(const STBDATA& Var1) { }
STBDATA::STBDATA() {};
STBDATA::~STBDATA() {};
bool STBDATA::Load2(char* szFileName, bool bHasTYPE, bool bMakeKEY) { return CallMemberFunction<STBDATA, bool, char*, bool, bool>(0x1009F8C0, this, szFileName, bHasTYPE, bMakeKEY); }
bool STBDATA::Load(char* szFileName, bool bHasNameCol, bool bHasDescCol, bool bMakeKEY) { return CallMemberFunction<STBDATA, bool, char*, bool, bool, bool>(0x1009F430, this, szFileName, bHasNameCol, bHasDescCol, bMakeKEY); }
void STBDATA::Free() { return CallMemberFunction<STBDATA, void>(0x1009FE20, this); }
bool STBDATA::LoadWSTB(bool bCheckQuotationMark, char* szFileName, int iKeyColIDX) { return CallMemberFunction<STBDATA, bool, bool, char*, int>(0x1009EEE0, this, bCheckQuotationMark, szFileName, iKeyColIDX); }
char* STBDATA::GetValueSTR(short nCol, short nRow) { return CallMemberFunction<STBDATA, char*, short, short>(0x1000CF00, this, nCol, nRow); }
short STBDATA::GetRowIndex(char* szName) { return CallMemberFunction<STBDATA, short, char*>(0x100016A0, this, szName); }
short STBDATA::GetRowIndex(unsigned long HashKey) { return CallMemberFunction<STBDATA, short, unsigned long>(0x10001640, this, HashKey); }

STBVALUE::STBVALUE() {};
STBVALUE::~STBVALUE() {};
void STBVALUE::SetTYPE(bool bString) { return CallMemberFunction<STBVALUE, void, bool>(0x1000C010, this, bString); }
bool STBVALUE::IsString() { return CallMemberFunction<STBVALUE, bool>(0x10001470, this); }
void STBVALUE::SetVALUE(int iValue) { return CallMemberFunction<STBVALUE, void, int>(0x1009ECF0, this, iValue); }
void STBVALUE::SetVALUE(char* szValue) { return CallMemberFunction<STBVALUE, void, char*>(0x1009ED10, this, szValue); }
int STBVALUE::GetINT() { return CallMemberFunction<STBVALUE, int>(0x10001490, this); }
char* STBVALUE::GetSTR() { return CallMemberFunction<STBVALUE, char*>(0x100014B0, this); }
int STBVALUE::GetStrLEN() { return CallMemberFunction<STBVALUE, int>(0x10001510, this); }




