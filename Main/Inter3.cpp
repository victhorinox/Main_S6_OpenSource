#include "stdafx.h"
#include "Inter3.h"
#include "Defines.h"
#include "TMemory.h"
#include "User.h"
#include "Offset.h"
#include "Import.h"
#include "Util.h"
#include "Protect.h"
#include "Interface.h"

__declspec(naked) void DrawAGPosition()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static float AGPositionW = 14.0f;
		static float AGPositionH = 38.0f;
		static float AGPositionX = 551.5f;
		static float AGPositionY = 435.7f;
		static DWORD AGPosition_buff = 0x008102AD;
		
		_asm
		{
			FLD DWORD PTR DS:[AGPositionW]
			FSTP DWORD PTR SS:[EBP-0x18]
			FLD DWORD PTR DS:[AGPositionH]
			FSTP DWORD PTR SS:[EBP-0x14]
			FLD DWORD PTR DS:[AGPositionX]
			FSTP DWORD PTR SS:[EBP-0x10]
			FLD DWORD PTR DS:[AGPositionY]
			FSTP DWORD PTR SS:[EBP-0x0C]
			jmp [AGPosition_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static float AGPositionW = 14.0f;
		static float AGPositionH = 38.0f;
		static float AGPositionX = 551.2f;
		static float AGPositionY = 434.2f;
		static DWORD AGPosition_buff = 0x008102AD;

		_asm
		{
			FLD DWORD PTR DS:[AGPositionW]
			FSTP DWORD PTR SS:[EBP-0x18]
			FLD DWORD PTR DS:[AGPositionH]
			FSTP DWORD PTR SS:[EBP-0x14]
			FLD DWORD PTR DS:[AGPositionX]
			FSTP DWORD PTR SS:[EBP-0x10]
			FLD DWORD PTR DS:[AGPositionY]
			FSTP DWORD PTR SS:[EBP-0x0C]
			jmp [AGPosition_buff]
		}
	}
}

__declspec(naked) void DrawSDPosition()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static float SDPositionW = 14.0f;
		static float SDPositionH = 38.0f;
		static float SDPositionX = 73.0f;
		static float SDPositionY = 435.7f;
		static DWORD SDPosition_buff = 0x0081057D;
		
		_asm
		{
			FLD DWORD PTR DS:[SDPositionW]
			FSTP DWORD PTR SS:[EBP-0x20]
			FLD DWORD PTR DS:[SDPositionH]
			FSTP DWORD PTR SS:[EBP-0x1C]
			FLD DWORD PTR DS:[SDPositionX]
			FSTP DWORD PTR SS:[EBP-0x10]
			FLD DWORD PTR DS:[SDPositionY]
			FSTP DWORD PTR SS:[EBP-0x0C]
			jmp [SDPosition_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static float SDPositionW = 14.0f;
		static float SDPositionH = 37.0f;
		static float SDPositionX = 73.0f;
		static float SDPositionY = 435.0f;
		static DWORD SDPosition_buff = 0x0081057D;
		
		_asm
		{
			FLD DWORD PTR DS:[SDPositionW]
			FSTP DWORD PTR SS:[EBP-0x20]
			FLD DWORD PTR DS:[SDPositionH]
			FSTP DWORD PTR SS:[EBP-0x1C]
			FLD DWORD PTR DS:[SDPositionX]
			FSTP DWORD PTR SS:[EBP-0x10]
			FLD DWORD PTR DS:[SDPositionY]
			FSTP DWORD PTR SS:[EBP-0x0C]
			jmp [SDPosition_buff]
		}
	}
}

__declspec(naked) void DrawMANAPosition()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static float MANAPositionW = 52.5f;
		static float MANAPositionX = 488.0f;
		static float MANAPositionH = 51.0f;
		static float MANAPositionY = 428.5f;
		static DWORD MANAPosition_buff = 0x0080FFD0;
		
		_asm
		{
			FLD DWORD PTR DS:[MANAPositionW]
			FSTP DWORD PTR SS:[EBP-0x20]
			FLD DWORD PTR DS:[MANAPositionX]
			FSTP DWORD PTR SS:[EBP-0x0C]
			FLD DWORD PTR DS:[MANAPositionH]
			FSTP DWORD PTR SS:[EBP-0x1C]
			FLD DWORD PTR DS:[MANAPositionY]
			FSTP DWORD PTR SS:[EBP-0x8]
			jmp [MANAPosition_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static float MANAPositionW = 52.5f;
		static float MANAPositionX = 489.0f;
		static float MANAPositionH = 51.0f;
		static float MANAPositionY = 428.5f;
		static DWORD MANAPosition_buff = 0x0080FFD0;
		
		_asm
		{
			FLD DWORD PTR DS:[MANAPositionW]
			FSTP DWORD PTR SS:[EBP-0x20]
			FLD DWORD PTR DS:[MANAPositionX]
			FSTP DWORD PTR SS:[EBP-0x0C]
			FLD DWORD PTR DS:[MANAPositionH]
			FSTP DWORD PTR SS:[EBP-0x1C]
			FLD DWORD PTR DS:[MANAPositionY]
			FSTP DWORD PTR SS:[EBP-0x8]
			jmp [MANAPosition_buff]
		}
	}
}

__declspec(naked) void DrawHPPosition()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static float HPPositionW = 52.5f;
		static float HPPositionH = 51.0f;
		static float HPPositionX = 98.0f;
		static float HPPositionY = 428.5f;
		static DWORD HPPosition_buff = 0x0080FD7C;
		
		_asm
		{
			FLD DWORD PTR DS:[HPPositionW]
			FSTP DWORD PTR SS:[EBP-0x20]
			FLD DWORD PTR DS:[HPPositionX]
			FSTP DWORD PTR SS:[EBP-0x0C]
			FLD DWORD PTR DS:[HPPositionH]
			FSTP DWORD PTR SS:[EBP-0x1C]
			FLD DWORD PTR DS:[HPPositionY]
			FSTP DWORD PTR SS:[EBP-0x8]
			jmp [HPPosition_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static float HPPositionW = 52.5f;
		static float HPPositionH = 51.0f;
		static float HPPositionX = 97.0f;
		static float HPPositionY = 428.5f;
		static DWORD HPPosition_buff = 0x0080FD7C;
		
		_asm
		{
			FLD DWORD PTR DS:[HPPositionW]
			FSTP DWORD PTR SS:[EBP-0x20]
			FLD DWORD PTR DS:[HPPositionX]
			FSTP DWORD PTR SS:[EBP-0x0C]
			FLD DWORD PTR DS:[HPPositionH]
			FSTP DWORD PTR SS:[EBP-0x1C]
			FLD DWORD PTR DS:[HPPositionY]
			FSTP DWORD PTR SS:[EBP-0x8]
			jmp [HPPosition_buff]
		}
	}
}

__declspec(naked) void DrawUsingSkillPosition()
{
	static float UsingSkillPositionX = 310.0f;
	static float UsingSkillPositionY = 447.0f;
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

__declspec(naked) void DrawSkillClickPosition()
{
	static float SkillClickPositionX = 310.0f;
	static float SkillClickPositionY = 445.0f;
	static float SkillClickPositionW = 25.0f;
	static float SkillClickPositionH = 32.0f;
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

__declspec(naked) void DrawSkillBarDrawPosition()
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

__declspec(naked) void DrawSkillSwitchDraw()
{
	static float SkillSwitchDrawX = 385.0f;
	static float SkillSwitchDrawY = 365.0f;
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

__declspec(naked) void DrawSkillSwitchClick()
{
	static float SkillSwitchDrawX = 385.0f;
	static float SkillSwitchDrawY = 365.0f;
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

__declspec(naked) void RavenSkillPos()
{
	static float SkillRavenDrawX = 290.0f;
	static float SkillRavenDrawY = 325.0f;
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

__declspec(naked) void RavenSkillClicPos()
{
	static float SkillRavenClicDrawX = 290.0f;
	static float SkillRavenClicDrawY = 325.0f;
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

__declspec(naked) void DrawQPosition1()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static float BarNumberY = 444.0f;
		static DWORD QPosition1_buff = 0x00895A4F;
		
		_asm
		{
			FLD DWORD PTR DS:[BarNumberY]
			FSTP DWORD PTR SS:[ESP]
			jmp [QPosition1_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static float BarNumberY = 465.0f;
		static DWORD QPosition1_buff = 0x00895A4F;
		
		_asm
		{
			FLD DWORD PTR DS:[BarNumberY]
			FSTP DWORD PTR SS:[ESP]
			jmp [QPosition1_buff]
		}
	}
}

__declspec(naked) void DrawQPosition2()
{
	static float QPosition2X = 226.0f;
	static DWORD QPosition2_buff = 0x00895A59;

	_asm
	{
		FLD DWORD PTR DS:[QPosition2X]
		FSTP DWORD PTR SS:[ESP]
		jmp [QPosition2_buff]
	}
}

__declspec(naked) void DrawQPosition3()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static float BarPotionY = 452.0f;
		static DWORD QPosition3_buff = 0x00895A63;

		_asm
		{
			FLD DWORD PTR DS:[BarPotionY]
			FSTP DWORD PTR SS:[ESP]
			jmp [QPosition3_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static float BarPotionY = 453.0f;
		static DWORD QPosition3_buff = 0x00895A63;

		_asm
		{
			FLD DWORD PTR DS:[BarPotionY]
			FSTP DWORD PTR SS:[ESP]
			jmp [QPosition3_buff]
		}
	}
}

__declspec(naked) void DrawQPosition4()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static float QPosition4X = 208.0f;
		static DWORD QPosition4_buff = 0x00895A6D;
	
		_asm
		{
			FLD DWORD PTR DS:[QPosition4X]
			FSTP DWORD PTR SS:[ESP]
			jmp [QPosition4_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static float QPosition4X = 210.0f;
		static DWORD QPosition4_buff = 0x00895A6D;
	
		_asm
		{
			FLD DWORD PTR DS:[QPosition4X]
			FSTP DWORD PTR SS:[ESP]
			jmp [QPosition4_buff]
		}
	}
}

__declspec(naked) void DrawWPosition1()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static float BarNumberY = 444.0f;
		static DWORD WPosition1_buff = 0x00895AC4;
		
		_asm
		{
			FLD DWORD PTR DS:[BarNumberY]
			FSTP DWORD PTR SS:[ESP]
			jmp [WPosition1_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static float BarNumberY = 465.0f;
		static DWORD WPosition1_buff = 0x00895AC4;
		
		_asm
		{
			FLD DWORD PTR DS:[BarNumberY]
			FSTP DWORD PTR SS:[ESP]
			jmp [WPosition1_buff]
		}
	}
}

__declspec(naked) void DrawWPosition2()
{
	static float WPosition2X = 256.0f;
	static DWORD WPosition2_buff = 0x00895ACE;
	
	_asm
	{
		FLD DWORD PTR DS:[WPosition2X]
		FSTP DWORD PTR SS:[ESP]
		jmp [WPosition2_buff]
	}
}

__declspec(naked) void DrawWPosition3()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static float BarPotionY = 452.0f;
		static DWORD WPosition3_buff = 0x00895AD8;

		_asm
		{
			FLD DWORD PTR DS:[BarPotionY]
			FSTP DWORD PTR SS:[ESP]
			jmp [WPosition3_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static float BarPotionY = 453.0f;
		static DWORD WPosition3_buff = 0x00895AD8;

		_asm
		{
			FLD DWORD PTR DS:[BarPotionY]
			FSTP DWORD PTR SS:[ESP]
			jmp [WPosition3_buff]
		}
	}
}

__declspec(naked) void DrawWPosition4()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static float WPosition4X = 239.0f;
		static DWORD WPosition4_buff = 0x00895AE2;
	
		_asm
		{
			FLD DWORD PTR DS:[WPosition4X]
			FSTP DWORD PTR SS:[ESP]
			jmp [WPosition4_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static float WPosition4X = 240.0f;
		static DWORD WPosition4_buff = 0x00895AE2;
	
		_asm
		{
			FLD DWORD PTR DS:[WPosition4X]
			FSTP DWORD PTR SS:[ESP]
			jmp [WPosition4_buff]
		}
	}
}

__declspec(naked) void DrawEPosition1()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static float BarNumberY = 444.0f;
		static DWORD EPosition1_buff = 0x00895B39;
		
		_asm
		{
			FLD DWORD PTR DS:[BarNumberY]
			FSTP DWORD PTR SS:[ESP]
			jmp [EPosition1_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static float BarNumberY = 465.0f;
		static DWORD EPosition1_buff = 0x00895B39;
		
		_asm
		{
			FLD DWORD PTR DS:[BarNumberY]
			FSTP DWORD PTR SS:[ESP]
			jmp [EPosition1_buff]
		}
	}
}

__declspec(naked) void DrawEPosition2()
{
	static float EPosition2X = 287.0f;
	static DWORD EPosition2_buff = 0x00895B43;
	
	_asm
	{
		FLD DWORD PTR DS:[EPosition2X]
		FSTP DWORD PTR SS:[ESP]
		jmp [EPosition2_buff]
	}
}

__declspec(naked) void DrawEPosition3()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static float BarPotionY = 452.0f;
		static DWORD EPosition3_buff = 0x00895B4D;
	
		_asm
		{
			FLD DWORD PTR DS:[BarPotionY]
			FSTP DWORD PTR SS:[ESP]
			jmp [EPosition3_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static float BarPotionY = 453.0f;
		static DWORD EPosition3_buff = 0x00895B4D;
	
		_asm
		{
			FLD DWORD PTR DS:[BarPotionY]
			FSTP DWORD PTR SS:[ESP]
			jmp [EPosition3_buff]
		}
	}
}

__declspec(naked) void DrawEPosition4()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static float EPosition4X = 269.0f;
		static DWORD EPosition4_buff = 0x00895B57;
	
		_asm
		{
			FLD DWORD PTR DS:[EPosition4X]
			FSTP DWORD PTR SS:[ESP]
			jmp [EPosition4_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static float EPosition4X = 270.0f;
		static DWORD EPosition4_buff = 0x00895B57;
	
		_asm
		{
			FLD DWORD PTR DS:[EPosition4X]
			FSTP DWORD PTR SS:[ESP]
			jmp [EPosition4_buff]
		}
	}
}

__declspec(naked) void DrawNopRShortKey()
{
	static DWORD RButtonAddress = 0x00895C0C;
	
	_asm
	{
		jmp RButtonAddress
	}
}

__declspec(naked) void DrawHPNumberPosition()
{
	gInterface.DrawCoord();

	static float HPNumberPositionX = 45.0f;
	static DWORD HPNumberPosition_buff = 0x0080FF1E;
	
	_asm
	{
		FADD DWORD PTR DS:[HPNumberPositionX]
		FSTP DWORD PTR SS:[EBP-0x19C]
		FLD DWORD PTR SS:[EBP-0x19C]
		jmp [HPNumberPosition_buff]
	}
}

__declspec(naked) void DrawMasterButton()
{
	static DWORD MasterButtonAddress1 = 0x0077ED20;
	
	_asm
	{
		jmp [MasterButtonAddress1]
	}
}

__declspec(naked) void DrawHelperAll()
{
	static DWORD HelperStopAddress1 = 0x007D28B4;
	_asm
	{
		jmp [HelperStopAddress1]
	}
}

__declspec(naked) void DrawEXP1()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static double Ancho = 221.0f;
		static double Alto = 435.0f;
		static double AnchoTex = 198.0f;
		static double AltoTex = 5.8f;
		static DWORD EXP1_buff = 0x00811408;
	
		_asm
		{
			FLD QWORD PTR DS:[Ancho]
			FSTP QWORD PTR SS:[EBP-0x10]
			FLD QWORD PTR DS:[Alto]
			FSTP QWORD PTR SS:[EBP-0x8]
			FLD DWORD PTR SS:[EBP-0x1B0]
			FMUL QWORD PTR DS:[AnchoTex]
			FSTP QWORD PTR SS:[EBP-0x28]
			FLD QWORD PTR DS:[AltoTex]
			FSTP QWORD PTR SS:[EBP-0x20]
			jmp [EXP1_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static double Ancho = 221.0f;
		static double Alto = 435.5f;
		static double AnchoTex = 198.0f;
		static double AltoTex = 5.8f;
		static DWORD EXP1_buff = 0x00811408;
	
		_asm
		{
			FLD QWORD PTR DS:[Ancho]
			FSTP QWORD PTR SS:[EBP-0x10]
			FLD QWORD PTR DS:[Alto]
			FSTP QWORD PTR SS:[EBP-0x8]
			FLD DWORD PTR SS:[EBP-0x1B0]
			FMUL QWORD PTR DS:[AnchoTex]
			FSTP QWORD PTR SS:[EBP-0x28]
			FLD QWORD PTR DS:[AltoTex]
			FSTP QWORD PTR SS:[EBP-0x20]
			jmp [EXP1_buff]
		}
	}

}

__declspec(naked) void DrawEXP2()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static double Ancho = 221.0f;
		static double Alto = 435.0f;
		static double AnchoTex = 198.0f;
		static double AltoTex = 5.8f;
		static DWORD EXP2_buff = 0x00811552;
	
		_asm
		{
			FLD QWORD PTR DS:[Ancho]
			FSTP QWORD PTR SS:[EBP-0x10]
			FLD QWORD PTR DS:[Alto]
			FSTP QWORD PTR SS:[EBP-0x8]
			FLD DWORD PTR SS:[EBP-0x1C4]
			FMUL QWORD PTR DS:[AnchoTex]
			FSTP QWORD PTR SS:[EBP-0x28]
			FLD QWORD PTR DS:[AltoTex]
			FSTP QWORD PTR SS:[EBP-0x20]
			jmp [EXP2_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static double Ancho = 221.0f;
		static double Alto = 435.5f;
		static double AnchoTex = 198.0f;
		static double AltoTex = 5.8f;
		static DWORD EXP2_buff = 0x00811552;
	
		_asm
		{
			FLD QWORD PTR DS:[Ancho]
			FSTP QWORD PTR SS:[EBP-0x10]
			FLD QWORD PTR DS:[Alto]
			FSTP QWORD PTR SS:[EBP-0x8]
			FLD DWORD PTR SS:[EBP-0x1C4]
			FMUL QWORD PTR DS:[AnchoTex]
			FSTP QWORD PTR SS:[EBP-0x28]
			FLD QWORD PTR DS:[AltoTex]
			FSTP QWORD PTR SS:[EBP-0x20]
			jmp [EXP2_buff]
		}
	}
}

__declspec(naked) void DrawEXP3()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static double Ancho = 221.0f;
		static double Alto = 435.0f;
		static double AnchoTex = 198.0f;
		static double AltoTex = 5.8f;
		static DWORD EXP3_buff = 0x00811719;
	
		_asm
		{
			FLD QWORD PTR DS:[Ancho]
			FSTP QWORD PTR SS:[EBP-0x10]
			FLD QWORD PTR DS:[Alto]
			FSTP QWORD PTR SS:[EBP-0x8]
			FLD DWORD PTR SS:[EBP-0x1B0]
			FMUL QWORD PTR DS:[AnchoTex]
			FSTP QWORD PTR SS:[EBP-0x28]
			FLD QWORD PTR DS:[AltoTex]
			FSTP QWORD PTR SS:[EBP-0x20]
			jmp [EXP3_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static double Ancho = 221.0f;
		static double Alto = 435.5f;
		static double AnchoTex = 198.0f;
		static double AltoTex = 5.8f;
		static DWORD EXP3_buff = 0x00811719;
	
		_asm
		{
			FLD QWORD PTR DS:[Ancho]
			FSTP QWORD PTR SS:[EBP-0x10]
			FLD QWORD PTR DS:[Alto]
			FSTP QWORD PTR SS:[EBP-0x8]
			FLD DWORD PTR SS:[EBP-0x1B0]
			FMUL QWORD PTR DS:[AnchoTex]
			FSTP QWORD PTR SS:[EBP-0x28]
			FLD QWORD PTR DS:[AltoTex]
			FSTP QWORD PTR SS:[EBP-0x20]
			jmp [EXP3_buff]
		}
	}
}

__declspec(naked) void DrawEXP4()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static double Ancho = 221.0f;
		static double Alto = 435.0f;
		static double AnchoTex = 198.0f;
		static double AltoTex = 5.8f;
		static DWORD EXP4_buff = 0x0081181F;
	
		_asm
		{
			FLD QWORD PTR DS:[Ancho]
			FSTP QWORD PTR SS:[EBP-0x10]
			FLD QWORD PTR DS:[Alto]
			FSTP QWORD PTR SS:[EBP-0x8]
			FLD QWORD PTR DS:[AnchoTex]
			FSTP QWORD PTR SS:[EBP-0x28]
			FLD QWORD PTR DS:[AltoTex]
			FSTP QWORD PTR SS:[EBP-0x20]
			FLD QWORD PTR SS:[EBP-0x20]
			jmp [EXP4_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static double Ancho = 221.0f;
		static double Alto = 435.5f;
		static double AnchoTex = 198.0f;
		static double AltoTex = 5.8f;
		static DWORD EXP4_buff = 0x0081181F;
	
		_asm
		{
			FLD QWORD PTR DS:[Ancho]
			FSTP QWORD PTR SS:[EBP-0x10]
			FLD QWORD PTR DS:[Alto]
			FSTP QWORD PTR SS:[EBP-0x8]
			FLD QWORD PTR DS:[AnchoTex]
			FSTP QWORD PTR SS:[EBP-0x28]
			FLD QWORD PTR DS:[AltoTex]
			FSTP QWORD PTR SS:[EBP-0x20]
			FLD QWORD PTR SS:[EBP-0x20]
			jmp [EXP4_buff]
		}
	}
}

__declspec(naked) void DrawEXPMASTER1()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static double Ancho = 221.0f;
		static double Alto = 435.0f;
		static double AltoTex = 5.8f;
		static double AnchoTex = 198.0f;
		static DWORD EXPMASTER1_buff = 0x00810B6E;
	
		_asm
		{
			FLD QWORD PTR DS:[Ancho]
			FSTP QWORD PTR SS:[EBP-0x10]
			FLD QWORD PTR DS:[Alto]
			FSTP QWORD PTR SS:[EBP-0x8]
			FLD QWORD PTR SS:[EBP-0x58]
			FMUL QWORD PTR DS:[AnchoTex]
			FSTP QWORD PTR SS:[EBP-0x28]
			FLD QWORD PTR DS:[AltoTex]
			FSTP QWORD PTR SS:[EBP-0x20]
			jmp [EXPMASTER1_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static double Ancho = 221.0f;
		static double Alto = 435.5f;
		static double AltoTex = 5.8f;
		static double AnchoTex = 198.0f;
		static DWORD EXPMASTER1_buff = 0x00810B6E;
	
		_asm
		{
			FLD QWORD PTR DS:[Ancho]
			FSTP QWORD PTR SS:[EBP-0x10]
			FLD QWORD PTR DS:[Alto]
			FSTP QWORD PTR SS:[EBP-0x8]
			FLD QWORD PTR SS:[EBP-0x58]
			FMUL QWORD PTR DS:[AnchoTex]
			FSTP QWORD PTR SS:[EBP-0x28]
			FLD QWORD PTR DS:[AltoTex]
			FSTP QWORD PTR SS:[EBP-0x20]
			jmp [EXPMASTER1_buff]
		}
	}
}

__declspec(naked) void DrawEXPMASTER2()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static double Ancho = 221.0f;
		static double Alto = 435.0f;
		static double AnchoTex = 198.0f;
		static double AltoTex = 5.8f;
		static DWORD EXPMASTER2_buff = 0x00810CB5;
	
		_asm
		{
			FLD QWORD PTR DS:[Ancho]
			FSTP QWORD PTR SS:[EBP-0x10]
			FLD QWORD PTR DS:[Alto]
			FSTP QWORD PTR SS:[EBP-0x8]
			FLD QWORD PTR SS:[EBP-0x88]
			FMUL QWORD PTR DS:[AnchoTex]
			FSTP QWORD PTR SS:[EBP-0x28]
			FLD QWORD PTR DS:[AltoTex]
			FSTP QWORD PTR SS:[EBP-0x20]
			jmp [EXPMASTER2_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static double Ancho = 221.0f;
		static double Alto = 435.5f;
		static double AnchoTex = 198.0f;
		static double AltoTex = 5.8f;
		static DWORD EXPMASTER2_buff = 0x00810CB5;
	
		_asm
		{
			FLD QWORD PTR DS:[Ancho]
			FSTP QWORD PTR SS:[EBP-0x10]
			FLD QWORD PTR DS:[Alto]
			FSTP QWORD PTR SS:[EBP-0x8]
			FLD QWORD PTR SS:[EBP-0x88]
			FMUL QWORD PTR DS:[AnchoTex]
			FSTP QWORD PTR SS:[EBP-0x28]
			FLD QWORD PTR DS:[AltoTex]
			FSTP QWORD PTR SS:[EBP-0x20]
			jmp [EXPMASTER2_buff]
		}
	}
}

__declspec(naked) void DrawEXPMASTER3()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static double Ancho = 221.0f;
		static double Alto = 435.0f;
		static double AnchoTex = 198.0f;
		static double AltoTex = 5.8f;
		static DWORD EXPMASTER3_buff = 0x00810E79;
	
		_asm
		{
			FLD QWORD PTR DS:[Ancho]
			FSTP QWORD PTR SS:[EBP-0x10]
			FLD QWORD PTR DS:[Alto]
			FSTP QWORD PTR SS:[EBP-0x8]
			FLD QWORD PTR SS:[EBP-0x58]
			FMUL QWORD PTR DS:[AnchoTex]
			FSTP QWORD PTR SS:[EBP-0x28]
			FLD QWORD PTR DS:[AltoTex]
			FSTP QWORD PTR SS:[EBP-0x20]
			jmp [EXPMASTER3_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static double Ancho = 221.0f;
		static double Alto = 435.5f;
		static double AnchoTex = 198.0f;
		static double AltoTex = 5.8f;
		static DWORD EXPMASTER3_buff = 0x00810E79;
	
		_asm
		{
			FLD QWORD PTR DS:[Ancho]
			FSTP QWORD PTR SS:[EBP-0x10]
			FLD QWORD PTR DS:[Alto]
			FSTP QWORD PTR SS:[EBP-0x8]
			FLD QWORD PTR SS:[EBP-0x58]
			FMUL QWORD PTR DS:[AnchoTex]
			FSTP QWORD PTR SS:[EBP-0x28]
			FLD QWORD PTR DS:[AltoTex]
			FSTP QWORD PTR SS:[EBP-0x20]
			jmp [EXPMASTER3_buff]
		}
	}
}

__declspec(naked) void DrawEXPMASTER4()
{
	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		static double Ancho = 221.0f;
		static double Alto = 435.0f;
		static double AnchoTex = 198.0f;
		static double AltoTex = 5.8f;
		static DWORD EXPMASTER4_buff = 0x00810F73;

		_asm
		{
			FLD QWORD PTR DS:[Ancho]
			FSTP QWORD PTR SS:[EBP-0x10]
			FLD QWORD PTR DS:[Alto]
			FSTP QWORD PTR SS:[EBP-0x8]
			FLD QWORD PTR DS:[AnchoTex]
			FSTP QWORD PTR SS:[EBP-0x28]
			FLD QWORD PTR DS:[AltoTex]
			FSTP QWORD PTR SS:[EBP-0x20]
			jmp [EXPMASTER4_buff]
		}
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		static double Ancho = 221.0f;
		static double Alto = 435.5f;
		static double AnchoTex = 198.0f;
		static double AltoTex = 5.8f;
		static DWORD EXPMASTER4_buff = 0x00810F73;

		_asm
		{
			FLD QWORD PTR DS:[Ancho]
			FSTP QWORD PTR SS:[EBP-0x10]
			FLD QWORD PTR DS:[Alto]
			FSTP QWORD PTR SS:[EBP-0x8]
			FLD QWORD PTR DS:[AnchoTex]
			FSTP QWORD PTR SS:[EBP-0x28]
			FLD QWORD PTR DS:[AltoTex]
			FSTP QWORD PTR SS:[EBP-0x20]
			jmp [EXPMASTER4_buff]
		}
	}

}

int CClassicUICharacterInfoWindow(int a1)
{
	int v42; // ST24_4@1
	float green; // ST08_4@1
	float red; // ST04_4@1
	
	v42 = a1;
	green = (double)*(signed int *)(a1 + 20);
	red =   (double)*(signed int *)(a1 + 16);
	pDrawGUI(31352, red, green, 190.0, 433.0);
	
	int DL = pGetCharClass(*(BYTE *)(oUserPreviewStruct + 19));
	
	if (DL == 4)
	{
		green = (double)*(signed int *)(a1 + 20);
		red = (double)*(signed int *)(a1 + 16);
		pDrawGUI(51291, red, green, 190.0, 433.0);
	}
	
	int Class = pGetCharClass(*(BYTE *)(oUserPreviewStruct + 19));
	
	if (Class == 3 || Class == 5 || Class == 6)
	{
		green = (double)*(signed int *)(a1 + 20);
		red = (double)*(signed int *)(a1 + 16);
		pDrawGUI(51292, red, green, 190.0, 433.0);
	}
	
	return a1;
}

__declspec(naked) void DrawInterfaceS2DisableR()
{
	static DWORD RButtonAddress = 0x00895C0C;
	
	_asm
	{
		jmp RButtonAddress
	}
}

__declspec(naked) void ToolTipSkill()
{
	static DWORD SkillRavenClicDraw_buff = 0x00813C25;

	_asm
	{
		PUSH ECX
			MOV EDX,DWORD PTR SS:[EBP-0x04]
		MOV EAX,DWORD PTR DS:[EDX+0x4C]
		SUB EAX,0x1B
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP-0x04]
		MOV EDX,DWORD PTR DS:[ECX+0x48]
		ADD EDX,0x0F
			jmp [SkillRavenClicDraw_buff]
	}
}

//- Fix Guild War Score + Custom Interface
_declspec(naked) void GuildWarPosition()
{
	static DWORD ReturnAdress = 0x00777026;	
	_asm
	{
		ADD ECX,-230 //POS X
		MOV DWORD PTR SS:[EBP-0x4],ECX
		MOV EDX,DWORD PTR SS:[EBP-0x90]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX,-354 //POS Y
		MOV DWORD PTR SS:[EBP-0x8C],EAX
		MOV ECX,DWORD PTR DS:[0xE8C58C]
		JMP [ReturnAdress]
	}
}


DWORD SlotOccupied = -1; //-> Define check variable

__declspec(naked) void ShadowColorCheck()
{
	static DWORD jmpBack = 0x007DB30F;

	__asm
	{
		mov eax, [ebp - 0x1C]
		movzx ecx, byte ptr[eax + 0x60]
		mov SlotOccupied, ecx
		jmp [jmpBack]
	}
}

void ShadowColorChange(DWORD a, float b, float c, float d, float e)
{
	switch (SlotOccupied)
	{
	case 0:
		((void(__cdecl*)(int ImageID, float PosX, float PosY, float Width, float Height, int Arg6, float Arg7, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, bool ScaleAlpha)) 0x637C60)(0x7960, b, c, d, e, 0, 0, 1.0f, 1.0f, 1, 1, 0);
		break;
	case 1:
		((void(__cdecl*)(DWORD, float, float, float, float, float, float, DWORD)) 0x00790F20)(0x7960, b, c, d, e, 1.0f, 1.0f, Color4f(255, 255, 0, 102));
		break;
	case 2:
		((void(__cdecl*)(DWORD, float, float, float, float, float, float, DWORD)) 0x00790F20)(0x7960, b, c, d, e, 1.0f, 1.0f, Color4f(255, 168, 0, 102));
		break;
	case 3:
		((void(__cdecl*)(DWORD, float, float, float, float, float, float, DWORD)) 0x00790F20)(0x7960, b, c, d, e, 1.0f, 1.0f, Color4f(255, 84, 0, 102));
		break;
	case 4:
		((void(__cdecl*)(DWORD, float, float, float, float, float, float, DWORD)) 0x00790F20)(0x7960, b, c, d, e, 1.0f, 1.0f, Color4f(255, 0, 0, 102));
		break;
	case 5:
		((void(__cdecl*)(DWORD, float, float, float, float, float, float, DWORD)) 0x00790F20)(0x7960, b, c, d, e, 1.0f, 1.0f, Color4f(255, 51, 0, 102));
		break;
	default:
		((void(__cdecl*)(int ImageID, float PosX, float PosY, float Width, float Height, int Arg6, float Arg7, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, bool ScaleAlpha)) 0x637C60)(0x795F, b, c, d, e, 0, 0, 1.0f, 1.0f, 1, 1, 0);
		break;
	}

	SlotOccupied = -1;
}

void InitInter3()
{
	//- Shadow of items in the inventory
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		SetCompleteHook(0xE9, 0x007DB308, &ShadowColorCheck); //Get Slot Type
		SetCompleteHook(0xE8, 0x007DB5D0, &ShadowColorChange); //Draw Inventory Box
	}

	//-> Fix Guild War Score + Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		SetCompleteHook(0xE9, 0x00777008, &GuildWarPosition);
		MemorySet(0x00776FE4,0x90,0x5);
	}

	

	//- Remove Inventory Border (S1/S2)
	/*if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		MemorySet(0x007DB7B0, 0x90, 0x05);
		MemorySet(0x007DB812, 0x90, 0x05);
		MemorySet(0x007DB874, 0x90, 0x05);
		MemorySet(0x007DB8E0, 0x90, 0x05);
		MemorySet(0x007DB959, 0x90, 0x05);
		MemorySet(0x007DB9A2, 0x90, 0x05);
		MemorySet(0x007DBA20, 0x90, 0x05);
		MemorySet(0x007DBA69, 0x90, 0x05); 
	}*/

	SetDword(0x004D9746 + 3,480); //-> Disable Background
	//-
	SetCompleteHook(0xE9,0x00813C11,&ToolTipSkill);
	//-
	MemorySet(0x00895B8D,0x90,0x7E); //-> Disable (R) Key Function
	SetCompleteHook(0xE9,0x00895B8D,&DrawInterfaceS2DisableR);
	//-
	SetRange((LPVOID)0x0080F270, 0x4D1, ASM::NOP); //-> Interface -> Draw Button
	//-
	SetByte((PVOID)(0x008137AF + 3), 0);
	SetByte((PVOID)(0x008119A7), 0xEB);
	SetRange((LPVOID)0x00811AC0, 0xAC, ASM::NOP);
	//-
	SetRange((LPVOID)0x0081028C, 0x24, ASM::NOP);
	SetOp((LPVOID)0x0081028C, (LPVOID)DrawAGPosition, ASM::JMP);
	//-
	SetRange((LPVOID)0x0080FFAF, 0x24, ASM::NOP);
	SetOp((LPVOID)0x0080FFAF, (LPVOID)DrawMANAPosition, ASM::JMP);
	//-
	SetRange((LPVOID)0x0080FD5B, 0x24, ASM::NOP);
	SetOp((LPVOID)0x0080FD5B, (LPVOID)DrawHPPosition, ASM::JMP);
	//-
	SetRange((LPVOID)0x008138DF, 0x24, ASM::NOP);
	SetOp((LPVOID)0x008138DF, (LPVOID)DrawUsingSkillPosition, ASM::JMP);
	//-
	SetRange((LPVOID)0x00812713, 0x24, ASM::NOP);
	SetOp((LPVOID)0x00812713, (LPVOID)DrawSkillClickPosition, ASM::JMP);
	//-
	SetRange((LPVOID)0x00812947, 0x24, ASM::NOP);
	SetOp((LPVOID)0x00812947, (LPVOID)DrawSkillBarDrawPosition, ASM::JMP);
	//-
	SetRange((LPVOID)0x008139A0, 0x2D, ASM::NOP);
	SetOp((LPVOID)0x008139A0, (LPVOID)DrawSkillSwitchDraw, ASM::JMP);
	//-
	SetRange((LPVOID)0x00812D3F, 0x2D, ASM::NOP);
	SetOp((LPVOID)0x00812D3F, (LPVOID)DrawSkillSwitchClick, ASM::JMP);
	//-
	SetRange((LPVOID)0x00813CBC,0x6,ASM::NOP);
	SetJg((LPVOID)0x00813CBC,RavenSkillPos);
	//-
	SetRange((LPVOID)0x008130AA,0x6,ASM::NOP);
	SetJg((LPVOID)0x008130AA,RavenSkillClicPos);
	//--
	SetRange((LPVOID)0x0080FF12, 0x12, ASM::NOP);
	SetOp((LPVOID)0x0080FF12, (LPVOID)DrawHPNumberPosition, ASM::JMP);
	//-
	SetRange((LPVOID)0x0077EC97, 0x88, ASM::NOP);
	SetOp((LPVOID)0x0077EC97, (LPVOID)DrawMasterButton, ASM::JMP);
	//-
	//-> Q
	SetRange((LPVOID)0x00895A49, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895A49, (LPVOID)DrawQPosition1, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895A53, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895A53, (LPVOID)DrawQPosition2, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895A5D, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895A5D, (LPVOID)DrawQPosition3, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895A67, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895A67, (LPVOID)DrawQPosition4, ASM::JMP);
	//-> W
	SetRange((LPVOID)0x00895ABE, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895ABE, (LPVOID)DrawWPosition1, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895AC8, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895AC8, (LPVOID)DrawWPosition2, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895AD2, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895AD2, (LPVOID)DrawWPosition3, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895ADC, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895ADC, (LPVOID)DrawWPosition4, ASM::JMP);
	//-> E
	SetRange((LPVOID)0x00895B33, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895B33, (LPVOID)DrawEPosition1, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895B3D, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895B3D, (LPVOID)DrawEPosition2, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895B47, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895B47, (LPVOID)DrawEPosition3, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895B51, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895B51, (LPVOID)DrawEPosition4, ASM::JMP);
	
	//EXP
	SetRange((LPVOID)0x008113DE, 5, ASM::NOP);
	SetOp((LPVOID)0x008113DE, (LPVOID)DrawEXP1, ASM::JMP);
	SetRange((LPVOID)0x00811528, 5, ASM::NOP);
	SetOp((LPVOID)0x00811528, (LPVOID)DrawEXP2, ASM::JMP);
	SetRange((LPVOID)0x008116EF, 5, ASM::NOP);
	SetOp((LPVOID)0x008116EF, (LPVOID)DrawEXP3, ASM::JMP);
	SetRange((LPVOID)0x008117F8, 5, ASM::NOP);
	SetOp((LPVOID)0x008117F8, (LPVOID)DrawEXP4, ASM::JMP);
	
	//EXP MASTER
	SetRange((LPVOID)0x00810B47, 5, ASM::NOP);
	SetOp((LPVOID)0x00810B47, (LPVOID)DrawEXPMASTER1, ASM::JMP);
	SetRange((LPVOID)0x00810C8B, 5, ASM::NOP);
	SetOp((LPVOID)0x00810C8B, (LPVOID)DrawEXPMASTER2, ASM::JMP);
	SetRange((LPVOID)0x00810E52, 5, ASM::NOP);
	SetOp((LPVOID)0x00810E52, (LPVOID)DrawEXPMASTER3, ASM::JMP);
	SetRange((LPVOID)0x00810F4F, 5, ASM::NOP);
	SetOp((LPVOID)0x00810F4F, (LPVOID)DrawEXPMASTER4, ASM::JMP);
	SetRange((LPVOID)0x00810B7F, 5, ASM::NOP);
	//-
	SetDouble(0x00D461C8, 198);		//-> Experience Bar Max Size

	//-> Custom Interface (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		SetDouble(0x00D461C0, 425);		//-> Exp Number Position X
		SetDouble(0x00D461B8, 431.5);	//-> Exp Number Position Y
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		SetDouble(0x00D461C0, 425);		//-> Exp Number Position X
		SetDouble(0x00D461B8, 432);		//-> Exp Number Position Y
	}

	//-> Custom Interface (S2/S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		SetRange((LPVOID)0x0081055C, 0x24, ASM::NOP);
		SetOp((LPVOID)0x0081055C, (LPVOID)DrawSDPosition, ASM::JMP);
	}

	if (gProtect.m_MainInfo.CustomInterfaceType == 1)
	{
		SetRange((LPVOID)0x0081057D, 0x24, ASM::NOP); //-> Remove SD
	}

	//-> Character UI Stats (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		SetCompleteHook(0xE8, 0x0077F7EE, &CClassicUICharacterInfoWindow);
		SetDword((PVOID)(0x0077E935 + 1), 51290);
		SetByte((PVOID)(0x0077E94A + 1), 24);
		SetByte((PVOID)(0x0077E94C + 1), 24);
		SetByte((PVOID)(0x0077E957 + 2), 117);
		SetByte((PVOID)(0x0077E964 + 1), 130);
		SetDword((PVOID)(0x0077E97E + 1), 51290);
		SetByte((PVOID)(0x0077E996 + 1), 24);
		SetByte((PVOID)(0x0077E998 + 1), 24);
		SetByte((PVOID)(0x0077E9A3 + 2), 172);
		SetByte((PVOID)(0x0077E9B3 + 2), 130);
		SetDword((PVOID)(0x0077E9D1 + 1), 51290);
		SetByte((PVOID)(0x0077E9E9 + 1), 24);
		SetByte((PVOID)(0x0077E9EB + 1), 24);
		SetByte((PVOID)(0x0077E9F6 + 1), 237);
		SetByte((PVOID)(0x0077EA05 + 2), 130);
		SetDword((PVOID)(0x0077EA23 + 1), 51290);
		SetByte((PVOID)(0x0077EA3B + 1), 24);
		SetByte((PVOID)(0x0077EA3D + 1), 24);
		SetByte((PVOID)(0x0077EA48 + 2), 292);
		SetByte((PVOID)(0x0077EA58 + 1), 130);
		SetDword((PVOID)(0x0077EA75 + 1), 51290);
		SetByte((PVOID)(0x0077EA8D + 1), 24);
		SetByte((PVOID)(0x0077EA8F + 1), 24);
		SetByte((PVOID)(0x0077EA9A + 2), 347);
		SetByte((PVOID)(0x0077EAAA + 2), 130);
		SetByte((PVOID)(0x007801D9 + 1), 4);
		SetByte((PVOID)(0x007801DD + 1), 42);
		SetByte((PVOID)(0x00780217 + 1), 2);
		SetByte((PVOID)(0x0078023A + 2), 56);
		SetByte((PVOID)(0x0078190D + 1), 4);
		SetByte((PVOID)(0x00781911 + 1), 42);
		SetByte((PVOID)(0x0078194E + 1), 2);
		SetByte((PVOID)(0x00781973 + 2), 56);
		SetByte((PVOID)(0x007830EF + 1), 4);
		SetByte((PVOID)(0x007830F3 + 1), 42);
		SetByte((PVOID)(0x00783130 + 1), 2);
		SetByte((PVOID)(0x00783155 + 2), 56);
		SetByte((PVOID)(0x00782D15 + 1), 4);
		SetByte((PVOID)(0x00782D19 + 1), 42);
		SetByte((PVOID)(0x00782D56 + 1), 2);
		SetByte((PVOID)(0x00782D7C + 2), 56);
		SetByte((PVOID)(0x00782D15 + 1), 4);
		SetByte((PVOID)(0x00782D19 + 1), 42);
		SetByte((PVOID)(0x00782D56 + 1), 2);
		SetByte((PVOID)(0x00782D7C + 2), 56);
		SetByte((PVOID)(0x00784B6D + 1), 4);
		SetByte((PVOID)(0x00784B71 + 1), 42);
		SetByte((PVOID)(0x00784BAE + 1), 2);
		SetByte((PVOID)(0x00784BD4 + 2), 56);
	}

	//-> Custom Interface (S1)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1)
	{
		SetDword(0x0080F04A+1,(DWORD)"Custom\\Interface\\S1\\Exbar_Master.jpg");
		SetDword(0x008124FA+1,(DWORD)"Custom\\Interface\\S1\\newui_skill2.jpg");
		SetDword(0x0086D10C+1,(DWORD)"Custom\\Interface\\S1\\newui_skill2.jpg");
		SetDword(0x00888E7A+1,(DWORD)"Custom\\Interface\\S1\\newui_skill2.jpg");
		SetDword(0x0081259A+1,(DWORD)"Custom\\Interface\\S1\\newui_non_skill2.jpg");
		SetDword(0x0086D12C+1,(DWORD)"Custom\\Interface\\S1\\newui_non_skill2.jpg");
		SetDword(0x0080F02A+1,(DWORD)"Custom\\Interface\\S1\\newui_exbar.jpg");
	}

	//-> Custom Interface (S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		SetDword(0x0080F04A+1,(DWORD)"Custom\\Interface\\S2\\Exbar_Master.jpg");
		SetDword(0x008124FA+1,(DWORD)"Custom\\Interface\\S2\\newui_skill2.jpg");
		SetDword(0x0086D10C+1,(DWORD)"Custom\\Interface\\S2\\newui_skill2.jpg");
		SetDword(0x00888E7A+1,(DWORD)"Custom\\Interface\\S2\\newui_skill2.jpg");
		SetDword(0x0081259A+1,(DWORD)"Custom\\Interface\\S2\\newui_non_skill2.jpg");
		SetDword(0x0086D12C+1,(DWORD)"Custom\\Interface\\S2\\newui_non_skill2.jpg");
		SetDword(0x0080F02A+1,(DWORD)"Custom\\Interface\\S2\\newui_exbar.jpg");
	}

	//-> Custom Interface (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		SetDword(0x0080F04A+1,(DWORD)"Custom\\Interface\\S3\\Exbar_Master.jpg");
		SetDword(0x008124FA+1,(DWORD)"Custom\\Interface\\S3\\newui_skill2.jpg");
		SetDword(0x0086D10C+1,(DWORD)"Custom\\Interface\\S3\\newui_skill2.jpg");
		SetDword(0x00888E7A+1,(DWORD)"Custom\\Interface\\S3\\newui_skill2.jpg");
		SetDword(0x0081259A+1,(DWORD)"Custom\\Interface\\S3\\newui_non_skill2.jpg");
		SetDword(0x0086D12C+1,(DWORD)"Custom\\Interface\\S3\\newui_non_skill2.jpg");
		SetDword(0x0080F02A+1,(DWORD)"Custom\\Interface\\S3\\newui_exbar.jpg");
	}
	
	MemorySet(0x007A8330,0x90,0x198);		//-> MENU ESC TRANSPARENTE
	//-
	SetDword((PVOID)(0x007D0EF6+1),350);	//-> POSI플O Y GUILD MASTER BUTTONS PART1
	SetDword((PVOID)(0x007D0F5D+1),350);	//-> POSI플O Y GUILD MASTER BUTTONS PART1
	SetByte((PVOID)(0x007D0F05+2),43);		//-> POSI플O X GUILD MASTER BUTTONS PART1
	SetByte((PVOID)(0x007D0F6C+2),88);		//-> POSI플O X GUILD MASTER BUTTONS PART1
	SetDword((PVOID)(0x007D11DE+2),350);	//-> POSI플O Y GUILD MASTER BUTTONS PART2
	SetDword((PVOID)(0x007D1249+2),350);	//-> POSI플O Y GUILD MASTER BUTTONS PART2
	SetByte((PVOID)(0x007D11EE+2),43);		//-> POSI플O X GUILD MASTER BUTTONS PART2
	SetByte((PVOID)(0x007D1259+2),88);		//-> POSI플O X GUILD MASTER BUTTONS PART2

	//Textures (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		//newui_btn_empty.tga
		SetDword(0x0078EDDA+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty.tga");
		SetDword(0x007C2E7A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty.tga");
		SetDword(0x007C670A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty.tga");
		SetDword(0x007C672A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty.tga");
		SetDword(0x007C839A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty.tga");
		SetDword(0x007C83BA+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty.tga");
		SetDword(0x007D0A7A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty.tga");
		SetDword(0x00824FBA+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty.tga");
		SetDword(0x0084644A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty.tga");
		SetDword(0x0085101A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty.tga");
		SetDword(0x00852A2A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty.tga");
		SetDword(0x008804CA+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty.tga");
		SetDword(0x00882D0A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty.tga");
		//--
		//newui_btn_empty_big
		SetDword(0x00824FFA+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_big.tga");
		SetDword(0x0087518A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_big.tga");
		SetDword(0x00878CDA+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_big.tga");
		//--
		//newui_btn_empty_small
		SetDword(0x007C2E5A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_small.tga");
		SetDword(0x007CDE8A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_small.tga");
		SetDword(0x007D0A9A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_small.tga");
		SetDword(0x00824FDA+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_small.tga");
		SetDword(0x00854CEA+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_small.tga");
		//--
		//newui_btn_empty_small
		SetDword(0x007C177A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_very_small.tga");
		SetDword(0x0082501A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_very_small.tga");
		SetDword(0x00867F3A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_very_small.tga");
		SetDword(0x0086D0EC+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_very_small.tga");
		SetDword(0x0087694A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_very_small.tga");
		SetDword(0x00879BEA+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_very_small.tga");
		SetDword(0x0088116A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_very_small.tga");
		SetDword(0x0088428A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_very_small.tga");
		SetDword(0x0089300A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_very_small.tga");
		SetDword(0x0089413A+1,(DWORD)"Custom\\Interface\\S2\\newui_btn_empty_very_small.tga");
		//--
		//newui_Bt_money01
		SetDword(0x00857EBA+1,(DWORD)"Custom\\Interface\\S2\\newui_Bt_money01.tga");
		SetDword(0x008651EA+1,(DWORD)"Custom\\Interface\\S2\\newui_Bt_money01.tga");
		//--
		//newui_Bt_money02
		SetDword(0x00857EDA+1,(DWORD)"Custom\\Interface\\S2\\newui_Bt_money02.tga");
		//--
		//newui_Bt_lock
		SetDword(0x00857F1A+1,(DWORD)"Custom\\Interface\\S2\\newui_Bt_lock.tga");
		//--
		//newui_Bt_lock
		SetDword(0x00857EFA+1,(DWORD)"Custom\\Interface\\S2\\newui_Bt_lock02.tga");
		//--
		//newui_repair_00
		SetDword(0x00836D1A+1,(DWORD)"Custom\\Interface\\S2\\newui_repair_00.tga");
		SetDword(0x0084753A+1,(DWORD)"Custom\\Interface\\S2\\newui_repair_00.tga");
		//--
		//newui_expansion_btn
		SetDword(0x00836D3A+1,(DWORD)"Custom\\Interface\\S2\\newui_expansion_btn.tga");
		//--
		//Quest_Bt_open
		SetDword(0x0083E8BA+1,(DWORD)"Custom\\Interface\\S2\\Quest_Bt_open.tga");
		//--
		//Quest_Bt_cast
		SetDword(0x0083E8DA+1,(DWORD)"Custom\\Interface\\S2\\Quest_Bt_cast.tga");
		//--
		//newui_chainfo_btn_quest
		SetDword(0x00784F0A+1,(DWORD)"Custom\\Interface\\S2\\newui_chainfo_btn_quest.tga");
		
		//newui_chainfo_btn_pet
		SetDword(0x00784F2A+1,(DWORD)"Custom\\Interface\\S2\\newui_chainfo_btn_pet.tga");

		//newui_Box_openTitle
		SetDword(0x00840C6A+1,(DWORD)"Custom\\Interface\\S2\\newui_Box_openTitle.tga");
		SetDword(0x0084F11A+1,(DWORD)"Custom\\Interface\\S2\\newui_Box_openTitle.tga");
		//--	
		//newui_item_money
		SetDword(0x00836CDA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_money.tga");
		SetDword(0x008651AA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_money.tga");
		//--	
		//newui_item_money2
		SetDword(0x0084642A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_money2.tga");
		SetDword(0x0084755A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_money2.tga");
		SetDword(0x00879D0A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_money2.tga");
		//--	
		//newui_item_money3
		SetDword(0x00857F3A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_money3.tga");
		//--
		//newui_Bt_accept
		SetDword(0x0086524A+1,(DWORD)"Custom\\Interface\\S2\\newui_Bt_accept.tga");
		//--
		//newui_exit_00
		SetDword(0x00784EAA+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x0078EDBA+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x007C048A+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x007C674A+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x007C83DA+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x007CDE6A+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x007D0B3A+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x007D53FA+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x00836CFA+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x0083E87A+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x00840C4A+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x00843F2A+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x0084646A+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x0084B31A+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x0084E75A+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x0084F0FA+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x0085103A+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x00852A4A+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x008651CA+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x00867F7A+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x0087516A+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x00878CBA+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x00879B8A+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x008804AA+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x0088114A+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x00882CEA+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x0088424A+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		SetDword(0x00945FFA+1,(DWORD)"Custom\\Interface\\S2\\newui_exit_00.tga");
		//newui_item_back01
		SetDword(0x0078ED3A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x007C16FA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x007CDD0A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x007D0ABA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x00836ADA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x0083E7FA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x00840BCA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x0084B29A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x0084F07A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x0085666A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x00857E3A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x0086510A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x00867EBA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x008750EA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x00878C3A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x00879B0A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x0088042A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x008810CA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x00882C6A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x008841CA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x00892F8A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		SetDword(0x008940BA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back01.tga");
		//newui_item_back02-L
		SetDword(0x00784D4A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x0078ED5A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x007C171A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x007C2DFA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x007C66AA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x007C833A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x007CDD2A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x007D0ADA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x007D539A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x007EF286+3,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x0082C81A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x00836B1A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x0083E81A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x00840BEA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x00843E6A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x008463AA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x008474DA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x0084B2BA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x0084E6FA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x0084F09A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x00850F5A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x0085296A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x00854C8A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x0085668A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x00857E5A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x0086512A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x00867EDA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x0087510A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x00878C5A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x00879B2A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x0088044A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x008810EA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x00882C8A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x008841EA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x00892FAA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		SetDword(0x008940DA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-L.tga");
		//newui_item_back02-R
		SetDword(0x00784D6A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x0078ED7A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x007C173A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x007C2E1A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x007C66CA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x007C835A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x007CDD4A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x007D0AFA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x007D53BA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x007EF28D+3,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga"); 
		SetDword(0x0082C83A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x00836B3A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x0083E83A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x00840C0A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x00843E8A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x008463CA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x008474FA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x0084B2DA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x0084E71A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x0084F0BA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x00850F7A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x0085298A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x00854CAA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x008566AA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x00857E7A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x0086514A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x00867EFA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x0087512A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x00878C7A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x00879B4A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x0088046A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x0088110A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x00882CAA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x0088420A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x00892FCA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		SetDword(0x008940FA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back02-R.tga");
		//newui_item_back03
		SetDword(0x00784D8A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0078ED9A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x007C175A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x007C2E3A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x007C66EA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x007C837A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x007CDD6A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x007D0B1A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x007D53DA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x007EF294+3,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0082C85A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x00836B5A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x00836B5A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x00840C2A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x00843EAA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x008463EA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0084751A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0084928A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0084B2FA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0084E73A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0084F0DA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x00850F9A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x008529AA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x00854CCA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x008566CA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x00857E9A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0086516A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x00867F1A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0087514A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x00878C9A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x00879B6A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0088048A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0088112A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x00882CCA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0088422A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x00892FEA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0089411A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0094844A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0094BAEA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0094C57A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0094FB7A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0095129A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		SetDword(0x0095203A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back03.tga");
		//newui_item_back04
		SetDword(0x00784D2A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back04.tga");
		SetDword(0x007C2DDA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back04.tga");
		SetDword(0x007C668A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back04.tga");
		SetDword(0x007C831A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back04.tga");
		SetDword(0x007D537A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back04.tga");
		SetDword(0x007EF286+3,(DWORD)"Custom\\Interface\\S2\\newui_item_back04.tga"); 
		SetDword(0x0082C7FA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back04.tga");
		SetDword(0x00836AFA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back04.tga");
		SetDword(0x00843E4A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back04.tga");
		SetDword(0x0084638A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back04.tga");
		SetDword(0x008474BA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back04.tga");
		SetDword(0x0084E6DA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back04.tga");
		SetDword(0x00850F3A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back04.tga");
		SetDword(0x0085294A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back04.tga");
		SetDword(0x00854C6A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_back04.tga");
		//newui_item_box
		SetDword(0x007D991A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_box.tga");
		//newui_item_boots
		SetDword(0x00836B7A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_boots.tga");
		//newui_item_cap
		SetDword(0x00836B9A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_cap.tga");
		//newui_item_fairy
		SetDword(0x00836BBA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_fairy.tga");
	
		//newui_msgbox_back
		SetDword(0x00784D0A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0078ED1A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x007C16DA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x007C2DBA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x007C666A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x007C82FA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x007CDCEA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x007D0A5A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x007D535A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x007EF278+3,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x00824EDA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0082C7DA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x00836A7A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0083E7DA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x00840BAA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x00843E2A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0084636A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0084749A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0084926A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0084B27A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0084E6BA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0084F05A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x00850F1A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0085292A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x00853C3A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x00854C4A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0085664A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x00857E1A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x008650EA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x00867E9A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x00868E3A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0086D0CC+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x008750CA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0087692A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x00878C1A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x00879AEA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0088040A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x008810AA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x00882C4A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x008841AA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x00892F6A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0089409A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0094842A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0094BACA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0094C55A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0094FB5A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0095127A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		SetDword(0x0095201A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.tga");
		//newui_msgbox_back
		SetDword(0x00784D0A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0078ED1A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x007C16DA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x007C2DBA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x007C666A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x007C82FA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x007CDCEA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x007D0A5A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x007D535A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x007EF278+3,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x00824EDA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0082C7DA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x00836A7A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0083E7DA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x00840BAA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x00843E2A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0084636A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0084749A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0084926A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0084B27A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0084E6BA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0084F05A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x00850F1A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0085292A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x00853C3A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x00854C4A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0085664A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x00857E1A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x008650EA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x00867E9A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x00868E3A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0086D0CC+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x008750CA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0087692A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x00878C1A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x00879AEA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0088040A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x008810AA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x00882C4A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x008841AA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x00892F6A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0089409A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0094842A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0094BACA+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0094C55A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0094FB5A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0095127A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");
		SetDword(0x0095201A+1,(DWORD)"Custom\\Interface\\S2\\newui_msgbox_back.jpg");

		//newui_item_add_table
		SetDword(0x007D541A+1,(DWORD)"Custom\\Interface\\null.tga"); //-> Borda Inventario Expanded

		//newui_item_gloves
		SetDword(0x00836C5A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_gloves.tga");
		//newui_item_lower
		SetDword(0x00836C7A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_lower.tga");
		//newui_item_ring
		SetDword(0x00836C9A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_ring.tga");
		//newui_item_necklace
		SetDword(0x00836CBA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_necklace.tga");
		//newui_item_wing
		SetDword(0x00836BDA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_wing.tga");
		//newui_item_weapon(L)
		SetDword(0x00836BFA+1,(DWORD)"Custom\\Interface\\S2\\newui_item_weapon(L).tga");
		//newui_item_weapon(R)
		SetDword(0x00836C1A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_weapon(R).tga");
		//newui_item_upper
		SetDword(0x00836C3A+1,(DWORD)"Custom\\Interface\\S2\\newui_item_upper.tga");
		//newui_Bt_closeshop
		SetDword(0x00836ABA+1,(DWORD)"Custom\\Interface\\S2\\newui_Bt_closeshop.tga");
		SetDword(0x00840CAA+1,(DWORD)"Custom\\Interface\\S2\\newui_Bt_closeshop.tga");
		//newui_Bt_openshop
		SetDword(0x00836A9A+1,(DWORD)"Custom\\Interface\\S2\\newui_Bt_openshop.tga");
		SetDword(0x00840C8A+1,(DWORD)"Custom\\Interface\\S2\\newui_Bt_openshop.tga");
		//--
		//Transparency border inventory etc..
		//newui_item_table01(L)
		SetDword(0x00784DAA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x007D993A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0084B33A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0084E79A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x00879C0A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x008804EA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x00882D2A+1,(DWORD)"Custom\\Interface\\Null.tga");
		//--
		//newui_item_table01(R)
		SetDword(0x00784DCA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x007D995A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0084B35A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0084E7BA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x00879C2A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0088050A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x00882D4A+1,(DWORD)"Custom\\Interface\\Null.tga");
		//--
		//newui_item_table02(L)
		SetDword(0x00784DEA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x007D997A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0084B37A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0084E7DA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x00879C4A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0088052A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x00882D6A+1,(DWORD)"Custom\\Interface\\Null.tga");
		//--
		//newui_item_table02(R)
		SetDword(0x00784E0A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x007D999A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0084B39A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0084E7FA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x00879C6A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0088054A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x00882D8A+1,(DWORD)"Custom\\Interface\\Null.tga");
		//--
		//newui_item_table03(Dw)
		SetDword(0x00784E4A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x007CDE0A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x007D99DA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0084B3DA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0084E83A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x00879CAA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0088058A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x00882DCA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x008842CA+1,(DWORD)"Custom\\Interface\\Null.tga");
		//--
		//newui_item_table03(L)
		SetDword(0x00784E6A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x007CDE2A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x007D99FA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0084B3FA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0084E85A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x00879CCA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x008805AA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x00882DEA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x008842EA+1,(DWORD)"Custom\\Interface\\Null.tga");
		//--
		//newui_item_table03(R)
		SetDword(0x00784E8A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x007CDE4A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x007D9A1A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0084B41A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0084E87A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x00879CEA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x008805CA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x00882E0A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0088430A+1,(DWORD)"Custom\\Interface\\Null.tga");
		//--
		//newui_item_table03(Up)
		SetDword(0x00784E2A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x007CDDEA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x007D99BA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0084B3BA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0084E81A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x00879C8A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x0088056A+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x00882DAA+1,(DWORD)"Custom\\Interface\\Null.tga");
		SetDword(0x008842AA+1,(DWORD)"Custom\\Interface\\Null.tga");

		//op1_back1.tga
	SetDword(0x006333C7+1,(DWORD)"Custom\\Interface\\S2\\Menu\\op1_back1.tga");

	//op1_back2.tga
	SetDword(0x006333E7+1,(DWORD)"Custom\\Interface\\S2\\Menu\\op1_back2.tga");

	//op1_back3.tga
	SetDword(0x00633407+1,(DWORD)"Custom\\Interface\\S2\\Menu\\op1_back3.tga");

	//op1_back4.tga
	SetDword(0x00633427+1,(DWORD)"Custom\\Interface\\S2\\Menu\\op1_back4.tga");

	//op1_stone.jpg
	SetDword(0x006333A7+1,(DWORD)"Custom\\Interface\\S2\\Menu\\op1_stone.jpg");

	//op2_back1.tga
	SetDword(0x00633467+1,(DWORD)"Custom\\Interface\\S2\\Menu\\op2_back1.tga");

	//op2_ch.tga
	SetDword(0x00633487+1,(DWORD)"Custom\\Interface\\S2\\Menu\\op2_ch.tga");
	
	//op2_volume1.tga
	SetDword(0x006334E7+1,(DWORD)"Custom\\Interface\\S2\\Menu\\op2_volume1.tga");

	//op2_volume2.jpg
	SetDword(0x006334C7+1,(DWORD)"Custom\\Interface\\S2\\Menu\\op2_volume2.jpg");

	//op2_volume3.tga
	SetDword(0x006334A7+1,(DWORD)"Custom\\Interface\\S2\\Menu\\op2_volume3.tga");

	//mini_map_ui_cancel
	SetDword(0x0082A863+1,(DWORD)"Custom\\Interface\\S2\\Menu\\mini_map_ui_cancel.tga");
	
	//newui_Message_03
	SetDword(0x00824F1A+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_Message_03.tga");
	
	//newui_msgbox_bottom.tga
	SetDword(0x0087690A+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_msgbox_bottom.tga");
	SetDword(0x0086D0AC+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_msgbox_bottom.tga");
	SetDword(0x00824EBA+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_msgbox_bottom.tga");

	//newui_msgbox_middle.tga
	SetDword(0x008768EA+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_msgbox_middle.tga");
	SetDword(0x0086D08C+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_msgbox_middle.tga");
	SetDword(0x00824E9A+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_msgbox_middle.tga");

	//newui_msgbox_top.tga
	SetDword(0x008768CA+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_msgbox_top.tga");
	SetDword(0x0086D06C+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_msgbox_top.tga");
	SetDword(0x00824E7A+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_msgbox_top.tga");

	//newui_option_top
	SetDword(0x0095205A+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_top.tga");
	SetDword(0x009512BA+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_top.tga");
	SetDword(0x0094FB9A+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_top.tga");
	SetDword(0x0094C59A+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_top.tga");
	SetDword(0x0094BB0A+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_top.tga");
	SetDword(0x0094846A+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_top.tga");
	SetDword(0x008492AA+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_top.tga");

	//newui_option_back06(R)
	SetDword(0x0095209A+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_back06(R).tga");
	SetDword(0x009512FA+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_back06(R).tga");
	SetDword(0x0094FBDA+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_back06(R).tga");
	SetDword(0x0094C5DA+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_back06(R).tga");
	SetDword(0x0094BB4A+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_back06(R).tga");
	SetDword(0x009484AA+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_back06(R).tga");
	SetDword(0x008492EA+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_back06(R).tga");

	//newui_option_back06(L)
	SetDword(0x0095207A+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_back06(L).tga");
	SetDword(0x009512DA+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_back06(L).tga");
	SetDword(0x0094FBBA+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_back06(L).tga");
	SetDword(0x0094C5BA+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_back06(L).tga");
	SetDword(0x0094BB2A+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_back06(L).tga");
	SetDword(0x0094848A+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_back06(L).tga");
	SetDword(0x008492CA+1,(DWORD)"Custom\\Interface\\S2\\Menu\\newui_option_back06(L).tga");
	}
}