#define pGetItemAtt(id, offset)	(*(DWORD*)0x8128AC0 + 84 * id + offset) //1.04D || 1.04E may be -0x150
#define pSetItemOption			((void(__cdecl*)(ObjectItem * lpItem, BYTE Option, BYTE Special, BYTE Value)) 0x58B910) //1.04D || 1.04E may be -0x150

class cItemInfoEx
{
public:
	cItemInfoEx();
	~cItemInfoEx();
	void Load();
	// ----
}; extern cItemInfoEx gItemInfoEx;