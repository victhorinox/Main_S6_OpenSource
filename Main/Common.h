#pragma once

void InitCommon();
BOOL CheckIsLuckyItem(int ItemID);
BOOL CheckGensBattleMap(int map);
BOOL CheckGensMoveIndex(int idx);
void LoginTab();
void CheckMasterLevel();
void CompareGensMoveIndex();
void DrawEffectsPic(int &EffectID, float StartX, float StartY, float StartWidth, float StartHeight );
void Copyright();

extern BYTE GensBattleMapCount;
extern BYTE GensMoveIndexCount;
extern BYTE GensBattleMap[120];
extern BYTE GensMoveIndex[120];

extern int DisableStaticEffect;
extern int DisableDynamicEffect;
extern int DisableSkillEffect;
extern int DisableGlowEffect;
extern int Anisotropy;
extern int MaxAnisotropy;
extern int Linear;
extern int GMT;
extern int Fog;
extern int Tron;
extern int MiniMap;
extern int offhelper;
extern int upgradeActiveChat;

static void RotateDmg(float& X, float& Y, float D);
static void RotateFix();

char FixHelperMouseClickC(int a1);
char FixHelperMouseClick(int a1);

void FixEffectCitys();

#define pSetPlayerStop						((int(__cdecl*)(lpViewObj lpObj)) 0x0054EA80)
#define SetCharacterScale		((int(__cdecl*)(int index)) 0x0057F020)
#define pGetClassModel			((char(__cdecl*)(BYTE))0x00587500)
