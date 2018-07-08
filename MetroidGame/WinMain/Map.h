#pragma once
//#include"../Others/GameObject.h"
//#include"../Others/Coordinate.h"
#include "Coordinate.h"
#include "GameObject.h"
#include "Define.h"
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Map : public GameObject {
public:
	Map() {
		float x,
			float y,
			float rotation,
			float speed,
			float maxSpeed;
			//CollisionManager* collisionManager,
			//SpriteManager* spritemanager,
			//GraphicsDevice* gDevice
			//,Sound* sound
	}

	~Map() {

	}

	bool Initialize(LPDIRECT3DDEVICE9 device);
	void Draw(float gameTime);

	void Update();
	void Update(int _roomID);

	bool IsInitialize = false;

	void setLimitation(int x, int y, int width, int height);

	bool loadMap(string filePath);

protected:
	std::string filePath;
	vector<string> stringMap;
	vector<Coordinate*> Positions;
	int roomID;
	//GameSprite* painter;

	//Start coordinate of the camera
	int camera_X;
	int camera_Y;

	//TODO: 
	int widthLimitation;
	int heightLimitation;

};
