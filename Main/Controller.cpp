#include "stdafx.h"
#include "Controller.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protocol.h"
#include "Import.h"
#include "Interface.h"
#include "User.h"
#include "Protect.h"
#include "CSCharacterS13.h"
#include "CustomJewelBank.h"
#include "resource.h"
#include "TMemory.h"
#include "CMacroUIEx.h"
#include "WindowsStruct.h"
#include "Camera.h"

Controller	gController;

void __declspec(naked) iconHook()
{
	//- Custom Client Ico (S8)
	if(gProtect.m_MainInfo.CustomClientIconType == 1)
	{
		static DWORD dwIcon = (DWORD)LoadIcon(gController.Instance, MAKEINTRESOURCE(IDI_ICON2));
		
		static DWORD dwJmp = 0x004D0E3C;
		
		_asm
		{
			MOV EAX,dwIcon
				JMP dwJmp
		}
	}

	//- Custom Client Ico (EX)
	if(gProtect.m_MainInfo.CustomClientIconType == 2)
	{
		static DWORD dwIcon = (DWORD)LoadIcon(gController.Instance, MAKEINTRESOURCE(IDI_ICON3));
		
		static DWORD dwJmp = 0x004D0E3C;
		
		_asm
		{
			MOV EAX,dwIcon
				JMP dwJmp
		}
	}

	//- Custom Client Ico (Mu Plasma)
	if(gProtect.m_MainInfo.CustomClientIconType == 1001)
	{
		static DWORD dwIcon = (DWORD)LoadIcon(gController.Instance, MAKEINTRESOURCE(IDI_ICON4));
		
		static DWORD dwJmp = 0x004D0E3C;
		
		_asm
		{
			MOV EAX,dwIcon
				JMP dwJmp
		}
	}

	//- Custom Client Ico (Classic)
	else
	{
		static DWORD dwIcon = (DWORD)LoadIcon(gController.Instance, MAKEINTRESOURCE(IDI_ICON1));
		
		static DWORD dwJmp = 0x004D0E3C;
		
		_asm
		{
			MOV EAX,dwIcon
				JMP dwJmp
		}
	}
}

bool Controller::Load()
{
	if(!this->MouseHook)
	{
		this->MouseHook = SetWindowsHookEx(WH_MOUSE, this->Mouse, gController.Instance, GetCurrentThreadId());
		
		if(!this->MouseHook)
		{
			return false;
		}
	}
	
	if(!this->KeyboardHook)
	{

	}

	SetOp((LPVOID)0x004D0E2F, iconHook, ASM::CALL);
	
	return true;
}

LRESULT Controller::Mouse(int Code, WPARAM wParam, LPARAM lParam)
{
	if(GetForegroundWindow() != pGameWindow)
	{
		return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
	}
	
	MOUSEHOOKSTRUCTEX * Mouse	= (MOUSEHOOKSTRUCTEX*)lParam;
	
	//gCamera.Run(Mouse, wParam);

	switch(wParam)
	{
	case WM_LBUTTONUP:
	case WM_LBUTTONDOWN:
		{
			gCustomRanking.EventRankingNext(wParam);
			gCustomRanking.EventRankingBack(wParam);
			gInterface.EventVipWindow_Main(wParam);
			gCustomRanking.EventVipWindow_Close(wParam);
			gCustomCommandInfo.EventCommandWindow_Close(wParam);
			gCustomCommandInfo.CommandNext(wParam);
			gCustomCommandInfo.CommandPrev(wParam);
			gCustomEventTime.EventEventTimeWindow_Close(wParam);
			gCustomEventTime.EventNext(wParam);
			gCustomEventTime.EventPrev(wParam);
			gInterface.EventDrawMenu_Open(wParam);
			gInterface.EventDrawMenu_Close(wParam);
			gInterface.EventDrawMenu_Op1(wParam);
			gInterface.EventDrawMenu_Op2(wParam);
			gInterface.EventDrawMenu_Op3(wParam);
			gInterface.EventDrawMenu_Op4(wParam);
			gInterface.EventDrawMenu_Op20(wParam);
			gInterface.EventDrawMenu_Op21(wParam);
			gInterface.EventConfirm_CANCEL(wParam);
			gInterface.EventConfirm_OK(wParam);
			gOffTrade.EventOffTradeWindow_Main(wParam);
			gOffTrade.EventCloseTradeWindow_Main(wParam); //- Fix Custom Store close button
			gCSCharacterS13.SelectCharButton(wParam); //- S13
			gInterface.EventUsersPanelAntiLag(wParam); //-> Anti Lag
			EventMuOffhelper(wParam); //-> Helper Offline
			//gInterface.EventCameraUI(wParam); //> 3D Camera

			//-> Jewel Bank Window
			gJewelBank.JewelBankEvent(wParam);
			gJewelBank.EventJewelWindows_Close(wParam);
			//-> Jewel Bank Buttons
			gInterface.EventSendZenButton(wParam);
			gInterface.EventRecvZenButton(wParam);
			gInterface.EventSendChaosButton(wParam);
			gInterface.EventRecvChaosButton(wParam);
			gInterface.EventSendBlessButton(wParam);
			gInterface.EventRecvBlessButton(wParam);
			gInterface.EventSendSoulButton(wParam);
			gInterface.EventRecvSoulButton(wParam);
			gInterface.EventSendLifeButton(wParam);
			gInterface.EventRecvLifeButton(wParam);
			gInterface.EventSendCreationButton(wParam);
			gInterface.EventRecvCreationButton(wParam);
			gInterface.EventSendHarmonyButton(wParam);
			gInterface.EventRecvHarmonyButton(wParam);
			gInterface.EventSendGuardianButton(wParam);
			gInterface.EventRecvGuardianButton(wParam);
			gInterface.EventSendGemstoneButton(wParam);
			gInterface.EventRecvGemstoneButton(wParam);
			gInterface.EventSendLowerRefineStoneButton(wParam);
			gInterface.EventRecvLowerRefineStoneButton(wParam);
			gInterface.EventSendHighRefineStoneButton(wParam);
			gInterface.EventRecvHighRefineStoneButton(wParam);
			//	gJewelBank.JewelBankNext(wParam);
			//	gJewelBank.JewelBankPrev(wParam);
			//	gJewelBank.JewelBankButton(wParam);


			switch(gProtect.m_MainInfo.CustomInterfaceType)
			{
			case 1:
				gInterface.EventNewInterface97_All(wParam);
				break;
			case 2:
				gInterface.EventNewInterface_All(wParam);
				break;
			case 3:
				gInterface.EventNewInterface_All(wParam);
				break;
			case 4:
				gInterface.EventMenuButton(wParam);
				gCMacroUIEx.Button(wParam);
				break;
			case 5:
				gInterface.EventMenuButton(wParam);
				gCMacroUIEx.Button(wParam);
				break;
			}
		}
		
		break;
	}
	
	return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
}

LRESULT Controller::Keyboard(int Code, WPARAM wParam, LPARAM lParam)
{
	if(GetForegroundWindow() != pGameWindow)
	{
		return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
	}

	if (Code < 0) return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
	
	if((Code == HC_ACTION) && (wParam == WM_KEYDOWN))
	{
		KBDLLHOOKSTRUCT Hook = *((KBDLLHOOKSTRUCT*)lParam);
		switch(Hook.vkCode)
		{
		
	/*	case VK_F8:
		{
			gCustomRanking.OpenWindow();
		}*/
		break;
		case 0x48:
		{
			gCustomEventTime.OpenWindow();
		}
		break;
		case VK_ESCAPE:
		{
			if (gInterface.Data[eCommand_MAIN].OnShow == true)
			{
				gInterface.Data[eCommand_MAIN].OnShow = false;
				pSetCursorFocus = false;
				return -1;
			}

			if (gInterface.Data[eRankPANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eRankPANEL_MAIN].OnShow = false;
				pSetCursorFocus = false;
				return -1;
			}

			if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
				pSetCursorFocus = false;
				return -1;
			}

			if (gInterface.CheckVipWindow())
			{
				gInterface.CloseVipWindow();
				return -1;
			}

			if (gInterface.CheckMenuWindow())
			{
				gInterface.CloseMenuWindow();
				return -1;
			}
		}
		break;
		case VK_END:
		{
			if (gInterface.CheckVipWindow())
			{
				gInterface.CloseVipWindow();
			}
			else
			{
				gInterface.CloseCustomWindow();
				gInterface.OpenVipWindow();
			}
		}
		break;
		case VK_SNAPSHOT:
		{
			gInterface.Data[eLogo].EventTick = GetTickCount()+1500;
			//gInterface.Data[eLogo].OnShow = true;
			//gInterface.DrawLogo();
			return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
		}
		break;
		default:
			break;
		}
	}
	
	return (LRESULT) NULL;
}
