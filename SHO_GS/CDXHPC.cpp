#include "CDXHPC.h"

CDXHPC::CDXHPC() {};
CDXHPC::~CDXHPC() {};
int CDXHPC::Start() { return CallMemberFunction<CDXHPC, int>(0x1003DAE0, this); }
unsigned long CDXHPC::GetValue() { return CallMemberFunction<CDXHPC, unsigned long>(0x1003DBA0, this); }
void CDXHPC::Wait(unsigned long dwMilliSecs) { return CallMemberFunction<CDXHPC, void, unsigned long>(0x1003DC20, this, dwMilliSecs); }
unsigned long CDXHPC::Reset() { return CallMemberFunction<CDXHPC, unsigned long>(0x1003DC80, this); }
unsigned long CDXHPC::GetCheckTime() { return 0; }
unsigned long CDXHPC::GetCurrentTIME() { return CallMemberFunction<CDXHPC, unsigned long>(0x1003DD60, this); }
unsigned long CDXHPC::GetPassTIME() { return CallMemberFunction<CDXHPC, unsigned long>(0x10010EE0, this); }



