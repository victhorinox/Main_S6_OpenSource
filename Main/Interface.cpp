#include "stdafx.h"
#include "Common.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Interface.h"
#include "Import.h"
#include "Reconnect.h"
#include "TMemory.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protect.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "User.h"
#include "Util.h"
#include "Inter3.h"
#include "InterEx.h"
#include "Object.h"
#include "CustomCloak.h"
#define GMT (24 + (gProtect.m_MainInfo.GMT_TIME))
#include "post_item.h"
#include "StatsAdvance.h"
#include "Object.h"
#include "CustomJewelBank.h"
#include "WingInvisible.h"
#include "Performance.h"
#include "WindowsStruct.h"
#include "Camera.h"
#include "CChatEx.h"
#include "CScene.h"

Interface	gInterface;

static const char* StoreName = "Teste";

char ChatWindows(MUChat* This)
{
	This->WindowPosX = 0;

	if(gInterface.CheckWindow(ChatWindow))
	{
		This->WindowPosY = 382;
	}
	else
	{
		This->WindowPosY = 429;
	}

	sub_7889B0(This);

	return 1;
}

int sub_790B10(int v13, int v12, int v11, int v10)
{
	glColor4f(1.0, 1.0, 1.0, 1.0);

	return pCheckMouseOver	(v13, v12, v11, v10);
}

void Interface::Load()
{
	//SetCompleteHook(0xE8, 0x0078B09A, &ChatWindows); //-> ChatPosition

	SetCompleteHook(0xE8, 0x0080FF56, &sub_790B10); //-> Fix hp/mp/sd/ag mouse over color

	//-> Jewels Bank
	if (gProtect.m_MainInfo.CustomJewelBankEnable == 1)
	{
		gJewelBank.Bind();
	}

	//-> Advanced Stats
	if (gProtect.m_MainInfo.CustomAdvancedStausEnable == 1)
	{
		g_StatsAdvance.Bind();
	}

	this->BindObject(eFlag01, 0x7880, 78, 78, -1, -1);
	this->BindObject(eFlag02, 0x7881, 78, 78, -1, -1);
	this->BindObject(eFlag03, 0x7882, 78, 78, -1, -1);
	this->BindObject(eFlag04, 0x7883, 78, 78, -1, -1);
	this->BindObject(eFlag05, 0x7884, 78, 78, -1, -1);
	this->BindObject(eFlag06, 0x7885, 78, 78, -1, -1);
	this->BindObject(eFlag07, 0x7886, 78, 78, -1, -1);
	this->BindObject(eFlag08, 0x7887, 78, 78, -1, -1);
	this->BindObject(eFlag09, 0x7888, 78, 78, -1, -1);
	this->BindObject(eFlag10, 0x7889, 78, 78, -1, -1);
	this->BindObject(eFlag11, 0x7890, 78, 78, -1, -1);
	this->BindObject(eFlag12, 0x7891, 78, 78, -1, -1);
	this->BindObject(eFlag13, 0x7892, 78, 78, -1, -1);
	this->BindObject(eFlag14, 0x7893, 78, 78, -1, -1);
	this->BindObject(eFlag15, 0x7894, 78, 78, -1, -1);
	this->BindObject(eFlag16, 0x7895, 78, 78, -1, -1);
	this->BindObject(eFlag17, 0x7896, 78, 78, -1, -1);
	this->BindObject(eFlag18, 0x7897, 78, 78, -1, -1);
	this->BindObject(eFlag19, 0x7898, 78, 78, -1, -1);
	this->BindObject(eFlag20, 0x7899, 78, 78, -1, -1);
	this->BindObject(eFlag21, 0x7900, 78, 78, -1, -1);
	this->BindObject(eFlag22, 0x7901, 78, 78, -1, -1);
	this->BindObject(eRanking, 0x7902, 179, 27, -1, -1);
	this->BindObject(eSAMPLEBUTTON, 0x7903, 25, 40, -1, -1);
	this->BindObject(eSAMPLEBUTTON2, 0x7904, 25, 40, -1, -1);

	//-> Server Time Bar
	this->BindObject(eTIME, 0x787F, 131, 70, -10, 359);

	//-> Premium system
	this->BindObject(eVip_MAIN, 0x7A5A, 222, 260, -1, -1);
	this->BindObject(eVip_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eVip_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eVip_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eVip_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eVip_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eVip_BRONZE, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_SILVER, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_GOLD, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_PLATINUM, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_STATUS, 0x7A5E, 108, 29, -1, -1);
	
	//-> Custom Menu
	this->BindObject(eMenu_MAIN, 0x7A5A, 222, 290, -1, -1);
	this->BindObject(eMenu_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eMenu_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eMenu_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eMenu_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eMenu_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eMenu_OPT1, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_OPT2, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_OPT3, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_OPT4, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_OPT20, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_OPT21, 0x7A5E, 108, 29, -1, -1);
	
	//Command info
	this->BindObject(eCommand_MAIN, 0x7A5A, 222, 300, -1, -1);
	this->BindObject(eCommand_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCommand_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCommand_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCommand_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCommand_CLOSE, 0x7EC5, 36, 29, -1, -1);

	this->BindObject(eRanking_MAIN, 0x7A5A, 222, 260, -1, -1);
	this->BindObject(eRanking_CLOSE, 0x7EC5, 36, 29, -1, -1);

	this->BindObject(eEventTime_MAIN, 0x7A5A, 222, 225, -1, -1);
	this->BindObject(eEventTime_CLOSE, 0x7EC5, 36, 29, -1, -1);

	this->BindObject(eCONFIRM_MAIN, 0x7A5A, 222, 120, -1, -1);
	this->BindObject(eCONFIRM_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCONFIRM_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCONFIRM_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCONFIRM_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCONFIRM_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_BTN_CANCEL, 0x7A5C, 54, 30, -1, -1);

	this->BindObject(eLogo, 0x7905, 150, 114, -1, -1);
	
	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
	}
	else
	{
		this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
		this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
	}

	//->Disable Cash Shop - Option S4
	if(gProtect.m_MainInfo.DisableCashShop == 1 && gProtect.m_MainInfo.CustomInterfaceType == 0)
	{
		SetByte(0x0080F270, 0xC3);

		this->BindObject(ebtnOption1, 0x53529, 37, 40, -10, 200);
		this->BindObject(ebtnOption1hover, 0x53530, 37, 40, -10, 200);
		this->BindObject(ebtnOption1click, 0x53531, 37, 40, -10, 200);
		this->BindObject(ebtnOption2, 0x53532, 37, 40, -10, 200);
		this->BindObject(ebtnOption2hover, 0x53533, 37, 40, -10, 200);
		this->BindObject(ebtnOption2click, 0x53534, 37, 40, -10, 200);
		this->BindObject(ebtnOption3, 0x53535, 37, 40, -10, 200);
		this->BindObject(ebtnOption3hover, 0x53536, 37, 40, -10, 200);
		this->BindObject(ebtnOption3click, 0x53537, 37, 40, -10, 200);
		this->BindObject(ebtnOption4, 0x53538, 37, 40, -10, 200);
		this->BindObject(ebtnOption4hover, 0x53539, 37, 40, -10, 200);
		this->BindObject(ebtnOption4click, 0x53540, 37, 40, -10, 200);
		this->BindObject(eBackG, 0x53541, 151, 40, -10, 200);
	}
	
	//-> Custom Store
	this->BindObject(eOFFTRADE_JoB, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_JoS, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_JoC, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_WCC, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_WCP, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_WCG, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_OPEN, 0x7BFD, 108, 30, -1, -1);

	//-> Custom Interface Type (S1/S2)
	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		this->BindObject(eDragonLeft, 2337, 108.0, 45.0, 0.0, 384.0);
		this->BindObject(eDragonRight, 2336, 108.0, 45.0, 532.0, 384.0);
		this->BindObject(eParty, iNewParty, 24, 24, 348, 447);
		this->BindObject(eCharacter, iNewCharacter, 24, 24, 379, 447);
		this->BindObject(eInventory, iNewInventory, 24, 24, 409, 447);
		this->BindObject(eFriend, iNewWinpush, 52, 18, 581, 432);
		this->BindObject(eGuild, iNewGuild, 52, 18, 581, 454);

		this->BindObject(eOrelhinha, 0x700021, 16, 16, -10, 359);
		this->BindObject(eJanelinha, 0x700022, 16, 16, -10, 359);
		this->BindObject(eLuizinha, 0x700023, 16, 16, -10, 359);
		this->BindObject(ebtnWisper, 0x7A34, 15, 15, -10, 359);
	}

	//-> Custom Interface Type (S2/S3)
	if(gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		this->BindObject(eFastMenu, iNewFastMenu, 53, 19, 5, 432);
	}

	//-> Custom Interface Type (S3)
	if(gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		this->BindObject(eDragonLeft, 2337, 108.0, 45.0, 0.0, 383.5);
		this->BindObject(eDragonRight, 2336, 108.0, 45.0, 532.0, 383.5);
		this->BindObject(eParty, iNewParty, 24, 25, 348, 447);
		this->BindObject(eCharacter, iNewCharacter, 24, 25, 379, 447);
		this->BindObject(eInventory, iNewInventory, 24, 25, 409, 447);
		this->BindObject(eFriend, iNewWinpush, 52, 18, 581, 432);
		this->BindObject(eGuild, iNewGuild, 52, 18, 581, 454);
	}

	//-> Custom Interface Type (S8)
	if(gProtect.m_MainInfo.CustomInterfaceType == 4 || gProtect.m_MainInfo.CustomInterfaceType == 5)
	{
		this->BindObject(eMainEx700Exp, 59000, 960, 160, 50, 394);
		this->BindObject(eMainEx700, 31293, 960, 160, 50, 388);
		this->BindObject(eShop1, 0x901, 17, 17, 76.5, 452);
		this->BindObject(eShop2, 0x902, 17, 17, 76.5, 452);
		this->BindObject(eCharacter1, 0x903, 17, 17, 98.5, 452);
		this->BindObject(eCharacter2, 0x904, 17, 17, 98.5, 452);
		this->BindObject(eInventory1, 0x905, 17, 17, 120.5, 452);
		this->BindObject(eInventory2, 0x906, 17, 17, 120.5, 452);
		this->BindObject(eQuest1, 0x907, 17, 17, 503.5, 452);
		this->BindObject(eQuest2, 0x908, 17, 17, 503.5, 452);
		this->BindObject(eCommunity1, 0x909, 17, 17, 525.5, 452);
		this->BindObject(eCommunity2, 0x910, 17, 17, 525.5, 452);
		this->BindObject(eSystem1, 0x911, 17, 17, 547.5, 452);
		this->BindObject(eSystem2, 0x912, 17, 17, 547.5, 452);

		this->BindObject(ButtonSettings, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStart, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStop, 51522, 19, 19, -1, -1);
	}

	//-> Camera
	this->BindObject(eCAMERA_MAIN, 0x787A, 93, 18, 174, 0);
	this->BindObject(eCAMERA_BUTTON1, 0x787B, 16, 12, -1, -1);
	this->BindObject(eCAMERA_BUTTON2, 0x787C, 16, 12, -1, -1);

	//-> Jewel Bank Buttons
	this->BindObject(e_SEND_ZEN_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(e_RECV_ZEN_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(e_SEND_CHAOS_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(e_RECV_CHAOS_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(e_SEND_BLESS_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(e_RECV_BLESS_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(e_SEND_SOUL_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(e_RECV_SOUL_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(e_SEND_LIFE_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(e_RECV_LIFE_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(e_SEND_CREATION_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(e_RECV_CREATION_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(e_SEND_HARMONY_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(e_RECV_HARMONY_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(e_SEND_GUARDIAN_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(e_RECV_GUARDIAN_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(e_SEND_GEMSTONE_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(e_RECV_GEMSTONE_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(e_SEND_LOW_REFINE_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(e_RECV_LOW_REFINE_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(e_SEND_HIGH_REFINE_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(e_RECV_HIGH_REFINE_BUTTON, 0x7C0D, 15, 15, -1, -1);
	//--
	this->BindObject(EXPe_SEND_ZEN_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(EXPe_RECV_ZEN_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(EXPe_SEND_CHAOS_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(EXPe_RECV_CHAOS_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(EXPe_SEND_BLESS_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(EXPe_RECV_BLESS_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(EXPe_SEND_SOUL_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(EXPe_RECV_SOUL_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(EXPe_SEND_LIFE_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(EXPe_RECV_LIFE_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(EXPe_SEND_CREATION_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(EXPe_RECV_CREATION_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(EXPe_SEND_HARMONY_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(EXPe_RECV_HARMONY_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(EXPe_SEND_GUARDIAN_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(EXPe_RECV_GUARDIAN_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(EXPe_SEND_GEMSTONE_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(EXPe_RECV_GEMSTONE_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(EXPe_SEND_LOW_REFINE_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(EXPe_RECV_LOW_REFINE_BUTTON, 0x7C0D, 15, 15, -1, -1);
	this->BindObject(EXPe_SEND_HIGH_REFINE_BUTTON, 0x7AA4, 15, 15, -1, -1);
	this->BindObject(EXPe_RECV_HIGH_REFINE_BUTTON, 0x7C0D, 15, 15, -1, -1);
	
	//- Fix Custom Store close button
	this->BindObject(eSTORE_CLOSE, iNewCloseStoreBtn, 30, 30, -1, -1);

	this->BindObject(eNextCommand, 0x7903, 25, 40, -1, -1);
	this->BindObject(ePrevCommand, 0x7904, 25, 40, -1, -1);

	this->BindObject(eNextEvent, 0x7903, 25, 40, -1, -1);
	this->BindObject(ePrevEvent, 0x7904, 25, 40, -1, -1);

	this->BindObject(ButtonStartAttack, 31593, 15, 15, -15, -15);

	//-> Welcome Yes Button
	this->BindObject(eBEMVINDO_YES,0x7B12,54, 30,-1,-1);
	
	//-> Time Zone
	int EnableTime = GetPrivateProfileIntA("Other", "ServerTime ", 0, ".\\Settings.ini");
	if(EnableTime == 0)
	{
		this->Data[eTIME].OnShow = false;
	}
	
	else
	{
		this->Data[eTIME].OnShow = true;
	}

	teste=0;

	SetOp((LPVOID)oLoadSomeForm_Call, this->LoadImages, ASM::CALL);
	SetOp((LPVOID)oDrawInterface_Call, this->Work, ASM::CALL);
	SetOp((LPVOID)oDrawInterface2_Call, this->Work2, ASM::CALL);

	SetCompleteHook(0xFF, 0x00633FFB, &this->LoadModels);

	//==========================================
	// - Remove Texts PShop
	//==========================================
	SetRange((LPVOID)0x00842086, 5, ASM::NOP);
	SetRange((LPVOID)0x0084234F, 5, ASM::NOP);
	SetRange((LPVOID)0x008423C3, 5, ASM::NOP);

	//-> New Blood Castle Window
	if(gProtect.m_MainInfo.CustomBloodCastleWindow == 1)
	{
		SetDword(0x00874FB0+1,(DWORD)""); //Remove Text BC8 (Text.bmd)
	}

	//SetDword(0x0D47384,(DWORD)40);

	//new op menu KG
	this->BindObject(eOpMenu_MAINKG, 0x7A5A, 222, 290, -1, -1);
	this->BindObject(eOpMenu_TITLEKG, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eOpMenu_CLOSEKG, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eUSERSPANEL_LINE, 0x7B67, 154, 2, -1, -1);
	this->BindObject(eOpMenu_FRAMEKG, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eOpMenu_FOOTERKG, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eOpMenu_DIVKG, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCheck, 0x9991, 15, 15, -1, -1);
	this->BindObject(eUnCheck, 0x9992, 15, 15, -1, -1);
	this->BindObject(eUSERSPANEL_OPTION, 0x7B68, 10, 10, -1, -1);
	//op new menu -> Button
	this->BindObject(eUSERSPANEL_FOG, 0x9991, 15, 15, -1, -1);
	this->BindObject(eUSERSPANEL_MINIMAP, 0x9991, 15, 15, -1, -1);
	this->BindObject(eUSERSPANEL_TIME, 0x9991, 15, 15, -1, -1);
	this->BindObject(eUSERSPANEL_GLOW, 0x9991, 15, 15, -1, -1);
	this->BindObject(eUSERSPANEL_FPS, 0x9991, 15, 15, -1, -1);
	this->BindObject(eUSERSPANEL_CHAT, 0x9991, 15, 15, -1, -1);
	this->BindObject(eUSERSPANEL_DRAGON, 0x9991, 15, 15, -1, -1);
	this->BindObject(eUSERSPANEL_INVIS1, 0x9991, 15, 15, -1, -1);
	this->BindObject(eUSERSPANEL_INVIS2, 0x9991, 15, 15, -1, -1);
	this->BindObject(eUSERSPANEL_INVIS3, 0x9991, 15, 15, -1, -1);
	this->BindObject(eUSERSPANEL_INVIS4, 0x9991, 15, 15, -1, -1);

	//- Add ShowPing in game option
	if(gProtect.m_MainInfo.PingTest == 1)
	{
		int DisablePing = GetPrivateProfileIntA("Other", "DisablePing ", 0, ".\\Settings.ini");
		if(DisablePing == 0)
		{
			//Ping
			gInterface.iniciador = 1;
			//FPS
			gInterface.lastReport = GetTickCount();
			gInterface.frameCount = 0;
		}
	}
}

void Interface::LoadModels()
{
	pLoadModel(406, "Data\\Custom\\Bmd\\VIP1\\", "musign", -1);
	pLoadTexture(406, "Custom\\Bmd\\VIP1\\", 0x2901, 0x2600, 1);
	pLoadModel(407, "Data\\Custom\\Bmd\\VIP2\\", "musign", -1);
	pLoadTexture(407, "Custom\\Bmd\\VIP2\\", 0x2901, 0x2600, 1);
	pLoadModel(408, "Data\\Custom\\Bmd\\VIP3\\", "musign", -1);
	pLoadTexture(408, "Custom\\Bmd\\VIP3\\", 0x2901, 0x2600, 1);
	// ----
	pInitModelData2();
}

void Interface::LoadImages()
{
	//-> Rank User
	pLoadImage("Custom\\Interface\\Rank01.tga", 0x7880, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank02.tga", 0x7881, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank03.tga", 0x7882, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank04.tga", 0x7883, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank05.tga", 0x7884, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank06.tga", 0x7885, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank07.tga", 0x7886, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank08.tga", 0x7887, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank09.tga", 0x7888, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank10.tga", 0x7889, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank11.tga", 0x7890, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank12.tga", 0x7891, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank13.tga", 0x7892, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank14.tga", 0x7893, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank15.tga", 0x7894, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank16.tga", 0x7895, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank17.tga", 0x7896, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank18.tga", 0x7897, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank19.tga", 0x7898, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank20.tga", 0x7899, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank21.tga", 0x7900, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank22.tga", 0x7901, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Ranking.tga", 0x7902, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Next.tga", 0x7903, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Previous.tga", 0x7904, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\MU-logo.tga", 0x7905, 0x2601, 0x2901, 1, 0);

	pLoadImage("Custom\\Interface\\MenuBC.tga", 0x922, GL_LINEAR, GL_CLAMP, 1, 0);

	//Login Screen S2
	if(gProtect.m_MainInfo.SelectLoginThemeType == 1)
	{
		pLoadImage("Logo\\Login_Back01.jpg", 500021, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Logo\\Login_Back02.jpg", 500022, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Logo\\MU-logo.tga", 531018, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Logo\\MU-logo_g.jpg", 531019, GL_LINEAR, GL_REPEAT, 1, 0);

		pLoadImage("Logo\\character_back01.jpg", 100014, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Logo\\character_back02.jpg", 100015, GL_LINEAR, GL_CLAMP, 1, 0);
	}

	//Login Screen S4
	if(gProtect.m_MainInfo.SelectLoginThemeType == 1)
	{
		pLoadImage("Logo\\sos3sky01.jpg", 531013, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Logo\\sos3sky02.jpg", 531014, GL_LINEAR, GL_CLAMP, 1, 0);
	}

	//Login Screen Ex700
	if(gProtect.m_MainInfo.SelectLoginThemeType == 4 || gProtect.m_MainInfo.SelectLoginThemeType == 5)
	{
		pLoadImage("Logo\\MU-logo.tga", 531018, GL_LINEAR, GL_REPEAT, 1, 0);	
		pLoadImage("Logo\\MU-logo_g.jpg", 531019, GL_LINEAR, GL_REPEAT, 1, 0);	
		pLoadImage("Effect\\magic_ground1_3.jpg", 32779, GL_LINEAR, GL_REPEAT, 1, 0);
	}

	//-> Custom Menu
	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		pLoadImage("Custom\\Interface\\Menu1.tga", 0x7906, 0x2601, 0x2901, 1, 0);
	}
	else
	{
		
		//Custom Interface Type (S8)
		if(gProtect.m_MainInfo.CustomInterfaceType == 4 || gProtect.m_MainInfo.CustomInterfaceType == 5 || gProtect.m_MainInfo.CustomInterfaceType == 6)
		{	
			pLoadImage("Custom\\Interface\\null.tga", 0x7906, 0x2601, 0x2901, 1, 0);
			pLoadImage("Custom\\Interface\\null.tga", 0x7907, 0x2601, 0x2901, 1, 0);
		}
		else
		{
			pLoadImage("Custom\\Interface\\Menu2.tga", 0x7906, 0x2601, 0x2901, 1, 0);
			//pLoadImage("Custom\\Interface\\null.tga", 0x7907, 0x2601, 0x2901, 1, 0);
			pLoadImage("Custom\\Interface\\Menu_BG.tga", 0x7907, 0x2601, 0x2901, 1, 0);
		}
	}
	
	pLoadImage("Custom\\Interface\\Button.tga", 0x7908, 0x2601, 0x2900,1,0);
	

	//-> Custom Interface (S6 Original)
	if(gProtect.m_MainInfo.CustomInterfaceType == 0)
	{
		//-> Server Time Bar
		pLoadImage("Custom\\Interface\\TimeBar.tga", 0x787F, 0x2601, 0x2901, 1, 0);
	}

	//-> Custom Interface (S1)
	if(gProtect.m_MainInfo.CustomInterfaceType == 1)
	{
		//-- chat
		LoadBitmapA("Custom\\Interface\\S2\\chat\\nis_vframe.jpg", 51551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\S2\\chat\\nis_rsframe.tga", 51552, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\S2\\chat\\nis_rsframe_up.jpg", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\S2\\chat\\nis_rsframe_m.jpg", 51554, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\S2\\chat\\nis_rsframe_down.jpg", 51555, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\S2\\chat\\nis_hframe.jpg", 31275, 9729, 10496, 1, 0);
		LoadBitmapA("Custom\\Interface\\S2\\Chat\\dialogue1.tga", 51530, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\S2\\Chat\\dialogue2.tga", 51531, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\S2\\Chat\\dialogue2_1.jpg", 51532, GL_LINEAR, GL_CLAMP, 1, 0);

		//--
		LoadBitmapA("Custom\\Interface\\S2\\Chat\\chat_bg03.tga", 51545, GL_LINEAR, GL_CLAMP, 1, 0);

		pLoadImage("Custom\\Interface\\S2\\Chat\\dialogue2_1.jpg", 51532, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Chat\\btnChatOn.jpg", 0x700021, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Chat\\btnWinSize.jpg", 0x700022, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Chat\\btnAlpha.jpg", 0x700023, GL_LINEAR, GL_CLAMP, 1, 0);

		pLoadImage("Custom\\Interface\\S1\\DragonRight.tga", 2336, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\DragonLeft.tga", 2337, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\Menu_Left.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\Menu_Middle.jpg", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\Menu_Right.jpg", 31294, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\Menu_Red.tga", 0x7A42, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\Menu_Green.tga", 0x7A41, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\Menu_Blue.tga", 0x7A40, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\Menu_AG.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Null.tga", 31300, GL_LINEAR, GL_CLAMP, 1, 0); //SD
		pLoadImage("Custom\\Interface\\S1\\newui_skill.jpg", 31308, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\newui_skill3.jpg", 31311, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\newui_command.jpg", 31310, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\newui_non_skill.jpg", 31314, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\newui_non_skill3.jpg", 31317, GL_LINEAR, GL_CLAMP, 1, 0); 
		pLoadImage("Custom\\Interface\\S1\\newui_skillbox.jpg", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\newui_skillbox2.jpg", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\Menu_Inventory.tga", iNewInventory, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\Menu_Character.tga", iNewCharacter, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\Menu_Party.tga", iNewParty, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\Menu_friend.tga", iNewWinpush, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\Menu_guild.tga", iNewGuild, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\Stats.jpg", 31352, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\StatsDL.jpg", 51291, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\Stats2.jpg", 51292, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\Level_box.jpg", 35353, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S1\\Level_button.jpg", 51290, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Null.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0);

		//-> Server Time Bar
		pLoadImage("Custom\\Interface\\TimeBar.tga", 0x787F, 0x2601, 0x2901, 1, 0);
	}

	//-> Custom Interface (S2)
	if(gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		//-- chat
		LoadBitmapA("Custom\\Interface\\S2\\chat\\nis_vframe.jpg", 51551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\S2\\chat\\nis_rsframe.tga", 51552, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\S2\\chat\\nis_rsframe_up.jpg", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\S2\\chat\\nis_rsframe_m.jpg", 51554, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\S2\\chat\\nis_rsframe_down.jpg", 51555, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\S2\\chat\\nis_hframe.jpg", 31275, 9729, 10496, 1, 0);
		LoadBitmapA("Custom\\Interface\\S2\\Chat\\dialogue1.tga", 51530, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\S2\\Chat\\dialogue2.tga", 51531, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\S2\\Chat\\dialogue2_1.jpg", 51532, GL_LINEAR, GL_CLAMP, 1, 0);

		//--
		LoadBitmapA("Custom\\Interface\\S2\\Chat\\chat_bg03.tga", 51545, GL_LINEAR, GL_CLAMP, 1, 0);

		pLoadImage("Custom\\Interface\\S2\\Chat\\dialogue2_1.jpg", 51532, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Chat\\btnChatOn.jpg", 0x700021, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Chat\\btnWinSize.jpg", 0x700022, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Chat\\btnAlpha.jpg", 0x700023, GL_LINEAR, GL_CLAMP, 1, 0);

		pLoadImage("Custom\\Interface\\S2\\DragonRight.tga", 2336, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\DragonLeft.tga", 2337, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Menu_Left.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Menu_Middle.jpg", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Menu_Right.jpg", 31294, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Menu_Red.tga", 0x7A42, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Menu_Green.tga", 0x7A41, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Menu_Blue.tga", 0x7A40, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Menu_AG.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Menu_SD.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\newui_skill.jpg", 31308, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\newui_skill3.jpg", 31311, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\newui_command.jpg", 31310, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\newui_non_skill.jpg", 31314, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\newui_non_skill3.jpg", 31317, GL_LINEAR, GL_CLAMP, 1, 0); 
		pLoadImage("Custom\\Interface\\S2\\newui_skillbox.jpg", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\newui_skillbox2.jpg", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Menu_Inventory.tga", iNewInventory, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Menu_Character.tga", iNewCharacter, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Menu_Party.tga", iNewParty, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Menu_friend.tga", iNewWinpush, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Menu_guild.tga", iNewGuild, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Menu_fastmenu.tga", iNewFastMenu, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Stats.jpg", 31352, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\StatsDL.jpg", 51291, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Stats2.jpg", 51292, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Level_box.jpg", 35353, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S2\\Level_button.jpg", 51290, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Null.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0);

		//-> Server Time Bar
		pLoadImage("Custom\\Interface\\TimeBar.tga", 0x787F, 0x2601, 0x2901, 1, 0);
	}

	//-> Custom Interface Type (S3)
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
	//	pLoadImage("Custom\\Interface\\S3\\DragonRight.tga", 2336, GL_LINEAR, GL_CLAMP, 1, 0);
	//	pLoadImage("Custom\\Interface\\S3\\DragonLeft.tga", 2337, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Menu_Left.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Menu_Middle.jpg", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Menu_Right.jpg", 31294, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Menu_Red.tga", 0x7A42, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Menu_Green.tga", 0x7A41, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Menu_Blue.tga", 0x7A40, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Menu_AG.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Menu_SD.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\newui_skill.jpg", 31308, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\newui_skill3.jpg", 31311, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\newui_command.jpg", 31310, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\newui_non_skill.jpg", 31314, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\newui_non_skill3.jpg", 31317, GL_LINEAR, GL_CLAMP, 1, 0); 
		pLoadImage("Custom\\Interface\\S3\\newui_skillbox.jpg", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\newui_skillbox2.jpg", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Menu_Inventory.tga", iNewInventory, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Menu_Character.tga", iNewCharacter, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Menu_Party.tga", iNewParty, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Menu_friend.tga", iNewWinpush, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Menu_guild.tga", iNewGuild, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Menu_fastmenu.tga", iNewFastMenu, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Stats.jpg", 31352, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\StatsDL.jpg", 51291, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Stats2.jpg", 51292, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Level_box.jpg", 35353, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S3\\Level_button.jpg", 51290, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Null.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0);

		//-> Server Time Bar
		pLoadImage("Custom\\Interface\\TimeBar.tga", 0x787F, 0x2601, 0x2901, 1, 0);
	}
	
	//-> Custom Interface Type (S8)
	if(gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		pLoadImage("Custom\\Interface\\S8\\Main_IE_Exp.tga", 59000, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Null.tga", 31292, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Null.tga", 0x7A48, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);	
		pLoadImage("Custom\\Interface\\Null.tga", 31294, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Null.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Main_I3.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Main_I2.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Main_I1.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Main_I5.tga", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Main_I4.tga", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\newui_skill.tga", 31308, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\newui_skill3.tga", 31311, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\newui_command.tga", 31310, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\newui_non_skill.tga", 31314, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\newui_non_skill3.tga", 31317, GL_LINEAR, GL_CLAMP, 1, 0); 
		pLoadImage("Custom\\Interface\\S8\\newui_non_command.tga", 31316, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Buttons\\Shop1.tga", 0x901, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Buttons\\Shop2.tga", 0x902, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Buttons\\Character1.tga", 0x903, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Buttons\\Character2.tga", 0x904, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Buttons\\Inventory1.tga", 0x905, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Buttons\\Inventory2.tga", 0x906, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Buttons\\Quest1.tga", 0x907, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Buttons\\Quest2.tga", 0x908, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Buttons\\Community1.tga", 0x909, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Buttons\\Community2.tga", 0x910, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Buttons\\System1.tga", 0x911, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Buttons\\System2.tga", 0x912, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);

		//-- Folder MacroUI
		pLoadImage("Custom\\Interface\\S8\\MacroUI\\MacroUI_Main.tga", 51550, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\MacroUI\\MacroUI_BSetup.tga", 51546, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\MacroUI\\MacroUI_BStart.tga", 51547, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\MacroUI\\MacroUI_Stop.tga", 51548, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\MacroUI\\MacroUI_Bar.jpg", 51549, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\MacroUI\\MacroUI_Menu.tga", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\Null.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Custom\\Interface\\S8\\PartyBar.tga", 61548, GL_LINEAR, GL_CLAMP, 1, 0);
        pLoadImage("Custom\\Interface\\S8\\newui_Party_Back.tga", 81520, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\newui_Party_flag.tga", 81521, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\newui_Party_HpBar.jpg", 81522, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\newui_Party_ManaBar.jpg", 81523, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\newui_Party_X.tga", 81524, 0x2601, 0x2901, 1, 0);

		LoadBitmapA("Custom\\Interface\\S8\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Custom\\Interface\\Null.tga", 51552, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\Null.tga", 51551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\S8\\Chat\\chat_bg03.tga", 51545, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\Null.tga", 31270, 9729, 10496, 1, 0);
		LoadBitmapA("Custom\\Interface\\Null.tga", 31271, 9729, 10496, 1, 0);
		LoadBitmapA("Custom\\Interface\\Null.tga", 31272, 9729, 10496, 1, 0);
	    LoadBitmapA("Custom\\Interface\\S8\\Chat\\newui_Scrollbar_stretch.tga", 31275, 9729, 10496, 1, 0);
    	LoadBitmapA("Custom\\Interface\\S8\\Chat\\Chat_Main01.tga", 51529, GL_LINEAR, GL_CLAMP, 1, 0);
	    LoadBitmapA("Custom\\Interface\\S8\\Chat\\Chat_Main02.tga", 51541, GL_LINEAR, GL_CLAMP, 1, 0);
	    for (int i = 51530; i < 51534; ++i)
		{
		    LoadBitmapA("Custom\\Interface\\S8\\Chat\\Chat_Button.tga", i, GL_LINEAR, GL_CLAMP, 1, 0);
	    }
	    LoadBitmapA("Custom\\Interface\\S8\\Chat\\Chat_ButtonWBack.tga", 51538, GL_LINEAR, GL_CLAMP, 1, 0);
	    LoadBitmapA("Custom\\Interface\\S8\\Chat\\Chat_ButtonSize.tga", 51539, GL_LINEAR, GL_CLAMP, 1, 0);
        LoadBitmapA("Custom\\Interface\\S8\\Chat\\Chat_ButtonTransparencyA.tga", 51540, GL_LINEAR, GL_CLAMP, 1, 0);
	    LoadBitmapA("Custom\\Interface\\S8\\Chat\\Chat_ButtonHide01.tga", 51542, GL_LINEAR, GL_CLAMP, 1, 0);
	    LoadBitmapA("Custom\\Interface\\S8\\Chat\\Chat_ButtonHide02.tga", 51543, GL_LINEAR, GL_CLAMP, 1, 0);
	    LoadBitmapA("Custom\\Interface\\S8\\Chat\\Chat_ButtonHide03.tga", 51544, GL_LINEAR, GL_CLAMP, 1, 0);
	}

	//-> Custom Interface Type (Legend)
	if(gProtect.m_MainInfo.CustomInterfaceType == 5)
	{
		pLoadImage("Custom\\Interface\\Legend\\Main_IE_Exp.tga", 59000, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Null.tga", 31292, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Null.tga", 0x7A48, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);	
		pLoadImage("Custom\\Interface\\Null.tga", 31294, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Null.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Main_I3.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Main_I2.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Main_I1.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Main_I5.tga", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Main_I4.tga", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\newui_skill.tga", 31308, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\newui_skill3.tga", 31311, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\newui_command.tga", 31310, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\newui_non_skill.tga", 31314, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\newui_non_skill3.tga", 31317, GL_LINEAR, GL_CLAMP, 1, 0); 
		pLoadImage("Custom\\Interface\\Legend\\newui_non_command.tga", 31316, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Buttons\\Shop1.tga", 0x901, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Buttons\\Shop2.tga", 0x902, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Buttons\\Character1.tga", 0x903, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Buttons\\Character2.tga", 0x904, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Buttons\\Inventory1.tga", 0x905, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Buttons\\Inventory2.tga", 0x906, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Buttons\\Quest1.tga", 0x907, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Buttons\\Quest2.tga", 0x908, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Buttons\\Community1.tga", 0x909, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Buttons\\Community2.tga", 0x910, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Buttons\\System1.tga", 0x911, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Buttons\\System2.tga", 0x912, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);

		//-- Folder MacroUI
		pLoadImage("Custom\\Interface\\Legend\\MacroUI\\MacroUI_Main.tga", 51550, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\MacroUI\\MacroUI_BSetup.tga", 51546, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\MacroUI\\MacroUI_BStart.tga", 51547, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\MacroUI\\MacroUI_Stop.tga", 51548, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\MacroUI\\MacroUI_Bar.jpg", 51549, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interface\\Legend\\MacroUI\\MacroUI_Menu.tga", 51553, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Custom\\Interface\\Null.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
	}

	//->Disable Cash Shop - Option S4
	if(gProtect.m_MainInfo.DisableCashShop == 1 && gProtect.m_MainInfo.CustomInterfaceType == 0)
	{
		pLoadImage("Custom\\Interface\\S4\\btnOption1.jpg", 0x53529, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Custom\\Interface\\S4\\btnOption1hover.jpg", 0x53530, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Custom\\Interface\\S4\\btnOption1click.jpg", 0x53531, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Custom\\Interface\\S4\\btnOption2.jpg", 0x53532, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Custom\\Interface\\S4\\btnOption2hover.jpg", 0x53533, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Custom\\Interface\\S4\\btnOption2click.jpg", 0x53534, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Custom\\Interface\\S4\\btnOption3.jpg", 0x53535, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Custom\\Interface\\S4\\btnOption3hover.jpg", 0x53536, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Custom\\Interface\\S4\\btnOption3click.jpg", 0x53537, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Custom\\Interface\\S4\\btnOption4.jpg", 0x53538, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Custom\\Interface\\S4\\btnOption4hover.jpg", 0x53539, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Custom\\Interface\\S4\\btnOption4click.jpg", 0x53540, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Custom\\Interface\\Null.tga", 0x53541, GL_LINEAR, GL_REPEAT, 1, 0);
	}

	//- Fix Custom Store close button
	pLoadImage("Custom\\Interface\\Null.tga", iNewCloseStoreBtn, 0x2601, 0x2901, 1, 0);
	
	//-> Custom Interface Type (S8)
	if(gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		//newmenu
		pLoadImage("Custom\\Interface\\S8\\check.jpg", 0x9991, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\uncheck.jpg", 0x9992, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\Button.tga", 0x7908, 0x2601, 0x2900,1,0);

		pLoadImage("Custom\\Interface\\S8\\Notice.jpg", 0x9969, 0x2601, 0x2900, 1, 0);

		//-> Camera
		pLoadImage("Custom\\Interface\\NULL.tga", 0x787B, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\Interface\\NULL.tga", 0x787C, 0x2601, 0x2900, 1, 0);

		pLoadImage("Custom\\Interface\\S8\\CameraUI_Switch.tga", 0x787D, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\Interface\\S8\\CameraUI_Reset.tga", 0x787E, 0x2601, 0x2900, 1, 0);
	}

	else
	{
		//newmenu
		pLoadImage("Custom\\Interface\\check.jpg", 0x9991, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\Interface\\uncheck.jpg", 0x9992, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\Interface\\Button.tga", 0x7908, 0x2601, 0x2900,1,0);

		pLoadImage("Custom\\Interface\\Notice.jpg", 0x9969, 0x2601, 0x2900, 1, 0);

		//-> Camera
		pLoadImage("Custom\\Interface\\CameraUI_BG.tga", 0x787A, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\Interface\\CameraUI_Switch.tga", 0x787B, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\Interface\\CameraUI_Reset.tga", 0x787C, 0x2601, 0x2900, 1, 0);
	}

	//-> Custom Cloaks
	gCloak.LoadTexture();

	pLoadImage("Custom\\Interface\\MenuWelcome.jpg", 0x923, GL_LINEAR, GL_CLAMP, 1, 0);

	LoadBitmapA("Custom\\Interface\\login_auto.tga", 531141, GL_NEAREST, GL_CLAMP, 1, 0);

	pLoadSomeForm();
}

void Interface::BindObject(short MonsterID, DWORD ModelID, float Width, float Height, float X, float Y)
{
	this->Data[MonsterID].EventTick	= 0;
	this->Data[MonsterID].OnClick	= false;
	this->Data[MonsterID].OnShow	= false;
	this->Data[MonsterID].ModelID	= ModelID;
	this->Data[MonsterID].Width		= Width;
	this->Data[MonsterID].Height	= Height;
	this->Data[MonsterID].X			= X;
	this->Data[MonsterID].Y			= Y;
	this->Data[MonsterID].MaxX		= X + Width;
	this->Data[MonsterID].MaxY		= Y + Height;
	this->Data[MonsterID].Attribute	= 0;
}

void Interface::DrawGUI(short ObjectID, float PosX, float PosY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI2(short ObjectID, float PosX, float PosY)
{
	this->Data[ObjectID].X		= PosX;
	this->Data[ObjectID].Y		= PosY;
	this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if(this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	pDrawImage(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
}

void Interface::ResetDrawIMG(short ObjectID)
{
	if(this->Data[ObjectID].X != -1 || this->Data[ObjectID].Y != -1)
	{
		this->Data[ObjectID].X		= -1;
		this->Data[ObjectID].Y		= -1;
		this->Data[ObjectID].MaxX	= -1;
		this->Data[ObjectID].MaxY	= -1;
	}
}

void Interface::BetellHost()  
{
	char test[500];
	sprintf_s(test, sizeof(test), "%s || Player: %s || Level: %d || Reset: %d || WC: %d || WP: %d || GP: %d", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name, gObjUser.lpPlayer->Level, ViewReset, Coin1, Coin2, Coin3);
	SetWindowText(pGameWindow, test);
}

void Interface::Work()
{
	gObjUser.Refresh();
	//--
	//gCamera.Rotate();
	//gCamera.Position();
	//gInterface.DrawCameraUI();
	//--
	gCustomRanking.DrawRankPanelWindow();
	gCustomEventTime.DrawEventTimePanelWindow();
	gInterface.DrawTimeUI();
	ReconnectMainProc();
	gInterface.DrawVipWindow();
	gInterface.DrawMenu();
	gInterface.DrawMenuOpen();
	gCustomCommandInfo.DrawCommandWindow();
	gOffTrade.DrawOffTradeWindow();
	gInterface.DrawConfirmOpen();
	gInterface.DrawChaosBoxWindow();

	//-> Jewels Bank
	if (gProtect.m_MainInfo.CustomJewelBankEnable == 1)
	{
		gJewelBank.DrawJewelBank();
	}

	//-> Anti Lag System
	if (gProtect.m_MainInfo.CustomJewelBankEnable == 1)
	{
		gInterface.DrawOpAntiLag();
	}

	if( GetForegroundWindow() == pGameWindow )
	{
		if (GetKeyState(VK_SNAPSHOT) < 0) 
		{
			gInterface.DrawLogo(1); 
		}

	//-> Jewels Bank
	if (gProtect.m_MainInfo.CustomJewelBankEnable == 1)
	{
		if (GetKeyState('J') & 0x4000  && GetTickCount() >= gJewelBank.OpenJewelBankDelay + 250)
		{
			if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
			{
				if (gJewelBank.CheckJewelWindow())
				{
					gJewelBank.CloseJewelWindow();
					pSetCursorFocus = false;
				}
				else
				{
					gJewelBank.OpenJewelWindow();
					pSetCursorFocus = true;
				}
				gJewelBank.OpenJewelBankDelay = GetTickCount();
			}
		}
	}

		if (GetKeyState(VK_END) & 0x4000) 
		{
			if((GetTickCount()-gInterface.Data[eVip_MAIN].EventTick) > 300)
			{
				if (gInterface.CheckVipWindow())
				{
					gInterface.Data[eVip_MAIN].EventTick = GetTickCount();
					gInterface.CloseVipWindow();
				}

				else
				{
					gInterface.Data[eVip_MAIN].EventTick = GetTickCount();
					gInterface.CloseCustomWindow();
					gInterface.OpenVipWindow();
				}
			}
		}

		if (GetKeyState('H') & 0x4000) 
		{
			gCustomEventTime.OpenWindow();
		}

		//Anti Lag System
		if (GetKeyState('O') & 0x4000 && GetTickCount() >= gInterface.MenuAntlagDelayClick + 250) 
		{
			if (!gInterface.CheckWindow(ObjWindow::ChatWindow))
			{
				if (gInterface.CheckOpMenuAntiLag())
				{
					gInterface.CloseOpMenuAntiLag();
				}
				
				else
				{
					gInterface.OpenOpMenuAntiLag();
				}
			}

			gInterface.MenuAntlagDelayClick = GetTickCount();
		}

	/*	if (GetKeyState(VK_F8) & 0x4000) 
		{
			gCustomRanking.OpenWindow();
		}*/

		if (GetKeyState(VK_TAB) & 0x4000) 
		{
			if (gInterface.CheckWindow(ObjWindow::FullMap))
			{
				MiniMap = (MiniMap==0)?1:0;
			}
		}

		if (GetKeyState(VK_ESCAPE) < 0) 
		{
			if (gInterface.Data[eCommand_MAIN].OnShow == true)
			{
				gInterface.Data[eCommand_MAIN].OnShow = false;
				pSetCursorFocus = false;
			}

			if (gInterface.Data[eRankPANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eRankPANEL_MAIN].OnShow = false;
				pSetCursorFocus = false;
			}

			if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
				pSetCursorFocus = false;
			}

			if (gInterface.CheckVipWindow())
			{
				gInterface.CloseVipWindow();
			}

			if (gInterface.CheckMenuWindow())
			{
				gInterface.CloseMenuWindow();
			}
		}
	}

	gInterface.DrawLogo(0);

	//-> Interface Dragons (S1/S2)
	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		gInterface.DrawInterfaceDragonLS3();
		gInterface.DrawInterfaceDragonRS3();
	}

	pDrawInterface();

	//-> Advanced Stats
	if (gProtect.m_MainInfo.CustomAdvancedStausEnable == 1)
	{
		g_StatsAdvance.DrawInfo();
	}
	
	switch(gProtect.m_MainInfo.CustomInterfaceType)
	{
	case 1:
		gInterface.DrawInterface97Menu();
		break;
	case 2:
		gInterface.DrawInterfaceS2Menu();
		break;
	case 3:
		gInterface.DrawInterfaceS3Menu();
		break;
	case 4:
		gInterface.DrawInterfaceCustom();
		gInterface.DrawMenuButton();
		if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 677) != 0 || *(DWORD *)(*(DWORD *)0x7BC4F04 + 557) != 65535)
		{
			gInterface.BarPartyNew();
		}
		break;
	case 5:
		gInterface.DrawInterfaceCustom();
		gInterface.DrawMenuButton();
		break;
		if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 677) != 0 || *(DWORD *)(*(DWORD *)0x7BC4F04 + 557) != 65535)
		{
			gInterface.BarPartyNew();
		}
	}

	//-> Custom Blood Castle Window
	if(gProtect.m_MainInfo.CustomBloodCastleWindow == 1)
	{
		gInterface.DrawInterfaceBloodCastle(); //-> Nova Janela do Blood Castle
	}

	//->Disable Cash Shop - Option S4
	if(gProtect.m_MainInfo.DisableCashShop == 1 && gProtect.m_MainInfo.CustomInterfaceType == 0)
	{
		gInterface.OldOption();
	}

	gInterface.DrawSendZenButton();
	gInterface.DrawRecvZenButton();
	gInterface.DrawSendChaosButton();
	gInterface.DrawRecvChaosButton();
	gInterface.DrawSendBlessButton();
	gInterface.DrawRecvBlessButton();
	gInterface.DrawSendSoulButton();
	gInterface.DrawRecvSoulButton();
	gInterface.DrawSendLifeButton();
	gInterface.DrawRecvLifeButton();
	gInterface.DrawSendCreationButton();
	gInterface.DrawRecvCreationButton();
	gInterface.DrawSendHarmonyButton();
	gInterface.DrawRecvHarmonyButton();
	gInterface.DrawSendGuardianButton();
	gInterface.DrawRecvGuardianButton();
	gInterface.DrawSendGemstoneButton();
	gInterface.DrawRecvGemstoneButton();
	gInterface.DrawSendLowerRefineStoneButton();
	gInterface.DrawRecvLowerRefineStoneButton();
	gInterface.DrawSendHighRefineStoneButton();
	gInterface.DrawRecvHighRefineStoneButton();

	//-> Custom Main Window
	if(gProtect.m_MainInfo.CustomMainWindow == 1)
	{
		gInterface.BetellHost();
	}
	//--
	//-> Custom Interface Helper Bar (S4)
	if(gProtect.m_MainInfo.CustomInterfaceHelperBar == 2)
	{
		if(gProtect.m_MainInfo.CustomInterfaceType == 4 || gProtect.m_MainInfo.CustomInterfaceType == 5 || gProtect.m_MainInfo.CustomInterfaceType == 6)
		{
			//
		}
		else
		{
			gInterface.DrawCoordS4();
		}
	}

	//- Custom Start Item Window
	if (ViewPoint == -1)
	{
		gInterface.DrawInterfaceBemVindo();
		gInterface.OpenBemVindoWindow();
	}
}

void Interface::Work2() 
{
	if (gInterface.item_post_ && pCursorX < 150)
			{
				//--
				gInterface.DrawItemToolTipText(gInterface.item_post_, pCursorX + 80, pCursorY - 80);
				if (gInterface.last_tickcount_view_ + 100 < GetTickCount())
				{
					gInterface.item_post_ = nullptr;
				}
				//--
				glColor4f(0.0, 0.0, 0.0, 0.8);
				pDrawBarForm((float)(+300), (float)(+150), 80.0f, 110.0f, 0.0f, 0); //pCursorY->Len Xuong // pCursorX->Trai Phai
				DrawItemIMG(+340.0f, +210.0f, gObjUser.PostItemX, gObjUser.PostItemY, gObjUser.PostItemID, gObjUser.PostItemLV, gObjUser.PostItemExc, 0, 0);
				//--
			}

	//- Add ShowPing in game option
	if(gProtect.m_MainInfo.PingTest == 1)
	{
		int DisablePing = GetPrivateProfileIntA("Other", "DisablePing ", 0, ".\\Settings.ini");
		if(DisablePing == 0)
		{
			//Interfaz Barra Negra
			gInterface.guiMonitore();
			//FPS
			gInterface.UPDATE_FPS();
			//Ping
			gInterface.SendPingRecv();
		}
	}

	pDrawInterface2();
}

void Interface::DrawCoordS4()
{
	gObjUser.Refresh();

	if(this->CheckWindow(ObjWindow::CashShop) 
		|| this->CheckWindow(ObjWindow::SkillTree) 
		|| this->CheckWindow(ObjWindow::MoveList) 
		
		|| (this->CheckWindow(ObjWindow::ExpandWarehouse) && this->CheckWindow(ObjWindow::Warehouse) && this->CheckWindow(ObjWindow::Inventory))
		|| (this->CheckWindow(ObjWindow::ExpandInventory) && this->CheckWindow(ObjWindow::Warehouse) && this->CheckWindow(ObjWindow::Inventory))
		|| (this->CheckWindow(ObjWindow::ExpandInventory) && this->CheckWindow(ObjWindow::Character) && this->CheckWindow(ObjWindow::Inventory))
		|| (this->CheckWindow(ObjWindow::ExpandInventory) && this->CheckWindow(ObjWindow::Store) && this->CheckWindow(ObjWindow::Inventory)))
	{
		return;
	}

	char Cord[256];

	if (*(DWORD*)MAIN_SCREEN_STATE == 5)
	{
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pSetTextColor(pTextThis(), 240, 240, 240, 255);
	
		wsprintf(Cord, "%d  %d", gObjUser.CoordenadaX, gObjUser.CoordenadaY);
	}

	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 240, 240, 240, 255);
	pDrawText(pTextThis(), 1 - 63, 4, Cord, 190, 0, (LPINT)3, 0);
	pGLSwitch();
	EnableAlphaTest(0);
}

void Interface::DrawTimeUI()
{
	if( !this->Data[eTIME].OnShow )
	{
		return;
	}

	if(this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::FullMap) || this->CheckWindow(ObjWindow::ChatWindow) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::MoveList))
	{
		return;
	}

	if(gProtect.m_MainInfo.CustomInterfaceType == 4 || gProtect.m_MainInfo.CustomInterfaceType == 5 || gProtect.m_MainInfo.CustomInterfaceType == 6)
	{
		pSetBlend(true);
		glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.6);
		pDrawBarForm(4.0, 386.0, 84.0, 42.0, 0.0f, 0);
		pGLSwitchBlend();
		glColor3f(1.0, 1.0, 1.0);
		pSetBlend(false);
	}
	else
	{
		this->DrawGUI(eTIME, this->Data[eTIME].X, this->Data[eTIME].Y);
	}
	
	struct tm * ServerT, * LocalT;
	
	time_t TimeServer, TimeLocal;
	time(&TimeServer);
	time(&TimeLocal);

	ServerT = gmtime(&TimeServer);

	char ServerTimeName[25] = "Server:";
	char ServerTime[30];
	
	sprintf(ServerTime, "%2d:%02d:%02d", (ServerT->tm_hour + 8 + GMT)%24, ServerT->tm_min, ServerT->tm_sec);
	
	LocalT = localtime(&TimeLocal); 
	
	char LocalTimeName[25] = "Local:";
	char LocalTime[30];
	
	sprintf(LocalTime, "%2d:%02d:%02d", LocalT->tm_hour, LocalT->tm_min, LocalT->tm_sec);
	
	this->DrawFormat(eGold, 10, 392, 50, 1, ServerTimeName);
	this->DrawFormat(eWhite, 50, 392, 100, 1, ServerTime);

	this->DrawFormat(eGold, 10, 414, 50, 1, LocalTimeName);
	this->DrawFormat(eWhite, 50, 414, 100, 1, LocalTime);
}

int Interface::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	int LineCount = 0;
	
	char * Line = strtok(Buff, "\n");
	
	while( Line != NULL )
	{
		pDrawColorText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
	
	return PosY;
}

bool Interface::CheckWindow(int WindowID)
{
	return pCheckWindow(pWindowThis(), WindowID);
}

int Interface::CloseWindow(int WindowID)
{
	return pCloseWindow(pWindowThis(), WindowID);
}

int Interface::OpenWindow(int WindowID)
{
	return pOpenWindow(pWindowThis(), WindowID);
}

bool Interface::IsWorkZone(short ObjectID)
{
	if((gObjUser.m_CursorX < this->Data[ObjectID].X || gObjUser.m_CursorX > this->Data[ObjectID].MaxX) || (gObjUser.m_CursorY < this->Data[ObjectID].Y || gObjUser.m_CursorY > this->Data[ObjectID].MaxY))

		return false;
	
	return true;
}

float Interface::GetResizeX(short ObjectID)
{
	if( pWinWidth == 800 )
	{
		return this->Data[ObjectID].X + 16.0;
	}

	else if( pWinWidth != 1024 )
	{
		return this->Data[ObjectID].X - 16.0;
	}
	
	return this->Data[ObjectID].X;
}

int Interface::DrawToolTip(int X, int Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	return pDrawToolTip(X, Y, Buff);
}

int Interface::DrawMessage(int Mode, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	return pDrawMessage(Buff, Mode);
}

void Interface::DrawVipWindow()
{
	if( !this->Data[eVip_MAIN].OnShow )
	{
		return;
	}

	if( gProtect.m_MainInfo.EnableVipShop != 1 )
	{
		this->CloseVipWindow();
		return;
	}

	if (this->CheckWindow(ObjWindow::MoveList)
		|| this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::FullMap)
		|| this->CheckWindow(ObjWindow::Store) //- Fix BuyVip + CustomStore
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Store))
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Character))
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory))
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		CloseVipWindow();
		return;
	}
	
	float MainWidth			= 230.0;
	float MainHeight		= 130.0;
	float StartBody			= 40.0;
	float StartY			= 40.0;
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);

	this->DrawGUI(eVip_MAIN, StartX, StartY + (float)2.0);
	this->DrawGUI(eVip_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eVip_FRAME, StartX, StartY + (float)20.0, 13);
	this->DrawGUI(eVip_FOOTER, StartX, StartY);
	this->DrawGUI(eVip_CLOSE, StartX + MainWidth - this->Data[eVip_CLOSE].Width, StartBody);

	if (this->IsWorkZone(eVip_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eVip_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eVip_CLOSE, this->Data[eVip_CLOSE].X, StartBody, Color);
		this->DrawToolTip((int)this->Data[eVip_CLOSE].X + 5, StartBody + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(5));
	int LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 35, 210, 1, gCustomMessage.GetMessage(6), gObjUser.lpPlayer->Name);
	LineY = this->DrawFormat(eGold, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(14));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(7));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(8));
	// ----
	this->DrawGUI(eVip_DIV, StartX, StartBody + 70);
	this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 95 - 2, 210, 1, "Plan");
	this->DrawFormat(eGold, (int)StartX + 80, (int)StartBody + 95 - 2 , 210, 1, "Exp");
	this->DrawFormat(eGold, (int)StartX + 130, (int)StartBody + 95 - 2, 210, 1, "Drop");
	this->DrawFormat(eGold, (int)StartX + 170, (int)StartBody + 95 - 2, 210, 1, "Time");
	// ----

	if (gProtect.m_MainInfo.VipTypes < 1 || gProtect.m_MainInfo.VipTypes > 3)
	{
		gProtect.m_MainInfo.VipTypes = 3;
	}

	for( int i = 0; i < (int)gProtect.m_MainInfo.VipTypes; i++ )
	{
		this->DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 110 + (12 * i) - 5, 210, 1, gCustomBuyVip.m_CustomBuyVipInfo[i].VipName);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 80, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Exp);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 130, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Drop);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 170, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "%d day(s)", gCustomBuyVip.m_CustomBuyVipInfo[i].Days);

		pDrawGUI(0x7B5E, StartX + 30, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
		pDrawGUI(0x7B5E, StartX + 30 + 82, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
	}

	if (gProtect.m_MainInfo.VipTypes > 0)
	{
	// ---- bronze start 
	if (IsWorkZone(eVip_BRONZE))
	{
		if (this->Data[eVip_BRONZE].OnClick)
			this->DrawButton(eVip_BRONZE, StartX + 64, 195, 0, 58);
		else
			this->DrawButton(eVip_BRONZE, StartX + 64, 195, 0, 29);
		// ----
		this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
		this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin1);
		this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin2);
		this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin3);
	}
	else
		this->DrawButton(eVip_BRONZE, StartX + 64, 195, 0, 0);
	// ----
	this->DrawFormat(eWhite, (int)StartX + 90, 195 + 9, 160, 1, gCustomMessage.GetMessage(9),gCustomBuyVip.m_CustomBuyVipInfo[0].VipName);
	// ---- bronze end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 1)
	{
	// ---- Silver start ------------------------------------
	if (IsWorkZone(eVip_SILVER))
	{
		if (this->Data[eVip_SILVER].OnClick)
			this->DrawButton(eVip_SILVER, StartX + 64, 225, 0, 58);
		else
			this->DrawButton(eVip_SILVER, StartX + 64, 225, 0, 29);
		// ----
		this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
		this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin1);
		this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin2);
		this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin3);
	}
	else
		this->DrawButton(eVip_SILVER, StartX + 64, 225, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 90, 225 + 9, 160, 1, gCustomMessage.GetMessage(9),gCustomBuyVip.m_CustomBuyVipInfo[1].VipName);
	// ---- silver end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 2)
	{
	// ---- gold start ------------------------------------
	if (IsWorkZone(eVip_GOLD))
	{
		if (this->Data[eVip_GOLD].OnClick)
			this->DrawButton(eVip_GOLD, StartX + 64, 255, 0, 58);
		else
			this->DrawButton(eVip_GOLD, StartX + 64, 255, 0, 29);
		// ----
		this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
		this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin1);
		this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin2);
		this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin3);
	}
	else
		this->DrawButton(eVip_GOLD, StartX + 64, 255, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 90, 255 + 9, 160, 1, gCustomMessage.GetMessage(9),gCustomBuyVip.m_CustomBuyVipInfo[2].VipName);
	// ---- gold end ------------------------------------
	}
}

bool Interface::EventVipWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_CLOSE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_CLOSE].EventTick = GetTickCount();
	this->CloseVipWindow();
	// ----
	return false;
}

bool Interface::EventVipWindow_Bronze(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_BRONZE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_BRONZE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_BRONZE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_BRONZE].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_BRONZE].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(1);
	this->CloseVipWindow();
	// ----
	return false;
}

bool Interface::EventVipWindow_Silver(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_SILVER].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_SILVER))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 2)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_SILVER].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_SILVER].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_SILVER].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(2);
	this->CloseVipWindow();
	// ----
	return false;
}

bool Interface::EventVipWindow_Gold(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_GOLD].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_GOLD))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 3)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_GOLD].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_GOLD].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_GOLD].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(3);
	this->CloseVipWindow();
	// ----
	return false;
}

bool Interface::EventVipWindow_Main(DWORD Event)
{
	this->EventVipWindow_Close(Event);
	this->EventVipWindow_Bronze(Event);
	this->EventVipWindow_Silver(Event);
	this->EventVipWindow_Gold(Event);
	// ----
	return true;
}

float Interface::DrawRepeatGUI(short MonsterID, float X, float Y, int Count)
{
	float StartY = Y;
	// ----
	for( int i = 0; i < Count; i++ )
	{
		pDrawGUI(this->Data[MonsterID].ModelID, X, StartY,
			this->Data[MonsterID].Width, this->Data[MonsterID].Height);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

void Interface::DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawButton2(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= X;
		this->Data[ObjectID].Y		= Y;
		this->Data[ObjectID].MaxX	= X + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= Y + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y, 
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawLogo(bool active)
{
	if (gProtect.m_MainInfo.PrintLogo != 0)
	{
		if (active == 1)
		{
			this->Data[eLogo].EventTick = GetTickCount()+1500;
		}

		if (gInterface.Data[eLogo].EventTick > GetTickCount())
		{
			if (gProtect.m_MainInfo.PrintLogo == 1)
			{
				this->DrawGUI(eLogo, 10, 10);
			}

			if (gProtect.m_MainInfo.PrintLogo == 2)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, 10);

			}

			if (gProtect.m_MainInfo.PrintLogo == 3)
			{
				this->DrawGUI(eLogo, 10, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 4)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 5)
			{
				this->DrawGUI(eLogo, (MAX_WIN_WIDTH/2)-(150/2), (MAX_WIN_HEIGHT/2)-(-150/2));
			}
		}
	}
}

void Interface::DrawMenu()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eMenu].OnShow)
	{
		this->Data[eMenu].OnShow = false;
	}
	
	if (this->CheckWindow(ObjWindow::MoveList) 
		|| this->CheckWindow(ObjWindow::CashShop) 
		|| this->CheckWindow(ObjWindow::SkillTree) 
		|| this->CheckWindow(ObjWindow::FullMap)
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Character) && this->CheckWindow(ExpandInventory))
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandInventory))
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ChaosBox) && this->CheckWindow(ExpandInventory))
		)
	{
		CloseMenuWindow();
		return;
	}
	
	this->Data[eMenu].OnShow = true;

	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		this->DrawGUI(eMenu, 3, 72);
	}

	else
	{
		//Custom Interface Type (S8)
		if(gProtect.m_MainInfo.CustomInterfaceType == 4 || gProtect.m_MainInfo.CustomInterfaceType == 5 || gProtect.m_MainInfo.CustomInterfaceType == 6)
		{
		
		}

		else
		{
			//Custom Interface Type (S4)
			if(gProtect.m_MainInfo.CustomInterfaceHelperBar == 2)
			{
				float PosX = this->GetResizeX(eMenuBG);

				this->DrawGUI(eMenuBG, PosX - 123, 0);

				this->DrawGUI(eMenu, PosX + 0.5 - 123, 1);

				if (IsWorkZone(eMenu))
				{
					this->DrawToolTip(PosX + 0.5 - 123 - 5, 25, "Custom Menu S4");
				
					if (this->Data[eMenu].OnClick)
					{
						this->DrawColoredGUI(eMenu, PosX - 123 + 0.5, 1, pMakeColor(40, 20, 3, 130));
						return;
					}
				
					this->DrawColoredGUI(eMenu, PosX - 123 + 0.5, 1, pMakeColor(255, 204, 20, 200));
				}
			}
		
			else
			{
				float PosX = this->GetResizeX(eMenuBG);

				this->DrawGUI(eMenuBG, PosX, 0);

				this->DrawGUI(eMenu, PosX + 0.5, 1);

				if (IsWorkZone(eMenu))
				{
					this->DrawToolTip(PosX + 0.5 - 5, 25, "Custom Menu");
				
					if (this->Data[eMenu].OnClick)
					{
						this->DrawColoredGUI(eMenu, PosX + 0.5, 1, pMakeColor(40, 20, 3, 130));
						return;
					}
				
					this->DrawColoredGUI(eMenu, PosX + 0.5, 1, pMakeColor(255, 204, 20, 200));
				}
			}
		}
	}
}

bool Interface::EventDrawMenu_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu].EventTick);
	// ----
	if (!this->Data[eMenu].OnShow || !IsWorkZone(eMenu))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		pSetCursorFocus = true;
		this->Data[eMenu].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	
	// ----
	this->Data[eMenu].EventTick = GetTickCount();
	
	if (CheckMenuWindow())
	{
		CloseMenuWindow();
	}
	else
	{
		CloseCustomWindow();
		OpenMenuWindow();
		//OpenWindow(27+teste);
		//teste++;
	}
	// ----
	return false;
}

void Interface::DrawMenuOpen()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if( !this->Data[eMenu_MAIN].OnShow )
	{
		return;
	}

	float MainWidth			= 230.0;
	float MainHeight		= 130.0;
	float StartBody			= 40.0;
	float StartY			= 40.0;
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);

	this->DrawGUI(eMenu_MAIN, StartX, StartY + (float)2.0);
	this->DrawGUI(eMenu_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eMenu_FRAME, StartX, StartY + (float)40.0, 14);
	this->DrawGUI(eMenu_FOOTER, StartX, StartY);
	this->DrawGUI(eMenu_CLOSE, StartX + MainWidth - this->Data[eVip_CLOSE].Width, StartBody);
	// ----
	if (this->IsWorkZone(eMenu_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eMenu_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eVip_CLOSE, this->Data[eMenu_CLOSE].X, StartBody, Color);
		this->DrawToolTip((int)this->Data[eMenu_CLOSE].X + 5, StartBody + 25, "Close");
	}

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, "Menu");

	if (gProtect.m_MainInfo.EnableCoinStatus == 1)
	{
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 35, 210, 3, gCustomMessage.GetMessage(50));

		this->DrawFormat(eWhite, (int)StartX + 25, (int)StartBody + 50, 40, 1, gCustomMessage.GetMessage(51));
		this->DrawFormat(eGold, (int)StartX + 50, (int)StartBody + 50, 40, 1, "%d",Coin1);

		this->DrawFormat(eWhite, (int)StartX + 90, (int)StartBody + 50, 40, 1, gCustomMessage.GetMessage(52));
		this->DrawFormat(eGold, (int)StartX + 115, (int)StartBody + 50, 40, 1, "%d",Coin2);

		this->DrawFormat(eWhite, (int)StartX + 153, (int)StartBody + 50, 40, 1, gCustomMessage.GetMessage(53));
		this->DrawFormat(eGold, (int)StartX + 176, (int)StartBody + 50, 40, 1, "%d",Coin3);
	}
	else
	{
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 45, 210, 3, gCustomMessage.GetMessage(54));
	}

	this->DrawGUI(eVip_DIV, StartX, StartBody + 60);

	int BtCount		= 0;
	int BtStart		= StartBody + 78;
	int BtDistance	= 33;

	if (gProtect.m_MainInfo.EnableEventTimeButton == 1)
	{
		BtCount++;
	}

	else
	{	
		BtStart	-= 33;
	}

	if (gProtect.m_MainInfo.EnableVipShopButton == 1)
	{
		BtCount++;
	}

	if (gProtect.m_MainInfo.EnableRankingButton == 1)
	{
		BtCount++;
	}

	if (gProtect.m_MainInfo.EnableCommandButton == 1)
	{
		BtCount++;
	}

	//Jewels Bank
	if (gProtect.m_MainInfo.EnableJewelBankButton == 1)
	{
		BtCount++;
	}

	if (gProtect.m_MainInfo.EnableOptionButton == 1)
	{
		BtCount++;
	}

	if (BtCount == 5)
	{
		BtStart		+= 15;
	}

	if (BtCount == 4)
	{
		BtStart		+= 30;
	}

	if (BtCount == 3)
	{
		BtStart		+= 45;
	}

	if (BtCount == 2)
	{
		BtStart		+= 60;
	}

	if (BtCount == 1)
	{
		BtStart		+= 75;
	}

	//Horario eventos
	if (gProtect.m_MainInfo.EnableEventTimeButton == 1)
	{
	
	if (IsWorkZone(eMenu_OPT1))
	{
		if (this->Data[eMenu_OPT1].OnClick)
			this->DrawButton(eMenu_OPT1, StartX + 64, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT1, StartX + 64, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT1, StartX + 64, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(25));
	}

	//Comprar vip
	if (gProtect.m_MainInfo.EnableVipShopButton == 1)
	{
	
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT2))
	{
		if (this->Data[eMenu_OPT2].OnClick)
			this->DrawButton(eMenu_OPT2, StartX + 64, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT2, StartX + 64, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT2, StartX + 64, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(26));
	}

	//Ranking
	if (gProtect.m_MainInfo.EnableRankingButton == 1)
	{
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT3))
	{
		if (this->Data[eMenu_OPT3].OnClick)
			this->DrawButton(eMenu_OPT3, StartX + 64, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT3, StartX + 64, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT3, StartX + 64, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(27));
	}

	if (gProtect.m_MainInfo.EnableCommandButton == 1)
	{
	//Commandos
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT4))
	{
		if (this->Data[eMenu_OPT4].OnClick)
			this->DrawButton(eMenu_OPT4, StartX + 64, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT4, StartX + 64, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT4, StartX + 64, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(28));
	}

	if (gProtect.m_MainInfo.EnableJewelBankButton == 1)
	{
	//Jewels Bank
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT21))
	{
		if (this->Data[eMenu_OPT21].OnClick)
			this->DrawButton(eMenu_OPT21, StartX + 64, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT21, StartX + 64, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT21, StartX + 64, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(69));
	}

	//Options
	if (gProtect.m_MainInfo.EnableOptionButton == 1)
	{
	//Opções
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT20))
	{
		if (this->Data[eMenu_OPT20].OnClick)
			this->DrawButton(eMenu_OPT20, StartX + 64, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT20, StartX + 64, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT20, StartX + 64, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(44));
	}

}

bool Interface::EventDrawMenu_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_CLOSE].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_CLOSE].EventTick = GetTickCount();
	this->CloseMenuWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op1(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT1].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT1))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT1].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT1].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT1].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gCustomEventTime.OpenWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op2(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT2].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT2))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT2].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT2].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT2].EventTick = GetTickCount();

	this->CloseCustomWindow();

	this->OpenVipWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op3(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT3].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT3))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT3].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT3].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT3].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gCustomRanking.OpenWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op4(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT4].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT4))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT4].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT4].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT4].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gCustomCommandInfo.OpenCommandWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op20(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT20].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT20))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT20].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT20].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT20].EventTick = GetTickCount();

	this->CloseMenuWindow();

//	this->OpenWindow(ObjWindow::Options);
	gInterface.OpenOpMenuAntiLag();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op21(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT21].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT21))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT21].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT21].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT21].EventTick = GetTickCount();

	this->CloseMenuWindow();

	//this->OpenWindow(ObjWindow::Options);
	gJewelBank.OpenJewelWindow();
	// ----
	return false;
}

void Interface::CloseCustomWindow()
{
	this->CloseMenuWindow();
	this->CloseVipWindow();
	this->Data[eRankPANEL_MAIN].OnShow		= false;
	this->Data[eEventTimePANEL_MAIN].OnShow = false;
	this->Data[eCommand_MAIN].OnShow		= false;
	pSetCursorFocus = false;
}

void Interface::DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{
	if (this->CheckWindow(ObjWindow::MoveList) 
		|| this->CheckWindow(ObjWindow::CashShop) 
		|| this->CheckWindow(ObjWindow::SkillTree) 
		|| this->CheckWindow(ObjWindow::FullMap)
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	pSetBlend(true);
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);

	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;

	if (ItemID == 406)
	{
		sub_6358A0_Addr(0.4f, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else if (ItemID == 407)
	{
		sub_6358A0_Addr(0.5, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else
	{
		sub_6358A0_Addr(0.7f, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0); 
	sub_635DE0_Addr();
	sub_635E40_Addr();

	//posX 
	//posY
	//Width
	//Height
	//unk
	// 1 - Excellent Effect
	// 1 - Aura +7
	// 1 - original size
	glClear(0x100);

	//pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);

	 // int v31 = pTest((double)PosY);
	  //int v32 = pTest((double)PosX);

	VAngle v45;

	unsigned __int8 v44 = 1; //0 = parado / 1 = girando

	sub_6359B0_Addr(PosX, PosY, (int)&v45, 0); //posição do bmd
	sub_5CA0D0_Addr(ItemID, Level, Excl, Anc, (int)&v45, v44, 0); //funão que mostra o BMD
	
	sub_636720_Addr();

	glMatrixMode(0x1700);
	glPopMatrix();
	glMatrixMode(0x1701);
	glPopMatrix();

	sub_637770_Addr();

	glColor3f(1,1,1);
	pSetBlend(false);
}

void Interface::DrawConfirmOpen()
{
	if(!this->CheckWindow(Shop) && this->Data[eCONFIRM_MAIN].OnShow == true)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
		pSetCursorFocus = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_OK].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
		pSetCursorFocus = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_CANCEL].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
		pSetCursorFocus = false;
	}

	if( !this->Data[eCONFIRM_MAIN].OnShow )
	{
		return;
	}

	//this->Data[eCONFIRM_MAIN].EventTick = GetTickCount();

	float MainWidth			= 230.0;
	float MainHeight		= 130.0;
	float StartBody			= 90.0;
	float StartY			= 90.0;
	float StartX			= 25;
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);

	gInterface.DrawGUI(eCONFIRM_MAIN, StartX, StartY + (float)2.0);
	gInterface.DrawGUI(eVip_TITLE, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(eVip_FRAME, StartX, StartY + (float)5.0, 5);
	gInterface.DrawGUI(eVip_FOOTER, StartX, StartY);

		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(66));

		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 40, 210, 3, gCustomMessage.GetMessage(67));

		this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, 0);

		if( this->IsWorkZone(eCONFIRM_BTN_OK) )
		{
			int ScaleY = 30;
			// ----
			if( this->Data[eCONFIRM_BTN_OK].OnClick )
			{
				ScaleY = 60;
			}
			// ----
			this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, ScaleY);
		}

		this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, 0);

		if( this->IsWorkZone(eCONFIRM_BTN_CANCEL) )
		{
			int ScaleY = 30;
			// ----
			if( this->Data[eCONFIRM_BTN_CANCEL].OnClick )
			{
				ScaleY = 60;
			}
			// ----
			this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, ScaleY);
		}

}

bool Interface::EventConfirm_OK(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_OK].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_OK))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_OK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].EventTick = GetTickCount();

	PMSG_ITEM_BUY_RECV pMsg;

	pMsg.header.set(0xF3, 0xED,sizeof(pMsg));

	pMsg.slot = this->ConfirmSlot;

	DataSend((BYTE*)&pMsg,pMsg.header.size);

	this->Data[eCONFIRM_MAIN].OnShow = false;
	pSetCursorFocus = false;
	// ----
	return false;
}

bool Interface::EventConfirm_CANCEL(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_CANCEL].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_CANCEL))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_CANCEL].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].EventTick = GetTickCount();

	this->Data[eCONFIRM_MAIN].OnShow = false;
	pSetCursorFocus = false;
	// ----
	return false;
}

void Interface::DrawInterfaceDragonLS3()
{
	//-> Disable Move List
	if(gProtect.m_MainInfo.DisableMoveList == 1)
	{
		if(this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::FullMap) || this->CheckWindow(ObjWindow::ChatWindow) || this->CheckWindow(ObjWindow::SkillTree) /*|| this->CheckWindow(ObjWindow::MoveList)*/)
		{
			return;
		}

		//Time Zone
		int EnableTime = GetPrivateProfileIntA("Other", "ServerTime", 0, ".\\Settings.ini");
		
		if(EnableTime == 0)
		{
			this->DrawGUI(eDragonLeft, this->Data[eDragonLeft].X, this->Data[eDragonLeft].Y);
		}
	}

	else
	{
		if(this->CheckWindow(ObjWindow::CashShop) /*|| this->CheckWindow(ObjWindow::FullMap) || this->CheckWindow(ObjWindow::ChatWindow)*/ || this->CheckWindow(ObjWindow::SkillTree)|| this->CheckWindow(ObjWindow::MoveList))
		{
			return;
		}
		
		//Time Zone
		int EnableTime = GetPrivateProfileIntA("Other", "ServerTime ", 0, ".\\Settings.ini");
		
		if(EnableTime == 0)
		{
			this->DrawGUI(eDragonLeft, this->Data[eDragonLeft].X, this->Data[eDragonLeft].Y);
		}
	}
}

void Interface::DrawInterfaceDragonRS3()
{	
	if (this->CheckWindow(ObjWindow::FriendList) || this->CheckWindow(ObjWindow::Party) || this->CheckWindow(ObjWindow::Quest) || this->CheckWindow(ObjWindow::Guild)
	||  (this->CheckWindow(CommandWindow) || this->CheckWindow(Inventory) || this->CheckWindow(Character) || this->CheckWindow(FastMenu) || this->CheckWindow(SkillTree)
	|| this->CheckWindow(CashShop) /*|| this->CheckWindow(FullMap)*/ || this->CheckWindow(MuHelper)) || pMapNumber == 39 //Kanturu
		|| pMapNumber == 58 //Selupam
		|| pMapNumber == 64 //Duel Arena
		|| pMapNumber == 65 //Doppelganger
		|| pMapNumber == 66 //Doppelganger
		|| pMapNumber == 67 //Doppelganger
		|| pMapNumber == 68 //Doppelganger
		|| pMapNumber == 69 //Imperial Guardian
		|| pMapNumber == 70 //Imperial Guardian
		|| pMapNumber == 71 //Imperial Guardian
		|| pMapNumber == 72 //Imperial Guardian
		|| pMapNumber == 11	//Blood Castle
		|| pMapNumber == 12	//Blood Castle
		|| pMapNumber == 13	//Blood Castle
		|| pMapNumber == 14	//Blood Castle
		|| pMapNumber == 15	//Blood Castle
		|| pMapNumber == 16	//Blood Castle
		|| pMapNumber == 17	//Blood Castle
		|| pMapNumber == 52	//Blood Castle
		|| pMapNumber == 9	//Devil Square
		|| pMapNumber == 32	//Devil Square
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 45	//Illusion Temple
		|| pMapNumber == 46	//Illusion Temple
		|| pMapNumber == 47	//Illusion Temple
		|| pMapNumber == 48	//Illusion Temple
		|| pMapNumber == 49	//Illusion Temple
		|| pMapNumber == 50	//Illusion Temple
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
//		|| pMapNumber == 34 //Crywolf
//		|| pMapNumber == 30 //Valley/CastleSiege
		|| pMapNumber == 65 /*DuelArena*/)
	{
		return;
	}
		this->DrawGUI(eDragonRight, this->Data[eDragonRight].X, this->Data[eDragonRight].Y);
}

void Interface::DrawCoord()
{
	gObjUser.Refresh();

	if (*(DWORD*)MAIN_SCREEN_STATE == 5)
	{
		glColor3f(1.0f, 1.0f, 1.0f);

		//-> Custom Interface (S1/S2)
		if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			pDrawInterfaceNumBer(22, 459, gObjUser.lpViewPlayer->MapPosX, 1);
			pDrawInterfaceNumBer(46, 459, gObjUser.lpViewPlayer->MapPosY, 1);
		}

		//-> Custom Interface (S3)
		if(gProtect.m_MainInfo.CustomInterfaceType == 3)
		{
			pDrawInterfaceNumBer(26, 462, gObjUser.lpViewPlayer->MapPosX, 1);
			pDrawInterfaceNumBer(50, 462, gObjUser.lpViewPlayer->MapPosY, 1);
		}
	}
}

void Interface::DrawInterfaceS3Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}

	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348.5, 450, 0.0, 0.0);
	}

	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}

	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 379.0f, 450, 0.0, 0.0);
	}

	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}

	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409.5, 450, 0.0, 0.0);
	}

	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}

	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 449, 0.0, 0.0);
	}

	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}

	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 582, 432, 0.0, 0.0);
	}

	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}

	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 582, 457, 0.0, 0.0);
	}

	if (IsWorkZone(eFastMenu))
	{
		this->DrawToolTip(13, 420, "System");
	}
	
	if (this->CheckWindow(CommandWindow))
	{
		gInterface.DrawButton(eFastMenu, 5, 433, 0.0, 0.0);
	}
}

void Interface::DrawInterfaceS2Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 449, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 449, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 449, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 449, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 431, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 455, 0.0, 0.0);
	}
	if (IsWorkZone(eFastMenu))
	{
		this->DrawToolTip(13, 420, "System");
	}
	if (this->CheckWindow(CommandWindow))
	{
		gInterface.DrawButton(eFastMenu, 6, 431, 0.0, 0.0);
	}
}

void Interface::DrawInterface97Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 347, 449, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5, 449, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 449, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 449, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 431, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 455, 0.0, 0.0);
	}
}

void Interface::EventNewInterface_All(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}
	
	if (IsWorkZone(eFastMenu))
	{
		DWORD Delay = (CurrentTick - this->Data[eFastMenu].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFastMenu].OnClick = true;
			return;
		}
		this->Data[eFastMenu].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFastMenu].EventTick = GetTickCount();
		if (this->CheckWindow(CommandWindow)) 
		{
				this->CloseWindow(CommandWindow);
		}
		else 
		{
			this->OpenWindow(CommandWindow);
		}
	}
	else if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}
	
	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory)) {
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList)) {
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild)) {
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}

void Interface::EventNewInterface97_All(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}
	
	if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}
	
	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory)) {
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList)) {
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild)) {
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}

void Interface::DrawInterfaceCustom()
{
	gInterface.DrawIMG(eMainEx700, 36, 413, 1.5, 2.0);
	gInterface.DrawGUI(eShop1, 76.5, 452);
	gInterface.DrawGUI(eCharacter1, 98.5, 452);
	gInterface.DrawGUI(eInventory1, 120.5, 452);
	gInterface.DrawGUI(eQuest1, 503.5, 452);
	gInterface.DrawGUI(eCommunity1, 525.5, 452);
	gInterface.DrawGUI(eSystem1, 547.5, 452);

	float v3; // ST58_4@49
	float v4; // ST54_4@49
	float v5; // ST50_4@49
	float v41; // [sp+A8h] [bp-130h]@48
	float RenderFillY; // [sp+B4h] [bp-124h]@48
	float Height; // [sp+1B8h] [bp-20h]@48
	float Widht; // [sp+1BCh] [bp-1Ch]@48
	float HPFill; // [sp+1C8h] [bp-10h]@44
	float MPFill; // [sp+1C8h] [bp-10h]@44
	float RenderX_HP; // [sp+1CCh] [bp-Ch]@48
	float RenderX_MP; // [sp+1CCh] [bp-Ch]@48
	float RenderY_HP; // [sp+1D0h] [bp-8h]@48
	float RenderY_MP; // [sp+1D0h] [bp-8h]@48

	RenderX_HP = 135.0f;//-- x
	RenderY_HP = 414.0f;//-- y
	RenderX_MP = 448.0f;
	RenderY_MP = 415.0f;//-- y
	Widht = 53.0f; //-- W
	Height = 51.0f; //-- H 
	HPFill = 0.0;
	MPFill = 0.0;

	if ((signed int)ViewMaxHP > 0 && (signed int)ViewCurHP > 0 && (double)ViewCurHP / (double)ViewMaxHP < 0.2000000029802322)
		pChatReserveLine(34, 0, 0);
	if ((signed int)ViewMaxHP > 0 )
		HPFill = (double)(ViewMaxHP - ViewCurHP) / (double)ViewMaxHP;
	if ((signed int)ViewMaxMP > 0 )
		MPFill = (double)(ViewMaxMP - ViewCurMP) / (double)ViewMaxMP;
	RenderFillY = HPFill * (float)Widht + (float)RenderY_HP;
	v41 = (float)Widht - HPFill * (float)Widht;

	v3 = (1.0 - HPFill) * Widht / 64.0;
	v4 = Height / 64.0;
	v5 = HPFill * Widht / 64.0;

	if (sub_4C8640((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 55))
	{
		RenderBitmap(31297, RenderX_HP, RenderFillY, Height, v41, 0.0, v5, v4, v3, 1, 1, 0.0);
	}
	
	else
	{
		RenderBitmap(31298, RenderX_HP, RenderFillY, Height, v41, 0.0, v5, v4, v3, 1, 1, 0.0);
	}
	
	RenderFillY = MPFill * (float)Widht + (float)RenderY_MP;
	v41 = (float)Widht - MPFill * (float)Widht;

	v3 = (1.0 - MPFill) * Widht / 64.0;
	v4 = Height / 64.0;
	v5 = MPFill * Widht / 64.0;

	RenderBitmap(31296, RenderX_MP, RenderFillY, Height, v41, 0.0, v5, v4, v3, 1, 1, 0.0);

	gInterface.DrawFormat(eWhite, RenderX_HP + (Widht / 2) - 40 , RenderY_HP + 25, 80, 3, "%d/%d", ViewCurHP, ViewMaxHP);//-- HEALT
	gInterface.DrawFormat(eWhite, RenderX_MP + (Widht / 2) - 40 , RenderY_MP + 24, 80, 3, "%d/%d", ViewCurMP, ViewMaxMP);//-- MANA

	//gInterface.DrawFormat(eWhite, RenderX_HP + (Widht / 2) - 40 , RenderY_HP + 25, 80, 3, "%d", ViewCurHP);//-- HEALT
	//gInterface.DrawFormat(eWhite, RenderX_MP + (Widht / 2) - 40 , RenderY_MP + 24, 80, 3, "%d", ViewCurMP);//-- MANA
	//---
	float CurrentScale; // ST38_4@18
	float CurrentWidth; // [sp+158h] [bp-28h]@18
	DWORD MaxSD; // [sp+168h] [bp-18h]@5
	float SDFill; // [sp+16Ch] [bp-14h]@16
	DWORD CurrentSD; // [sp+17Ch] [bp-4h]@8
	MaxSD = ViewMaxSD;
	CurrentSD = ViewCurSD;

	SDFill = 0.0;
	if  (MaxSD > 0)
		SDFill = (double)(MaxSD - CurrentSD) / (double)MaxSD;

	CurrentWidth = (float)63.0 - SDFill * (float)63.0;
	CurrentScale = ( 1.0 - SDFill ) * 61.0f / 63.0f;

	RenderBitmap(31300, 195.0, 431.0f, CurrentWidth, 8.0f, 0.0, 0.0, CurrentScale, 1.0, 1, 1, 0.0);

	gInterface.DrawFormat(eWhite, 195.0, 431.0f, 63.0, 3, "%d/%d", CurrentSD, MaxSD);

	//gInterface.DrawFormat(eWhite, 195.0, 431.0f, 63.0, 3, "%d", CurrentSD);

	float AGFill; // [sp+15Ch] [bp-24h]@16
	DWORD CurrentAG; // [sp+160h] [bp-20h]@8
	DWORD MaxAG; // [sp+17Ch] [bp-4h]@5
	//float CurrentWidth; // [sp+158h] [bp-28h]@18
	float CurrentX; // [sp+164h] [bp-1Ch]@18
	float CurrentMove; // ST34_4@18
	//float CurrentScale; // ST38_4@18

	MaxAG = ViewMaxBP;
	CurrentAG = ViewCurBP;
	AGFill = 0.0;
	if ( MaxAG > 0 )
		AGFill = (double)(MaxAG - CurrentAG) / (double)MaxAG;

	CurrentX = AGFill * (float) 64.0 + (float) 383.0;
	CurrentWidth = (float) 64.0 - AGFill * (float) 64.0;
	CurrentScale = ( 1.0 - AGFill ) * 61.0f / 64.0f;
	CurrentMove = AGFill * (63.0f) / 64.0f;

	RenderBitmap(31299, CurrentX, 431, CurrentWidth, 8.0f, CurrentMove, 0.0, CurrentScale, 1.0, 1, 1, 0.0);

	gInterface.DrawFormat(eWhite, 383.0, 431, 64.0, 3, "%d/%d", CurrentAG, MaxAG);

	//gInterface.DrawFormat(eWhite, 383.0, 431, 64.0, 3, "%d", CurrentAG);

	//--SD TOOLTIP
	if (pCheckMouseOver((float) 194.0, (float) 431.0, (float) 64.0, (float) 8.0) == 1)
	{
		gInterface.DrawToolTip(194.0, 415.0f, pGetTextLine(pTextThis(),2037), ViewCurSD, ViewMaxSD);
	}
	//-- BP TOOLTIP
	if (pCheckMouseOver((float) 383.0, (float) 431.0, (float) 64.0, (float) 8.0) == 1)
	{
		gInterface.DrawToolTip(383.0, 431 - 16, pGetTextLine(pTextThis(),214), ViewCurBP, ViewMaxBP);
	}
	//-- HP TOOLTIP
	if (pCheckMouseOver((float) 135.0, (float) 414.0, (float) 52.0, (float) 51.0) == 1)
	{
		gInterface.DrawToolTip(135.0f, 400.0, pGetTextLine(pTextThis(),358), ViewCurHP, ViewMaxHP);
	}
	//-- MP TOOLTIP
	if (pCheckMouseOver((float) 448.0, (float) 414.0, (float) 52.0, (float) 51.0) == 1)
	{
		gInterface.DrawToolTip(448, 400, pGetTextLine(pTextThis(),359), ViewCurMP, ViewMaxMP);
	}
}

void Interface::DrawMenuButton()
{
	if (IsWorkZone(eShop2))
	{
		this->DrawToolTip(74, 441, "Game Shop (X)");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop2,   76.5, 452, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter2))
	{
		this->DrawToolTip(96.5, 441, "Character (C)");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter2,  98.5, 452, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory2))
	{
		this->DrawToolTip(103, 441, "Inventory (I,V)");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory2,  120.5, 452, 0.0, 0.0);
	}
	if (IsWorkZone(eQuest2))
	{
		this->DrawToolTip(501, 441, "Quest (T)");
	}
	if (this->CheckWindow(Quest))
	{
		gInterface.DrawButton(eQuest2, 503.5, 452, 0.0, 0.0);
	}
	if (IsWorkZone(eCommunity2))
	{
		this->DrawToolTip(523, 441, "Community (F)");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eCommunity2,   525.5, 452, 0.0, 0.0);
	}
	if (IsWorkZone(eSystem2))
	{
		this->DrawToolTip(545, 441, "System (U)");
	}
	if (this->CheckWindow(FastMenu))
	{
		gInterface.DrawButton(eSystem2,   547.5, 452, 0.0, 0.0);
	}
}

#define	sub_944E50_Addr		((char(*)()) 0x944E50)
#define	sub_93F370_Addr		((void*(*)()) 0x93F370)
#define sub_93FCA0_Addr		((bool(__thiscall*)(int a1)) 0x93FCA0)
#define sub_93F600_Addr		((char(__thiscall*)(char* a1)) 0x93F600)
#define sub_93FD10_Addr		((bool(__thiscall*)(int a1)) 0x93FD10)
#define sub_93F950_Addr		((char(__thiscall*)(char* a1)) 0x93F950)
#define sub_941030_Addr		((int(__thiscall*)(BYTE* a1)) 0x941030)
#define sub_941000_Addr		((int(__thiscall*)(BYTE* a1)) 0x941000)
#define sub_944FE0_Addr		((void(__thiscall*)(BYTE *This, int a2, BYTE *a3)) 0x944FE0)
#define sub_9406C0_Addr		((char(__thiscall*)(BYTE* a1)) 0x9406C0)
#define sub_9406A0_Addr		((BYTE*(__thiscall*)(BYTE* a1, char a2)) 0x9406A0)
#define sub_8611E0_Addr		((int(__thiscall*)(DWORD* a1)) 0x8611E0)
#define sub_815130_Addr		((int(__thiscall*)(char *This, int a2, char a3)) 0x815130)
#define sub_861900_Addr		((int(__thiscall*)(int This)) 0x861900)

struct PMSG_CASH_SHOP_OPEN_RECV
{
	#pragma pack(1)
	PSBMSG_HEAD header; // C1:D2:02
	BYTE OpenType;
	#pragma pack()
};

void OpenCashShopSend(BYTE type)
{
	PMSG_CASH_SHOP_OPEN_RECV pMsg;
	pMsg.OpenType = type;
	pMsg.header.set(0xD2,0x02,sizeof(pMsg));
	DataSend((BYTE*)&pMsg,sizeof(pMsg));
}

bool CashShopSwitchState()
{
	sub_861900_Addr((int)pWindowThis());

	if ( !sub_944E50_Addr() )
		return 0;

	void* v48 = sub_93F370_Addr();

	if ( sub_93FCA0_Addr((int)v48) == 1 )
	{
		if ( !sub_93F600_Addr((CHAR *)sub_93F370_Addr()) )
			return 0;
	}

	if ( sub_93FD10_Addr((int)sub_93F370_Addr()) == 1 )
	{
		if ( sub_93F950_Addr((CHAR *)sub_93F370_Addr()) == 1 )
		{
			BYTE* v53 = (BYTE *)sub_941030_Addr((BYTE*)sub_93F370_Addr());
			int v55 = sub_941000_Addr((BYTE*)sub_93F370_Addr());
			BYTE* v57 = (BYTE *)sub_861900_Addr((int)pWindowThis());
			sub_944FE0_Addr(v57, v55, v53);
		}
	}

	if ( pCheckWindow(pWindowThis(), 65) )
	{
		OpenCashShopSend(1);
		pCloseWindow(pWindowThis(), 65);
	}
	else
	{
		if ( !sub_9406C0_Addr((BYTE*)sub_93F370_Addr()) )
		{
			OpenCashShopSend(0);
			sub_9406A0_Addr((BYTE*)sub_93F370_Addr(), 1);
			char* v62 = (char *)sub_8611E0_Addr((DWORD*)pWindowThis());
			sub_815130_Addr(v62, 0, 1);
		}
	}
}

void Interface::EventMenuButton(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}
	if (IsWorkZone(eShop1))
	{
		DWORD Delay = (CurrentTick - this->Data[eShop1].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eShop1].OnClick = true;
			return;
		}
		this->Data[eShop1].OnClick = false;
		if (Delay < 1000) {
			return;
		}
//		g_Console.AddMessage(5,"Press eSop1");
		this->Data[eShop1].EventTick = GetTickCount();
		CashShopSwitchState();
	}
	else if (IsWorkZone(eCharacter1))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter1].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCharacter1].OnClick = true;
			return;
		}
		this->Data[eCharacter1].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eCharacter1].EventTick = GetTickCount();
		if (this->CheckWindow(Character))
		{
			this->CloseWindow(Character);
		}
		else
		{
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory1))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory1].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eInventory1].OnClick = true;
			return;
		}
		this->Data[eInventory1].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eInventory1].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory))
		{
			this->CloseWindow(Inventory);
		}
		else
		{
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eQuest1))
	{
		DWORD Delay = (CurrentTick - this->Data[eQuest1].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eQuest1].OnClick = true;
			return;
		}
		this->Data[eQuest1].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eQuest1].EventTick = GetTickCount();
		if (this->CheckWindow(Quest))
		{
			this->CloseWindow(Quest);
		}
		else
		{
			this->OpenWindow(Quest);
		}
	}
	else if (IsWorkZone(eCommunity1))
	{
		DWORD Delay = (CurrentTick - this->Data[eCommunity1].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCommunity1].OnClick = true;
			return;
		}
		this->Data[eCommunity1].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eCommunity1].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList))
		{
			this->CloseWindow(FriendList);
		}
		else
		{
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eSystem1))
	{
		DWORD Delay = (CurrentTick - this->Data[eSystem1].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSystem1].OnClick = true;
			return;
		}
		this->Data[eSystem1].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eSystem1].EventTick = GetTickCount();
		if (this->CheckWindow(FastMenu))
		{
			this->CloseWindow(FastMenu);
		}
		else
		{
			this->OpenWindow(FastMenu);
		}
	}
}

//Interfaz Barra Negra
void Interface::guiMonitore()
{
	if (this->CheckWindow(Inventory)
		|| this->CheckWindow(CashShop)
		|| this->CheckWindow(ChaosBox)
		|| this->CheckWindow(Character)
		|| this->CheckWindow(CommandWindow)
		|| this->CheckWindow(ExpandInventory) 
		|| this->CheckWindow(ExpandWarehouse)
		|| this->CheckWindow(FullMap)
		|| this->CheckWindow(GensInfo)
		|| this->CheckWindow(Guild) ||
		this->CheckWindow(NPC_Dialog) ||
		this->CheckWindow(NPC_Julia) ||
		this->CheckWindow(NPC_Titus) ||
		this->CheckWindow(OtherStore) ||
		this->CheckWindow(Party) ||
		this->CheckWindow(PetInfo) ||
		this->CheckWindow(Shop) ||
		this->CheckWindow(SkillTree) ||
		this->CheckWindow(Store) ||
		this->CheckWindow(Trade) ||
		this->CheckWindow(FriendList) ||
		//this->CheckWindow(FastMenu) ||
		this->CheckWindow(MuHelper) ||
		this->CheckWindow(Quest) ||
		this->CheckWindow(Lugard) ||
		this->CheckWindow(Jerint) ||
		this->CheckWindow(GoldenArcher1) ||
		this->CheckWindow(GoldenArcher2) ||
		this->CheckWindow(LuckyCoin1) ||
		this->CheckWindow(LuckyCoin2) ||
		this->CheckWindow(NPC_Duel) ||
		this->CheckWindow(NPC_Devin) ||
		this->CheckWindow(GuardNPC) ||
		this->CheckWindow(SeniorNPC) ||
		this->CheckWindow(GuardNPC2) ||
		this->CheckWindow(CastleGateSwitch) ||
		this->CheckWindow(CatapultNPC) ||
		this->CheckWindow(CreateGuild) ||
		this->CheckWindow(Warehouse) ||
		this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store) ||
		this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse) ||
		this->CheckWindow(Inventory) && this->CheckWindow(Character) && this->CheckWindow(Store) ||
		this->CheckWindow(BloodCastle) ||
		this->CheckWindow(DevilSquare))
	{
		return;
	}

	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(545.0, 0.0, 150.0, 11.0, 0.0f, 0);
	pGLSwitchBlend();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}

//FPS
void Interface::UPDATE_FPS()
{
	gInterface.frameCount++;

	if (GetTickCount() - gInterface.lastReport >= 1000)
	{
		gInterface.frameRate = gInterface.frameCount / ((GetTickCount() - gInterface.lastReport) / 1000);
		sprintf(gInterface.FPS_REAL, "FPS: %d", gInterface.frameRate);
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}

	if (this->CheckWindow(Inventory) ||
		this->CheckWindow(CashShop) ||
		this->CheckWindow(ChaosBox) ||
		this->CheckWindow(Character) ||
		this->CheckWindow(CommandWindow) ||
		this->CheckWindow(ExpandInventory) ||
		this->CheckWindow(ExpandWarehouse) ||
		this->CheckWindow(FullMap) ||
		this->CheckWindow(GensInfo) ||
		this->CheckWindow(Guild) ||
		this->CheckWindow(NPC_Dialog) ||
		this->CheckWindow(NPC_Julia) ||
		this->CheckWindow(NPC_Titus) ||
		this->CheckWindow(OtherStore) ||
		this->CheckWindow(Party) ||
		this->CheckWindow(PetInfo) ||
		this->CheckWindow(Shop) ||
		this->CheckWindow(SkillTree) ||
		this->CheckWindow(Store) ||
		this->CheckWindow(Trade) ||
		this->CheckWindow(FriendList) ||
		//this->CheckWindow(FastMenu) ||
		this->CheckWindow(MuHelper) ||
		this->CheckWindow(Quest) ||
		this->CheckWindow(Lugard) ||
		this->CheckWindow(Jerint) ||
		this->CheckWindow(GoldenArcher1) ||
		this->CheckWindow(GoldenArcher2) ||
		this->CheckWindow(LuckyCoin1) ||
		this->CheckWindow(LuckyCoin2) ||
		this->CheckWindow(NPC_Duel) ||
		this->CheckWindow(NPC_Devin) ||
		this->CheckWindow(GuardNPC) ||
		this->CheckWindow(SeniorNPC) ||
		this->CheckWindow(GuardNPC2) ||
		this->CheckWindow(CastleGateSwitch) ||
		this->CheckWindow(CatapultNPC) ||
		this->CheckWindow(CreateGuild) ||
		this->CheckWindow(Warehouse) ||
		this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store) ||
		this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse) ||
		this->CheckWindow(Inventory) && this->CheckWindow(Character) && this->CheckWindow(Store) ||
		this->CheckWindow(BloodCastle) ||
		this->CheckWindow(DevilSquare))
	{
		return;
	}
	this->DrawFormat(eGold, 605, 2, 80, 1, gInterface.FPS_REAL);
}

//Ping recibido desde protocol, respuesta del gameserver
void Interface::DrawPing()
{
	gInterface.msPing = GetTickCount() - gInterface.lastSend;
	gInterface.iniciador = 3;
}

//Ping
void Interface::SendPingRecv()
{
	if(gInterface.iniciador == 1)
	{
		PMSG_PING pMsgPing;
		pMsgPing.h.set(0xFF,sizeof(pMsgPing));
		gInterface.lastSend = GetTickCount();
		DataSend((BYTE*)&pMsgPing,sizeof(pMsgPing));
		gInterface.iniciador=2;
	}
	
	else if(gInterface.iniciador == 3)
	{
		if (GetTickCount() >= gInterface.lastSend + 1000)
		{
			PMSG_PING pMsgPing;
			pMsgPing.h.set(0xFF,sizeof(pMsgPing));
			gInterface.lastSend = GetTickCount();
			DataSend((BYTE*)&pMsgPing,sizeof(pMsgPing));
			gInterface.iniciador=2;
		}
	}

	if (this->CheckWindow(Inventory) ||
		this->CheckWindow(CashShop) ||
		this->CheckWindow(ChaosBox) ||
		this->CheckWindow(Character) ||
		this->CheckWindow(CommandWindow) ||
		this->CheckWindow(ExpandInventory) ||
		this->CheckWindow(ExpandWarehouse) ||
		this->CheckWindow(FullMap) ||
		this->CheckWindow(GensInfo) ||
		this->CheckWindow(Guild) ||
		this->CheckWindow(NPC_Dialog) ||
		this->CheckWindow(NPC_Julia) ||
		this->CheckWindow(NPC_Titus) ||
		this->CheckWindow(OtherStore) ||
		this->CheckWindow(Party) ||
		this->CheckWindow(PetInfo) ||
		this->CheckWindow(Shop) ||
		this->CheckWindow(SkillTree) ||
		this->CheckWindow(Store) ||
		this->CheckWindow(Trade) ||
		this->CheckWindow(FriendList) ||
		//this->CheckWindow(FastMenu) ||
		this->CheckWindow(MuHelper) ||
		this->CheckWindow(Quest) ||
		this->CheckWindow(Lugard) ||
		this->CheckWindow(Jerint) ||
		this->CheckWindow(GoldenArcher1) ||
		this->CheckWindow(GoldenArcher2) ||
		this->CheckWindow(LuckyCoin1) ||
		this->CheckWindow(LuckyCoin2) ||
		this->CheckWindow(NPC_Duel) ||
		this->CheckWindow(NPC_Devin) ||
		this->CheckWindow(GuardNPC) ||
		this->CheckWindow(SeniorNPC) ||
		this->CheckWindow(GuardNPC2) ||
		this->CheckWindow(CastleGateSwitch) ||
		this->CheckWindow(CatapultNPC) ||
		this->CheckWindow(CreateGuild) ||
		this->CheckWindow(Warehouse) ||
		this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store) ||
		this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse) ||
		this->CheckWindow(Inventory) && this->CheckWindow(Character) && this->CheckWindow(Store) ||
		this->CheckWindow(BloodCastle) ||
		this->CheckWindow(DevilSquare))
	{
		return;
	}

	sprintf(gInterface.ServerPing, "PING: %d ms", gInterface.msPing/2);

	gInterface.validar=0;
	
	if(gInterface.msPing>0)
	{
		this->DrawFormat(eGold, 555, 2, 100, 1, gInterface.ServerPing);
		sprintf(gInterface.ultimoping,gInterface.ServerPing);
		gInterface.ultimo_ping = gInterface.msPing;
		gInterface.validar=1;
	}
	
	if(gInterface.validar==0)
	{
		if(gInterface.ultimo_ping > 0)
		{
			this->DrawFormat(eGold, 555, 2, 100, 1, gInterface.ultimoping);
		}
		
		else
		{
			this->DrawFormat(eGold, 555, 2, 100, 1, gInterface.ServerPing);
		}
	}
}

void testfunc()
{
	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();
}

#define sub_636720_Addr ((int(*)())0x636720)
#define sub_6363D0_Addr ((void(__cdecl*)(GLint x, int a2, GLsizei width, GLsizei height)) 0x6363D0)
#define sub_6358A0_Addr ((int(__cdecl*)(float a1, float a2, float a3, float a4)) 0x6358A0)
#define sub_635830_Addr ((void(__cdecl*)(LPVOID a1)) 0x635830)
#define sub_635DE0_Addr ((void(*)()) 0x635DE0)
#define sub_635E40_Addr ((void(*)()) 0x635E40)
#define sub_637770_Addr ((void(*)()) 0x637770)

void Interface::DrawItemIMG(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse) // code hien thi item
{

	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	//float X = ull_to_float2(*(QWORD*)0xE61E58);
	//float Y = ull_to_float2(*(QWORD*)0xE61E58+1);

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);
	//float v2 = (X / (Y / 100.0f)) / 100.0f;//(*(float*)MAIN_RESOLUTION_X / (*(float*)MAIN_RESOLUTION_Y / 100.0f)) / 100.0f;
	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;
	sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();

	//posX
	//posY
	//Width
	//Height
	//unk
	// 1 - Excellent Effect
	// 1 - Aura +7
	// 1 - original size
	//glClear(0x100u);
	pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);

	testfunc();
	//sub_637770_Addr();

	glColor3f(1, 1, 1);
	pSetBlend(false);
}
/*
void Interface::Work2() {


			if (gInterface.item_post_ && pCursorX < 150)
			{
				glColor4f(0.0, 0.0, 0.0, 0.8);
				pDrawBarForm((float)(+300), (float)(+150), 80.0f, 110.0f, 0.0f, 0); //pCursorY->Len Xuong // pCursorX->Trai Phai
				DrawItemIMG(+340.0f, +210.0f, gObjUser.PostItemX, gObjUser.PostItemY, gObjUser.PostItemID, gObjUser.PostItemLV, gObjUser.PostItemExc, 0, 0);


				gInterface.DrawItemToolTipText(gInterface.item_post_, pCursorX + 80, pCursorY - 80);
				if (gInterface.last_tickcount_view_ + 100 < GetTickCount())
				{
					gInterface.item_post_ = nullptr;
				}
			}

   pDrawInterface2();
}*/

void Interface::DrawChat ( int mode, char* character, char* message ) {
    PBMSG_CHATPOSTITEM chat;
    memset ( &chat.character_[0], 0, 10 );
    memset ( &chat.message_[0], 0, 89 );
    memcpy ( &chat.character_[0], &character[0], 10 );
    memcpy ( &chat.message_[0], &message[0], strlen ( message ) );
    pHandlePacketChatData ( &chat );

	if (mode >= 1 && mode <= 9 && ChatBoxMuObjectChatDataPtrArrayLength) {
		int index = ChatBoxMuObjectChatDataPtrArrayLength - 1;
		ChatBoxMuObjectChatDataPtrArray[index]->chat_type_ = mode;
	}
}

void Interface::DrawItemToolTipText ( void * item, int x, int y ) {
		static DWORD mem = 0;
		//static DWORD ItemToolTipAdress1 = 0x00861110; //1.04D-> 0x00860FC0
		//static DWORD ItemToolTipAdress2 = 0x00861AA0; //1.04D-> 0x00861950
		//static DWORD ItemToolTipAdress3 = 0x007E3E30; //1.04D-> 0x007E3CE0
		_asm {
		    PUSH 0
		    PUSH 0
		    PUSH 0
		    PUSH item
		    PUSH y
		    PUSH x
			MOV mem,0x00861110
		    CALL mem
		    MOV ECX, EAX
			MOV mem,0x00861AA0
		    CALL mem
		    MOV ECX, EAX
			MOV mem,0x007E3E30
		    CALL mem
		}
}

//========================================================================================================================================
// Advanced Stats
//========================================================================================================================================
void Interface::DrawBarForm(float PosX, float PosY, float Width, float Height, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	pSetBlend(1);
	glColor4f(red, green, blue, alpha);
	pDrawBarForm(PosX, PosY, Width, Height, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
}
// ----------------------------------------------------------------------------------------------

bool Interface::CheckWindowEx(int WindowID)
{
	if (WindowID < 0 || WindowID > MAX_WINDOW_EX)
	{
		return 0;
	}
	return this->WindowEx[WindowID];
}

void Interface::DrawWindow(int ObjMain, int ObjTitle, int ObjFrame, int ObjFooter, int Repeat, float X, float Y, char* Text)
{
	float StartY = Y;
	float StartX = X;

	gInterface.DrawGUI(ObjMain, StartX, StartY + 2);
	gInterface.DrawGUI(ObjTitle, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(ObjFrame, StartX, StartY + 40.0, Repeat);
	gInterface.DrawGUI(ObjFooter, StartX, StartY);
	gInterface.DrawFormat(eGold, StartX + 10, Y + 10, 210, 3, Text);
}

void Interface::DrawItemIMGBank(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse) // code hien thi item
{
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);
	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;
	sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();

	pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);

	testfunc();
	glColor3f(1, 1, 1);
	pSetBlend(false);
}

//-> Custom Blood Castle Window
void Interface::DrawInterfaceBloodCastle()
{
	float MainWidth=230.0;
	float MainHeight=313.0;
	float StartY=20.0;
	float StartX=(MAX_WIN_WIDTH/2)-(MainWidth/2);
	
	//--
	if (this->CheckWindow(BloodCastle))
	{
		pDrawImage(2338, 450.0, 0.0, 280.0, 540.0, 0, 0, 0.84375, 0.703125, 1, 1, 0.0); //-> Janela do BC
		//--
		this->DrawFormat(eGold,StartX+274,StartY+29,+150,1,"Arrisque sua vida para salvar o Arcanjo!");
		//--
		this->DrawFormat(eWhite240,StartX+272,StartY+43,+150,1,"Um dos guerreiros mais fortes do continente");
		this->DrawFormat(eWhite240,StartX+272,StartY+54,+150,1,"agora precisa de sua ajuda. Derrote as forças");
		this->DrawFormat(eWhite240,StartX+272,StartY+65,+150,1,"do mal, destrua o portão do castelo, quebre");
		this->DrawFormat(eWhite240,StartX+272,StartY+76,+150,1,"a estátua de cristal e salve o Arcanjo para ");
		this->DrawFormat(eWhite240,StartX+272,StartY+87,+150,1,"receber uma recompensa muito valiosa.");
		//--
		this->DrawFormat(eGold,StartX+279,StartY+119,+150,1,"Recompensas ao completar esta missão");
		//--
		this->DrawFormat(eDivine,StartX+287,StartY+140,+150,1,"Divine Sword of Archangel");
		this->DrawFormat(eDivine,StartX+287,StartY+155,+150,1,"Divine Short Sword of Archangel");
		this->DrawFormat(eDivine,StartX+287,StartY+170,+150,1,"Divine Mace of Archangel");
		this->DrawFormat(eDivine,StartX+287,StartY+185,+150,1,"Divine Scepter of Archangel");
		this->DrawFormat(eDivine,StartX+287,StartY+200,+150,1,"Divine Lance of Archangel");
		this->DrawFormat(eDivine,StartX+287,StartY+215,+150,1,"Divine Crossbow of Archangel");
		this->DrawFormat(eDivine,StartX+287,StartY+230,+150,1,"Divine Staff of Archangel");
		this->DrawFormat(eDivine,StartX+287,StartY+245,+150,1,"Divine Stick of Archangel");
		//--
		this->DrawFormat(eDivine,StartX+287,StartY+260,+150,1,"Bundled Jewel of Bless");
		this->DrawFormat(eDivine,StartX+287,StartY+275,+150,1,"Bundled Jewel of Soul");
		this->DrawFormat(eDivine,StartX+287,StartY+290,+150,1,"Bundled Jewel of Life");
		//--
		this->DrawFormat(eDivine,StartX+287,StartY+305,+150,1,"Steel of Heaven");
		//--
		this->DrawFormat(eWhite240,StartX+307,StartY+345,+150,1,"Entrar no Blood Castle");
	}
}

//-> Anti Lag System
void Interface::DrawOpAntiLag()
{
	if( !this->Data[eOpMenu_MAINKG].OnShow )
	{
		return;
	}

	if (this->CheckWindow(ObjWindow::MoveList) 
		|| this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::FullMap) 
		|| this->CheckWindow(ObjWindow::CashShop) 
		|| this->CheckWindow(ObjWindow::MuHelper) 
		||  (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		||  (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		CloseMenuWindow();
		return;
	}

	float MainWidth, MainHeight;
    MainWidth		= 230.0;
	MainHeight		= 130.0;
	float StartBody	= 40.0;
	float StartY	= 40.0;
	float StartX	= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter	= StartX + (MainWidth / 3);
	float ButtonX		= MainCenter - (float)(29.0 / 2);

	//Custom Interface Type (S8)
	if(gProtect.m_MainInfo.CustomInterfaceType == 4 || gProtect.m_MainInfo.CustomInterfaceType == 5 || gProtect.m_MainInfo.CustomInterfaceType == 6)
	{
		this->DrawGUI(eOpMenu_MAINKG, StartX, StartY + (float)2.0);
		this->DrawGUI(eOpMenu_TITLEKG, StartX, StartY);
		this->DrawFormat(eGold, (int)StartX + 9, (int)StartBody + 13, 210, 3, "Advanced Options");
		StartY = this->DrawRepeatGUI(eOpMenu_FRAMEKG, StartX, StartY + (float)40.0, 14);
		this->DrawGUI(eOpMenu_FOOTERKG, StartX, StartY);
		this->DrawGUI(eOpMenu_CLOSEKG, StartX + MainWidth - this->Data[eVip_CLOSE].Width, StartBody);
	}

	else
	{
		this->DrawGUI(eOpMenu_MAINKG, StartX, StartY + (float)2.0);
		this->DrawGUI(eOpMenu_TITLEKG, StartX, StartY);
		this->DrawFormat(eGold, (int)StartX + 9, (int)StartBody + 10, 210, 3, "Advanced Options");
		StartY = this->DrawRepeatGUI(eOpMenu_FRAMEKG, StartX, StartY + (float)40.0, 14);
		this->DrawGUI(eOpMenu_FOOTERKG, StartX, StartY);
		this->DrawGUI(eOpMenu_CLOSEKG, StartX + MainWidth - this->Data[eVip_CLOSE].Width, StartBody);
	}

	if (this->IsWorkZone(eOpMenu_CLOSEKG))
	{
	    DWORD Color = eGray100;

		if (this->Data[eOpMenu_CLOSEKG].OnClick)
		{
		    Color = eGray150;
		}

		this->DrawColoredGUI(eOpMenu_CLOSEKG, this->Data[eOpMenu_CLOSEKG].X, StartBody, Color);
		this->DrawToolTip((int)this->Data[eOpMenu_CLOSEKG].X + 5, StartBody + 25, "Close");
	}

	float opLine, opStart, opSO, opTxt;
    opSO    = ButtonX + 110;
	opStart = StartX + 35;
	opLine  = StartX + 35;
	opTxt   = StartX + 50;

	// ---- Inicio Glow
		this->DrawGUI(eUSERSPANEL_GLOW, opSO, this->Data[eOpMenu_MAINKG].Y + 42);
	    this->DrawGUI(eUSERSPANEL_OPTION, opStart, this->Data[eOpMenu_MAINKG].Y + 43);
	    this->DrawGUI(eUSERSPANEL_LINE, opLine, this->Data[eOpMenu_MAINKG].Y + 60);
		this->DrawFormat(eYellow, opTxt, this->Data[eOpMenu_MAINKG].Y + 45, + 125, 1, "Disable Glow Effect");
		
		{
			if (DisableGlowEffect==1)
			{
			
			}
			
			else
			{
				this->DrawGUI(eUnCheck, opSO, this->Data[eOpMenu_MAINKG].Y + 42);
			}
		}
	// ---- Fim Glow

	// ---- Inicio Dynamic
		this->DrawGUI(eUSERSPANEL_MINIMAP, opSO, this->Data[eOpMenu_MAINKG].Y + 72);
	    this->DrawGUI(eUSERSPANEL_OPTION, opStart, this->Data[eOpMenu_MAINKG].Y + 73);
	    this->DrawGUI(eUSERSPANEL_LINE, opLine, this->Data[eOpMenu_MAINKG].Y + 90);
		this->DrawFormat(eYellow, opTxt, this->Data[eOpMenu_MAINKG].Y + 75, + 125, 1, "Disable Dynamic Effect");
	{
	   if (testFunctionInvItem3==1)
		{
	    }
	    else
		{
		        this->DrawGUI(eUnCheck, opSO, this->Data[eOpMenu_MAINKG].Y + 72);
	   }
	}
	// ---- Fim Dynamic


    // ---- Inicio static
		this->DrawGUI(eUSERSPANEL_FPS, opSO, this->Data[eOpMenu_MAINKG].Y + 102);
	    this->DrawGUI(eUSERSPANEL_OPTION, opStart, this->Data[eOpMenu_MAINKG].Y + 103);
	    this->DrawGUI(eUSERSPANEL_LINE, opLine, this->Data[eOpMenu_MAINKG].Y + 120);
		this->DrawFormat(eYellow, opTxt, this->Data[eOpMenu_MAINKG].Y + 105, + 125, 1, "Disable Static Effect");
	{
	        if (testFunctionInvItem4==1)
			{
	        }
	        else
			{
		        this->DrawGUI(eUnCheck, opSO, this->Data[eOpMenu_MAINKG].Y + 102);
	        }
	}
	// ---- Fim Static

    // ---- Inicio Remove Wings
		this->DrawGUI(eUSERSPANEL_INVIS1, opSO, this->Data[eOpMenu_MAINKG].Y + 132);
	    this->DrawGUI(eUSERSPANEL_OPTION, opStart, this->Data[eOpMenu_MAINKG].Y + 133);
	    this->DrawGUI(eUSERSPANEL_LINE, opLine, this->Data[eOpMenu_MAINKG].Y + 150);
		this->DrawFormat(eYellow, opTxt, this->Data[eOpMenu_MAINKG].Y + 135, + 125, 1, "Disable Wings and Cloaks");
	{
	        if (testFunctionInvItem5==1)
			{
	        }
	        else
			{
		        this->DrawGUI(eUnCheck, opSO, this->Data[eOpMenu_MAINKG].Y + 132);
	        }
	}
	 // ---- Fim Remove Wings

	    // ---- Inicio Remove Weapons
	    this->DrawGUI(eUSERSPANEL_INVIS2, opSO, this->Data[eOpMenu_MAINKG].Y + 162);
	    this->DrawGUI(eUSERSPANEL_OPTION, opStart, this->Data[eOpMenu_MAINKG].Y + 163);
	    this->DrawGUI(eUSERSPANEL_LINE, opLine, this->Data[eOpMenu_MAINKG].Y + 180);
	    this->DrawFormat(eYellow, opTxt, this->Data[eOpMenu_MAINKG].Y + 165, + 125, 1, "Disable Weapons and Shields");
	    {
	        if (testFunctionInvItem6==1)
			{
	        }
	        else
			{
		        this->DrawGUI(eUnCheck, opSO, this->Data[eOpMenu_MAINKG].Y + 162);
	        }
	    }
		 // ---- Fim Remove Weapons

	    // ---- Inicio Invisible Item
	    this->DrawGUI(eUSERSPANEL_DRAGON, opSO, this->Data[eOpMenu_MAINKG].Y + 192);
	    this->DrawGUI(eUSERSPANEL_OPTION, opStart, this->Data[eOpMenu_MAINKG].Y + 193);
	    this->DrawGUI(eUSERSPANEL_LINE, opLine, this->Data[eOpMenu_MAINKG].Y + 210);
	    this->DrawFormat(eYellow, opTxt, this->Data[eOpMenu_MAINKG].Y + 195, + 125, 1, "Invisible Character Models");
	    {
	        if (testFunctionInvItem==1)
			{
	        }
	        else
			{
		        this->DrawGUI(eUnCheck, opSO, this->Data[eOpMenu_MAINKG].Y + 192);
	        }
	    }
	    // ---- Fim Invisible Item

	    // ---- Inicio RemoveObjects
	    this->DrawGUI(eUSERSPANEL_INVIS4, opSO, this->Data[eOpMenu_MAINKG].Y + 222);
	    this->DrawGUI(eUSERSPANEL_OPTION, opStart, this->Data[eOpMenu_MAINKG].Y + 223);
	    this->DrawGUI(eUSERSPANEL_LINE, opLine, this->Data[eOpMenu_MAINKG].Y + 240);
	    this->DrawFormat(eYellow, opTxt, this->Data[eOpMenu_MAINKG].Y + 225, + 125, 1, "Disable Objects");
	    {
	        if (testFunctionInvItem8==1)
			{
	        }
	        else
			{
		        this->DrawGUI(eUnCheck, opSO, this->Data[eOpMenu_MAINKG].Y + 222);
	        }
	    }
	    // ---- Fin RemoveObjects	
		 
	// ---- Inicio Disable +15 Effect
	if(gProtect.m_MainInfo.DisableSet15Effect == 0)
	{
	    this->DrawGUI(eUSERSPANEL_INVIS3, opSO, this->Data[eOpMenu_MAINKG].Y + 252);
	    this->DrawGUI(eUSERSPANEL_OPTION, opStart, this->Data[eOpMenu_MAINKG].Y + 253);
	    this->DrawGUI(eUSERSPANEL_LINE, opLine, this->Data[eOpMenu_MAINKG].Y + 270);
	    this->DrawFormat(eYellow, opTxt, this->Data[eOpMenu_MAINKG].Y + 255, + 125, 1, "Disable +15 Effect");
	    {
	        if (testFunctionInvItem7==1)
			{
	        }
	        else
			{
		        this->DrawGUI(eUnCheck, opSO, this->Data[eOpMenu_MAINKG].Y + 252);
	        }
	    }
	}
	// ---- Fim Disable +15 Effect
}

__declspec(naked) void EJCGetPartGlowObject_1()
{
	static DWORD JCItemID;
	static DWORD JCThis;
	static DWORD JCModel;
	static DWORD JCStructEffect;
	static DWORD main_addr;
	static DWORD JCANALYZER_ITEM;


	_asm
	{
		//--
		MOV EAX, DWORD PTR SS:[EBP+0x10]
		MOV JCItemID, EAX
		//--
		MOV EDX,DWORD PTR SS:[EBP+0x8]
		MOV JCThis, EDX
		//--
		MOV EAX,DWORD PTR SS:[EBP+0x18]
		MOV JCModel, EAX
		//--
		MOV ECX,DWORD PTR SS:[EBP+0xC]
		MOV JCStructEffect, ECX
	}


	if ( JCItemID == 0x14CF )
	{
		main_addr = 0x00608CB5;
	}
	else if( JCItemID >= 1171 )
	{
		main_addr = 0x00608F8F;
	}
	else
	{
		main_addr = 0x00608CFC;
	}
	_asm
	{
		JMP[ main_addr ]
	}
}

__declspec(naked) void EJCGetPartBrightnessObject_2()
{
	static DWORD JCItemID;
	static DWORD JCThis;
	static DWORD JCModel;
	static DWORD JCStructEffect;
	static DWORD main_addr;
	static DWORD JCANALYZER_ITEM;


	_asm
	{
		//--
		MOV EAX, DWORD PTR SS:[EBP+0x10]
		MOV JCItemID, EAX
		//--
		MOV EDX,DWORD PTR SS:[EBP+0x8]
		MOV JCThis, EDX
		//--
		MOV EAX,DWORD PTR SS:[EBP+0x18]
		MOV JCModel, EAX
		//--
		MOV ECX,DWORD PTR SS:[EBP+0xC]
		MOV JCStructEffect, ECX
	}
	
	if ( JCItemID == 0x14CF )
	{
		main_addr = 0x00609556;
	}
	else if( JCItemID >= 1171)
	{
		main_addr = 0x006097AC;
	}
	else
	{
		main_addr = 0x0060959D;
	}


	_asm
	{
		JMP[ main_addr ]
	}
}


__declspec(naked) void EJCGetPartOptionObject_3()
{
	static DWORD JCItemID;
	static DWORD JCThis;
	static DWORD JCModel;
	static DWORD JCStructEffect;
	static DWORD main_addr;
	static DWORD JCANALYZER_ITEM;


	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 0xC]
		MOV JCItemID,EDX
		//--
		MOV ECX,DWORD PTR SS:[EBP - 0x8]
		MOV JCThis,ECX
		//--
		MOV ECX,DWORD PTR SS:[EBP + 0x14]
		MOV JCModel,ECX
		//--
		MOV EAX,DWORD PTR SS:[EBP + 0x8]
		MOV JCStructEffect,EAX
	}
	
	if ( JCItemID == 0x12E6 )
	{
		main_addr = 0x0060F055;
	}
	else if( JCItemID >= 1171 )
	{
		main_addr = 0x0060F320;
	}
	else
	{
		main_addr = 0x0060F094;
	}


	_asm
	{
		JMP[ main_addr ]
	}
}

bool Interface::EventUsersPanelAntiLag(DWORD Event)
{
	this->EventUsersPanelAntiLag_GLOW(Event);
	this->EventUsersPanelAntiLag_EFFECTDYNAMIC(Event);
	this->EventUsersPanelAntiLag_TRANSPARENCE(Event);
	this->EventUsersPanelAntiLag_EFFECTSTATIC(Event);
	this->EventUsersPanelAntiLag_INVISIBLY(Event);
	this->EventUsersPanelAntiLag_INVISIBLYWINGS(Event);
	this->EventUsersPanelAntiLag_INVISIBLYWEAPONS(Event);
	this->EventUsersPanelAntiLag_EFFECT15(Event);
	this->EventUsersPanelAntiLag_OBJECTS(Event);
	this->EventUsersPanelAntiLag_CLOSE(Event);
	return true;
}

bool Interface::EventUsersPanelAntiLag_GLOW(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eUSERSPANEL_GLOW].EventTick);
	// ----
	if( !this->Data[eOpMenu_MAINKG].OnShow || !IsWorkZone(eUSERSPANEL_GLOW) )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eUSERSPANEL_GLOW].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	this->Data[eUSERSPANEL_GLOW].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if( Delay < 500 )
	{
		return false;
	}
	// ----
	this->Data[eUSERSPANEL_GLOW].EventTick = GetTickCount();
	if (DisableGlowEffect!=0)
	{
		DisableGlowEffect = 0;
		SetRange((LPVOID)0x0060F04C, 7, 0x90);
		SetRange((LPVOID)0x0060954D, 7, 0x90);
		SetRange((LPVOID)0x00608CAC, 7, 0x90);
	}
    else
	{
		DisableGlowEffect = 1;
		SetOp((LPVOID)0x00608CAC,(LPVOID)EJCGetPartGlowObject_1,0xE9);
		SetOp((LPVOID)0x0060954D,(LPVOID)EJCGetPartBrightnessObject_2,0xE9);
		SetOp((LPVOID)0x0060F04C,(LPVOID)EJCGetPartOptionObject_3,0xE9);
	}
}

bool Interface::EventUsersPanelAntiLag_TRANSPARENCE(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eUSERSPANEL_DRAGON].EventTick);
	// ----
	if( !this->Data[eOpMenu_MAINKG].OnShow || !IsWorkZone(eUSERSPANEL_DRAGON) )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eUSERSPANEL_DRAGON].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	this->Data[eUSERSPANEL_DRAGON].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if( Delay < 500 )
	{
		return false;
	}
	// ----
	this->Data[eUSERSPANEL_DRAGON].EventTick = GetTickCount();
	if (testFunctionInvItem!=0)
	{
		testFunctionInvItem = 0;
        InvisibleItem2();
		InvisibleItemX();
	}
    else
	{
		InvisibleItem1();
		testFunctionInvItem = 1;
	}
}

bool Interface::EventUsersPanelAntiLag_INVISIBLY(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eUSERSPANEL_TIME].EventTick);
	// ----
	if( !this->Data[eOpMenu_MAINKG].OnShow || !IsWorkZone(eUSERSPANEL_TIME) )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eUSERSPANEL_TIME].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	this->Data[eUSERSPANEL_TIME].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if( Delay < 500 )
	{
		return false;
	}
	// ----
	this->Data[eUSERSPANEL_TIME].EventTick = GetTickCount();
	if (testFunctionInvItem2!=0)
	{
		testFunctionInvItem2 = 0;
		DelectlpViewPlayerOff_Hook();
	}
    else
	{
        DelectlpViewPlayerOn_Hook();
		testFunctionInvItem2 = 1;
	}
}

bool Interface::EventUsersPanelAntiLag_EFFECTDYNAMIC(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eUSERSPANEL_MINIMAP].EventTick);
	// ----
	if( !this->Data[eOpMenu_MAINKG].OnShow || !IsWorkZone(eUSERSPANEL_MINIMAP) )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eUSERSPANEL_MINIMAP].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	this->Data[eUSERSPANEL_MINIMAP].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if( Delay < 500 )
	{
		return false;
	}
	// ----
	this->Data[eUSERSPANEL_MINIMAP].EventTick = GetTickCount();
	if (testFunctionInvItem3!=0)
	{
		testFunctionInvItem3 = 0;
		DelectEffectDynamicOff_Hook();

		
		DelectEffectSkillOff_Hook();

		SetByte(0x00608FB0, 0x55); //Enable Skill Effects
	}
    else
	{
		SetByte(0x00608FB0, 0xC3); //Disable Skill Effects

        DelectEffectDynamicOn_Hook();

		
        DelectEffectSkillOn_Hook();

		testFunctionInvItem3 = 1;
	}
}

bool Interface::EventUsersPanelAntiLag_EFFECTSTATIC(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eUSERSPANEL_FPS].EventTick);
	// ----
	if( !this->Data[eOpMenu_MAINKG].OnShow || !IsWorkZone(eUSERSPANEL_FPS) )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eUSERSPANEL_FPS].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	this->Data[eUSERSPANEL_FPS].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if( Delay < 500 )
	{
		return false;
	}
	// ----
	this->Data[eUSERSPANEL_FPS].EventTick = GetTickCount();
	if (testFunctionInvItem4!=0)
	{
		testFunctionInvItem4 = 0;
		DelectEffectStaticOff_Hook();
	}
    else
	{
        DelectEffectStaticOn_Hook();
		testFunctionInvItem4 = 1;
	}
}

bool Interface::EventUsersPanelAntiLag_INVISIBLYWINGS(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eUSERSPANEL_INVIS1].EventTick);
	// ----
	if( !this->Data[eOpMenu_MAINKG].OnShow || !IsWorkZone(eUSERSPANEL_INVIS1) )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eUSERSPANEL_INVIS1].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	this->Data[eUSERSPANEL_INVIS1].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if( Delay < 500 )
	{
		return false;
	}
	// ----
	this->Data[eUSERSPANEL_INVIS1].EventTick = GetTickCount();
	if (testFunctionInvItem5!=0)
	{
		testFunctionInvItem5 = 0;
		SetOp((LPVOID)0x00588661,(LPVOID)0x005655C0,ASM::CALL);
		SetByte(0x0051EE20, 0x55); //Enable Cloaks
	}
    else
	{
		SetByte(0x0051EE20, 0xC3); //Disable Cloaks
        MemorySet(0x588661,0x90,0x5);
		testFunctionInvItem5 = 1;
	}
}

bool Interface::EventUsersPanelAntiLag_INVISIBLYWEAPONS(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eUSERSPANEL_INVIS2].EventTick);
	// ----
	if( !this->Data[eOpMenu_MAINKG].OnShow || !IsWorkZone(eUSERSPANEL_INVIS2) )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eUSERSPANEL_INVIS2].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	this->Data[eUSERSPANEL_INVIS2].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if( Delay < 500 )
	{
		return false;
	}
	// ----
	this->Data[eUSERSPANEL_INVIS2].EventTick = GetTickCount();
	if (testFunctionInvItem6!=0)
	{
		testFunctionInvItem6 = 0;
		SetOp((LPVOID)0x00576DDB,(LPVOID)0x005655C0,ASM::CALL);
		SetOp((LPVOID)0x005883F4,(LPVOID)0x005655C0,ASM::CALL);
	}
    else
	{
		MemorySet(0x576DDB,0x90,0x5);
		MemorySet(0x5883F4,0x90,0x5);
		testFunctionInvItem6 = 1;
	}
}

bool Interface::EventUsersPanelAntiLag_EFFECT15(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eUSERSPANEL_INVIS3].EventTick);
	// ----
	if( !this->Data[eOpMenu_MAINKG].OnShow || !IsWorkZone(eUSERSPANEL_INVIS3) )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eUSERSPANEL_INVIS3].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	this->Data[eUSERSPANEL_INVIS3].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if( Delay < 500 )
	{
		return false;
	}
	// ----
	this->Data[eUSERSPANEL_INVIS3].EventTick = GetTickCount();
	if (testFunctionInvItem7!=0)
	{
		testFunctionInvItem7 = 0;
		SetOp((LPVOID)0x0057655B,(LPVOID)0x006097B0,ASM::CALL); //original +15
	}
    else
	{
		MemorySet(0x0057655B,0x90,0x5); //remove +15
		testFunctionInvItem7 = 1;
	}
}

bool Interface::EventUsersPanelAntiLag_OBJECTS(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eUSERSPANEL_INVIS4].EventTick);
	// ----
	if( !this->Data[eOpMenu_MAINKG].OnShow || !IsWorkZone(eUSERSPANEL_INVIS4) )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eUSERSPANEL_INVIS4].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	this->Data[eUSERSPANEL_INVIS4].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if( Delay < 500 )
	{
		return false;
	}
	// ----
	this->Data[eUSERSPANEL_INVIS4].EventTick = GetTickCount();
	if (testFunctionInvItem8!=0)
	{
		testFunctionInvItem8 = 0;
		SetByte(0x005EDFE0, 0x55); //RESTAURA OBJETOS
		SetOp((LPVOID)0x005F8924,(LPVOID)0x0095A1E0,ASM::CALL); //Restore Drop Zen
	}
    else
	{
		MemorySet(0x005F8924,0x90,0x5); //Reduce Drop Zen
		SetByte(0x005EDFE0, 0xC3); //REMOVE OBJETOS
		testFunctionInvItem8 = 1;
	}
}

bool Interface::EventUsersPanelAntiLag_CLOSE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eOpMenu_CLOSEKG].EventTick);
	// ----
	if (!gInterface.Data[eOpMenu_MAINKG].OnShow || !gInterface.IsWorkZone(eOpMenu_CLOSEKG))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eOpMenu_CLOSEKG].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eOpMenu_CLOSEKG].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eOpMenu_CLOSEKG].EventTick = GetTickCount();
	gInterface.Data[eOpMenu_MAINKG].Close();
	// ----
	return false;
}

void Interface::DrawChaosBoxWindow()
{
	if(this->CheckWindow(ObjWindow::ChaosBox) && gProtect.m_MainInfo.DisableExpandedInventory == 0)
	{
		this->OpenWindow(ObjWindow::ExpandInventory);
	}
}

void Interface::BarPartyNew()
{
	if(gInterface.CheckWindow(ObjWindow::CashShop) 
		||gInterface.CheckWindow(ObjWindow::FullMap) 
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
	    || gInterface.CheckWindow(ObjWindow::MuHelper)
	    || gInterface.CheckWindow(ObjWindow::Character)
	    || gInterface.CheckWindow(ObjWindow::Inventory)
	    || gInterface.CheckWindow(ObjWindow::Shop))
	{
		return;
	}
}

//-> Interface Season 4
void Interface::OldOption()
{
	gInterface.DrawGUI(eBackG, 489, 431);
	//STATUS BUTTON
	if(gInterface.CheckWindow(Character))
	{
		if(pCursorX > 489 && pCursorX < 526 && pCursorY > 431 && pCursorY < 471)
		{
			gInterface.DrawGUI(ebtnOption1click, 489, 431);
			gInterface.DrawToolTip(485.0f, 418.0f, "Status (C)");
		}
		else
		{
			gInterface.DrawGUI(ebtnOption1click, 489, 431);
		}
	}
	else
	{
		if(pCursorX > 489 && pCursorX < 526 && pCursorY > 431 && pCursorY < 471)
		{
			gInterface.DrawGUI(ebtnOption1hover, 489, 431);
			gInterface.DrawToolTip(485.0f, 418.0f, "Status (C)");
		}
		else
		{
			gInterface.DrawGUI(ebtnOption1, 489, 431);
		}
	}
	//*
	if(pCursorX > 489 && pCursorX < 526 && pCursorY > 431 && pCursorY < 471 && (GetKeyState(VK_LBUTTON) & 0x100) != 0)
	{
		if(gInterface.CheckWindow(Character))
		{
			gInterface.CloseWindow(Character);
			keybd_event(VK_LBUTTON, 0, KEYEVENTF_KEYUP, 0);
		}
		else
		{
			gInterface.OpenWindow(Character);
			keybd_event(VK_LBUTTON, 0, KEYEVENTF_KEYUP, 0);
		}
	}
	//INVENTORY BUTTON
	if(gInterface.CheckWindow(Inventory))
	{
		if(pCursorX > 527 && pCursorX < 564 && pCursorY > 431 && pCursorY < 471)
		{
			gInterface.DrawGUI(ebtnOption2click, 527, 431);
			gInterface.DrawToolTip(523.0f, 418.0f, "Inventory (V,I)");
		}
		else
		{
			gInterface.DrawGUI(ebtnOption2click, 527, 431);
		}
	}
	else
	{
		if(pCursorX > 527 && pCursorX < 564 && pCursorY > 431 && pCursorY < 471)
		{
			gInterface.DrawGUI(ebtnOption2hover, 527, 431);
			gInterface.DrawToolTip(523.0f, 418.0f, "Inventory (V,I)");
		}
		else
		{
			gInterface.DrawGUI(ebtnOption2, 527, 431);
		}
	}
	//*
	if(pCursorX > 527 && pCursorX < 564 && pCursorY > 431 && pCursorY < 471 && (GetKeyState(VK_LBUTTON) & 0x100) != 0)
	{
		if(gInterface.CheckWindow(Inventory))
		{
			gInterface.CloseWindow(Inventory);
			keybd_event(VK_LBUTTON, 0, KEYEVENTF_KEYUP, 0);
		}
		else
		{
			gInterface.OpenWindow(Inventory);
			keybd_event(VK_LBUTTON, 0, KEYEVENTF_KEYUP, 0);
		}
	}
	//CORREIOS BUTTON
	if(gInterface.CheckWindow(FriendList))
	{
		if(pCursorX > 565 && pCursorX < 602 && pCursorY > 431 && pCursorY < 471)
		{
			gInterface.DrawGUI(ebtnOption3click, 565, 431);
			gInterface.DrawToolTip(561.0f, 418.0f, "Correios (F)");
		}
		else
		{
			gInterface.DrawGUI(ebtnOption3click, 565, 431);
		}
	}
	else
	{
		if(pCursorX > 565 && pCursorX < 602 && pCursorY > 431 && pCursorY < 471)
		{
			gInterface.DrawGUI(ebtnOption3hover, 565, 431);
			gInterface.DrawToolTip(561.0f, 418.0f, "Correios (F)");
		}
		else
		{
			gInterface.DrawGUI(ebtnOption3, 565, 431);
		}
	}
	//*
	if(pCursorX > 565 && pCursorX < 602 && pCursorY > 431 && pCursorY < 471 && (GetKeyState(VK_LBUTTON) & 0x100) != 0)
	{
		if(gInterface.CheckWindow(FriendList))
		{
			gInterface.CloseWindow(FriendList);
			keybd_event(VK_LBUTTON, 0, KEYEVENTF_KEYUP, 0);
		}
		else
		{
			gInterface.OpenWindow(FriendList);
			keybd_event(VK_LBUTTON, 0, KEYEVENTF_KEYUP, 0);
		}
	}
	//MENU BUTTON
	if(gInterface.CheckWindow(FastMenu))
	{
		if(pCursorX > 603 && pCursorX < 640 && pCursorY > 431 && pCursorY < 471)
		{
			gInterface.DrawGUI(ebtnOption4click, 603, 431);
			gInterface.DrawToolTip(599.0f, 418.0f, "Menu (U)");
		}
		else
		{
			gInterface.DrawGUI(ebtnOption4click, 603, 431);
		}
	}
	else
	{
		if(pCursorX > 603 && pCursorX < 640 && pCursorY > 431 && pCursorY < 471)
		{
			gInterface.DrawGUI(ebtnOption4hover, 603, 431);
			gInterface.DrawToolTip(599.0f, 418.0f, "Menu (U)");
		}
		else
		{
			gInterface.DrawGUI(ebtnOption4, 603, 431);
		}
	}
	//*
	if(pCursorX > 603 && pCursorX < 640 && pCursorY > 431 && pCursorY < 471 && (GetKeyState(VK_LBUTTON) & 0x100) != 0)
	{
		if(gInterface.CheckWindow(FastMenu))
		{
			gInterface.CloseWindow(FastMenu);
			keybd_event(VK_LBUTTON, 0, KEYEVENTF_KEYUP, 0);
		}
		else
		{
			gInterface.OpenWindow(FastMenu);
			keybd_event(VK_LBUTTON, 0, KEYEVENTF_KEYUP, 0);
		}
	}
}

void Interface::DrawCameraUI()
{
	float PosX = this->GetResizeX(eCAMERA_MAIN);

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		
		|| (this->CheckWindow(ObjWindow::ExpandWarehouse) && this->CheckWindow(ObjWindow::Warehouse) && this->CheckWindow(ObjWindow::Inventory))
		|| (this->CheckWindow(ObjWindow::ExpandInventory) && this->CheckWindow(ObjWindow::Warehouse) && this->CheckWindow(ObjWindow::Inventory))
		|| (this->CheckWindow(ObjWindow::ExpandInventory) && this->CheckWindow(ObjWindow::Character) && this->CheckWindow(ObjWindow::Inventory))
		|| (this->CheckWindow(ObjWindow::ExpandInventory) && this->CheckWindow(ObjWindow::Store) && this->CheckWindow(ObjWindow::Inventory)))
	{
		return;
	}

	//Custom Interface Type (S8)
	if(gProtect.m_MainInfo.CustomInterfaceType == 4 || gProtect.m_MainInfo.CustomInterfaceType == 5 || gProtect.m_MainInfo.CustomInterfaceType == 6)
	{
		
		this->DrawGUI(eCAMERA_BUTTON1, PosX - 97.5, 15);
		RenderBitmap(0x787D, PosX - 97.5, 14, 19, 19, 0.0, 0.0, 0.878, 0.225, 1, 1, 0.0);
		
		this->DrawGUI(eCAMERA_BUTTON2, PosX - 77.5, 13);
		RenderBitmap(0x787E, PosX - 77.5, 13, 19, 19, 0.0, 0.0, 0.878, 0.225, 1, 1, 0.0);
		
		if (gCamera.IsActive)
		{
			this->DrawColoredGUI(eCAMERA_BUTTON1, PosX - 97.5, 15, eShinyGreen);
			RenderBitmap(0x787D, PosX - 97.5, 14, 19, 19, 0.0, 0.451f, 0.878, 0.225, 1, 1, 0.0);
		}
	
		if (IsWorkZone(eCAMERA_BUTTON1))
		{
			if (gCamera.IsActive)
			{
				this->DrawToolTip(PosX - 97.5, 45, "Zoom: %02.f%%", gCamera.ZoomPercent);
			}

			else
			{
				this->DrawToolTip(PosX - 97.5, 45, gCustomMessage.GetMessageB(3243));
			}

			if (this->Data[eCAMERA_BUTTON1].OnClick)
			{
				RenderBitmap(0x787D, PosX - 97.5, 14, 19, 19, 0.0, 0.451f, 0.878, 0.225, 1, 1, 0.0);
				return;
			}

			RenderBitmap(0x787D, PosX - 97.5, 14, 19, 19, 0.0, 0.2255f, 0.878, 0.225, 1, 1, 0.0);
		}
		else if (IsWorkZone(eCAMERA_BUTTON2))
		{
			this->DrawToolTip(PosX - 77.5, 45, gCustomMessage.GetMessageB(3242));
			
			if (this->Data[eCAMERA_BUTTON2].OnClick)
			{
				RenderBitmap(0x787E, PosX - 77.5, 13, 19, 19, 0.0, 0.451f, 0.878, 0.225, 1, 1, 0.0);
				return;
			}

			RenderBitmap(0x787E, PosX - 77.5, 13, 19, 19, 0.0, 0.2255f, 0.878, 0.225, 1, 1, 0.0);
		}
	}

	//-> Classic S6
	else
	{
		this->DrawGUI(eCAMERA_MAIN, PosX, 0);
		this->DrawGUI(eCAMERA_BUTTON1, PosX + 18.5, 1);
		this->DrawGUI(eCAMERA_BUTTON2, PosX + 37.0, 1);
	
		if (gCamera.IsActive)
		{
			this->DrawColoredGUI(eCAMERA_BUTTON1, PosX + 18.5, 1, pMakeColor(255, 215, 40, 200));
		}
	
		if (IsWorkZone(eCAMERA_BUTTON1))
		{
			if (gCamera.IsActive)
			{
				this->DrawToolTip(PosX + 18.5 - 5, 25, "Zoom: %02.f%%", gCamera.ZoomPercent);
			}

			else
			{
				this->DrawToolTip(PosX + 18.5 - 5, 25, gCustomMessage.GetMessageB(3243));
			}
		
			if (this->Data[eCAMERA_BUTTON1].OnClick)
			{
				this->DrawColoredGUI(eCAMERA_BUTTON1, PosX + 18.5, 1, pMakeColor(40, 20, 3, 130));
				return;
			}
			
			this->DrawColoredGUI(eCAMERA_BUTTON1, PosX + 18.5, 1, pMakeColor(255, 204, 20, 200));
		}
		else if (IsWorkZone(eCAMERA_BUTTON2))
		{
			this->DrawToolTip(PosX + 37.0 - 5, 25, gCustomMessage.GetMessageB(3242));
			
			if (this->Data[eCAMERA_BUTTON2].OnClick)
			{
				this->DrawColoredGUI(eCAMERA_BUTTON2, PosX + 37.0, 1, pMakeColor(40, 20, 3, 130));
				return;
			}
			
			this->DrawColoredGUI(eCAMERA_BUTTON2, PosX + 37.0, 1, pMakeColor(255, 204, 20, 200));
		}
	}
}

void Interface::EventCameraUI(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (this->CheckWindow(CashShop)
		|| this->CheckWindow(SkillTree)
		|| this->CheckWindow(FullMap)
		|| this->CheckWindow(MoveList)
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store))
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}
	
	if (IsWorkZone(eCAMERA_BUTTON1))
	{
		DWORD Delay = (CurrentTick - this->Data[eCAMERA_BUTTON1].EventTick);
		
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCAMERA_BUTTON1].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
	
		this->Data[eCAMERA_BUTTON1].OnClick = false;
		pSetCursorFocus = false;
		
		if (Delay < 500)
		{
			return;
		}
		
		this->Data[eCAMERA_BUTTON1].EventTick = GetTickCount();
		
		gCamera.Switch();
	}
	
	else if (IsWorkZone(eCAMERA_BUTTON2))
	{
		DWORD Delay = (CurrentTick - this->Data[eCAMERA_BUTTON2].EventTick);
		
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCAMERA_BUTTON2].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		
		this->Data[eCAMERA_BUTTON2].OnClick = false;
		pSetCursorFocus = false;
		
		if (Delay < 500)
		{
			return;
		}
		
		this->Data[eCAMERA_BUTTON2].EventTick = GetTickCount();
		
		gCamera.Init();
	}
}

bool Interface::ButtonEx(DWORD Event, int ButtonID, bool Type)
{
	if( !this->IsWorkZone(ButtonID) )
	{
		return false;
	}

	if( Type == true )
	{
		if( !this->Data[ButtonID].Attribute )
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if( Event == WM_LBUTTONDOWN  && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
		//return false;
	}

	if(Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if( Delay < 500 )
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

//--

void Interface::DrawSendZenButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_SEND_ZEN_BUTTON, PosX + 175 - 185, 87);

		if (IsWorkZone(EXPe_SEND_ZEN_BUTTON))
		{
			if (this->Data[EXPe_SEND_ZEN_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_SEND_ZEN_BUTTON, PosX + 175 - 185, 87, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_SEND_ZEN_BUTTON, PosX + 175, 87);

		if (IsWorkZone(e_SEND_ZEN_BUTTON))
		{
			if (this->Data[e_SEND_ZEN_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_SEND_ZEN_BUTTON, PosX + 175, 87, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventSendZenButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}
	
	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_SEND_ZEN_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_SEND_ZEN_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_SEND_ZEN_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_SEND_ZEN_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_SEND_ZEN_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x02,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_SEND_ZEN_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_SEND_ZEN_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_SEND_ZEN_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_SEND_ZEN_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_SEND_ZEN_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x02,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

void Interface::DrawRecvZenButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}
	
	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_RECV_ZEN_BUTTON, PosX + 155 - 185, 87);

		if (IsWorkZone(EXPe_RECV_ZEN_BUTTON))
		{
			if (this->Data[EXPe_RECV_ZEN_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_RECV_ZEN_BUTTON, PosX + 155 - 185, 87, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_RECV_ZEN_BUTTON, PosX + 155, 87);

		if (IsWorkZone(e_RECV_ZEN_BUTTON))
		{
			if (this->Data[e_RECV_ZEN_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_RECV_ZEN_BUTTON, PosX + 155, 87, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventRecvZenButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}
	
	DWORD CurrentTick = GetTickCount();

	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_RECV_ZEN_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_RECV_ZEN_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_RECV_ZEN_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_RECV_ZEN_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_RECV_ZEN_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x03,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_RECV_ZEN_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_RECV_ZEN_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_RECV_ZEN_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_RECV_ZEN_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_RECV_ZEN_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x03,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

//--

void Interface::DrawSendChaosButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_SEND_CHAOS_BUTTON, PosX + 175 - 185, 106);

		if (IsWorkZone(EXPe_SEND_CHAOS_BUTTON))
		{
			if (this->Data[EXPe_SEND_CHAOS_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_SEND_CHAOS_BUTTON, PosX + 175 - 185, 106, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_SEND_CHAOS_BUTTON, PosX + 175, 106);

		if (IsWorkZone(e_SEND_CHAOS_BUTTON))
		{
			if (this->Data[e_SEND_CHAOS_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_SEND_CHAOS_BUTTON, PosX + 175, 106, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventSendChaosButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_SEND_CHAOS_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_SEND_CHAOS_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_SEND_CHAOS_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_SEND_CHAOS_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_SEND_CHAOS_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x04,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_SEND_CHAOS_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_SEND_CHAOS_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_SEND_CHAOS_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_SEND_CHAOS_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_SEND_CHAOS_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x04,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

void Interface::DrawRecvChaosButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_RECV_CHAOS_BUTTON, PosX + 155 - 185, 106);

		if (IsWorkZone(EXPe_RECV_CHAOS_BUTTON))
		{
			if (this->Data[EXPe_RECV_CHAOS_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_RECV_CHAOS_BUTTON, PosX + 155 - 185, 106, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_RECV_CHAOS_BUTTON, PosX + 155, 106);

		if (IsWorkZone(e_RECV_CHAOS_BUTTON))
		{
			if (this->Data[e_RECV_CHAOS_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_RECV_CHAOS_BUTTON, PosX + 155, 106, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventRecvChaosButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_RECV_CHAOS_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_RECV_CHAOS_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_RECV_CHAOS_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_RECV_CHAOS_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_RECV_CHAOS_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x05,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_RECV_CHAOS_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_RECV_CHAOS_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_RECV_CHAOS_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_RECV_CHAOS_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_RECV_CHAOS_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x05,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

//--

void Interface::DrawSendBlessButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_SEND_BLESS_BUTTON, PosX + 175 - 185, 126);

		if (IsWorkZone(EXPe_SEND_BLESS_BUTTON))
		{
			if (this->Data[EXPe_SEND_BLESS_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_SEND_BLESS_BUTTON, PosX + 175 - 185, 126, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_SEND_BLESS_BUTTON, PosX + 175, 126);

		if (IsWorkZone(e_SEND_BLESS_BUTTON))
		{
			if (this->Data[e_SEND_BLESS_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_SEND_BLESS_BUTTON, PosX + 175, 126, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventSendBlessButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_SEND_BLESS_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_SEND_BLESS_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_SEND_BLESS_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_SEND_BLESS_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_SEND_BLESS_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x06,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_SEND_BLESS_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_SEND_BLESS_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_SEND_BLESS_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_SEND_BLESS_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_SEND_BLESS_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x06,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

void Interface::DrawRecvBlessButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_RECV_BLESS_BUTTON, PosX + 155 - 185, 126);

		if (IsWorkZone(EXPe_RECV_BLESS_BUTTON))
		{
			if (this->Data[EXPe_RECV_BLESS_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_RECV_BLESS_BUTTON, PosX + 155 - 185, 126, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_RECV_BLESS_BUTTON, PosX + 155, 126);

		if (IsWorkZone(e_RECV_BLESS_BUTTON))
		{
			if (this->Data[e_RECV_BLESS_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_RECV_BLESS_BUTTON, PosX + 155, 126, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventRecvBlessButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_RECV_BLESS_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_RECV_BLESS_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_RECV_BLESS_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_RECV_BLESS_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_RECV_BLESS_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x07,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_RECV_BLESS_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_RECV_BLESS_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_RECV_BLESS_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_RECV_BLESS_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_RECV_BLESS_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x07,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

//--

void Interface::DrawSendSoulButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_SEND_SOUL_BUTTON, PosX + 175 - 185, 146);

		if (IsWorkZone(EXPe_SEND_SOUL_BUTTON))
		{
			if (this->Data[EXPe_SEND_SOUL_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_SEND_SOUL_BUTTON, PosX + 175 - 185, 146, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_SEND_SOUL_BUTTON, PosX + 175, 146);

		if (IsWorkZone(e_SEND_SOUL_BUTTON))
		{
			if (this->Data[e_SEND_SOUL_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_SEND_SOUL_BUTTON, PosX + 175, 146, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventSendSoulButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_SEND_SOUL_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_SEND_SOUL_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_SEND_SOUL_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_SEND_SOUL_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_SEND_SOUL_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x08,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_SEND_SOUL_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_SEND_SOUL_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_SEND_SOUL_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_SEND_SOUL_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_SEND_SOUL_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x08,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

void Interface::DrawRecvSoulButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_RECV_SOUL_BUTTON, PosX + 155 - 185, 146);

		if (IsWorkZone(EXPe_RECV_SOUL_BUTTON))
		{
			if (this->Data[EXPe_RECV_SOUL_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_RECV_SOUL_BUTTON, PosX + 155 - 185, 146, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_RECV_SOUL_BUTTON, PosX + 155, 146);

		if (IsWorkZone(e_RECV_SOUL_BUTTON))
		{
			if (this->Data[e_RECV_SOUL_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_RECV_SOUL_BUTTON, PosX + 155, 146, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventRecvSoulButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_RECV_SOUL_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_RECV_SOUL_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_RECV_SOUL_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_RECV_SOUL_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_RECV_SOUL_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x09,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_RECV_SOUL_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_RECV_SOUL_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_RECV_SOUL_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_RECV_SOUL_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_RECV_SOUL_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x09,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

//--

void Interface::DrawSendLifeButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_SEND_LIFE_BUTTON, PosX + 175 - 185, 166);

		if (IsWorkZone(EXPe_SEND_LIFE_BUTTON))
		{
			if (this->Data[EXPe_SEND_LIFE_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_SEND_LIFE_BUTTON, PosX + 175 - 185, 166, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_SEND_LIFE_BUTTON, PosX + 175, 166);

		if (IsWorkZone(e_SEND_LIFE_BUTTON))
		{
			if (this->Data[e_SEND_LIFE_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_SEND_LIFE_BUTTON, PosX + 175, 166, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventSendLifeButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_SEND_LIFE_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_SEND_LIFE_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_SEND_LIFE_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_SEND_LIFE_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_SEND_LIFE_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x10,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_SEND_LIFE_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_SEND_LIFE_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_SEND_LIFE_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_SEND_LIFE_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_SEND_LIFE_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x10,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

void Interface::DrawRecvLifeButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_RECV_LIFE_BUTTON, PosX + 155 - 185, 166);

		if (IsWorkZone(EXPe_RECV_LIFE_BUTTON))
		{
			if (this->Data[EXPe_RECV_LIFE_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_RECV_LIFE_BUTTON, PosX + 155 - 185, 166, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_RECV_LIFE_BUTTON, PosX + 155, 166);

		if (IsWorkZone(e_RECV_LIFE_BUTTON))
		{
			if (this->Data[e_RECV_LIFE_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_RECV_LIFE_BUTTON, PosX + 155, 166, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventRecvLifeButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_RECV_LIFE_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_RECV_LIFE_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_RECV_LIFE_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_RECV_LIFE_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_RECV_LIFE_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x11,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_RECV_LIFE_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_RECV_LIFE_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_RECV_LIFE_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_RECV_LIFE_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_RECV_LIFE_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x11,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

//--

void Interface::DrawSendCreationButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_SEND_CREATION_BUTTON, PosX + 175 - 185, 186);

		if (IsWorkZone(EXPe_SEND_CREATION_BUTTON))
		{
			if (this->Data[EXPe_SEND_CREATION_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_SEND_CREATION_BUTTON, PosX + 175 - 185, 186, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_SEND_CREATION_BUTTON, PosX + 175, 186);

		if (IsWorkZone(e_SEND_CREATION_BUTTON))
		{
			if (this->Data[e_SEND_CREATION_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_SEND_CREATION_BUTTON, PosX + 175, 186, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventSendCreationButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_SEND_CREATION_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_SEND_CREATION_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_SEND_CREATION_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_SEND_CREATION_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_SEND_CREATION_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x12,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_SEND_CREATION_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_SEND_CREATION_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_SEND_CREATION_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_SEND_CREATION_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_SEND_CREATION_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x12,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

void Interface::DrawRecvCreationButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}
	
	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);	
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_RECV_CREATION_BUTTON, PosX + 155 - 185, 186);

		if (IsWorkZone(EXPe_RECV_CREATION_BUTTON))
		{
			if (this->Data[EXPe_RECV_CREATION_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_RECV_CREATION_BUTTON, PosX + 155 - 185, 186, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_RECV_CREATION_BUTTON, PosX + 155, 186);

		if (IsWorkZone(e_RECV_CREATION_BUTTON))
		{
			if (this->Data[e_RECV_CREATION_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_RECV_CREATION_BUTTON, PosX + 155, 186, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventRecvCreationButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_RECV_CREATION_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_RECV_CREATION_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_RECV_CREATION_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_RECV_CREATION_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_RECV_CREATION_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x13,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_RECV_CREATION_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_RECV_CREATION_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_RECV_CREATION_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_RECV_CREATION_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_RECV_CREATION_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x13,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

//--

void Interface::DrawSendHarmonyButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_SEND_HARMONY_BUTTON, PosX + 175 - 185, 206);

		if (IsWorkZone(EXPe_SEND_HARMONY_BUTTON))
		{
			if (this->Data[EXPe_SEND_HARMONY_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_SEND_HARMONY_BUTTON, PosX + 175 - 185, 206, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_SEND_HARMONY_BUTTON, PosX + 175, 206);

		if (IsWorkZone(e_SEND_HARMONY_BUTTON))
		{
			if (this->Data[e_SEND_HARMONY_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_SEND_HARMONY_BUTTON, PosX + 175, 206, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventSendHarmonyButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_SEND_HARMONY_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_SEND_HARMONY_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_SEND_HARMONY_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_SEND_HARMONY_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_SEND_HARMONY_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x14,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_SEND_HARMONY_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_SEND_HARMONY_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_SEND_HARMONY_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_SEND_HARMONY_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_SEND_HARMONY_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x14,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

void Interface::DrawRecvHarmonyButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_RECV_HARMONY_BUTTON, PosX + 155 - 185, 206);

		if (IsWorkZone(EXPe_RECV_HARMONY_BUTTON))
		{
			if (this->Data[EXPe_RECV_HARMONY_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_RECV_HARMONY_BUTTON, PosX + 155 - 185, 206, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
	
	else
	{
		this->DrawGUI(e_RECV_HARMONY_BUTTON, PosX + 155, 206);

		if (IsWorkZone(e_RECV_HARMONY_BUTTON))
		{
			if (this->Data[e_RECV_HARMONY_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_RECV_HARMONY_BUTTON, PosX + 155, 206, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventRecvHarmonyButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_RECV_HARMONY_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_RECV_HARMONY_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_RECV_HARMONY_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_RECV_HARMONY_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_RECV_HARMONY_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x15,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_RECV_HARMONY_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_RECV_HARMONY_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_RECV_HARMONY_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_RECV_HARMONY_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_RECV_HARMONY_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x15,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

//--

void Interface::DrawSendGuardianButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_SEND_GUARDIAN_BUTTON, PosX + 175 - 185, 226);

		if (IsWorkZone(EXPe_SEND_GUARDIAN_BUTTON))
		{
			if (this->Data[EXPe_SEND_GUARDIAN_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_SEND_GUARDIAN_BUTTON, PosX + 175 - 185, 226, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_SEND_GUARDIAN_BUTTON, PosX + 175, 226);
		
		if (IsWorkZone(e_SEND_GUARDIAN_BUTTON))
		{
			if (this->Data[e_SEND_GUARDIAN_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_SEND_GUARDIAN_BUTTON, PosX + 175, 226, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventSendGuardianButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_SEND_GUARDIAN_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_SEND_GUARDIAN_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_SEND_GUARDIAN_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_SEND_GUARDIAN_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_SEND_GUARDIAN_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x16,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_SEND_GUARDIAN_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_SEND_GUARDIAN_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_SEND_GUARDIAN_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_SEND_GUARDIAN_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_SEND_GUARDIAN_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x16,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

void Interface::DrawRecvGuardianButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_RECV_GUARDIAN_BUTTON, PosX + 155 - 185, 226);

		if (IsWorkZone(EXPe_RECV_GUARDIAN_BUTTON))
		{
			if (this->Data[EXPe_RECV_GUARDIAN_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_RECV_GUARDIAN_BUTTON, PosX + 155 - 185, 226, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_RECV_GUARDIAN_BUTTON, PosX + 155, 226);

		if (IsWorkZone(e_RECV_GUARDIAN_BUTTON))
		{
			if (this->Data[e_RECV_GUARDIAN_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_RECV_GUARDIAN_BUTTON, PosX + 155, 226, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventRecvGuardianButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();

	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_RECV_GUARDIAN_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_RECV_GUARDIAN_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_RECV_GUARDIAN_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_RECV_GUARDIAN_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_RECV_GUARDIAN_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x17,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_RECV_GUARDIAN_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_RECV_GUARDIAN_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_RECV_GUARDIAN_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_RECV_GUARDIAN_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_RECV_GUARDIAN_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x17,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

//--

void Interface::DrawSendGemstoneButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_SEND_GEMSTONE_BUTTON, PosX + 175 - 185, 246);

		if (IsWorkZone(EXPe_SEND_GEMSTONE_BUTTON))
		{
			if (this->Data[EXPe_SEND_GEMSTONE_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_SEND_GEMSTONE_BUTTON, PosX + 175 - 185, 246, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_SEND_GEMSTONE_BUTTON, PosX + 175, 246);

		if (IsWorkZone(e_SEND_GEMSTONE_BUTTON))
		{
			if (this->Data[e_SEND_GEMSTONE_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_SEND_GEMSTONE_BUTTON, PosX + 175, 246, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventSendGemstoneButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_SEND_GEMSTONE_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_SEND_GEMSTONE_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_SEND_GEMSTONE_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_SEND_GEMSTONE_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_SEND_GEMSTONE_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x18,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_SEND_GEMSTONE_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_SEND_GEMSTONE_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_SEND_GEMSTONE_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_SEND_GEMSTONE_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_SEND_GEMSTONE_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x18,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

void Interface::DrawRecvGemstoneButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_RECV_GEMSTONE_BUTTON, PosX + 155 - 185, 246);

		if (IsWorkZone(EXPe_RECV_GEMSTONE_BUTTON))
		{
			if (this->Data[EXPe_RECV_GEMSTONE_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_RECV_GEMSTONE_BUTTON, PosX + 155 - 185, 246, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_RECV_GEMSTONE_BUTTON, PosX + 155, 246);

		if (IsWorkZone(e_RECV_GEMSTONE_BUTTON))
		{
			if (this->Data[e_RECV_GEMSTONE_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_RECV_GEMSTONE_BUTTON, PosX + 155, 246, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventRecvGemstoneButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_RECV_GEMSTONE_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_RECV_GEMSTONE_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_RECV_GEMSTONE_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_RECV_GEMSTONE_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_RECV_GEMSTONE_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x19,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_RECV_GEMSTONE_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_RECV_GEMSTONE_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_RECV_GEMSTONE_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_RECV_GEMSTONE_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_RECV_GEMSTONE_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x19,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

//--

void Interface::DrawSendLowerRefineStoneButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_SEND_LOW_REFINE_BUTTON, PosX + 175 - 185, 266);

		if (IsWorkZone(EXPe_SEND_LOW_REFINE_BUTTON))
		{
			if (this->Data[EXPe_SEND_LOW_REFINE_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_SEND_LOW_REFINE_BUTTON, PosX + 175 - 185, 266, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_SEND_LOW_REFINE_BUTTON, PosX + 175, 266);

		if (IsWorkZone(e_SEND_LOW_REFINE_BUTTON))
		{
			if (this->Data[e_SEND_LOW_REFINE_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_SEND_LOW_REFINE_BUTTON, PosX + 175, 266, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventSendLowerRefineStoneButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_SEND_LOW_REFINE_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_SEND_LOW_REFINE_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_SEND_LOW_REFINE_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_SEND_LOW_REFINE_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_SEND_LOW_REFINE_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x20,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_SEND_LOW_REFINE_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_SEND_LOW_REFINE_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_SEND_LOW_REFINE_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_SEND_LOW_REFINE_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_SEND_LOW_REFINE_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x20,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

void Interface::DrawRecvLowerRefineStoneButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_RECV_LOW_REFINE_BUTTON, PosX + 155 - 185, 266);

		if (IsWorkZone(EXPe_RECV_LOW_REFINE_BUTTON))
		{
			if (this->Data[EXPe_RECV_LOW_REFINE_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_RECV_LOW_REFINE_BUTTON, PosX + 155 - 185, 266, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_RECV_LOW_REFINE_BUTTON, PosX + 155, 266);

		if (IsWorkZone(e_RECV_LOW_REFINE_BUTTON))
		{
			if (this->Data[e_RECV_LOW_REFINE_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_RECV_LOW_REFINE_BUTTON, PosX + 155, 266, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventRecvLowerRefineStoneButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_RECV_LOW_REFINE_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_RECV_LOW_REFINE_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_RECV_LOW_REFINE_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_RECV_LOW_REFINE_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_RECV_LOW_REFINE_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x21,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_RECV_LOW_REFINE_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_RECV_LOW_REFINE_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_RECV_LOW_REFINE_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_RECV_LOW_REFINE_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_RECV_LOW_REFINE_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x21,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

//--

void Interface::DrawSendHighRefineStoneButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_SEND_HIGH_REFINE_BUTTON, PosX + 175 - 185, 286);

		if (IsWorkZone(EXPe_SEND_HIGH_REFINE_BUTTON))
		{
			if (this->Data[EXPe_SEND_HIGH_REFINE_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_SEND_HIGH_REFINE_BUTTON, PosX + 175 - 185, 286, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_SEND_HIGH_REFINE_BUTTON, PosX + 175, 286);

		if (IsWorkZone(e_SEND_HIGH_REFINE_BUTTON))
		{
			if (this->Data[e_SEND_HIGH_REFINE_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_SEND_HIGH_REFINE_BUTTON, PosX + 175, 286, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventSendHighRefineStoneButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_SEND_HIGH_REFINE_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_SEND_HIGH_REFINE_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_SEND_HIGH_REFINE_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_SEND_HIGH_REFINE_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_SEND_HIGH_REFINE_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x22,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_SEND_HIGH_REFINE_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_SEND_HIGH_REFINE_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_SEND_HIGH_REFINE_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_SEND_HIGH_REFINE_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_SEND_HIGH_REFINE_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x22,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

void Interface::DrawRecvHighRefineStoneButton()
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody	= 40.0;
	float StartY = 40;
	float PosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		this->DrawGUI(EXPe_RECV_HIGH_REFINE_BUTTON, PosX + 155 - 185, 286);

		if (IsWorkZone(EXPe_RECV_HIGH_REFINE_BUTTON))
		{
			if (this->Data[EXPe_RECV_HIGH_REFINE_BUTTON].OnClick)
			{
				this->DrawColoredGUI(EXPe_RECV_HIGH_REFINE_BUTTON, PosX + 155 - 185, 286, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}

	else
	{
		this->DrawGUI(e_RECV_HIGH_REFINE_BUTTON, PosX + 155, 286);

		if (IsWorkZone(e_RECV_HIGH_REFINE_BUTTON))
		{
			if (this->Data[e_RECV_HIGH_REFINE_BUTTON].OnClick)
			{
				this->DrawColoredGUI(e_RECV_HIGH_REFINE_BUTTON, PosX + 155, 286, pMakeColor(40, 20, 3, 130));
				return;
			}
		}
	}
}

void Interface::EventRecvHighRefineStoneButton(DWORD Event)
{
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	// - Fix Jewel bank + Npc Guardsman
	if (gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::Warehouse))
	{
		return;
	}

	if (this->CheckWindow(CashShop) 
		|| this->CheckWindow(SkillTree) 
		|| this->CheckWindow(FullMap) 
		|| this->CheckWindow(MoveList) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(ExpandInventory) && this->CheckWindow(Store)) 
		|| (this->CheckWindow(Inventory) && this->CheckWindow(Warehouse) && this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	
	//Check Expanded Inventory
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		if (IsWorkZone(EXPe_RECV_HIGH_REFINE_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[EXPe_RECV_HIGH_REFINE_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[EXPe_RECV_HIGH_REFINE_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[EXPe_RECV_HIGH_REFINE_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[EXPe_RECV_HIGH_REFINE_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x23,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}

	else
	{
		if (IsWorkZone(e_RECV_HIGH_REFINE_BUTTON))
		{
			DWORD Delay = (CurrentTick - this->Data[e_RECV_HIGH_REFINE_BUTTON].EventTick);
		
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[e_RECV_HIGH_REFINE_BUTTON].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
		
			this->Data[e_RECV_HIGH_REFINE_BUTTON].OnClick = false;
			pSetCursorFocus = false;
		
			if (Delay < 500)
			{
				return;
			}

			this->Data[e_RECV_HIGH_REFINE_BUTTON].EventTick = GetTickCount();

			PMSG_TICKET_SEND pMsg;
			pMsg.header.set(0x79,0x23,sizeof(pMsg));
			DataSend((BYTE*)&pMsg,pMsg.header.size);
		}
	}
}

//--

//-> Custom Bonus Welcome Window
void Interface::DrawInterfaceBemVindo()
{
	/*if(!this->Data[eBEMVINDO_MAIN].OnShow)
	{
		return;
	}
	//--
	float MainWidth=380.0;
	float MainHeight=380.0;
	float StartY=10.0;
	float StartX=(MAX_WIN_WIDTH/2)-(MainWidth/2);
	//--
	pDrawImage(2339, 140.0, 30.0, 365.0, 360.0, 0, 0, 1, 1, 1, 1, 0.0); //-> Janela Bem Vindo

	//--> Texto Bem vindo + Fix Resoluções
	if(pWinWidth == 800){this->DrawFormat(eGold,StartX+58,StartY+107,+250,1,"Bem Vindo ao MU Show");}
	if(pWinWidth == 1024){this->DrawFormat(eGold,StartX+64,StartY+107,+250,1,"Bem Vindo ao MU Show");}
	if(pWinWidth == 1280){this->DrawFormat(eGold,StartX+65,StartY+109,+250,1,"Bem Vindo ao MU Show");}
	if(pWinWidth == 1360 || pWinWidth == 1440){this->DrawFormat(eGold,StartX+70,StartY+108,+250,1,"Bem Vindo ao MU Show");}
	if(pWinWidth == 1680){this->DrawFormat(eGold,StartX+70,StartY+108,+250,1,"Bem Vindo ao MU Show");}
	if(pWinWidth == 1920){this->DrawFormat(eGold,StartX+75,StartY+109,+250,1,"Bem Vindo ao MU Show");}

	//--> Texto
	this->DrawFormat(eWhite240,StartX+22,StartY+142,+250,1,"Olá aventureiro, embora este seja um mundo");
	this->DrawFormat(eWhite240,StartX+22,StartY+153,+250,1,"repleto de caos, desistir não é uma opção.");
	this->DrawFormat(eWhite240,StartX+22,StartY+164,+250,1,"Portanto você receberá este kit de sobrevivência.");
	this->DrawFormat(eWhite240,StartX+22,StartY+175,+250,1,"Use-o com sabedoria, fique forte e junte-se a");
	this->DrawFormat(eWhite240,StartX+22,StartY+186,+250,1,"outros jogadores para desbravar o desconhecido!");

	//--> Reward Text + Fix Resoluções
	if(pWinWidth == 800){this->DrawFormat(eGold,StartX+21.5,StartY+212,+250,1,"Você receberá as seguintes recompensas abaixo");}
	if(pWinWidth == 1024){this->DrawFormat(eGold,StartX+25,StartY+212,+250,1,"Você receberá as seguintes recompensas abaixo");}
	if(pWinWidth == 1280){this->DrawFormat(eGold,StartX+25,StartY+214,+250,1,"Você receberá as seguintes recompensas abaixo");}
	if(pWinWidth == 1360 || pWinWidth == 1440){this->DrawFormat(eGold,StartX+40,StartY+213,+250,1,"Você receberá as seguintes recompensas abaixo");}
	if(pWinWidth == 1680){this->DrawFormat(eGold,StartX+40,StartY+213,+250,1,"Você receberá as seguintes recompensas abaixo");}
	if(pWinWidth == 1920){this->DrawFormat(eGold,StartX+54,StartY+213,+250,1,"Você receberá as seguintes recompensas abaixo");}

	//--> Rewards
	this->DrawFormat(eDivine,StartX+24,StartY+229,+250,1,"Seal of Ascension (3 Dias)");
	this->DrawFormat(eDivine,StartX+24,StartY+243,+250,1,"Scroll of Defense (1 Dia)");
	this->DrawFormat(eDivine,StartX+24,StartY+257,+250,1,"1000 Pontos para distribuir");
	this->DrawFormat(eDivine,StartX+24,StartY+271,+250,1,"10,000,000 Zen para gastar");
	//--
	this->DrawGUI(eBEMVINDO_YES,StartX+74,StartY+302.5);*/

	if(!this->Data[eBEMVINDO_MAIN].OnShow)
	{
		return;
	}
	//--
	float MainWidth=200.0;
	float MainHeight=300.0;
	float StartY=10.0;
	float StartX=(MAX_WIN_WIDTH/2)-(MainWidth/2);
	//--
	pDrawImage(2339, 208.5, 98.0, 224.0, 250.0, 0, 0, 1, 1, 1, 1, 0.0); //-> Janela Bem Vindo

	//--> Texto Bem vindo + Fix Resoluções
	if(pWinWidth == 800){this->DrawFormat(eGold,StartX+58,StartY+107,+250,1,"Bem Vindo ao MU Show");}
	if(pWinWidth == 1024){this->DrawFormat(eGold,StartX+64,StartY+107,+250,1,"Bem Vindo ao MU Show");}
	if(pWinWidth == 1280){this->DrawFormat(eGold,StartX+65,StartY+109,+250,1,"Bem Vindo ao MU Show");}
	if(pWinWidth == 1360 || pWinWidth == 1440){this->DrawFormat(eGold,StartX+70,StartY+108,+250,1,"Bem Vindo ao MU Show");}
	if(pWinWidth == 1680){this->DrawFormat(eGold,StartX+70,StartY+108,+250,1,"Bem Vindo ao MU Show");}
	if(pWinWidth == 1920){this->DrawFormat(eGold,StartX+75,StartY+109,+250,1,"Bem Vindo ao MU Show");}

	//--> Texto
	this->DrawFormat(eWhite240,StartX+22,StartY+142,+250,1,"Olá aventureiro, embora este seja um mundo");
	this->DrawFormat(eWhite240,StartX+22,StartY+153,+250,1,"repleto de caos, desistir não é uma opção.");
	this->DrawFormat(eWhite240,StartX+22,StartY+164,+250,1,"Portanto você receberá este kit de sobrevivência.");
	this->DrawFormat(eWhite240,StartX+22,StartY+175,+250,1,"Use-o com sabedoria, fique forte e junte-se a");
	this->DrawFormat(eWhite240,StartX+22,StartY+186,+250,1,"outros jogadores para desbravar o desconhecido!");

	//--> Reward Text + Fix Resoluções
	if(pWinWidth == 800){this->DrawFormat(eGold,StartX+21.5,StartY+212,+250,1,"Você receberá as seguintes recompensas abaixo");}
	if(pWinWidth == 1024){this->DrawFormat(eGold,StartX+25,StartY+212,+250,1,"Você receberá as seguintes recompensas abaixo");}
	if(pWinWidth == 1280){this->DrawFormat(eGold,StartX+25,StartY+214,+250,1,"Você receberá as seguintes recompensas abaixo");}
	if(pWinWidth == 1360 || pWinWidth == 1440){this->DrawFormat(eGold,StartX+40,StartY+213,+250,1,"Você receberá as seguintes recompensas abaixo");}
	if(pWinWidth == 1680){this->DrawFormat(eGold,StartX+40,StartY+213,+250,1,"Você receberá as seguintes recompensas abaixo");}
	if(pWinWidth == 1920){this->DrawFormat(eGold,StartX+54,StartY+213,+250,1,"Você receberá as seguintes recompensas abaixo");}

	//--> Rewards
	this->DrawFormat(eDivine,StartX+24,StartY+229,+250,1,"Seal of Ascension (3 Dias)");
	this->DrawFormat(eDivine,StartX+24,StartY+243,+250,1,"Scroll of Defense (1 Dia)");
	this->DrawFormat(eDivine,StartX+24,StartY+257,+250,1,"1000 Pontos para distribuir");
	this->DrawFormat(eDivine,StartX+24,StartY+271,+250,1,"10,000,000 Zen para gastar");
	//--
	this->DrawGUI(eBEMVINDO_YES,StartX+74,StartY+302.5);
}

//--> Bem Vindo Event Window
bool Interface::DrawInterfaceBemVindo_Main(DWORD Event)
{
	this->DrawInterfaceBemVindo_Button1(Event);
	//this->OffAttackEvent_Button2(Event);
	return true;
}

//-> Bem Vindo Event Button
bool Interface::DrawInterfaceBemVindo_Button1(DWORD Event)
{
	DWORD CurrentTick=GetTickCount();
	DWORD Delay=(CurrentTick-this->Data[eBEMVINDO_YES].EventTick);
	if(!this->Data[eBEMVINDO_MAIN].OnShow||!IsWorkZone(eBEMVINDO_YES))
	{
		return false;
	}
	if(Event == WM_LBUTTONDOWN)
	{
		this->Data[eBEMVINDO_YES].OnClick=true;
		pSetCursorFocus=true;
		return true;
	}
	this->Data[eBEMVINDO_YES].OnClick=false;
	pSetCursorFocus=false;
	if(Delay<500)
	{
		return false;
	}
	this->Data[eBEMVINDO_YES].EventTick=GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFF,0x08,sizeof(pMsg));
	DataSend((BYTE*)&pMsg,pMsg.header.size);
	this->CloseBemVindoWindow();
}