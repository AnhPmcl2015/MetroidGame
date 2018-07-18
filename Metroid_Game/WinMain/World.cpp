#include "World.h"
#include <vector>

using namespace std;

World::World()
{
}

World::World(LPD3DXSPRITE spriteHandler, Metroid * metroid)
{
	//Gán
	this->spriteHandler = spriteHandler;
	this->metroid = metroid;

	//Khởi tạo các đối tượng trong World
	samus = new Samus(spriteHandler, this);
}

World::~World()
{
	//delete(samus);
}

void World::Update(float t)
{
	samus->Update(t);
	//updateBullet(t);
}

void World::Render()
{
	samus->Render();
	samus->renderBullet();
}

void World::InitSprites(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DTEXTURE9 texture)
{
	samus->InitSprites(d3ddv, texture);
}

//void World::updateBullet(float t)
//{
//	for (int i = 0; i < bulletList.size(); i++)
//	{
//		Bullet currentBullet = bulletList[i];
//		currentBullet.Update(t);
//		if (!currentBullet.isActive) {
//			bulletList.erase(bulletList.begin() + i);
//		}
//	}
//}



