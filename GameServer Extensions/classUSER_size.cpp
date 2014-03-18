#include "..\Shared\RunOnLoad.hpp"

//Increase size from 2A40 -> 2A44 :D
void __stdcall WriteUserSizes(){
	Code::Write<unsigned int>(0x100021C3, 0x2A44);
	Code::Write<unsigned int>(0x1000B669, 0x2A44);
	Code::Write<unsigned int>(0x1000B6A0, 0x2A44);
	Code::Write<unsigned int>(0x1000B70F, 0x2A44);
	Code::Write<unsigned int>(0x1000B74B, 0x2A44);

	unsigned char data[] = { 0x89, 0x4D, 0xFC, 0xC7, 0x81, 0x40, 0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	Code::Write(0x1000B7F4, data, 13);
}

RunOnLoad(WriteUserSizes);



