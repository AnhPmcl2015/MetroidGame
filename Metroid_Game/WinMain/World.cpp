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

	texture = new Texture();
	//Khởi tạo các đối tượng trong World
	samus = new Samus(spriteHandler, this);
	manager = new Manager();
	/*for (int i = 0; i < bulletList.size(); i++)
		bulletList[i] = new Bullet();*/
}

World::~World()
{
	//delete(samus);
	delete(texture);
}

void World::Update(float t)
{
	samus->Update(t);
	updateBullet(t);
}

void World::Render()
{
	samus->Render();
}

void World::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	LPDIRECT3DTEXTURE9 samus_texture = texture->loadTexture(d3ddv, TEXTURE_GAME_CHARACTERS);
	if (samus_texture == NULL)
		trace(L"Unable to load PlayerTexture");
	samus->InitSprites(d3ddv, samus_texture);

	LPDIRECT3DTEXTURE9 bullet_texture = texture->loadTexture(d3ddv, TEXTURE_GAME_CHARACTERS);
	if (samus_texture == NULL)
		trace(L"Unable to load PlayerTexture");
	bullet->InitSprites(d3ddv, bullet_texture);
	weapon.push_back(bullet);
}

void World::updateBullet(float t)
{
	for (int i = 0; i < weapon.size(); i++)
	{
		weapon[i]->Update(t);
		if (!bulletList[i]->isActive) {
			delete bulletList[i];
			bulletList[i] = NULL;
			bulletList.erase(bulletList.begin() + i);
		}
	}
}



