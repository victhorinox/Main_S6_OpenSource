#include "stdafx.h"
#include "Interface.h"
#include "CustomJewelBank.h"
#include "Item.h"
#include "User.h"
#include "Util.h"
#include "Object.h"
#include "Defines.h"

JewelBank gJewelBank;

JewelBank::JewelBank()
{

}

JewelBank::~JewelBank()
{

}

void JewelBank::Bind()
{
	gInterface.BindObject(eJEWELBANK_MAIN, 0x7A5A, 222, 290, -1, -1);
	gInterface.BindObject(eJEWELBANK_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(eJEWELBANK_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(eJEWELBANK_POINT, 0x7B68, 10, 10, -1, -1);
	gInterface.BindObject(eJEWELBANK_LINE, 0x7B67, 154, 3, -1, -1);
	gInterface.BindObject(eJEWELBANK_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(eJEWELBANK_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(eJEWELBANKe_CLOSE, 0x7EC5, 36, 29, -1, -1);

/*	gInterface.BindObject(EXPeJEWELBANK_PAGEUP1, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEUP2, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEUP3, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEUP4, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEUP5, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEUP6, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEUP7, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEUP8, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEUP9, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEUP10, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEUP11, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEDN1, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEDN2, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEDN3, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEDN4, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEDN5, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEDN6, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEDN7, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEDN8, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEDN9, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEDN10, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(EXPeJEWELBANK_PAGEDN11, 0x7C0D, 15, 15, -1, -1);*/

	/*gInterface.BindObject(eJEWELBANK_PAGEUP1, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP2, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP3, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP4, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP5, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP6, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP7, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP8, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP9, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP10, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP11, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN1, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN2, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN3, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN4, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN5, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN6, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN7, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN8, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN9, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN10, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN11, 0x7C0D, 15, 15, -1, -1);

	gInterface.BindObject(eJEWELBANK_NEXTWIN, 0x7903, 25, 40, -1, -1);
	gInterface.BindObject(eJEWELBANK_PREVWIN, 0x7904, 25, 40, -1, -1);*/
}

bool JewelBank::EventJewelWindows_Close(DWORD Event)
{
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANKe_CLOSE].EventTick);
		if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANKe_CLOSE))
		{
			return false;
		}
		
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eJEWELBANKe_CLOSE].OnClick = true;
			return true;
		}
		
		gInterface.Data[eJEWELBANKe_CLOSE].OnClick = false;

		if (Delay < 500)
		{
			return false;
		}

		gInterface.Data[eJEWELBANKe_CLOSE].EventTick = GetTickCount();
	
		this->CloseJewelWindow();
		
		return false;
	}

	//Normal
	else
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_CLOSE].EventTick);
		if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_CLOSE))
		{
			return false;
		}
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eJEWELBANK_CLOSE].OnClick = true;
			return true;
		}
		gInterface.Data[eJEWELBANK_CLOSE].OnClick = false;
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eJEWELBANK_CLOSE].EventTick = GetTickCount();
		this->CloseJewelWindow();
		return false;
	}
}

void JewelBank::DrawJewelBank()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		this->CloseJewelWindow();
		return;
	}

	pSetCursorFocus = true;

	DWORD Color = eGray100;

	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		float MainWidth = 230.0;
		float MainHeight = 130.0;
		float StartBody	= 40.0;
		float StartY = 40;
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2) - 185;

		gInterface.DrawWindow(eJEWELBANK_MAIN, eJEWELBANK_TITLE, eJEWELBANK_FRAME, eJEWELBANK_FOOTER, 14, StartX, StartY, "Jewel Bank System");

		gInterface.DrawGUI(eJEWELBANKe_CLOSE, StartX + MainWidth - gInterface.Data[eJEWELBANKe_CLOSE].Width, StartBody);

		if (gInterface.IsWorkZone(eJEWELBANKe_CLOSE))
		{
			DWORD Color = eGray100;

			if (gInterface.Data[eJEWELBANKe_CLOSE].OnClick)
			{
				Color = eGray150;
			}

			gInterface.DrawColoredGUI(eJEWELBANKe_CLOSE, gInterface.Data[eJEWELBANKe_CLOSE].X, gInterface.Data[eJEWELBANKe_CLOSE].Y, Color);
			gInterface.DrawToolTip(gInterface.Data[eJEWELBANKe_CLOSE].X + 5, gInterface.Data[eJEWELBANKe_CLOSE].Y + 25, "Close");
		}

		float flDrawX = StartX + 20;
		float flDrawY = StartY + 10;

		flDrawY += 10;

		flDrawY += 20;
		this->DrawInfo(flDrawX, flDrawY, "Zen", true, gObjUser.BankEx.Money);

		flDrawY += 20;
		this->DrawLine(12, 15, 1, flDrawX, flDrawY, "Jewel Of Chaos", gObjUser.BankEx.Chaos);

		flDrawY += 20;
		this->DrawLine(14, 13, 2, flDrawX, flDrawY, "Jewel Of Bless", gObjUser.BankEx.Bless);

		flDrawY += 20;
		this->DrawLine(14, 14, 3, flDrawX, flDrawY, "Jewel Of Soul", gObjUser.BankEx.Soul);

		flDrawY += 20;
		this->DrawLine(14, 16, 4, flDrawX, flDrawY, "Jewel Of Life", gObjUser.BankEx.Life);

		flDrawY += 20;
		this->DrawLine(14, 22, 5, flDrawX, flDrawY, "Jewel Of Creation", gObjUser.BankEx.Creation);

		flDrawY += 20;
		this->DrawLine(14, 42, 6, flDrawX, flDrawY, "Jewel Of Harmony", gObjUser.BankEx.Harmony);

		flDrawY += 20;
		this->DrawLine(14, 31, 7, flDrawX, flDrawY, "Jewel Of Guardian", gObjUser.BankEx.Guardian);

		flDrawY += 20;
		this->DrawLine(14, 41, 8, flDrawX, flDrawY, "Gemstone", gObjUser.BankEx.Gemstone);
	
		flDrawY += 20;
		this->DrawLine(14, 43, 9, flDrawX, flDrawY, "Lower Refining Stone", gObjUser.BankEx.LowRefine);

		flDrawY += 20;
		this->DrawLine(14, 44, 10, flDrawX, flDrawY, "Higher Refining Stone", gObjUser.BankEx.HigRefine);
	}

	//Normal
	else 
	{
		float MainWidth = 230.0;
		float MainHeight = 130.0;
		float StartBody	= 40.0;
		float StartY = 40;
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

		gInterface.DrawWindow(eJEWELBANK_MAIN, eJEWELBANK_TITLE, eJEWELBANK_FRAME, eJEWELBANK_FOOTER, 14, StartX, StartY, "Jewel Bank System");

		gInterface.DrawGUI(eJEWELBANK_CLOSE, StartX + MainWidth - gInterface.Data[eJEWELBANK_CLOSE].Width, StartBody);

		if (gInterface.IsWorkZone(eJEWELBANK_CLOSE))
		{
			DWORD Color = eGray100;

			if (gInterface.Data[eJEWELBANK_CLOSE].OnClick)
			{
				Color = eGray150;
			}

			gInterface.DrawColoredGUI(eJEWELBANK_CLOSE, gInterface.Data[eJEWELBANK_CLOSE].X, gInterface.Data[eJEWELBANK_CLOSE].Y, Color);
			gInterface.DrawToolTip(gInterface.Data[eJEWELBANK_CLOSE].X + 5, gInterface.Data[eJEWELBANK_CLOSE].Y + 25, "Close");
		}

		float flDrawX = StartX + 20;
		float flDrawY = StartY + 10;

		flDrawY += 10;

		flDrawY += 20;
		this->DrawInfo(flDrawX, flDrawY, "Zen", true, gObjUser.BankEx.Money);

		flDrawY += 20;
		this->DrawLine(12, 15, 1, flDrawX, flDrawY, "Jewel Of Chaos", gObjUser.BankEx.Chaos);

		//gInterface.DrawGUI(eOFFATTACK_BUTTON, PosX + 0.5, 1.5);
		//flX += 95 ;

		flDrawY += 20;
		this->DrawLine(14, 13, 2, flDrawX, flDrawY, "Jewel Of Bless", gObjUser.BankEx.Bless);

		flDrawY += 20;
		this->DrawLine(14, 14, 3, flDrawX, flDrawY, "Jewel Of Soul", gObjUser.BankEx.Soul);

		flDrawY += 20;
		this->DrawLine(14, 16, 4, flDrawX, flDrawY, "Jewel Of Life", gObjUser.BankEx.Life);

		flDrawY += 20;
		this->DrawLine(14, 22, 5, flDrawX, flDrawY, "Jewel Of Creation", gObjUser.BankEx.Creation);

		flDrawY += 20;
		this->DrawLine(14, 42, 6, flDrawX, flDrawY, "Jewel Of Harmony", gObjUser.BankEx.Harmony);

		flDrawY += 20;
		this->DrawLine(14, 31, 7, flDrawX, flDrawY, "Jewel Of Guardian", gObjUser.BankEx.Guardian);

		flDrawY += 20;
		this->DrawLine(14, 41, 8, flDrawX, flDrawY, "Gemstone", gObjUser.BankEx.Gemstone);
	
		flDrawY += 20;
		this->DrawLine(14, 43, 9, flDrawX, flDrawY, "Lower Refining Stone", gObjUser.BankEx.LowRefine);

		flDrawY += 20;
		this->DrawLine(14, 44, 10, flDrawX, flDrawY, "Higher Refining Stone", gObjUser.BankEx.HigRefine);
	}
}

void JewelBank::DrawLine(int ItemType, int ItemIndex, int ItemLevel, float ItemDrawX, float ItemDrawY, char * ItemName, int Count)
{
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		ItemBmdStruct* ItemInfo = pGetItemBmdStruct(ITEM(ItemType, ItemIndex));
		const int WidthValue = 24;
		const int HeightValue = 24;
		float barWidth = WidthValue * ItemInfo->ItemWidth;
		float barHeight = HeightValue * ItemInfo->ItemHeight;
		float flX = ItemDrawX + 10;
		float flX2 = ItemDrawX + 10;
		float flY = ItemDrawY;
		int iLevel = 0;
		gInterface.DrawItemIMGBank(flX, flY, barWidth, barHeight, GET_ITEM(ItemType, ItemIndex), SET_ITEMOPT_LEVEL(iLevel), 0, 0, 0);
	
		flX += 30;
		flX2 += 110;
		flY += 7;

		gInterface.DrawFormat(eYellow, flX, flY + 2, 100, 1, "%s", ItemName);
		gInterface.DrawFormat(eYellow, flX2, flY + 2, 100, 1, "x %d", Count);

		flX += 95 ;
//		gInterface.DrawGUI(EXPeJEWELBANK_PAGEDN1 + ItemLevel, flX, flY - 1);

/*		if(gInterface.IsWorkZone(EXPeJEWELBANK_PAGEDN1 + ItemLevel))
		{
			if(gInterface.Data[EXPeJEWELBANK_PAGEDN1 + ItemLevel].OnClick)
			{
				gInterface.DrawColoredGUI(EXPeJEWELBANK_PAGEDN1 + ItemLevel, gInterface.Data[EXPeJEWELBANK_PAGEDN1 + ItemLevel].X, gInterface.Data[EXPeJEWELBANK_PAGEDN1 + ItemLevel].Y - 1, eGray150);
			}	
		}*/

		flX += 20;
//		gInterface.DrawGUI(EXPeJEWELBANK_PAGEUP1 + ItemLevel, flX, flY - 1);

	/*	if(gInterface.IsWorkZone(EXPeJEWELBANK_PAGEUP1 + ItemLevel))
		{
			if(gInterface.Data[EXPeJEWELBANK_PAGEUP1 + ItemLevel].OnClick)
			{
				gInterface.DrawColoredGUI(EXPeJEWELBANK_PAGEUP1 + ItemLevel, gInterface.Data[EXPeJEWELBANK_PAGEUP1 + ItemLevel].X, gInterface.Data[EXPeJEWELBANK_PAGEUP1 + ItemLevel].Y - 1, eGray150);
			}
		}*/

		gInterface.DrawGUI(eJEWELBANK_LINE, ItemDrawX + 15, flY + 15);
	}

	else
	{
		ItemBmdStruct* ItemInfo = pGetItemBmdStruct(ITEM(ItemType, ItemIndex));
		const int WidthValue = 24;
		const int HeightValue = 24;
		float barWidth = WidthValue * ItemInfo->ItemWidth;
		float barHeight = HeightValue * ItemInfo->ItemHeight;
		float flX = ItemDrawX + 10;
		float flX2 = ItemDrawX + 10;
		float flY = ItemDrawY;
		int iLevel = 0;
		gInterface.DrawItemIMGBank(flX, flY, barWidth, barHeight, GET_ITEM(ItemType, ItemIndex), SET_ITEMOPT_LEVEL(iLevel), 0, 0, 0);
	
		flX += 30;
		flX2 += 110;
		flY += 7;

		gInterface.DrawFormat(eYellow, flX, flY + 2, 100, 1, "%s", ItemName);
		gInterface.DrawFormat(eYellow, flX2, flY + 2, 100, 1, "x %d", Count);

		flX += 95;
	//	gInterface.DrawGUI(eJEWELBANK_PAGEDN1 + ItemLevel, flX, flY - 1);

	/*	if(gInterface.IsWorkZone(eJEWELBANK_PAGEDN1 + ItemLevel))
		{
			if(gInterface.Data[eJEWELBANK_PAGEDN1 + ItemLevel].OnClick)
			{
				gInterface.DrawColoredGUI(eJEWELBANK_PAGEDN1 + ItemLevel, gInterface.Data[eJEWELBANK_PAGEDN1 + ItemLevel].X, gInterface.Data[eJEWELBANK_PAGEDN1 + ItemLevel].Y - 1, eGray150);
			}	
		}*/

		flX += 20;
//		gInterface.DrawGUI(eJEWELBANK_PAGEUP1 + ItemLevel, flX, flY - 1);

/*		if(gInterface.IsWorkZone(eJEWELBANK_PAGEUP1 + ItemLevel))
		{
			if(gInterface.Data[eJEWELBANK_PAGEUP1 + ItemLevel].OnClick)
			{
				gInterface.DrawColoredGUI(eJEWELBANK_PAGEUP1 + ItemLevel, gInterface.Data[eJEWELBANK_PAGEUP1 + ItemLevel].X, gInterface.Data[eJEWELBANK_PAGEUP1 + ItemLevel].Y - 1, eGray150);
			}
		}*/

		gInterface.DrawGUI(eJEWELBANK_LINE, ItemDrawX + 15, flY + 15);
	}
}

void JewelBank::DrawInfo(float InfoDrawX, float InfoDrawY, char* Text, bool Type, int Count)
{
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		float flX = InfoDrawX + 10;
		float flY = InfoDrawY;

		gInterface.DrawGUI(eJEWELBANK_POINT, flX + 8, flY + 8);

		flX += 30;
		flY += 7;


		if (Type)
		{
			gInterface.DrawFormat(eYellow, flX, flY + 2, 100, 1, "%s: %d", Text, Count);
		
			flX += 95;
//			gInterface.DrawGUI(EXPeJEWELBANK_PAGEDN1, flX, flY);
	
	/*		if(gInterface.IsWorkZone(EXPeJEWELBANK_PAGEDN1))
			{
				if(gInterface.Data[EXPeJEWELBANK_PAGEDN1].OnClick)
				{
					gInterface.DrawColoredGUI(EXPeJEWELBANK_PAGEDN1, gInterface.Data[EXPeJEWELBANK_PAGEDN1].X, gInterface.Data[EXPeJEWELBANK_PAGEDN1].Y, eGray150);
				}
			}*/

			flX += 20;
//			gInterface.DrawGUI(EXPeJEWELBANK_PAGEUP1, flX, flY);

	/*		if(gInterface.IsWorkZone(EXPeJEWELBANK_PAGEUP1))
			{
				if(gInterface.Data[EXPeJEWELBANK_PAGEUP1].OnClick)
				{
					gInterface.DrawColoredGUI(EXPeJEWELBANK_PAGEUP1, gInterface.Data[EXPeJEWELBANK_PAGEUP1].X, gInterface.Data[EXPeJEWELBANK_PAGEUP1].Y, eGray150);
				}
			
			}*/
		}

		flX += 95;
		gInterface.DrawGUI(eJEWELBANK_LINE, InfoDrawX + 15, flY + 15);
	}

	else
	{
		float flX = InfoDrawX + 10;
		float flY = InfoDrawY;

		gInterface.DrawGUI(eJEWELBANK_POINT, flX + 8, flY + 8);

		flX += 30;
		flY += 7;


		if (Type)
		{
			gInterface.DrawFormat(eYellow, flX, flY + 2, 100, 1, "%s: %d", Text, Count);
		
			flX += 95;
//			gInterface.DrawGUI(eJEWELBANK_PAGEDN1, flX, flY);
	

			/*	if(gInterface.IsWorkZone(eJEWELBANK_PAGEDN1))
				{
					if(gInterface.Data[eJEWELBANK_PAGEDN1].OnClick)
					{
						gInterface.DrawColoredGUI(eJEWELBANK_PAGEDN1, gInterface.Data[eJEWELBANK_PAGEDN1].X, gInterface.Data[eJEWELBANK_PAGEDN1].Y, eGray150);
					}
				}*/

			flX += 20;
//			gInterface.DrawGUI(eJEWELBANK_PAGEUP1, flX, flY);

	/*		if(gInterface.IsWorkZone(eJEWELBANK_PAGEUP1))
			{
				if(gInterface.Data[eJEWELBANK_PAGEUP1].OnClick)
				{
					gInterface.DrawColoredGUI(eJEWELBANK_PAGEUP1, gInterface.Data[eJEWELBANK_PAGEUP1].X, gInterface.Data[eJEWELBANK_PAGEUP1].Y, eGray150);
				}
			
			}*/
		}

		flX += 95;
		gInterface.DrawGUI(eJEWELBANK_LINE, InfoDrawX + 15, flY + 15);
	}
}

bool JewelBank::JewelBankEvent(DWORD Event)
{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_CLOSE].EventTick);

		if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_CLOSE))
		{
			return false;
		}

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eJEWELBANK_CLOSE].OnClick = true;
			return true;
		}

		gInterface.Data[eJEWELBANK_CLOSE].OnClick = false;

		if (Delay < 500)
		{
			return false;
		}

		gInterface.Data[eJEWELBANK_CLOSE].EventTick = GetTickCount();
		gInterface.Data[eJEWELBANK_MAIN].Close();

		return false;
}
/*
bool JewelBank::JewelBankNext(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay		= (CurrentTick - gInterface.Data[eJEWELBANK_NEXTWIN].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[eJEWELBANK_PREVWIN].EventTick);

	if( !gInterface.Data[eJEWELBANK_MAIN].OnShow )
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(eJEWELBANK_NEXTWIN) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[eJEWELBANK_NEXTWIN].OnClick = true;
		return true;
	}

	if( Delay < 100 || Delay2 < 100 )
	{
		return false;
	}
	
	gInterface.Data[eJEWELBANK_NEXTWIN].OnClick = false;
	
	this->Page++;
	
	gInterface.Data[eJEWELBANK_NEXTWIN].EventTick = GetTickCount();
	
	return true;
}

bool JewelBank::JewelBankPrev(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay		= (CurrentTick - gInterface.Data[eJEWELBANK_PREVWIN].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[eJEWELBANK_NEXTWIN].EventTick);

	if( !gInterface.Data[eJEWELBANK_MAIN].OnShow )
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(eJEWELBANK_PREVWIN) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[eJEWELBANK_PREVWIN].OnClick = true;
		return true;
	}

	if( Delay < 100 || Delay2 < 100 )
	{
		return false;
	}
	
	gInterface.Data[eJEWELBANK_PREVWIN].OnClick = false;
	
	gInterface.Data[eJEWELBANK_PREVWIN].EventTick = GetTickCount();

	this->Page--;
	
	return true;
}
*/
/*
void JewelBank::JewelBankButton(DWORD key)
{
	for(int i = 0; i < 11; i++)
	{
		if(gInterface.ButtonEx(key, eJEWELBANK_PAGEUP1 + i, false))
		{
		//	this->JewelBankPacket(i);
				return;
		}
		else if(gInterface.ButtonEx(key, eJEWELBANK_PAGEDN1 + i, false))
		{
		//	this->JewelBankPacket(i+11);
			return;
		}
	}
}
*/

/*
void JewelBank::JewelBankPacket(int number)
{
	PMSG_JEWELBANK pMsg;
	pMsg.h.set((LPBYTE)&pMsg, 0xFB, 0xDA, sizeof(pMsg));
	pMsg.Result = number;
	DataSend((LPBYTE)&pMsg, pMsg.h.size);
}
*/