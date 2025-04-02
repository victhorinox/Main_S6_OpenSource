#include "stdafx.h"
#include "Defines.h"
#include "CustomItemPower.h"
//#include "InfoLog.h"

CCustomItemInfo gCustomItemInfo;

CCustomItemInfo::CCustomItemInfo() // OK
{
	this->Init();
}

CCustomItemInfo::~CCustomItemInfo() // OK
{

}

void CCustomItemInfo::Init() // OK
{
	for(int n=0;n < MAX_CUSTOM_ITEM_INFO;n++)
	{
		this->m_CustomItemInfoEx[n].Index = -1;
	}
}

void CCustomItemInfo::Load(CUSTOM_ITEM_INFO_EX* info) // OK
{
	for(int n=0;n < MAX_CUSTOM_ITEM_INFO;n++)
	{
		this->SetInfo(info[n]);
		
	}
}

void CCustomItemInfo::SetInfo(CUSTOM_ITEM_INFO_EX info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_ITEM_INFO)
	{
		return;
	}

	this->m_CustomItemInfoEx[info.Index] = info;
}

CUSTOM_ITEM_INFO_EX* CCustomItemInfo::GetInfo(int index) // OK
{
	if(index < 0 || index >= MAX_CUSTOM_ITEM_INFO)
	{
		return 0;
	}

	if(this->m_CustomItemInfoEx[index].Index != index)
	{
		return 0;
	}
	
	return &this->m_CustomItemInfoEx[index];
}

CUSTOM_ITEM_INFO_EX* CCustomItemInfo::GetInfoByItem(int ItemIndex) // OK
{
	for(int n=0;n < MAX_CUSTOM_ITEM_INFO;n++)
	{
		CUSTOM_ITEM_INFO_EX* lpInfo = this->GetInfo(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(ITEM(lpInfo->ItemType,lpInfo->ItemIndex) == ItemIndex)
		{
		//	gInfoLog.Output(LOG_KILLERS,"item %d,%d",this->m_CustomItemInfoEx[n].ItemType,this->m_CustomItemInfoEx[n].ItemIndex);
			return lpInfo;
		}
	}

	return 0;
}

bool CCustomItemInfo::isCustomItem(int ItemIndex,float* ItemColor) // OK
{
	return true;
}