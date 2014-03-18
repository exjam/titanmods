#include "classSQL.h"

classSQL::classSQL() {};
classSQL::~classSQL() {};
bool classSQL::GetNextRECORD() { return CallMemberFunction<classSQL, bool>(0x10004F30, this); }
char* classSQL::GetQueryBuffPTR() { return CallMemberFunction<classSQL, char*>(0x1000E3B0, this); }
bool classSQL::Connect(char* Var1, char* Var2, char* Var3) { return 0; }
void classSQL::Disconnect() { return; }
bool classSQL::SelectDB(char* Var1) { return 0; }
const char* classSQL::GetERROR() { return 0; }
int classSQL::GetRecordCNT() { return 0; }
int classSQL::GetColumnCNT() { return 0; }
bool classSQL::Fetch() { return 0; }
bool classSQL::BindPARAM(short Var1, unsigned char* Var2, unsigned int Var3) { return 0; }
unsigned long classSQL::MakeQuery(char* Var1, ...) { return 0; }
int classSQL::ExecSQLBuffer(char* Var1, unsigned long Var2) { return 0; }
int classSQL::ExecSQLBuffer(char* Var1) { return 0; }
int classSQL::ExecSQLBuffer() { return 0; }
int classSQL::ExecSQLPacket(char* Var1, unsigned long Var2) { return 0; }
bool classSQL::QuerySQL(char* Var1, ...) { return 0; }
int classSQL::ExecSQL(char* Var1, ...) { return 0; }
bool classSQL::QueryString(char* Var1) { return 0; }
bool classSQL::QueryString(char* Var1, unsigned long Var2) { return 0; }
bool classSQL::QuerySQLBuffer() { return 0; }
unsigned char* classSQL::GetDataPTR(unsigned short Var1) { return 0; }
char* classSQL::GetStrPTR(unsigned short Var1, bool Var2) { return 0; }
int classSQL::GetStrLen(unsigned short Var1) { return 0; }
int classSQL::GetInteger(unsigned short Var1) { return 0; }
short classSQL::GetInteger16(unsigned short Var1) { return 0; }
__int64 classSQL::GetInt64(unsigned short Var1) { return 0; }
bool classSQL::GetTimestamp(unsigned short Var1, sqlTIMESTAMP* Var2) { return 0; }
bool classSQL::BindRESULT() { return CallMemberFunction<classSQL, bool>(0x100476B0, this); }
bool classSQL::GetMoreRESULT() { return CallMemberFunction<classSQL, bool>(0x100476E0, this); }
bool classSQL::SetParameter(short nParamIDX, unsigned char* pData, unsigned int uiDataSize, short nIOType, short nValueType, short nParamType) { return CallMemberFunction<classSQL, bool, short, unsigned char*, unsigned int, short, short, short>(0x10047710, this, nParamIDX, pData, uiDataSize, nIOType, nValueType, nParamType); }
bool classSQL::SetParam_string(short nParamIDX, char* szStr) { return CallMemberFunction<classSQL, bool, short, char*>(0x10047740, this, nParamIDX, szStr); }
bool classSQL::SetParam_wstring(short nParamIDX, char* szStr) { return CallMemberFunction<classSQL, bool, short, char*>(0x10047770, this, nParamIDX, szStr); }
bool classSQL::SetParam_long(short nParamIDX, long& lOutResult, long& cbLen) { return CallMemberFunction<classSQL, bool, short, long&, long&>(0x100477A0, this, nParamIDX, lOutResult, cbLen); }



