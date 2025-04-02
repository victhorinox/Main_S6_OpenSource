#include "stdafx.h"
#include "Common.h"
#include "Defines.h"
#include "Import.h"
#include "Interface.h"
#include "Offset.h"
#include "Util.h"
#include "TMemory.h"
#include "Protect.h"
#include "CLoginWin.h"
#include "AutoLogin.h"

BYTE GensBattleMapCount = 0;
BYTE GensMoveIndexCount = 0;
BYTE GensBattleMap[120];
BYTE GensMoveIndex[120];

int DisableStaticEffect;
int DisableDynamicEffect;
int DisableSkillEffect;
int DisableGlowEffect;
int Anisotropy;
int MaxAnisotropy;
int Linear;
int GMT;
int Tron;
int MiniMap;
int Fog;
int offhelper;
int upgradeActiveChat;

__declspec(naked) void GlobalMessagem()
{
	static DWORD ADDS = 0x00597698;

	_asm
	{
		CMP DWORD PTR SS:[EBP-8],1200
		JMP [ADDS]
	}
}

__declspec(naked) void ItemTooltipRender()
{
	static DWORD Addr = 0x007E5CB6;
	static DWORD Addr_Exc = 0;
	static DWORD Addr_Acc = 0;

	_asm
	{
		MOV ECX, DWORD PTR SS : [EBP + 0x10]
		MOVZX EAX,BYTE PTR DS:[ECX+0x17]
		MOV Addr_Exc, EAX
			MOVZX EDX,BYTE PTR DS:[ECX+0x18]
		MOV Addr_Acc, EDX
	}
	
	if(Addr_Exc >= 1 && Addr_Acc >= 1)
	{
		_asm
		{
			PUSH 1                                  ; /Arg7 = 00000001
			PUSH 0                                  ; |Arg6 = 00000000
			PUSH 3                                  ; |Arg5 = 00000003
			PUSH 0                                  ; |Arg4 = 00000000
			MOV EAX,DWORD PTR SS:[EBP-0x74]            ; |
			PUSH EAX                                ; |Arg3
			MOV ECX,DWORD PTR SS:[EBP+0xC]            ; |
			//ADD ECX, 120
			PUSH 0x5                                ; |Arg2
			MOV EDX,DWORD PTR SS:[EBP+0x8]            ; |
			PUSH EDX                                ; |Arg1
			JMP [Addr]
		}
	}
	
	else
	{
		_asm
		{
			PUSH 1                                  ; /Arg7 = 00000001
			PUSH 0                                  ; |Arg6 = 00000000
			PUSH 3                                  ; |Arg5 = 00000003
			PUSH 0                                  ; |Arg4 = 00000000
			MOV EAX,DWORD PTR SS:[EBP-0x74]            ; |
			PUSH EAX                                ; |Arg3
			MOV ECX,DWORD PTR SS:[EBP+0xC]            ; |
			//ADD ECX, 120
			PUSH ECX                                ; |Arg2
			MOV EDX,DWORD PTR SS:[EBP+0x8]            ; |
			PUSH EDX                                ; |Arg1
			JMP [Addr]
		}
	}
}

void __declspec(naked) CSetPlayerSwimStop()
{
	static DWORD CReturn = 0x0054EE7F;
	_asm
	{
			CMP DWORD PTR DS:[0xE61E18],7
			je ReturnLoad
			CMP DWORD PTR DS:[0xE61E18],130//ID del Mapa
			je ReturnLoad
			// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}

void __declspec(naked) CSetPlayerSwimWalk()
{
	static DWORD CReturn = 0x0054FFBE;
	_asm
	{
			CMP DWORD PTR DS:[0xE61E18],7
			je ReturnLoad
			CMP DWORD PTR DS:[0xE61E18],130//ID del Mapa
			je ReturnLoad
			// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}

void __declspec(naked) CRenderCharacterBackItem_Swim()
{
	static DWORD CReturn = 0x005880B4;
	_asm
	{
			CMP DWORD PTR DS:[0xE61E18],7
			je ReturnLoad
			CMP DWORD PTR DS:[0xE61E18],130//ID del Mapa
			je ReturnLoad
			// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}

void __declspec(naked) CPlayWalkSound_Swim()
{
	static DWORD CReturn = 0x00560CED;
	_asm
	{
			CMP DWORD PTR DS:[0xE61E18],7
			je ReturnLoad
			CMP DWORD PTR DS:[0xE61E18],130//ID del Mapa
			je ReturnLoad

			// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}

void RotateDmg(float& X, float& Y, float D)
{
	const float Rad = 0.01745329f;
	float sinTh = sin(Rad * (*(float*)0x87933D8));
	float cosTh = cos(Rad * (*(float*)0x87933D8));

	X += D / 0.7071067f * cosTh / 2;
	Y -= D / 0.7071067f * sinTh / 2;
}

__declspec(naked) void RotateFix()
{
	static DWORD jmpBack = 0x0063752D;

	_asm
	{
		Lea Eax, [Ebp - 0x38];
		Lea Ecx, [Ebp - 0x3C];
		Push Dword Ptr[Ebp + 0x18];
		Push Eax;
		Push Ecx;
		Call RotateDmg;
		Add Esp, 0xC;
		jmp[jmpBack];
	}
}

Naked(NoTopName)
{
	static DWORD Call1 = 0x00790B50;
	static DWORD Call2 = 0x0041FE10;
	static DWORD Call3 = 0x00420120;
	static DWORD Call4 = 0x00420150;
	static DWORD Call5 = 0x004200F0;
	static DWORD Call8 = 0x00420040;
	static DWORD Call9 = 0x00402320;

	_asm
	{
		PUSH EBP
		MOV EBP,ESP
		SUB ESP,0x24
		MOV DWORD PTR SS:[EBP-0x4],ECX
		PUSH ECX                                
		FLD DWORD PTR DS:[0xD2CB5C]               
		FSTP DWORD PTR SS:[ESP]                 
		PUSH ECX                                
		FLD DWORD PTR DS:[0xD254E0]               
		FSTP DWORD PTR SS:[ESP]                 
		MOV EAX,DWORD PTR SS:[EBP-0x4]          
		MOV ECX,DWORD PTR DS:[EAX+0x14]         
		ADD ECX,0x1B                            
		MOV DWORD PTR SS:[EBP-0x8],ECX          
		FILD DWORD PTR SS:[EBP-0x8]             
		PUSH ECX                                
		FSTP DWORD PTR SS:[ESP]                 
		MOV EDX,DWORD PTR SS:[EBP-0x4]          
		MOV EAX,DWORD PTR DS:[EDX+0x10]         
		ADD EAX,0x0A                            
		MOV DWORD PTR SS:[EBP-0xC],EAX            
		FILD DWORD PTR SS:[EBP-0xC]               
		PUSH ECX                                
		FSTP DWORD PTR SS:[ESP]                 
		PUSH 0x7AAC                             
		CALL [Call1]
		ADD ESP,0x14
		MOV ECX,DWORD PTR DS:[0xE8C588]
		PUSH ECX
		CALL [Call2]
		MOV ECX,EAX                             
		CALL [Call3]
		PUSH 0x0
		CALL [Call2]
		MOV ECX,EAX                             
		CALL [Call5]
		MOV EDX,DWORD PTR SS:[EBP-0x4]
		CMP DWORD PTR DS:[EDX+0x21C],0x0
		PUSH ECX                                
		FLD DWORD PTR DS:[0xD2CB5C]               
		FSTP DWORD PTR SS:[ESP]                 
		PUSH ECX                                
		FLD DWORD PTR DS:[0xD22C0C]               
		FSTP DWORD PTR SS:[ESP]                 
		MOV EAX,DWORD PTR SS:[EBP-0x4]          
		MOV ECX,DWORD PTR DS:[EAX+0x14]         
		ADD ECX,0x1B                            
		MOV DWORD PTR SS:[EBP-0x10],ECX         
		FILD DWORD PTR SS:[EBP-0x10]            
		PUSH ECX                                
		FSTP DWORD PTR SS:[ESP]                 
		MOV EDX,DWORD PTR SS:[EBP-0x4]          
		MOV EAX,DWORD PTR DS:[EDX+0x10]         
		ADD EAX,0x0A                            
		MOV DWORD PTR SS:[EBP-0x14],EAX         
		FILD DWORD PTR SS:[EBP-0x14]            
		PUSH ECX                                
		FSTP DWORD PTR SS:[ESP]                 
		PUSH 0x7AAD                                
		CALL [Call1]
		ADD ESP,0x14
		PUSH 0x0FF
		PUSH 0x0FF
		PUSH 0x0FF
		PUSH 0x0FF
		CALL [Call2]
		MOV ECX,EAX                                
		CALL [Call8]
		PUSH 0x0
		PUSH 0x3
		PUSH 0x0
		PUSH 0x30
		PUSH 0x474                                    
		MOV ECX,0x08128ADC                 
		CALL [Call9]
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX,0x22
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x4]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,0x0A
		PUSH ECX
		CALL [Call2]
		MOV ECX,EAX                                
		CALL [Call4]                         
		PUSH 0x0B5
		PUSH 0x0B5
		PUSH 0x0B5
		PUSH 0x0B5
		CALL [Call2]
		MOV ECX,EAX                               
		CALL [Call8]    
		MOV ESP,EBP
		POP EBP
		RETN
	}
}

void InitCommon() // OK
{
	gCLoginWin.Load();
	//AutoLogin.Load();
	//--
	SetCompleteHook(0xE9, 0x0083F785, 0x0083F78F);
	SetCompleteHook(0xE9, 0x0083F8C9, 0x0083F8D3);
	//-
	SetCompleteHook(0xE9, 0x0083E6CB, 0x0083E6D5);
	SetCompleteHook(0xE9, 0x0083E729, 0x0083E733);
	//--
	SetCompleteHook(0xE9, 0x0083F572, 0x0083F57C);
	SetCompleteHook(0xE9, 0x0083F57E, 0x0083F5B2);
	SetCompleteHook(0xE9, 0x0083F5D0, &NoTopName);
	SetCompleteHook(0xE9, 0x0083E6CB, 0x0083E6D5);
	SetCompleteHook(0xE9, 0x0083E729, 0x0083E733);
	//--


	SetCompleteHook(0xE9, 0x0063764C, &RotateFix); //-> Fix Rotate Damage on Camera 3d

	//SetCompleteHook(0xE9, 0x00597691, &GlobalMessagem);

	SetByte((0x00597691+4),0x04); //-> Size Global Msg

	SetCompleteHook(0xE9, 0x0059AFFA, 0x0059B00E); //-> Fix Monstros ao morre com skills do SM

	SetCompleteHook(0xE9, 0x0054EE78, &CSetPlayerSwimStop);
	SetCompleteHook(0xE9, 0x0054FFB7, &CSetPlayerSwimWalk);
	SetCompleteHook(0xE9, 0x005880AD, &CRenderCharacterBackItem_Swim);
	SetCompleteHook(0xE9, 0x00560CE6, &CPlayWalkSound_Swim);

	//-> Fix Evol Character
	SetDword(0x0057F9FA + 3, 304); //-- slot armor
	SetDword(0x0057FA3D + 3, 340); //-- slot pants
	SetDword(0x0057FA7F + 3, 376); //-- slot glove
	SetDword(0x0057FAC1 + 3, 412); //-- slot boot

//	SetCompleteHook(0xE9, 0x007E5CA2, &ItemTooltipRender); //-> Fix ToolTip Render

	SetCompleteHook(0xE8,0x007D2B0C,&FixHelperMouseClickC); //-> - [AntiDupe] Disabled Helper Config window click when use the Chaos machine

	SetCompleteHook(0xE9,0x0040B154,&LoginTab);

	SetCompleteHook(0xFF,0x0064A79A,&CheckMasterLevel); // C1:16

	SetCompleteHook(0xFF,0x0064A85F,&CheckMasterLevel); // C1:16

	SetCompleteHook(0xFF,0x00656E03,&CheckMasterLevel); // C1:48

	SetCompleteHook(0xFF,0x0064AB3D,&CheckMasterLevel); // C1:9C

	SetCompleteHook(0xFF,0x0064AC02,&CheckMasterLevel); // C1:9C

	SetCompleteHook(0xFF,0x0063DDF2,&CheckMasterLevel); // C1:F3:03

	SetCompleteHook(0xFF,0x0063DF89,&CheckMasterLevel); // C1:F3:03

	SetCompleteHook(0xFF,0x0063EA4C,&CheckMasterLevel); // C1:F3:04

	SetCompleteHook(0xFF,0x0064CA0C,&CheckMasterLevel); // LevelUp

	SetCompleteHook(0xFF,0x0077FAF9,&CheckMasterLevel); // Print Level

	SetCompleteHook(0xFF,0x0081071B,&CheckMasterLevel); // Experience Bar

	SetCompleteHook(0xFF,0x0081079B,&CheckMasterLevel); // Experience Bar

	SetCompleteHook(0xFF,0x0047FE31,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x0059890D,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x0059A399,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x0059A93C,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x0059B13B,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x005A4261,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x005A4D52,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x005B6117,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x0065A6CE,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x00727987,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x007861F1,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x007D32FA,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x007D3B0D,&CheckGensBattleMap);

	SetCompleteHook(0xE9,0x008317BD,&CompareGensMoveIndex);

	//SetCompleteHook(0xFF,0x00777DC8,&DrawEffectsPic); //??

	//SetByte(0x004ADD59+3, 180); //Efeito Lite

	//SetCompleteHook(0xFF,0x007EFC93,&CheckIsLuckyItem);
	
	DisableStaticEffect		= GetPrivateProfileIntA("AntiLag", "DisableStatasdasdicEffect", 0, "./Settings.ini");
	DisableDynamicEffect	= GetPrivateProfileIntA("AntiLag", "DisableDynasdasdamicEffect", 0, "./Settings.ini");
	DisableSkillEffect		= GetPrivateProfileIntA("AntiLag", "DisableSkillasdasdEffect", 0, "./Settings.ini");
	DisableGlowEffect		= GetPrivateProfileIntA("AntiLag", "DisableGasdasdlowEffect", 0, "./Settings.ini");

	Anisotropy				= GetPrivateProfileIntA("Graphics","Anisotropy",1,"./Settings.ini");
	MaxAnisotropy			= GetPrivateProfileIntA("Graphics","MaxAnisotropy",1,"./Settings.ini");
	Linear					= GetPrivateProfileIntA("Graphics","Linear",1,"./Settings.ini");
	Tron					= GetPrivateProfileIntA("Graphics","TronEffects", 0, "./Settings.ini");
	MiniMap					= GetPrivateProfileIntA("Graphics","MiniMap", 0, "./Settings.ini");
	Fog						= GetPrivateProfileIntA("Graphics","Fog",1,"./Settings.ini");
	
	GMT						= GetPrivateProfileIntA("Other","ServerTime",0,"./Settings.ini");

	offhelper = 0;

	upgradeActiveChat       = GetPrivateProfileIntA("Interface", "ActiveChatUpgrade", 1, "./Settings.ini");

	//-> Remove Language System
	SetRange((LPVOID)0x004D1360,28,0x90); //-> Remove Registry
	SetDword(0x006340AA+1,(DWORD)"Data\\Local\\Item.bmd"); //Item.bmd
	SetDword(0x006340E3+1,(DWORD)"Data\\Local\\MoveReq.bmd"); //MoveReq.bmd
	SetDword(0x006345D4+1,(DWORD)"Data\\Local\\Text.bmd"); //Text.bmd
	SetDword(0x006341B7+1,(DWORD)"Data\\Local\\Skill.bmd"); //Skill.bmd
	SetDword(0x006341F0+1,(DWORD)"Data\\Local\\SocketItem.bmd"); //SocketItem.bmd
	SetDword(0x00634071+1,(DWORD)"Data\\Local\\Dialog.bmd"); //Dialog.bmd
	SetDword(0x00634141+1,(DWORD)"Data\\Local\\NpcName.bmd"); //NpcName.bmd
	SetDword(0x0063417A+1,(DWORD)"Data\\Local\\Quest.bmd"); //Quest.bmd
	SetDword(0x004AD7F6+1,(DWORD)"/BuffEffect"); //BuffEffect.bmd
	SetDword(0x007E31DC+1,(DWORD)""); //ItemLevelTooltip.bmd
	SetDword(0x004E8785+1,(DWORD)""); //ItemSetOption.bmd
	SetDword(0x007E308D+1,(DWORD)""); //ItemToolTip.bmd
	SetDword(0x007E333D+1,(DWORD)""); //ItemToolTipText.bmd
	SetDword(0x0047BA79+1,(DWORD)"\\JewelOfHarmonyOption"); //JewelOfHarmonyOption.bmd
	SetDword(0x00634271+1,(DWORD)""); //MasterSkillTooltip.bmd
	SetDword(0x00521663+1,(DWORD)"\\QuestWords"); //QuestWords.bmd
	SetDword(0x00521788+1,(DWORD)"\\QuestWords"); //QuestWords.bmd
	SetDword(0x00856131+1,(DWORD)"\\Slide"); //Slide.bmd
	SetDword(0x0082B4CC+1,(DWORD)"Data\\Local\\%s\\Minimap\\Minimap_%s%s.bmd"); //Minimap_World.bmd
	SetDword(0x00634228+1,(DWORD)".\\Data\\Local\\Gate.bmd"); //Gate.bmd

	//-> Remove Webzenlogo.OZJ
	SetDword(0x00631A4F+1,(DWORD)"Interface\\win_mark.tga"); //-> Local\\Webzenlogo.OZJ

	//-> Only One Map Name For La Cleon
	SetDword(0x0047F6C3+1,(DWORD)"mapname_raklion.tga"); //mapname_raklionboss.tga

	//-> Remove 2 Loadings
	SetDword(0x004D57C7+1,(DWORD)"Interface\\lo_back_im01.jpg");
	SetDword(0x004D57E7+1,(DWORD)"Interface\\lo_back_im02.jpg");
	SetDword(0x004D5807+1,(DWORD)"Interface\\lo_back_im03.jpg");
	SetDword(0x004D5827+1,(DWORD)"Interface\\lo_back_im04.jpg");
	SetDword(0x004D5847+1,(DWORD)"Interface\\lo_back_im05.jpg");
	SetDword(0x004D5867+1,(DWORD)"Interface\\lo_back_im06.jpg");

	//-> Remove gamecensorship_12.ozt
	SetDword(0x004F877A+1,(DWORD)"Interface\\win_mark.tga"); //-> Interface\\gamecensorship_12.ozt
	SetDword(0x004F879A+1,(DWORD)"Interface\\win_mark.tga"); //-> Interface\\gamecensorship_15.ozt
	SetDword(0x004F87BA+1,(DWORD)"Interface\\win_mark.tga"); //-> Interface\\gamecensorship_18.ozt
	SetDword(0x004F87DA+1,(DWORD)"Interface\\win_mark.tga"); //-> Interface\\gamecensorship_fear.ozt
	SetDword(0x004F87FA+1,(DWORD)"Interface\\win_mark.tga"); //-> Interface\\gamecensorship_vio.ozt
	
	//-> Remove lo_121518.OZT
	SetDword(0x004D564C+1,(DWORD)"Interface\\win_mark.tga"); //-> lo_121518.tga
	
	//-> Remove menu01_new2_SD.ozj
	SetDword(0x006339DA+1,(DWORD)"Interface\\win_mark.tga"); //-> Interface\\menu01_new2_SD.ozj

	//-> Remove New_lo_webzen_logo.tga
	SetDword(0x004D566C+1,(DWORD)"Interface\\win_mark.tga"); //-> New_lo_webzen_logo.tga

	//-> Remove cr_mu_lo.tga.tga
	SetDword(0x00631256+1,(DWORD)"Interface\\win_mark.tga"); //-> cr_mu_lo.tga.tga

	//-> Remove MacroUI Textures
	SetDword(0x0080B6BA+1,(DWORD)"Interface\\MacroUI\\MacroUI_Gauge_Bar_(Y).jpg"); //-> MacroUI_Gauge_Bar_(B).OZJ
	SetDword(0x0080B6DA+1,(DWORD)"Interface\\MacroUI\\MacroUI_Gauge_Bar_(Y).jpg"); //-> MacroUI_Gauge_Bar_(G).OZJ
	SetDword(0x0080B71A+1,(DWORD)"Interface\\MacroUI\\MacroUI_Gauge_Bar_(Y).jpg"); //-> MacroUI_Gauge_Bar_(O).OZJ
	SetDword(0x0080B73A+1,(DWORD)"Interface\\MacroUI\\MacroUI_Gauge_Bar_(Y).jpg"); //-> MacroUI_Gauge_Bar_(R).OZJ

	//-> Remove Cash Shop
	SetDword(0x009460FA+1,(DWORD)"Interface\\mu_title.tga"); //-> Gift
	SetDword(0x0094611A+1,(DWORD)"Interface\\mu_title.tga"); //-> Cash
	SetDword(0x0094613A+1,(DWORD)"Interface\\mu_title.tga"); //-> Reset

	//server_credit_b_all.tga
	SetDword(0x00631176+1,(DWORD)"Interface\\win_mark.tga");

	//->  Client Error logs moved to Logs folder
	if(gProtect.m_MainInfo.RemoveMuErrorLog == 0)
	{
		static char* LogName = "Data\\Logs\\MuError.log";
		static char* LogName2 = "Data\\Logs\\MuError_%d.log";
		static char* DumpName = "Data\\Logs\\MuError.dmp";
		
		SetDword((PVOID)(0x0096AA48+1),(DWORD)LogName);
		SetDword((PVOID)(0x0096AACF+1),(DWORD)LogName);
		SetDword((PVOID)(0x0096AB5B+1),(DWORD)LogName2);
		SetDword((PVOID)(0x004D1D0B+1),(DWORD)DumpName);
		SetByte((PVOID)(0x007AF175+1),9);
		SetByte((PVOID)(0x007AF415+1),9);
		SetByte((PVOID)(0x007AF795+1),9);
		SetByte((PVOID)(0x007B0315+1),9);
	}

	//-> Remove MuError.log option
	if(gProtect.m_MainInfo.RemoveMuErrorLog == 1)
	{
		static char* LogName = " ";
		static char* LogName2 = " ";
		static char* DumpName = " ";
		
		SetDword((PVOID)(0x0096AA48+1),(DWORD)LogName);
		SetDword((PVOID)(0x0096AACF+1),(DWORD)LogName);
		SetDword((PVOID)(0x0096AB5B+1),(DWORD)LogName2);
		SetDword((PVOID)(0x004D1D0B+1),(DWORD)DumpName);
		SetByte((PVOID)(0x007AF175+1),9);
		SetByte((PVOID)(0x007AF415+1),9);
		SetByte((PVOID)(0x007AF795+1),9);
		SetByte((PVOID)(0x007B0315+1),9);
	}

	//-> Remove +15 Eye Effects
	MemorySet(0x0057BF78,0x90,0x05);	//-> pin_lights eyes
	MemorySet(0x0057C125,0x90,0x05);	//-> pin_lights eyes
	MemorySet(0x0057BE80,0x90,0x05);	//-> JointLaser01 eyes
	MemorySet(0x0057C057,0x90,0x05);	//-> JointLaser01 eyes
	MemorySet(0x0057BF0E,0x90,0x05);	//-> shiny05 eyes
	MemorySet(0x0057C0BB,0x90,0x05);	//-> shiny05 eyes

	//- Fix Dark horse look around
	SetCompleteHook(0xE9,0x0064452A,0x00644537);

	//-> Remove Some Buttons
	MemorySet(0x0040A7EF,0x90,0x5); //RETIRA BOTÃO MENU TELA PRINCIPAL
	MemorySet(0x0040A87E,0x90,0x5); //RETIRA BOTÃO CREDIT TELA PRINCIPAL

	SetCompleteHook(0xE9,0x005DB322,0x5DB408); // Fix 3D Cam in Santa Village

	//-> Walk with Full Map Open
	MemorySet(0x82AC07,0x90,0x5); //Background
	MemorySet(0x82B03D,0x90,0x5); //Moldura
	MemorySet(0x82B0A7,0x90,0x5); //Moldura
	MemorySet(0x82B18B,0x90,0x5); //Moldura
	MemorySet(0x82B1FA,0x90,0x5); //Moldura
	MemorySet(0x82B21B,0x90,0x5); //Moldura
	MemorySet(0x82B2CB,0x90,0x5); //Moldura
	MemorySet(0x82B339,0x90,0x5); //Moldura
	MemorySet(0x82B3B7,0x90,0x5); //Moldura
	MemorySet(0x82B3CA,0x90,0x5); //Button
	MemorySet(0x82B772,0x90,0x5); //Walk

	//-> Black Bar Size
	if(gProtect.m_MainInfo.SelectLoginThemeType != 0 && gProtect.m_MainInfo.SelectLoginThemeType != 1 && gProtect.m_MainInfo.SelectLoginThemeType != 2)
	{
		SetDword((PVOID)(0x004D7A0E),480);//Select Server
		SetByte((PVOID)(0x004D7A18),0);//Select Server
		SetDword((PVOID)(0x004D7179),480);//Select Character
		SetByte((PVOID)(0x004D7183),0);//Select Character
	}

	//-> Fix GM Wings on Blood Castle
	//SetCompleteHook(0xE9,0x005880F0,0x0058811F);
	//SetDword(0x00588444+3,4095);

	//-> Fix Trade Zen Limit //-> Fix Store Zen Limit
    SetByte((PVOID)(0x007AF175+1),9);
    SetByte((PVOID)(0x007AF415+1),9);
    SetByte((PVOID)(0x007AF795+1),9);
    SetByte((PVOID)(0x007B0315+1),9);

	//-> Fix Map Name Coordinate Text Position
	SetByte(0x007D2E19+2, 4); //Pos Y
	//SetByte(0x007D2E26+2, 10); //Pos X

	//-> Custom ImgsMapName (97d ~ 99b)
	if(gProtect.m_MainInfo.ImgsMapNameType == 0)
	{
		SetDword(0x0047E21E+1,(DWORD)"Empty.tga"); //-> Lorencia.tga
	}

	//-> Buff Icons (Small)
	if(gProtect.m_MainInfo.BuffIconType == 1)
	{
		SetFloat((PVOID)(0x00D43220), 10);
		SetFloat((PVOID)(0x00D43224), 14);
		SetByte((PVOID)(0x00777E70), 0x16);
		//--
		SetDword(0x0077823A+1,(DWORD)"Custom\\Interface\\small_newui_statusicon.jpg");
		SetDword(0x0077825A+1,(DWORD)"Custom\\Interface\\small_newui_statusicon2.jpg");
		SetDword(0x0077827A+1,(DWORD)"Custom\\Interface\\small_newui_statusicon3.jpg");
	}

	//-> Buff Icons (Disabled)
	if(gProtect.m_MainInfo.BuffIconType == 2)
	{
		SetFloat((PVOID)(0x00D43220), 0);
		SetFloat((PVOID)(0x00D43224), 0);
		SetByte((PVOID)(0x00777E70), 0x00);
	}

	//-> Custom Master Skill Tree Type (EX700)
	if(gProtect.m_MainInfo.SkillTreeType == 1)
	{
	
		SetDword(0x0063424F+1,(DWORD)"Data\\Custom\\Local\\MasterSkillTreeData.bmd");
	}

	//-> Custom Master Skill Tree Type (S13)
	if(gProtect.m_MainInfo.SkillTreeType == 2)
	{
		SetDword(0x0063424F+1,(DWORD)"Data\\Custom\\Local\\MasterSkillTreeDataEx.bmd");
	}
}

BOOL CheckIsLuckyItem(int ItemID) // OK
{
	bool result;
	
	if (ItemID < 4158 || ItemID > 4168)
	{
		if (ItemID < 3646 || ItemID > 3656)
		{
			if (ItemID < 5694 || ItemID > 5704)
			{
				if (ItemID < 5182 || ItemID > 5192)
					result = ItemID >= 4670 && ItemID <= 4680;
				else
					result = 1;
			}

			else
			{
				result = 1;
			}
		}

		else
		{
			result = 1;
		}
	}

	else
	{
		result = 1;
	}

	return result;
}

BOOL CheckGensBattleMap(int map) // OK
{
	for(int n=0;n < GensBattleMapCount;n++)
	{
		if(GensBattleMap[n] == map)
		{
			return 1;
		}
	}

	return 0;
}

BOOL CheckGensMoveIndex(int idx) // OK
{
	for(int n=0;n < GensMoveIndexCount;n++)
	{
		if(GensMoveIndex[n] == idx)
		{
			return 1;
		}
	}

	return 0;
}

__declspec(naked) void LoginTab() // OK
{
	static DWORD LoginTabAddress1 = 0x0040B16F;
	
	__asm
	{
		Push 0
		Mov Eax,Dword Ptr Ss:[Ebp-0x38]
		Mov Ecx,Dword Ptr Ds:[Eax+0x350]
		Mov Edx,Dword Ptr Ss:[Ebp-0x38]
		Mov Eax,Dword Ptr Ds:[Edx+0x350]
		Mov Edx,Dword Ptr Ds:[Eax]
		Call Dword Ptr Ds:[Edx+0x30]
		Mov Eax,Dword Ptr Ss:[Ebp-0x38]
		Mov Ecx,Dword Ptr Ds:[Eax+0x354]
		Push Ecx
		Mov Edx,Dword Ptr Ss:[Ebp-0x38]
		Mov Ecx,Dword Ptr Ds:[Edx+0x350]
		Mov Eax,Dword Ptr Ss:[Ebp-0x38]
		Mov Edx,Dword Ptr Ds:[Eax+0x350]
		Mov Eax,Dword Ptr Ds:[Edx]
		Call Dword Ptr Ds:[Eax+0x58]
		Mov Ecx,Dword Ptr Ss:[Ebp-0x38]
		Mov Edx,Dword Ptr Ds:[Ecx+0x350]
		Push Edx
		Mov Eax,Dword Ptr Ss:[Ebp-0x38]
		Mov Ecx,Dword Ptr Ds:[Eax+0x354]
		Mov Edx,Dword Ptr Ss:[Ebp-0x38]
		Mov Eax,Dword Ptr Ds:[Edx+0x354]
		Mov Edx,Dword Ptr Ds:[Eax]
		Call Dword Ptr Ds:[Edx+0x58]
		Jmp [LoginTabAddress1]
	}
}

__declspec(naked) void CheckMasterLevel() // OK
{
	static DWORD CheckMasterLevelAddress1 = 0x005875A0;

	_asm
	{
		Push Ebp
		Mov Ebp,Esp
		Mov Eax,Dword Ptr Ds:[MAIN_CHARACTER_STRUCT]
		Xor Ecx,Ecx
		Mov Cx,Word Ptr Ds:[Eax+0x0E]
		Cmp Ecx,0x190
		Je NEXT
		Xor Eax,Eax
		Jmp EXIT
		NEXT:
		Xor Edx,Edx
		Mov Dl,Byte Ptr Ss:[Ebp+0x08]
		Push Edx
		Call [CheckMasterLevelAddress1]
		Add Esp,0x04
		EXIT:
		Pop Ebp
		Retn
	}
}

__declspec(naked) void CompareGensMoveIndex() // OK
{
	static DWORD CheckGensMoveIndexAddress1 = 0x0051B090;
	static DWORD CheckGensMoveIndexAddress2 = 0x008317FC;
	static DWORD CheckGensMoveIndexAddress3 = 0x008317EA;

	__asm
	{
		Lea Ecx,Dword Ptr Ss:[Ebp-0x08]
		Call [CheckGensMoveIndexAddress1]
		Mov Ecx,Dword Ptr Ds:[Eax]
		Mov Edx,Dword Ptr Ds:[Ecx]
		Push Edx
		Call [CheckGensMoveIndex]
		Add Esp,0x04
		Test Eax,Eax
		Jnz EXIT
		Jmp [CheckGensMoveIndexAddress2]
		EXIT:
		Jmp [CheckGensMoveIndexAddress3]
	}
}

void DrawEffectsPic(int &EffectID, float StartX, float StartY, float StartWidth, float StartHeight )
{
	//console.Log("", "%d | %f | %f | %f | %f", EffectID, StartX, StartY, StartWidth, StartHeight);
	
	if ( EffectID > 0 && EffectID < 180 )
	{
		int EffectValue = (EffectID - 1) % 80;
		float SourceX = (double)(EffectValue % 10) * StartWidth / 256.0;
		float SourceY = (double)(EffectValue / 10) * StartHeight / 256.0;
		float SourceWidth = StartWidth / 256.0;
		float SourceHeight = StartHeight / 256.0;
		pDrawImage((EffectID - 1) / 80 + 31725, StartX, StartY, StartWidth, StartHeight, SourceX, SourceY, SourceWidth, SourceHeight, 1, 1, 0);
	}
}

/*
SetCompleteHook(0xE8,0x004D7D13,&Copyright); //Copyright SelectServer

void Copyright(LPVOID This, BYTE r, BYTE g, BYTE b, BYTE h)
{
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
}
*/

__declspec(naked) void Copyright()
{
	static DWORD	Test_Buff;
	static char		Test_LevelBuff[40];
	
	gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 74, 460, 150, 3, "Powered By Emershow (c) 2021");
	//gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 74, 470, 150, 3, gCustomMessage.GetMessageB(455));
	
	_asm
	{
		lea eax, Test_LevelBuff
			push eax
	}
	
	_asm
	{
		mov Test_Buff, 0x004D7D1D
			jmp Test_Buff
	}
}

char FixHelperMouseClickC(int a1) //- [AntiDupe] Disabled Helper Config window click when use the Chaos machine
{
	if (gInterface.CheckWindow(ChaosBox) || gInterface.CheckWindow(Warehouse))
		return 0;

	return pHelperMouseClick(a1);
}

__declspec(naked) void FixEffects()
{
	static DWORD Address1 = 0x0062F6CE;
	static DWORD Address2 = 0x0062F69F;

	if (pMapNumber == 0 || pMapNumber == 3)
	{
		_asm
		{
			jmp Address1
		}
	}

	else
	{
		_asm
		{
			jmp Address2
		}
	}
}

void FixEffectCitys()
{
	SetCompleteHook(0xE9, 0x0062F69A, &FixEffects);
}