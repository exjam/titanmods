class CClanMemberItem :	public CWinCtrl {
public:
	CClanMemberItem(const char* name, int playerClass, int clanPoint, int channelNo, short level, short job);
	virtual ~CClanMemberItem();
	const char* GetName();

public:
	int	mOnlineMarkImageID;
	int	mOfflineMarkImageID;
	int mClass;
	int mClanPoint;
	int mChannelNo;
	short mLevel;
	short mJob;
};

const char* CClanMemberItem::GetName(){
	return CallMemberFunction<CClanMemberItem, const char*>(0x004CA1B0, this);
}