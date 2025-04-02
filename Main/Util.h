#pragma once

struct REFERENCE_INFO
{
	DWORD count;
	DWORD start;
	DWORD end;
};

struct REFERENCE_BASE
{
	DWORD address;
};

struct REFERENCE_DATA
{
	DWORD address;
	DWORD value;
};

void SetByte(DWORD offset,BYTE value);
void SetWord(DWORD offset,WORD value);
void SetDword(DWORD offset,DWORD value);
void SetFloat(DWORD offset,float value);
void SetDouble(DWORD offset,double value);
void SetCompleteHook(BYTE head,DWORD offset,...);
void MemoryCpy(DWORD offset,void* value,DWORD size);
void MemorySet(DWORD offset,DWORD value,DWORD size);
void VirtualizeOffset(DWORD offset,DWORD size);
void PacketArgumentEncrypt(char* out_buff,char* in_buff,int size);
char* ConvertModuleFileName(char* name);
void LoadReferenceAddressTable(HMODULE mod,char* name,DWORD address);
void SetJmp(DWORD offset,DWORD size,LPVOID function);

extern DWORD FrameValue;
extern DWORD MainTickCount;
extern BYTE NewAddressData1[240];
extern BYTE NewAddressData2[240];
extern BYTE NewAddressData3[6000];


	

	/*
	SetByte(0x4D8FD0, 0xC3);
					//MemorySet(0x005F8767, 0x90, 0x05); //Item Drop voando
					//MemorySet(0x005F87C9, 0x90, 0x05); //Item Drop Luz
					//MemorySet(0x005F8924, 0x90, 0x05); //Drop Zen Reduz 1
					//MemorySet(0x005F89B3, 0x90, 0x05); //Drop Zen Reduz 2
					//MemorySet(0x005F8BB2, 0x90, 0x05); //Drop Item
					//MemorySet(0x005F8C1A, 0x90, 0x05); //Name Drop Item

					SetByte(0x542D20, 0xC3); esse é mais doido ainda kkk

*/