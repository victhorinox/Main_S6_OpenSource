#pragma once
#pragma warning(push)
#pragma warning(disable: 4244; disable: 4482; disable: 4101; disable:4099; disable: 4733; disable: 4715; disable: 4800; disable: 4018; disable: 4305; disable: 4309; disable: 4700) // possible loss of data

typedef unsigned __int64 QWORD;

#define _CRT_SECURE_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#define _WIN32_WINNT _WIN32_WINNT_WINXP

#define MOVE_ITEM	1

// System Include
#include <vector>
#include <windows.h>
#include <iostream>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <winsock2.h>
#include <Mmsystem.h>
#include <time.h>
#include <gl\GL.h>
#include "detours.h"
#include <tlhelp32.h>
#include <tchar.h>

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"Opengl32.lib")
#pragma comment(lib,"detours.lib")

#define MAX_CHAT_TYPE1 10
#define MAX_CUSTOM_WING 100
#define MAX_DYNAMIC_WING_EFFECT 1500
#define MAX_CUSTOM_WING_EFFECT 3000

void InitLoginThemeS4();
void InitLoginThemeS2();
