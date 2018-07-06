#pragma once

#include"Define.h"
#include"Coordinate.h"
#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>

using namespace std;

class SpriteManager {
public:
	SpriteManager();
	~SpriteManager();

	bool initSprite(string filePath);

	Coordinate* getCoordinate(int index);

protected:
	vector<Coordinate*> _ListCoordinate;
};