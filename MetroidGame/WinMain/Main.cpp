//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	Metroid metroid(hInstance, TITLE, GAME_SCREEN_RESOLUTION_640_480_24, FULLSCREENMODE, FRAME_RATE);
//
//	metroid.GameInit();
//	metroid.GameRun();
//
//	return 0;
//}

#include<Windows.h>
#include<iostream>
#include "Game.h"

using namespace std;

//bool GenerationWindow(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR WindowTitle, int width, int height, HWND& hWnd);
//bool GenerationWindow(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR WindowTitle, int x, int y, int width, int height, HWND& hWnd);

bool GenerationWindow(HINSTANCE hInstance, int nCmdShow, LPCWSTR className, LPCWSTR WindowTitle, int width, int height, HWND& hWnd);
bool GenerationWindow(HINSTANCE hInstance, int nCmdShow, LPCWSTR className, LPCWSTR WindowTitle, int x, int y, int width, int height, HWND& hWnd);

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wPrama, LPARAM lParam);

#define WINDOW_WIDTH 256
#define WINDOW_HEIGHT 244
#define WINDOW_LOCATION_X 100
#define WINDOW_LOCATION_Y 100
#define CLASSNAME L"GameScene"
#define TILE L"Metroid1984 Remaster"

//Game *game;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	if (GenerationWindow(hInstance, nCmdShow, CLASSNAME, TILE, WINDOW_WIDTH, WINDOW_HEIGHT, hWnd))
	{
		MSG msg;

		int done = 0;
		DWORD frame_start = GetTickCount();
		DWORD tick_per_frame = 1000 / 20;                 //18fps 

		/*game = new Game();
		if (game->Initialize(hWnd, hInstance, WINDOW_WIDTH, WINDOW_HEIGHT))
		{
			while (!done)
			{
				if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
				{
					if (msg.message == WM_QUIT)
						done = 1;

					TranslateMessage(&msg);
					DispatchMessage(&msg);

				}
				DWORD now = GetTickCount();
				DWORD _DeltaTime = now - frame_start;
				if (_DeltaTime >= tick_per_frame)
				{
					frame_start = now;
					game->Run(_DeltaTime / 2);
				}

				game->ProcessController(hWnd);
				Sleep(_DeltaTime / 2);
			}

			delete game;
			return msg.wParam;
		}*/
	}
	return 0;
}

bool GenerationWindow(HINSTANCE hInstance, int nCmdShow, LPCWSTR className, LPCWSTR WindowTile, int width, int height, HWND& hWnd)
{
	return GenerationWindow(hInstance, nCmdShow, className, WindowTile, WINDOW_LOCATION_X, WINDOW_LOCATION_Y, width, height, hWnd);
}

//bool GenerationWindow(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR WindowTitle, int x, int y, int width, int height, HWND& hWnd)
bool GenerationWindow(HINSTANCE hInstance, int nCmdShow, LPCWSTR className, LPCWSTR WindowTitle, int x, int y, int width, int height, HWND& hWnd)
{

	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(WNDCLASSEX));
	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WindowProc;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wcex.lpszClassName = className;
	wcex.hIconSm = LoadIcon(NULL, IDI_WINLOGO);

	if (!RegisterClassEx(&wcex))
	{
		return false;
	}
	hWnd = CreateWindowEx(
		NULL,
		className,
		WindowTitle,
		WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
		x,
		y,
		width,
		height,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hWnd, nCmdShow);
	return true;
}

HRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}break;

	default:
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
