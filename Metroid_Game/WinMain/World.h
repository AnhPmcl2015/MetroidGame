#pragma once
#ifndef _WORLD_H_
#define _WORLD_H_

#include <d3dx9.h>
#include "Define.h"
#include "Samus.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "Texture.h"
#include <vector>
using namespace std;

/*
Class này chứa tất cả những thứ trong Game
Các class khác chứa con trỏ đến class này để thao tác với các đối tượng trong class này
*/

class World
{
public:
	Texture * texture;
	Metroid * metroid;
	Samus * samus;
	Manager * manager;
	Bullet * bullet;
	//vector<Bullet*> bulletList = vector<Bullet*> ();
	vector<Bullet*> weapon = vector<Bullet*>(0);
	LPD3DXSPRITE spriteHandler;

	World();
	World(LPD3DXSPRITE spriteHandler, Metroid * metroid);
	~World();

	void Update(float t);
	void Render();
	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);

	void updateBullet(float t);

};

#endif // !_WORLD_H_

