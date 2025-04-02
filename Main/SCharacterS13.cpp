#include "stdafx.h"
#include "SCharacter.h"
#include "Defines.h"
#include "TMemory.h"
#include "import.h"
#include "Protect.h"

__declspec(naked) void SelectCharacterCordPJ1SSX()
{
	static float D41DCC = 13629.000f; //8008.000
	static float D41DC8 = 12339.000f; //18885.00
	static float D27AE0 = 90.000f; //115.0000
	static DWORD SelectCharacterCordPJ1_buff = 0x0063D1E9;
	
	_asm
	{
		FLD DWORD PTR DS:[D41DCC]
		FSTP DWORD PTR SS:[EBP-0x14]
		FLD DWORD PTR DS:[D41DC8]
		FSTP DWORD PTR SS:[EBP-0x10]
		FLD DWORD PTR DS:[D27AE0]
		FSTP DWORD PTR SS:[EBP-0x18]
		jmp [SelectCharacterCordPJ1_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ21SSX()
{
	static float D41DCC = 13629.000f; //8008.000
	static float D41DC8 = 12339.00f; //18885.00
	static float D27AE0 = 90.0000f; //115.0000
	static DWORD SelectCharacterCordPJ1_buff = 0x0063D42A;

	_asm
	{
		FLD DWORD PTR DS:[D41DCC]
		FSTP DWORD PTR SS:[EBP-0xC]
		FLD DWORD PTR DS:[D41DC8]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[D27AE0]
		FSTP DWORD PTR SS:[EBP-0x14]
		jmp [SelectCharacterCordPJ1_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ1S4()
{
	static float D41DCC = 22840.0f; //8008.000
	static float D41DC8 = 15355.0f; //18885.00
	static float D27AE0 = 45.0f; //115.0000
	static DWORD SelectCharacterCordPJ1_buff = 0x0063D1E9;
	_asm
	{
		FLD DWORD PTR DS:[D41DCC]
		FSTP DWORD PTR SS:[EBP-0x14]
		FLD DWORD PTR DS:[D41DC8]
		FSTP DWORD PTR SS:[EBP-0x10]
		FLD DWORD PTR DS:[D27AE0]
		FSTP DWORD PTR SS:[EBP-0x18]
		jmp [SelectCharacterCordPJ1_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ21S4()
{
	static float D41DCC = 22840.0f; //8008.000
	static float D41DC8 = 15355.0f; //18885.00
	static float D27AE0 = 45.0f; //115.0000
	static DWORD SelectCharacterCordPJ1_buff = 0x0063D42A;
	_asm
	{
		FLD DWORD PTR DS:[D41DCC]
		FSTP DWORD PTR SS:[EBP-0xC]
		FLD DWORD PTR DS:[D41DC8]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[D27AE0]
		FSTP DWORD PTR SS:[EBP-0x14]
		jmp [SelectCharacterCordPJ1_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ2S4()
{
	static float D41DC4 = 1000.0f; //7986.000
	static float D41DC0 = 5845.0f; //19145.00
	static float D254C0 = 45.0f; //90.00000
	static DWORD SelectCharacterCordPJ2_buff = 0x0063D206;
	_asm
	{
		FLD DWORD PTR DS:[D41DC4]
		FSTP DWORD PTR SS:[EBP-0x14]
		FLD DWORD PTR DS:[D41DC0]
		FSTP DWORD PTR SS:[EBP-0x10]
		FLD DWORD PTR DS:[D254C0]
		FSTP DWORD PTR SS:[EBP-0x18]
		jmp [SelectCharacterCordPJ2_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ22S4()
{
	static float D41DC4 = 1000.0f; //7986.000
	static float D41DC0 = 5845.0f; //19145.00
	static float D254C0 = 45.0f; //90.00000
	static DWORD SelectCharacterCordPJ2_buff = 0x0063D447;
	_asm
	{
		FLD DWORD PTR DS:[D41DC4]
		FSTP DWORD PTR SS:[EBP-0xC]
		FLD DWORD PTR DS:[D41DC0]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[D254C0]
		FSTP DWORD PTR SS:[EBP-0x14]
		jmp [SelectCharacterCordPJ2_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ3S4()
{
	static float D41DBC = 1000.0f; //8046.000
	static float D41DB8 = 5845.0f; //19400.00
	static float D2B954 = 45.0f; //75.00000
	static DWORD SelectCharacterCordPJ3_buff = 0x0063D223;
	_asm
	{
		FLD DWORD PTR DS:[D41DBC]
		FSTP DWORD PTR SS:[EBP-0x14]
		FLD DWORD PTR DS:[D41DB8]
		FSTP DWORD PTR SS:[EBP-0x10]
		FLD DWORD PTR DS:[D2B954]
		FSTP DWORD PTR SS:[EBP-0x18]
		jmp [SelectCharacterCordPJ3_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ23S4()
{
	static float D41DBC = 1000.0f; //8046.000
	static float D41DB8 = 5845.0f; //19400.00
	static float D2B954 = 45.0f; //75.00000
	static DWORD SelectCharacterCordPJ3_buff = 0x0063D464;
	_asm
	{
		FLD DWORD PTR DS:[D41DBC]
		FSTP DWORD PTR SS:[EBP-0xC]
		FLD DWORD PTR DS:[D41DB8]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[D2B954]
		FSTP DWORD PTR SS:[EBP-0x14]
		jmp [SelectCharacterCordPJ3_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ4S4()
{
	static float D41DB4 = 1000.0f; //8133.000
	static float D41DB0 = 5845.0f; //19645.00
	static float D2577C = 45.0f; //60.00000
	static DWORD SelectCharacterCordPJ4_buff = 0x0063D240;
	_asm
	{
		FLD DWORD PTR DS:[D41DB4]
		FSTP DWORD PTR SS:[EBP-0x14]
		FLD DWORD PTR DS:[D41DB0]
		FSTP DWORD PTR SS:[EBP-0x10]
		FLD DWORD PTR DS:[D2577C]
		FSTP DWORD PTR SS:[EBP-0x18]
		jmp [SelectCharacterCordPJ4_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ24S4()
{
	static float D41DB4 = 1000.0f; //8133.000
	static float D41DB0 = 5845.0f; //19645.00
	static float D2577C = 45.0f; //60.00000
	static DWORD SelectCharacterCordPJ4_buff = 0x0063D481;
	_asm
	{
		FLD DWORD PTR DS:[D41DB4]
		FSTP DWORD PTR SS:[EBP-0xC]
		FLD DWORD PTR DS:[D41DB0]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[D2577C]
		FSTP DWORD PTR SS:[EBP-0x14]
		jmp [SelectCharacterCordPJ4_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ5S4()
{
	static float D41DAC = 1000.0f; //8282.000
	static float D41DA8 = 5845.0f; //19845.00
	static float D27BFC = 45.0f; //35.00000
	static DWORD SelectCharacterCordPJ5_buff = 0x0063D25D;
	_asm
	{
		FLD DWORD PTR DS:[D41DAC]
		FSTP DWORD PTR SS:[EBP-0x14]
		FLD DWORD PTR DS:[D41DA8]
		FSTP DWORD PTR SS:[EBP-0x10]
		FLD DWORD PTR DS:[D27BFC]
		FSTP DWORD PTR SS:[EBP-0x18]
		jmp [SelectCharacterCordPJ5_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ25S4()
{
	static float D41DAC = 1000.0f; //8282.000
	static float D41DA8 = 5845.0f; //19845.00
	static float D27BFC = 45.0f; //35.00000
	static DWORD SelectCharacterCordPJ5_buff = 0x0063D49E;
	_asm
	{
		FLD DWORD PTR DS:[D41DAC]
		FSTP DWORD PTR SS:[EBP-0xC]
		FLD DWORD PTR DS:[D41DA8]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[D27BFC]
		FSTP DWORD PTR SS:[EBP-0x14]
		jmp [SelectCharacterCordPJ5_buff]
	}
}

void SCharacterS13()
{
	//-> Login Theme Type (Season 4)
	if(gProtect.m_MainInfo.SelectLoginThemeType == 2)
	{
		SetRange((LPVOID)0x0063D1CE, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D1CE, (LPVOID)SelectCharacterCordPJ1S4, ASM::JMP);
		SetRange((LPVOID)0x0063D40F, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D40F, (LPVOID)SelectCharacterCordPJ21S4, ASM::JMP);
	
		SetRange((LPVOID)0x0063D1EB, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D1EB, (LPVOID)SelectCharacterCordPJ2S4, ASM::JMP);
		SetRange((LPVOID)0x0063D42C, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D42C, (LPVOID)SelectCharacterCordPJ22S4, ASM::JMP);
	
		SetRange((LPVOID)0x0063D208, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D208, (LPVOID)SelectCharacterCordPJ3S4, ASM::JMP);
		SetRange((LPVOID)0x0063D449, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D449, (LPVOID)SelectCharacterCordPJ23S4, ASM::JMP);
	
		SetRange((LPVOID)0x0063D225, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D225, (LPVOID)SelectCharacterCordPJ4S4, ASM::JMP);
		SetRange((LPVOID)0x0063D466, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D466, (LPVOID)SelectCharacterCordPJ24S4, ASM::JMP);
	
		SetRange((LPVOID)0x0063D242, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D242, (LPVOID)SelectCharacterCordPJ5S4, ASM::JMP);
		SetRange((LPVOID)0x0063D483, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D483, (LPVOID)SelectCharacterCordPJ25S4, ASM::JMP);
	}

	//-> Login Theme Type (EX700)
	if(gProtect.m_MainInfo.SelectLoginThemeType == 4)
	{
		SetRange((LPVOID)0x0063D1CE, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D1CE, (LPVOID)SelectCharacterCordPJ1SSX, ASM::JMP);

		SetRange((LPVOID)0x0063D40F, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D40F, (LPVOID)SelectCharacterCordPJ21SSX, ASM::JMP);
	}
}