#include "stdafx.h"
#include "CSceneS2.h"
#include "Defines.h"
#include "TMemory.h"
#include "Util.h"
#include "Interface.h"
#include "zzzMathLib.h"
#include "Protect.h"
#include "Import.h"
#include "Config.h"
#include "CScene.h"

void LoginScreenS2(int a1, DWORD *a2)
{
	if (pMapNumber == 55)
	{
		glColor3f(1.0, 1.0, 1.0);
		BeginBitmap();
		pDrawImage(500021, 0.0, 25.0, 320.0, 320.0, 0, 0, 1.0, 1.0, 1, 1, 0.0);
		pDrawImage(500022, 320.0, 25.0, 320.0, 320.0, 0, 0, 1.0, 1.0, 1, 1, 0.0);
		EndOpengl();
		SetFloat((PVOID)(0x005DB53F), -2.014084447E38);
		SetFloat((PVOID)(0x005DB55D), -2.70652875E38);
		*(float*)0xE61E3C = 330000.0;
		*(float*)0x87933D0 = -96.5;
		*(float*)0x87933D4 = 0.0;
		*(float*)0x87933D8 = -36.0;
		*(float*)0x87933DC = 12778.0;
		*(float*)0x87933E0 = 12678.0;
		*(float*)0x87933E4 = 579.0;	
		*(float*)0xE61E40 = 35.0;
	}
}

void LogoMUmS2()
{
	if ( SceneFlag == 2 )
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		*(float*)0xE8CB18 = *(float*)0xE8CB18 + 0.01999999955296516;
		if ( *(float*)0xE8CB18 > 10.0 ) *(float*)0xE8CB18 = 10.0;
		EnableAlphaBlend();
		float v25 = *(float*)0xE8CB18 - 0.300000011920929;
		float v24 = *(float*)0xE8CB18 - 0.300000011920929;
		float v23 = *(float*)0xE8CB18 - 0.300000011920929;
		float v22 = *(float*)0xE8CB18 - 0.300000011920929;
		glColor4f(v22, v23, v24, v25);
		RenderBitmap(531019, 217.60001, 25.0, 204.8, 102.4, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		EnableAlphaTest(1);
		glColor4f(*(float*)0xE8CB18, *(float*)0xE8CB18, *(float*)0xE8CB18, *(float*)0xE8CB18);
		RenderBitmap(531018, 217.60001, 25.0, 204.8, 102.4, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		glEnable(GL_TEXTURE_2D);

		//-> Custom Server News
		if(gProtect.m_MainInfo.ServerNews == 1)
		{
			int PosX;
			PosX = 470;
		
			pDrawGUI(0x9969, (float)455 , (float)70 - 40, 173, 406);
		
			gInterface.DrawFormat(Color4f(Config.ColorText0_R, Config.ColorText0_G, Config.ColorText0_B, 255),510,47,250,1,Config.NewsText0);
			gInterface.DrawFormat(Color4f(Config.ColorText1_R, Config.ColorText1_G, Config.ColorText1_B, 255),480,77,250,1,Config.NewsText1);
			gInterface.DrawFormat(Color4f(Config.ColorText2_R, Config.ColorText2_G, Config.ColorText2_B, 255),480,87,250,1,Config.NewsText2);
			gInterface.DrawFormat(Color4f(Config.ColorText3_R, Config.ColorText3_G, Config.ColorText3_B, 255),480,97,250,1,Config.NewsText3);
			gInterface.DrawFormat(Color4f(Config.ColorText4_R, Config.ColorText4_G, Config.ColorText4_B, 255),480,107,250,1,Config.NewsText4);
			gInterface.DrawFormat(Color4f(Config.ColorText5_R, Config.ColorText5_G, Config.ColorText5_B, 255),480,117,250,1,Config.NewsText5);
			gInterface.DrawFormat(Color4f(Config.ColorText6_R, Config.ColorText6_G, Config.ColorText6_B, 255),480,127,250,1,Config.NewsText6);
			gInterface.DrawFormat(Color4f(Config.ColorText7_R, Config.ColorText7_G, Config.ColorText7_B, 255),480,137,250,1,Config.NewsText7);
			gInterface.DrawFormat(Color4f(Config.ColorText8_R, Config.ColorText8_G, Config.ColorText8_B, 255),480,147,250,1,Config.NewsText8);
			gInterface.DrawFormat(Color4f(Config.ColorText9_R, Config.ColorText9_G, Config.ColorText9_B, 255),480,157,250,1,Config.NewsText9);
			gInterface.DrawFormat(Color4f(Config.ColorText10_R, Config.ColorText10_G, Config.ColorText10_B, 255),480,167,250,1,Config.NewsText10);
			gInterface.DrawFormat(Color4f(Config.ColorText11_R, Config.ColorText11_G, Config.ColorText11_B, 255),480,177,250,1,Config.NewsText11);
			gInterface.DrawFormat(Color4f(Config.ColorText12_R, Config.ColorText12_G, Config.ColorText12_B, 255),480,187,250,1,Config.NewsText12);
			gInterface.DrawFormat(Color4f(Config.ColorText13_R, Config.ColorText13_G, Config.ColorText13_B, 255),480,197,250,1,Config.NewsText13);
			gInterface.DrawFormat(Color4f(Config.ColorText14_R, Config.ColorText14_G, Config.ColorText14_B, 255),480,207,250,1,Config.NewsText14);
			gInterface.DrawFormat(Color4f(Config.ColorText15_R, Config.ColorText15_G, Config.ColorText15_B, 255),480,217,250,1,Config.NewsText15);
			gInterface.DrawFormat(Color4f(Config.ColorText16_R, Config.ColorText16_G, Config.ColorText16_B, 255),480,227,250,1,Config.NewsText16);
			gInterface.DrawFormat(Color4f(Config.ColorText17_R, Config.ColorText17_G, Config.ColorText17_B, 255),480,237,250,1,Config.NewsText17);
			gInterface.DrawFormat(Color4f(Config.ColorText18_R, Config.ColorText18_G, Config.ColorText18_B, 255),480,247,250,1,Config.NewsText18);
			gInterface.DrawFormat(Color4f(Config.ColorText19_R, Config.ColorText19_G, Config.ColorText19_B, 255),480,257,250,1,Config.NewsText19);
			gInterface.DrawFormat(Color4f(Config.ColorText20_R, Config.ColorText20_G, Config.ColorText20_B, 255),480,267,250,1,Config.NewsText20);
			gInterface.DrawFormat(Color4f(Config.ColorText21_R, Config.ColorText21_G, Config.ColorText21_B, 255),480,277,250,1,Config.NewsText21);
			gInterface.DrawFormat(Color4f(Config.ColorText22_R, Config.ColorText22_G, Config.ColorText22_B, 255),480,287,250,1,Config.NewsText22);
			gInterface.DrawFormat(Color4f(Config.ColorText23_R, Config.ColorText23_G, Config.ColorText23_B, 255),480,297,250,1,Config.NewsText23);
			gInterface.DrawFormat(Color4f(Config.ColorText24_R, Config.ColorText24_G, Config.ColorText24_B, 255),480,307,250,1,Config.NewsText24);
			gInterface.DrawFormat(Color4f(Config.ColorText25_R, Config.ColorText25_G, Config.ColorText25_B, 255),480,317,250,1,Config.NewsText25);
			gInterface.DrawFormat(Color4f(Config.ColorText26_R, Config.ColorText26_G, Config.ColorText26_B, 255),480,327,250,1,Config.NewsText26);
			gInterface.DrawFormat(Color4f(Config.ColorText27_R, Config.ColorText27_G, Config.ColorText27_B, 255),480,337,250,1,Config.NewsText27);
			gInterface.DrawFormat(Color4f(Config.ColorText28_R, Config.ColorText28_G, Config.ColorText28_B, 255),480,347,250,1,Config.NewsText28);
			gInterface.DrawFormat(Color4f(Config.ColorText29_R, Config.ColorText29_G, Config.ColorText29_B, 255),480,357,250,1,Config.NewsText29);
			gInterface.DrawFormat(Color4f(Config.ColorText30_R, Config.ColorText30_G, Config.ColorText30_B, 255),480,367,250,1,Config.NewsText30);
			gInterface.DrawFormat(Color4f(Config.ColorText31_R, Config.ColorText31_G, Config.ColorText31_B, 255),480,377,250,1,Config.NewsText31);
			gInterface.DrawFormat(Color4f(Config.ColorText32_R, Config.ColorText32_G, Config.ColorText32_B, 255),480,387,250,1,Config.NewsText32);
			gInterface.DrawFormat(Color4f(Config.ColorText33_R, Config.ColorText33_G, Config.ColorText33_B, 255),480,397,250,1,Config.NewsText33);
		
			gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 74, 459, 150, 3, "Powered By Emershow");
			gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 74, 469, 150, 3, "2021 © Webzen all rights reserved");
		}
	}
}

void sub_4D5EC0S2()
{
	LogoMUmS2();
	sub_4D5EC0R();
}

void CSceneS2()
{
	SetCompleteHook(0xE8, 0x004D7EB1,&sub_4D5EC0S2);
	SetCompleteHook(0xE8, 0x004D76FB, &LoginScreenS2);//Select Server
	SetCompleteHook(0xE8, 0x004D79C3, &LoginScreenS2);//Select Server
	SetDword((LPVOID)0x004D75F0, 5);
}