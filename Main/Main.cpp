#include "stdafx.h"
#include "resource.h"
#include "Main.h"
#include "..\\..\\Util\\CCRC32.H"
#include "Common.h"
#include "Controller.h"
#include "CustomBuyVip.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomGloves.h"
#include "CustomItem.h"
#include "CustomItemDescription.h"
#include "CustomJewel.h"
#include "CustomMap.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "CustomWing.h"
#include "Fix.h"
#include "StaticEffect.h"
#include "DynamicEffect.h"
#include "HackCheck.h"
#include "HealthBar.h"
#include "Item.h"
#include "ItemAsm.h"
#include "ItemShopValue.h" 
#include "ItemSmoke.h"
#include "Interface.h"
#include "OffTrade.h"
#include "PacketManager.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Protocol.h"
#include "Reconnect.h"
#include "Resolution.h"
#include "User.h"
#include "Util.h"
//#include "WingInvisible.h"
//#include "WingEffect.h"
#include "BattleGloves.h"
#include "Inter3.h"
#include "InterEx.h"
#include "CustomBow.h"
#include "CustomCloak.h"
#include "Cape.h"
#include "Pet.h"
#include "PetHook.h"
#include "CustomPet.h"
#include "TMemory.h"
#include "DisableButton.h"
#include "MiniMap.h"
#include "NewFont.h"
#include "ItemSetOption.h"
#include "CustomMonsterGlow.h"
#include "MonsterGlow.h"
#include "CustomPetEffect.h"
#include "CustomPetGlow.h"
#include "CScene.h"
#include "SCharacter.h"
#include "CSCharacterS13.h"
#include "StatsAdvance.h"
#include "CustomItemPower.h"
#include "ItemPower.h"
#include "ItemNameColor.h"
#include "CustomItemTooltip.h"
#include "CustomItemDisableGlow.h"
#include "FixVisualAgility.h"
#include "SelectCharAnimation.h"
#include "Slide.h"
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include "ChatClassic.h"
#include "ChatExpanded.h"
#include "ChatWindow.h"
#include "MoveLocal.h"
#include "CSceneS2.h"
#include "CustomNotice.h"
#include "CMacroUIEx.h"
#include "Central.h"
#include "WindowsStruct.h"
#include "Config.h"
#include "CustomItemNameColor.h"
#include "CChatEx.h"
#include "GetBarPlayer.h"
#include "Camera3D.h"
#include "CScene97.h"

HINSTANCE hins;

void StartAddress(LPVOID lpThreadParameter)
{
	HANDLE v1;
	HANDLE v2;
	
	while (TRUE)
	{
		Sleep(5000);

		v1 = GetCurrentProcess();
		SetProcessWorkingSetSize(v1, 0xFFFFFFFF, 0xFFFFFFFF);

		v2 = GetCurrentProcess();
		SetThreadPriority(v2, -2);
	}
}

bool CProtect::IsProcessRunning(const char *ProcessName, int maxProcess)
{
	PROCESSENTRY32 pe32 = {sizeof(PROCESSENTRY32)};
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	
	int Temp = 0;
	if (Process32First(hSnapshot, &pe32))
	{
		do
		{
			if (_tcsicmp(pe32.szExeFile, ProcessName) == 0)
			{
				Temp++;
				
				if (Temp > maxProcess)
				{
					CloseHandle(hSnapshot);
					return true;
				}
			}
		}
		while (Process32Next(hSnapshot, &pe32));
	}
	
	CloseHandle(hSnapshot);
	return false;
	
	//-> Anti Bypass
	if (*(BYTE*)GetProcAddress(GetModuleHandle("ntdll.dll"), "LdrLoadDll") != 233)
	{
		ExitProcess(0);
		return true;
	}
}

HHOOK HookKB;
HHOOK HookMS;
BOOL VKF9_State = 0;
BOOL VKF8_State = 0;

LRESULT CALLBACK KeyboardProc(int nCode,WPARAM wParam,LPARAM lParam) // OK
{
	if(nCode == HC_ACTION)
	{
		if(((DWORD)lParam & (1 << 30)) != 0 && ((DWORD)lParam & (1 << 31)) != 0)
		{
			switch(wParam)
			{
				case VK_F10:
					if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
					{
						gCamera.Toggle();
						pDrawMessage ("Camera 3D Switch", 1);
					}
					break;
				case VK_F11:
					if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
					{
						gCamera.Restore();
						pDrawMessage ("Camera 3D Restore", 1);
					}
					break;
				case VK_F9:
					if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
					{
						VKF9_State ^= 1;
						SendMessage(*(HWND*)(MAIN_WINDOW),WM_RBUTTONUP,VK_F9,MK_RBUTTON);
						pDrawMessage ("Auto Attack Switch", 1);
					}
					break;
				case VK_F8:
					if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
					{
						VKF8_State ^= 1;
						SetByte(0x0059AF53+2,1);
						SetByte(0x0059B248+2,1);
						pDrawMessage ("Ctrl Attack PVP Switch", 1);
					}
				default:
					break;
			}
		}
	}
	return CallNextHookEx(HookKB,nCode,wParam,lParam);
}

LRESULT CALLBACK MouseProc(int nCode,WPARAM wParam,LPARAM lParam) // OK
{
	if(nCode == HC_ACTION)
	{
		MOUSEHOOKSTRUCTEX* HookStruct = (MOUSEHOOKSTRUCTEX*)lParam;

		switch(wParam)
		{
			case WM_MOUSEMOVE:
				if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
				{
					gCamera.Move(HookStruct);
				}
				break;
			case WM_MBUTTONDOWN:
				if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
				{
					gCamera.SetIsMove(1);
					gCamera.SetCursorX(HookStruct->pt.x);
					gCamera.SetCursorY(HookStruct->pt.y);
				}
				break;
			case WM_MBUTTONUP:
				if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
				{
					gCamera.SetIsMove(0);
				}
				break;
			case WM_MOUSEWHEEL:
				if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
				{
					gCamera.Zoom(HookStruct);
				}
				break;
			default:
				break;
		}
	}

	return CallNextHookEx(HookMS,nCode,wParam,lParam);
}


LONG WINAPI CheckMacroThread() // OK
{
	while(!SleepEx(500,0))
	{
		if(VKF9_State != 0)
		{
			SendMessage(*(HWND*)(MAIN_WINDOW),WM_RBUTTONDOWN,VK_F9,MK_RBUTTON);
		}

		if(VKF8_State != 0)
		{
			SetByte(0x0059AF53+2,0);
			SetByte(0x0059B248+2,0);
		}
	}

	return 0;
}

extern "C" _declspec(dllexport) void EntryProc() // OK
{

	CreateThread(0,0,(LPTHREAD_START_ROUTINE)CheckMacroThread,0,0,0);

	HookKB = SetWindowsHookEx(WH_KEYBOARD,KeyboardProc,hins,GetCurrentThreadId());

	HookMS = SetWindowsHookEx(WH_MOUSE,MouseProc,hins,GetCurrentThreadId());

	SetByte(0x0054A270, 0xC3); //-> Disable Game Shadows

	if(gProtect.ReadMainFile("main.premium") == 0)
	{
		MessageBox(0,"Main.premium not found or invalid!","Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	SetByte(0x00E61144,0xA0); // Accent
	SetByte(0x004D1E69,0xEB); // Crack (mu.exe)
	SetByte(0x004D228D,0xE9); // Crack (GameGuard)
	SetByte(0x004D228E,0x8B); // Crack (GameGuard)
	SetByte(0x004D228F,0x00); // Crack (GameGuard)
	SetByte(0x004D2290,0x00); // Crack (GameGuard)
	SetByte(0x004D2291,0x00); // Crack (GameGuard)
	SetByte(0x004D559C,0xEB); // Crack (ResourceGuard)
	SetByte(0x00633F7A,0xEB); // Crack (ResourceGuard)
	SetByte(0x00634403,0xEB); // Crack (ResourceGuard)
	SetByte(0x0063E6C4,0xEB); // Crack (ResourceGuard)
	SetByte(0x004D2246,0xEB); // Crack (ResourceGuard)
	SetByte(0x00501163,0xEB); // Crack (ResourceGuard)
	SetByte(0x0040AF0A,0x00); // Crack (ResourceGuard)
	SetByte(0x0040B4BC,0x50); // Login Screen
	SetByte(0x0040B4C5,0x50); // Login Screen
	SetByte(0x0040B4CF,0x18); // Login Screen
	SetByte(0x0040AF0A,0x00); // Login Screen
	SetByte(0x0040AFD5,0xEB); // Login Screen
	SetByte(0x00777FD6,0x70); // Item Text Limit
	SetByte(0x00777FD7,0x17); // Item Text Limit
	SetByte(0x004EBEC7,0x3C); // Item Text Limit
	SetByte(0x005C4004,0x3C); // Item Text Limit
	SetByte(0x007E40BB,0x3C); // Item Text Limit
	SetByte(0x0081B546,0x3C); // Item Text Limit
	SetByte(0x0081B58D,0x3C); // Item Text Limit
	SetByte(0x0086E284,0x3C); // Item Text Limit
	SetByte(0x0086E44C,0x3C); // Item Text Limit
	SetByte(0x0086E573,0x3C); // Item Text Limit
	SetByte(0x0086F8FC,0x3C); // Item Text Limit
	SetByte(0x007DA373,0xB7); // Item Type Limit
	SetByte(0x007E1C44,0xB7); // Item Type Limit
	SetByte(0x0052100D,0xEB); // Ctrl Fix
	SetByte(0x009543C4,0x00); // Move Vulcanus
	SetByte(0x00886FDE,0x00); // Minimap loren Valley Onload Off
	SetByte(0x0064CBD1,((gProtect.m_MainInfo.HelperActiveAlert==0)?0xEB:0x75)); // Helper Message Box
	SetByte(0x0064CBD0,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); // Helper Active Level
	SetByte(0x0095CEEF,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); // Helper Active Level
	SetByte(0x0095CF14,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); // Helper Active Level
	SetByte(0x00E61F68,(gProtect.m_MainInfo.ClientVersion[0]+1)); // Version
	SetByte(0x00E61F69,(gProtect.m_MainInfo.ClientVersion[2]+2)); // Version
	SetByte(0x00E61F6A,(gProtect.m_MainInfo.ClientVersion[3]+3)); // Version
	SetByte(0x00E61F6B,(gProtect.m_MainInfo.ClientVersion[5]+4)); // Version
	SetByte(0x00E61F6C,(gProtect.m_MainInfo.ClientVersion[6]+5)); // Version
	SetWord(0x00E609E4,(gProtect.m_MainInfo.IpAddressPort)); // IpAddressPort
	SetDword(0x004D9D3B,(DWORD)&FrameValue);
	SetDword(0x004DAC60,(DWORD)&FrameValue);

	//-> Enable FPS Limit
	if(gProtect.m_MainInfo.FpsLimitEnable == 1)
	{
		SetDword(0x7B55338,(DWORD)10);
		SetDword(0x004D597B,(DWORD)&MainTickCount);
		SetDword(0x004DA289,(DWORD)&MainTickCount);
		SetDword(0x004DA297,(DWORD)&MainTickCount);
		SetDword(0x004DA3A2,(DWORD)&MainTickCount);
		SetDword(0x004DA3CE,(DWORD)&MainTickCount);
		SetDword(0x004DA3D9,(DWORD)&MainTickCount);
		SetDword(0x0063D326,(DWORD)&MainTickCount);
		SetDword(0x00642112,(DWORD)&MainTickCount);
	}

	SetDword(0x004D0E09,(DWORD)gProtect.m_MainInfo.WindowName);
	SetDword(0x004D9F55,(DWORD)gProtect.m_MainInfo.ScreenShotPath);

	SetByte(0x005C914B+3,0x00); // LuckItemmove

	//SetByte(0x71E70C, 16);

	MemorySet(0x0063E908,0x90,20); // C1:F3:04

	MemoryCpy(0x00E611B2,gProtect.m_MainInfo.IpAddress,sizeof(gProtect.m_MainInfo.IpAddress)); // IpAddress

	MemoryCpy(0x00E61F70,gProtect.m_MainInfo.ClientSerial,sizeof(gProtect.m_MainInfo.ClientSerial)); // ClientSerial

	SetCompleteHook(0xFF,0x0065FD79,&ProtocolCoreEx);

	//-> Enable FPS Limit
	if(gProtect.m_MainInfo.FpsLimitEnable == 1)
	{
		SetCompleteHook(0xE9,0x004DA280,&CheckTickCount1);
		SetCompleteHook(0xE9,0x004DA3A1,&CheckTickCount2);
	}

	//-> Fix MU Helper with Inventory
	if(gProtect.m_MainInfo.AllowHelperInventory == 1)
	{
		SetCompleteHook(0xE9,0x0095DFBE,0x0095DFD3);
	}

	//-> Disable Cash Shop (X) Option
	if(gProtect.m_MainInfo.DisableCashShop == 1)
	{
		SetByte((PVOID)(0x007D3D56+1),0xFF);	//-> Remove Press Key X
		MemorySet(0x00944E50,0x90,0x15E);		//-> Remove Shop X (MonsterZone)
		MemorySet(0x00661700,0x90,0x145);		//-> Remove Shop X (SafeZone)
	}

	//-> Disable Master Skill Tree (A) Option
	if(gProtect.m_MainInfo.DisableTree == 1)
	{
		MemorySet(0x008193F0,0x90,0xC8);		//-> Remove Press Key A
		DisableButtonOpenSkillTree();			//-> Remove Button in Character Stats
	}

	//-> Disable Command Window (D) Option
	if(gProtect.m_MainInfo.DisableCommandWindow == 1)
	{
		SetByte((PVOID)(0x007D3AF1+1),0xFF);	//-> Remove Press Key D
	}

	//-> Disable Full Map (Tab) Option
	if(gProtect.m_MainInfo.CustomMiniMapType == 0)
	{
		MemorySet(0x0062F876,0x90,0x30);		//-> Disable ViewMap (Key TAB)
	}

	//-> Disable Button Quest Window
	if(gProtect.m_MainInfo.DisableQuest == 1)
	{	
		SetByte((PVOID)(0x007D399F+1),0xFF);	//-> Disable Press Key T
		DisableButtonQuest();
	}

	//-> Disable Button Pet (DL)
	if(gProtect.m_MainInfo.DisablePet == 1)
	{	
		DisableButtonPet();
	}

	//-> Disable Gens (Key B)
	if(gProtect.m_MainInfo.DisableGens == 1)
	{	
		MemorySet(0x007C5AD2,0x90,0x05);		//-> Disable Gens (Key B)
		MemorySet(0x007C5A68,0x90,0x25);		//-> Remove Gens Window (B Buttom)
		MemorySet(0x00842DD0,0x90,0x1D7);		//-> Remove NPC Gens window
		SetByte(0x00868C44+3, 5);				//-> Gens Text in FastMenu
		SetByte(0x00868CF0, 0xC3);				//-> Gens Text in FastMenu
	}

	//-> Disable Button Friend
	if(gProtect.m_MainInfo.DisableFriend == 1)
	{	
		SetByte((PVOID)(0x007D37A1+1),0xFF);	//-> Disable Press Key F
	}

	//-> Disable Expanded Inventory Button
	if(gProtect.m_MainInfo.DisableExpandedInventory == 1)
	{
		SetCompleteHook(0xE9,0x008369FA,0x00836A23);	//-> Remove Button (K)
		SetCompleteHook(0xE9,0x007D36B8,0x007D36BF);	//-> Função (K) Inventário aberto
		SetCompleteHook(0xE9,0x007D3F9C,0x007D3FA3);	//-> Função (K) Baú Aberto
	}

	//-> Disable Expanded Warehouse Button
	if(gProtect.m_MainInfo.DisableExpandedWarehouse == 1)
	{
		SetCompleteHook(0xE9,0x007D371E,0x007D3725); // Remove botão (H)
		SetCompleteHook(0xE9,0x00856FAA,0x00856FD2); // Remove (H) Baú Aberto
	}

	//-> Disable Button Open Store
	if(gProtect.m_MainInfo.DisablePersonalShop == 1)
	{	
		SetByte((PVOID)(0x00834E12+1),0xFF); // Disable Key S
		DisableButtonOpenStore();	
	}

	SetCompleteHook(0xE8,0x005B96E8,&DrawNewHealthBar);

	VirtualizeOffset(0x004D9D39,12);

	VirtualizeOffset(0x004D9D45,7);

	VirtualizeOffset(0x004D9EFC,15);

	VirtualizeOffset(0x004DAC5C,8);

	VirtualizeOffset(0x005451F7,5);

	VirtualizeOffset(0x00545230,8);

	VirtualizeOffset(0x005A52E9,8);

	LoadReferenceAddressTable((HMODULE)hins,MAKEINTRESOURCE(IDR_BIN1),(DWORD)&NewAddressData1);

	LoadReferenceAddressTable((HMODULE)hins,MAKEINTRESOURCE(IDR_BIN2),(DWORD)&NewAddressData2);

	LoadReferenceAddressTable((HMODULE)hins,MAKEINTRESOURCE(IDR_BIN3),(DWORD)&NewAddressData3);

	gCustomMessage.LoadEng(gProtect.m_MainInfo.EngCustomMessageInfo);

	gCustomMessage.LoadPor(gProtect.m_MainInfo.PorCustomMessageInfo);

	gCustomMessage.LoadSpn(gProtect.m_MainInfo.SpnCustomMessageInfo);

	gCustomJewel.Load(gProtect.m_MainInfo.CustomJewelInfo);

	gCustomWing.Load(gProtect.m_MainInfo.CustomWingInfo);

	gCustomItem.Load(gProtect.m_MainInfo.CustomItemInfo);

	gCustomBuyVip.Load(gProtect.m_MainInfo.CustomBuyVipInfo);

	gCustomCommandInfo.Load(gProtect.m_MainInfo.CustomCommandInfo);

	gCustomItemDescription.Load(gProtect.m_MainInfo.CustomDescriptionInfo);

	gCustomEventTime.Load(gProtect.m_MainInfo.CustomEventInfo);

	gCustomWingEffect.Load(gProtect.m_MainInfo.CustomWingEffectInfo);

	gDynamicWingEffect.Load(gProtect.m_MainInfo.DynamicWingEffectInfo);

	gFog.Load(gProtect.m_MainInfo.CustomFog);

	gSmokeEffect.Load(gProtect.m_MainInfo.CustomSmokeEffect);

	gCustomMonster.Load(gProtect.m_MainInfo.CustomMonsters);

	gNPCName.Load(gProtect.m_MainInfo.CustomNPCName);

	gCustomBattleGloves.Load(gProtect.m_MainInfo.CustomGloves);

	gCustomBow.Load(gProtect.m_MainInfo.CustomBowInfo);

	gCloak.Load(gProtect.m_MainInfo.CustomCloakInfo);

	gCustomPet2.Load(gProtect.m_MainInfo.CustomPetInfo);

	gCustomMonsterGlow.LoadGlow(gProtect.m_MainInfo.m_CustomMonsterGlow);

	gCustomMonsterGlow.LoadBrightness(gProtect.m_MainInfo.m_CustomMonsterbrightness);

	JCEffectMonster.Load(gProtect.m_MainInfo.m_CustomMonsterEffect);

	gCustomCEffectPet.Load(gProtect.m_MainInfo.m_PetCEffectBMD);

	cRender.Load(gProtect.m_MainInfo.RenderMeshPet);

	gCustomItemInfo.Load(gProtect.m_MainInfo.m_CustomItemInfo_Ex);

	GInfo.loadnInformation(gProtect.m_MainInfo.m_TRSTooltipData);

	GInfo.loadnText(gProtect.m_MainInfo.m_TRSTooltipText);

	JCRemoveGlow.Load(gProtect.m_MainInfo.m_JCWRemoveGlow);

	gPacketManager.LoadEncryptionKey("Data\\Enc1.dat");

	gPacketManager.LoadDecryptionKey("Data\\Dec2.dat");

	InitCommon();

	InitHackCheck();

	InitItem();

	InitJewel();

	InitPrintPlayer();

	InitReconnect();

	InitResolution();

	gController.Load();

	InitWing();

	gObjUser.Load();

	gInterface.Load();

	gCustomItemDescription.Init();

	gOffTrade.Init();

	gFog.Init();

	//-> Config Load
	Config.Load();

	if(gProtect.m_MainInfo.CustomMonsterEnable == 1)
	{
		gCustomMonster.InitMonster();

		InitloadGlow();
	}

	gProtect.CheckLauncher();

	gProtect.CheckInstance();

	gProtect.CheckClientFile();

	gProtect.CheckPlugin1File();
	
	gProtect.CheckPlugin2File();
	
	gProtect.CheckPlugin3File();
	
	gProtect.CheckPlugin4File();
	
	gProtect.CheckPlugin5File();

	gProtect.CheckCameraFile();

	//gFix.Load();

	//-> Custom Bow/Crossbow
	if(gProtect.m_MainInfo.EnableCustomBow == 1)
	{
		InitBows();
	}

	gCustomMap.Load();

	if(gProtect.m_MainInfo.EnableShopValueSystem == 1)
	{
		gItemPrice.Init();
	}

	if(gProtect.m_MainInfo.CsSkill == 1)
	{
		//Liberar CS Skills
		SetByte((0x005B89C3+3), 0x00);
		SetByte((0x005B89C9+3), 0x00);
		SetByte((0x005B89CF+3), 0x00);
		SetByte((0x005B89D5+3), 0x00);
		SetByte((0x005B89DB+3), 0x00);
		SetByte((0x005B89E1+3), 0x00);
		SetWord((0x005B89E7+3), 0x00);
		//--
		SetByte((0x005C6314+2), 0x00);
		SetByte((0x005C6327+2), 0x00);
		SetByte((0x005C633A+2), 0x00);
		SetByte((0x005C634D+2), 0x00);
		SetByte((0x005C6360+2), 0x00);
		SetByte((0x005C6373+2), 0x00);
		SetWord((0x005C6386+2), 0x00);
	}

	//Reduce Memory use (v2)
	int ReduceMemory = GetPrivateProfileIntA("AntiLag", "ReduceMemory", 0, ".\\Settings.ini");
	if(ReduceMemory == 1)
	{
		CreateThread(0,0,(LPTHREAD_START_ROUTINE)StartAddress,0,0,0);
	}
	//--

	//-> Remove RF
	if(gProtect.m_MainInfo.RemoveClass == 4)
	{
		SetByte(0x004030D1+3,6);
	}
	
	//-> Remove SU/RF
	if(gProtect.m_MainInfo.RemoveClass == 3)
	{
		SetByte(0x004030D1+3,5);
	}
	
	//-> Remove DL/SU/RF
	if(gProtect.m_MainInfo.RemoveClass == 2)
	{
		SetByte(0x004030D1+3,4);
	}

	//-> Remove MG/DL/SU/RF
	if(gProtect.m_MainInfo.RemoveClass == 1)
	{
		SetByte(0x004030D1+3,3);
	}
	
	//-> Disable Reflect Effect
	if(gProtect.m_MainInfo.DisableReflectEffect == 1)
	{
		SetByte(0x005528A0,0xC3);
	}

	//-> Disable BattleZone
	if(gProtect.m_MainInfo.DisableBattleZone == 1)
	{
		SetCompleteHook(0xE9,0x00832862, 0x00832897);
		//MemorySet(0x00832CF2,0x90,0x5); //2987 "(Batalha)"
	}

	//-> Change Credits
//	MemorySet(0x004D7DAD,0x90,0x0F); //AD7D4D
//	SetCompleteHook(0xE9,0x004D7D13,&Copyright); //137D4D

	//-> Custom Server News
	if(gProtect.m_MainInfo.ServerNews == 1)
	{
		InitNotices();
	}

	//-> Custom Battle Gloves
	if(gProtect.m_MainInfo.CustomGlovesEnable == 1)
	{
		gCustomBattleGloves.Init();
	}

	//-> Custom Interface (S6 Original)
	if(gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		CgChatExpanded.Load();
	}

	//Custom Interface Type (S1/S2)
	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		gSlide.Load(); //- Slide help classic position
		gCChatClassic.Load(); //-> Classic Chat
	}

	//Custom Interface Type (S1/S2/S3)
	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		InitInter3();
	}

	gCMacroUIEx.Load();

	//Custom Interface Type (S8)
	if(gProtect.m_MainInfo.CustomInterfaceType == 4 || gProtect.m_MainInfo.CustomInterfaceType == 5 || gProtect.m_MainInfo.CustomInterfaceType == 6)
	{
		InitInterEx();
		gCentral.InitCentral(); //-> Party
		//InitSeason15();
		gCChatEx.Load();
		CgChatExpanded.Load();
	}

	//-> Custom Interface Helper Bar
	if(gProtect.m_MainInfo.CustomInterfaceHelperBar == 0)
	{
		MemorySet(0x0085B6AC,0x90,0x05);	//-> Remove Helper Top Screen
		SetByte((PVOID)(0x007D410F+1),0xFF); //-> Disable Z Key
	}

	//-> Custom Interface Helper Bar
	if(gProtect.m_MainInfo.CustomInterfaceHelperBar == 1)
	{
		MemorySet(0x0085B6AC,0x90,0x05);	//-> Remove Helper Top Screen
	}

	//-> Custom Interface Helper Bar (S4)
	if(gProtect.m_MainInfo.CustomInterfaceHelperBar == 2)
	{
		//MuHelper Dimensionamento
		MemorySet(0x007D2DEE,0x90,0x5);
		MemorySet(0x007D2E31,0x90,0x5);
		MemorySet(0x007D2D18,0x90,0x5);
		SetByte((PVOID)(0x007D2D52+3),-74);		//INTERFACE MINIMAPC
		SetByte((PVOID)(0x007D2771+3),-117);	//START MUHELPER
		SetByte((PVOID)(0x007D281C+3),-117);	//STOP MUHELPER
		SetByte((PVOID)(0x007D26D5+3),-117);	//CONFIG MUHELPER
		SetDword(0x007D2F0A+1,(DWORD)"Interface\\Minimap_positionC.tga");
	}

	SetByte((PVOID)(0x007D37A1+1),0xFF); //disable F Key

	//-> Disable Move List (M) Option
	if(gProtect.m_MainInfo.DisableMoveList == 1)
	{
		SetByte((PVOID)(0x007D3C6B+1),0xFF);
	}

	//-> Disable Set +15 Effect Option
	if(gProtect.m_MainInfo.DisableSet15Effect == 1)
	{
		MemorySet(0x006097B0,0x90,0x69D); //-> Remove +15 Effects
	}
	
	//-> Custom Cloak
	if(gProtect.m_MainInfo.CustomCloakEnable == 1)
	{
		gCapeAnimation.Load();
	}

	//-> Custom Pet
	if(gProtect.m_MainInfo.CustomPetEnable == 1)
	{
		gCustomPet.Load();
		gObjCreatePetExHook();
		gCustomCEffectPet.Init();
	}

	//-> Custom Ancient
	if(gProtect.m_MainInfo.CustomAncientSwitch == 1)
	{
		//CSItemOption::Load();
		gCItemSetOption.Load();
		SetDword(0x004E8798+1,(DWORD)"Data\\Custom\\Local\\");
	}

	//-> Classic Mini Map
	if(gProtect.m_MainInfo.CustomMiniMapType == 2)
	{
		InitMiniMap();
	}

	//-> Custom Font System
	gFont.Load();

	//-> Select Server Type (Season 0)
	if(gProtect.m_MainInfo.SelectLoginThemeType == 0)
	{
		//-> Select Server/Character 99B
		gCSceneA.Load();
	}

	//-> Select Server Type (Season 2)
	if(gProtect.m_MainInfo.SelectLoginThemeType == 1)
	{
		CSceneS2();			//-> Load New Login Screen (S2)
		SCharacterS3();		//-> Select Character (S2)
		InitLoginThemeS2();	//-> Load New Login Screen (S2)

		if(gProtect.m_MainInfo.SelectCharacterType == 0)
		{
			SetByte(0x00503834,0xEB);	//-> Fix Mount Select Charcter (S2)
		}
		
		else
		{
			gCSCharacterS13.Load();	//-> New Select Character (S2-S13)
		}
	}

	//-> Login Theme Type (Season 4)
	if(gProtect.m_MainInfo.SelectLoginThemeType == 2)
	{
		MemoryCpy(0x009184D9,"192.95.49.237",sizeof("192.95.49.237"));
		MemoryCpy(0x00918522,"TbYehR2hFUPBKgZj",sizeof("TbYehR2hFUPBKgZj"));
		InitLoginThemeS4();	//-> Load Login Theme (Season 4)

		if(gProtect.m_MainInfo.SelectCharacterType == 0)
		{
			SCharacterS4();
			SetByte(0x00503834,0xEB);	//-> Fix Mount Select Charcter (S4)
		}
		
		else
		{
			CScene();				//-> Custom Login Theme Type
			SCharacterS13();		//-> New Select Character (S13)
			gCSCharacterS13.Load();	//-> New Select Character (S13)
		}
	}

	//-> Login Theme Type (Season 6)
	if(gProtect.m_MainInfo.SelectLoginThemeType == 3)
	{
		if(gProtect.m_MainInfo.SelectCharacterType == 1)
		{
			CScene();	//-> Custom Login Theme Type
			gCSCharacterS13.Load();	//-> New Select Character (S13)
		}
	}

	//-> Select Login Theme Type (EX700)
	if(gProtect.m_MainInfo.SelectLoginThemeType == 4)
	{
		CScene();	//-> Custom Login Theme Type

		if(gProtect.m_MainInfo.SelectCharacterType == 0)
		{
			SCharacterS8();	//-> New Select Character (EX700)
		}
		
		else
		{
			SCharacterS13();		//-> New Select Character (S13)
			gCSCharacterS13.Load();	//-> New Select Character (S13)
		}
	}

	//-> Custom Server Name
	if(gProtect.m_MainInfo.CustomServerNameEnable == 1)
	{
		SetDword(0x00954148+1,(DWORD)gProtect.m_MainInfo.ServerNameA);
		SetDword(0x0040B6EB+1,(DWORD)0xEAB);
		SetDword(0x0077F93E+1,(DWORD)0xEAB);
		SetDword(0x00954115+1,(DWORD)gProtect.m_MainInfo.ServerNameB);
		SetDword(0x0040B6D6+1,(DWORD)0xEAC);
		SetDword(0x0077F929+1,(DWORD)0xEAC);
		SetDword(0x009540E2+1,(DWORD)gProtect.m_MainInfo.ServerNameC);
		SetDword(0x0040B6C1+1,(DWORD)0xEAD);
		SetDword(0x0077F914+1,(DWORD)0xEAD);
		SetDword(0x009540AC+1,(DWORD)gProtect.m_MainInfo.ServerNameD);
		SetDword(0x0040B6AC+1,(DWORD)0xEAE);
		SetDword(0x0077F8FF+1,(DWORD)0xEAE);
	}

	//-> Remove Character Delete Level
	SetWord(0x00405B7A+2,(WORD)gProtect.m_MainInfo.CharacterDeleteMaxLevel);
	SetWord(0x0040CC3F+1,(WORD)gProtect.m_MainInfo.CharacterDeleteMaxLevel);

	//-> Custom Item Name Color
	if(gProtect.m_MainInfo.EnableItemNameColor == 1)
	{
		InitCustomNameColor();
		ItemNameColor.Load();
	}

	//-> Select Character Animation
	if(gProtect.m_MainInfo.SCAnimation == 1)
	{
		gSelectChar.Load();
	}

	gItemInfoEx.Load();

	JCRemoveGlow.Init(); //-> Disable Item Glow

	//FixVisualSpeedAttack();

	FixEffectCitys();

	//-> Fix Socket + Jewel of Harmony
	if(gProtect.m_MainInfo.SocketItemAcceptHarmony == 1)
	{
		SetByte(0x008385E4, 0xEB); // Fix
		SetByte(0x00838647, 0xEB); // Fix
		SetByte(0x00838658, 0xEB); // Fix
		SetByte(0x005BD939, 0xEB); // Fix
		SetByte(0x007E1DE1, 0xEB); // Fix
		SetRange(0x007E5429, 6, ASM::NOP); // Fix
	}

	//-> Custom ImgsMapName (eX700 ~ S16)
	if(gProtect.m_MainInfo.ImgsMapNameType == 2)
	{
		MoveLocal();
	}

	//-> Show Name
	if(gProtect.m_MainInfo.NameStyle == 1)
	{
		SetByte((PVOID)(0x81C03FA), 0x01);
	}

	//-> Show Name + Guild Logo
	if(gProtect.m_MainInfo.NameStyle == 2)
	{
		SetByte((PVOID)(0x81C03FA), 0x01);
		JumPlayer.Load();
	}

	//-> Control Key
	//SetByte(0x0059AF53+2,0);
	//SetByte(0x0059B248+2,0);

	//InitAttackSpeed(); //-> FIX VISUAL SKILL
}

void InitLoginThemeS4()
{
	HMODULE hModule = LoadLibraryA("Data\\Object79\\Object179.bmd");

	void (*EntryProc)(char*) = ((void(*)(char*))GetProcAddress(hModule,"EntryProc"));

	if (EntryProc)
	{
		EntryProc("InitLoginThemeS4");
	}
}

void InitLoginThemeS2()
{
	HMODULE hModule = LoadLibraryA("Data\\Object55\\Object155.bmd");

	void (*EntryProc)(char*) = ((void(*)(char*))GetProcAddress(hModule,"EntryProc"));

	if (EntryProc)
	{
		EntryProc("SS2");
	}
}

BOOL APIENTRY DllMain(HMODULE hModule,DWORD ul_reason_for_call,LPVOID lpReserved) // OK
{
	switch(ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			hins = (HINSTANCE)hModule;
			gController.Instance = hModule;
			break;
		case DLL_PROCESS_DETACH:
			break;
		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
			break;
	}

	return 1;
}
