#pragma once

#define MAX_CUSTOM_ITEM_INFO 1000

struct CUSTOM_ITEM_INFO_EX
{
	int Index;
	int ItemType;
	int ItemIndex;
	int DamageMin;
	int DamageMax;
	int Defense;
	int MagicDefense;
};

class CCustomItemInfo
{
public:
	CCustomItemInfo();
	virtual ~CCustomItemInfo();
	void Init();
	void Load(CUSTOM_ITEM_INFO_EX* info);
	void SetInfo(CUSTOM_ITEM_INFO_EX info);
	CUSTOM_ITEM_INFO_EX* GetInfo(int index);
	CUSTOM_ITEM_INFO_EX* GetInfoByItem(int ItemIndex);
	bool isCustomItem(int ItemIndex,float* ItemColor);
public:
	CUSTOM_ITEM_INFO_EX m_CustomItemInfoEx[MAX_CUSTOM_ITEM_INFO];
};

extern CCustomItemInfo gCustomItemInfo;