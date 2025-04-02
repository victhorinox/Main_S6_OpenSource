#include "stdafx.h"
#include "TMemory.h"
#include "Import.h"
#include "ToolKit.h"
#include "Defines.h"

char Folder1[255]="ImgsMapName\\";
char Folder2[255]="%s";
char Folder3[255]="Custom\\Local\\";
char Folder4[255]="ImgsMapName\\MapNameAddStrife.tga";

__declspec(naked) void MoveLocal1()
{
	static DWORD Address1=0x0047E1D3;
	
	_asm
	{
		Lea Eax,Folder1
			PUSH Eax
			Lea Ecx,Folder2
			Push Ecx
			Lea Edx,Folder3
			PUSH Edx
			Jmp Address1
	}
}

__declspec(naked) void MoveLocal2()
{
	static DWORD Address1=0x006339F6;
	
	_asm
	{
		Lea Eax,Folder4
			PUSH Eax
			Lea Ecx,Folder2
			Push Ecx
			Lea Edx,Folder3
			PUSH Edx
			Jmp Address1
	}
}

void MoveLocal()
{
	SetRange((PVOID)0x0047E1C4,0xF,ASM::NOP);
	SetOp((LPVOID)0x0047E1C4,(LPVOID)MoveLocal1,ASM::JMP);
	
	SetRange((PVOID)0x006339E7,0xF,ASM::NOP);
	SetOp((LPVOID)0x006339E7,(LPVOID)MoveLocal2,ASM::JMP);
}