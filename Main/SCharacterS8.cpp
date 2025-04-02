#include "stdafx.h"
#include "SCharacter.h"
#include "Defines.h"
#include "TMemory.h"
#include "import.h"

__declspec(naked) void SelectCharacterCordPJ1SS()
{
	static float D41DCC = 13379.0f;
	static float D41DC8 = 11958.0f;
	static float D27AE0 = 115.0f;
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

__declspec(naked) void SelectCharacterCordPJ21SS()
{
	static float D41DCC = 13379.0f;
	static float D41DC8 = 11958.0f;
	static float D27AE0 = 115.0f;
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

__declspec(naked) void SelectCharacterCordPJ2SS()
{
	static float D41DC4 = 13367.0f;
	static float D41DC0 = 12229.0f;
	static float D254C0 = 90.0f;
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

__declspec(naked) void SelectCharacterCordPJ22SS()
{
	static float D41DC4 = 13367.0f;
	static float D41DC0 = 12229.0f;
	static float D254C0 = 90.0f;
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

__declspec(naked) void SelectCharacterCordPJ3SS()
{
	static float D41DBC = 13384.0f;
	static float D41DB8 = 12503.0f;
	static float D2B954 = 75.0f;
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

__declspec(naked) void SelectCharacterCordPJ23SS()
{
	static float D41DBC = 13384.0f;
	static float D41DB8 = 12503.0f;
	static float D2B954 = 75.0f;
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

__declspec(naked) void SelectCharacterCordPJ4SS()
{
	static float D41DB4 = 13468.0f;
	static float D41DB0 = 12764.0f;
	static float D2577C = 60.0f;
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

__declspec(naked) void SelectCharacterCordPJ24SS()
{
	static float D41DB4 = 13468.0f;
	static float D41DB0 = 12764.0f;
	static float D2577C = 60.0f;
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

__declspec(naked) void SelectCharacterCordPJ5SS()
{
	static float D41DAC = 13566.0f;
	static float D41DA8 = 13018.0f;
	static float D27BFC = 35.0f;
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

__declspec(naked) void SelectCharacterCordPJ25SS()
{
	static float D41DAC = 13566.0f;
	static float D41DA8 = 13018.0f;
	static float D27BFC = 35.0f;
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

void SCharacterS8()
{
	SetRange((LPVOID)0x0063D1CE, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D1CE, (LPVOID)SelectCharacterCordPJ1SS, ASM::JMP);
	SetRange((LPVOID)0x0063D40F, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D40F, (LPVOID)SelectCharacterCordPJ21SS, ASM::JMP);
	
	SetRange((LPVOID)0x0063D1EB, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D1EB, (LPVOID)SelectCharacterCordPJ2SS, ASM::JMP);
	SetRange((LPVOID)0x0063D42C, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D42C, (LPVOID)SelectCharacterCordPJ22SS, ASM::JMP);
	
	SetRange((LPVOID)0x0063D208, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D208, (LPVOID)SelectCharacterCordPJ3SS, ASM::JMP);
	SetRange((LPVOID)0x0063D449, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D449, (LPVOID)SelectCharacterCordPJ23SS, ASM::JMP);
	
	SetRange((LPVOID)0x0063D225, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D225, (LPVOID)SelectCharacterCordPJ4SS, ASM::JMP);
	SetRange((LPVOID)0x0063D466, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D466, (LPVOID)SelectCharacterCordPJ24SS, ASM::JMP);
	
	SetRange((LPVOID)0x0063D242, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D242, (LPVOID)SelectCharacterCordPJ5SS, ASM::JMP);
	SetRange((LPVOID)0x0063D483, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D483, (LPVOID)SelectCharacterCordPJ25SS, ASM::JMP);
}