#include "CCriticalSection.h"

CCriticalSection::CCriticalSection() {};
CCriticalSection::CCriticalSection(unsigned long dwSpinCount) {};
CCriticalSection::~CCriticalSection() {};
void CCriticalSection::Lock() { return CallMemberFunction<CCriticalSection, void>(0x10003D90, this); }
void CCriticalSection::Unlock() { return CallMemberFunction<CCriticalSection, void>(0x10003DD0, this); }
