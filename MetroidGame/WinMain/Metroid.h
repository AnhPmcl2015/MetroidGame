//#pragma once
//#ifndef _METROID_H_
//#define _METROID_H_
//
//#include "Define.h"
//#include "Game.h"
//
////class Metroid : public Game
////{
////protected:
////	LPDIRECT3DSURFACE9 startscreen;
////
////	LPD3DXSPRITE spriteHandler;
////
////private:
////	void _InitBackground();
////	void _InitSprites(LPDIRECT3DDEVICE9 d3ddv);
////	void _InitPositions();
////
////	DWORD start_jump;
////	DWORD now_jump;
////	DWORD tick_per_frame;
////public:
////	Metroid(HINSTANCE hInstance, LPWSTR Name, int Mode, int IsFullScreen, int FrameRate);
////	~Metroid();
////
////	virtual void LoadResources(LPDIRECT3DDEVICE9 d3ddv);
////	// ---------------------------
////	virtual void Update(float Delta); //Kiểm tra screen Mode (bắt đầu, room1, room2,... hay gameover)
////	virtual void UpdateFrame(float Delta);	//update các object trong game
////	// -----------------------------
////	virtual void Render(LPDIRECT3DDEVICE9 d3ddv);	//render từng screen mode (room1, room2,... hay gameover)
////	virtual void RenderStartScreen(LPDIRECT3DDEVICE9 d3ddv);	//render các scene chính (room1, room2...) trong game
////	virtual void RenderFrame(LPDIRECT3DDEVICE9 d3ddv);		//render từng object trong game
////	// ---------------------------
////	virtual void ProcessInput(LPDIRECT3DDEVICE9 d3ddv, float Delta);
////	virtual void OnKeyDown(int KeyCode);
////
////	DWORD GetTickPerFrame();
////
////	int screenMode;
////	bool isFreezing;
////	bool isOnFloor;
////	bool isInGame;
////};
//class MetroidGame : public Game
//{
//private:
//	SpriteBatch batch;
//	PlayScene playScene;
//	IntroScene introScene;
//	StartScene startScene;
//	GameOverScene gameOverScene;
//	float pauseTime;
//	Scene *scenes;
//protected:
//	//create all the things of a game here, such as world, object, ...
//	void CreateGame() override;
//	//update game by one frame (render, control game) - just write your game here
//	void UpdateGame(float dt) override;
//
//
//public:
//	MetroidGame(HINSTANCE hInstance, LPWSTR windowName, int screenWidth, int screenHeight, bool isFullScreen, int frameRate);
//	~MetroidGame();
//	void Release() override;
//};
//#endif // !_METROID_
