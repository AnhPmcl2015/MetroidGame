#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Define.h"
#include "DeviceManager.h"
#include "DXGraphics.h"
#include <string>
#include "trace.h"

using namespace std;

class Sprite {
private:
	LPDIRECT3DTEXTURE9 texture;      // file chua sprite lon
	LPD3DXSPRITE sprite;			  // Dung de xu ly xuat hien sprite dua vao texture
	D3DCOLOR transColor;			  // transparent color

	int width;
	int height;
	LPWSTR textureFilePath;		  // Duong dan hinh anh sprite
	int x;		
	int y;
	int currentIndexOfSprite = 0;	  // Vi tri hien tai cua sprite can ve trong texture (dung cho viec chuyen dong sprite)
	int startIndexOfSprite;			  // Vi tri bat dau ve sprite			
	int count;						  // So luong sprite trong texture
public:
	Sprite(LPD3DXSPRITE, LPWSTR, int, int, int, int);
	~Sprite();
	void updateSprite();

	void setWidth(int value);
	int getWidth();

	void setHeight(int value);
	int getHeight();

	//Ex: player->drawSprite(0, 0, 16, 32, D3DXVECTOR3(10, 10, 0));
    void drawSprite(int x, int y, int width, int height, D3DXVECTOR3 position);
	void Reset();
};