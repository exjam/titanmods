////////////////////////////////////////////////////////////////////////
/////// CPacket ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CPacket_H
#define CPacket_H

#define PAK_CONTRIBUTION 0x604
#define PAK_ACHIEVEMENT 0x605
#define PAK_PARTYLIST 0x607
#define PAK_VENDMSG 0x609
#define PAK_NPCVAR 0x610
#define PAK_NPCVARALL 0x611
#define PAK_PLAYERDATA 0x612
#define PAK_DUEL  0x613
#define PAK_MESSAGE  0x614
#define PAK_ALLYCHAT 0x615
#define PAK_FLAGSTATUS 0x616

class CPacket {
public:
	CPacket()
	{
		mCommand = 0x700;
		mSize = 6;
		mChecksum = 0;
		mCursor = 6;
	}

	CPacket(short cmd)
	{
		mCommand = cmd;
		mSize = 6;
		mChecksum = 0;
		mCursor = 6;
	}

	void CreateNew(unsigned short cmd) {
		mCommand = cmd;
		mSize = 6;
		mChecksum = 0;
		mCursor = 6;
	}

	// Get @ Pos -> DATA
	template<typename T> T Get(int pos) const {
		return *((T*)&mData[pos]);
	}

	const char* GetString(int pos){
		return (const char*)&mData[pos];
	}

	// Add @ mSize -> BUFFER
	template<typename T> void Add(T val){
		*((T*)&mBuffer[mSize]) = val;
		mSize += sizeof( T );
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

	// Get @ Cursor -> BUFFER
	/*template<typename T> T Get(){
		T tmp = *((T*)&mBuffer[mCursor]);
		mCursor += sizeof(T);
		return tmp;
	}

	//0  1  2	 3	4  5        6
	//30 07 00 00 11 22 		12	34	35	78	90
	const char* GetString(){
		const char* tmp = (const char*)(&mBuffer[mCursor]);
		mCursor += strlen(tmp) + 1;
		return tmp;
	}*/

	void ToLog() {
		printf( "%03x(%u) ", Command(), Size() );
		for( unsigned short i = 0; i < Size() - 6; i++ ) {
			printf( "%02x ", mData[ i ] );
		}
		printf( "\n" );
	}

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
			unsigned short mSize;
			unsigned short mCommand;
			unsigned short mChecksum;
			char mData[1];
		};
		char mBuffer[0x800];
	};
	unsigned short mCursor;
};
 
#endif