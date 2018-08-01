//#include "Missile.h"
//#include "World.h"
//
//Missile::Missile(LPD3DXSPRITE spriteHandler, World* world) : Item(spriteHandler, world)
//{
//	this->setType(ITEM);
//	item_type = MARU_MARI;
//	missile = NULL;
//	isActive = true;
//
//	this->previousUnit = NULL;
//	this->nextUnit = NULL;
//	this->width = 16;
//	this->height = 16;
//}
//
//Missile::~Missile()
//{
//	delete(missile);
//}
//
//void Missile::InitSprites(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DTEXTURE9 texture)
//{
//	if (d3ddv == NULL) return;
//	HRESULT result = D3DXCreateSprite(d3ddv, &spriteHandler);
//	if (result != D3D_OK) return;
//	missile = new Sprite(spriteHandler, texture, ITEM_MISSILE, ITEM_MISSILE_WIDTH, ITEM_MISSILE_HEIGHT, ITEM_ENERGY_COUNT);
//}
//
//void Missile::Init(float posX, float posY)
//{
//	this->pos_x = posX;
//	this->pos_y = posY;
//	this->isActive = true;
//	time_survive = ITEM_TIME_SURVIVE;
//}
//
//void Missile::Render()
//{
//	D3DXVECTOR3 position;
//	position.x = pos_x;
//	position.y = pos_y;
//	position.z = 0;
//
//	if (!isActive)
//		return;
//
//	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
//	missile->drawSprite(missile->getWidth(), missile->getHeight(), position);
//	spriteHandler->End();
//}
//
//void Missile::Update(float t)
//{
//	DWORD now = GetTickCount();
//	if (now - last_time > 1000 / ANIMATE_RATE)
//	{
//		missile->updateSprite();
//		last_time = now;
//	}
//}
//
//void Missile::Destroy()
//{
//	isActive = false;
//}