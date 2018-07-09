#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#define KEYBOARD_BUFFER_SIZE	1024
#define KEY_DOWN(code) ( IsKeyDown(code) )
#define KEY_DOWN(vk_code) ( (GetAsyncKeyState(vk_code)&0x8000)?1:0 )

#define TIME_FREEZING 5000
#define TIME_IN_GAME 7000

//================ SCREEN RESOLUTION ================
#define GAME_SCREEN_RESOLUTION_512_416_24   0
#define GAME_SCREEN_RESOLUTION_800_600_24   1
#define GAME_SCREEN_RESOLUTION_1024_768_24  2

#define GAME_SCREEN_RESOLUTION_640_480_32   10
#define GAME_SCREEN_RESOLUTION_800_600_32   11
#define GAME_SCREEN_RESOLUTION_1024_768_32  12
//================ END RESOLUTION ====================


//================= OBJECT TYPE ================
enum OBJECT_TYPE
{
	SAMUS = 1,
	ENEMY = 2,
	BRICK = 3,
};
//================= END OBJECT TYPE ============


//================ SPRITE SAMUS ================
#define WIDTH_SAMUS_STAND 17
#define HEIGHT_SAMUS_STAND 38
//================= END SPRITE SAMUS ============

//================ SPRITE BRICK ================
#define WIDTH_SPRITE_BRICK 16
#define HEIGHT_SPRITE_BRICK 16
//================= END SPRITE BRICK ============


//================ ROOM LIMITATION (TILES COUNT)============================
#define X_LIMITATION 16
#define Y_LIMITATION 15
//================ END ROOM LIMITATION ============================