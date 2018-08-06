#pragma once
#include "Item.h"
#include "Sprite.h"
#include "Define.h"

class Missile : public Item
{
public:
	Missile(LPD3DXSPRITE spriteHandler, World* world);
	~Missile();
	void InitSprites(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DTEXTURE9 texture);
	//void Init(float posX, float posY);
	void Update(float t);
	//void Render();
	//void Destroy();
};