﻿#pragma once
#include "Enemy.h"
#include "Define.h"
#include "Math.h"

enum SKREE_STATE
{
	ON_HANGING,
	ON_FALLING
};

class Skree : public Enemy
{
protected:
	Sprite * skree;

	int animate_rate;	// cần biến này vì khi dí theo Samus animate rate thay đổi
public:
	Skree();
	Skree(LPD3DXSPRITE spriteHandler, World * manager, ENEMY_TYPE enemy_type);
	~Skree();

	SKREE_STATE state;
	void setState(SKREE_STATE _state);
	SKREE_STATE getState();

	int samus_PosX = 0;
	int samus_PosY = 0;

	virtual void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	//============== OVERRIDE VIRTUAL METHOD ===================
	virtual void Update(float t);
	virtual void Render();
	virtual void setEnemyStatefromString(string _state);
	virtual void startMoving();
	virtual void startMovingBySamus(int _posX, int _posY);
	//============== END OVERRIDE VIRTUAL METHOD ===============
	void Destroy();
};