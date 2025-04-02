#pragma once
#include "Object.h"
#include "Protocol.h"

struct BANKEX_USER_DATA
{
	long Money;
	long Bless;
	long Soul;
	long Chaos;
	long Creation;
	long Life;
	long Harmony;
	long Guardian;
	long Gemstone;
	long LowRefine;
	long HigRefine;
	long JCustomJ1;
	long JCustomJ2;
	long JCustomJ3;
	long JCustomJ4;
	long JCustomJ5;
	long JCustomJ6;
	long JCustomJ7;
	long JCustomJ8;
	long JCustomJ9;
	long JCustomJ10;
	long JCustomJ11;

};

#pragma pack(push, 1)
struct PMSG_TARGETDATA_REQ
{
	PSWMSG_HEAD header;
	int			aIndex;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGETDATA_ANS
{
	PSWMSG_HEAD header;
	int aIndex;
    bool isMonster;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGET_MONSTER_DATA : PMSG_TARGETDATA_ANS
{
    int Life;
    int MaxLife;
    short Level;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGET_PLAYER_DATA : PMSG_TARGET_MONSTER_DATA
{
    int SD;
    int MaxSD;
    short Reset;
	short RankTitle;
	short Long;
};
#pragma pack(pop)

struct CUSTOM_LOGO
{
	int Active;
	int	X;
	int	Y;
};

class User
{
public:
	int		CoordenadaX;
	int		CoordenadaY;
	void		Load();
	void		Refresh();	
	bool		GetTarget();
	lpCharObj	lpPlayer;
	lpViewObj	lpViewPlayer;
	lpViewObj	lpViewTarget;
	BYTE		m_TargetType;	//1 - npc, 2 - attack
	int			m_MapNumber;
	int			m_CursorX;
	int			MagickAttack;
	int			m_CursorY;
	DWORD		m_TargetUpdateTick;
	static void	AllInOne();
	void DrawHP();
	void DrawRank();
	void SetTargetData(PMSG_TARGETDATA_ANS * lpMsg);
	int GetActiveSkill();
	static void	SetEventEffect(int PreviewStruct);
	CUSTOM_LOGO m_Logo[400];
	int				PostItemID;
	int				PostItemLV;
	int				PostItemExc;
	int				PostItemAcc;
	int				PostItemX;
	int				PostItemY;

	//jewelbank
	BANKEX_USER_DATA BankEx;
};
extern User gObjUser;