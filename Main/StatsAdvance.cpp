#include "stdafx.h"
#include "protocol.h"
#include "Interface.h"
#include "StatsAdvance.h"
#include "Defines.h"
#include "Protect.h"

CStatsAdvance g_StatsAdvance;

CStatsAdvance::CStatsAdvance()
{
	this->m_Enable = false;
	this->m_Loaded = false;

	memset(&this->m_Data, 0, sizeof(this->m_Data));
}

CStatsAdvance::~CStatsAdvance()
{
}

void CStatsAdvance::Bind()
{
	// largura , altura
	gInterface.BindObject(eADVANCE_STAT_INFO, ex_INFO_2, 36, 27, -1, -1);
}

void CStatsAdvance::Load()
{
	this->m_Enable = true;
}

void CStatsAdvance::DrawInfo()
{
	if (!this->m_Enable && !this->m_Loaded)
	{
		return;
	}

	if (!gInterface.CheckWindow(ObjWindow::Character))
	{
		return;
	}


	//-> Custom Interface Type (S8)
	if(gProtect.m_MainInfo.CustomInterfaceType == 4 || gProtect.m_MainInfo.CustomInterfaceType == 5 || gProtect.m_MainInfo.CustomInterfaceType == 6)
	{
		pLoadImage("Custom\\Interface\\S8\\info_block.tga", ex_INFO_2, 0x2601, 0x2900, 1, 0);
	}
	else
	{
		pLoadImage("Custom\\Interface\\info_block.tga", ex_INFO_2, 0x2601, 0x2900, 1, 0);
	}

	DWORD dwColor = eWhite;
	//POSITION HORIZONTAL ICONE
	float flDrawX = this->m_CharX + 583;	//450;
	//POSITION VERTICAL ICONE
	float flDrawY = this->m_CharY + 83;	//18;

	gInterface.DrawGUI(eADVANCE_STAT_INFO, flDrawX, flDrawY);

	if (!gInterface.IsWorkZone(eADVANCE_STAT_INFO))
	{
		return;
	}


	//POSITION DO ADVANCED STATS FORA...
	flDrawX = this->m_CharX + 450;	// - 15;
	flDrawY = 0;//this->m_CharY - 52;	//18;

	float flWidth = 190;
	float flHight = 430;

	// POSITION DENTRO DO ADVANCED STATS
	gInterface.DrawBarForm(flDrawX, flDrawY, flWidth, flHight, 0, 0, 0, 150);
	flDrawY += 7;

	///////
	gInterface.DrawFormat(eGold, flDrawX, flDrawY, flWidth, 3, "ADVANCED STATUS");
	flDrawY += 14;
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Level (ML): %d (%d)",this->m_Data.MasterLevel,this->m_Data.Reset);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Reset (MR): %d (%d)", this->m_Data.GrandReset,this->m_Data.Defense);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Total Damage Reflect: %d%%", this->m_Data.TotalDamageReflect);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Full Damage Reflect Rate: %d%%", this->m_Data.FullDamageReflectRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Critical Damage Rate: %d%%", this->m_Data.CriticalDamageRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Critical Damage: %d", this->m_Data.CriticalDamagePower);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Exellent Damage Rate: %d%%", this->m_Data.ExellentDamageRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Exellent Damage: %d", this->m_Data.ExellentDamagePower);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Double Damage Rate: %d%%", this->m_Data.DoubleDamageRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Triple Damage Rate: %d%%", this->m_Data.TripleDamageRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Damage Reduction Rate: %d%%", this->m_Data.DamageReductionRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Shield Skill Damage Reduction Rate: %d%%", this->m_Data.ShieldSkillDamageReductionRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "SD Damage Reduction Rate: %d%%", this->m_Data.SDDamageReductionRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "SD Decrease Damage Rate (Target): %d%%", this->m_Data.SDDecreaseDamageRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Ignore Defense Rate: %d%%", this->m_Data.IgnoreDefenceRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Ignore SD Rate: %d%%", this->m_Data.IgnoreSDRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Increase Damage PvP: %d", this->m_Data.IncreaseDamagePvP);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Increase Defense PvP: %d", this->m_Data.IncreaseDefencePvP);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Critical Damage Rate: %d%%", this->m_Data.ResistCriticalDamageRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Excellent Damage Rate: %d%%", this->m_Data.ResistExellentDamageRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Double Damage Rate: %d%%", this->m_Data.ResistDoubleDamageRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Ignore Defense Rate: %d%%", this->m_Data.ResistIgnoreDefenceRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Ignore SD Rate: %d%%", this->m_Data.ResistIgnoreSDRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Stun Rate: %d%%", this->m_Data.ResistStumRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Ice: %d", this->m_Data.ResistIce);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Poison: %d", this->m_Data.ResistPoison);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Lighting: %d", this->m_Data.ResistLighting);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Fire: %d", this->m_Data.ResistFire);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Earth: %d", this->m_Data.ResistEarth);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Wind: %d", this->m_Data.ResistWind);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Water: %d", this->m_Data.ResistWater);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Full HP Restore Rate: %d%%", this->m_Data.FullHPRestoreRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Full MP Restore Rate: %d%%", this->m_Data.FullMPRestoreRate);
	flDrawY = this->DrawLine(flDrawX, flDrawY, flWidth, "Full SD Restore Rate: %d%%", this->m_Data.FullSDRestoreRate);

pSetBlend(false);

}

float CStatsAdvance::DrawLine(float PosX, float PosY, int Width, LPCSTR Text, ...)
{
	float flResult = 0.0;
	DWORD dwColor = eWhite;

	char szBuff[256];
	int iBuffLen = sizeof(szBuff) - 1;
	ZeroMemory(szBuff, iBuffLen);

	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(szBuff, iBuffLen, Text, args);
	va_end(args);

	pDrawColorText(szBuff, PosX, PosY, Width, 0, dwColor, 0, 3);

	pDrawColorButton(eRed, PosX + 10, PosY + 10, Width - 20, 0.6, NULL, NULL, eRed);

	flResult = PosY + 12;

	return flResult;
}

void CStatsAdvance::Button(DWORD Event)
{
	if (!gInterface.CheckWindowEx(ObjWindowsEx::exWinStatsAdvance))
	{
		//return;
	}
}

void CStatsAdvance::Recv(PMSG_STATS_ADVANCE* lpMsg)
{
	if (!lpMsg->Result)
	{
		return;
	}

	memcpy(&this->m_Data, &lpMsg->StatInfo, sizeof(this->m_Data));

	this->m_Loaded = true;
}

void CStatsAdvance::Send()
{

}