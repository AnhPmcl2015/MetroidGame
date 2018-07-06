#pragma once
//#include"../Others/GameObject.h"
//#include"../Others/Coordinate.h"
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
			float maxSpeed,
			//CollisionManager* collisionManager,
			SpriteManager* spritemanager,
			GraphicsDevice* gDevice
			//,Sound* sound
	}

	~Map() {

	}

	bool Initialize(LPDIRECT3DDEVICE9 device);
	void Update(int roomID);
	void Draw(float gameTime);

	bool IsInitialize = false;

	void setLimitation(int x, int y, int width, int height);

	bool loadMap();

protected:
	std::string filepath;
	vector<string> stringMap;
	vector<Coordinate*> Positions;
	GameSprite* painter;
};