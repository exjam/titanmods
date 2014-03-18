#ifndef CMAP_H
#define CMAP_H

class CMAP
{
public:
	bool AddObject(int iObjectIndex, D3DVECTOR* Position, D3DXQUATERNION* Rotate, D3DVECTOR* Scale){
		return CallMemberFunction<CMAP, bool, int, D3DVECTOR*, D3DXQUATERNION*, D3DVECTOR*>(0x00434B40, this, iObjectIndex, Position, Rotate, Scale);
	}

	float GetHEIGHT (float fWorldX, float fWorldY) {
		return CallMemberFunction<CMAP, float, float, float>(0x00431E30, this, fWorldX, fWorldY);
	}
};

#endif
