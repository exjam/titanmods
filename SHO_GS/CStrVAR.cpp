#include "CStrVAR.h"
CStrVAR::CStrVAR() {};
CStrVAR::CStrVAR(unsigned short wStrLen, unsigned short wStaticStrLen) {};
CStrVAR::~CStrVAR() {};
char* CStrVAR::Alloc(unsigned short wStrLen, unsigned short wStaticStrLen) { return CallMemberFunction<CStrVAR, char*, unsigned short, unsigned short>(0x10035610, this, wStrLen, wStaticStrLen); }
void CStrVAR::Set(char* szStrIn) { return CallMemberFunction<CStrVAR, void, char*>(0x10035740, this, szStrIn); }
char* CStrVAR::Get() { return CallMemberFunction<CStrVAR, char*>(0x10001430, this); }
void CStrVAR::Del() { return CallMemberFunction<CStrVAR, void>(0x10035690, this); }
unsigned short CStrVAR::BuffLength() { return CallMemberFunction<CStrVAR, unsigned short>(0x10001450, this); }
unsigned int CStrVAR::GetHASH(char* szString) { return CallMemberFunction<CStrVAR, unsigned int, char*>(0x100359F0, this, szString); }
unsigned int CStrVAR::GetHASH() { return CallMemberFunction<CStrVAR, unsigned int>(0x1000BFE0, this); }
char* CStrVAR::Printf(char* fmt) { return CallMemberFunction<CStrVAR, char*, char*>(0x10035840, this, fmt); }
char* CStrVAR::GetTokenFirst(char* pStr, char* pDelimiters) { return CallMemberFunction<CStrVAR, char*, char*, char*>(0x100358B0, this, pStr, pDelimiters); }
char* CStrVAR::GetTokenNext(char* pDelimiters) { return CallMemberFunction<CStrVAR, char*, char*>(0x100359A0, this, pDelimiters); }
char* CStrVAR::ReadString(_iobuf* fp, bool bIgnoreWhiteSpace) { return CallMemberFunction<CStrVAR, char*, _iobuf*, bool>(0x10035A30, this, fp, bIgnoreWhiteSpace); }
bool CStrVAR::SaveString(char* szFileName, char* szString) { return CallMemberFunction<CStrVAR, bool, char*, char*>(0x10035C40, this, szFileName, szString); }

