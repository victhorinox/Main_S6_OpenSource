#include "stdafx.h"
#include "MemScript.h"
#include "Util.h"
#include "Defines.h"
#include "Reconnect.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "Import.h"
#include "Defines.h"

CCustomMonster gCustomMonster;

CCustomMonster::CCustomMonster()
{
	this->Init();
}

CCustomMonster::~CCustomMonster()
{
	
}

void CCustomMonster::Init()
{
	for (int i=0; i<MAX_CUSTOMMONSTER; i++)
	{
		this->m_CustomMonster[i].Index = -1;
	}
	memset(this->m_NpcName,0,sizeof(this->m_NpcName));
}

void CCustomMonster::Load(CUSTOMMONSTER_DATA* info)
{
	for (int i=0; i<MAX_CUSTOMMONSTER; i++)
	{
		this->SetInfo(info[i]);
	}
}

void CCustomMonster::SetInfo(CUSTOMMONSTER_DATA info)
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOMMONSTER)
	{
		return;
	}

	this->m_CustomMonster[info.Index] = info;
}

CUSTOMMONSTER_DATA* CCustomMonster::GetInfoByMonsterID(int MonsterID)
{
	for(int n=0;n < MAX_CUSTOMMONSTER;n++)
	{
		CUSTOMMONSTER_DATA* lpInfo = this->GetInfoByIndex(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(MonsterID == lpInfo->ID)
		{
			return lpInfo;
		}
	}

	return 0;
}

CUSTOMMONSTER_DATA* CCustomMonster::GetInfoByIndex(int index)
{
	if(index < 0 || index >= MAX_CUSTOMMONSTER)
	{
		return 0;
	}

	if(this->m_CustomMonster[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomMonster[index];
}

void CCustomMonster::InitMonster()
{
	SetCompleteHook(0xE8, 0x0061FE3F, &LoadMonsterBMD);
	SetCompleteHook(0xE8, 0x0061FEEA, &LoadMonsterTexture);

	//Limit kill
	SetByte(0x00559B85,0xFF);
	SetByte(0x00559B86,0xFF);

	SetCompleteHook(0xE8, 0x004E199D, &ShowMonster);
	SetCompleteHook(0xE8, 0x00587049, &ShowMonster);
	SetCompleteHook(0xE8, 0x00590CCC, &ShowMonster);
	SetCompleteHook(0xE8, 0x005BBEE6, &ShowMonster);
	SetCompleteHook(0xE8, 0x0064229D, &ShowMonster);
	SetCompleteHook(0xE8, 0x00642D51, &ShowMonster);
	SetCompleteHook(0xE8, 0x00643229, &ShowMonster);
	SetCompleteHook(0xE8, 0x0065EA86, &ShowMonster);
	SetCompleteHook(0xE8, 0x00911A53, &ShowMonster);
	SetCompleteHook(0xE8, 0x00911A6D, &ShowMonster);
	SetCompleteHook(0xE8, 0x00911A87, &ShowMonster);
	SetCompleteHook(0xE8, 0x00911AA1, &ShowMonster);
	SetCompleteHook(0xE8, 0x00911ABB, &ShowMonster);

	SetCompleteHook(0xFF, 0x0058101A, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x0058105B, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x0058109C, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x005810DD, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x0058111E, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x0058115F, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x005811A0, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x005811E1, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x00581222, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x00581263, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x005812A8, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x005812ED, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x0058132E, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x0058136F, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x005813B4, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x005813F9, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x00586859, &this->SetMainAttribute);
}

void CCustomMonster::LoadMonsterBMD(signed int Class, char* FileDir, char* BmdName, signed int BmdType)
{
	int MonsterID = Class - MAX_MONSTER_MODEL;
	// ----
	CUSTOMMONSTER_DATA* lpInfo = gCustomMonster.GetInfoByMonsterID(MonsterID);
	
	if (lpInfo == 0)
	{
		pLoadMonsterBMD(Class, FileDir, BmdName, BmdType);
	}
	else
	{
		pLoadMonsterBMD(Class, lpInfo->Dir, lpInfo->BMDFile, -1);
	}
}

void CCustomMonster::LoadMonsterTexture(signed int Class, char* FolderDir, int a3, int a4)
{
	int MonsterID = Class - MAX_MONSTER_MODEL;

	CUSTOMMONSTER_DATA* lpInfo = gCustomMonster.GetInfoByMonsterID(MonsterID);

	if (lpInfo == 0)
	{
		pLoadTexture(Class, FolderDir, a3, a4,0);
	}
	else
	{
		pLoadTexture(Class, lpInfo->Folder, a3, a4,0);
	}
}

int CCustomMonster::ShowMonster(int Class, int a2, int a3, int a4)
{

	for (int i = 0; i < MAX_CUSTOMMONSTER; i++)
	{
		if (gCustomMonster.m_CustomMonster[i].Index == -1)
		{
			continue;
		}
		if (Class != gCustomMonster.m_CustomMonster[i].ID)
		{
			continue;
		}
	
		pLoadMonsterID(Class);

		DWORD ObjectStruct = pViewObject(a4, Class + MAX_MONSTER_MODEL, a2, a3, 0.0);

		ObjectPreview* Object = &*(ObjectPreview*)ObjectStruct;

		memcpy(Object->Name, gCustomMonster.m_CustomMonster[i].Name, sizeof(gCustomMonster.m_CustomMonster[i].Name));

		NPCNAME_DATA* NpcName = gNPCName.GetNPCName(Class, pMapNumber, Object->RespawnPosX, Object->RespawnPosY);

		if (NpcName != 0)
		{
			sprintf(Object->Name, NpcName->Name);
		}

		switch (gCustomMonster.m_CustomMonster[i].Type)
		{
			case CUSTOM_MONSTER_TYPE_NPC:
				*(BYTE*)(ObjectStruct + 800) = emNPC;
				break;
			case CUSTOM_MONSTER_TYPE_MOB:
				*(BYTE*)(ObjectStruct + 800) = emMonster;
				break;
			default:
				*(BYTE*)(ObjectStruct + 800) = emNone;
				break;
		}

		*(float *)(ObjectStruct + 872) = gCustomMonster.m_CustomMonster[i].Size;

		Object->ID = Class;

		*(BYTE*)(ObjectStruct + 798) = 0;

		Object->Unknown128 = *(DWORD*)0x879343C;
			
		return ObjectStruct;
	}

	return (int)pShowMonster(Class, a2, a3, a4);

	
}

void CCustomMonster::SetMainAttribute(lpViewObj Object, int MonsterID)
{
	sub_580BB0((int)Object,MonsterID);

	NPCNAME_DATA* NpcName = gNPCName.GetNPCName(MonsterID, pMapNumber, Object->RespawnPosX, Object->RespawnPosY);

	if (NpcName != 0)
	{
		sprintf(Object->Name, NpcName->Name);
	}
}