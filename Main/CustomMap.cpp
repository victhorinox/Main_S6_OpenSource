#include "stdafx.h"
#include "CustomMap.h"
#include "Defines.h"
#include "TMemory.h"
#include "Import.h"
#include "Interface.h"

CCustomMap gCustomMap;

char * Map82 = "Map82.tga";
char * Map83 = "Map83.tga";
char * Map84 = "Map84.tga";
char * Map85 = "Map85.tga";
char * Map86 = "Map86.tga";
char * Map87 = "Map87.tga";
char * Map88 = "Map88.tga";
char * Map89 = "Map89.tga";
char * Map90 = "Map90.tga";
char * Map91 = "Acheron.tga";
char * Map92 = "Map92.tga";
char * Map93 = "Map93.tga";
char * Map94 = "Map94.tga";
char * Map95 = "Deventer.tga";
char * Map96 = "Map96.tga";
char * Map97 = "Map97.tga";
char * Map98 = "Map98.tga";
char * Map99 = "Map99.tga";
//--
char * Map100 = "Uruk.tga";
char * Map110 = "Nars.tga";
char * Map112 = "Ferea.tga";
char * Map113 = "Nixies.tga";
char * Map121 = "Deep.tga";
char * Map123 = "Darkness.tga";
char * Map124 = "Mines.tga";
char * Map131 = "Abyss.tga";
char * Map132 = "Canyon.tga";
char * Map133 = "Icarus.tga";
char * Map134 = "Temple.tga";
char * Map135 = "GrayAida.tga";

char* LoadMapName(signed int MapNumber)
{
	if (MapNumber >= 82 && MapNumber <= 135)
	{
		return pGetTextLine(pTextLineThis, (3160 + MapNumber - 82));
	}
	return pMapName(MapNumber);
}

Naked(LoadInterfaceMapName)
{
	_asm
	{
		//hook
			MOV DWORD PTR SS:[EBP-0x848],0x51//ok
			PUSH 0x00D25498							
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//-> Map82
			MOV DWORD PTR SS : [EBP - 0x848], 0x52//ok
			PUSH Map82
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map83
			MOV DWORD PTR SS : [EBP - 0x848], 0x53//ok
			PUSH Map83
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map84
			MOV DWORD PTR SS : [EBP - 0x848], 0x54//ok
			PUSH Map84							
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map85
			MOV DWORD PTR SS : [EBP - 0x848], 0x55//ok
			PUSH Map85							
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map86
			MOV DWORD PTR SS : [EBP - 0x848], 0x56//ok
			PUSH Map86							
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map87
			MOV DWORD PTR SS : [EBP - 0x848], 0x57//ok
			PUSH Map87					
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map88
			MOV DWORD PTR SS : [EBP - 0x848], 0x58//ok
			PUSH Map88					
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map89
			MOV DWORD PTR SS : [EBP - 0x848], 0x59//ok
			PUSH Map89					
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map90
			MOV DWORD PTR SS : [EBP - 0x848], 0x5A//ok
			PUSH Map90					
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map91
			MOV DWORD PTR SS : [EBP - 0x848], 0x5B//ok
			PUSH Map91					
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map92
			MOV DWORD PTR SS : [EBP - 0x848], 0x5C//ok
			PUSH Map92					
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map93
			MOV DWORD PTR SS : [EBP - 0x848], 0x5D//ok
			PUSH Map93					
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map94
			MOV DWORD PTR SS : [EBP - 0x848], 0x5E//ok
			PUSH Map94					
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map95
			MOV DWORD PTR SS : [EBP - 0x848], 0x5F//ok
			PUSH Map95				
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map96
			MOV DWORD PTR SS : [EBP - 0x848], 0x60//pk
			PUSH Map96					
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map97
			MOV DWORD PTR SS : [EBP - 0x848], 0x61//ok
			PUSH Map97
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map98
			MOV DWORD PTR SS : [EBP - 0x848], 0x62//ok
			PUSH Map98					
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map99
			MOV DWORD PTR SS : [EBP - 0x848], 0x63//ok
			PUSH Map99					
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//-> Map 100 Uruk
			MOV DWORD PTR SS:[EBP-0x848],0x64
		PUSH Map100
		LEA EAX,DWORD PTR SS:[EBP-0x28]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		PUSH ECX
		CALL InterfaceLoad1
		ADD ESP,0xC
		MOV DWORD PTR SS:[EBP-0xA74],EAX
		MOV EDX,DWORD PTR SS:[EBP-0xA74]
		MOV DWORD PTR SS:[EBP-0xA78],EDX
		MOV BYTE PTR SS:[EBP-0x4],0x43
		MOV EAX,DWORD PTR SS:[EBP-0xA78]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x848]
		PUSH ECX
		MOV ECX,DWORD PTR SS:[EBP-0x868]
		ADD ECX,0x4
		CALL InterfaceLoad2
		MOV ECX,EAX
		CALL InterfaceLoad3
		MOV BYTE PTR SS:[EBP-0x4],0x2
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		CALL InterfaceLoad4
		MOV DWORD PTR SS:[EBP-0x4],-0x1
		LEA ECX,DWORD PTR SS:[EBP-0x28]
		// ----
		MOV DWORD PTR SS:[EBP-0x848],0x6E
		PUSH Map110
		LEA EAX,DWORD PTR SS:[EBP-0x28]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		PUSH ECX
		CALL InterfaceLoad1
		ADD ESP,0xC
		MOV DWORD PTR SS:[EBP-0xA74],EAX
		MOV EDX,DWORD PTR SS:[EBP-0xA74]
		MOV DWORD PTR SS:[EBP-0xA78],EDX
		MOV BYTE PTR SS:[EBP-0x4],0x43
		MOV EAX,DWORD PTR SS:[EBP-0xA78]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x848]
		PUSH ECX
		MOV ECX,DWORD PTR SS:[EBP-0x868]
		ADD ECX,0x4
		CALL InterfaceLoad2
		MOV ECX,EAX
		CALL InterfaceLoad3
		MOV BYTE PTR SS:[EBP-0x4],0x2
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		CALL InterfaceLoad4
		MOV DWORD PTR SS:[EBP-0x4],-0x1
		LEA ECX,DWORD PTR SS:[EBP-0x28]
		// ----
		MOV DWORD PTR SS:[EBP-0x848],0x70
		PUSH Map112
		LEA EAX,DWORD PTR SS:[EBP-0x28]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		PUSH ECX
		CALL InterfaceLoad1
		ADD ESP,0xC
		MOV DWORD PTR SS:[EBP-0xA74],EAX
		MOV EDX,DWORD PTR SS:[EBP-0xA74]
		MOV DWORD PTR SS:[EBP-0xA78],EDX
		MOV BYTE PTR SS:[EBP-0x4],0x43
		MOV EAX,DWORD PTR SS:[EBP-0xA78]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x848]
		PUSH ECX
		MOV ECX,DWORD PTR SS:[EBP-0x868]
		ADD ECX,0x4
		CALL InterfaceLoad2
		MOV ECX,EAX
		CALL InterfaceLoad3
		MOV BYTE PTR SS:[EBP-0x4],0x2
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		CALL InterfaceLoad4
		MOV DWORD PTR SS:[EBP-0x4],-0x1
		LEA ECX,DWORD PTR SS:[EBP-0x28]
		// ----
		MOV DWORD PTR SS:[EBP-0x848],0x71
		PUSH Map113
		LEA EAX,DWORD PTR SS:[EBP-0x28]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		PUSH ECX
		CALL InterfaceLoad1
		ADD ESP,0xC
		MOV DWORD PTR SS:[EBP-0xA74],EAX
		MOV EDX,DWORD PTR SS:[EBP-0xA74]
		MOV DWORD PTR SS:[EBP-0xA78],EDX
		MOV BYTE PTR SS:[EBP-0x4],0x43
		MOV EAX,DWORD PTR SS:[EBP-0xA78]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x848]
		PUSH ECX
		MOV ECX,DWORD PTR SS:[EBP-0x868]
		ADD ECX,0x4
		CALL InterfaceLoad2
		MOV ECX,EAX
		CALL InterfaceLoad3
		MOV BYTE PTR SS:[EBP-0x4],0x2
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		CALL InterfaceLoad4
		MOV DWORD PTR SS:[EBP-0x4],-0x1
		LEA ECX,DWORD PTR SS:[EBP-0x28]
		// ----
		MOV DWORD PTR SS:[EBP-0x848],0x78
		PUSH Map121
		LEA EAX,DWORD PTR SS:[EBP-0x28]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		PUSH ECX
		CALL InterfaceLoad1
		ADD ESP,0xC
		MOV DWORD PTR SS:[EBP-0xA74],EAX
		MOV EDX,DWORD PTR SS:[EBP-0xA74]
		MOV DWORD PTR SS:[EBP-0xA78],EDX
		MOV BYTE PTR SS:[EBP-0x4],0x43
		MOV EAX,DWORD PTR SS:[EBP-0xA78]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x848]
		PUSH ECX
		MOV ECX,DWORD PTR SS:[EBP-0x868]
		ADD ECX,0x4
		CALL InterfaceLoad2
		MOV ECX,EAX
		CALL InterfaceLoad3
		MOV BYTE PTR SS:[EBP-0x4],0x2
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		CALL InterfaceLoad4
		MOV DWORD PTR SS:[EBP-0x4],-0x1
		LEA ECX,DWORD PTR SS:[EBP-0x28]
		// ----
		MOV DWORD PTR SS:[EBP-0x848],0x7A
		PUSH Map123
		LEA EAX,DWORD PTR SS:[EBP-0x28]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		PUSH ECX
		CALL InterfaceLoad1
		ADD ESP,0xC
		MOV DWORD PTR SS:[EBP-0xA74],EAX
		MOV EDX,DWORD PTR SS:[EBP-0xA74]
		MOV DWORD PTR SS:[EBP-0xA78],EDX
		MOV BYTE PTR SS:[EBP-0x4],0x43
		MOV EAX,DWORD PTR SS:[EBP-0xA78]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x848]
		PUSH ECX
		MOV ECX,DWORD PTR SS:[EBP-0x868]
		ADD ECX,0x4
		CALL InterfaceLoad2
		MOV ECX,EAX
		CALL InterfaceLoad3
		MOV BYTE PTR SS:[EBP-0x4],0x2
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		CALL InterfaceLoad4
		MOV DWORD PTR SS:[EBP-0x4],-0x1
		LEA ECX,DWORD PTR SS:[EBP-0x28]
		// ----
		MOV DWORD PTR SS:[EBP-0x848],0x7B
		PUSH Map124
		LEA EAX,DWORD PTR SS:[EBP-0x28]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		PUSH ECX
		CALL InterfaceLoad1
		ADD ESP,0xC
		MOV DWORD PTR SS:[EBP-0xA74],EAX
		MOV EDX,DWORD PTR SS:[EBP-0xA74]
		MOV DWORD PTR SS:[EBP-0xA78],EDX
		MOV BYTE PTR SS:[EBP-0x4],0x43
		MOV EAX,DWORD PTR SS:[EBP-0xA78]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x848]
		PUSH ECX
		MOV ECX,DWORD PTR SS:[EBP-0x868]
		ADD ECX,0x4
		CALL InterfaceLoad2
		MOV ECX,EAX
		CALL InterfaceLoad3
		MOV BYTE PTR SS:[EBP-0x4],0x2
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		CALL InterfaceLoad4
		MOV DWORD PTR SS:[EBP-0x4],-0x1
		LEA ECX,DWORD PTR SS:[EBP-0x28]
		// ----
		MOV DWORD PTR SS:[EBP-0x848],0x82
		PUSH Map131
		LEA EAX,DWORD PTR SS:[EBP-0x28]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		PUSH ECX
		CALL InterfaceLoad1
		ADD ESP,0xC
		MOV DWORD PTR SS:[EBP-0xA74],EAX
		MOV EDX,DWORD PTR SS:[EBP-0xA74]
		MOV DWORD PTR SS:[EBP-0xA78],EDX
		MOV BYTE PTR SS:[EBP-0x4],0x43
		MOV EAX,DWORD PTR SS:[EBP-0xA78]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x848]
		PUSH ECX
		MOV ECX,DWORD PTR SS:[EBP-0x868]
		ADD ECX,0x4
		CALL InterfaceLoad2
		MOV ECX,EAX
		CALL InterfaceLoad3
		MOV BYTE PTR SS:[EBP-0x4],0x2
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		CALL InterfaceLoad4
		MOV DWORD PTR SS:[EBP-0x4],-0x1
		LEA ECX,DWORD PTR SS:[EBP-0x28]
		// ----
		MOV DWORD PTR SS:[EBP-0x848],0x83
		PUSH Map132
		LEA EAX,DWORD PTR SS:[EBP-0x28]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		PUSH ECX
		CALL InterfaceLoad1
		ADD ESP,0xC
		MOV DWORD PTR SS:[EBP-0xA74],EAX
		MOV EDX,DWORD PTR SS:[EBP-0xA74]
		MOV DWORD PTR SS:[EBP-0xA78],EDX
		MOV BYTE PTR SS:[EBP-0x4],0x43
		MOV EAX,DWORD PTR SS:[EBP-0xA78]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x848]
		PUSH ECX
		MOV ECX,DWORD PTR SS:[EBP-0x868]
		ADD ECX,0x4
		CALL InterfaceLoad2
		MOV ECX,EAX
		CALL InterfaceLoad3
		MOV BYTE PTR SS:[EBP-0x4],0x2
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		CALL InterfaceLoad4
		MOV DWORD PTR SS:[EBP-0x4],-0x1
		LEA ECX,DWORD PTR SS:[EBP-0x28]
		// ----
		MOV DWORD PTR SS:[EBP-0x848],0x84
		PUSH Map133
		LEA EAX,DWORD PTR SS:[EBP-0x28]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		PUSH ECX
		CALL InterfaceLoad1
		ADD ESP,0xC
		MOV DWORD PTR SS:[EBP-0xA74],EAX
		MOV EDX,DWORD PTR SS:[EBP-0xA74]
		MOV DWORD PTR SS:[EBP-0xA78],EDX
		MOV BYTE PTR SS:[EBP-0x4],0x43
		MOV EAX,DWORD PTR SS:[EBP-0xA78]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x848]
		PUSH ECX
		MOV ECX,DWORD PTR SS:[EBP-0x868]
		ADD ECX,0x4
		CALL InterfaceLoad2
		MOV ECX,EAX
		CALL InterfaceLoad3
		MOV BYTE PTR SS:[EBP-0x4],0x2
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		CALL InterfaceLoad4
		MOV DWORD PTR SS:[EBP-0x4],-0x1
		LEA ECX,DWORD PTR SS:[EBP-0x28]
		// ----
		MOV DWORD PTR SS:[EBP-0x848],0x85
		PUSH Map134
		LEA EAX,DWORD PTR SS:[EBP-0x28]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		PUSH ECX
		CALL InterfaceLoad1
		ADD ESP,0xC
		MOV DWORD PTR SS:[EBP-0xA74],EAX
		MOV EDX,DWORD PTR SS:[EBP-0xA74]
		MOV DWORD PTR SS:[EBP-0xA78],EDX
		MOV BYTE PTR SS:[EBP-0x4],0x43
		MOV EAX,DWORD PTR SS:[EBP-0xA78]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x848]
		PUSH ECX
		MOV ECX,DWORD PTR SS:[EBP-0x868]
		ADD ECX,0x4
		CALL InterfaceLoad2
		MOV ECX,EAX
		CALL InterfaceLoad3
		MOV BYTE PTR SS:[EBP-0x4],0x2
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		CALL InterfaceLoad4
		MOV DWORD PTR SS:[EBP-0x4],-0x1
		LEA ECX,DWORD PTR SS:[EBP-0x28]
		// ----
		MOV DWORD PTR SS:[EBP-0x848],0x86
		PUSH Map135
		LEA EAX,DWORD PTR SS:[EBP-0x28]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		PUSH ECX
		CALL InterfaceLoad1
		ADD ESP,0xC
		MOV DWORD PTR SS:[EBP-0xA74],EAX
		MOV EDX,DWORD PTR SS:[EBP-0xA74]
		MOV DWORD PTR SS:[EBP-0xA78],EDX
		MOV BYTE PTR SS:[EBP-0x4],0x43
		MOV EAX,DWORD PTR SS:[EBP-0xA78]
		PUSH EAX
		LEA ECX,DWORD PTR SS:[EBP-0x848]
		PUSH ECX
		MOV ECX,DWORD PTR SS:[EBP-0x868]
		ADD ECX,0x4
		CALL InterfaceLoad2
		MOV ECX,EAX
		CALL InterfaceLoad3
		MOV BYTE PTR SS:[EBP-0x4],0x2
		LEA ECX,DWORD PTR SS:[EBP-0x864]
		CALL InterfaceLoad4
		MOV DWORD PTR SS:[EBP-0x4],-0x1
		LEA ECX,DWORD PTR SS:[EBP-0x28]
		//--
		CALL InterfaceLoad4
		MOV ECX,DWORD PTR SS:[EBP-0xC]
		MOV DWORD PTR FS:[0x0],ECX

		MOV EDI,0x0047FD08
			JMP EDI

		InterfaceLoad1:
		MOV EDI,0x0047C220
			JMP EDI

		InterfaceLoad2:
		MOV EDI,0x00480160
			JMP EDI

		InterfaceLoad3:
		MOV EDI,0x00409AF0
			JMP EDI

		InterfaceLoad4:
		MOV EDI,0x00409AD0
			JMP EDI

			MOV ESP,EBP
			POP EBP
			RETN
		}
}

void LoadMapMusic(HDC Arg1)
{
 static PCHAR MusicID;
 // ----
 if(pPlayerState == 5)       // -> Si el PJ esta adentro del Juego
 {
  switch(pMapNumber)
  {
   case 82:        // -> Si el PJ esta en el Mapa Numero: 82
   {
		MusicID = "Data\\Custom\\Music\\Map82.mp3";
    // ----
    //if(*(BYTE*)(*(DWORD*)0x7BC4F04+14)) // -> Si el PJ esta en Zona Segura del Mapa 82 (Comienza a reproducirse la Musica)
    //{
		pWzAudioPlay(MusicID,0);
    //}
    //else        // -> Si el PJ NO esta en una Zona Segura del Mapa 82 (Se detiene la Musica)
    //{
     //pWzAudioStop(MusicID,0);
    //}
   }
   break;
   case 83:        // -> Si el PJ esta en el Mapa Numero: 83
   {
		MusicID = "Data\\Custom\\Music\\Map83.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 84:        // -> Si el PJ esta en el Mapa Numero: 84
   {
		MusicID = "Data\\Custom\\Music\\Map84.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 85:        // -> Si el PJ esta en el Mapa Numero: 85
   {
		MusicID = "Data\\Custom\\Music\\Map85.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 86:        // -> Si el PJ esta en el Mapa Numero: 86
   {
		MusicID = "Data\\Custom\\Music\\Map86.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 87:        // -> Si el PJ esta en el Mapa Numero: 87
   {
		MusicID = "Data\\Custom\\Music\\Map87.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 88:        // -> Si el PJ esta en el Mapa Numero: 88
   {
		MusicID = "Data\\Custom\\Music\\Map88.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 89:        // -> Si el PJ esta en el Mapa Numero: 89
   {
		MusicID = "Data\\Custom\\Music\\Map89.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 90:        // -> Si el PJ esta en el Mapa Numero: 90
   {
		MusicID = "Data\\Custom\\Music\\Map90.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 91:        // -> Si el PJ esta en el Mapa Numero: 91
   {
		MusicID = "Data\\Music\\Acheron.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 92:        // -> Si el PJ esta en el Mapa Numero: 92
   {
		MusicID = "Data\\Custom\\Music\\Map92.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 93:        // -> Si el PJ esta en el Mapa Numero: 93
   {
		MusicID = "Data\\Custom\\Music\\Map93.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 94:        // -> Si el PJ esta en el Mapa Numero: 94
   {
		MusicID = "Data\\Custom\\Music\\Map94.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 95:        // -> Si el PJ esta en el Mapa Numero: 95
   {
		MusicID = "Data\\Custom\\Music\\Map95.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 96:        // -> Si el PJ esta en el Mapa Numero: 96
   {
		MusicID = "Data\\Custom\\Music\\Map96.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 97:        // -> Si el PJ esta en el Mapa Numero: 97
   {
		MusicID = "Data\\Custom\\Music\\Map97.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 98:        // -> Si el PJ esta en el Mapa Numero: 98
   {
		MusicID = "Data\\Custom\\Music\\Map98.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 99:        // -> Si el PJ esta en el Mapa Numero: 99
   {
		MusicID = "Data\\Custom\\Music\\Map99.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 100:
			{
				MusicID = "Data\\Music\\Uruk.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 110:
			{
				MusicID = "Data\\Music\\Nars.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 112:
			{
				MusicID = "Data\\Music\\Ferea.mp3";
					pWzAudioPlay(MusicID,0);
			}
			break;
			case 113:
			{
				MusicID = "Data\\Music\\Nixies.mp3";
				pWzAudioPlay(MusicID,0);
			}
			case 120:
			{
				MusicID = "Data\\Music\\Dungeon.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 122:
			{
				MusicID = "Data\\Music\\Darkness.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 123:
			{
				MusicID = "Data\\Music\\KuberaMine.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 130:
			{
				MusicID = "Data\\Music\\Atlans.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 131:
			{
				MusicID = "Data\\Music\\ScorchedCanyon.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 132:
			{
				MusicID = "Data\\Music\\Icarus.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 133:
			{
				MusicID = "Data\\Music\\Temple.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 134:
			{
				MusicID = "Data\\Music\\Aida.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
  }
 }
 // ----
 pLoadGameStuffs(Arg1);
}

void CCustomMap::Load()
{
	SetOp((LPVOID)0x00520ECF,(LPVOID)LoadMapName,ASM::CALL);
	SetOp((LPVOID)0x00520F1F,(LPVOID)LoadMapName,ASM::CALL);
	SetOp((LPVOID)0x0063E743,(LPVOID)LoadMapName,ASM::CALL);
	SetOp((LPVOID)0x00640EB2,(LPVOID)LoadMapName,ASM::CALL);
	SetOp((LPVOID)0x007D2DD9,(LPVOID)LoadMapName,ASM::CALL);
	SetOp((LPVOID)0x007E6C0F,(LPVOID)LoadMapName,ASM::CALL);
	SetOp((LPVOID)0x0084AEF7,(LPVOID)LoadMapName,ASM::CALL);

	SetRange((LPVOID)0x0047FC85,131,ASM::NOP);
	SetOp((LPVOID)0x0047FC85,(LPVOID)LoadInterfaceMapName,ASM::JMP);

	//Bypass in terrains files
	SetByte((LPVOID)0x0062EBF8,0xEB);
	SetByte((LPVOID)0x0062EBFE,0xEB);
	SetByte((LPVOID)0x0062EE42,0xEB);
	SetByte((LPVOID)0x0062EE48,0xEB);
	SetByte((LPVOID)0x0062EEE5,0xEB);
	SetByte((LPVOID)0x0062EEEB,0xEB);
	
	//Increase terrains amount
	SetByte((LPVOID)0x0062EBF7,0x69);
	SetByte((LPVOID)0x0062EE41,0x69);
	SetByte((LPVOID)0x0062EEE4,0x69);

	//Set Music
	SetOp((LPVOID)0x004DADA4,(LPVOID)LoadMapMusic,ASM::CALL);
}