#ifndef CTERRAIN_H
#define CTERRAIN_H

class CMAP;

class CTERRAIN 
{
public:
	static CTERRAIN* Instance(){
		return *reinterpret_cast<CTERRAIN**>(0x695B30);
	}

	CMAP* GetMapPtrByWorldCoordinates(float fWorldX, float fWorldY){
		return CallMemberFunction<CTERRAIN, CMAP*, float, float>(0x00430470, this, fWorldX, fWorldY);
	}

	unsigned char unk[0x48];
	short m_nZoneNO;
};

#endif
