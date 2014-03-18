#include "classODBC.h"

void classODBC::AllocParam(short nCntToAlloc) { return CallMemberFunction<classODBC, void, short>(0x10048250, this, nCntToAlloc); }
void classODBC::AllocColumn(short nCntToAlloc) { return CallMemberFunction<classODBC, void, short>(0x10048350, this, nCntToAlloc); }
classODBC::classODBC(short nBindParamCNT, unsigned short wQueryBufferLEN) {};
classODBC::~classODBC() {};
bool classODBC::QuerySQL(char* szFormat) { return CallMemberFunction<classODBC, bool, char*>(0x10049450, this, szFormat); }
int classODBC::ExecSQL(char* szFormat) { return CallMemberFunction<classODBC, int, char*>(0x100498D0, this, szFormat); }
void classODBC::Clear() { return CallMemberFunction<classODBC, void>(0x10049B90, this); }
short classODBC::GetColDataType(unsigned char Var1) { return 0; }
bool classODBC::FirstDSN(char* pszDSN, int lMax) { return CallMemberFunction<classODBC, bool, char*, int>(0x10047CF0, this, pszDSN, lMax); }
bool classODBC::NextDSN(char* pszDSN, int lMax) { return CallMemberFunction<classODBC, bool, char*, int>(0x10047DF0, this, pszDSN, lMax); }
bool classODBC::RegisterDSN(char* szDSN, char* szDBName, char* szServerIP, char* szUser) { return CallMemberFunction<classODBC, bool, char*, char*, char*, char*>(0x10047EF0, this, szDSN, szDBName, szServerIP, szUser); }
bool classODBC::ReigsterDsnIfNone(char* szDSN, char* szDBName, char* szServerIP, char* szUser) { return CallMemberFunction<classODBC, bool, char*, char*, char*, char*>(0x10048570, this, szDSN, szDBName, szServerIP, szUser); }
bool classODBC::Connect(char* szDSN, char* szUserName, char* szPassword) { return CallMemberFunction<classODBC, bool, char*, char*, char*>(0x10048730, this, szDSN, szUserName, szPassword); }
void classODBC::Disconnect() { return CallMemberFunction<classODBC, void>(0x100488F0, this); }
bool classODBC::SelectDB(char* szDBName) { return CallMemberFunction<classODBC, bool, char*>(0x10049820, this, szDBName); }
const char* classODBC::GetERROR() { return CallMemberFunction<classODBC, const char*>(0x100483F0, this); }
int classODBC::GetRecordCNT() { return CallMemberFunction<classODBC, int>(0x10049850, this); }
int classODBC::GetColumnCNT() { return CallMemberFunction<classODBC, int>(0x10049890, this); }
bool classODBC::Fetch() { return CallMemberFunction<classODBC, bool>(0x10049AB0, this); }
bool classODBC::BindPARAM(short nParamIDX, unsigned char* pData, unsigned int uiDataSize) { return CallMemberFunction<classODBC, bool, short, unsigned char*, unsigned int>(0x10048970, this, nParamIDX, pData, uiDataSize); }
unsigned long classODBC::MakeQuery(char* szCommand) { return CallMemberFunction<classODBC, unsigned long, char*>(0x1004A140, this, szCommand); }
int classODBC::ExecSQLBuffer(char* szQuery, unsigned long ulLength) { return CallMemberFunction<classODBC, int, char*, unsigned long>(0x100499D0, this, szQuery, ulLength); }
int classODBC::ExecSQLBuffer(char* szQuery) { return CallMemberFunction<classODBC, int, char*>(0x10049A40, this, szQuery); }
int classODBC::ExecSQLBuffer() { return CallMemberFunction<classODBC, int>(0x100495A0, this); }
int classODBC::ExecSQLPacket(char* szQuery, unsigned long ulLength) { return CallMemberFunction<classODBC, int, char*, unsigned long>(0x10049940, this, szQuery, ulLength); }
bool classODBC::QueryString(char* szQuery) { return CallMemberFunction<classODBC, bool, char*>(0x10049530, this, szQuery); }
bool classODBC::QueryString(char* szQuery, unsigned long ulLength) { return CallMemberFunction<classODBC, bool, char*, unsigned long>(0x100494C0, this, szQuery, ulLength); }
bool classODBC::QuerySQLBuffer() { return CallMemberFunction<classODBC, bool>(0x10049210, this); }
unsigned char* classODBC::GetDataPTR(unsigned short wColumnIDX) { return CallMemberFunction<classODBC, unsigned char*, unsigned short>(0x10049D10, this, wColumnIDX); }
char* classODBC::GetStrPTR(unsigned short wColumnIDX, bool bSetSpaceToNULL) { return CallMemberFunction<classODBC, char*, unsigned short, bool>(0x10049D90, this, wColumnIDX, bSetSpaceToNULL); }
int classODBC::GetStrLen(unsigned short wColumnIDX) { return CallMemberFunction<classODBC, int, unsigned short>(0x10049F60, this, wColumnIDX); }
int classODBC::GetInteger(unsigned short wColumnIDX) { return CallMemberFunction<classODBC, int, unsigned short>(0x10049FC0, this, wColumnIDX); }
short classODBC::GetInteger16(unsigned short wColumnIDX) { return CallMemberFunction<classODBC, short, unsigned short>(0x1004A040, this, wColumnIDX); }
__int64 classODBC::GetInt64(unsigned short wColumnIDX) { return CallMemberFunction<classODBC, __int64, unsigned short>(0x1004A0C0, this, wColumnIDX); }
bool classODBC::GetTimestamp(unsigned short wColumnIDX, sqlTIMESTAMP* pTimeStamp) { return CallMemberFunction<classODBC, bool, unsigned short, sqlTIMESTAMP*>(0x10049BF0, this, wColumnIDX, pTimeStamp); }
bool classODBC::BindRESULT() { return CallMemberFunction<classODBC, bool>(0x10048D70, this); }
bool classODBC::GetMoreRESULT() { return CallMemberFunction<classODBC, bool>(0x10049970, this); }
bool classODBC::SetParameter(short nParamIDX, unsigned char* pData, unsigned int uiDataSize, short nIOType, short nValueType, short nParamType) { return CallMemberFunction<classODBC, bool, short, unsigned char*, unsigned int, short, short, short>(0x10048AD0, this, nParamIDX, pData, uiDataSize, nIOType, nValueType, nParamType); }
bool classODBC::SetParam_string(short nParamIDX, char* szStr) { return CallMemberFunction<classODBC, bool, short, char*>(0x10048C90, this, nParamIDX, szStr); }
bool classODBC::SetParam_wstring(short nParamIDX, char* szStr) { return CallMemberFunction<classODBC, bool, short, char*>(0x10048D00, this, nParamIDX, szStr); }
bool classODBC::SetParam_long(short nParamIDX, long& lOutResult, long& cbLen) { return CallMemberFunction<classODBC, bool, short, long&, long&>(0x10048BE0, this, nParamIDX, lOutResult, cbLen); }


