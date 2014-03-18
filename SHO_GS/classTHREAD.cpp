#include "classTHREAD.h"
classTHREAD::classTHREAD() {};
classTHREAD::classTHREAD(bool bCreateSuspended) {};
classTHREAD::~classTHREAD() {};
unsigned long classTHREAD::Suspend() { return CallMemberFunction<classTHREAD, unsigned long>(0x10038CB0, this); }
unsigned long classTHREAD::Resume() { return CallMemberFunction<classTHREAD, unsigned long>(0x10038D10, this); }
void classTHREAD::Terminate() { return CallMemberFunction<classTHREAD, void>(0x10038BB0, this); }
int classTHREAD::WaitFor() { return CallMemberFunction<classTHREAD, int>(0x10038C10, this); }
bool classTHREAD::IsFinished() { return CallMemberFunction<classTHREAD, bool>(0x10014C80, this); }
void classTHREAD::SetSuspended(bool bValue) { return CallMemberFunction<classTHREAD, void, bool>(0x10038D70, this, bValue); }
int classTHREAD::SetPriority(int iPriority) { return CallMemberFunction<classTHREAD, int, int>(0x1000E370, this, iPriority); }
void classTHREAD::Execute() { return; }



