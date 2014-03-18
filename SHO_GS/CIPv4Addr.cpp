#include "CIPv4Addr.h"

CIPv4Addr::~CIPv4Addr() {};
bool CIPv4Addr::Add(char* szIPFrom, char* szIPTo) { return CallMemberFunction<CIPv4Addr, bool, char*, char*>(0x10045510, this, szIPFrom, szIPTo); }
bool CIPv4Addr::Find(char* szIPAddr) { return CallMemberFunction<CIPv4Addr, bool, char*>(0x10045740, this, szIPAddr); }
bool CIPv4Addr::Find(in_addr& inADDR) { return CallMemberFunction<CIPv4Addr, bool, in_addr&>(0x10045670, this, inADDR); }
CIPv4Addr::CIPv4Addr() {};



