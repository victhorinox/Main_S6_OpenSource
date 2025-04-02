#pragma once

#define RenderBitmapUV ((void(__cdecl*)(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9)) 0x00638E90)
#define RenderNumber ((void(__cdecl*)(float a4, float a5, int a6, float a7)) 0x00791000)
#define World *(int*)0x0E61E18
#define pCheckMouseOver ((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)
#define RenderBitmap ((void(__cdecl*)(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)) 0x00637C60)
#define sub_4C8640 ((char(__thiscall*)(LPVOID This, char a2)) 0x4C8640)
#define pBarExpDraw ((void(__cdecl*)()) 0x00810700)
#define CGetScreenWidth2 ((signed int(*)()) 0x005C6E80)

enum iInterfaceEx
{
/*	eMainEx700Exp = 59000,
	eMainEx700 = 31293,
	eShop1 = 0x901,
	eShop2 = 0x902,
	eCharacter1 = 0x903,
	eCharacter2 = 0x904,
	eInventory1 = 0x905,
	eInventory2 = 0x906,
	eQuest1 = 0x907,
	eQuest2 = 0x908,
	eCommunity1 = 0x909,
	eCommunity2 = 0x910,
	eSystem1 = 0x911,
	eSystem2 = 0x912,*/

	eMainEx700Exp = 2,
	eMainEx700,
	eShop1,
	eShop2,
	eCharacter1,
	eCharacter2,
	eInventory1,
	eInventory2,
	eQuest1,
	eQuest2,
	eCommunity1,
	eCommunity2,
	eSystem1,
	eSystem2,

	ButtonSettings,
	ButtonStart,
	ButtonStop,
	ButtonStartAttack,
};

bool WindowsCombinedChecks();
bool WindowsCombined2Checks();
bool WindowsCheck();
void InitInterEx();