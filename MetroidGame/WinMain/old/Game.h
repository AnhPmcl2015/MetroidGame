#pragma once
#ifndef _GAME_H_
#define _GAME_H_
#include <windows.h>
#include <DxErr.h>
#include "Input.h"
#include "DeviceManager.h"
#include "DXGraphics.h"
#include "GameObject.h"

//class Game : public GameObject
//{
//	protected:
//		DWORD _DeltaTime;		// Time between the last frame and current frame
//		Input * _input;
//		static Graphics * _dxgraphics;
//		DeviceManager * _device;
//
//		// Render a single frame
//		void _RenderFrame();
//
//		//
//		//====================== VIRTUAL METHOD ===========================
//		//
//		virtual void Update(float Delta);
//		// Đã bỏ delta time cho phương thức Render
//		virtual void RenderFrame(LPDIRECT3DDEVICE9 d3ddv);
//		virtual void LoadResources(LPDIRECT3DDEVICE9 d3ddv);
//		virtual void ProcessInput(LPDIRECT3DDEVICE9 d3ddv, float Delta);
//
//		virtual void OnKeyDown(int KeyCode);
//		virtual void OnKeyUp(int KeyCode);
//		//======================= END VIRTUAL METHOD ======================
//
//	public:
//		//Doi tuong Direct Sound
//		//static SoundManager *gameSound;
//		Game();
//		Game(HINSTANCE hInstance, LPWSTR Name, int Mode, int IsFullscreen, int FrameRate);
//		~Game();
//
//		// Initialize the game with set parameters
//		void GameInit();
//
//		// Run game
//		void GameRun();
//};
class Game : public GameObject
{
private:

	//Window related variables
	HINSTANCE _HInstance; //handle for a window instance
	HWND _HWnd;				// Handle of the Game Window
	LPWSTR _WindowName; //the application title
	bool _IsFullScreen; //fullscreen or not?
	int _FrameRate; //how many frames in one second?

					//Direct3D variables
	LPDIRECT3DSURFACE9 _Backbuffer;
	LPDIRECT3DSURFACE9 _Background;
	D3DCOLOR _BackGroundColor;
	LPWSTR _BackGroundFilePath;

	//window event callback function - basically we use this function to determine what message is sent to Window
	static LRESULT CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	//time between two frames
	DWORD DeltaTime;

	//store the client rect
	//RECT _WindowRect;

	//init
	bool InitWindow();
	bool InitDirectX();
	bool InitGame();


	//Scene
	//Scene* _CurrentScene;

protected:
	//RECOMMEND: overide these two function and do all the things you want
	//create all the things of a game here, such as world, object, ...
	void virtual CreateGame() = 0;
	//update game by one frame (render, control game) - just write your game here
	void virtual UpdateGame(float dt) = 0;

	//void virtual Resize(float x, float y);

	//set background color. If you have already set background image, this function has no affect at all
	void SetBackGroundColor(D3DCOLOR color);
	//create a background from this image. If you want to disable this function, just set the filePath to be NULL
	void SetBackGroundImage(LPWSTR filePath);

	//void SetScene(Scene *scene);

	//call postmessage to shut down application
	void ShutDownApplication();

public:
	//constructor and destructor
	Game();
	Game(HINSTANCE hInstance, LPWSTR windowName, int screenWidth, int screenHeight, bool isFullScreen, int frameRate);
	~Game();


	//RECOMMEND: don't modify this function, just call it in the main function
	//do things in the updateGame function
	//and this function will take care the rest for you
	int RunGame();

	//Release game
	void virtual Release() = 0;

};
#endif
