#include "CSqlTHREAD.h"

char* CSqlTHREAD::Del_SqlPACKET(char* pDelNODE) { return CallMemberFunction<CSqlTHREAD, char*, char*>(0x10042FA0, this, pDelNODE); }
bool CSqlTHREAD::Run_SqlPACKET(tagQueryDATA* Var1) { return 0; }
bool CSqlTHREAD::Proc_QuerySTRING() { return CallMemberFunction<CSqlTHREAD, bool>(0x10043460, this); }
CSqlTHREAD::CSqlTHREAD() { }
CSqlTHREAD::CSqlTHREAD(bool bCreateSuspended) {};
CSqlTHREAD::~CSqlTHREAD() {};
bool CSqlTHREAD::Connect(unsigned char btSqlTYPE, char* szServerIP, char* szUser, char* szPassword, char* szDBName, short nBindParamCNT, unsigned short wQueryBufferLEN) { return CallMemberFunction<CSqlTHREAD, bool, unsigned char, char*, char*, char*, char*, short, unsigned short>(0x10042BC0, this, btSqlTYPE, szServerIP, szUser, szPassword, szDBName, nBindParamCNT, wQueryBufferLEN); }
void CSqlTHREAD::Free() { return CallMemberFunction<CSqlTHREAD, void>(0x10042F40, this); }
bool CSqlTHREAD::Add_SqlPACKET(int iTAG, char* szName, unsigned char* pDATA, int iDataSize) { return CallMemberFunction<CSqlTHREAD, bool, int, char*, unsigned char*, int>(0x10043030, this, iTAG, szName, pDATA, iDataSize); }
bool CSqlTHREAD::Add_QueryString(const char* szQuery) { return CallMemberFunction<CSqlTHREAD, bool, const char*>(0x10043370, this, szQuery); }



