#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include "../others/DataSet.h"
#include "../others/Coordinate.h"
#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>

using namespace std;

class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();

	bool Initialize(string filepath);
	Coordinate* getCoordinate(int index);

protected:
	vector<Coordinate*> _ListCoordinate;

};

#endif SPRITEMANAGER_H