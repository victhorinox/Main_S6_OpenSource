#include "stdafx.h"
#include "CSCharacterS13.h"
#include "Defines.h"
#include "TMemory.h"
#include "Util.h"
#include "Interface.h"
#include "zzzMathLib.h"
#include "Offset.h"
#include "User.h"
#include "Protect.h"

CSCharacterS13 gCSCharacterS13;

void CSCharacterS13::Load()
{
	gInterface.BindObject(CharacterSelect, 51522, 85, 150, 219, 178);
	gInterface.BindObject(CharacterSelect_0Button01, 51519, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_0Button02, 51520, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_0Button03, 51521, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_1Button01, 51519, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_1Button02, 51520, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_1Button03, 51521, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_2Button01, 51519, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_2Button02, 51520, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_2Button03, 51521, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_3Button01, 51519, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_3Button02, 51520, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_3Button03, 51521, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_4Button01, 51519, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_4Button02, 51520, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_4Button03, 51521, 150, 35, -1, -1);

	SetCompleteHook(0xE8, 0x004D5EE6,this->SelectChar);
	SetCompleteHook(0xE8, 0x004D6C3E,this->OpenCharacterSceneData);

	SetDword((PVOID)(0x004D6C73), 0);
	SetByte((PVOID)(0x00402106), 0);
}

void CSCharacterS13::OpenCharacterSceneData()
{
	pLoadImage("Custom\\Interface\\Gfx\\CharacterSelect_Button01.tga", 51519, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Gfx\\CharacterSelect_Button02.tga", 51520, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Gfx\\CharacterSelect_Button03.tga", 51521, 0x2601, 0x2901, 1, 0);
	
	((void(__cdecl*)())0x006312E0)();
}

void CharacterSelect360()
{
	for (int i = 0; i < 5; i++)
	{
		if (gInterface.IsWorkZone(CharacterSelect))
		{
			int v5 = pGetPreviewStruct(pPreviewThis(),i);
			int v8 = v5 + 776;
			*(float *)(v8 + 272) = (int) (timeGetTime() * gProtect.m_MainInfo.SelectCharacterTurnAroundSpeed/50) % 360;
		}
	}
}

void CharacterCharacteristics(int a1,float a2)
{
	char* Name;
	char* Status;
	int Class;
	char Level[256];
	float X = 471;
	float Y = 51;
	int This = (int)sub_482B70() + 36744;
	int Hero00 = This;
	Hero00 = *(DWORD *)(This + 4) + 368 * a1;
	
	Name = strcpy((char *)Hero00 + 176, (const char *)(*((DWORD *)Hero00 + 42) + 56));
	Status = (char *)Hero00 + 240;
	Class = sub_587620(*(BYTE *)(*(DWORD *)(Hero00 + 168) + 19));
	gInterface.DrawFormat(eGold, X + 35, Y + 20 + a2, 190, 2, (const char *)Name);
	gInterface.DrawFormat(eWhite180, X + 11, Y + 7 + a2, 190, 0, (const char *)Class);
	gInterface.DrawFormat(eWhite180, X - 50, Y + 7 + a2, 190, 4, (const char *)Status);
	wsprintf(Level, "%d", *(WORD *)(*(DWORD *)(Hero00 + 168) + 130));
	pSetTextColor(pTextThis(), 255, 189, 25, 0xFF);
	pDrawText(pTextThis(), X - 50, Y + 20 + a2, Level, 190, 0, (LPINT)4, 0);
}

void CharacterTeleport(int a1,float a2,float a3,float a4)
{
	if(*(DWORD*)(MAIN_SCREEN_STATE) == ObjState::SwitchCharacter)
	{
		int v5 = pGetPreviewStruct(pPreviewThis(),a1);
		int v8 = v5 + 776;
		
		if ( v5 ) 
		{
			*(float *)(v8 + 156) = 0.30000001;
			*(float *)(v8 + 160) = 0.30000001;
			*(float *)(v8 + 164) = 0.30000001;
			*(float *)(v8 + 252) = a2;
			*(float *)(v8 + 256) = a3;
			*(float *)(v8 + 272) = a4;
		}
	}
}

void CSCharacterS13::SelectChar()
{
	gObjUser.Refresh();
	
	if(*(DWORD*)(MAIN_SCREEN_STATE) == ObjState::SwitchCharacter)
	{
		float X = 471;
		float Y = 51;
		
		if ( !*(BYTE *)((int)sub_482B70() + 33948) )
		{
			//-> Create Select
			//-> 0
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),0) + 780) )
			{
				gInterface.DrawIMG(CharacterSelect_0Button01, 471, 51, 0.878, 0.82);

				if (gInterface.IsWorkZone(CharacterSelect_0Button01))
				{
					gInterface.DrawIMG(CharacterSelect_0Button02, 471, 51, 0.878, 0.82);
				}
				
				if (gInterface.Data[CharacterSelect_0Button01].OnClick)
				{
					gInterface.DrawIMG(CharacterSelect_0Button03, 471, 51, 0.878, 0.82);

					sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
				}
				
				gInterface.DrawFormat(eWhite180, X-29, Y+13, 210, 3, "Empty Character Slot");
			}
			
			//-> 1
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),1) + 780) )
			{
				gInterface.DrawIMG(CharacterSelect_1Button01, 471, 88, 0.878, 0.82);

				if (gInterface.IsWorkZone(CharacterSelect_1Button01))
				{
					gInterface.DrawIMG(CharacterSelect_1Button02, 471, 88, 0.878, 0.82);
				}
				
				if (gInterface.Data[CharacterSelect_1Button01].OnClick)
				{
					gInterface.DrawIMG(CharacterSelect_1Button03, 471, 88, 0.878, 0.82);

					sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
				}
				
				gInterface.DrawFormat(eWhite180, X-29, Y+13+ 37, 210, 3, "Empty Character Slot");
			}
			
			//-> 2
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),2) + 780) )
			{
				gInterface.DrawIMG(CharacterSelect_2Button01, 471, 125, 0.878, 0.82);
				
				if (gInterface.IsWorkZone(CharacterSelect_2Button01))
				{
					gInterface.DrawIMG(CharacterSelect_2Button02, 471, 125, 0.878, 0.82);
				}
				
				if (gInterface.Data[CharacterSelect_2Button01].OnClick)
				{
					gInterface.DrawIMG(CharacterSelect_2Button03, 471, 125, 0.878, 0.82);

					sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
				}
				
				gInterface.DrawFormat(eWhite180, X-29, Y+13+ 74, 210, 3, "Empty Character Slot");
			}
			
			//-> 3
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),3) + 780) )
			{
				gInterface.DrawIMG(CharacterSelect_3Button01, 471, 162, 0.878, 0.82);

				if (gInterface.IsWorkZone(CharacterSelect_3Button01))
				{
					gInterface.DrawIMG(CharacterSelect_3Button02, 471, 162, 0.878, 0.82);
				}
				
				if (gInterface.Data[CharacterSelect_3Button01].OnClick)
				{
					gInterface.DrawIMG(CharacterSelect_3Button03, 471, 162, 0.878, 0.82);

					sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
				}
				
				gInterface.DrawFormat(eWhite180, X-29, Y+13+ 111, 210, 3, "Empty Character Slot");
			}
			
			//-> 4
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),4) + 780) )
			{
				gInterface.DrawIMG(CharacterSelect_4Button01, 471, 199, 0.878, 0.82);

				if (gInterface.IsWorkZone(CharacterSelect_4Button01))
				{
					gInterface.DrawIMG(CharacterSelect_4Button02, 471, 199, 0.878, 0.82);
				}
				
				if (gInterface.Data[CharacterSelect_4Button01].OnClick)
				{
					gInterface.DrawIMG(CharacterSelect_4Button03, 471, 199, 0.878, 0.82);
					
					sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
				}
				
				gInterface.DrawFormat(eWhite180, X-29, Y+13+ 148, 210, 3, "Empty Character Slot");
			}
			
			//-> Character Select Rotation
			if(gProtect.m_MainInfo.SelectCharacterTurnAround == 1)
			{
				CharacterSelect360();
			}
			
			//-> 0
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),0) + 780) )
			{
				gInterface.DrawIMG(CharacterSelect_0Button01, 471, 51, 0.878, 0.82);
				
				if (gInterface.IsWorkZone(CharacterSelect_0Button01))
				{
					SelectedCharacter = 0;
					gInterface.DrawIMG(CharacterSelect_0Button02, 471, 51, 0.878, 0.82);
				}
				
				if (gInterface.Data[CharacterSelect_0Button01].OnClick)
				{
					PlayBuffer(25, 0, 0);
					SelectedHero = 0;

					//-> Login Theme Type (Season 2)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 1)
					{
						CharacterTeleport(0, 7900.0, 19300.0, 90.0);
						CharacterTeleport(1, 1000.0, 5145.0, 45.0);
						CharacterTeleport(2, 1000.0, 5145.0, 45.0);
						CharacterTeleport(3, 1000.0, 5145.0, 45.0);
						CharacterTeleport(4, 1000.0, 5145.0, 45.0);
					}
					
					//-> Login Theme Type (Season 4)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 2)
					{
						CharacterTeleport(0, 22840.0, 15355.0, 45.0);
						CharacterTeleport(1, 1000.0, 5145.0, 45.0);
						CharacterTeleport(2, 1000.0, 5145.0, 45.0);
						CharacterTeleport(3, 1000.0, 5145.0, 45.0);
						CharacterTeleport(4, 1000.0, 5145.0, 45.0);
					}
					
					//-> Login Theme Type (Season 6)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 3)
					{
						CharacterTeleport(0, 8172.84083, 19265.57287, 90.0);
						CharacterTeleport(1, 0.0, 8171.84083, 90.0);
						CharacterTeleport(2, 0.0, 8171.84083, 90.0);
						CharacterTeleport(3, 0.0, 8171.84083, 90.0);
						CharacterTeleport(4, 0.0, 8171.84083, 90.0);
					}

					//-> Login Theme Type (EX700)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 4)
					{
						CharacterTeleport(0, 13629.0, 12339.0, 90.0);
						CharacterTeleport(1, 0.0, 13539.0, 90.0);
						CharacterTeleport(2, 0.0, 13539.0, 90.0);
						CharacterTeleport(3, 0.0, 13539.0, 90.0);
						CharacterTeleport(4, 0.0, 13539.0, 90.0);
					}

					gInterface.DrawIMG(CharacterSelect_0Button03, 471, 51, 0.878, 0.82);
				}
				
				if(SelectedHero == 0)
				{
					gInterface.DrawIMG(CharacterSelect_0Button03, 471, 51, 0.878, 0.82);
				}
				
				CharacterCharacteristics(0,0);
			}
			
			//-> 1
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),1) + 780) )
			{
				gInterface.DrawIMG(CharacterSelect_1Button01, 471, 88, 0.878, 0.82);
				
				if (gInterface.IsWorkZone(CharacterSelect_1Button01))
				{
					SelectedCharacter = 1;
					
					gInterface.DrawIMG(CharacterSelect_1Button02, 471, 88, 0.878, 0.82);
				}
				
				if (gInterface.Data[CharacterSelect_1Button01].OnClick)
				{
					PlayBuffer(25, 0, 0);
					SelectedHero = 1;

					//-> Login Theme Type (Season 2)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 1)
					{
						CharacterTeleport(1, 7900.0, 19300.0, 90.0);
						CharacterTeleport(0, 1000.0, 5145.0, 45.0);
						CharacterTeleport(2, 1000.0, 5145.0, 45.0);
						CharacterTeleport(3, 1000.0, 5145.0, 45.0);
						CharacterTeleport(4, 1000.0, 5145.0, 45.0);
					}

					//-> Login Theme Type (Season 4)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 2)
					{
						CharacterTeleport(1, 22840.0, 15355.0, 45.0);
						CharacterTeleport(0, 1000.0, 5145.0, 45.0);
						CharacterTeleport(2, 1000.0, 5145.0, 45.0);
						CharacterTeleport(3, 1000.0, 5145.0, 45.0);
						CharacterTeleport(4, 1000.0, 5145.0, 45.0);
					}
					
					//-> Login Theme Type (Season 6)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 3)
					{
						CharacterTeleport(1, 8172.84083, 19265.57287, 90.0);
						CharacterTeleport(0, 0.0, 8171.84083, 90.0);
						CharacterTeleport(2, 0.0, 8171.84083, 90.0);
						CharacterTeleport(3, 0.0, 8171.84083, 90.0);
						CharacterTeleport(4, 0.0, 8171.84083, 90.0);
					}

					//-> Login Theme Type (EX700)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 4)
					{
						CharacterTeleport(1, 13629.0, 12339.0, 90.0);
						CharacterTeleport(0, 0.0, 13539.0, 90.0);
						CharacterTeleport(2, 0.0, 13539.0, 90.0);
						CharacterTeleport(3, 0.0, 13539.0, 90.0);
						CharacterTeleport(4, 0.0, 13539.0, 90.0);
					}
					
					
					gInterface.DrawIMG(CharacterSelect_1Button03, 471, 88, 0.878, 0.82);
				}
				
				if(SelectedHero == 1)
				{
					gInterface.DrawIMG(CharacterSelect_1Button03, 471, 88, 0.878, 0.82);
				}
				
				CharacterCharacteristics(1,37);
			}
			
			//-> 2
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),2) + 780) )
			{
				gInterface.DrawIMG(CharacterSelect_2Button01, 471, 125, 0.878, 0.82);
				
				if (gInterface.IsWorkZone(CharacterSelect_2Button01))
				{
					SelectedCharacter = 2;
					
					gInterface.DrawIMG(CharacterSelect_2Button02, 471, 125, 0.878, 0.82);
				}
				
				if (gInterface.Data[CharacterSelect_2Button01].OnClick)
				{
					PlayBuffer(25, 0, 0);
					SelectedHero = 2;

					//-> Login Theme Type (Season 2)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 1)
					{
						CharacterTeleport(2, 7900.0, 19300.0, 90.0);
						CharacterTeleport(0, 1000.0, 5145.0, 45.0);
						CharacterTeleport(1, 1000.0, 5145.0, 45.0);
						CharacterTeleport(3, 1000.0, 5145.0, 45.0);
						CharacterTeleport(4, 1000.0, 5145.0, 45.0);
					}

					//-> Login Theme Type (Season 4)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 2)
					{
						CharacterTeleport(2, 22840.0, 15355.0, 45.0);
						CharacterTeleport(0, 1000.0, 5145.0, 45.0);
						CharacterTeleport(1, 1000.0, 5145.0, 45.0);
						CharacterTeleport(3, 1000.0, 5145.0, 45.0);
						CharacterTeleport(4, 1000.0, 5145.0, 45.0);
					}
					
					//-> Login Theme Type (Season 6)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 3)
					{
						CharacterTeleport(2, 8172.84083, 19265.57287, 90.0);
						CharacterTeleport(0, 0.0, 8171.84083, 90.0);
						CharacterTeleport(1, 0.0, 8171.84083, 90.0);
						CharacterTeleport(3, 0.0, 8171.84083, 90.0);
						CharacterTeleport(4, 0.0, 8171.84083, 90.0);
					}

					//-> Login Theme Type (EX700)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 4)
					{
						CharacterTeleport(2, 13629.0, 12339.0, 90.0);
						CharacterTeleport(0, 0.0, 13539.0, 90.0);
						CharacterTeleport(1, 0.0, 13539.0, 90.0);
						CharacterTeleport(3, 0.0, 13539.0, 90.0);
						CharacterTeleport(4, 0.0, 13539.0, 90.0);
					}
					
					gInterface.DrawIMG(CharacterSelect_2Button03, 471, 125, 0.878, 0.82);
				}
				
				if(SelectedHero == 2)
				{	
					gInterface.DrawIMG(CharacterSelect_2Button03, 471, 125, 0.878, 0.82);
				}
				
				CharacterCharacteristics(2,74);
			}
			
			//-> 3
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),3) + 780) )
			{
				gInterface.DrawIMG(CharacterSelect_3Button01, 471, 162, 0.878, 0.82);
				
				if (gInterface.IsWorkZone(CharacterSelect_3Button01))
				{
					SelectedCharacter = 3;
					
					gInterface.DrawIMG(CharacterSelect_3Button02, 471, 162, 0.878, 0.82);
				}
				
				if (gInterface.Data[CharacterSelect_3Button01].OnClick)
				{
					PlayBuffer(25, 0, 0);
					SelectedHero = 3;

					//-> Login Theme Type (Season 2)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 1)
					{
						CharacterTeleport(3, 7900.0, 19300.0, 90.0);
						CharacterTeleport(0, 1000.0, 5145.0, 45.0);
						CharacterTeleport(1, 1000.0, 5145.0, 45.0);
						CharacterTeleport(2, 1000.0, 5145.0, 45.0);
						CharacterTeleport(4, 1000.0, 5145.0, 45.0);
					}

					//-> Login Theme Type (Season 4)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 2)
					{
						CharacterTeleport(3, 22840.0, 15355.0, 45.0);
						CharacterTeleport(0, 1000.0, 5145.0, 45.0);
						CharacterTeleport(1, 1000.0, 5145.0, 45.0);
						CharacterTeleport(2, 1000.0, 5145.0, 45.0);
						CharacterTeleport(4, 1000.0, 5145.0, 45.0);
					}
					
					//-> Login Theme Type (Season 6)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 3)
					{
						CharacterTeleport(3, 8172.84083, 19265.57287, 90.0);
						CharacterTeleport(0, 0.0, 8171.84083, 90.0);
						CharacterTeleport(1, 0.0, 8171.84083, 90.0);
						CharacterTeleport(2, 0.0, 8171.84083, 90.0);
						CharacterTeleport(4, 0.0, 8171.84083, 90.0);
					}

					//-> Login Theme Type (EX700)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 4)
					{
						CharacterTeleport(3, 13629.0, 12339.0, 90.0);
						CharacterTeleport(0, 0.0, 13539.0, 90.0);
						CharacterTeleport(1, 0.0, 13539.0, 90.0);
						CharacterTeleport(2, 0.0, 13539.0, 90.0);
						CharacterTeleport(4, 0.0, 13539.0, 90.0);
					}
					
					gInterface.DrawIMG(CharacterSelect_3Button03, 471, 162, 0.878, 0.82);
				}
				
				if(SelectedHero == 3)
				{
					gInterface.DrawIMG(CharacterSelect_3Button03, 471, 162, 0.878, 0.82);
				}
				
				CharacterCharacteristics(3,111);
			}
			
			//-> 4
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),4) + 780) )
			{
				gInterface.DrawIMG(CharacterSelect_4Button01, 471, 199, 0.878, 0.82);

				if (gInterface.IsWorkZone(CharacterSelect_4Button01))
				{
					SelectedCharacter = 4;
					gInterface.DrawIMG(CharacterSelect_4Button02, 471, 199, 0.878, 0.82);
				}
				
				if (gInterface.Data[CharacterSelect_4Button01].OnClick)
				{
					PlayBuffer(25, 0, 0);
					SelectedHero = 4;

					//-> Login Theme Type (Season 2)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 1)
					{
						CharacterTeleport(4, 7900.0, 19300.0, 90.0);
						CharacterTeleport(0, 1000.0, 5145.0, 45.0);
						CharacterTeleport(1, 1000.0, 5145.0, 45.0);
						CharacterTeleport(2, 1000.0, 5145.0, 45.0);
						CharacterTeleport(3, 1000.0, 5145.0, 45.0);
					}

					//-> Login Theme Type (Season 4)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 2)
					{
						CharacterTeleport(4, 22840.0, 15355.0, 45.0);
						CharacterTeleport(0, 1000.0, 5145.0, 45.0);
						CharacterTeleport(1, 1000.0, 5145.0, 45.0);
						CharacterTeleport(2, 1000.0, 5145.0, 45.0);
						CharacterTeleport(3, 1000.0, 5145.0, 45.0);
					}
					
					//-> Login Theme Type (Season 6)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 3)
					{
						CharacterTeleport(4, 8172.84083, 19265.57287, 90.0);
						CharacterTeleport(0, 0.0, 8171.84083, 90.0);
						CharacterTeleport(1, 0.0, 8171.84083, 90.0);
						CharacterTeleport(2, 0.0, 8171.84083, 90.0);
						CharacterTeleport(3, 0.0, 8171.84083, 90.0);
					}

					//-> Login Theme Type (EX700)
					if(gProtect.m_MainInfo.SelectLoginThemeType == 4)
					{
						CharacterTeleport(4, 13629.0, 12339.0, 90.0);
						CharacterTeleport(0, 0.0, 13539.0, 90.0);
						CharacterTeleport(1, 0.0, 13539.0, 90.0);
						CharacterTeleport(2, 0.0, 13539.0, 90.0);
						CharacterTeleport(3, 0.0, 13539.0, 90.0);
					}

					gInterface.DrawIMG(CharacterSelect_4Button03, 471, 199, 0.878, 0.82);
				}
				
				if(SelectedHero == 4)
				{
					gInterface.DrawIMG(CharacterSelect_4Button03, 471, 199, 0.878, 0.82);
				}
				
				CharacterCharacteristics(4,148);
			}
		}
	}

	((void(__cdecl*)())0x005BB0B0)();
}

void CSCharacterS13::SelectCharButton(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	
	if(*(DWORD*)(MAIN_SCREEN_STATE) != ObjState::SwitchCharacter)
	{
		return;
	}
	
	if( gInterface.IsWorkZone(CharacterSelect_0Button01) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_0Button01].EventTick);
		
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_0Button01].OnClick = true;

			return;
		}
		
		gInterface.Data[CharacterSelect_0Button01].OnClick = false;
		
		if( Delay < 500 )
		{
			return;
		}
		
		gInterface.Data[CharacterSelect_0Button01].EventTick = GetTickCount();
	}

	else if( gInterface.IsWorkZone(CharacterSelect_1Button01) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_1Button01].EventTick);
		
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_1Button01].OnClick = true;

			return;
		}
		
		gInterface.Data[CharacterSelect_1Button01].OnClick = false;
		
		if( Delay < 500 )
		{
			return;
		}
		
		gInterface.Data[CharacterSelect_1Button01].EventTick = GetTickCount();
	}
	
	else if( gInterface.IsWorkZone(CharacterSelect_2Button01) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_2Button01].EventTick);
		
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_2Button01].OnClick = true;

			return;
		}
		
		gInterface.Data[CharacterSelect_2Button01].OnClick = false;
		
		if( Delay < 500 )
		{
			return;
		}
		
		gInterface.Data[CharacterSelect_2Button01].EventTick = GetTickCount();
	}
	
	else if( gInterface.IsWorkZone(CharacterSelect_3Button01) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_3Button01].EventTick);
		
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_3Button01].OnClick = true;

			return;
		}
		
		gInterface.Data[CharacterSelect_3Button01].OnClick = false;
		
		if( Delay < 500 )
		{
			return;
		}
		
		gInterface.Data[CharacterSelect_3Button01].EventTick = GetTickCount();
	}
	
	else if( gInterface.IsWorkZone(CharacterSelect_4Button01) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_4Button01].EventTick);
		
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_4Button01].OnClick = true;

			return;
		}
		
		gInterface.Data[CharacterSelect_4Button01].OnClick = false;
		
		if( Delay < 500 )
		{
			return;
		}
		
		gInterface.Data[CharacterSelect_4Button01].EventTick = GetTickCount();
	}
}