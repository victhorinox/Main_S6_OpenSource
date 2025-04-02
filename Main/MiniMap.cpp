#include "stdafx.h"
#include "MiniMap.h"
#include "Import.h"
#include "Offset.h"
#include "Util.h"

bool MiniMapTable[MAX_MINI_MAP];

void InitMiniMap() // OK
{
	memset(MiniMapTable, 0, sizeof(MiniMapTable));

	MemorySet(0x0063E7E4, 0x90, 0x02); //ok

	SetCompleteHook(0xFF, 0x0062EB26, &MiniMapCore); //ok

	SetCompleteHook(0xE8, 0x00888D5F, &MiniMapLoad); //ok

	SetCompleteHook(0xFF, 0x00886CD7, &MiniMapCheck); //ok

	SetCompleteHook(0xFF, 0x007D3CBD, &MiniMapCheck); //ok
}

void MiniMapCore() // OK
{
	((void(*)())0x00629180)();

	MiniMapLoad();
}

void MiniMapLoad() // OK
{
	if (pMapNumber < MAX_MINI_MAP)
	{
		char buff[32];

		wsprintf(buff, "World%d\\Map1.jpg", (pMapNumber+1));

		if (MiniMapFileCheck(pMapNumber) != 0)
		{
			MiniMapTable[pMapNumber] = 1;
			pLoadImageJPG(buff, 0x7B7A, 0x2601, 0x2900, 1, 0);
		}
	}
}

bool MiniMapCheck(int map) // OK
{
	if (map == 30 || (map < MAX_MINI_MAP && MiniMapTable[map] != 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool MiniMapFileCheck(int map) // OK
{
	if (map == 30) { return 1; }

	char buff[64];

	wsprintf(buff, ".\\Data\\World%d\\Map1.ozj", (map + 1));

	FILE* file;

	if (fopen_s(&file, buff, "r") != 0)
	{
		return 0;
	}
	else
	{
		fclose(file);
		return 1;
	}
}