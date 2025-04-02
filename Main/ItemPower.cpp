#include "stdafx.h"
#include "ItemPower.h"
#include "TMemory.h"
#include "Util.h"
#include "Defines.h"
#include "Import.h"
#include "Object.h"
#include "CustomItemPower.h"
//#include "InfoLog.h"

void SetNewOption(ObjectItem * lpItem, BYTE Option, BYTE Special, BYTE Value);

cItemInfoEx gItemInfoEx;

cItemInfoEx::cItemInfoEx() {

}

cItemInfoEx::~cItemInfoEx() {

}

void cItemInfoEx::Load() {

	SetOp((LPVOID)0x58B77E, SetNewOption, ASM::CALL);		//<- :c ?
	SetOp((LPVOID)0x5C7833, SetNewOption, ASM::CALL);		//<- :c ?
	SetOp((LPVOID)0x5C7D71, SetNewOption, ASM::CALL);		//<- :c ?
	SetOp((LPVOID)0x5C7F1B, SetNewOption, ASM::CALL);		//<- :c ?
	SetOp((LPVOID)0x5C80BE, SetNewOption, ASM::CALL);		//<- :c ?
	SetOp((LPVOID)0x7E22BA, SetNewOption, ASM::CALL);
}

void SetNewOption(ObjectItem * lpItem, BYTE Option, BYTE Special, BYTE Value) {
	
	pSetItemOption(lpItem, Option, Special, Value);

	CUSTOM_ITEM_INFO_EX* Exdata = gCustomItemInfo.GetInfoByItem(lpItem->ItemID);

	if (Exdata) {
		lpItem->DamageMin = Exdata->DamageMin;
		lpItem->DamageMax = Exdata->DamageMax;
		lpItem->Defense = Exdata->Defense;
		lpItem->MagicDefense = Exdata->MagicDefense;
		DWORD v6 = 0;
		DWORD v7 = 0;
		DWORD v8 = 0;
		DWORD v9 = 0;
		DWORD v10 = 0;
		DWORD v13 = 0;
		DWORD v14 = 0;
		int v16 = Special & 0x3F;
		signed int v17 = *(WORD *)pGetItemAtt(lpItem->ItemID, 32) + 30;
		char v22 = 0;
		int v24 = (Option >> 3) & 0xF;

		if (lpItem->ItemID >= 6147 && lpItem->ItemID <= 6150
			|| lpItem->ItemID >= 6180 && lpItem->ItemID <= 6184
			|| lpItem->ItemID >= 6186 && lpItem->ItemID <= 6187
			|| lpItem->ItemID == 19
			|| lpItem->ItemID == 2066
			|| lpItem->ItemID == 2570
			|| lpItem->ItemID == 1037
			|| lpItem->ItemID == 6686
			|| lpItem->ItemID >= 6274 && lpItem->ItemID <= 6278
			|| lpItem->ItemID >= 6193 && lpItem->ItemID <= 6194
			|| lpItem->ItemID == 6279
			|| lpItem->ItemID == 2596)
		{
			v16 = 0;
		}

		if (Value % 4 == 1 || Value % 4 == 2)
		{
			v16 = 1;
			v22 = 1;
		}

		signed int v18 = 0;

		switch (lpItem->ItemID)
		{
		case 0x406:
			v18 = 15;
			break;
		case 0x806:
			v18 = 30;
			break;
		case 0xA07:
			v18 = 25;
			break;
		}

		if (Exdata->DamageMin > 0)
		{
			if (v16 > 0 && *(WORD *)pGetItemAtt(lpItem->ItemID, 32))
			{
				if (v18)
					lpItem->DamageMin += v18;
				else
					lpItem->DamageMin += (25 * Exdata->DamageMin / *(WORD *)pGetItemAtt(lpItem->ItemID, 32)) + 5;
			}
			if (v22)
				lpItem->DamageMin += v17 / 40 + 5;
			if (v24 <= 9)
				v14 = (Option >> 3) & 0xF;
			else
				v14 = 9;
			lpItem->DamageMin += 3 * v14;
			switch (v24)
			{
			case 15:
				lpItem->DamageMin += 9;
			case 14:
				lpItem->DamageMin += 8;
			case 13:
				lpItem->DamageMin += 7;
			case 12:
				lpItem->DamageMin += 6;
			case 11:
				lpItem->DamageMin += 5;
			case 10:
				lpItem->DamageMin += 4;
				break;
			default:
				break;
			}
		}
		if (Exdata->DamageMax > 0)
		{
			if (v16 > 0 && *(WORD *)pGetItemAtt(lpItem->ItemID, 32))
			{
				if (v18)
					lpItem->DamageMax += v18;
				else
					lpItem->DamageMax += (25 * Exdata->DamageMax / *(WORD *)pGetItemAtt(lpItem->ItemID, 32)) + 5;
			}
			if (v22)
				lpItem->DamageMax += v17 / 40 + 5;
			if (v24 <= 9)
				v13 = (Option >> 3) & 0xF;
			else
				v13 = 9;
			lpItem->DamageMax += 3 * v13;
			switch (v24)
			{
			case 15:
				lpItem->DamageMax += 9;
			case 14:
				lpItem->DamageMax += 8;
			case 13:
				lpItem->DamageMax += 7;
			case 12:
				lpItem->DamageMax += 6;
			case 11:
				lpItem->DamageMax += 5;
			case 10:
				lpItem->DamageMax += 4;
				break;
			default:
				break;
			}
		}
		if (lpItem->ItemID == 6686) //???
		{
			lpItem->Defense = 15;
		}
		if (Exdata->Defense > 0)
		{
			if (lpItem->ItemID < 3072 || lpItem->ItemID >= 3584)
			{
				if (v16 > 0 && *(WORD *)pGetItemAtt(lpItem->ItemID, 32))
					lpItem->Defense += 12 * Exdata->Defense / *(WORD *)pGetItemAtt(lpItem->ItemID, 32) + *(WORD *)pGetItemAtt(lpItem->ItemID, 32) / 5 + 4;
				if (v22)
					lpItem->Defense += 3 * lpItem->Defense / v17 + v17 / 30 + 2;
				if ((lpItem->ItemID < 6147 || lpItem->ItemID > 6150) && lpItem->ItemID != 6186)
				{
					if (lpItem->ItemID != 6686 && lpItem->ItemID != 6193)
					{
						if ((lpItem->ItemID < 6180 || lpItem->ItemID > 6184)
							&& lpItem->ItemID != 6187
							&& lpItem->ItemID != 6194)
						{
							if (v24 <= 9)
								v7 = (Option >> 3) & 0xF;
							else
								v7 = 9;
							lpItem->Defense += 3 * v7;
						}
						else
						{
							if (v24 <= 9)
								v8 = (Option >> 3) & 0xF;
							else
								v8 = 9;
							lpItem->Defense += 4 * v8;
						}
					}
					else
					{
						if (v24 <= 9)
							v9 = (Option >> 3) & 0xF;
						else
							v9 = 9;
						lpItem->Defense += 2 * v9;
					}
				}
				else
				{
					if (v24 <= 9)
						v10 = (Option >> 3) & 0xF;
					else
						v10 = 9;
					lpItem->Defense += 2 * v10;
				}
				if ((lpItem->ItemID < 6180 || lpItem->ItemID > 6184)
					&& lpItem->ItemID != 6187
					&& lpItem->ItemID != 6194)
				{
					switch (v24)
					{
					case 15:
						lpItem->Defense += 9;
					case 14:
						lpItem->Defense += 8;
					case 13:
						lpItem->Defense += 7;
					case 12:
						lpItem->Defense += 6;
					case 11:
						lpItem->Defense += 5;
					case 10:
						lpItem->Defense += 4;
						break;
					default:
						break;
					}
				}
				else
				{
					switch (v24)
					{
					case 15:
						lpItem->Defense += 10;
					case 14:
						lpItem->Defense += 9;
					case 13:
						lpItem->Defense += 8;
					case 12:
						lpItem->Defense += 7;
					case 11:
						lpItem->Defense += 6;
					case 10:
						lpItem->Defense += 5;
						break;
					default:
						break;
					}
				}
			}
			else
			{
				lpItem->Defense += v24;
				if (v22)
					lpItem->Defense += (unsigned int)(20 * lpItem->Defense / v17) + 2;
			}
		}
		if (Exdata->MagicDefense > 0)
		{
			if (v24 <= 9)
				v6 = (Option >> 3) & 0xF;
			else
				v6 = 9;
			lpItem->MagicDefense += 3 * v6;
			switch (v24)
			{
			case 15:
				lpItem->MagicDefense += 9;
			case 14:
				lpItem->MagicDefense += 8;
			case 13:
				lpItem->MagicDefense += 7;
			case 12:
				lpItem->MagicDefense += 6;
			case 11:
				lpItem->MagicDefense += 5;
			case 10:
				lpItem->MagicDefense += 4;
				break;
			default:
				break;
			}
		}

	}
}