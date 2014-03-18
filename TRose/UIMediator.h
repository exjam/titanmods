#ifndef UIMED_H
#define UIMED_H

class UIMediator {
public:
	static UIMediator* Instance(){
		return reinterpret_cast<UIMediator*>(0x006974D0);
	}

	void AddChatMsg( int iCharIndex, const char* pMsg, DWORD Color = 0xFF000000 )
	{
		return CallMemberFunction<UIMediator, void, int, const char*, DWORD>(0x00489980, this, iCharIndex, pMsg, Color); 
	}
};

#endif