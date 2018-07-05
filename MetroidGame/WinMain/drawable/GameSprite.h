#ifndef GAMESPRITE_H
#define GAMESPRITE_H

#include<string>
#include "../others/GraphicDevice.h"
#include "SpriteManager.h"

class GameSprite
{
public:

	GameSprite(SpriteManager* data);
	~GameSprite();

	bool initialize(LPDIRECT3DDEVICE9 device, LPDIRECT3DTEXTURE9 tex, int indexInData, int count);
	bool IsInitialize();

	virtual void Update(float gameTime);
	virtual void Draw(float gameTime, D3DXVECTOR3 position);
	void Draw(int XInTexture, int yInTexture, int width, int height, D3DXVECTOR3 position);

	float getHeight();
	float getWidth();

private:
	LPDIRECT3DTEXTURE9 _tex;
	LPD3DXSPRITE sprite;
	D3DCOLOR color;
	bool initialized;
	int index = 0;
	int startIndex;
	int _width; int _height;
	int x; int y;
	int _count;
	SpriteManager* _data;
};

#endif