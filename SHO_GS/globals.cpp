#include "SHO_GS.h"

classPACKET* Packet_AllocNLock(){
	return CallStaticFunction<0x10004100, classPACKET*>();
}

void Packet_ReleaseNUnlock(classPACKET* pak){
	return CallStaticFunction<0x10004120, void, classPACKET*>(pak);
}

unsigned int StrToHashKey(const char* str){
	return CallStaticFunction<0x10038890, unsigned int, const char*>(str);
}

tagMallDATA::tagMallDATA() {};
tagMallDATA::~tagMallDATA() {};

unsigned char tagQuestData::GetBit(int iIndex) { return CallMemberFunction<tagQuestData, unsigned char, int>(0x1000CA90, this, iIndex); }
void tagQuestData::SetBit(int iIndex) { return CallMemberFunction<tagQuestData, void, int>(0x1000CAD0, this, iIndex); }
void tagQuestData::ClearBit(int iIndex) { return CallMemberFunction<tagQuestData, void, int>(0x1000CB20, this, iIndex); }
unsigned char tagQuestData::FlipBit(int Var1) { return 0; }
void tagQuestData::Init() { return CallMemberFunction<tagQuestData, void>(0x1000E020, this); }
void tagQuestData::CheckExpiredTIME() { return CallMemberFunction<tagQuestData, void>(0x1000E0D0, this); }
void tagQuestData::ClearAllSwitchs() { return CallMemberFunction<tagQuestData, void>(0x1000CB70, this); }
void tagQuestData::Set_SWITCH(int iSwitchNO, int iValue) { return CallMemberFunction<tagQuestData, void, int, int>(0x1000CBB0, this, iSwitchNO, iValue); }
int tagQuestData::Get_SWITCH(int iSwitchNO) { return CallMemberFunction<tagQuestData, int, int>(0x1000CC00, this, iSwitchNO); }
int tagQuestData::Flip_SWITCH(int Var1) { return 0; }

