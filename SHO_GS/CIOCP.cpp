#include "CIOCP.h"

CIOCP::CIOCP() {};
CIOCP::~CIOCP() {};
void* CIOCP::GetHANDLE() { return CallMemberFunction<CIOCP, void*>(0x10040F60, this); }
bool CIOCP::OpenPort(unsigned long dwWorkerThreadCNT) { return CallMemberFunction<CIOCP, bool, unsigned long>(0x10040F90, this, dwWorkerThreadCNT); }
void CIOCP::ClosePort() { return CallMemberFunction<CIOCP, void>(0x10041000, this); }
bool CIOCP::LinkPort(void* hFileHandle, unsigned long ulCompletionKey) { return CallMemberFunction<CIOCP, bool, void*, unsigned long>(0x10041060, this, hFileHandle, ulCompletionKey); }



