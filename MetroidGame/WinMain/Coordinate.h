
#ifndef COORDINATE 
#define COORDINATE

class Coordinate
{
public:
	Coordinate(int xInTexture, int yInTexture, int xInWorld, int yInWorld, int width, int height);
	~Coordinate();

	int _xInTexture;
	int _yInTexture;
	int _xInWorld;
	int _yInWorld;
	int _width;
	int _height;

private:

};

#endif 