#include "IOCPSocketSERVER.h"

IOCPSocketSERVER::IOCPSocketSERVER() { }
IOCPSocketSERVER::IOCPSocketSERVER(char* szName, unsigned char btMulCPU, char cAddCPU, bool bManageSocketVerify) {};
IOCPSocketSERVER::~IOCPSocketSERVER() {};
bool IOCPSocketSERVER::Add_RefuseIP(char* Var1, char* Var2) { return 0; }
char* IOCPSocketSERVER::GetServerNAME() { return CallMemberFunction<IOCPSocketSERVER, char*>(0x10041780, this); }
iocpSOCKET* IOCPSocketSERVER::AllocClientSOCKET() { return 0; }
void IOCPSocketSERVER::InitClientSOCKET(iocpSOCKET* pCLIENT) { return CallMemberFunction<IOCPSocketSERVER, void, iocpSOCKET*>(0x1000AE80, this, pCLIENT); }
void IOCPSocketSERVER::FreeClientSOCKET(iocpSOCKET* Var1) { return; }
void IOCPSocketSERVER::ClosedClientSOCKET(iocpSOCKET* Var1) { return; }
void IOCPSocketSERVER::LockLIST() { return; }
void IOCPSocketSERVER::UnlockLIST() { return; }
iocpSOCKET* IOCPSocketSERVER::GetSOCKET(int iSocketIDX) { return CallMemberFunction<IOCPSocketSERVER, iocpSOCKET*, int>(0x10004290, this, iSocketIDX); }
bool IOCPSocketSERVER::New_SOCKET(unsigned int hSocket, sockaddr_in& SockADDR) { return CallMemberFunction<IOCPSocketSERVER, bool, unsigned int, sockaddr_in&>(0x100405A0, this, hSocket, SockADDR); }
iocpSOCKET* IOCPSocketSERVER::Del_SOCKET(int iSocketIDX) { return CallMemberFunction<IOCPSocketSERVER, iocpSOCKET*, int>(0x10040970, this, iSocketIDX); }
void IOCPSocketSERVER::On_TRUE(_OVERLAPPED* lpOverlapped, unsigned long dwCompletionKey, unsigned long dwBytesIO) { return CallMemberFunction<IOCPSocketSERVER, void, _OVERLAPPED*, unsigned long, unsigned long>(0x10040AF0, this, lpOverlapped, dwCompletionKey, dwBytesIO); }
void IOCPSocketSERVER::On_FALSE(_OVERLAPPED* lpOverlapped, unsigned long dwCompletionKey) { return CallMemberFunction<IOCPSocketSERVER, void, _OVERLAPPED*, unsigned long>(0x10040A40, this, lpOverlapped, dwCompletionKey); }
int IOCPSocketSERVER::GetUsedSocketCNT() { return CallMemberFunction<IOCPSocketSERVER, int>(0x10001CE0, this); }
bool IOCPSocketSERVER::Active(int iListenTCPPortNO, unsigned long dwMaxSocketCount, int iKeepAliveSec) { return CallMemberFunction<IOCPSocketSERVER, bool, int, unsigned long, int>(0x1003FC70, this, iListenTCPPortNO, dwMaxSocketCount, iKeepAliveSec); }
void IOCPSocketSERVER::Shutdown() { return CallMemberFunction<IOCPSocketSERVER, void>(0x10041AE0, this); }
void IOCPSocketSERVER::ShutdownSOCKET() { return CallMemberFunction<IOCPSocketSERVER, void>(0x1003FD90, this); }
bool IOCPSocketSERVER::StartACCEPT(int iListenTCPPortNO, int iKeepAliveSec) { return CallMemberFunction<IOCPSocketSERVER, bool, int, int>(0x1003FE70, this, iListenTCPPortNO, iKeepAliveSec); }
void IOCPSocketSERVER::ShutdownACCEPT() { return CallMemberFunction<IOCPSocketSERVER, void>(0x1003FFE0, this); }
void IOCPSocketSERVER::StartWORKER() { return CallMemberFunction<IOCPSocketSERVER, void>(0x100400A0, this); }
void IOCPSocketSERVER::ShutdownWORKER() { return CallMemberFunction<IOCPSocketSERVER, void>(0x10040200, this); }
unsigned long IOCPSocketSERVER::GetMaxSocketCOUNT() { return CallMemberFunction<IOCPSocketSERVER, unsigned long>(0x1000AEA0, this); }
void IOCPSocketSERVER::CloseIdleSCOKET(unsigned long dwIdleMilliSec) { return CallMemberFunction<IOCPSocketSERVER, void, unsigned long>(0x10040420, this, dwIdleMilliSec); }



