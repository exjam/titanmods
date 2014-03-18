#ifndef PACKETS_H
#define PACKETS_H

class CPacket;
class classUSER;

void ProcDuelPacket(CPacket* pak, classUSER* user);
void ProcAllyPacket(CPacket* pak, classUSER* user);
void ProcPartyPacket(CPacket* pak, classUSER* user);

#endif
