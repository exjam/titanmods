#ifndef PACKET_H
#define PACKET_H
#pragma pack(push, 1)

#define PAK_CONTRIBUTION			0x604
#define PAK_ACHIEVEMENT				0x605
#define PAK_PARTYLIST				0x607
#define PAK_VENDMSG					0x609
#define	PAK_NPCVAR					0x610
#define	PAK_NPCVARALL				0x611
#define PAK_PLAYERDATA				0x612
#define PAK_DUEL					0x613
#define PAK_MESSAGE					0x614
#define PAK_ALLYCHAT				0x615
#define PAK_FLAGSTATUS				0x616


#define	CLI_ALIVE					0x0700
#define	SRV_ANNOUNCE_TEXT			0x0701
#define	CLI_ACCEPT_REQ				0x0703
#define	CLI_CHANNEL_LIST_REQ		0x0704
#define	CLI_CHECK_AUTH				0x0705
#define	CLI_LOGOUT_REQ				0x0707
#define CLI_LOGIN_REQ				0x0708
#define	CLI_SELECT_SERVER			0x070a
#define	CLI_JOIN_SERVER_REQ			0x070b
#define	SRV_JOIN_SERVER_REPLY		0x070c
#define	CLI_CHAR_LIST				0x0712
#define	CLI_CREATE_CHAR				0x0713
#define	CLI_DELETE_CHAR				0x0714
#define	CLI_SELECT_CHAR				0x0715
#define	CLI_RELAY_REPLY				0x071a
#define	CLI_CHAR_CHANGE				0x071c
#define	CLI_LOGOUT_CANCEL			0x0722
#define	CLI_QUEST_REQ				0x0730
#define	CLI_JOIN_ZONE				0x0753
#define	CLI_REVIVE_REQ				0x0755
#define	CLI_SET_REVIVE_POS			0x0756
#define	CLI_SET_VAR_REQ				0x0757
#define CLI_CHAR_INFO_REQ			0x0761
#define	CLI_SET_WEIGHT_RATE			0x0762
#define	CLI_CANTMOVE				0x0771
#define	CLI_SUMMON_CMD				0x0775
#define	CLI_SET_MOTION				0x0781
#define	CLI_TOGGLE					0x0782
#define	CLI_CHAT					0x0783
#define	CLI_WHISPER					0x0784
#define	CLI_SHOUT					0x0785
#define	CLI_PARTY_CHAT				0x0786
#define	CLI_CLAN_CHAT				0x0787
#define	CLI_ALLIED_CHAT				0x0788
#define	CLI_ALLIED_SHOUT			0x0789
#define	GSV_NPC_CHAR				0x0791
#define	GSV_MOB_CHAR				0x0792
#define	GSV_AVT_CHAR				0x0793
#define CLI_SETPOS				    0x0795
#define	CLI_STOP					0x0796
#define	CLI_ATTACK					0x0798
#define	CLI_DAMAGE					0x0799
#define	CLI_MOUSECMD				0x079a
#define	CLI_HP_REQ					0x079f
#define	CLI_STORE_TRADE_REQ			0x07a1
#define	CLI_USE_ITEM				0x07a3
#define	CLI_DROP_ITEM				0x07a4
#define	CLI_EQUIP_ITEM				0x07a5
#define	CLI_GET_FIELDITEM_REQ		0x07a7
#define CLI_TELEPORT_REQ			0x07a8
#define	CLI_USE_BPOINT_REQ			0x07a9
#define	CLI_SET_HOTICON				0x07aa
#define	CLI_SET_BULLET				0x07ab
#define	CLI_BANK_LIST_REQ			0x07ad
#define	CLI_MOVE_ITEM				0x07ae
#define	CLI_CREATE_ITEM_REQ			0x07af
#define	CLI_SKILL_LEVELUP_REQ		0x07b1
#define	CLI_SELF_SKILL				0x07b2
#define	CLI_TARGET_SKILL			0x07b3
#define	CLI_POSITION_SKILL			0x07b4
#define	CLI_APPRAISAL_REQ			0x07ba
#define	CLI_CRAFT_ITEM_REQ			0x07bc
#define	CLI_SET_WISHITEM			0x07bf
#define	CLI_TRADE_P2P				0x07c0
#define	CLI_TRADE_P2P_ITEM			0x07c1
#define CLI_P_STORE_OPEN			0x07c2
#define CLI_P_STORE_CLOSE			0x07c3
#define CLI_P_STORE_LIST_REQ		0x07c4
#define CLI_P_STORE_BUY_REQ			0x07c5
#define	CLI_P_STORE_SELL_REQ		0x07c6
#define	CLI_ASSEMBLE_RIDE_ITEM		0x07ca
#define	CLI_USE_ITEM_TO_REPAIR		0x07cb
#define	CLI_REPAIR_FROM_NPC			0x07cd
#define	CLI_PARTY_REQ				0x07d0
#define	CLI_PARTY_REPLY				0x07d1
#define	CLI_PARTY_RULE				0x07d7
#define	CLI_ITEM_RESULT_REPORT		0x07d8
#define	CLI_MALL_ITEM_REQ			0x07d9
#define	CLI_MOVE_ZULY				0x07da
#define	CLI_CART_RIDE				0x07dd
#define CLI_CLAN_COMMAND			0x07e0
#define	CLI_MESSENGER				0x07e1
#define	CLI_MESSENGER_CHAT			0x07e2					   
#define	CLI_CHATROOM				0x07e3					   
#define	CLI_CHATROOM_MSG			0x07e4
#define	CLI_MEMO					0x07e5
#define	CLI_CLANMARK_SET			0x07e6
#define	CLI_CLANMARK_REQ			0x07e7
#define CLI_CLANMARK_REG_TIME		0x07e8




class Packet {
public:
	Packet()
	{
		SetSize(6);
		SetCommand(0x700);
	}

	Packet(short cmd)
	{
		SetSize(6);
		SetCommand(cmd);
	}

	// Get @ Pos -> DATA
	template <class T> void Set(int pos, T value){
		*((T*)(mData+pos)) = value;
	}

	template <class T> T Get(int pos){
		return *((T*)(mData+pos));
	}

	char* GetString(int pos){
		char* tmp = (char*)(&mData[pos]);
		return tmp;
	}

	// Add @ mSize -> BUFFER
	template <class T> void Add(T value){
		*((T*)(mBuffer + mSize)) = value;
		mSize += sizeof(T);
	}

	void AddString(const char* val, bool zt = true){
		size_t len = strlen(val);
		memcpy_s(mBuffer + mSize, 0x800 - mSize, val, len);
		mSize += len;
		if(zt){
			mBuffer[mSize] = 0;
			++mSize;
		}
	}

	/*void ToLog(bool Out) {
		if (Command() == 0x797) return;

		if (Out) {
			printf( "SEND >> %s\n", ToString() );
		} else {
			printf( "RECV << %s\n", ToString() );
		}
	}*/

	void Reset(){
		SetSize(6);
		SetCommand(0x700);
	}

	void SetSize(short size){
		mSize = size;
	}

	void SetCommand(short command){
		mCommand = command;
	}

	short Size(){
		return mSize;
	}

	short Command(){
		return mCommand;
	}

private:
	union {
		struct {
			short mSize;
			unsigned short mCommand;
			unsigned short mReserved;
			unsigned char mData[1];
		};
		unsigned char mBuffer[0x800];
	};
};

#pragma pack(pop)
#endif

