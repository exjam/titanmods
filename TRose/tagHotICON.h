#ifndef TAGHOTICON_H
#define TAGHOTICON_H

enum t_HotIconTYPE {
	INV_ICON = 1,
	COMMAND_ICON,
	SKILL_ICON,
	EMOTION_ICON,
	DIALOG_ICON,
	CLANSKILL_ICON,
};

struct tagHotICON {
	union {
		struct {
			unsigned short mType : 5;
			unsigned short mSlotNo : 11;
		};
		unsigned short mHotICON;
	};
};

#endif
