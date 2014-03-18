#ifndef CAMERA_H
#define CAMERA_H

class CCamera
{
public:
	void Add_Distance(float distance) {
		return CallMemberFunction<CCamera, void, float>(0x00406090, this, distance); 
	}

	static CCamera* Instance(){
		return *reinterpret_cast<CCamera**>(0x00695B40);
	}
};

#endif