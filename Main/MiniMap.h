#pragma once

#define MAX_MINI_MAP 99
#define pMapNumber *(int*)0x0E61E18
#define pLoadImageJPG ((void(__cdecl*)(char *Folder, int ModelID, GLint a3, GLint a4, int a5, int a6)) 0x00772330)

void InitMiniMap();
void MiniMapCore();
void MiniMapLoad();
bool MiniMapCheck(int map);
bool MiniMapFileCheck(int map);