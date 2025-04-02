#pragma once 
#include "stdafx.h"
#include "Performance.h"
#include "Util.h"

__declspec(naked) void DelectlpViewPlayerOn()
{
	static DWORD Buff_lpViewPlayer = 0x0057D27F;

	_asm
	{
		CMP DWORD PTR SS:[EBP-0x4],0
		JMP [Buff_lpViewPlayer]
	}
}

__declspec(naked) void DelectlpViewPlayerOff()
{
	static DWORD Buff_lpViewPlayer = 0x0057D27F;

		_asm
		{
			CMP DWORD PTR SS:[EBP-0x4],400
			JMP [Buff_lpViewPlayer]
		}
}

void DelectlpViewPlayerOff_Hook()
{
	SetCompleteHook(0xE9, 0x0057D278, &DelectlpViewPlayerOff);
}

void DelectlpViewPlayerOn_Hook()
{
	SetCompleteHook(0xE9, 0x0057D278, &DelectlpViewPlayerOn);
}

__declspec(naked) void DelectEffectDynamicOn()
{
	static DWORD Buff_EffectDynamic = 0x0074CD57;

	_asm
	{
		CMP DWORD PTR SS:[EBP-0x4],0
		JMP [Buff_EffectDynamic]
	}
}

__declspec(naked) void DelectEffectDynamicOff()
{
	static DWORD Buff_EffectDynamic = 0x0074CD57;

	_asm
	{
		CMP DWORD PTR SS:[EBP-0x4],0x0BB8
		JMP [Buff_EffectDynamic]
	}
}

void DelectEffectDynamicOff_Hook()
{
	SetCompleteHook(0xE9, 0x0074CD50, &DelectEffectDynamicOff);
}

void DelectEffectDynamicOn_Hook()
{
	SetCompleteHook(0xE9, 0x0074CD50, &DelectEffectDynamicOn);
}

__declspec(naked) void DelectEffectStaticOn()
{
	static DWORD Buff_EffectStatic = 0x0077132F;

	_asm
	{
		CMP DWORD PTR SS:[EBP-0x4],0
		JMP [Buff_EffectStatic]
	}
}

__declspec(naked) void DelectEffectStaticOff()
{
	static DWORD Buff_EffectStatic = 0x0077132F;

		_asm
		{
			CMP DWORD PTR SS:[EBP-0x4],0x3E8
			JMP [Buff_EffectStatic]
		}
}

void DelectEffectStaticOn_Hook()
{
	SetCompleteHook(0xE9, 0x00771328, &DelectEffectStaticOn);
}

void DelectEffectStaticOff_Hook()
{
	SetCompleteHook(0xE9, 0x00771328, &DelectEffectStaticOff);
}

__declspec(naked) void DelectEffectSkillOn()
{
	static DWORD Buff_EffectSkill = 0x0072D1D3;

	_asm
	{
		CMP DWORD PTR SS:[EBP-0x4],0
		JMP [Buff_EffectSkill]
	}
}

__declspec(naked) void DelectEffectSkillOff()
{
	static DWORD Buff_EffectSkill = 0x0072D1D3;

	_asm
	{
		CMP DWORD PTR SS:[EBP-0x4],0x1F4
		JMP [Buff_EffectSkill]
	}
}

void DelectEffectSkillOn_Hook()
{
	SetCompleteHook(0xE9, 0x0072D1CC, &DelectEffectSkillOn);
}

void DelectEffectSkillOff_Hook()
{
	SetCompleteHook(0xE9, 0x0072D1CC, &DelectEffectSkillOff);
}