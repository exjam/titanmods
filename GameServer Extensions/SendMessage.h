#ifndef SEND_MESSAGE_H
#define SEND_MESSAGE_H

static enum {
	CHAT_TYPE_ALL,
	CHAT_TYPE_SHOUT,
	CHAT_TYPE_PARTY,
	CHAT_TYPE_WHISPER,
	CHAT_TYPE_NOTICE,
	CHAT_TYPE_SYSTEM,
	CHAT_TYPE_ERROR,
	CHAT_TYPE_QUEST,
	CHAT_TYPE_QUESTREWARD,
	CHAT_TYPE_CLAN,
	CHAT_TYPE_TRADE,
	CHAT_TYPE_ALLIED,
	CHAT_TYPE_FRIEND,
	CHAT_TYPE_MAX,
};

void SendMSG(class classUSER* user, int type, const char* text, bool zone = false, unsigned int colour = 0);

#endif
