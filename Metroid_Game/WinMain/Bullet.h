#pragma once
#include "Sprite.h"
#include "GameObject.h"
#include "trace.h"
#include "World.h"
#include "Define.h"

enum BULLET_STATE {
	SAMUS_BULLET,
	KREE_BULLET,
	BOSS_BULLET
};

class Bullet : public GameObject {
protected:
	Sprite * bulletSprite;

	BULLET_STATE state = SAMUS_BULLET;

public:
	bool isActive;
	//ket thuc thoi gian liveTime, xem nhu vien dan bay het duong bay -> huy vien dan
	float liveTime = 0;
	
	Bullet();
	Bullet(LPD3DXSPRITE spriteHandler);
	~Bullet();

	void InitSprites(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DTEXTURE9 texture);
	void InitPostition();

	BULLET_STATE GetState();
	void SetState(BULLET_STATE value);
	bool isBulletActive();

	void ResetAllSprites();
	bool GetStateActive();

	//================ OVERRIDE VIRTUAL METHOD ==================
	void Reset(int  x, int y);
	void Update(float t);
	void Render();
	void Destroy();
	//================= END OVERRIDE VIRTUAL METHOD =============

};
