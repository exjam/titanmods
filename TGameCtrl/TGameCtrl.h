#ifndef TGAMECTRL_H
#define TGAMECTRL_H

#pragma warning(disable : 4251)

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/*
FAKE THESE PLZ COS SHIT CHANGES
std_string = 0x1C
std_deque = 0x14
std_list = 0x0C
*/

class std_string {
	char data[0x1C];
};

template<class T>
class std_deque {
	char data[0x14];
};

template<class T>
class std_list {
	char data[0x0C];
};


#ifdef TGAMECTRL_EXPORTS
# define TGAMECTRL_API __declspec(dllexport)
#else
# define TGAMECTRL_API __declspec(dllimport)
#endif

/*
DONE:
6602044E "IMAGE"
66020499 "BUTTON"
6602052F "CAPTION"
66020930 "CHECKBOX"
6602057A "EDITBOX"
6602080B "GUAGE"
660205C3 "LISTBOX"
6602069E "RADIOBOX"
660206E7 "RADIOBUTTON"
66020655 "SCROLLBAR"
66020854 "TABBEDPANE"
66020730 "COMBOBOX"
660208F5 "ZLISTBOX"

MAYBE:
66020968 "PANE" <-- resizable tabbed pane or something like that
660209A0 "TABLE" <-- like in create clan, with the clan marks
6602060C "STATIC" <-- no used static string though

CBA BRUV
66020779 "JCOMBOBOX" <-- wut are Jxxx?
660207C2 "JLISTBOX" <-- wut are Jxxx?
6602089D "BACKGROUNDIMAGE" <-- not used

WTF NO EXIST SIR? NO EXIST!?
660204E4 "PUSHBUTTON" <-- toggle button on/off
*/

#endif
