#pragma once

#include "stdafx.h"
#include "import.h"

#define MAX_WINDOW_EX		100
#define MAX_OBJECT			250
#define MAX_WIN_WIDTH		640
#define MAX_WIN_HEIGHT		480
#define pDrawInterfaceNumBer	((double(__stdcall*)(float X, float Y, int num, float size)) 0x854FE0)

enum ObjectID
{
	eFlag01=1,
	eFlag02,
	eFlag03,
	eFlag04,
	eFlag05,
	eFlag06,
	eFlag07,
	eFlag08,
	eFlag09,
	eFlag10,
	eFlag11,
	eFlag12,
	eFlag13,
	eFlag14,
	eFlag15,
	eFlag16,
	eFlag17,
	eFlag18,
	eFlag19,
	eFlag20,
	eFlag21,
	eFlag22,
	eTIME,

	//-> Advanced Stats
	ex_INFO_2,
	eADVANCE_STAT_INFO,

	eRankPANEL_MAIN,
	eRanking,
	eSAMPLEBUTTON,
	eSAMPLEBUTTON2,
	eVip_MAIN,
	eVip_TITLE,
	eVip_FRAME,
	eVip_FOOTER,
	eVip_DIV,
	eVip_CLOSE,
	eVip_BRONZE,
	eVip_SILVER,
	eVip_GOLD,
	eVip_PLATINUM,
	eVip_STATUS,
	eRanking_MAIN,
	eRanking_CLOSE,
	eLogo,
	eEventTimePANEL_MAIN,
	eEventTime_MAIN,
	eEventTime_CLOSE,
	eMenu,
	eMenuBG,
	eMenu_MAIN,
	eMenu_TITLE,
	eMenu_FRAME,
	eMenu_FOOTER,
	eMenu_DIV,
	eMenu_CLOSE,
	eMenu_OPT1,
	eMenu_OPT2,
	eMenu_OPT3,
	eMenu_OPT4,
	eMenu_OPT20,
	eMenu_OPT21,
	eCommand_MAIN,
	eCommand_TITLE,
	eCommand_FRAME,
	eCommand_FOOTER,
	eCommand_DIV,
	eCommand_CLOSE,
	eOFFTRADE_JoB,
	eOFFTRADE_JoS,
	eOFFTRADE_JoC,
	eOFFTRADE_WCC,
	eOFFTRADE_WCP,
	eOFFTRADE_WCG,
	eOFFTRADE_OPEN,

	CharacterSelect,
	CharacterSelect_0Button01,
	CharacterSelect_0Button02,
	CharacterSelect_0Button03,
	CharacterSelect_1Button01,
	CharacterSelect_1Button02,
	CharacterSelect_1Button03,
	CharacterSelect_2Button01,
	CharacterSelect_2Button02,
	CharacterSelect_2Button03,
	CharacterSelect_3Button01,
	CharacterSelect_3Button02,
	CharacterSelect_3Button03,
	CharacterSelect_4Button01,
	CharacterSelect_4Button02,
	CharacterSelect_4Button03,

	eCONFIRM_MAIN,
	eCONFIRM_BTN_OK,
	eCONFIRM_BTN_CANCEL,
	eCONFIRM_TITLE,
	eCONFIRM_FRAME,
	eCONFIRM_FOOTER,
	eCONFIRM_DIV,

	eNextCommand,
	ePrevCommand,

	eNextEvent,
	ePrevEvent,
	eNewInterfaceParty,
	eNewInterfaceCharacter,
	eNewInterfaceInventory,
	
	//Custom Interface Type (S1/S2/S3)
	eMainS2right,
	eMainS2middle,
	eMainS2left,
	eSkillBox,
	eDragonLeft,
	eDragonRight,
	eCharacter,
	eInventory,
	eParty,
	eFriend,
	eFastMenu,
	eShop,
	eGuild,
	eOrelhinha,
	eJanelinha,
	eLuizinha,
	ebtnWisper,

	eSTORE_CLOSE,
	iNewCloseStoreBtn,

	//jewelbank
	eJEWELBANKe_CLOSE,
	eJEWELBANK_CLOSE,
	eJEWELBANK_MAIN,
	eJEWELBANK_TITLE,
	eJEWELBANK_FRAME,
	eJEWELBANK_FOOTER,
	eJEWELBANK_POINT,
	eJEWELBANK_LINE,
	eJEWELBANK_DIV,
	/*eJEWELBANK_PAGEUP1,
	eJEWELBANK_PAGEUP2,
	eJEWELBANK_PAGEUP3,
	eJEWELBANK_PAGEUP4,
	eJEWELBANK_PAGEUP5,
	eJEWELBANK_PAGEUP6,
	eJEWELBANK_PAGEUP7,
	eJEWELBANK_PAGEUP8,
	eJEWELBANK_PAGEUP9,
	eJEWELBANK_PAGEUP10,
	eJEWELBANK_PAGEUP11,
	eJEWELBANK_PAGEDN1,
	eJEWELBANK_PAGEDN2,
	eJEWELBANK_PAGEDN3,
	eJEWELBANK_PAGEDN4,
	eJEWELBANK_PAGEDN5,
	eJEWELBANK_PAGEDN6,
	eJEWELBANK_PAGEDN7,
	eJEWELBANK_PAGEDN8,
	eJEWELBANK_PAGEDN9,
	eJEWELBANK_PAGEDN10,
	eJEWELBANK_PAGEDN11,
	eJEWELBANK_NEXTWIN,
	eJEWELBANK_PREVWIN,*/
	//--
/*	EXPeJEWELBANK_PAGEUP1,
	EXPeJEWELBANK_PAGEUP2,
	EXPeJEWELBANK_PAGEUP3,
	EXPeJEWELBANK_PAGEUP4,
	EXPeJEWELBANK_PAGEUP5,
	EXPeJEWELBANK_PAGEUP6,
	EXPeJEWELBANK_PAGEUP7,
	EXPeJEWELBANK_PAGEUP8,
	EXPeJEWELBANK_PAGEUP9,
	EXPeJEWELBANK_PAGEUP10,
	EXPeJEWELBANK_PAGEUP11,
	EXPeJEWELBANK_PAGEDN1,
	EXPeJEWELBANK_PAGEDN2,
	EXPeJEWELBANK_PAGEDN3,
	EXPeJEWELBANK_PAGEDN4,
	EXPeJEWELBANK_PAGEDN5,
	EXPeJEWELBANK_PAGEDN6,
	EXPeJEWELBANK_PAGEDN7,
	EXPeJEWELBANK_PAGEDN8,
	EXPeJEWELBANK_PAGEDN9,
	EXPeJEWELBANK_PAGEDN10,
	EXPeJEWELBANK_PAGEDN11,*/
	//--

	//-> Buttons (S4)
	ebtnOption1,
	ebtnOption1hover,
	ebtnOption1click,
	ebtnOption2,
	ebtnOption2hover,
	ebtnOption2click,
	ebtnOption3,
	ebtnOption3hover,
	ebtnOption3click,
	ebtnOption4,
	ebtnOption4hover,
	ebtnOption4click,
	eBackG,

	//antilag
	//option new menu
	eOpMenu_MAINKG,
	eOpMenu_TITLEKG,
	eOpMenu_FRAMEKG,
	eOpMenu_FOOTERKG,
	eOpMenu_DIVKG,
	eOpMenu_CLOSEKG,
	eCheck,
	eUnCheck,
	//new menu ops
	eUSERSPANEL_FOG,
	eUSERSPANEL_MINIMAP,
	eUSERSPANEL_TIME,
	eUSERSPANEL_GLOW,
	eUSERSPANEL_FPS,
	eUSERSPANEL_CHAT,
	eUSERSPANEL_DRAGON,
	eUSERSPANEL_OPTION,
	eUSERSPANEL_LINE,
	//PANEL ANTILAG
	eUSERSPANEL_INVIS1,
	eUSERSPANEL_INVIS2,
	eUSERSPANEL_INVIS3,
	eUSERSPANEL_INVIS4,

	eCAMERA_MAIN,
	eCAMERA_BUTTON1,
	eCAMERA_BUTTON2,

	//--
	e_SEND_ZEN_BUTTON,
	e_RECV_ZEN_BUTTON,
	e_SEND_CHAOS_BUTTON,
	e_RECV_CHAOS_BUTTON,
	e_SEND_BLESS_BUTTON,
	e_RECV_BLESS_BUTTON,
	e_SEND_SOUL_BUTTON,
	e_RECV_SOUL_BUTTON,
	e_SEND_LIFE_BUTTON,
	e_RECV_LIFE_BUTTON,
	e_SEND_CREATION_BUTTON,
	e_RECV_CREATION_BUTTON,
	e_SEND_HARMONY_BUTTON,
	e_RECV_HARMONY_BUTTON,
	e_SEND_GUARDIAN_BUTTON,
	e_RECV_GUARDIAN_BUTTON,
	e_SEND_GEMSTONE_BUTTON,
	e_RECV_GEMSTONE_BUTTON,
	e_SEND_LOW_REFINE_BUTTON,
	e_RECV_LOW_REFINE_BUTTON,
	e_SEND_HIGH_REFINE_BUTTON,
	e_RECV_HIGH_REFINE_BUTTON,
	//--
	EXPe_SEND_ZEN_BUTTON,
	EXPe_RECV_ZEN_BUTTON,
	EXPe_SEND_CHAOS_BUTTON,
	EXPe_RECV_CHAOS_BUTTON,
	EXPe_SEND_BLESS_BUTTON,
	EXPe_RECV_BLESS_BUTTON,
	EXPe_SEND_SOUL_BUTTON,
	EXPe_RECV_SOUL_BUTTON,
	EXPe_SEND_LIFE_BUTTON,
	EXPe_RECV_LIFE_BUTTON,
	EXPe_SEND_CREATION_BUTTON,
	EXPe_RECV_CREATION_BUTTON,
	EXPe_SEND_HARMONY_BUTTON,
	EXPe_RECV_HARMONY_BUTTON,
	EXPe_SEND_GUARDIAN_BUTTON,
	EXPe_RECV_GUARDIAN_BUTTON,
	EXPe_SEND_GEMSTONE_BUTTON,
	EXPe_RECV_GEMSTONE_BUTTON,
	EXPe_SEND_LOW_REFINE_BUTTON,
	EXPe_RECV_LOW_REFINE_BUTTON,
	EXPe_SEND_HIGH_REFINE_BUTTON,
	EXPe_RECV_HIGH_REFINE_BUTTON,

	eBEMVINDO_MAIN,
	eBEMVINDO_YES,
};

//========================================================================================================================================
// Advanced Stats
//========================================================================================================================================
enum ObjWindowsEx
{
	/*exWinNews = 1,
	exWinReset = 2,
	exWinGrandReset = 3,
	exWinRanking = 4,
	exWinDonate = 5,
	exWinPremium = 6,
	exWinMiniMenu = 7,
	exWinSettings = 8,
	exWinPTSearchMaster = 9,
	exWinPTSearchUser = 10,
	exWinPersonalSearch = 12,
	exWinPersonalPrice = 13,
	exWinNPCBuffer,
	exWinSmithy,
	exWinSmithyCheck,
	exWinCheckOffAfk,
	exWinMarriage,
	exWinAddPoints,
	exWinAddResetPoint,
	exWinCustomMenu,
	exWinCustomMenuChangeClass,
	exWinDungeonSiege,
	exWinTeamVsTeam,
	exWinTeamVsTeamStatistic,
	exWinAchievements,
	exWinAchievementsPower,
	exWinTeleport,
	exWinTeleportEvo,
	exWinResetRage,
	exWinDonateCheck,
	exWinPKClear,
	exWinAccWarning,
	exWinAccMenu,
	exWinAccOption,
	exWinAccPC,
	exWinAccMessage,
	exWinAccNumber,
	exWinReferralMenu,
	exWinReferralSystem,
	exWinReferralSystem2,
	exWinQuest,
	exWinLottery,
	exWinItemMarket,
	exWinItemMarket2,
	exWinMenuV3,*/
	exWinStatsAdvance,	
};

struct InterfaceObject
{
	DWORD	ModelID;
	float	Width;
	float	Height;
	float	X;
	float	Y;
	float	MaxX;
	float	MaxY;
	DWORD	EventTick;
	bool	OnClick;
	bool	OnShow;
	BYTE	Attribute;
	bool	ByClose;
	long	OpenedValue;
	BYTE	Speed;
	char	StatValue[20];
	int		Type;
	bool	FirstLoad;
	void Close()
	{
		this->OnShow = false;
		pSetCursorFocus = false;
		this->ByClose = false;
	};

	void Open()
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->ByClose = false;
	};

	void Open(int Value, int Speed)
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
		this->FirstLoad = true;
	};

		void Close(int Value, int Speed)
	{
		this->OnShow = false; pSetCursorFocus = false; 
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
	}

	void CloseAnimated(int Speed)
	{
		pSetCursorFocus = false;
		this->Speed = Speed;
		this->ByClose = true;
	}
};

class Interface
{
public:
	//Interface();

	float PetY;
	float PetX;
	void		Load();
	static void	LoadImages();
	static void	LoadModels();
	static void	Work();
	static void Work2();

	int teste;

	void Interface::DrawGUI2(short ObjectID, float PosX, float PosY);
	void Interface::DrawButton2(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	
	void		BindObject(short ObjectID, DWORD ModelID, float Width, float Height, float X, float Y);
	void		DrawGUI(short ObjectID, float PosX, float PosY);
	void		DrawTimeUI();
	int			DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	void		DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void		ResetDrawIMG(short ObjectID);
	int			DrawMessage(int Mode, LPCSTR Text, ...);
	void		DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);

	bool		CheckWindow(int WindowID);
	int			CloseWindow(int WindowID);
	int			OpenWindow(int WindowID);

	void		DrawCameraUI();
	void		EventCameraUI(DWORD Event);

	void		DrawSendZenButton();
	void		DrawRecvZenButton();
	void		EventSendZenButton(DWORD Event);
	void		EventRecvZenButton(DWORD Event);

	void		DrawSendChaosButton();
	void		DrawRecvChaosButton();
	void		EventSendChaosButton(DWORD Event);
	void		EventRecvChaosButton(DWORD Event);

	void		DrawSendBlessButton();
	void		DrawRecvBlessButton();
	void		EventSendBlessButton(DWORD Event);
	void		EventRecvBlessButton(DWORD Event);

	void		DrawSendSoulButton();
	void		DrawRecvSoulButton();
	void		EventSendSoulButton(DWORD Event);
	void		EventRecvSoulButton(DWORD Event);

	void		DrawSendLifeButton();
	void		DrawRecvLifeButton();
	void		EventSendLifeButton(DWORD Event);
	void		EventRecvLifeButton(DWORD Event);

	void		DrawSendCreationButton();
	void		DrawRecvCreationButton();
	void		EventSendCreationButton(DWORD Event);
	void		EventRecvCreationButton(DWORD Event);

	void		DrawSendHarmonyButton();
	void		DrawRecvHarmonyButton();
	void		EventSendHarmonyButton(DWORD Event);
	void		EventRecvHarmonyButton(DWORD Event);

	void		DrawSendGuardianButton();
	void		DrawRecvGuardianButton();
	void		EventSendGuardianButton(DWORD Event);
	void		EventRecvGuardianButton(DWORD Event);

	void		DrawSendGemstoneButton();
	void		DrawRecvGemstoneButton();
	void		EventSendGemstoneButton(DWORD Event);
	void		EventRecvGemstoneButton(DWORD Event);

	void		DrawSendLowerRefineStoneButton();
	void		DrawRecvLowerRefineStoneButton();
	void		EventSendLowerRefineStoneButton(DWORD Event);
	void		EventRecvLowerRefineStoneButton(DWORD Event);

	void		DrawSendHighRefineStoneButton();
	void		DrawRecvHighRefineStoneButton();
	void		EventSendHighRefineStoneButton(DWORD Event);
	void		EventRecvHighRefineStoneButton(DWORD Event);

	bool		IsWorkZone(short ObjectID);
	float		GetResizeX(short ObjectID);
	int			DrawToolTip(int X, int Y, LPCSTR Text, ...);
	float		DrawRepeatGUI(short MonsterID, float X, float Y, int Count);
	void		DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color);
	void		DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void		DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);

	//Vip Window
	void		OpenVipWindow() { this->Data[eVip_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CloseVipWindow() { this->Data[eVip_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CheckVipWindow() { return this->Data[eVip_MAIN].OnShow; };
	void		DrawVipWindow();
	bool		EventVipWindow_Main(DWORD Event);
	bool		EventVipWindow_Close(DWORD Event);
	bool		EventVipWindow_Bronze(DWORD Event);
	bool		EventVipWindow_Silver(DWORD Event);
	bool		EventVipWindow_Gold(DWORD Event);
	bool		EventVipWindow_Platinum(DWORD Event);
	bool		EventVipWindow_StatusVip(DWORD Event);

	//Menu
	void		DrawMenu();
	bool		EventDrawMenu_Open(DWORD Event);
	void		OpenMenuWindow() { this->Data[eMenu_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CloseMenuWindow() { this->Data[eMenu_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CheckMenuWindow() { return this->Data[eMenu_MAIN].OnShow; };
	void		DrawMenuOpen();
	bool		EventDrawMenu_Close(DWORD Event);
	bool		EventDrawMenu_Op1(DWORD Event);
	bool		EventDrawMenu_Op2(DWORD Event);
	bool		EventDrawMenu_Op3(DWORD Event);
	bool		EventDrawMenu_Op4(DWORD Event);
	bool		EventDrawMenu_Op20(DWORD Event);
	bool		EventDrawMenu_Op21(DWORD Event);
	void		DrawConfirmOpen();
	bool		EventConfirm_OK(DWORD Event);
	bool		EventConfirm_CANCEL(DWORD Event);

	void		DrawLogo(bool active);
	void		CloseCustomWindow();

	void OldOption();

	//Mini Map
//	void		DrawMiniMap();
//	bool		MiniMapCheck();
//	bool		CombinedChecks();
//	bool		CheckMap();

	//Custom Interface Type (S1/S2/S3)
	void DrawInterfaceS3Menu();
	void DrawInterfaceS2Menu();
	void DrawInterface97Menu();
	void EventNewInterface_All(DWORD Event);
	void EventNewInterface97_All(DWORD Event);
	void DrawCoord();
	void DrawCoordS4();
	void DrawInterfaceDragonLS3();
	void DrawInterfaceDragonRS3();

	//Custom Interface Type (S8)
	void		EventMenuButton(DWORD Event);
	void		DrawMenuButton();
	void		DrawInterfaceS8AG();
	void		DrawInterfaceCustom();
	void		BarPartyNew();

	int			ConfirmSlot;
	InterfaceObject Data[MAX_OBJECT];

	//PING:
	int			iniciador;
	int			msPing;
	int			lastSend;
	int			pingCheck;
	int			validar;
	char		ServerPing[20];
	char		ServerPingRTT[20];
	char		ultimoping[30];
	int			ultimo_ping;
	void		DrawPing();
	void		SendPingRecv();

	//FPS:
	int		lastReport;
	int		frameCount;
	int		frameRate;
	char		FPS_REAL[30];
	void		UPDATE_FPS();

	//Interfaz Barra Negra
	void		guiMonitore();

	// Advanced Stats
	bool		WindowEx[MAX_WINDOW_EX];
	bool		CheckWindowEx(int WindowID);
	void		DrawBarForm(float PosX,float PosY,float Width,float Height,GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);


	static void DrawItemIMG(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	static void DrawChat ( int mode, char* character, char* message );
	static void DrawItemToolTipText ( void * item, int x, int y );
    void * item_post_;
    DWORD last_tickcount_view_;

	void DrawWindow(int ObjMain, int ObjTitle, int ObjFrame, int ObjFooter, int Repeat, float X, float Y, char* Text);
	static void DrawItemIMGBank(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse); // code hien thi item
	bool		ButtonEx(DWORD Event, int ButtonID, bool Type);

	void		DrawInterfaceBloodCastle();

	void		DrawChaosBoxWindow();

	//antilag
	DWORD       MenuAntlagDelayClick;	
	int         testFunctionInvItem;
	int			testFunctionInvItem2;
	int			testFunctionInvItem3;
	int			testFunctionInvItem4;
	int			testFunctionInvItem5;
	int			testFunctionInvItem6;
	int			testFunctionInvItem7;
	int			testFunctionInvItem8;
	void		OpenOpMenuAntiLag() { this->Data[eOpMenu_MAINKG].OnShow = true; pSetCursorFocus = true; };
	void		CloseOpMenuAntiLag() { this->Data[eOpMenu_MAINKG].OnShow = false; pSetCursorFocus = false; };
	bool		CheckOpMenuAntiLag() { return this->Data[eOpMenu_MAINKG].OnShow; };
	void        DrawOpAntiLag();
	bool		EventUsersPanelAntiLag(DWORD Event);
	bool		EventUsersPanelAntiLag_GLOW(DWORD Event); //glow dos itens
	bool		EventUsersPanelAntiLag_TRANSPARENCE(DWORD Event); //transparence dos itens
	bool		EventUsersPanelAntiLag_INVISIBLY(DWORD Event); //invisibilidade
	bool		EventUsersPanelAntiLag_INVISIBLYWINGS(DWORD Event); //invisibilidade
	bool		EventUsersPanelAntiLag_INVISIBLYWEAPONS(DWORD Event); //invisibilidade
	bool		EventUsersPanelAntiLag_EFFECTDYNAMIC(DWORD Event); //dynamic
	bool        EventUsersPanelAntiLag_EFFECTSTATIC(DWORD Event);
	bool		EventUsersPanelAntiLag_EFFECT15(DWORD Event);
	bool		EventUsersPanelAntiLag_OBJECTS(DWORD Event);
	bool		EventUsersPanelAntiLag_CLOSE(DWORD Event);

	void        BetellHost();

	void		DrawInterfaceBemVindo();
	bool		DrawInterfaceBemVindo_Main(DWORD Event);
	bool		DrawInterfaceBemVindo_Button1(DWORD Event);
	void		OpenBemVindoWindow(){this->Data[eBEMVINDO_MAIN].OnShow=true;pSetCursorFocus=true;};
	void		CloseBemVindoWindow(){this->Data[eBEMVINDO_MAIN].OnShow=false;pSetCursorFocus=false;};
	bool		CheckBemVindoWindow(){return this->Data[eBEMVINDO_MAIN].OnShow;};

private:
	
};
extern Interface gInterface;
