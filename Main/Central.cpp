#include "stdafx.h"
#include "Import.h"
#include "Util.h"
#include "Defines.h"
#include "Central.h"
#include "postInterface.h"
#include "Interface.h"
#include "Protect.h"
#include "PrintPlayer.h"
//#include "Ruud.h"
#include "MiniMap.h"
#include "Common.h"
#include "CSCharacterS13.h"
#include "WindowsStruct.h"
//#include "PartyBuffs.h"
#include "User.h"
#include "StatsAdvance.h"
//#include "InfoLog.h"
//#include "NPCRuud.h"
//#include "JCOptionBox.h"

Centralizado gCentral;

Centralizado::Centralizado()
{
}

Centralizado::~Centralizado()
{
}

char RenderPartyBack(DWORD a1)
{
	char result; // al@2
	float x; // ST08_4@5
	float y; // ST04_4@5
	HGDIOBJ alpha; // ST18_4@3
	char *v8; // [sp+20h] [bp-20h]@30
	float lifecurrent; // ST64_4@25
	float manacurrent; // ST10_4@25
	int Addr; // [sp+54h] [bp-1Ch]@1
	int v44; // [sp+5Ch] [bp-14h]@7
	int Salto; // [sp+68h] [bp-8h]@5
	int i; // [sp+6Ch] [bp-4h]@3
	
	PartyList unk_81CB4E8;

	Addr = a1;

	if(gInterface.CheckWindow(ObjWindow::CashShop) 
		//||gInterface.CheckWindow(ObjWindow::FullMap) 
		||gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
	    || gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return 0;
	}
	
	if( *(BYTE *)(a1 + 917) )
	{
		pSetBlend(1);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		alpha = pFontNormal;
		pSetFont(pTextThis(), (int)alpha);
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);

		*(DWORD *)(Addr + 920) = 43;

		x = (double)(*(DWORD *)(Addr + 16) + *(DWORD *)(Addr + 24));
		y = (double)(*(DWORD *)(Addr + 28) + *(DWORD *)(Addr + 20));
		
		for ( i = 0; i < pPartyMemberCount; ++i )
		{
			v8 = (char *)&pPartyListStruct + 32 * i;
			signed int PartyViewPort = *((DWORD *)v8 + 7);

			Salto = *(DWORD *)(Addr + 920) * i;
			glColor4f(0.0, 0.0, 0.0, 0.89999998);
			
			pDrawBarForm(x + 2, (double)(y + Salto + 2), 74.0, 17.0, 0.0, 0);

			EnableAlphaTest(1);

			if ( PartyViewPort == -1 )
			{
				glColor4f(0.30000001, 0.0, 0.0, 0.5);
				pDrawBarForm(x + 2, y + Salto + 2, 74.0, 17.0, 0.0, 0);
				EnableAlphaTest(1);
			}
			else
			{
				v44 = pGetPreviewStruct(pPreviewThis(), PartyViewPort);

				if ( v44 && pCheckEffectPlayer((DWORD *)(v44 + 1260), 2) == 1 )
				{
					glColor4f(0.2, 1.0, 0.2, 0.2);
					pDrawBarForm(x + 2, y + Salto + 2, 74.0, 17.0, 0.0, 0);
					EnableAlphaTest(1);
				}
				if ( *(DWORD *)(Addr + 924) != -1 && *(DWORD *)(Addr + 924) == i )
				{
					glColor4f(0.40000001, 0.40000001, 0.40000001, 0.69999999);
					pDrawBarForm(x + 2, y + Salto + 2, 74.0, 17.0, 0.0, 0);
					EnableAlphaTest(1);
				}
			}
			pGLSupremo();
			//-- Back

			pDrawGUI(81520, x, (double)(y + Salto), 77.0, 30.0);

			if ( i )
			{
				if ( PartyViewPort == -1 )
					SetTextColorByHDC(pTextThis(), pMakeColor(0x80u, 0x80u, 0x80u, 0xFFu));
				else
					SetTextColorByHDC(pTextThis(), pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
				//--
				pDrawText(pTextThis(), x + 14, y + Salto + 4, pGetStrutParty( i ).Name, 77, 0,(PINT) 1, 0);
//				gPartyBuffs.DrawPartyBuffs((double) x,(double) y + Salto + 31, pGetStrutParty( i ).Name);
			}
			else
			{
				if ( PartyViewPort == -1 )
					SetTextColorByHDC(pTextThis(), pMakeColor(0x80u, 0x4Bu, 0xBu, 0xFFu));
				else
					SetTextColorByHDC(pTextThis(), pMakeColor(0xFFu, 0x94u, 0x16u, 0xFFu));

				unk_81CB4E8 = *(PartyList*)0x81CB4E8;
				//-- Flag
				pDrawGUI(81521, x + 53, (double)(y + 3), 9.0, 10.0);
				//--
				pDrawText(pTextThis(), x + 14, y + Salto + 4, unk_81CB4E8.Name, 77, 0,(PINT) 1, 0);
//				gPartyBuffs.DrawPartyBuffs((double) x,(double) y + Salto + 31, unk_81CB4E8.Name);
			}

			//-- vida Concurrent
			if ( (signed int) pGetLifeMemberParty( i ) <= 10 )
				lifecurrent = pGetLifeMemberParty( i );
			else
				lifecurrent = 10;

			pDrawGUI(81522, x + 4, y + Salto + 16, (double)lifecurrent / 10.0 * 69.0, 3.0);
			//-- mana Concurrent
			manacurrent = (double) (69.0 / 100) * gCentral.m_PartyLife[i].mana;
			pDrawGUI(81523, x + 4, y + Salto + 23, manacurrent, 3.0);

			ChangeButtonInfo((char *)(Addr + 172 * i + 32), x + 63, y + Salto + 3, 11, 11);

			if ( !strcmp(unk_81CB4E8.Name, pGetUserName) 
				|| !strcmp(pGetStrutParty( i ).Name, pGetUserName) )
			{
				if(CheckButtonPressed((int) (x + 63), (int) (y + Salto + 3), (int) 11, (int) 11) )
				{
					pDrawButton(81524, x + 63, y + Salto + 3, 11, 11, 0, 11);
				}
				else
				{
					pDrawButton(81524, x + 63, y + Salto + 3, 11, 11, 0, 0);
				}
			}
		}
		
		glEnable(0xDE1u);
		pGLSwitch();
	}
	return 1;
}

bool InfoOverParty(int x, int y, int w, int h)
{
	return pCheckMouseOver(x, y, 77, 30);
}

bool MouseBlockParty(int x, int y, int w, int h)
{
	return pCheckMouseOver(x, y, 77, 43 * pPartyMemberCount);
}
void Centralizado::InitCentral()
{
	SetCompleteHook(0xE8, 0x0084BC0F, &InfoOverParty);
	SetCompleteHook(0xE8, 0x0084BD1D, &MouseBlockParty);
	SetCompleteHook(0xE9, 0x0084BDB0, &RenderPartyBack);
}