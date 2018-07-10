#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class World;
class Samus;
class Metroid;

#define KEYBOARD_BUFFER_SIZE	1024
#define KEY_DOWN(code) ( IsKeyDown(code) )
#define KEY_DOWN(vk_code) ( (GetAsyncKeyState(vk_code)&0x8000)?1:0 )

#define TIME_FREEZING 5000
#define TIME_IN_GAME 7000

#define JUMP_VELOCITY_BOOST 0.1f
#define JUMP_VELOCITY_BOOST_FIRST 0.6f
#define FALLDOWN_VELOCITY_DECREASE 0.07f
#define GRAVITY_VELOCITY 0.005f
#define ANIMATE_RATE 20

#define SAMUS_SPEED 100.0f
#define FRICTION 1.0f
#define TEXTURE_GAME_CHARACTERS L"sprites\\Player_32x16.png"

//================ SCREEN RESOLUTION ================
#define GAME_SCREEN_RESOLUTION_512_480_24   0
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
#define WIDTH_SAMUS_STAND 20
#define HEIGHT_SAMUS_STAND 32
#define COUNT_SAMUS_STAND 1
#define STAND_RIGHT_PATH L"sprites\\STAND_RIGHT.txt"
#define STAND_LEFT_PATH L"sprites\\STAND_LEFT.txt"

#define WIDTH_SAMUS_RUNRIGHT 18
#define HEIGHT_SAMUS_RUNRIGHT 32
#define COUNT_SAMUS_RUNRIGHT 3
#define RUNRIGHT_PATH L"sprites\\RIGHTING.txt"

#define WIDTH_SAMUS_RUNLEFT 17
#define HEIGHT_SAMUS_RUNLEFT 32
#define COUNT_SAMUS_RUNLEFT 3
#define RUNLEFT_PATH L"sprites\\LEFTING.txt"

#define WIDTH_SAMUS_MORPHLEFT 19
#define HEIGHT_SAMUS_MORPHLEFT 23
#define COUNT_SAMUS_MORPHLEFT 4
#define MORPHLEFT_PATH L"sprites\\MORPH_LEFT.txt"

#define WIDTH_SAMUS_MORPHRIGHT 19
#define HEIGHT_SAMUS_MORPHRIGHT 23
#define COUNT_SAMUS_MORPHRIGHT 4
#define MORPHRIGHT_PATH L"sprites\\MORPH_RIGHT.txt"

#define WIDTH_SAMUS_JUMP 23
#define HEIGHT_SAMUS_JUMP 25
#define COUNT_SAMUS_JUMP 1
#define JUMPLEFT_PATH L"sprites\\JUMP_LEFT.txt"
#define JUMPRIGHT_PATH L"sprites\\JUMP_RIGHT.txt"

#define WIDTH_SAMUS_BALLLEFT 12
#define HEIGHT_SAMUS_BALLLEFT 13
#define COUNT_SAMUS_BALLLEFT 4
#define BALLLEFT_PATH L"sprites\\TRANSFORM_BALL_LEFT.txt"

#define WIDTH_SAMUS_BALLRIGHT 12
#define HEIGHT_SAMUS_BALLRIGHT 13
#define COUNT_SAMUS_BALLRIGHT 4
#define BALLRIGHT_PATH L"sprites\\TRANSFORM_BALL_RIGHT.txt"

#define WIDTH_SAMUS_STANDSHOOTUP 14
#define HEIGHT_SAMUS_STANDSHOOTUP 36
#define COUNT_SAMUS_STANDSHOOTUP 1
#define STANDSHOOTUP_LEFT_PATH L"sprites\\STANDSHOOT_LEFT.txt"
#define STANDSHOOTUP_RIGHT_PATH L"sprites\\STANDSHOOT_RIGHT.txt"

#define WIDTH_SAMUS_RUNSHOOTright 25
#define HEIGHT_SAMUS_RUNSHOOTright 31
#define COUNT_SAMUS_RUNSHOOTright 3
#define RUNSHOOTright_PATH L"sprites\\RUNSHOOT_RIGHT.txt"

#define WIDTH_SAMUS_RUNSHOOTleft 25
#define HEIGHT_SAMUS_RUNSHOOTleft 31
#define COUNT_SAMUS_RUNSHOOTleft 3
#define RUNSHOOTleft_PATH L"sprites\\RUNSHOOT_LEFT.txt"

#define WIDTH_SAMUS_JUMPSHOOTright 19
#define HEIGHT_SAMUS_JUMPSHOOTright 38
#define COUNT_SAMUS_JUMPSHOOTright 4
#define JUMPSHOOTright_PATH L"sprites\\JUMPSHOOT_RIGHT.txt"

#define WIDTH_SAMUS_JUMPSHOOTleft 19
#define HEIGHT_SAMUS_JUMPSHOOTleft 38
#define COUNT_SAMUS_JUMPSHOOTleft 4
#define JUMPSHOOTleft_PATH L"sprites\\JUMPSHOOT_LEFT.txt"
//================= END SPRITE SAMUS ============

//================ SPRITE BRICK ================
#define WIDTH_SPRITE_BRICK 32
#define HEIGHT_SPRITE_BRICK 32
//================= END SPRITE BRICK ============


//================ ROOM LIMITATION (TILES COUNT)============================
#define X_LIMITATION 20
#define Y_LIMITATION 15
//================ END ROOM LIMITATION ==================================

//================ BRICK SIZE =============================================
#define BRICK_SIZE 32
//================ END BRICK SIZE =========================================