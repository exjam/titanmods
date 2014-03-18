#ifndef STBS_H
#define STBS_H

struct STBVALUE {
	bool mIsString;
	int mIntVal;
	void* mStrVal;
};

class STB {
public:
	static STBVALUE** GetZoneSTB(){
		return *(STBVALUE***)0x69614C;
	}
};

#endif
