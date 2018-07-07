#include "SpriteManager.h"

SpriteManager::SpriteManager()
{

}
SpriteManager::~SpriteManager()
{
	/*for (int i = 0; i < _ListCoordinate.size(); i++)
	{
	delete _ListCoordinate[i];
	_ListCoordinate[i] = nullptr;
	}*/
}

bool SpriteManager::initSprite(string filepath)
{
	ifstream file_txt(filepath);
	string str;
	string fileContent;
	while (getline(file_txt, str))
	{
		string name;
		int x;
		int y;
		int width;
		int height;
		std::istringstream iss(str);

		iss >> name >> x >> y >> width >> height;
		Coordinate* coordinate = new Coordinate(x, y, 0, 0, width, height);
		_ListCoordinate.push_back(coordinate);
	}

	return true;
}
Coordinate* SpriteManager::getCoordinate(int index)
{
	return _ListCoordinate[index];
}
