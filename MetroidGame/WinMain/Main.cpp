#include <windows.h>
#include "Game.h"
#include "Metroid.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Metroid metroid(hInstance, TITLE, GAME_SCREEN_RESOLUTION_640_480_24, FULLSCREENMODE, FRAME_RATE);

	metroid.GameInit();
	metroid.GameRun();

	return 0;
}