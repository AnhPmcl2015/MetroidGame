#ifndef GAME_H
#define GAME_H

#include"./others/GraphicDevice.h"
#include<dinput.h>
#include "./others/GameObject.h"
//#include"Player.h"
#include "./input/KeyBoard.h"
//#include"Camera.h"
//#include"BackGround.h"
//#include"Map.h"
//#include"CollisionManager.h"
//#include"QuadTree.h"
//#include"MonsterManager.h"
//#include"DoorManager.h"
//#include"Sound.h"

#define KEYBOARD_BUFFER_SIZE 1024

class Game
{
public:
	Game();
	~Game();

	bool Initialize(HWND hWnd, HINSTANCE hInstance, int width, int height);
	void Run(float gameTime);
	void Update(float gameTime);
	void Draw(float gameTime);

	void DrawMap();
	void ProcessController(HWND hWnd);
	void ProcessInput();

	void SceneChange(int index);

private:
	GraphicsDevice *gDevice;

	int _width;
	int _height;
	bool Auto = false;
	bool AutoPlayer = false;
	float _gameTime;

	/*Player* player;*/

	//KeyBoard* keyBoard;

	/*Camera* camera;

	Map* map;

	CollisionManager* collisionManager;*/

	SpriteManager* spriteManager;
/*
	QuadTree* quadTree;

	MonsterManager* monsterManager;

	DoorManager* doorManager;

	Sound* sound;

	BackGround* scene;*/
	bool Intro;
	bool SelectScene;
	bool SelectScene1;
	bool SelectScene2;
	bool PLayScene;
};

#endif GAME_H