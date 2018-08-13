#include "Bomb.h"

Bomb::Bomb(LPD3DXSPRITE spriteHandler, World* world) : Item(spriteHandler, world)
{
	this->width = 16;
	this->height = 16;
}

Bomb::~Bomb()
{
	delete(item);
}

void Bomb::InitSprites(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DTEXTURE9 texture)
{
	if (d3ddv == NULL) return;
	//Create sprite handler
	HRESULT result = D3DXCreateSprite(d3ddv, &spriteHandler);
	if (result != D3D_OK) return;
	// TODO: Bomb sprite
	item = new Sprite(spriteHandler, texture, ITEM_BOMB_PATH, ITEM_BOMB_WIDTH, ITEM_BOMB_HEIGHT, ITEM_BOMB_COUNT);
}

void Bomb::Update(float t)
{
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		item->updateSprite();
		last_time = now;
	}
}

void Bomb::touchedBySamus(Samus * samus)
{
	// TODO: affect to samus
	this->Destroy();
}