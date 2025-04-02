#include "stdafx.h"
#include "Item.h"
#include "TMemory.h"
#include "Import.h"
#include "ItemNameColor.h"
#include "Util.h"
#include "Defines.h"
#include "Protect.h"
#include "CustomItemNameColor.h"

DWORD DivineWeapon_Buff=0;
DWORD DivineWeapon_Pointer=0;

__declspec(naked)void DivineWeapon()
{
	static DWORD DivineWeaponAdress1=0x007E785F;
	static DWORD DivineWeaponAdress2=0x007E7866;
	
	_asm
	{
		Mov DivineWeapon_Buff,Edx
		MOVSX EDX,WORD PTR SS:[EBP+0x8]
		mov DWORD PTR SS:[EBP+0x8],Edx
		mov DivineWeapon_Pointer,Edx
		Mov Edx,DivineWeapon_Buff
	}
	
	if(DivineWeapon_Pointer==0x13
		||DivineWeapon_Pointer==0x812
		||DivineWeapon_Pointer==0x0A0A
		||DivineWeapon_Pointer==0x40D
		||DivineWeapon_Pointer==0x0A24
		//--
		||DivineWeapon_Pointer==ITEM(0,51)	//-> Blessed Divine Sword of Archangel
		||DivineWeapon_Pointer==ITEM(0,60)	//-> Divine Claw of Archangel
		||DivineWeapon_Pointer==ITEM(0,61)	//-> Blessed Divine Claw of Archangel
		||DivineWeapon_Pointer==ITEM(0,76)	//-> Divine Short Sword of Archangel
		||DivineWeapon_Pointer==ITEM(0,77)	//-> Blessed Divine Short Sword of Archangel
		||DivineWeapon_Pointer==ITEM(2,25)	//-> Blessed Divine Scepter of Archangel
		||DivineWeapon_Pointer==ITEM(2,34)	//-> Divine Mace of Archangel
		||DivineWeapon_Pointer==ITEM(2,35)	//-> Blessed Divine Mace of Archangel
		||DivineWeapon_Pointer==ITEM(3,26)	//-> Divine Lance of Archangel
		||DivineWeapon_Pointer==ITEM(3,27)	//-> Blessed Divine Lance of Archangel
		||DivineWeapon_Pointer==ITEM(4,30)	//-> Blessed Divine Crossbow
		||DivineWeapon_Pointer==ITEM(5,49)	//-> Blessed Divine Staff
		||DivineWeapon_Pointer==ITEM(5,50)	//-> Blessed Divine Stick
		//--
		||DivineWeapon_Pointer==ITEM(12,200)
		||DivineWeapon_Pointer==ITEM(12,201)
		||DivineWeapon_Pointer==ITEM(12,202)
		||DivineWeapon_Pointer==ITEM(12,203)
		||DivineWeapon_Pointer==ITEM(12,204)
		||DivineWeapon_Pointer==ITEM(12,205)
		//--
		||DivineWeapon_Pointer==ITEM(12,206)
		||DivineWeapon_Pointer==ITEM(12,207)
		||DivineWeapon_Pointer==ITEM(12,208)
		||DivineWeapon_Pointer==ITEM(12,209)
		||DivineWeapon_Pointer==ITEM(12,210)
		||DivineWeapon_Pointer==ITEM(12,211)
		||DivineWeapon_Pointer==ITEM(12,212)
		//--
		||DivineWeapon_Pointer==ITEM(12,213)
		||DivineWeapon_Pointer==ITEM(12,214)
		||DivineWeapon_Pointer==ITEM(12,215)
		||DivineWeapon_Pointer==ITEM(12,216)
		||DivineWeapon_Pointer==ITEM(12,217)
		||DivineWeapon_Pointer==ITEM(12,218)
		||DivineWeapon_Pointer==ITEM(12,219)
		||DivineWeapon_Pointer==ITEM(12,220)
		||DivineWeapon_Pointer==ITEM(12,221)
		||DivineWeapon_Pointer==ITEM(12,222)
		||DivineWeapon_Pointer==ITEM(12,223)
		||DivineWeapon_Pointer==ITEM(12,224)
		||DivineWeapon_Pointer==ITEM(12,225)
		||DivineWeapon_Pointer==ITEM(12,226)
		||DivineWeapon_Pointer==ITEM(12,227)
		||DivineWeapon_Pointer==ITEM(12,228)
		||DivineWeapon_Pointer==ITEM(12,229)
		//--
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_01
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_02
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_03
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_04
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_05
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_06
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_07
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_08
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_09
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_10
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_11
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_12
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_13
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_14
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_15
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_16
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_17
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_18
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_19
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_20
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_21
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_22
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_23
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_24
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_25
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_26
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_27
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_28
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_29
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_30
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_31
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_32
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_33
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_34
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_35
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_36
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_37
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_38
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_39
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_40
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_41
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_42
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_43
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_44
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_45
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_46
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_47
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_48
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_49
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_50
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_51
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_52
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_53
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_54
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_55
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_56
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_57
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_58
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_59
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_60
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_61
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_62
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_63
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_64
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_65
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_66
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_67
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_68
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_69
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_70
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_71
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_72
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_73
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_74
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_75
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_76
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_77
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_78
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_79
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_80
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_81
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_82
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_83
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_84
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_85
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_86
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_87
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_88
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_89
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_90
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_91
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_92
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_93
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_94
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_95
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_96
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_97
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_98
		||DivineWeapon_Pointer==ItemNameColor.ItemColor_99)
		{
			_asm
			{
				Jmp DivineWeaponAdress1
			}
		}
		else
		{
			_asm
			{
				Jmp DivineWeaponAdress2
			}
		}
	}
	
	DWORD DropColorProtect;
	DWORD DropColorPointer;
	
__declspec(naked)void DropColor()
{
	_asm
	{
		Mov DropColorProtect,Eax
		MOV EDX,DWORD PTR SS:[EBP-0x18]
		Mov Eax,DWORD PTR DS:[EDX+0x30]
		Mov DropColorPointer,Eax
		Mov Eax,DropColorProtect
	}
	
	if(DropColorPointer==0x253B)
	{
		_asm{
			Mov DropColorPointer,0x005F47AA // Orange
			Jmp DropColorPointer
		}
	}
	else if(DropColorPointer==ITEM2(0,51))
	{
		_asm
		{
			Mov DropColorPointer,0x005F4918 // Divine
			Jmp DropColorPointer
		}
	}
	
	else if
		(DropColorPointer==ITEM2(14,14)	// Jewel of Chaos
		//--
		||DropColorPointer==ITEM2(14,176) // Death King's Bone
		||DropColorPointer==ITEM2(14,177) // Hell Maine's Leather
		||DropColorPointer==ITEM2(14,178) // Dark Phoenix Flame
		||DropColorPointer==ITEM2(14,179) // Death Beam Knight Soul
		//--
		||DropColorPointer==ITEM2(14,217) // Titan's Anger
		||DropColorPointer==ITEM2(14,218) // Tantalose's Punishment
		||DropColorPointer==ITEM2(14,219) // Erohim's Nightmare
		||DropColorPointer==ITEM2(14,220) // Hell Maine's Insanity
		||DropColorPointer==ITEM2(14,221) // Kundun's Greed
		//--
		||DropColorPointer==ITEM2(14,342) // Steel of Heaven
		||DropColorPointer==ITEM2(14,343) // Hammer of Archangel
		//--
		||DropColorPointer==ItemNameColor.ItemColor_01
		||DropColorPointer==ItemNameColor.ItemColor_02
		||DropColorPointer==ItemNameColor.ItemColor_03
		||DropColorPointer==ItemNameColor.ItemColor_04
		||DropColorPointer==ItemNameColor.ItemColor_05
		||DropColorPointer==ItemNameColor.ItemColor_06
		||DropColorPointer==ItemNameColor.ItemColor_07
		||DropColorPointer==ItemNameColor.ItemColor_08
		||DropColorPointer==ItemNameColor.ItemColor_09
		||DropColorPointer==ItemNameColor.ItemColor_10
		||DropColorPointer==ItemNameColor.ItemColor_11
		||DropColorPointer==ItemNameColor.ItemColor_12
		||DropColorPointer==ItemNameColor.ItemColor_13
		||DropColorPointer==ItemNameColor.ItemColor_14
		||DropColorPointer==ItemNameColor.ItemColor_15
		||DropColorPointer==ItemNameColor.ItemColor_16
		||DropColorPointer==ItemNameColor.ItemColor_17
		||DropColorPointer==ItemNameColor.ItemColor_18
		||DropColorPointer==ItemNameColor.ItemColor_19
		||DropColorPointer==ItemNameColor.ItemColor_20
		||DropColorPointer==ItemNameColor.ItemColor_21
		||DropColorPointer==ItemNameColor.ItemColor_22
		||DropColorPointer==ItemNameColor.ItemColor_23
		||DropColorPointer==ItemNameColor.ItemColor_24
		||DropColorPointer==ItemNameColor.ItemColor_25
		||DropColorPointer==ItemNameColor.ItemColor_26
		||DropColorPointer==ItemNameColor.ItemColor_27
		||DropColorPointer==ItemNameColor.ItemColor_28
		||DropColorPointer==ItemNameColor.ItemColor_29
		||DropColorPointer==ItemNameColor.ItemColor_30
		||DropColorPointer==ItemNameColor.ItemColor_31
		||DropColorPointer==ItemNameColor.ItemColor_32
		||DropColorPointer==ItemNameColor.ItemColor_33
		||DropColorPointer==ItemNameColor.ItemColor_34
		||DropColorPointer==ItemNameColor.ItemColor_35
		||DropColorPointer==ItemNameColor.ItemColor_36
		||DropColorPointer==ItemNameColor.ItemColor_37
		||DropColorPointer==ItemNameColor.ItemColor_38
		||DropColorPointer==ItemNameColor.ItemColor_39
		||DropColorPointer==ItemNameColor.ItemColor_40
		||DropColorPointer==ItemNameColor.ItemColor_41
		||DropColorPointer==ItemNameColor.ItemColor_42
		||DropColorPointer==ItemNameColor.ItemColor_43
		||DropColorPointer==ItemNameColor.ItemColor_44
		||DropColorPointer==ItemNameColor.ItemColor_45
		||DropColorPointer==ItemNameColor.ItemColor_46
		||DropColorPointer==ItemNameColor.ItemColor_47
		||DropColorPointer==ItemNameColor.ItemColor_48
		||DropColorPointer==ItemNameColor.ItemColor_49
		||DropColorPointer==ItemNameColor.ItemColor_50
		||DropColorPointer==ItemNameColor.ItemColor_51
		||DropColorPointer==ItemNameColor.ItemColor_52
		||DropColorPointer==ItemNameColor.ItemColor_53
		||DropColorPointer==ItemNameColor.ItemColor_54
		||DropColorPointer==ItemNameColor.ItemColor_55
		||DropColorPointer==ItemNameColor.ItemColor_56
		||DropColorPointer==ItemNameColor.ItemColor_57
		||DropColorPointer==ItemNameColor.ItemColor_58
		||DropColorPointer==ItemNameColor.ItemColor_59
		||DropColorPointer==ItemNameColor.ItemColor_60
		||DropColorPointer==ItemNameColor.ItemColor_61
		||DropColorPointer==ItemNameColor.ItemColor_62
		||DropColorPointer==ItemNameColor.ItemColor_63
		||DropColorPointer==ItemNameColor.ItemColor_64
		||DropColorPointer==ItemNameColor.ItemColor_65
		||DropColorPointer==ItemNameColor.ItemColor_66
		||DropColorPointer==ItemNameColor.ItemColor_67
		||DropColorPointer==ItemNameColor.ItemColor_68
		||DropColorPointer==ItemNameColor.ItemColor_69
		||DropColorPointer==ItemNameColor.ItemColor_70
		||DropColorPointer==ItemNameColor.ItemColor_71
		||DropColorPointer==ItemNameColor.ItemColor_72
		||DropColorPointer==ItemNameColor.ItemColor_73
		||DropColorPointer==ItemNameColor.ItemColor_74
		||DropColorPointer==ItemNameColor.ItemColor_75
		||DropColorPointer==ItemNameColor.ItemColor_76
		||DropColorPointer==ItemNameColor.ItemColor_77
		||DropColorPointer==ItemNameColor.ItemColor_78
		||DropColorPointer==ItemNameColor.ItemColor_79
		||DropColorPointer==ItemNameColor.ItemColor_80
		||DropColorPointer==ItemNameColor.ItemColor_81
		||DropColorPointer==ItemNameColor.ItemColor_82
		||DropColorPointer==ItemNameColor.ItemColor_83
		||DropColorPointer==ItemNameColor.ItemColor_84
		||DropColorPointer==ItemNameColor.ItemColor_85
		||DropColorPointer==ItemNameColor.ItemColor_86
		||DropColorPointer==ItemNameColor.ItemColor_87
		||DropColorPointer==ItemNameColor.ItemColor_88
		||DropColorPointer==ItemNameColor.ItemColor_89
		||DropColorPointer==ItemNameColor.ItemColor_90
		||DropColorPointer==ItemNameColor.ItemColor_91
		||DropColorPointer==ItemNameColor.ItemColor_92
		||DropColorPointer==ItemNameColor.ItemColor_93
		||DropColorPointer==ItemNameColor.ItemColor_94
		||DropColorPointer==ItemNameColor.ItemColor_95
		||DropColorPointer==ItemNameColor.ItemColor_96
		||DropColorPointer==ItemNameColor.ItemColor_97
		||DropColorPointer==ItemNameColor.ItemColor_98
		||DropColorPointer==ItemNameColor.ItemColor_99)
	{
		_asm
		{
			mov DropColorPointer,0x005F439E//Yellow
			jmp DropColorPointer
		}
	}
	else
	{
		_asm
		{
			Mov DropColorPointer,0x005F47BC//Next
			Jmp DropColorPointer
		}
	}
}

void InitCustomNameColor()
{
	SetRange((LPVOID)0x007E7827,4,ASM::NOP);
	SetOp((LPVOID)0x007E7827,(LPVOID)DivineWeapon,ASM::JMP);
	//--
	SetRange((LPVOID)0x005F479E,10,ASM::NOP);
	SetOp((LPVOID)0x005F479E,(LPVOID)DropColor,ASM::JMP);
}