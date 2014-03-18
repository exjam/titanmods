#ifndef DRAWIMPL_H
#define DRAWIMPL_H

//This class is supposed to be a implementation of ITDraw
class DrawImpl {
public:
	static DrawImpl* Instance(){
		return reinterpret_cast<DrawImpl*>(0x673EB8);
	}

	void Draw2D(int x, int y, int moduleID, int graphicID, int colour){ 
		return CallMemberFunction<DrawImpl, void, int, int, int, int, int>(0x00488B40, this, x, y, moduleID, graphicID, colour);
	}
	void Draw2DW(float x, float y, float z, int Width, int moduleID, int graphicID){ 
		return CallMemberFunction<DrawImpl, void, float, float, float, int, int, int>(0x00488F30, this, x, y, z, Width, moduleID, graphicID);
	}
	void Draw3D(float x, float y, float z, int moduleID, int graphicID, int colour){ 
		return CallMemberFunction<DrawImpl, void, float, float, float, int, int, int>(0x00488CE0, this, x, y, z, moduleID, graphicID, colour);
	}
};

enum
{	
	IMAGE_RES_UI				= 0,
	IMAGE_RES_ITEM				= 1,
	IMAGE_RES_NPCFACE			= 2,
	IMAGE_RES_EXUI				= 3,
	IMAGE_RES_SKILL_ICON		= 4,
	IMAGE_RES_STATE_ICON		= 5,
	IMAGE_RES_SOCKETJAM_ICON	= 6,
	IMAGE_RES_CLANBACK			= 7,
	IMAGE_RES_CLANCENTER		= 8,
	IMAGE_RES_TARGETMARK		= 9,
	IMAGE_RES_WARNING			= 10,
	IMAGE_RES_NEWUI				= 11,
	IMAGE_RES_MAX,
};

#endif
