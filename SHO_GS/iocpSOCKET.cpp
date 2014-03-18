#include "iocpSOCKET.h"

ePacketRECV iocpSOCKET::Recv_Continue(tagIO_DATA* pRecvDATA) { return CallMemberFunction<iocpSOCKET, ePacketRECV, tagIO_DATA*>(0x10044250, this, pRecvDATA); }
bool iocpSOCKET::Send_Continue(tagIO_DATA* pSendDATA) { return CallMemberFunction<iocpSOCKET, bool, tagIO_DATA*>(0x10044800, this, pSendDATA); }
void iocpSOCKET::CloseSocket() { return CallMemberFunction<iocpSOCKET, void>(0x10044080, this); }
iocpSOCKET::iocpSOCKET() {};
iocpSOCKET::~iocpSOCKET() {};
void iocpSOCKET::LockSOCKET() { return CallMemberFunction<iocpSOCKET, void>(0x10007120, this); }
void iocpSOCKET::UnlockSOCKET() { return CallMemberFunction<iocpSOCKET, void>(0x10004C30, this); }
void iocpSOCKET::Init_SCOKET() { return CallMemberFunction<iocpSOCKET, void>(0x100410C0, this); }
unsigned int iocpSOCKET::Get_SOCKET() { return CallMemberFunction<iocpSOCKET, unsigned int>(0x10010960, this); }
char* iocpSOCKET::Get_IP() { return CallMemberFunction<iocpSOCKET, char*>(0x10004C60, this); }
unsigned long iocpSOCKET::Get_CheckTIME() { return CallMemberFunction<iocpSOCKET, unsigned long>(0x10007150, this); }
void iocpSOCKET::Clear_LIST() { return CallMemberFunction<iocpSOCKET, void>(0x10044160, this); }
ePacketRECV iocpSOCKET::Recv_Start() { return CallMemberFunction<iocpSOCKET, ePacketRECV>(0x10044320, this); }
ePacketRECV iocpSOCKET::Recv_Complete(tagIO_DATA* pRecvDATA) { return CallMemberFunction<iocpSOCKET, ePacketRECV, tagIO_DATA*>(0x100443E0, this, pRecvDATA); }
bool iocpSOCKET::Send_Start(classPACKET* pCPacket) { return CallMemberFunction<iocpSOCKET, bool, classPACKET*>(0x10044910, this, pCPacket); }
bool iocpSOCKET::Send_Complete(tagIO_DATA* pSendDATA) { return CallMemberFunction<iocpSOCKET, bool, tagIO_DATA*>(0x10044B80, this, pSendDATA); }
bool iocpSOCKET::Recv_Done(tagIO_DATA* pRecvDATA) { return CallMemberFunction<iocpSOCKET, bool, tagIO_DATA*>(0x10044D70, this, pRecvDATA); }
bool iocpSOCKET::HandlePACKET(t_PACKETHEADER* Var1) { return 0; }
unsigned short iocpSOCKET::E_SendP(t_PACKETHEADER* pPacket) { return CallMemberFunction<iocpSOCKET, unsigned short, t_PACKETHEADER*>(0x10044FD0, this, pPacket); }
unsigned short iocpSOCKET::D_RecvH(t_PACKETHEADER* pPacket) { return CallMemberFunction<iocpSOCKET, unsigned short, t_PACKETHEADER*>(0x10045010, this, pPacket); }
short iocpSOCKET::D_RecvB(t_PACKETHEADER* pPacket) { return CallMemberFunction<iocpSOCKET, short, t_PACKETHEADER*>(0x10045050, this, pPacket); }
unsigned short iocpSOCKET::P_Length(t_PACKETHEADER* pPacket) { return CallMemberFunction<iocpSOCKET, unsigned short, t_PACKETHEADER*>(0x10045090, this, pPacket); }
classDLLNODE<tagIO_DATA>* iocpSOCKET::Alloc_RecvIODATA() { return CallMemberFunction<iocpSOCKET, classDLLNODE<tagIO_DATA>*>(0x100450D0, this); }
void iocpSOCKET::Free_RecvIODATA(tagIO_DATA* pRecvDATA) { return CallStaticFunction<0x10010980, void, tagIO_DATA*>(pRecvDATA); }
classDLLNODE<tagIO_DATA>* iocpSOCKET::Alloc_SendIODATA(classPACKET* pCPacket) { return CallMemberFunction<iocpSOCKET, classDLLNODE<tagIO_DATA>*, classPACKET*>(0x10045280, this, pCPacket); }
void iocpSOCKET::Free_SendIODATA(tagIO_DATA* pSendDATA) { return CallStaticFunction<0x10045430, void, tagIO_DATA*>(pSendDATA); }



