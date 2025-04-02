#include "stdafx.h"
#include "Offset.h"
#include "Util.h"
#include "TMemory.h"
#include "ItemAsm.h"
#include "Object.h"
#include "Import.h"
#include "Defines.h"
#include "CustomBow.h"
#include "Config.h"

DWORD IsBowItem = 0;
DWORD IsCrossItem = 0;
DWORD BowValue = 0x09C;
DWORD MaxBoneCount = 0x108;
DWORD WorldPosition = 0x0FC;
DWORD oCreateEffect = 0x006D9070; // 1.04D ENG
DWORD ReturnBowCode = 0x0074A12E; // 1.04D ENG
DWORD BowPosition = 0x005CC8ED; // 1.04D ENG
DWORD NextBowPosition = 0x005CC92E; // 1.04D ENG
DWORD BowAddPlayerDimension_Offset = 0x0056617F; // 1.04D ENG
DWORD ReturnCrossCode = 0x00749DD2;

void __declspec(naked) cBowAddSkillEffect()
{
	_asm
	{
		MOV ECX, DWORD PTR SS:[EBP-0x04]
		MOV DWORD PTR SS:[EBP-0x14],ECX
			MOV IsBowItem, ECX
	}
	
	if(gCustomBow.CheckCustomBow(IsBowItem - ITEM_INTER))
	{
		CUSTOM_BOW_INFO* bow = gCustomBow.GetInfoByItem(IsBowItem - ITEM_INTER);
		
		int SkillShot;
		
		if(bow != 0)
		{
			SkillShot = bow->SkillShot;
			
			_asm
			{
				PUSH - 1
				PUSH 0
				PUSH 0
				MOV DX, WORD PTR SS:[EBP+0x18]
				PUSH EDX
				MOV AX, WORD PTR SS:[EBP+0x14]
				PUSH EAX
				MOV ECX, DWORD PTR SS:[EBP+0x0C]

				mov dx, word ptr ds : [ecx + 0x2C]
				push edx
				mov eax, dword ptr ss : [ebp + 0x0C]
				push eax
				mov ecx, dword ptr ss : [ebp - 0x8]
				push ecx
				mov edx, dword ptr ss : [ebp + 0x0C]
				add edx, BowValue
				push edx
				mov eax, dword ptr ss : [ebp + 0x0C]
				add eax, MaxBoneCount
				push eax
				mov ecx, dword ptr ss : [ebp + 0x0C]
				add ecx, WorldPosition
				push ecx
				push SkillShot
				call oCreateEffect
			}
		}
	}
	
	_asm
	{
		jmp ReturnBowCode
	}
}

void __declspec(naked) cCrossAddSkillEffect()
{
	_asm
    {
		mov ecx, dword ptr ss : [ebp - 0x0C]
		mov dword ptr ss : [ebp - 0x10], ecx
		mov IsCrossItem, ecx
    }
	
	if(gCustomBow.CheckCustomCross(IsCrossItem - ITEM_INTER))
	{
		CUSTOM_BOW_INFO* cross = gCustomBow.GetInfoByItem(IsCrossItem - ITEM_INTER);

		int SkillShot;

		if(cross != 0)
		{

			SkillShot = cross->SkillShot;
			_asm
			{
				push - 1
				push 0
				push 0
				mov dx, word ptr ss : [ebp + 0x18]
				push edx
				mov ax, word ptr ss : [ebp + 0x14]
				push eax
				mov ecx, dword ptr ss : [ebp + 0x0C]
				mov dx, word ptr ds : [ecx + 0x2C]
				push edx
				mov eax, dword ptr ss : [ebp + 0x0C]
				push eax
				mov ecx, dword ptr ss : [ebp - 0x8]
				push ecx
				mov edx, dword ptr ss : [ebp + 0x0C]
				add edx, BowValue
				push edx
				mov eax, dword ptr ss : [ebp + 0x0C]
				add eax, MaxBoneCount
				push eax
				mov ecx, dword ptr ss : [ebp + 0x0C]
				add ecx, WorldPosition
				push ecx
				push SkillShot
				call oCreateEffect
			}
		}
    }
    _asm
    {
        jmp ReturnCrossCode
    }
}

void __declspec(naked) cBowAddInventoryPos()
{
	_asm
	{
		mov ecx, dword ptr ss : [ebp + 0x8]
		mov dword ptr ss : [ebp + 0x8], ecx
			mov IsBowItem, ecx
	}
	
	if (IsBowItem == 0x0CAB)
	{
		_asm
		{
			jmp BowPosition
		}
	}
	
	else if (IsBowItem > ITEM2(4,24) && IsBowItem < ITEM2(4,250) && !gCustomBow.CheckCustomCross(IsBowItem - 1171))
	{
		_asm
		{
			jmp BowPosition
		}
	}
	
	else
	{
		_asm
		{
			jmp NextBowPosition
		}
	}
}

void __declspec(naked) cBowAddPlayerDimension()
{
	_asm
	{
		CMP DWORD PTR SS:[EBP+0x1C],0x0CA7
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,25)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,26)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,27)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,28)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,29)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,30)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,31)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,32)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,33)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,34)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,35)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,36)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,37)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,38)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,39)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,40)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,41)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,42)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,43)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,44)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,45)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,46)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,47)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,48)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,49)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,50)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,51)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,52)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,53)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,54)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,55)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,56)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,57)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,58)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,59)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,60)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,61)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,62)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,63)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,64)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,65)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,66)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,67)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,68)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,69)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,70)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,71)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,72)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,73)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,74)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,75)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,76)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,77)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,78)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,79)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,80)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,81)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,82)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,83)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,84)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,85)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,86)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,87)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,88)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,89)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,90)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,91)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,92)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,93)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,94)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,95)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,96)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,97)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,98)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,99)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,100)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,101)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,102)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,103)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,104)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,105)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,106)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,107)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,108)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,109)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,110)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,111)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,112)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,113)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,114)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,115)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,116)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,117)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,118)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,119)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,120)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,121)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,122)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,123)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,124)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,125)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,126)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,127)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,128)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,129)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,130)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,131)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,132)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,133)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,134)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,135)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,136)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,137)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,138)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,139)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,140)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,141)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,142)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,143)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,144)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,145)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,146)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,147)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,148)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,149)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,150)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,151)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,152)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,153)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,154)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,155)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,156)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,157)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,158)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,159)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,160)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,161)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,162)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,163)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,164)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,165)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,166)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,167)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,168)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,169)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,170)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,171)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,172)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,173)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,174)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,175)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,176)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,177)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,178)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,179)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,180)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,181)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,182)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,183)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,184)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,185)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,186)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,187)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,188)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,189)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,190)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,191)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,192)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,193)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,194)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,195)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,196)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,197)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,198)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,199)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,200)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,201)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,202)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,203)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,204)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,205)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,206)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,207)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,208)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,209)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,210)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,211)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,212)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,213)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,214)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,215)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,216)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,217)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,218)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,219)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,220)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,221)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,222)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,223)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,224)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,225)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,226)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,227)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,228)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,229)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,230)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,231)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,232)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,233)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,234)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,235)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,236)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,237)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,238)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,239)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,240)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,241)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,242)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,243)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,244)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,245)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,246)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,247)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,248)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,249)
			JE ReturnLoad
			CMP DWORD PTR SS:[EBP+0x1C],ITEM2(4,250)
ReturnLoad:
			JMP BowAddPlayerDimension_Offset
	}
}

void __declspec(naked) cCrossBowAddPlayerDimension()
{
    static DWORD Address1 = 0x00565994;
    static DWORD Address2 = 0x005659E7;  

	_asm
	{
	   Mov Ecx, Dword ptr ss : [ebp + 0x1C]
	   Mov Dword ptr ss : [ebp + 0x1C],Ecx
	   Mov IsCrossItem, Ecx
	}

    if(IsCrossItem >= ITEM2(4,8) && IsCrossItem <= ITEM2(4,14)||IsCrossItem == ITEM2(4,16)||IsCrossItem == ITEM2(4,18)||IsCrossItem == ITEM2(4,19) || gCustomBow.CheckCustomCross(IsCrossItem - 1171)) // Devil Crossbow
    {
		_asm
		{
			jmp Address1
		}
	}
	else
	{
		_asm
		{
			jmp Address2
		}
	}
}

signed int __cdecl FixBowArrow(WORD *a1)
{
	signed int result;
	
	if ((int)(*a1/512) != 4 || *a1 == 2055 || *a1 == 2063)
	{
		return 0;
	}
	
	ItemBmdStruct* ItemInfo = pGetItemBmdStruct(*a1);
	
	if (ItemInfo == 0 || (*a1/512) != 4)
	{
		return 0;
	}
	
	if (ItemInfo->Slot == 0)
	{
		return 2;
	}
	
	if (ItemInfo->Slot == 1)
	{
		return 1;
	}
	
	return 0;
}

void __declspec(naked) CustomItemPosition()
{
    static DWORD IsItemPosition = 0;
    static DWORD ItemPosition = 0x005CD084;
    static DWORD NextItemPosition = 0x005CD086;
	//--
	static float FixSacredGloveSizeX = -90.0f;	static float FixSacredGloveSizeY = 0.0f;	static float FixSacredGloveSizeZ = 0.0f;	static double FixSacredGlovePosX = 0.0f;	static double FixSacredGlovePosY = 0.025f;		//-> Fix Sacred Glove (RF)
	static float CustomBookSizeX = -90.0f;		static float CustomBookSizeY = -05.0f;		static float CustomBookSizeZ = 0.0f;		static double CustomBookPosX = 0.01f;		static double CustomBookPosY = 0.00f;			//-> Custom Books (SU)
	static float NewAcessorySizeX = -90.0f;		static float NewAcessorySizeY = 0.0f;		static float NewAcessorySizeZ = 0.0f;		static double NewAcessoryPosX = 0.0f;		static double NewAcessoryPosY = 0.0f;			//-> New Acessory (S8)
	//--
	static float MountPetSizeX = -90.0f;		static float MountPetSizeY = -30.0f;		static float MountPetSizeZ = 0.0f;			static double MountPetPosX = 0.0125f;		static double MountPetPosY = -0.09f;			//-> Pet Mount
	//--
	static float EvolutionStoneSizeX = -90.0f;	static float EvolutionStoneSizeY = 0.0f;	static float EvolutionStoneSizeZ = 0.0f;	static double EvolutionStonePosX = -0.005f;	static double EvolutionStonePosY = -0.0375f;	//-> Evolution Stone
	//--
	static float LukiPetSizeX = -90.0f;			static float LukiPetSizeY = -30.0f;			static float LukiPetSizeZ = 0.0f;			static double LukiPetPosX = 0.024f;			static double LukiPetPosY = -0.12f;				//-> LukiPet
	static float TonyPetSizeX = -90.0f;			static float TonyPetSizeY = -30.0f;			static float TonyPetSizeZ = 0.0f;			static double TonyPetPosX = 0.008f;			static double TonyPetPosY = -0.071f;			//-> TonyPet
	static float NymphPetSizeX = -90.0f;		static float NymphPetSizeY = -30.0f;		static float NymphPetSizeZ = 0.0f;			static double NymphPetPosX = 0.007f;		static double NymphPetPosY = -0.069f;			//-> NymphPet
	static float SafiPetSizeX = -90.0f;			static float SafiPetSizeY = -30.0f;			static float SafiPetSizeZ = 0.0f;			static double SafiPetPosX = -0.001f;		static double SafiPetPosY = -0.054f;			//-> Safi Pet
	static float PaulPetSizeX = -90.0f;			static float PaulPetSizeY = -30.0f;			static float PaulPetSizeZ = 0.0f;			static double PaulPetPosX = -0.0015f;		static double PaulPetPosY = -0.1f;				//-> Paul Pet
	static float ChironPetSizeX = -90.0f;		static float ChironPetSizeY = -30.0f;		static float ChironPetSizeZ = 0.0f;			static double ChironPetPosX = -0.002f;		static double ChironPetPosY = -0.079f;			//-> Chiron Pet
	static float WooparooPetSizeX = -90.0f;		static float WooparooPetSizeY = -30.0f;		static float WooparooPetSizeZ = 0.0f;		static double WooparooPetPosX = -0.001f;	static double WooparooPetPosY = -0.085f;		//-> Wooparoo Pet
	static float TibettonPetSizeX = -90.0f;		static float TibettonPetSizeY = -30.0f;		static float TibettonPetSizeZ = 0.0f;		static double TibettonPetPosX = -0.01f;		static double TibettonPetPosY = -0.075f;		//-> Tibetton Pet
	static float WitchPetSizeX = -90.0f;		static float WitchPetSizeY = -30.0f;		static float WitchPetSizeZ = 0.0f;			static double WitchPetPosX = 0.001f;		static double WitchPetPosY = -0.095f;			//-> Witch Pet
	static float SkullPetSizeX = -90.0f;		static float SkullPetSizeY = -30.0f;		static float SkullPetSizeZ = 0.0f;			static double SkullPetPosX = -0.01f;		static double SkullPetPosY = -0.075f;			//-> Skull Pet
	static float PumpyPetSizeX = -90.0f;		static float PumpyPetSizeY = -30.0f;		static float PumpyPetSizeZ = 0.0f;			static double PumpyPetPosX = -0.01f;		static double PumpyPetPosY = -0.085f;			//-> Pumpy Pet
	static float SavathPetSizeX = -90.0f;		static float SavathPetSizeY = -30.0f;		static float SavathPetSizeZ = 0.0f;			static double SavathPetPosX = -0.01f;		static double SavathPetPosY = -0.085f;			//-> Savath Pet
	static float LycanPetSizeX = -90.0f;		static float LycanPetSizeY = -30.0f;		static float LycanPetSizeZ = 0.0f;			static double LycanPetPosX = -0.01f;		static double LycanPetPosY = -0.085f;			//-> Lycan Pet
	static float TorbyPetSizeX = -90.0f;		static float TorbyPetSizeY = -30.0f;		static float TorbyPetSizeZ = 0.0f;			static double TorbyPetPosX = -0.01f;		static double TorbyPetPosY = -0.084f;			//-> Torby Pet
	static float SeirenPetSizeX = -90.0f;		static float SeirenPetSizeY = -30.0f;		static float SeirenPetSizeZ = 0.0f;			static double SeirenPetPosX = -0.001f;		static double SeirenPetPosY = -0.082f;			//-> Seiren Pet
	static float BehemothPetSizeX = -90.0f;		static float BehemothPetSizeY = -30.0f;		static float BehemothPetSizeZ = 0.0f;		static double BehemothPetPosX = -0.001f;	static double BehemothPetPosY = -0.087f;		//-> Behemoth Pet
	static float LogglePetSizeX = -90.0f;		static float LogglePetSizeY = -30.0f;		static float LogglePetSizeZ = 0.0f;			static double LogglePetPosX = -0.03f;		static double LogglePetPosY = -0.089f;			//-> Loggle Pet
	static float MinoPetSizeX = -90.0f;			static float MinoPetSizeY = -30.0f;			static float MinoPetSizeZ = 0.0f;			static double MinoPetPosX = -0.025f;		static double MinoPetPosY = -0.088f;			//-> Mino Pet
	static float HoundPetSizeX = -90.0f;		static float HoundPetSizeY = -30.0f;		static float HoundPetSizeZ = 0.0f;			static double HoundPetPosX = -0.029f;		static double HoundPetPosY = -0.084f;			//-> Hound Pet
	static float TrivePetSizeX = -90.0f;		static float TrivePetSizeY = -30.0f;		static float TrivePetSizeZ = 0.0f;			static double TrivePetPosX = -0.025f;		static double TrivePetPosY = -0.083f;			//-> Trive Pet
	static float VoganPetSizeX = -90.0f;		static float VoganPetSizeY = -30.0f;		static float VoganPetSizeZ = 0.0f;			static double VoganPetPosX = -0.025f;		static double VoganPetPosY = -0.087f;			//-> Vogan Pet
	static float CyclopPetSizeX = -90.0f;		static float CyclopPetSizeY = -30.0f;		static float CyclopPetSizeZ = 0.0f;			static double CyclopPetPosX = -0.033f;		static double CyclopPetPosY = -0.0856f;			//-> Cyclop Pet
	static float BonfPetSizeX = -90.0f;			static float BonfPetSizeY = -40.0f;			static float BonfPetSizeZ = 0.0f;			static double BonfPetPosX = -0.025f;		static double BonfPetPosY = -0.0777f;			//-> Bonf Pet
	static float HawkPetSizeX = -90.0f;			static float HawkPetSizeY = -55.0f;			static float HawkPetSizeZ = 0.0f;			static double HawkPetPosX = -0.021f;		static double HawkPetPosY = -0.0225f;			//-> Hawk Pet
	static float eHawkPetSizeX = -90.0f;		static float eHawkPetSizeY = -55.0f;		static float eHawkPetSizeZ = 0.0f;			static double eHawkPetPosX = 0.021f;		static double eHawkPetPosY = -0.025f;			//-> Hawk Pet (Evo)
	static float MutPetSizeX = -90.0f;			static float MutPetSizeY = -45.0f;			static float MutPetSizeZ = 0.0f;			static double MutPetPosX = -0.021f;			static double MutPetPosY = -0.0874f;			//-> Mut Pet
	static float MantisPetSizeX = -90.0f;		static float MantisPetSizeY = -30.0f;		static float MantisPetSizeZ = 0.0f;			static double MantisPetPosX = 0.0f;			static double MantisPetPosY = -0.091f;			//-> Mantis Pet
	static float ScolpyPetSizeX = -90.0f;		static float ScolpyPetSizeY = -30.0f;		static float ScolpyPetSizeZ = 0.0f;			static double ScolpyPetPosX = -0.01f;		static double ScolpyPetPosY = -0.0936f;			//-> Scolpy Pet
	static float ChaferPetSizeX = -90.0f;		static float ChaferPetSizeY = -30.0f;		static float ChaferPetSizeZ = 0.0f;			static double ChaferPetPosX = -0.01f;		static double ChaferPetPosY = -0.084f;			//-> Chafer Pet
	static float CosplayGirlPetSizeX = -90.0f;	static float CosplayGirlPetSizeY = -30.0f;	static float CosplayGirlPetSizeZ = 0.0f;	static double CosplayGirlPetPosX = -0.01f;	static double CosplayGirlPetPosY = -0.086f;		//-> Cosplay Girl Pet
	static float CheerGirlPetSizeX = -90.0f;	static float CheerGirlPetSizeY = -30.0f;	static float CheerGirlPetSizeZ = 0.0f;		static double CheerGirlPetPosX = -0.01f;	static double CheerGirlPetPosY = -0.0851f;		//-> Cheer Girl Pet
	static float SportyGirlPetSizeX = -90.0f;	static float SportyGirlPetSizeY = -30.0f;	static float SportyGirlPetSizeZ = 0.0f;		static double SportyGirlPetPosX = -0.01f;	static double SportyGirlPetPosY = -0.0913f;		//-> Sporty Girl Pet
	static float BaalPetSizeX = -90.0f;			static float BaalPetSizeY = -25.0f;			static float BaalPetSizeZ = 0.0f;			static double BaalPetPosX = 0.0f;			static double BaalPetPosY = -0.079f;			//-> Baal Pet
	static float GaapPetSizeX = -90.0f;			static float GaapPetSizeY = -30.0f;			static float GaapPetSizeZ = 0.0f;			static double GaapPetPosX = -0.015f;		static double GaapPetPosY = -0.076f;			//-> Gaap Pet
	static float FrozenPetSizeX = -90.0f;		static float FrozenPetSizeY = -30.0f;		static float FrozenPetSizeZ = 0.0f;			static double FrozenPetPosX = -0.019f;		static double FrozenPetPosY = -0.082f;			//-> Frozen Pet
	static float LoorPetSizeX = -90.0f;			static float LoorPetSizeY = -30.0f;			static float LoorPetSizeZ = 0.0f;			static double LoorPetPosX = 0.0f;			static double LoorPetPosY = -0.081f;			//-> Loor Pet
	static float PurssilPetSizeX = -90.0f;		static float PurssilPetSizeY = -30.0f;		static float PurssilPetSizeZ = 0.0f;		static double PurssilPetPosX = 0.0f;		static double PurssilPetPosY = -0.0775f;		//-> Purssil Pet
	
	//--
	static float MasterScrollSizeX = -30.0f;	static float MasterScrollSizeY = 0.0f;		static float MasterScrollSizeZ = 0.0f;		static double MasterScrollPosX = 0.0f;		static double MasterScrollPosY = 0.125f;		//-> Master Scroll
	//--
	static float SpiritFragmentSizeX = -30.0f;	static float SpiritFragmentSizeY = 0.0f;	static float SpiritFragmentSizeZ = 0.0f;	static double SpiritFragmentPosX = 0.0f;	static double SpiritFragmentPosY = 0.0325f;		//-> SpiritFragment
	//--
	
	//-> Item Position 01
	//static float Item_01_SizeX = Config.Item_01_SizeX; static float Item_01_SizeY = Config.Item_01_SizeY; static float Item_01_SizeZ = Config.Item_01_SizeZ; static double Item_01_PosX = Config.Item_01_PosX; static double Item_01_PosY = Config.Item_01_PosY; //-> static DWORD WindowValue = (pWinWidth / 100) * 10; (R)
	//--
	_asm 
	{
        mov ecx, dword ptr ss:[ebp+0x8]
        mov dword ptr ss:[ebp+0x8], ecx
        mov IsItemPosition, ecx
    }
	//--
	//-> Fix Sacred Glove (RF)
	if (IsItemPosition==ITEM2(0,32)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[FixSacredGlovePosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[FixSacredGlovePosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[FixSacredGloveSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[FixSacredGloveSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[FixSacredGloveSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Custom Books (SU)
	else if (IsItemPosition>=ITEM2(5,57) && IsItemPosition<=ITEM2(5,60) || IsItemPosition==ITEM2(5,63) || IsItemPosition==ITEM2(5,66)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[CustomBookPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[CustomBookPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[CustomBookSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[CustomBookSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[CustomBookSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> New Acessory (S8)
	else if (IsItemPosition==ITEM2(13,76) || IsItemPosition==ITEM2(13,77) || IsItemPosition==ITEM2(13,78) || IsItemPosition==ITEM2(13,163) || IsItemPosition==ITEM2(13,164) || IsItemPosition==ITEM2(13,165) || IsItemPosition==ITEM2(13,166) || IsItemPosition==ITEM2(13,171) || IsItemPosition==ITEM2(13,172) || IsItemPosition==ITEM2(13,173) || IsItemPosition==ITEM2(13,174) || IsItemPosition==ITEM2(13,175) || IsItemPosition==ITEM2(13,176)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[NewAcessoryPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[NewAcessoryPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[NewAcessorySizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[NewAcessorySizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[NewAcessorySizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Pet Mount
	else if (IsItemPosition>=ITEM2(13, 200) && IsItemPosition<=ITEM2(13,210)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[MountPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[MountPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[MountPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[MountPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[MountPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Evolution Stone
	else if (IsItemPosition==ITEM2(13,211)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[EvolutionStonePosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[EvolutionStonePosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[EvolutionStoneSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[EvolutionStoneSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[EvolutionStoneSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Luki Pet
	else if (IsItemPosition==ITEM2(13,212) || IsItemPosition==ITEM2(13,213)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[LukiPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[LukiPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[LukiPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[LukiPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[LukiPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Tony Pet
	else if (IsItemPosition==ITEM2(13,214) || IsItemPosition==ITEM2(13,215)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[TonyPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[TonyPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[TonyPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[TonyPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[TonyPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Nymph Pet
	else if (IsItemPosition==ITEM2(13,216) || IsItemPosition==ITEM2(13,217)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[NymphPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[NymphPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[NymphPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[NymphPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[NymphPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Safi Pet
	else if (IsItemPosition==ITEM2(13,218) || IsItemPosition==ITEM2(13,219)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[SafiPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[SafiPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[SafiPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[SafiPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[SafiPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//-> Paul Pet
	else if (IsItemPosition==ITEM2(13,225) || IsItemPosition==ITEM2(13,226)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[PaulPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[PaulPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[PaulPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[PaulPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[PaulPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Chiron Pet
	else if (IsItemPosition==ITEM2(13,227) || IsItemPosition==ITEM2(13,228)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[ChironPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[ChironPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[ChironPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[ChironPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[ChironPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Wooparoo Pet
	else if (IsItemPosition==ITEM2(13,229) || IsItemPosition==ITEM2(13,230)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[WooparooPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[WooparooPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[WooparooPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[WooparooPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[WooparooPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Tibetton Pet
	else if (IsItemPosition==ITEM2(13,231) || IsItemPosition==ITEM2(13,232)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[TibettonPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[TibettonPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[TibettonPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[TibettonPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[TibettonPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Witch Pet
	else if (IsItemPosition==ITEM2(13,233) || IsItemPosition==ITEM2(13,234)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[WitchPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[WitchPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[WitchPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[WitchPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[WitchPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Skull Pet
	else if (IsItemPosition==ITEM2(13,235) || IsItemPosition==ITEM2(13,236)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[SkullPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[SkullPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[SkullPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[SkullPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[SkullPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Pumpy Pet
	else if (IsItemPosition==ITEM2(13,237) || IsItemPosition==ITEM2(13,238)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[PumpyPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[PumpyPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[PumpyPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[PumpyPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[PumpyPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Savath Pet
	else if (IsItemPosition==ITEM2(13,241) || IsItemPosition==ITEM2(13,242)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[SavathPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[SavathPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[SavathPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[SavathPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[SavathPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//-> Lycan Pet
	else if (IsItemPosition==ITEM2(13,243) || IsItemPosition==ITEM2(13,244)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[LycanPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[LycanPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[LycanPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[LycanPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[LycanPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Torby Pet
	else if (IsItemPosition==ITEM2(13,245) || IsItemPosition==ITEM2(13,246)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[TorbyPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[TorbyPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[TorbyPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[TorbyPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[TorbyPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Seiren Pet
	else if (IsItemPosition==ITEM2(13,252) || IsItemPosition==ITEM2(13,253)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[SeirenPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[SeirenPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[SeirenPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[SeirenPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[SeirenPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Behemoth Pet
	else if (IsItemPosition==ITEM2(13,254) || IsItemPosition==ITEM2(13,255)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[BehemothPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[BehemothPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[BehemothPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[BehemothPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[BehemothPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Loggle Pet
	else if (IsItemPosition==ITEM2(13,256) || IsItemPosition==ITEM2(13,257)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[LogglePetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[LogglePetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[LogglePetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[LogglePetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[LogglePetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Mino Pet
	else if (IsItemPosition==ITEM2(13,258) || IsItemPosition==ITEM2(13,259)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[MinoPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[MinoPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[MinoPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[MinoPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[MinoPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Hound Pet
	else if (IsItemPosition==ITEM2(13,260) || IsItemPosition==ITEM2(13,261)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[HoundPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[HoundPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[HoundPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[HoundPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[HoundPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Trive Pet
	else if (IsItemPosition==ITEM2(13,262) || IsItemPosition==ITEM2(13,263)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[TrivePetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[TrivePetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[TrivePetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[TrivePetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[TrivePetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Vogan Pet
	else if (IsItemPosition==ITEM2(13,264) || IsItemPosition==ITEM2(13,265)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[VoganPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[VoganPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[VoganPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[VoganPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[VoganPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Cyclop Pet
	else if (IsItemPosition==ITEM2(13,266) || IsItemPosition==ITEM2(13,267)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[CyclopPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[CyclopPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[CyclopPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[CyclopPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[CyclopPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Bonf Pet
	else if (IsItemPosition==ITEM2(13,270) || IsItemPosition==ITEM2(13,271)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[BonfPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[BonfPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[BonfPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[BonfPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[BonfPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Hawk Pet
	else if (IsItemPosition==ITEM2(13,272)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[HawkPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[HawkPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[HawkPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[HawkPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[HawkPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Hawk Pet (Evo)
	else if (IsItemPosition==ITEM2(13,273)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[eHawkPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[eHawkPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[eHawkPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[eHawkPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[eHawkPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Mut Pet
	else if (IsItemPosition==ITEM2(13,274) || IsItemPosition==ITEM2(13,275)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[MutPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[MutPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[MutPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[MutPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[MutPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Mantis Pet
	else if (IsItemPosition==ITEM2(13,278) || IsItemPosition==ITEM2(13,279)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[MantisPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[MantisPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[MantisPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[MantisPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[MantisPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Scolpy Pet
	else if (IsItemPosition==ITEM2(13,280) || IsItemPosition==ITEM2(13,281)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[ScolpyPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[ScolpyPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[ScolpyPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[ScolpyPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[ScolpyPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Chafer Pet
	else if (IsItemPosition==ITEM2(13,282) || IsItemPosition==ITEM2(13,283)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[ChaferPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[ChaferPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[ChaferPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[ChaferPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[ChaferPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Cosplay Girl Pet
	else if (IsItemPosition==ITEM2(13,290) || IsItemPosition==ITEM2(13,291)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[CosplayGirlPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[CosplayGirlPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[CosplayGirlPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[CosplayGirlPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[CosplayGirlPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Cheer Girl Pet
	else if (IsItemPosition==ITEM2(13,292) || IsItemPosition==ITEM2(13,293)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[CheerGirlPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[CheerGirlPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[CheerGirlPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[CheerGirlPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[CheerGirlPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Sporty Girl Pet
	else if (IsItemPosition==ITEM2(13,294) || IsItemPosition==ITEM2(13,295)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[SportyGirlPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[SportyGirlPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[SportyGirlPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[SportyGirlPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[SportyGirlPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Baal Pet
	else if (IsItemPosition==ITEM2(13,296) || IsItemPosition==ITEM2(13,297)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[BaalPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[BaalPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[BaalPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[BaalPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[BaalPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Gaap Pet
	else if (IsItemPosition==ITEM2(13,298) || IsItemPosition==ITEM2(13,299) || IsItemPosition==ITEM2(13,300) || IsItemPosition==ITEM2(13,301)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[GaapPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[GaapPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[GaapPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[GaapPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[GaapPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Frozen Pet
	else if (IsItemPosition==ITEM2(13,302) || IsItemPosition==ITEM2(13,303)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[FrozenPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[FrozenPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[FrozenPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[FrozenPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[FrozenPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Loor Pet
	else if (IsItemPosition==ITEM2(13,304) || IsItemPosition==ITEM2(13,305)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[LoorPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[LoorPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[LoorPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[LoorPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[LoorPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Purssil Pet
	else if (IsItemPosition==ITEM2(13,306) || IsItemPosition==ITEM2(13,307)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[PurssilPetPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[PurssilPetPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[PurssilPetSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[PurssilPetSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[PurssilPetSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Master Scrolls
	else if (IsItemPosition>=ITEM2(14,225) && IsItemPosition<=ITEM2(14,232) || IsItemPosition==ITEM2(14,235)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[MasterScrollPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[MasterScrollPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[MasterScrollSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[MasterScrollSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[MasterScrollSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Spirit Map Fragment
	else if (IsItemPosition>=ITEM2(14,173) && IsItemPosition<=ITEM2(14,174)) 
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[SpiritFragmentPosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[SpiritFragmentPosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[SpiritFragmentSizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[SpiritFragmentSizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[SpiritFragmentSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }
	//--
	//-> Custom Item Position 01
/*	else if (IsItemPosition==ITEM2(Config.Item_01_Type,Config.Item_01_ID))
	{
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[Config.Item_01_PosX]
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[Config.Item_01_PosY]
			FSTP DWORD PTR SS:[EBP-0x48]
			//--
			FLD DWORD PTR DS:[Item_01_SizeX]
			FSTP DWORD PTR DS:[0x82C6320]
			FLD DWORD PTR DS:[Item_01_SizeY]
			FSTP DWORD PTR DS:[0x82C6324]
			FLD DWORD PTR DS:[Item_01_SizeZ]
			FSTP DWORD PTR DS:[0x82C6328]
			jmp NextItemPosition
		}
    }*/
	//--
	else 
	{
        _asm 
		{
			jmp NextItemPosition
		}
    }
}
//--
void __declspec(naked) CustomItemPositionSize()
{
    static DWORD IsItemPositionSize = 0;
    static DWORD NextItemPositionSize = 0x005CF123;
	//--
	static float CustomBookScale		= 0.28f;		//-> Custom Book (SU)
	//--
	static float MountPetScale			= 0.00124f;		//-> Pet Mount
	//--
	static float EvolutionStoneScale	= 0.00275f;		//-> Evolution Stone
	//--
	static float LukiPetScale			= 0.00212f;		//-> Luki Pet
	static float TonyPetScale			= 0.00191f;		//-> Tony Pet
	static float NymphPetScale			= 0.00182f;		//-> Nymph Pet
	static float SafiPetScale			= 0.00185f;		//-> Safi Pet
	static float PaulPetScale			= 0.00213f;		//-> Paul Pet
	static float ChironPetScale			= 0.00185f;		//-> Chiron Pet
	static float WooparooPetScale		= 0.00224f;		//-> Wooparoo Pet
	static float TibettonPetScale		= 0.00242f;		//-> Tibetton Pet
	static float WitchPetScale			= 0.00221f;		//-> Witch Pet
	static float SkullPetScale			= 0.00222f;		//-> Skull Pet
	static float PumpyPetScale			= 0.00201f;		//-> Pumpy Pet
	static float SavathPetScale			= 0.00229f;		//-> Savath Pet
	static float LycanPetScale			= 0.00234f;		//-> Lycan Pet
	static float TorbyPetScale			= 0.00213f;		//-> Torby Pet
	static float SeirenPetScale			= 0.00203f;		//-> Seiren Pet
	static float BehemothPetScale		= 0.00191f;		//-> Behemoth Pet
	static float LogglePetScale			= 0.00202f;		//-> Loggle Pet
	static float MinoPetScale			= 0.00196f;		//-> Mino Pet
	static float HoundPetScale			= 0.00197f;		//-> Hound Pet
	static float TrivePetScale			= 0.00198f;		//-> Trive Pet
	static float VoganPetScale			= 0.00221f;		//-> Vogan Pet
	static float CyclopPetScale			= 0.00210f;		//-> Cyclop Pet
	static float BonfPetScale			= 0.00189f;		//-> Bonf Pet
	static float HawkPetScale			= 0.00211f;		//-> Hawk Pet
	static float MutPetScale			= 0.00187f;		//-> Mut Pet
	static float eMutPetScale			= 0.00174f;		//-> Mut Pet (Evo)
	static float MantisPetScale			= 0.00221f;		//-> Mantis Pet
	static float ScolpyPetScale			= 0.00206f;		//-> Scolpy Pet
	static float ChaferPetScale			= 0.00222f;		//-> Chafer Pet
	static float CosplayGirlPetScale	= 0.00269f;		//-> Cosplay Girl Pet
	static float CheerGirlPetScale		= 0.00271f;		//-> Cheer Girl Pet
	static float SportyGirlPetScale		= 0.00265f;		//-> Sporty Girl Pet
	static float BaalPetScale			= 0.00245f;		//-> Baal Pet
	static float GaapPetScale			= 0.00193f;		//-> Gaap Pet
	static float FrozenPetScale			= 0.00234f;		//-> Frozen Pet
	static float LoorPetScale			= 0.00235f;		//-> Loor Pet
	static float PurssilPetScale		= 0.00217f;		//-> Purssil Pet
	//--
	static float MasterScrollScale		= 0.0035f;		//-> Master Scrolls
	static float SpiritFragmentScale	= 0.00265f;		//-> Spirit Map Fragment
	//--

    _asm 
	{
        mov ecx, dword ptr ss:[ebp+0x8]
        mov dword ptr ss:[ebp+0x8],ecx
        mov IsItemPositionSize,ecx
    }
	//--
	//-> Custom Books (SU)
	if (IsItemPositionSize>=ITEM2(5,57) && IsItemPositionSize<=ITEM2(5,60) || IsItemPositionSize==ITEM2(5,63) || IsItemPositionSize==ITEM2(5,66)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[CustomBookScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
    }
	//--
	//-> Pet Mount
	else if (IsItemPositionSize>=ITEM2(13, 200) && IsItemPositionSize<=ITEM2(13,210)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[MountPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
    }
	//--
	//-> Master Scroll
	else if (IsItemPositionSize>=ITEM2(14,225) && IsItemPositionSize<=ITEM2(14,232) || IsItemPositionSize==ITEM2(14,235)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[MasterScrollScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Spirit Map Fragment
	else if (IsItemPositionSize>=ITEM2(14,173) && IsItemPositionSize<=ITEM2(14,174)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[SpiritFragmentScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Evolution Stone
	else if (IsItemPositionSize==ITEM2(13,211)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[EvolutionStoneScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Luki Pet
	else if (IsItemPositionSize==ITEM2(13,212) || IsItemPositionSize==ITEM2(13,213)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[LukiPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Tony Pet
	else if (IsItemPositionSize==ITEM2(13,214) || IsItemPositionSize==ITEM2(13,215)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[TonyPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Nymph Pet
	else if (IsItemPositionSize==ITEM2(13,216) || IsItemPositionSize==ITEM2(13,217)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[NymphPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Safi Pet
	else if (IsItemPositionSize==ITEM2(13,218) || IsItemPositionSize==ITEM2(13,219)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[SafiPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Paul Pet
	else if (IsItemPositionSize==ITEM2(13,225) || IsItemPositionSize==ITEM2(13,226)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[PaulPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Chiron Pet
	else if (IsItemPositionSize==ITEM2(13,227) || IsItemPositionSize==ITEM2(13,228)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[ChironPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Wooparoo Pet
	else if (IsItemPositionSize==ITEM2(13,229) || IsItemPositionSize==ITEM2(13,230)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[WooparooPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Tibetton Pet
	else if (IsItemPositionSize==ITEM2(13,231) || IsItemPositionSize==ITEM2(13,232)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[TibettonPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Witch Pet
	else if (IsItemPositionSize==ITEM2(13,233) || IsItemPositionSize==ITEM2(13,234)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[WitchPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Skull Pet
	else if (IsItemPositionSize==ITEM2(13,235) || IsItemPositionSize==ITEM2(13,236)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[SkullPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Pumpy Pet
	else if (IsItemPositionSize==ITEM2(13,237) || IsItemPositionSize==ITEM2(13,238)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[PumpyPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Savath Pet
	else if (IsItemPositionSize==ITEM2(13,241) || IsItemPositionSize==ITEM2(13,242)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[SavathPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Lycan Pet
	else if (IsItemPositionSize==ITEM2(13,243) || IsItemPositionSize==ITEM2(13,244)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[LycanPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Torby Pet
	else if (IsItemPositionSize==ITEM2(13,245) || IsItemPositionSize==ITEM2(13,246)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[TorbyPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Seiren Pet
	else if (IsItemPositionSize==ITEM2(13,252) || IsItemPositionSize==ITEM2(13,253)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[SeirenPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Behemoth Pet
	else if (IsItemPositionSize==ITEM2(13,254) || IsItemPositionSize==ITEM2(13,255)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[BehemothPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Loggle Pet
	else if (IsItemPositionSize==ITEM2(13,256) || IsItemPositionSize==ITEM2(13,257)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[LogglePetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Mino Pet
	else if (IsItemPositionSize==ITEM2(13,258) || IsItemPositionSize==ITEM2(13,259)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[MinoPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Hound Pet
	else if (IsItemPositionSize==ITEM2(13,260) || IsItemPositionSize==ITEM2(13,261)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[HoundPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Trive Pet
	else if (IsItemPositionSize==ITEM2(13,262) || IsItemPositionSize==ITEM2(13,263)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[TrivePetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Vogan Pet
	else if (IsItemPositionSize==ITEM2(13,264) || IsItemPositionSize==ITEM2(13,265)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[VoganPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Cyclop Pet
	else if (IsItemPositionSize==ITEM2(13,266) || IsItemPositionSize==ITEM2(13,267)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[CyclopPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Bonf Pet
	else if (IsItemPositionSize==ITEM2(13,270) || IsItemPositionSize==ITEM2(13,271)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[BonfPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Hawk Pet
	else if (IsItemPositionSize==ITEM2(13,272) || IsItemPositionSize==ITEM2(13,273)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[HawkPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Mut Pet
	else if (IsItemPositionSize==ITEM2(13,274)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[MutPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Mut Pet (Evo)
	else if (IsItemPositionSize==ITEM2(13,275)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[eMutPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Mantis Pet
	else if (IsItemPositionSize==ITEM2(13,278) || IsItemPositionSize==ITEM2(13,279)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[MantisPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Scolpy Pet
	else if (IsItemPositionSize==ITEM2(13,280) || IsItemPositionSize==ITEM2(13,281)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[ScolpyPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Chafer Pet
	else if (IsItemPositionSize==ITEM2(13,282) || IsItemPositionSize==ITEM2(13,283)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[ChaferPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Cosplay Girl Pet
	else if (IsItemPositionSize==ITEM2(13,290) || IsItemPositionSize==ITEM2(13,291)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[CosplayGirlPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Cheer Girl Pet
	else if (IsItemPositionSize==ITEM2(13,292) || IsItemPositionSize==ITEM2(13,293)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[CheerGirlPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Sporty Girl Pet
	else if (IsItemPositionSize==ITEM2(13,294) || IsItemPositionSize==ITEM2(13,295)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[SportyGirlPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Baal Pet
	else if (IsItemPositionSize==ITEM2(13,296) || IsItemPositionSize==ITEM2(13,297)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[BaalPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Gaap Pet
	else if (IsItemPositionSize==ITEM2(13,298) || IsItemPositionSize==ITEM2(13,299) || IsItemPositionSize==ITEM2(13,300) || IsItemPositionSize==ITEM2(13,301)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[GaapPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Frozen Pet
	else if (IsItemPositionSize==ITEM2(13,302) || IsItemPositionSize==ITEM2(13,303)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[FrozenPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Loor Pet
	else if (IsItemPositionSize==ITEM2(13,304) || IsItemPositionSize==ITEM2(13,305)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[LoorPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
	//-> Purssil Pet
	else if (IsItemPositionSize==ITEM2(13,306) || IsItemPositionSize==ITEM2(13,307)) 
	{
        _asm 
		{
			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[PurssilPetScale]
			FSTP DWORD PTR DS:[EDX+0x60]
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
	}
	//--
    else 
	{
        _asm 
		{
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextItemPositionSize
		}
    }
}
//--
void InitBows()
{
	SetCompleteHook(0xE9,0x005CD07D,CustomItemPosition);
	SetCompleteHook(0xE9,0x005CF11D,CustomItemPositionSize);

	//Fix Reload Arrow
	SetCompleteHook(0xE8,0x5913D0+0xDB ,&FixBowArrow);
	SetCompleteHook(0xE8,0x5913D0+0xF7 ,&FixBowArrow);
	SetCompleteHook(0xE8,0x5A05C0+0x92 ,&FixBowArrow);
	SetCompleteHook(0xE8,0x5A05C0+0x1B5,&FixBowArrow);
	SetCompleteHook(0xE8,0x5B5FC0+0xD34,&FixBowArrow);
	SetCompleteHook(0xE8,0x7E04B0+0xF8 ,&FixBowArrow);
	//--
	SetRange((LPVOID)iBowAddSkillEffect, 6, ASM::NOP);
	SetJmp((LPVOID)iBowAddSkillEffect, cBowAddSkillEffect);
	// ----
	SetCompleteHook(0xE9, iBowAddInventoryPos, cBowAddInventoryPos);
	// ----
	for (int i = 0; i < 6; i++)
	{
		SetByte(0x0056595E + i, 0x90);
	}
	// ----
	SetRange((LPVOID)iBowAddPlayerDimension, 7, ASM::NOP);
	SetJmp((LPVOID)iBowAddPlayerDimension, cBowAddPlayerDimension);
	// ----
    SetRange((LPVOID)iCrossAddSkillEffect, 6, ASM::NOP);
    SetJmp((LPVOID)iCrossAddSkillEffect, cCrossAddSkillEffect);

	SetRange((LPVOID)iCrossBowAddPlayerDimension, 6, ASM::NOP);
	SetJmp((LPVOID)iCrossBowAddPlayerDimension, cCrossBowAddPlayerDimension);
}