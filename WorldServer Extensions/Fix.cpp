#include "main.hpp"
#include "..\Shared\Code.hpp"
#include "..\Shared\RunOnLoad.hpp"


void __stdcall Fixes(){
	// Friends list limit 
	Code::Write<unsigned char>(0x1001A21F, 0x64);

	// Clan deputy kick
	Code::Write<unsigned char>(0x10015C43, 6);

	// Friends list limit (2)
	unsigned char FriendList[] = { 0x8B, 0x4D, 0xB0, 0xE8, 0x6E, 0x02, 0x00, 0x00, 0x83, 0xF8, 0x64, 0x7D, 0x1F };
	Code::Write(0x1001A24A, FriendList, 13);
}
/*
4 + 1 + 16 + 1 = 22 maxlength (binary) (44 hex) * 100 = binary(2200)

1024 = 35
2048 = 70
4096 = 140
2900
*/

RunOnLoad(Fixes);

/*
TRUE: 
S->C
(Invite send @ Command)
1000C9C4  |. 66:C740 02 E00>MOV WORD PTR DS:[EAX+2],7E0
1000C9CA  |. 8B45 8C        MOV EAX,DWORD PTR SS:[EBP-74]
1000C9CD  |. 66:C700 0700   MOV WORD PTR DS:[EAX],7
1000C9D2  |. 8B45 8C        MOV EAX,DWORD PTR SS:[EBP-74]
1000C9D5  |. C640 06 02     MOV BYTE PTR DS:[EAX+6],2

Send invite to invited person

10015BB8  |. 0FB7C0         MOVZX EAX,AX                                  ; |
10015BBB  |. 83C0 01        ADD EAX,1                                     ; |
10015BBE  |. 50             PUSH EAX                                      ; |Arg3
10015BBF  |. 6A 0B          PUSH 0B                                       ; |Arg2 = 0000000B
10015BC1  |. 8B8D 9CFEFFFF  MOV ECX,DWORD PTR SS:[EBP-164]                ; |
10015BC7  |. 51             PUSH ECX                                      ; |Arg1
10015BC8  |. E8 C36BFFFF    CALL SHO_WS_1.1000C790                        ; \SHO_WS_1.1000C790

FALSE: 
Invited refused, reply to inviter
S->C
10015C1C  |. 50             PUSH EAX                                      ; |Arg3
10015C1D  |. 6A 62          PUSH 62                                       ; |Arg2 = 00000062
10015C1F  |. 8B95 B4FEFFFF  MOV EDX,DWORD PTR SS:[EBP-14C]                ; |
10015C25  |. 52             PUSH EDX                                      ; |Arg1
10015C26  |. E8 656BFFFF    CALL SHO_WS_1.1000C790                        ; \SHO_WS_1.1000C790

Invite accepted, adding player
Add check here!
GS:
100A5997  |. 81C1 A0000000  ADD ECX,0A0
100A599D  |. E8 EEF3F5FF    CALL SHO_GS_1.CObjAVT::GetClanID
100A59A2  |. 50             PUSH EAX                                                     ; /Arg1                            ; |
WS:
100159DC  |. 8B8D F0FEFFFF  MOV ECX,DWORD PTR SS:[EBP-110]	
100159E2  |. E8 B92CFFFF    CALL SHO_WS_1.100086A0		// GetClanID
100159E7  |. 50             PUSH EAX                                      ; /Arg1

Invite:
Add name requester + req person to whitelist
Accept/Deny:
Check if it exists, Remove from list


Invite:
>> 7e0 02 <leader name>

Request:
<< 7e0 02 <leader name>

Accept:
>> 7e0

Deny:
>> 7e0

To members:
<< 7e0 61
<< 7e0 35
*/