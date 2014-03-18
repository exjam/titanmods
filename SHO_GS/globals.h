#ifndef GLOBALS_H
#define GLOBALS_H

class classPACKET;

TGAMESERVER_API classPACKET* Packet_AllocNLock();
TGAMESERVER_API void Packet_ReleaseNUnlock(classPACKET* pak);
TGAMESERVER_API unsigned int StrToHashKey(const char* str);

#endif