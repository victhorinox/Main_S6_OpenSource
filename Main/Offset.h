#pragma once

#define MAIN_WINDOW 0x00E8C578

#define MAIN_LANGUAGE 0x00E8C5C4
#define MAIN_CONNECTION_STATUS 0x08793704
#define MAIN_SCREEN_STATE 0x00E609E8
#define MAIN_CHARACTER_STRUCT 0x08128AC8
#define MAIN_VIEWPORT_STRUCT 0x07BC4F04
#define MAIN_PACKET_SERIAL 0x08793700
#define MAIN_HELPER_STRUCT 0x00E8CB7C
#define MAIN_FONT_SIZE 0x081C0380
#define MAIN_RESOLUTION 0x00E8C240
#define MAIN_RESOLUTION_X 0x00E61E58
#define MAIN_RESOLUTION_Y 0x00E61E5C
#define MAIN_PARTY_MEMBER_COUNT 0x081F6B6C

#define ProtocolCore ((BOOL(*)(DWORD,BYTE*,DWORD,DWORD))0x00663B20)
#define DrawInterface ((void(*)(DWORD,float,float,float,float))0x00790B50)
#define DrawInterfaceText ((void(*)(char*,int,int,int,int,int,int,int))0x007D04D0)

#define GetTextLineThis 0x8128ADC
#define GetTextLine ((char*(__thiscall*)(void*, int)) 0x0402320)

#define pSetFont				((int(__thiscall*)(LPVOID This, int a2)) 0x420120)
#define pSetBkColor				((int(__thiscall*)(LPVOID This, BYTE red, BYTE green, BYTE blue, BYTE alpha)) 0x4200B0)
#define pSetTexture				((void(__cdecl*)(int a1)) 0x00635CF0)//sub_635CF0(a1)
#define	pFontNormal				*(HGDIOBJ*)0x00E8C588
#define pFontBold				*(HGDIOBJ*)0x00E8C58C
#define pFontBigBold			*(HGDIOBJ*)0x00E8C590
#define pFontNormal2			*(HGDIOBJ*)0x00E8C594

//#define pPlayerState         (int)0x0E609E8
#define EnableAlphaTest            ((void(__cdecl*)(BYTE Mode)) 0x635FD0)
#define pSetTextSize            ((int(__thiscall*)(LPVOID This, HFONT a2)) 0x420120)
#define pSetTextColor         ((void(__thiscall*)(LPVOID This, BYTE r, BYTE g, BYTE b, BYTE h)) 0x00420040)
#define pSetBackgroundTextColor   ((void(__thiscall*)(LPVOID This, int r, int g, int b, int h)) 0x004200B0)
#define pCheckWindow         ((bool(__thiscall*)(LPVOID This, int Code)) 0x0085EC20)
#define NoticeInverse               (int)0x81C0418

#define pSetFont                ((int(__thiscall*)(LPVOID This, int a2)) 0x420120)