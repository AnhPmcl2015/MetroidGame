#include"Coordinate.h"

Coordinate::Coordinate(int xInTexture, int yInTexture, int xInWorld, int yInWorld, int width, int height)
{
	_xInTexture = xInTexture;
	_yInTexture = yInTexture;
	_xInWorld = xInWorld;
	_yInWorld = yInWorld;
	_width = width;
	_height = height;
}

Coordinate::~Coordinate()
{

}