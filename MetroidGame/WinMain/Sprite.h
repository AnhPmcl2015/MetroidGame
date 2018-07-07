#ifndef Sprite_H
#define Sprite_H

#include<string>
#include"DeviceManager.h"
#include"DXGraphics.h"
#include"SpriteManager.h"

class Sprite
{
private: 
	LPDIRECT3DTEXTURE9 texture;
	LPD3DXSPRITE sprite;
	D3DCOLOR transColor;


};

#endif