#ifndef TOOLTIP_H
#define TOOLTIP_H

#include "Game.h"


class Tooltip {
public:
	Tooltip() { m_iWidth = 1; CallMemberFunction<Tooltip, void>(0x00485800, this); }
	virtual ~Tooltip() { m_iWidth = 0; }
	void AddString(const char* text, unsigned long color=0xFFFFFFFF, HNODE hFont=GameDATA->m_hFONT[ FONT_NORMAL ], UINT uFormat=DT_LEFT){ return CallMemberFunction<Tooltip, void, const char*, unsigned long, HNODE, UINT>(0x00485D00, this, text, color, hFont, uFormat);}
	void Clear(){  return CallMemberFunction<Tooltip, void>(0x00485630, this); }
	void Draw(){  return CallMemberFunction<Tooltip, void>(0x00485190, this); }
	void SetPosition( POINT pt ){ return CallMemberFunction<Tooltip, void, POINT>(0x004850F0, this, pt); }

public:
	int			m_iLineImageNo;
	POINT		m_ptPosition;
	int			m_iWidth;
	int			m_iHeight;
	UINT		m_uMaxSizeString;///최대 글자수 
	char mUnkData[0x100];
};


#endif