#include "stdafx.h"
#include "SelectCharAnimation.h"
#include "Import.h"
#include "Defines.h"
#include "Protocol.h"
#include "Util.h"
#include "CustomPet.h"
#include "Protect.h"

cSelectChar gSelectChar;

void cSelectChar::Load()
{
	srand((unsigned)time(NULL));
	SetCompleteHook(ASM::CALL,oOnCharClick_Call,&this->OnCharClick);
};

int cSelectChar::OnCharClick(DWORD This)
{
	if(oSelectedCharView != -1)
	{
		DWORD ObjectPreview = (DWORD)pGetPreviewStruct(pPreviewThis(), oSelectedCharView);
		short ObjectPetSlot = *(short*)(ObjectPreview + 556);
		
		if (gCustomPet2.CheckCustomPetByItem( ObjectPetSlot - 1171 ))
		{
			if(gCustomPet2.GetInfoPetType( ObjectPetSlot - 1171 ) <= 0 || gCustomPet2.GetInfoPetType( ObjectPetSlot - 1171 ) == 4)
			{
				int Action[] = { gProtect.m_MainInfo.SCSlot1Animation, gProtect.m_MainInfo.SCSlot2Animation, gProtect.m_MainInfo.SCSlot3Animation, gProtect.m_MainInfo.SCSlot4Animation, gProtect.m_MainInfo.SCSlot5Animation, };
				pActionSend(ObjectPreview + 776,Action[rand() % 5],true);
			}
			
			if (gCustomPet2.GetInfoPetType( ObjectPetSlot - 1171 ) == 1)
			{
				int Action[] = {AT_FENRIRATTACK2, AT_FENRIRATTACK3};
				pActionSend(ObjectPreview + 776,Action[rand() % 2],true);
			}
			
			if (gCustomPet2.GetInfoPetType( ObjectPetSlot - 1171 ) == 2 || ObjectPetSlot == ITEM2(13,4))
			{
				int Random = (rand() % 2) ? AT_GALLOPINGACTION6 : ((rand() % 2) ? AT_GALLOPINGACTION6 : AT_GALLOPINGACTION1);
				
				if(Random == AT_GALLOPINGACTION5)
				{
			    	for(int i = 0;i < 5;i++)
					{
					    if(i != oSelectedCharView)
						{
						    DWORD TempObjectPreview = (DWORD)pGetPreviewStruct(pPreviewThis(), i);
						    short TempObjectPetSlot = *(short*)(TempObjectPreview + 556);
						    if(TempObjectPreview)
							{								
							    if(TempObjectPetSlot == -1)
								{
								    pActionSend(TempObjectPreview + 776,AT_FALL1,false);
							    }								
						    }							
					    }
				    }
			    }
			    pActionSend(ObjectPreview + 776,Random,true);
		    }
			
			if (gCustomPet2.GetInfoPetType( ObjectPetSlot - 1171 ) == 3)
			{
			    int Random = (rand() % 2) ? AT_GALLOPINGATTACK7 : ((rand() % 2) ? AT_GALLOPINGATTACK8 : AT_GALLOPINGATTACK9);
			    pActionSend(ObjectPreview + 776,Random,true);
		    }
		}
		else
		{
			switch(ObjectPetSlot)
			{
			    case ITEM2(13,4):
					{
				    int Random = (rand() % 2) ? AT_GALLOPINGACTION6 : ((rand() % 2) ? AT_GALLOPINGACTION6 : AT_GALLOPINGACTION1);
			        if(Random == AT_GALLOPINGACTION5)
					{
			    	    for(int i = 0;i < 5;i++)
						{
					        if(i != oSelectedCharView)
							{
						        DWORD TempObjectPreview = (DWORD)pGetPreviewStruct(pPreviewThis(), i);
						        short TempObjectPetSlot = *(short*)(TempObjectPreview + 556);
						        if(TempObjectPreview)
								{								
							        if(TempObjectPetSlot == -1)
									{
								        pActionSend(TempObjectPreview + 776,AT_FALL1,false);
							        }								
						        }							
					        }
				        }
			        }
			        pActionSend(ObjectPreview + 776,Random,true);
				}
				break;
	    		case ITEM2(13,37):
					{
			        int Action[] = {AT_FENRIRATTACK2, AT_FENRIRATTACK3};
			        pActionSend(ObjectPreview + 776,Action[rand() % 2],true);
				}
				break;
				case ITEM2(13,2):
				case ITEM2(13,3):
					{
			        int Random = (rand() % 2) ? AT_GALLOPINGATTACK7 : ((rand() % 2) ? AT_GALLOPINGATTACK8 : AT_GALLOPINGATTACK9);
			        pActionSend(ObjectPreview + 776,Random,true);
				}
			    break;
				default:
					{
					int Action[] ={gProtect.m_MainInfo.SCSlot1Animation,
					gProtect.m_MainInfo.SCSlot2Animation,
					gProtect.m_MainInfo.SCSlot3Animation,
					gProtect.m_MainInfo.SCSlot4Animation,
					gProtect.m_MainInfo.SCSlot5Animation,};				
			        pActionSend(ObjectPreview + 776,Action[rand() % 5],true);
				    break;
				}
			}
		}
	}

	return pOnCharClick(This);
}