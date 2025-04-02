#pragma once

#define MAX_PET_ITEM		300

struct CUSTOM_PET_INFO
{
    int Index;
    int ItemIndex;
	int IndexInventory;
    int PetType;
    float Scale_View;
    float Scale_Drop;
    int FenrrirEffect;
    char ModelName[50];
};


class cCustomPet
{
public:
	cCustomPet();
	virtual ~cCustomPet();
	void Init();
	void Load(CUSTOM_PET_INFO* info);
	int GetInfoByItem(int ItemIndex);
	int GetInfoByItemInventory(int ItemIndex);
	CUSTOM_PET_INFO* GetInfoByItem2(int ItemIndex);
	int GetInfoPetType(int ItemIndex); // OK
	int GetInfoPetEffect(int ItemIndex); // OK
	float GetScaleDrop(int ItemIndex);
	float GetScaleView(int ItemIndex);
	bool CheckCustomPetByItem(int ItemIndex);
public:
	std::map<int, CUSTOM_PET_INFO> m_CustomPetInfo;
};

extern cCustomPet gCustomPet2;