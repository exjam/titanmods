#ifndef RECVPACKET_H
#define RECVPACKET_H

#include <TRose\Packet.h>

extern Packet* gRecvPacket;

bool __stdcall OnReceivePacket(Packet* pak);
void Recv_srv_PVP(bool fromLogin);
void Recv_srv_ACHIEVEMENT();
void Recv_srv_CONTRIBUTION();
void Recv_srv_PARTYLIST();
void Recv_srv_VENDMESSAGE();
void Recv_srv_SCALE();
void Recv_srv_RIDE(bool spawnPlayer);
void Recv_srv_WHISPER();
void Recv_srv_BUFF();
void Recv_srv_PLAYERDATA();
void Recv_srv_MESSAGE();
void Recv_srv_DUEL();
void Recv_srv_ALLY();
void Recv_srv_FLAG();

#endif