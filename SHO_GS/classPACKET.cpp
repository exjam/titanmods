#include "classPACKET.h"

classPACKET::classPACKET() {};
classPACKET::~classPACKET() {};
void classPACKET::SetRefCnt(long lRefCnt) { return CallMemberFunction<classPACKET, void, long>(0x10003F90, this, lRefCnt); }
long classPACKET::IncRefCnt() { return CallMemberFunction<classPACKET, long>(0x10045370, this); }
long classPACKET::DecRefCnt() { return CallMemberFunction<classPACKET, long>(0x10003FB0, this); }
int classPACKET::GetRefCnt() { return CallMemberFunction<classPACKET, int>(0x10010780, this); }
unsigned short classPACKET::GetLength() { return CallMemberFunction<classPACKET, unsigned short>(0x10044F40, this); }
void classPACKET::SetLength(unsigned short wLen) { return CallMemberFunction<classPACKET, void, unsigned short>(0x10003FF0, this, wLen); }
char* classPACKET::GetStringPtr(short* pOffset) { return CallMemberFunction<classPACKET, char*, short*>(0x10043BC0, this, pOffset); }
unsigned char* classPACKET::GetDataPtr(short* pOffset, short nSize) { return CallMemberFunction<classPACKET, unsigned char*, short*, short>(0x10043C40, this, pOffset, nSize); }
bool classPACKET::AppendString(char* pStr) { return CallMemberFunction<classPACKET, bool, char*>(0x10043CB0, this, pStr); }
bool classPACKET::AppendData(void* pData, short nLen) { return CallMemberFunction<classPACKET, bool, void*, short>(0x10043DA0, this, pData, nLen); }



