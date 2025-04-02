#include "stdafx.h"
#include "TMemory.h"
#include "Util.h"
#include "Offset.h"
#include "CChatEx.h"
#include "ChatExpanded.h"
#include "Common.h"
#include "WindowsStruct.h"
#include "Defines.h"

CNewUIChat gCChatEx;

void CNewUIChat::LoadImages()
{
	((void(__cdecl*)())0x00785650)();
}

static DWORD chatReader = 0;
bool tecla;

void CNewUIChat::RenderFrame(int This)
{	
	gCChatEx.Hide1Teste();

	if(gInterface.CheckWindow(ChatWindow) && pCursorX > 0 && pCursorX < 19 && pCursorY > 380 && pCursorY < 400)
	{
		pSetCursorFocus = true;
	}
	else
	{
		pSetCursorFocus = false;
	}

	int Button;
	RenderBitmap(51529, 16, 371, 250, 47, 0, 0, 1.0, 0.73, 1, 1, 0.0);

	if(tecla == false)
	{
		RenderBitmap(51541, 16, 371, 250, 47, 0, 0, 1.0, 0.73, 1, 1, 0.0);
		Button = 51542;
	}
	else
	{
		RenderBitmap(51522, 16, 371, 250, 47, 0, 0, 1.0, 0.73, 1, 1, 0.0);
		Button = 51544;
	}

	gInterface.DrawButton(ButtonHideChat, 1, 382 , 0.0, 0.0);

	if(pCursorX > 2 && pCursorX < 17 && pCursorY > 382 && pCursorY < 398 && tecla == false)
	{
		Button = 51543;
	}
	if(pCursorX > 2 && pCursorX < 17 && pCursorY > 382 && pCursorY < 398 && (GetKeyState(VK_LBUTTON) & 0x100) != 0)
	{
		Button = 51544;
		PlayBuffer(25, 0, 0);
		keybd_event(VK_LBUTTON, 0, KEYEVENTF_KEYUP, 0);

		if(tecla == false)
		{
			tecla = true;
		}
		else
		{
			tecla = false;
		}
	}

	RenderBitmap(Button, 1, 382, 15, 15, 0, 0, 0.92, 0.92, 1, 1, 0.0);
}

void CNewUIChat::RenderButtons01(DWORD a1, float a2, float a3, float a4, float a5)
{
	if(tecla == false)
	{
		if(pWinWidth <= 800)
		{
		    RenderBitmap(a1 + 20250, a2 + 1.5, a3 + 12.0, 27.5, 14.0, 0, 0, 0.8700000048, 0.9, 1, 1, 0.0);
		    gInterface.DrawFormat(CGris, 17, 385, 27.5, 3, "All");
		    gInterface.DrawFormat(CGris, 44, 385, 27.5, 3, "Party");
		    gInterface.DrawFormat(CGris, 71, 385, 27.5, 3, "Guild");
		    gInterface.DrawFormat(CGris, 98, 385, 27.5, 3, "Gens");
		    gInterface.DrawFormat(CGris, 126.5, 385, 27.5, 3, "Whisp");
		    gInterface.DrawFormat(CGris, 154, 385, 27.5, 3, "Sys");
		    gInterface.DrawFormat(CGris, 180, 385, 27.5, 3, "Chat");
		}
		if(pWinWidth > 800)
		{
		    RenderBitmap(a1 + 20250, a2 + 1.5, a3 + 12.0, 27.5, 14.0, 0, 0, 0.8700000048, 0.9, 1, 1, 0.0);
		    gInterface.DrawFormat(CGris, 17, 385, 27.5, 3, "General");
		    gInterface.DrawFormat(CGris, 45, 385, 27.5, 3, "Party");
		    gInterface.DrawFormat(CGris, 71, 385, 27.5, 3, "Guild");
		    gInterface.DrawFormat(CGris, 99, 385, 27.5, 3, "Gens");
		    gInterface.DrawFormat(CGris, 126.5, 385, 27.5, 3, "Whisper");
		    gInterface.DrawFormat(CGris, 154, 385, 27.5, 3, "System");
		    gInterface.DrawFormat(CGris, 180.5, 385, 27.5, 3, "Chatting");
		}
	}
	else
	{
		//None
	}
}

void CNewUIChat::RenderButtons02(DWORD a1, float a2, float a3, float a4, float a5)
{		
	if(tecla == false)
	{
		if(pWinWidth <= 800)
		{
		    RenderBitmap(a1 + 20246, a2 - 3.0, a3 + 12.0, 27.5, 14.0, 0, 0, 0.8700000048, 0.9, 1, 1, 0.0);
		    gInterface.DrawFormat(CGris, 126.5, 385, 27.5, 3, "Whisp");
		}
		if(pWinWidth > 800)
		{
		    RenderBitmap(a1 + 20246, a2 - 3.0, a3 + 12.0, 27.5, 14.0, 0, 0, 0.8700000048, 0.9, 1, 1, 0.0);
		    gInterface.DrawFormat(CGris, 126.5, 385, 27.5, 3, "Whisper");
		}
	}
	else
	{
		//None
	}
}

void CNewUIChat::RenderButtons03(DWORD a1, float a2, float a3, float a4, float a5)
{
	if(tecla == false)
	{
		if(pWinWidth <= 800)
		{
		    RenderBitmap(a1 + 20244, a2 - 3.0, a3 + 12.0, 27.5, 14.0, 0, 0, 0.8700000048, 0.9, 1, 1, 0.0);	
		    gInterface.DrawFormat(CGris, 180, 385, 27.5, 3, "Chat");	
		}
		if(pWinWidth > 800)
		{
    		RenderBitmap(a1 + 20244, a2 - 3.0, a3 + 12.0, 27.5, 14.0, 0, 0, 0.8700000048, 0.9, 1, 1, 0.0);	
	    	gInterface.DrawFormat(CGris, 180.5, 385, 27.5, 3, "Chatting");	
		}
	}
	else
	{
		//None
	}
}

void CNewUIChat::RenderButtons04(DWORD a1, float a2, float a3, float a4, float a5)
{	
	if(tecla == false)
	{
		if(pWinWidth <= 800)
		{
		    RenderBitmap(a1 + 20245, a2 - 3.0, a3 + 12.0, 27.5, 14.0, 0, 0, 0.8700000048, 0.9, 1, 1, 0.0);
		    gInterface.DrawFormat(CGris, 154, 385, 27.5, 3, "Sys");
		    gInterface.DrawFormat(CGris, 180, 385, 27.5, 3, "Chat");
		}
		if(pWinWidth > 800)
		{
		    RenderBitmap(a1 + 20245, a2 - 3.0, a3 + 12.0, 27.5, 14.0, 0, 0, 0.8700000048, 0.9, 1, 1, 0.0);
		    gInterface.DrawFormat(CGris, 154, 385, 27.5, 3, "System");
	    	gInterface.DrawFormat(CGris, 180.5, 385, 27.5, 3, "Chatting");
		}
	}
	else
	{
		//None
	}
}

void CNewUIChat::RenderButtons05(DWORD a1, float a2, float a3, float a4, float a5)
{
	if(tecla == false)
	{
	    RenderBitmap(a1 + 20251, a2 - 1.5, a3 + 12.0, 16.0, 14.0, 0, 0, 1.0, 0.9, 1, 1, 0.0);
	    //RenderBitmap(51900, 16, 371, 250, 47, 0, 0, 1.0, 0.73, 1, 1, 0.0);
	}
	else
	{
        //None
	}
}

__declspec(naked) void RenderButtons06()
{
	static DWORD RenderButtons06_buff = 0x00785CD2;
	static DWORD CALL01  = 0x00779350;
	static DWORD CALL02  = 0x00779410;
	_asm
	{	
		PUSH EBP
		MOV EBP,ESP
		PUSH ECX
		MOV DWORD PTR SS:[EBP-0x4],ECX
		PUSH 0
		PUSH 0
		PUSH 0
		PUSH 51539//<<ID Textura
		PUSH 1
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		ADD ECX,0x78
		CALL CALL01
		PUSH 15//<<Alto Textura
		PUSH 16//<<Ancho Textura
		MOV EAX,DWORD PTR SS:[EBP-0x4]
		MOV ECX,DWORD PTR DS:[EAX+0x18]
		ADD ECX,12//<<Y
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x4]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX,214//<<X
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		ADD ECX,0x78
		CALL CALL02
		PUSH 0
		PUSH 0
		PUSH 0
		PUSH 51540//<<ID Textura
		PUSH 1
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		ADD ECX,0x124
		CALL CALL01
		PUSH 15//<<Alto Textura
		PUSH 16//<<Ancho Textura
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		MOV EDX,DWORD PTR DS:[ECX+0x18]
		ADD EDX,12//<<Y
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x4]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		ADD ECX,230//<<X
		PUSH ECX
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		ADD ECX,0x124
		CALL CALL02
		jmp [RenderButtons06_buff]
	}
}

void CNewUIChat::ButtonHide01()
{	
	int Button;
	Button = 51542;

	gInterface.DrawButton(ButtonHideChat, 1, 382 , 0.0, 0.0);

	if (gInterface.IsWorkZone(ButtonHideChat))
	{
		Button = 51543;
	}

	if (gInterface.Data[ButtonHideChat].OnClick)
	{
		Button = 51544;
		PlayBuffer(25, 0, 0);	
	}

	RenderBitmap(Button, 1, 382, 15, 15, 0, 0, 0.92, 0.92, 1, 1, 0.0);
}

bool CNewUIChat::ButtonHide02(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	
	if(*(DWORD*)(MAIN_SCREEN_STATE) != ObjState::GameProcess)
	{
		return false;
	}
	
	if( gInterface.IsWorkZone(ButtonHideChat) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[ButtonHideChat].EventTick);
		
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[ButtonHideChat].OnClick = true;
			return true;
		}
		
		gInterface.Data[ButtonHideChat].OnClick = false;
		
		if( Delay < 500 )
		{
			return false;
		}

		gInterface.Data[ButtonHideChat].EventTick = GetTickCount();
	}
}

void CNewUIChat::Hide1Teste()
{
	if(tecla == false)
	{
		SetByte(0x00786150, 0x55);
	}
	else
	{
		SetByte(0x00786150, 0xC3);
	}
}


char ChatWindowsDraw(MUChat * This)
{
	This->WindowPosY = 378;
	if(This->WindowsActivo)
	{
		chatReader = 10;
		pSetBlend(true);
		glColor4f(1.0, 1.0, 1.0, This->AlphaColor);

		if(This->WindowHeight == 55)
		{
			//pDrawButton(51545, This->WindowPosX, 323.0f,(float) This->WindowWidth, 55.0f, 0, 0);
			pDrawButton(51545, This->WindowPosX, 323.0f,260.0f, 55.0f, 0, 0);
		}
		if(This->WindowHeight == 100)
		{
			//pDrawButton(51545, This->WindowPosX, 278.0f,(float) This->WindowWidth, 100.0f, 0, 0);
			pDrawButton(51545, This->WindowPosX, 278.0f,260.0f, 100.0f, 0, 0);
		}
		if(This->WindowHeight == 145)
		{
			//pDrawButton(51545, This->WindowPosX, 233.0f,(float) This->WindowWidth, 145.0f, 0, 0);
			pDrawButton(51545, This->WindowPosX, 233.0f,260.0f, 145.0f, 0, 0);
		}
		if(This->WindowHeight == 190)
		{
			//pDrawButton(51545, This->WindowPosX, 188.0f,(float) This->WindowWidth, 190.0f, 0, 0);
			 pDrawButton(51545, This->WindowPosX, 188.0f,260.0f, 190.0f, 0, 0);
		}
		if(This->WindowHeight == 235)
		{
			//pDrawButton(51545, This->WindowPosX, 143.0f,(float) This->WindowWidth, 235.0f, 0, 0);	
			 pDrawButton(51545, This->WindowPosX, 143.0f,260.0f, 235.0f, 0, 0);
		}
		pGLSwitchBlend();
		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
		pSetBlend(false);
	}
	else
	{
		if(upgradeActiveChat == 1)
		{
			chatReader = 10;
		    pSetBlend(true);
		    glColor4f(1.0, 1.0, 1.0, This->AlphaColor);
		    if(This->WindowHeight == 55)
			{
		    	pDrawButton(51545, This->WindowPosX, 323.0f,260.0f, 55.0f, 0, 0);
		    }
		    if(This->WindowHeight == 100)
			{
		    	pDrawButton(51545, This->WindowPosX, 278.0f,260.0f, 100.0f, 0, 0);
		    }
		    if(This->WindowHeight == 145)
			{
		    	pDrawButton(51545, This->WindowPosX, 233.0f,260.0f, 145.0f, 0, 0);
		    }
		    if(This->WindowHeight == 190)
			{
			    pDrawButton(51545, This->WindowPosX, 188.0f,260.0f, 190.0f, 0, 0);
		    }
		    if(This->WindowHeight == 235)
			{
			    pDrawButton(51545, This->WindowPosX, 143.0f,260.0f, 235.0f, 0, 0);	
		    }
		    pGLSwitchBlend();
		    pGLSwitch();
		    glColor3f(1.0, 1.0, 1.0);
		    pSetBlend(false);
	    }
		else
		{
			chatReader = 0;
		}
	}
	return 1;
}

char RenderFrameChat(MUChat* This)
{
	float v4; // ST30_4@5
	float v5; // ST2C_4@5
	float v6; // ST28_4@5
	float v7; // ST20_4@7
	int i; // [sp+38h] [bp-Ch]@5
	float v16; // [sp+3Ch] [bp-8h]@2

	if(This->WindowsActivo)
	{
		v16 = (double)(This->WindowPosY - This->WindowHeight);
		v4 = v16 - 15.0;
		pSetBlend(true);
		glColor4f(1.0, 1.0, 1.0, 0.8);
		pDrawGUI(31275, (float)This->WindowPosX-21.0f, v4, (float)This->WindowWidth, 15.0f);
		pGLSwitchBlend();
		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
		pSetBlend(false);
	}

	return 1;
}

_declspec(naked) void WisperBarSizeMove()
{
	static float D2B828 = 17.00000;
	static float D4383C = 47.00000;
	static DWORD WhisperTxt_buf2f = 0x00787744;

	_asm
	{
		FLD DWORD PTR DS:[D2B828] 
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLD DWORD PTR DS:[D4383C] 
		FSTP DWORD PTR SS:[ESP]
		MOV ECX,DWORD PTR SS:[EBP-0x24]
		MOV EDX,DWORD PTR DS:[ECX+0x18]
		ADD EDX,0x1C
		MOV DWORD PTR SS:[EBP-0x28],EDX
		FILD DWORD PTR SS:[EBP-0x28]
		PUSH ECX
		FSTP DWORD PTR SS:[ESP]
		MOV EAX,DWORD PTR SS:[EBP-0x24]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		ADD ECX,2
		MOV DWORD PTR SS:[EBP-0x2C],ECX
		FILD DWORD PTR SS:[EBP-0x2C]
		JMP [WhisperTxt_buf2f]
	}
}

int RenderNotices()
{
	int result; // eax@1
	if ( pPlayerState == 5 )
	{
		result = (unsigned __int8)pCheckWindow((int *)GetInstance(), 65);
		if ( (unsigned __int8)result != 1 )
		{
			EnableAlphaTest(1);
			pSetTextSize(pTextThis(), (HFONT)pFontBold);
			glColor3f(1.0, 1.0, 1.0);
			for (signed int i = 0; i < 6; ++i )
			{
				if ( *((_BYTE *)0x813DDD0 + 264 * i + 260) )
				{
					pSetTextColor(pTextThis(), 0x64u, 0xFFu, 0xC8u, 0xFFu);
					pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x80u);
				}
				else
				{
					pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x80u);
					if ( NoticeInverse % 10 >= 5 )
					{
						pSetTextColor(pTextThis(), 0xFFu, 0xC8u, 0x50u, 0xFFu);
					}
					else
					{
						pSetTextColor(pTextThis(), 0xFFu, 0xC8u, 0x50u, 0x80u);
					}
				}
				pDrawText(pTextThis(), 320, 13 * i + 200, (LPCTSTR)0x813DDD0 + 264 * i, 0, 0, (LPINT)8, 0);
			}
			NoticeInverse == NoticeInverse + 1;
			result = NoticeInverse + 1;
		}
		return result;
	}
}

void CNewUIChat::Load()
{
	//SetCompleteHook(0xE8, 0x004D5EC3, &RenderNotices);

	SetCompleteHook(0xE8,0x0078B0CF,&RenderFrameChat);
	SetCompleteHook(0xE9,0x0078770E,&WisperBarSizeMove);
	SetCompleteHook(0xE8,0x0078B09A,&ChatWindowsDraw);

	gInterface.BindObject(ButtonHideChat, 51522, 15, 15, -1, -1);

	SetDword((PVOID)(0x0085A426), 370);//<-PosicionY del Chat_Back
	SetByte((PVOID)(0x0085A42B), 15);//<-PosicionX del Chat_Back
	SetByte((PVOID)(0x00785965), 54);//<-PosicionX del Texto Chat

	SetCompleteHook(0xE8, 0x00785B32,this->LoadImages);
	SetCompleteHook(0xE8, 0x00787620,this->RenderFrame);
	SetCompleteHook(0xE8, 0x007877FE,this->RenderButtons01);
	SetCompleteHook(0xE8, 0x00787847,this->RenderButtons02);
	SetCompleteHook(0xE8, 0x00787893,this->RenderButtons03);
	SetCompleteHook(0xE8, 0x007878DE,this->RenderButtons04);
	SetCompleteHook(0xE8, 0x00787931,this->RenderButtons05);
	SetByte((PVOID)(0x0078649D+1), 16);//<-AnchoBotonChat_ButtonWBack
	SetOp((LPVOID)0x00785C50, (LPVOID)RenderButtons06, ASM::JMP);
	//MemorySet(0x007877B0, 0x90, 0x1A9);//Elimina lso botones
	MemorySet(0x00787630, 0x90, 0x5);//Elimina el Texto arriba de lso botones

	//----------------------------------------------------------------------------------
	//-> Textures
	//----------------------------------------------------------------------------------

	//m_b_ok1.tga
	SetDword(0x0088E6CA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\m_b_ok1.tga");

	//m_b_ok2.tga
	SetDword(0x0088E6EA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\m_b_ok2.tga");
	
	//m_b_ok3.tga
	SetDword(0x0088E70A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\m_b_ok3.tga");

	//newui_button_ok.tga
	SetDword(0x00824F5A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\message_ok_b_all.tga");
	
	//loding_cancel_b_all.tga
	SetDword(0x00633327+1,(DWORD)"Custom\\Interface\\S8\\Menu\\loding_cancel_b_all.tga");

	//newui_button_cancel.tga
	SetDword(0x00824F7A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_button_cancel.tga");
	
	//message_ok_b_all.tga
	SetDword(0x00633307+1,(DWORD)"Custom\\Interface\\S8\\Menu\\message_ok_b_all.tga");
	
	//message_close_b_all.tga
	SetDword(0x00633347+1,(DWORD)"Custom\\Interface\\S8\\Menu\\message_close_b_all.tga");

	//b_create.tga
	SetDword(0x00631359+1,(DWORD)"Custom\\Interface\\S8\\Menu\\b_create.tga");

	//server_menu_b_all.tga
	SetDword(0x00631156+1,(DWORD)"Custom\\Interface\\S8\\Menu\\server_menu_b_all.tga");
	SetDword(0x00631379+1,(DWORD)"Custom\\Interface\\S8\\Menu\\server_menu_b_all.tga");

	//b_connect.tga
	SetDword(0x00631399+1,(DWORD)"Custom\\Interface\\S8\\Menu\\b_connect.tga");

	//b_delete.tga
	SetDword(0x006313B9+1,(DWORD)"Custom\\Interface\\S8\\Menu\\b_delete.tga");

	//Login_back.tga
	SetDword(0x006311B6+1,(DWORD)"Custom\\Interface\\S8\\Menu\\login_back.tga");
	
	//Login_me.tga
	SetDword(0x006311D6+1,(DWORD)"Custom\\Interface\\S8\\Menu\\Login_me.tga");
	
	//newui_btn_empty.tga
	SetDword(0x0078EDDA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty.tga");
	SetDword(0x007C2E7A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty.tga");
	SetDword(0x007C670A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty.tga");
	SetDword(0x007C672A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty.tga");
	SetDword(0x007C839A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty.tga");
	SetDword(0x007C83BA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty.tga");
	SetDword(0x007D0A7A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty.tga");
	SetDword(0x00824FBA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty.tga");
	SetDword(0x0084644A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty.tga");
	SetDword(0x0085101A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty.tga");
	SetDword(0x00852A2A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty.tga");
	SetDword(0x008804CA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty.tga");
	SetDword(0x00882D0A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty.tga");

	//newui_btn_empty_big
	SetDword(0x00824FFA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_big.tga");
	SetDword(0x0087518A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_big.tga");
	SetDword(0x00878CDA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_big.tga");

	//newui_btn_empty_small
	SetDword(0x007C2E5A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_small.tga");
	SetDword(0x007CDE8A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_small.tga");
	SetDword(0x007D0A9A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_small.tga");
	SetDword(0x00824FDA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_small.tga");
	SetDword(0x00854CEA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_small.tga");

	//newui_btn_empty_small
	SetDword(0x007C177A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_very_small.tga");
	SetDword(0x0082501A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_very_small.tga");
	SetDword(0x00867F3A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_very_small.tga");
	SetDword(0x0086D0EC+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_very_small.tga");
	SetDword(0x0087694A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_very_small.tga");
	SetDword(0x00879BEA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_very_small.tga");
	SetDword(0x0088116A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_very_small.tga");
	SetDword(0x0088428A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_very_small.tga");
	SetDword(0x0089300A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_very_small.tga");
	SetDword(0x0089413A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_btn_empty_very_small.tga");

	//newui_Bt_money01
	SetDword(0x00857EBA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_Bt_money01.tga");
	SetDword(0x008651EA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_Bt_money01.tga");

	//newui_Bt_money02
	SetDword(0x00857EDA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_Bt_money02.tga");

	//newui_Bt_lock
	SetDword(0x00857F1A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_Bt_lock.tga");

	//newui_Bt_lock
	SetDword(0x00857EFA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_Bt_lock02.tga");

	//newui_repair_00
	SetDword(0x00836D1A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_repair_00.tga");
	SetDword(0x0084753A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_repair_00.tga");

	//newui_expansion_btn
	SetDword(0x00836D3A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_expansion_btn.tga");

	//newui_SW_Minimap_Frame.tga
	SetDword(0x00888D7A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_SW_Minimap_Frame.tga");

	//op1_back1.tga
	SetDword(0x006333C7+1,(DWORD)"Custom\\Interface\\S8\\Menu\\op1_back1.tga");

	//op1_back2.tga
	SetDword(0x006333E7+1,(DWORD)"Custom\\Interface\\S8\\Menu\\op1_back2.tga");

	//op1_back3.tga
	SetDword(0x00633407+1,(DWORD)"Custom\\Interface\\S8\\Menu\\op1_back3.tga");

	//op1_back4.tga
	SetDword(0x00633427+1,(DWORD)"Custom\\Interface\\S8\\Menu\\op1_back4.tga");

	//op1_stone.jpg
	SetDword(0x006333A7+1,(DWORD)"Custom\\Interface\\S8\\Menu\\op1_stone.jpg");

	//op2_back1.tga
	SetDword(0x00633467+1,(DWORD)"Custom\\Interface\\S8\\Menu\\op2_back1.tga");

	//op2_ch.tga
	SetDword(0x00633487+1,(DWORD)"Custom\\Interface\\S8\\Menu\\op2_ch.tga");
	
	//op2_volume1.tga
	SetDword(0x006334E7+1,(DWORD)"Custom\\Interface\\S8\\Menu\\op2_volume1.tga");

	//op2_volume2.jpg
	SetDword(0x006334C7+1,(DWORD)"Custom\\Interface\\S8\\Menu\\op2_volume2.jpg");

	//op2_volume3.tga
	SetDword(0x006334A7+1,(DWORD)"Custom\\Interface\\S8\\Menu\\op2_volume3.tga");

	//mini_map_ui_cancel
	SetDword(0x0082A863+1,(DWORD)"Custom\\Interface\\S8\\Menu\\mini_map_ui_cancel.tga");
	
	//newui_Message_03
	SetDword(0x00824F1A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_Message_03.tga");
	
	//newui_msgbox_bottom.tga
	SetDword(0x0087690A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_bottom.tga");
	SetDword(0x0086D0AC+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_bottom.tga");
	SetDword(0x00824EBA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_bottom.tga");

	//newui_msgbox_middle.tga
	SetDword(0x008768EA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_middle.tga");
	SetDword(0x0086D08C+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_middle.tga");
	SetDword(0x00824E9A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_middle.tga");

	//newui_msgbox_top.tga
	SetDword(0x008768CA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_top.tga");
	SetDword(0x0086D06C+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_top.tga");
	SetDword(0x00824E7A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_top.tga");

	//newui_option_top
	SetDword(0x0095205A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_top.tga");
	SetDword(0x009512BA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_top.tga");
	SetDword(0x0094FB9A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_top.tga");
	SetDword(0x0094C59A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_top.tga");
	SetDword(0x0094BB0A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_top.tga");
	SetDword(0x0094846A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_top.tga");
	SetDword(0x008492AA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_top.tga");

	//newui_option_back06(R)
	SetDword(0x0095209A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_back06(R).tga");
	SetDword(0x009512FA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_back06(R).tga");
	SetDword(0x0094FBDA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_back06(R).tga");
	SetDword(0x0094C5DA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_back06(R).tga");
	SetDword(0x0094BB4A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_back06(R).tga");
	SetDword(0x009484AA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_back06(R).tga");
	SetDword(0x008492EA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_back06(R).tga");

	//newui_option_back06(L)
	SetDword(0x0095207A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_back06(L).tga");
	SetDword(0x009512DA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_back06(L).tga");
	SetDword(0x0094FBBA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_back06(L).tga");
	SetDword(0x0094C5BA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_back06(L).tga");
	SetDword(0x0094BB2A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_back06(L).tga");
	SetDword(0x0094848A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_back06(L).tga");
	SetDword(0x008492CA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_back06(L).tga");

	//newui_guild_tab01
	SetDword(0x007CDD8A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_guild_tab01.tga");

	//newui_guild_tab02
	SetDword(0x007CDDAA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_guild_tab02.tga");

	//newui_guild_tab03
	SetDword(0x007CDDCA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_guild_tab03.tga");

	//newui_guild_tab04
	SetDword(0x0088426A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_guild_tab04.tga");
	SetDword(0x00879BAA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_guild_tab04.tga");
	SetDword(0x0084E77A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_guild_tab04.tga");

	//newui_button_close
	SetDword(0x00824F9A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_button_close.tga");
	SetDword(0x0084924A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_button_close.tga");

	//newui_option_point
	SetDword(0x0084932A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_point.tga");

	//newui_option_check
	SetDword(0x0084934A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_option_check.tga");

	//Quest_Bt_open
	SetDword(0x0083E8BA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\Quest_Bt_open.tga");

	//Quest_tab01
	SetDword(0x0083E8FA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\Quest_tab01.tga");

	//Quest_tab02
	SetDword(0x0083E91A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\Quest_tab02.tga");
	
	//Quest_tab03
	SetDword(0x0083E93A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\Quest_tab03.tga");

	//Quest_Bt_cast
	SetDword(0x0083E8DA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\Quest_Bt_cast.tga");

	//newui_chainfo_btn_quest
	SetDword(0x00784F0A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_chainfo_btn_quest.tga");

	//newui_chainfo_btn_master
	SetDword(0x00784F4A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_chainfo_btn_master.tga");

	//newui_chainfo_btn_pet
	SetDword(0x00784F2A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_chainfo_btn_pet.tga");

	//newui_Box_openTitle
	SetDword(0x00840C6A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_Box_openTitle.tga");
	SetDword(0x0084F11A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_Box_openTitle.tga");

	//newui_cha_textbox02
	SetDword(0x00784ECA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_cha_textbox02.tga");

	//newui_chainfo_btn_level
	SetDword(0x00784EEA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_chainfo_btn_level.tga");

	//newui_item_add_table
	SetDword(0x007D541A+1,(DWORD)"Custom\\Interface\\null.tga");
	
	//newui_Message_Line
	SetDword(0x00824EFA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_Message_Line.tga");

	//newui_myquest_Line
	SetDword(0x0089415A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_myquest_Line.tga");
	SetDword(0x0089302A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_myquest_Line.tga");
	SetDword(0x00879BCA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_myquest_Line.tga");
	SetDword(0x00867F5A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_myquest_Line.tga");
	SetDword(0x0086518A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_myquest_Line.tga");
	SetDword(0x008529CA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_myquest_Line.tga");
	SetDword(0x00850FBA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_myquest_Line.tga");
	SetDword(0x0084640A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_myquest_Line.tga");
	SetDword(0x00843ECA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_myquest_Line.tga");
	SetDword(0x0083E89A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_myquest_Line.tga");
	SetDword(0x007C179A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_myquest_Line.tga");

	//newui_item_money
	SetDword(0x00836CDA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_money.tga");
	SetDword(0x008651AA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_money.tga");
	
	//newui_item_money2
	SetDword(0x0084642A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_money2.tga");
	SetDword(0x0084755A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_money2.tga");
	SetDword(0x00879D0A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_money2.tga");
	
	//newui_item_money3
	SetDword(0x00857F3A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_money3.tga");

	//newui_Bt_accept
	SetDword(0x0086524A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_Bt_accept.tga");

	//newui_exit_00
	SetDword(0x00784EAA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x0078EDBA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x007C048A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x007C674A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x007C83DA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x007CDE6A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x007D0B3A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x007D53FA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x00836CFA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x0083E87A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x00840C4A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x00843F2A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x0084646A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x0084B31A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x0084E75A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x0084F0FA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x0085103A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x00852A4A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x008651CA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x00867F7A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x0087516A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x00878CBA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x00879B8A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x008804AA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x0088114A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x00882CEA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x0088424A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");
	SetDword(0x00945FFA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_exit_00.tga");

	//newui_item_back01
	SetDword(0x0078ED3A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x007C16FA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x007CDD0A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x007D0ABA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x00836ADA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x0083E7FA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x00840BCA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x0084B29A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x0084F07A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x0085666A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x00857E3A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x0086510A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x00867EBA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x008750EA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x00878C3A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x00879B0A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x0088042A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x008810CA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x00882C6A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x008841CA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x00892F8A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");
	SetDword(0x008940BA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back01.tga");

	//newui_item_back02-L
	SetDword(0x00784D4A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x0078ED5A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x007C171A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x007C2DFA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x007C66AA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x007C833A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x007CDD2A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x007D0ADA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x007D539A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x007EF286+3,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x0082C81A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x00836B1A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x0083E81A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x00840BEA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x00843E6A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x008463AA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x008474DA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x0084B2BA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x0084E6FA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x0084F09A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x00850F5A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x0085296A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x00854C8A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x0085668A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x00857E5A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x0086512A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x00867EDA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x0087510A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x00878C5A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x00879B2A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x0088044A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x008810EA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x00882C8A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x008841EA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x00892FAA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");
	SetDword(0x008940DA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-L.tga");

	//newui_item_back02-R
	SetDword(0x00784D6A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x0078ED7A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x007C173A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x007C2E1A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x007C66CA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x007C835A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x007CDD4A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x007D0AFA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x007D53BA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x007EF28D+3,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x0082C83A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x00836B3A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x0083E83A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x00840C0A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x00843E8A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x008463CA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x008474FA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x0084B2DA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x0084E71A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x0084F0BA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x00850F7A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x0085298A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x00854CAA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x008566AA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x00857E7A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x0086514A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x00867EFA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x0087512A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x00878C7A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x00879B4A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x0088046A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x0088110A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x00882CAA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x0088420A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x00892FCA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");
	SetDword(0x008940FA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back02-R.tga");

	//newui_item_back03
	SetDword(0x00784D8A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0078ED9A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x007C175A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x007C2E3A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x007C66EA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x007C837A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x007CDD6A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x007D0B1A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x007D53DA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x007EF294+3,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0082C85A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x00836B5A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x00836B5A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x00840C2A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x00843EAA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x008463EA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0084751A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0084928A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0084B2FA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0084E73A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0084F0DA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x00850F9A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x008529AA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x00854CCA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x008566CA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x00857E9A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0086516A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x00867F1A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0087514A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x00878C9A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x00879B6A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0088048A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0088112A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x00882CCA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0088422A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x00892FEA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0089411A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0094844A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0094BAEA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0094C57A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0094FB7A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0095129A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");
	SetDword(0x0095203A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back03.tga");

	//newui_item_back04
	SetDword(0x00784D2A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back04.tga");
	SetDword(0x007C2DDA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back04.tga");
	SetDword(0x007C668A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back04.tga");
	SetDword(0x007C831A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back04.tga");
	SetDword(0x007D537A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back04.tga");
	SetDword(0x007EF286+3,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back04.tga");
	SetDword(0x0082C7FA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back04.tga");
	SetDword(0x00836AFA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back04.tga");
	SetDword(0x00843E4A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back04.tga");
	SetDword(0x0084638A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back04.tga");
	SetDword(0x008474BA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back04.tga");
	SetDword(0x0084E6DA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back04.tga");
	SetDword(0x00850F3A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back04.tga");
	SetDword(0x0085294A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back04.tga");
	SetDword(0x00854C6A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_back04.tga");

	//newui_item_box
	SetDword(0x007D991A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_box.tga");

	//newui_item_boots
	SetDword(0x00836B7A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_boots.tga");

	//newui_item_cap
	SetDword(0x00836B9A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_cap.tga");

	//newui_item_fairy
	SetDword(0x00836BBA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_fairy.tga");
	
	//newui_msgbox_back
	SetDword(0x00784D0A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0078ED1A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x007C16DA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x007C2DBA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x007C666A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x007C82FA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x007CDCEA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x007D0A5A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x007D535A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x007EF278+3,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x00824EDA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0082C7DA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x00836A7A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0083E7DA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x00840BAA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x00843E2A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0084636A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0084749A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0084926A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0084B27A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0084E6BA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0084F05A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x00850F1A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0085292A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x00853C3A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x00854C4A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0085664A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x00857E1A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x008650EA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x00867E9A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x00868E3A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0086D0CC+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x008750CA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0087692A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x00878C1A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x00879AEA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0088040A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x008810AA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x00882C4A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x008841AA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x00892F6A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0089409A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0094842A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0094BACA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0094C55A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0094FB5A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0095127A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");
	SetDword(0x0095201A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.tga");

	//newui_msgbox_back
	SetDword(0x00784D0A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0078ED1A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x007C16DA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x007C2DBA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x007C666A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x007C82FA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x007CDCEA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x007D0A5A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x007D535A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x007EF278+3,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x00824EDA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0082C7DA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x00836A7A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0083E7DA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x00840BAA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x00843E2A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0084636A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0084749A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0084926A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0084B27A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0084E6BA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0084F05A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x00850F1A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0085292A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x00853C3A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x00854C4A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0085664A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x00857E1A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x008650EA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x00867E9A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x00868E3A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0086D0CC+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x008750CA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0087692A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x00878C1A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x00879AEA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0088040A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x008810AA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x00882C4A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x008841AA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x00892F6A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0089409A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0094842A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0094BACA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0094C55A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0094FB5A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0095127A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");
	SetDword(0x0095201A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_msgbox_back.jpg");

	//newui_item_gloves
	SetDword(0x00836C5A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_gloves.tga");

	//newui_item_lower
	SetDword(0x00836C7A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_lower.tga");

	//newui_item_ring
	SetDword(0x00836C9A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_ring.tga");

	//newui_item_necklace
	SetDword(0x00836CBA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_necklace.tga");

	//newui_item_wing
	SetDword(0x00836BDA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_wing.tga");

	//newui_item_weapon(L)
	SetDword(0x00836BFA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_weapon(L).tga");

	//newui_item_weapon(R)
	SetDword(0x00836C1A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_weapon(R).tga");

	//newui_item_upper
	SetDword(0x00836C3A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_item_upper.tga");

	//newui_Bt_closeshop
	SetDword(0x00836ABA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_Bt_closeshop.tga");
	SetDword(0x00840CAA+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_Bt_closeshop.tga");

	//newui_Bt_openshop
	SetDword(0x00836A9A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_Bt_openshop.tga");
	SetDword(0x00840C8A+1,(DWORD)"Custom\\Interface\\S8\\Menu\\newui_Bt_openshop.tga");

	//Transparency border inventory etc..
	//newui_item_table01(L)
	SetDword(0x00784DAA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x007D993A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0084B33A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0084E79A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x00879C0A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x008804EA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x00882D2A+1,(DWORD)"Custom\\Interface\\Null.tga");

	//newui_item_table01(R)
	SetDword(0x00784DCA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x007D995A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0084B35A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0084E7BA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x00879C2A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0088050A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x00882D4A+1,(DWORD)"Custom\\Interface\\Null.tga");

	//newui_item_table02(L)
	SetDword(0x00784DEA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x007D997A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0084B37A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0084E7DA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x00879C4A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0088052A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x00882D6A+1,(DWORD)"Custom\\Interface\\Null.tga");

	//newui_item_table02(R)
	SetDword(0x00784E0A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x007D999A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0084B39A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0084E7FA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x00879C6A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0088054A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x00882D8A+1,(DWORD)"Custom\\Interface\\Null.tga");

	//newui_item_table03(Dw)
	SetDword(0x00784E4A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x007CDE0A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x007D99DA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0084B3DA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0084E83A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x00879CAA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0088058A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x00882DCA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x008842CA+1,(DWORD)"Custom\\Interface\\Null.tga");

	//newui_item_table03(L)
	SetDword(0x00784E6A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x007CDE2A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x007D99FA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0084B3FA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0084E85A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x00879CCA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x008805AA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x00882DEA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x008842EA+1,(DWORD)"Custom\\Interface\\Null.tga");

	//newui_item_table03(R)
	SetDword(0x00784E8A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x007CDE4A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x007D9A1A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0084B41A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0084E87A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x00879CEA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x008805CA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x00882E0A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0088430A+1,(DWORD)"Custom\\Interface\\Null.tga");

	//newui_item_table03(Up)
	SetDword(0x00784E2A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x007CDDEA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x007D99BA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0084B3BA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0084E81A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x00879C8A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x0088056A+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x00882DAA+1,(DWORD)"Custom\\Interface\\Null.tga");
	SetDword(0x008842AA+1,(DWORD)"Custom\\Interface\\Null.tga");

}

