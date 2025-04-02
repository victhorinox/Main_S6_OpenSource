#include "StdAfx.h"
#include "ChatExpanded.h"
#include "Import.h"
#include "TMemory.h"
#include <atlstr.h>
#include "ToolKit.h"
#include "Defines.h"
// ----------------------------------------------------------------------------------------------

CChatExpanded	CgChatExpanded;
// ----------------------------------------------------------------------------------------------

Naked(CFixSysMsg1)
{
	__asm
	{
		cmp dword ptr ss:[ebp+0x10], 3
		je _true
		call NewCall
		jmp FixSysMsg1_FALSE
		_true:
		pop eax
		jmp FixSysMsg1_TRUE
	}
}
// ----------------------------------------------------------------------------------------------

Naked(CFixSysMsg2)
{
	__asm 
	{
		cmp dword ptr ss:[ebp+0x10], 3
		je _true
		call NewCall
		jmp FixSysMsg2_FALSE
		_true:
		pop eax
		jmp FixSysMsg2_TRUE
	}
}
// ----------------------------------------------------------------------------------------------

Naked(CFixSysMsg3)
{
	__asm 
	{
		cmp dword ptr ss:[ebp+0x10], 3
		je _true
		call NewCall
		jmp FixSysMsg3_FALSE
		_true:
		pop eax
		jmp FixSysMsg3_TRUE
	}
}
// ----------------------------------------------------------------------------------------------

void CChatExpanded::Load()
{
	this->IsActive = true;
	SetOp((LPVOID)oShowChatMessage_Call, (LPVOID)this->ShowChatMessage, ASM::CALL);
	SetOp((LPVOID)FixSysMsg1_Hook, CFixSysMsg1, ASM::JMP);
	SetOp((LPVOID)FixSysMsg2_Hook, CFixSysMsg2, ASM::JMP);
	SetOp((LPVOID)FixSysMsg3_Hook, CFixSysMsg3, ASM::JMP);
}
// ----------------------------------------------------------------------------------------------

void CChatExpanded::SetInstance(LPVOID Instance)
{
	this->Instance			= Instance;
	this->PosYBuff			= this->GetPosY();
	this->HeightBuff		= this->GetHeight();
	this->MessageCountBuff	= this->GetMessageCount();
	this->MessageTypeBuff	= this->GetMessageType();
	this->ScrollPosBuff		= this->GetScrollPos();
}
// ----------------------------------------------------------------------------------------------

void CChatExpanded::Restore()
{
	this->SetPosY(this->PosYBuff);
	this->SetHeight(this->HeightBuff);
	this->SetMessageCount(this->MessageCountBuff);
	this->SetMessageType(this->MessageTypeBuff);
	this->SetScrollPos(this->ScrollPosBuff);
}
// ----------------------------------------------------------------------------------------------

void CChatExpanded::Switch()
{
	if( !CgChatExpanded.IsActive )
	{
		SetOp((LPVOID)FixSysMsg1_Hook, CFixSysMsg1, ASM::JMP);
		SetOp((LPVOID)FixSysMsg2_Hook, CFixSysMsg2, ASM::JMP);
		SetOp((LPVOID)FixSysMsg3_Hook, CFixSysMsg3, ASM::JMP);
		CgChatExpanded.IsActive = true;
	}
	else
	{
		SetOp((LPVOID)FixSysMsg1_Hook, (LPVOID)oNewCall, ASM::CALL);
		SetOp((LPVOID)FixSysMsg2_Hook, (LPVOID)oNewCall, ASM::CALL);
		SetOp((LPVOID)FixSysMsg3_Hook, (LPVOID)oNewCall, ASM::CALL);
		CgChatExpanded.IsActive = false;
	}
}
// ----------------------------------------------------------------------------------------------

bool CChatExpanded::ShowChatMessage(LPVOID This, LPVOID EDX)
{
	if( !CgChatExpanded.IsActive )
	{
		return pShowChatMessage(This);
	}
	// ----
	CgChatExpanded.SetInstance(This);
	CgChatExpanded.SetPosY(172);
	CgChatExpanded.SetHeight(100);
	CgChatExpanded.SetMessageCount(4);
	pSetChatMessageType(This, 3);
	pShowChatMessage(This);
	CgChatExpanded.Restore();
	return pShowChatMessage(This);
}
// ----------------------------------------------------------------------------------------------