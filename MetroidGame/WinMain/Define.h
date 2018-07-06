#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#define KEYBOARD_BUFFER_SIZE	1024
#define KEY_DOWN(code) ( IsKeyDown(code) )
#define KEY_DOWN(vk_code) ( (GetAsyncKeyState(vk_code)&0x8000)?1:0 )

#define TIME_FREEZING 5000
#define TIME_IN_GAME 7000

#define TITLE L"Metroid Game"

#define FULLSCREENMODE 0

#define FRAME_RATE 80

//================ SCREEN RESOLUTION ================
#define GAME_SCREEN_RESOLUTION_640_480_24   0
#define GAME_SCREEN_RESOLUTION_800_600_24   1
#define GAME_SCREEN_RESOLUTION_1024_768_24  2

#define GAME_SCREEN_RESOLUTION_640_480_32   10
#define GAME_SCREEN_RESOLUTION_800_600_32   11
#define GAME_SCREEN_RESOLUTION_1024_768_32  12
//================ END RESOLUTION ====================

//================ ROOM ID ============================
#define ROOM_1 1
#define ROOM_2 2
#define ROOM_3 3

//================ END ROOM ID ========================
