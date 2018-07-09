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

}

World::~World()
{
}

void World::Update(float t)
{
}

void World::Render()
{

}

void World::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{

}
