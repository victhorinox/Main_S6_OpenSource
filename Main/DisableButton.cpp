#include "stdafx.h"
#include "Defines.h"
#include "TMemory.h"
#include "import.h"
#include "DisableButton.h"

__declspec(naked) void OffButtonQuestInStats()
{
	static DWORD ButtonAddress = 0x0077EBB5;
	
	_asm
	{
		jmp ButtonAddress
	}
}

__declspec(naked) void OffButtonPetsInStats()
{
	static DWORD ButtonAddress = 0x0077EC5E;
	
	_asm
	{
		jmp ButtonAddress
	}
}

__declspec(naked) void OffButtonSkillMasterInStats()
{
	static DWORD ButtonAddress = 0x0077ECE7;
	
	_asm
	{
		jmp ButtonAddress
	}
}

__declspec(naked) void OffButtonInventoryExp()
{
	static DWORD ButtonAddress = 0x00836A28;
	
	_asm
	{
		jmp ButtonAddress
	}
}

__declspec(naked) void OffButtonOpenStore()
{
	static DWORD ButtonAddress = 0x008369B4;
	
	_asm
	{
		jmp ButtonAddress
	}
}
__declspec(naked) void OffButtonRepeirInInventory()
{
	static DWORD ButtonAddress = 0x00836941;
	
	_asm
	{
		jmp ButtonAddress
	}
}

void DisableButtonInventory()
{
	SetOp((LPVOID)0x0083693C,(LPVOID)OffButtonRepeirInInventory,ASM::CALL);
}

void DisableButtonInventoryExp()
{
	SetOp((LPVOID)0x00836A23,(LPVOID)OffButtonInventoryExp,ASM::CALL);
}

void DisableButtonOpenStore()
{
	SetOp((LPVOID)0x008369AF,(LPVOID)OffButtonOpenStore,ASM::CALL);
}

void DisableButtonQuest()
{
	SetOp((LPVOID)0x0077EBB0,(LPVOID)OffButtonQuestInStats,ASM::CALL);
}

void DisableButtonPet()
{
	SetOp((LPVOID)0x0077EC59,(LPVOID)OffButtonPetsInStats,ASM::CALL);
}

void DisableButtonOpenSkillTree()
{
	SetOp((LPVOID)0x0077ECE2,(LPVOID)OffButtonSkillMasterInStats,ASM::CALL);
}