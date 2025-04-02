#include "stdafx.h"
#include "InterEx.h"
#include "Defines.h"
#include "TMemory.h"
#include "import.h"
#include "PrintPlayer.h"
#include "Interface.h"
#include "Util.h"
#include "Protect.h"
#include "WindowsStruct.h"

static char* MasterIcon	= "Custom\\Interface\\S8\\new_Master_Icon.tga";
static char* NonMasterIcon	= "Custom\\Interface\\S8\\new_Master_non_Icon.tga";

__declspec(naked) void UsingSkillPosition()
{
	static float UsingSkillPositionX = 309.8f;
	static float UsingSkillPositionY = 442.5f;
	static float UsingSkillPositionW = 20.0f;
	static float UsingSkillPositionH = 28.0f;
	static DWORD UsingSkillPosition_buff = 0x00813900;
	
	_asm
	{
		FLD DWORD PTR DS:[UsingSkillPositionX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[UsingSkillPositionY]
		FSTP DWORD PTR SS:[EBP-0x4]
		FLD DWORD PTR DS:[UsingSkillPositionW]
		FSTP DWORD PTR SS:[EBP-0x18]
		FLD DWORD PTR DS:[UsingSkillPositionH]
		FSTP DWORD PTR SS:[EBP-0x14]
		jmp [UsingSkillPosition_buff]
	}
}


__declspec(naked) void SkillClickPosition()
{
	static float SkillClickPositionX = 310.0f;
	static float SkillClickPositionY = 443.0f;
	static float SkillClickPositionW = 20.0f;
	static float SkillClickPositionH = 27.0f;
	static DWORD SkillClickPosition_buff = 0x00812734;
	
	_asm
	{
		FLD DWORD PTR DS:[SkillClickPositionX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillClickPositionY]
		FSTP DWORD PTR SS:[EBP-0x4]
		FLD DWORD PTR DS:[SkillClickPositionW]
		FSTP DWORD PTR SS:[EBP-0x20]
		FLD DWORD PTR DS:[SkillClickPositionH]
		FSTP DWORD PTR SS:[EBP-0x1C]
		jmp [SkillClickPosition_buff]
	}
}

__declspec(naked) void SkillBarDrawPosition()
{
	static float SkillBarDrawPositionX = 222.0f;
	static float SkillBarDrawPositionY = 480.0f;
	static float SkillBarDrawPositionW = 160.0f;
	static float SkillBarDrawPositionH = 38.0f;
	static DWORD SkillBarDrawPosition_buff = 0x00812968;
	
	_asm
	{	
		FLD DWORD PTR DS:[SkillBarDrawPositionX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillBarDrawPositionY]
		FSTP DWORD PTR SS:[EBP-0x4]
		FLD DWORD PTR DS:[SkillBarDrawPositionW]
		FSTP DWORD PTR SS:[EBP-0x20]
		FLD DWORD PTR DS:[SkillBarDrawPositionH]
		FSTP DWORD PTR SS:[EBP-0x1C]
		jmp [SkillBarDrawPosition_buff]
	}
}

__declspec(naked) void SkillSwitchDraw()
{
	static float SkillSwitchDrawX = 385.0f;
	static float SkillSwitchDrawY = 370.0f;
	static float SkillSwitchDrawW = 32.0f;
	static float SkillSwitchDrawH = 38.0f;
	static float SkillSwitchDrawMW = 385.0f;
	static DWORD SkillSwitchDraw_buff = 0x008139CA;
	
	_asm
	{
		FLD DWORD PTR DS:[SkillSwitchDrawX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillSwitchDrawY]
		FSTP DWORD PTR SS:[EBP-0x4]	
		FLD DWORD PTR DS:[SkillSwitchDrawW]
		FSTP DWORD PTR SS:[EBP-0x18]
		FLD DWORD PTR DS:[SkillSwitchDrawH]
		FSTP DWORD PTR SS:[EBP-0x14]
		FLD DWORD PTR DS:[SkillSwitchDrawMW]
		FSTP DWORD PTR SS:[EBP-0x24]
		jmp [SkillSwitchDraw_buff]
	}
}

__declspec(naked) void SkillSwitchClick()
{
	static float SkillSwitchDrawX = 385.0f;
	static float SkillSwitchDrawY = 370.0f;
	static float SkillSwitchDrawW = 32.0f;
	static float SkillSwitchDrawH = 38.0f;
	static float SkillSwitchDrawMW = 385.0f;
	static DWORD SkillSwitchClick_buff = 0x00812D69;

	_asm
	{
		FLD DWORD PTR DS:[SkillSwitchDrawX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillSwitchDrawY]
		FSTP DWORD PTR SS:[EBP-0x4]
		FLD DWORD PTR DS:[SkillSwitchDrawW]
		FSTP DWORD PTR SS:[EBP-0x20]
		FLD DWORD PTR DS:[SkillSwitchDrawH]
		FSTP DWORD PTR SS:[EBP-0x1C]
		FLD DWORD PTR DS:[SkillSwitchDrawMW]
		FSTP DWORD PTR SS:[EBP-0x14]
		jmp [SkillSwitchClick_buff]
	}
}

__declspec(naked) void SkillBarra()
{
	static float SkillBarraX = 307.0f;
	static float SkillBarraY = 436.5f;
	static float SkillBarraW = 20.0f;
	static float SkillBarraH = 32.0f;
	static DWORD SkillBarra_buff = 0x0081379A;
	
	_asm
	{	
		FLD DWORD PTR DS:[SkillBarraX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillBarraY]
		FSTP DWORD PTR SS:[EBP-0x4]
		FLD DWORD PTR DS:[SkillBarraW]
		FSTP DWORD PTR SS:[EBP-0x18]
		FLD DWORD PTR DS:[SkillBarraH]
		FSTP DWORD PTR SS:[EBP-0x14]
		jmp [SkillBarra_buff]
	}
}

__declspec(naked) void QPosition1()
{
	static float BarNumberY = 455.0f;
	static DWORD QPosition1_buff = 0x00895A4F;
	
	_asm
	{
		FLD DWORD PTR DS:[BarNumberY]
		FSTP DWORD PTR SS:[ESP]
		jmp [QPosition1_buff]
	}
}

__declspec(naked) void QPosition2()
{
	static float QPosition2X = 222.0f;
	static DWORD QPosition2_buff = 0x00895A59;

	_asm
	{
		FLD DWORD PTR DS:[QPosition2X]
		FSTP DWORD PTR SS:[ESP]
		jmp [QPosition2_buff]
	}
}

__declspec(naked) void QPosition3()
{
	static float BarPotionY = 446.0f;
	static DWORD QPosition3_buff = 0x00895A63;
	
	_asm
	{
		FLD DWORD PTR DS:[BarPotionY]
		FSTP DWORD PTR SS:[ESP]
		jmp [QPosition3_buff]
	}
}

__declspec(naked) void QPosition4()
{
	static float QPosition4X = 204.0f;
	static DWORD QPosition4_buff = 0x00895A6D;
	
	_asm
	{
		FLD DWORD PTR DS:[QPosition4X]
		FSTP DWORD PTR SS:[ESP]
		jmp [QPosition4_buff]
	}
}

__declspec(naked) void WPosition1()
{
	static float BarNumberY = 455.0f;
	static DWORD WPosition1_buff = 0x00895AC4;
	
	_asm
	{
		FLD DWORD PTR DS:[BarNumberY]
		FSTP DWORD PTR SS:[ESP]
		jmp [WPosition1_buff]
	}
}

__declspec(naked) void WPosition2()
{
	static float WPosition2X = 249.0f;
	static DWORD WPosition2_buff = 0x00895ACE;
	
	_asm
	{
		FLD DWORD PTR DS:[WPosition2X]
		FSTP DWORD PTR SS:[ESP]
		jmp [WPosition2_buff]
	}
}

__declspec(naked) void WPosition3()
{
	static float BarPotionY = 446.0f;
	static DWORD WPosition3_buff = 0x00895AD8;
	
	_asm
	{
		FLD DWORD PTR DS:[BarPotionY]
		FSTP DWORD PTR SS:[ESP]
		jmp [WPosition3_buff]
	}
}

__declspec(naked) void WPosition4()
{
	static float WPosition4X = 231.0f;
	static DWORD WPosition4_buff = 0x00895AE2;
	
	_asm
	{
		FLD DWORD PTR DS:[WPosition4X]
		FSTP DWORD PTR SS:[ESP]
		jmp [WPosition4_buff]
	}
}

__declspec(naked) void EPosition1()
{
	static float BarNumberY = 455.0f;
	static DWORD EPosition1_buff = 0x00895B39;
	
	_asm
	{
		FLD DWORD PTR DS:[BarNumberY]
		FSTP DWORD PTR SS:[ESP]
		jmp [EPosition1_buff]
	}
}

__declspec(naked) void EPosition2()
{
	static float EPosition2X = 275.0f;
	static DWORD EPosition2_buff = 0x00895B43;

	_asm
	{
		FLD DWORD PTR DS:[EPosition2X]
		FSTP DWORD PTR SS:[ESP]
		jmp [EPosition2_buff]
	}
}

__declspec(naked) void EPosition3()
{
	static float BarPotionY = 446.0f;
	static DWORD EPosition3_buff = 0x00895B4D;
	
	_asm
	{
		FLD DWORD PTR DS:[BarPotionY]
		FSTP DWORD PTR SS:[ESP]
		jmp [EPosition3_buff]
	}
}

__declspec(naked) void EPosition4()
{
	static float EPosition4X = 257.0f;
	static DWORD EPosition4_buff = 0x00895B57;
	
	_asm
	{
		FLD DWORD PTR DS:[EPosition4X]
		FSTP DWORD PTR SS:[ESP]
		jmp [EPosition4_buff]
	}
}

_declspec(naked) void RPosition1()
{
	static float BarNumberY = 455.0f;
	static DWORD EPosition1_buff = 0x00895BAE;
	
	_asm
	{
		FLD DWORD PTR DS:[BarNumberY]
		FSTP DWORD PTR SS:[ESP]
		jmp [EPosition1_buff]
	}
}

__declspec(naked) void RPosition2()
{
	static float RPosition2X = 301.0f;
	static DWORD RPosition2_buff = 0x00895BB8;
	
	_asm
	{
		FLD DWORD PTR DS:[RPosition2X]
		FSTP DWORD PTR SS:[ESP]
		jmp [RPosition2_buff]
	}
}
__declspec(naked) void RPosition3()
{
	static float BarPotionY = 446.0f;
	static DWORD RPosition3_buff = 0x00895BC2;

	_asm
	{
		FLD DWORD PTR DS:[BarPotionY]
		FSTP DWORD PTR SS:[ESP]
		jmp [RPosition3_buff]
	}
}

__declspec(naked) void RPosition4()
{
	static float RPosition4X = 283.0f;
	static DWORD RPosition4_buff = 0x00895BCC;
	
	_asm
	{
		FLD DWORD PTR DS:[RPosition4X]
		FSTP DWORD PTR SS:[ESP]
		jmp [RPosition4_buff]
	}
}

//EXP
__declspec(naked) void EXP1()
{
	static float EXP1 = 92.0f;
	static DWORD EXP1_buff = 0x008113E4;
	
	_asm
	{
		FLD DWORD PTR DS:[EXP1]
		FSTP QWORD PTR SS:[EBP-0x10]
		jmp [EXP1_buff]
	}
}

__declspec(naked) void EXP2()
{
	static float EXP2 = 92.0f;
	static DWORD EXP2_buff = 0x0081152E;
	
	_asm
	{
		FLD DWORD PTR DS:[EXP2]
		FSTP QWORD PTR SS:[EBP-0x10]
		jmp [EXP2_buff]
	}
}

__declspec(naked) void EXP3()
{
	static float EXP3 = 92.0f;
	static DWORD EXP3_buff = 0x008116F5;
	
	_asm
	{
		FLD DWORD PTR DS:[EXP3]
		FSTP QWORD PTR SS:[EBP-0x10]
		jmp [EXP3_buff]
	}
}

__declspec(naked) void EXP4()
{
	static float EXP4 = 92.0f;
	static DWORD EXP4_buff = 0x008117FE;

	_asm
	{
		FLD DWORD PTR DS:[EXP4]
		FSTP QWORD PTR SS:[EBP-0x10]
		jmp [EXP4_buff]
	}
}

//EXP MASTER
__declspec(naked) void EXPMASTER1()
{
	static float EXPMASTER1 = 92.0f;
	static DWORD EXPMASTER1_buff = 0x00810B4D;
	
	_asm
	{
		FLD DWORD PTR DS:[EXPMASTER1]
		FSTP QWORD PTR SS:[EBP-0x10]
		jmp [EXPMASTER1_buff]
	}
}

__declspec(naked) void EXPMASTER2()
{
	static float EXPMASTER2 = 92.0f;
	static DWORD EXPMASTER2_buff = 0x00810C91;
	
	_asm
	{
		FLD DWORD PTR DS:[EXPMASTER2]
		FSTP QWORD PTR SS:[EBP-0x10]
		jmp [EXPMASTER2_buff]
	}
}

__declspec(naked) void EXPMASTER3()
{
	static float EXPMASTER3 = 92.0f;
	static DWORD EXPMASTER3_buff = 0x00810E58;
	
	_asm
	{
		FLD DWORD PTR DS:[EXPMASTER3]
		FSTP QWORD PTR SS:[EBP-0x10]
		jmp [EXPMASTER3_buff]
	}
}

__declspec(naked) void EXPMASTER4()
{
	static float EXPMASTER4 = 92.0f;
	static DWORD EXPMASTER4_buff = 0x00810F55;
	
	_asm
	{
		FLD DWORD PTR DS:[EXPMASTER4]
		FSTP QWORD PTR SS:[EBP-0x10]
		jmp [EXPMASTER4_buff]
	}
}

__declspec(naked) void BoxPoderes()
{
	static DWORD BoxPoderes_buff = 0x00813885;
	
	_asm
	{
		PUSH 0xc92c
			jmp [BoxPoderes_buff]
	}
}

__declspec(naked) void BoxPoderes2()
{
	static float TexY = 32.000f;
	static float TexX = 38.000f;
	static DWORD BoxPoderes2_buff = 0x00813880;
	
	_asm
	{
		PUSH ECX
			FLD DWORD PTR SS:[TexX]
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
			FLD DWORD PTR SS:[TexY]
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
			FLD DWORD PTR SS:[EBP-0x4]
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
			FLD DWORD PTR SS:[EBP-0x8]
		FSTP DWORD PTR SS:[ESP]
		jmp [BoxPoderes2_buff]
	}
}

__declspec(naked) void ChatFix()
{
	static DWORD ChatFix_buff = 0x00787BAD;
	
	_asm
	{
		FLD DWORD PTR DS:[0xD43849]
		jmp [ChatFix_buff]
	}
}

void LoadSkillMaster() 
{
	pLoadImage("Custom\\Interface\\S8\\new_Master_Icon.tga", 0x7B2E, GL_LINEAR, GL_CLAMP, 1, 0);
}

void SkillNumberPositionEx(float a4, float a5, int a6, float a7)
{
	return RenderNumber(a4 - 4.5f, a5 - 3.5f, a6, a7);
}

void RenderSands(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9)
{
	if (World == 8) //Tarkan
	{
		if (a1 == 32044)
		{
			RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}

		else if (a1 == 32045)
		{
			RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
	}

	if (World == 56) //Swamp of Peace
	{
		if (a1 == 32045)
		{
			RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
	
		else if (a1 == 32044)
		{
			RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
	}

	if (World == 56) //swamp
	{
		if (a1 == 32045)
		{
			RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
	
		else if (a1 == 32044)
		{
			RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
	}
}

__declspec(naked) void FixRavenSkillPos()
{
	static float SkillRavenDrawX = 290.0f;
	static float SkillRavenDrawY = 330.0f;
	static DWORD SkillRavenDraw_buff = 0x00813CCE;
	
	_asm
	{
		FLD DWORD PTR DS:[SkillRavenDrawX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillRavenDrawY]
		FSTP DWORD PTR SS:[EBP-0x4]
		jmp [SkillRavenDraw_buff]
	}
}

__declspec(naked) void FixRavenSkillClicPos()
{
	static float SkillRavenClicDrawX = 290.0f;
	static float SkillRavenClicDrawY = 330.0f;
	static DWORD SkillRavenClicDraw_buff = 0x008130BC;

	_asm
	{
		FLD DWORD PTR DS:[SkillRavenClicDrawX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillRavenClicDrawY]
		FSTP DWORD PTR SS:[EBP-0x4]
		jmp [SkillRavenClicDraw_buff]
	}
}

__declspec(naked) void ToolTipSkillEx()
{
	static DWORD SkillRavenClicDraw_buff = 0x00813C25;
	
	_asm
	{
		PUSH ECX
			MOV EDX,DWORD PTR SS:[EBP-0x04]
		MOV EAX,DWORD PTR DS:[EDX+0x4C]
		SUB EAX,0x12
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP-0x04]
		MOV EDX,DWORD PTR DS:[ECX+0x48]
		ADD EDX,0x0F
			jmp [SkillRavenClicDraw_buff]
	}
}

void RenderExpBar(int a1)
{
	DWORD ReadExp;
	DWORD ReadNextExp;
	QWORD CurrentMasterExp;
	QWORD NextMasterExp;

	pBarExpDraw();

	gInterface.DrawIMG(eMainEx700Exp, 36, 414.4f, 1.5, 2.0);

	if (pIsMaster(*(BYTE *)(*(DWORD *)0x7BC4F04 + 19)) == 1)
	{
		NextMasterExp = *(QWORD *)0x87935E8;
		CurrentMasterExp = *(QWORD *)0x87935E0;	
		gInterface.DrawFormat(eWhite150, 92.0f , 471, 454, 3, "%I64u / %I64u", CurrentMasterExp, NextMasterExp);
	}
	
	else
	{
		ReadExp = *(WORD *)(*(DWORD *)0x8128AC8 + 0x10);
		ReadNextExp = *(DWORD *)(*(DWORD *)0x8128AC8 + 0x14);
		gInterface.DrawFormat(eWhite150, 92.0f , 471, 454, 3, "%d / %d", ReadExp, ReadNextExp);
	}
}

signed int JCGetScreenWidth()
{
	signed int v52; // [sp+0h] [bp-4h]@11

	v52 = CGetScreenWidth2( );

	return v52;
}

signed int JCWinIngame()
{
	return 640;
}

bool CheckMouseWindow(int x, int y, int w, int h)
{
	if( pCheckWindow(pWindowThis(), 78) )
	{
		x = 70;

		return pCheckMouseOver(x, y, 380, h);
	}
	else
	{
		return pCheckMouseOver(x, y, w, h);
	}
}

void InitInterEx()
{
	//--
	//Fix Barra Negra
	//--
	//SetFloat((PVOID)(0x00D43668),480); //Texture Size
	SetDword(0x004D9746+3,480); //Disable background

	SetCompleteHook(0xE8, 0x00857746, &CheckMouseWindow); //-- baul check
	//--
	SetCompleteHook(0xE8, 0x005B6180, &JCGetScreenWidth);
	//--
	SetCompleteHook(0xE8, 0x0040F2E9, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x004D714E, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x004D79E7, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x004D9756, &JCWinIngame); //-- Camara General Renderizado
	//--
	SetCompleteHook(0xE8, 0x005DB4D5, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB1AA, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB22F, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB322, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB3A7, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB46D, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB4AD, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB534, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB5C4, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB628, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB68C, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB6ED, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x008605BF, &JCWinIngame); //-- load character
	//-
	SetCompleteHook(0xE8, 0x005B8344, &JCGetScreenWidth); //-- check cursor attack
	SetCompleteHook(0xE8, 0x0047FFF4, &JCGetScreenWidth); //-- Load MapName In-game
	SetCompleteHook(0xE8, 0x0048007C, &JCGetScreenWidth); //-- Load MapName In-game
	SetCompleteHook(0xE8, 0x004F2A6C, &JCGetScreenWidth); //-- algo del raven
	SetCompleteHook(0xE8, 0x004F2B55, &JCGetScreenWidth); //-- algo del raven
	SetCompleteHook(0xE8, 0x005B4956, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x005B9E22, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x005BAFE5, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x007D453E, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x007DF2D9, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x007DFD4B, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x007DFD54, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x007DFD68, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x007F3F87, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x007F4A63, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x007FAC46, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x008346F6, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x0085F90C, &JCGetScreenWidth);

	SetCompleteHook(0xE8, 0x0080F865, &RenderExpBar);
	//-
	SetCompleteHook(0xE9, 0x00813C11, &ToolTipSkillEx);
	//-
	SetRange((LPVOID)0x00813CBC, 0x6, ASM::NOP);
	SetJg((LPVOID)0x00813CBC, FixRavenSkillPos);
	//-
	SetRange((LPVOID)0x008130AA, 0x6, ASM::NOP);
	SetJg((LPVOID)0x008130AA, FixRavenSkillClicPos);
	
	//Fix background in Tarkan and other maps
	SetCompleteHook(0xE8, 0x005B97DC,&RenderSands);
	SetCompleteHook(0xE8, 0x005B984C,&RenderSands);
	SetCompleteHook(0xE8, 0x008C2E0F,&RenderSands);
	SetCompleteHook(0xE8, 0x008C2E7F,&RenderSands);
	SetCompleteHook(0xE8, 0x00914FC9,&RenderSands);
	SetCompleteHook(0xE8, 0x0091503E,&RenderSands);
	
	//Skill Number Position FIX
	SetOp((LPVOID)0x00814E63, (LPVOID) SkillNumberPositionEx, ASM::CALL);
	
	//Master Skill icon Fix
	SetRange((LPVOID)(0x0081A419), 0x5, ASM::NOP); //recarga la textura new_Master_non_Icon.ozt
	SetRange((LPVOID)(0x0081A3F9), 0x5, ASM::NOP);
	SetOp((LPVOID)(0x0081A3F9), (LPVOID)LoadSkillMaster, ASM::CALL); //recarga la textura new_Master_Icon.ozt
	
	//FIX MAP TAB
	SetFloat((PVOID)(0x00D46924), 480);
	SetDouble((PVOID)(0x00D46910), 480);

	//ChatFix
	SetRange((LPVOID)0x00787BA7, 5, ASM::NOP);
	SetJmp((LPVOID)0x00787BA7, ChatFix);
	
	//Skill Box
	SetRange((LPVOID)0x00813880, 5, ASM::NOP);
	SetOp((LPVOID)0x00813880, (LPVOID)BoxPoderes, ASM::JMP);
	SetRange((LPVOID)0x00813864, 5, ASM::NOP);
	SetOp((LPVOID)0x00813864, (LPVOID)BoxPoderes2, ASM::JMP);
	//--
    SetRange((LPVOID)0x0080F270, 0x4D1, ASM::NOP);//-> Interface -> Draw Button
	//-
	SetRange((LPVOID)0x0081028C, 0x24, ASM::NOP);
//	SetOp((LPVOID)0x0081028C, (LPVOID)AGPosition, ASM::JMP);
	//-
	SetRange((LPVOID)0x0081055C, 0x24, ASM::NOP);
//	SetOp((LPVOID)0x0081055C, (LPVOID)SDPosition, ASM::JMP);
	//-
	SetRange((LPVOID)0x0080FFAF, 0x24, ASM::NOP);
//	SetOp((LPVOID)0x0080FFAF, (LPVOID)MANAPosition, ASM::JMP);
	//-
	SetRange((LPVOID)0x0080FD5B, 0x24, ASM::NOP);
//	SetOp((LPVOID)0x0080FD5B, (LPVOID)HPPosition, ASM::JMP);
	//-
	SetRange((LPVOID)0x008138DF, 0x24, ASM::NOP);
	SetOp((LPVOID)0x008138DF, (LPVOID)UsingSkillPosition, ASM::JMP);
	//-
	SetRange((LPVOID)0x00812713, 0x24, ASM::NOP);
	SetOp((LPVOID)0x00812713, (LPVOID)SkillClickPosition, ASM::JMP);
	//-
	SetRange((LPVOID)0x00812947, 0x24, ASM::NOP);
	SetOp((LPVOID)0x00812947, (LPVOID)SkillBarDrawPosition, ASM::JMP);
	//-
	SetRange((LPVOID)0x008139A0, 0x2D, ASM::NOP);
	SetOp((LPVOID)0x008139A0, (LPVOID)SkillSwitchDraw, ASM::JMP);
	//-
	SetRange((LPVOID)0x00812D3F, 0x2D, ASM::NOP);
	SetOp((LPVOID)0x00812D3F, (LPVOID)SkillSwitchClick, ASM::JMP);
	//-
	SetRange((LPVOID)0x00813779, 0x24, ASM::NOP);
	SetOp((LPVOID)0x00813779, (LPVOID)SkillBarra, ASM::JMP);
	//-

	//->Q
	SetRange((LPVOID)0x00895A49, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895A49, (LPVOID)QPosition1, ASM::JMP);
	SetRange((LPVOID)0x00895A53, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895A53, (LPVOID)QPosition2, ASM::JMP);
	SetRange((LPVOID)0x00895A5D, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895A5D, (LPVOID)QPosition3, ASM::JMP);
	SetRange((LPVOID)0x00895A67, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895A67, (LPVOID)QPosition4, ASM::JMP);
	
	//->W
	SetRange((LPVOID)0x00895ABE, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895ABE, (LPVOID)WPosition1, ASM::JMP);
	SetRange((LPVOID)0x00895AC8, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895AC8, (LPVOID)WPosition2, ASM::JMP);
	SetRange((LPVOID)0x00895AD2, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895AD2, (LPVOID)WPosition3, ASM::JMP);
	SetRange((LPVOID)0x00895ADC, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895ADC, (LPVOID)WPosition4, ASM::JMP);
	
	//->E
	SetRange((LPVOID)0x00895B33, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895B33, (LPVOID)EPosition1, ASM::JMP);
	SetRange((LPVOID)0x00895B3D, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895B3D, (LPVOID)EPosition2, ASM::JMP);
	SetRange((LPVOID)0x00895B47, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895B47, (LPVOID)EPosition3, ASM::JMP);
	SetRange((LPVOID)0x00895B51, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895B51, (LPVOID)EPosition4, ASM::JMP);
	
	//-R
	SetRange((LPVOID)0x00895BA8, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895BA8, (LPVOID)RPosition1, ASM::JMP);
	SetRange((LPVOID)0x00895BB2, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895BB2, (LPVOID)RPosition2, ASM::JMP);
	SetRange((LPVOID)0x00895BBC, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895BBC, (LPVOID)RPosition3, ASM::JMP);
	SetRange((LPVOID)0x00895BC6, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895BC6, (LPVOID)RPosition4, ASM::JMP);

	//EXP
	SetRange((LPVOID)0x008113DE, 0x9, ASM::NOP);
	SetOp((LPVOID)0x008113DE, (LPVOID)EXP1, ASM::JMP);
	SetRange((LPVOID)0x00811528, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00811528, (LPVOID)EXP2, ASM::JMP);
	SetRange((LPVOID)0x008116EF, 0x9, ASM::NOP);
	SetOp((LPVOID)0x008116EF, (LPVOID)EXP3, ASM::JMP);
	SetRange((LPVOID)0x008117F8, 0x9, ASM::NOP);
	SetOp((LPVOID)0x008117F8, (LPVOID)EXP4, ASM::JMP);

	//EXPMASTER
	SetRange((LPVOID)0x00810B47, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00810B47, (LPVOID)EXPMASTER1, ASM::JMP);
	SetRange((LPVOID)0x00810C8B, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00810C8B, (LPVOID)EXPMASTER2, ASM::JMP);
	SetRange((LPVOID)0x00810E52, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00810E52, (LPVOID)EXPMASTER3, ASM::JMP);
	SetRange((LPVOID)0x00810F4F, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00810F4F, (LPVOID)EXPMASTER4, ASM::JMP);

	//Posicion Numero HP/MP
	SetFloat((PVOID)(0x00D461A4), 501);
	//Posicion Exp
	SetDouble((PVOID)(0x00D461C8), 450);
	//Posicion Numero Exp
	SetDouble((PVOID)(0x00D461C0), 572);
	//Tamaño numeros general (Prueba)
	SetDouble((PVOID)(0x00D27AF8), 0.4);

	SetDword((PVOID)(0x0081A3F4+1), (DWORD)MasterIcon); //1.04E-> 0081A3F4 || 1.04D->0x0081A2A4
	SetDword((PVOID)(0x0081A414+1), (DWORD)NonMasterIcon); //1.04E-> 0081A414 || 1.04D->0x0081A2C4

	SetDword(0x0081A38A+1,(DWORD)"Custom\\Interface\\S8\\new_Master_back01.tga");
	SetDword(0x0081A3AA+1,(DWORD)"Custom\\Interface\\S8\\new_Master_back02.tga");
	SetDword(0x0080F04A+1,(DWORD)"Custom\\Interface\\S8\\Exbar_Master.jpg");
	SetDword(0x0080F02A+1,(DWORD)"Custom\\Interface\\S8\\newui_exbar.jpg");

	//newui_skill2
	SetDword(0x008124FA+1,(DWORD)"Custom\\Interface\\S8\\newui_skill2.tga");
	SetDword(0x0086D10C+1,(DWORD)"Custom\\Interface\\S8\\newui_skill2.tga");
	SetDword(0x00888E7A+1,(DWORD)"Custom\\Interface\\S8\\newui_skill2.tga");
	
	//newui_non_skill2
	SetDword(0x0081259A+1,(DWORD)"Custom\\Interface\\S8\\newui_non_skill2.tga");
	SetDword(0x0086D12C+1,(DWORD)"Custom\\Interface\\S8\\newui_non_skill2.tga");

	//PetLife Bar
	SetDword(0x007E0A6A+1,(DWORD)"Custom\\Interface\\S8\\newui_Pet_Back.tga");
	SetDword(0x007E0A8A+1,(DWORD)"Custom\\Interface\\S8\\newui_Pet_HpBar.jpg");
	SetDword(0x0084E8DA+1,(DWORD)"Custom\\Interface\\S8\\newui_pet_lifebar01.jpg");
	SetDword(0x0084E8FA+1,(DWORD)"Custom\\Interface\\S8\\newui_pet_lifebar02.jpg");

	//Fixes by Emershow
	SetByte((PVOID)(0x00835227+2),0x120); //SetOption in Inventory	
	SetByte((PVOID)(0x0083533F+2),0x120); //SocketOption in Inventory
	SetByte((PVOID)(0x0077FA37+2),0x120); //ServerName in Character
	SetByte((PVOID)(0x0077FAC2+2),0x120); //ServerName in Character
	SetByte((PVOID)(0x00847281+2),0x120); //Tax rate in npcs
	SetByte((PVOID)(0x0082CF24+2),0x100); //General texts in chaos machine
	SetByte((PVOID)(0x00841FDF+2),0x10D); //Personal store name
	SetByte((PVOID)(0x007D56D1+2),0x10C); //expanded inventory name
}