#pragma once
#include "Enemy.h"
#include "Define.h"


class Zoomer : public Enemy
{
protected:
	ZOOMER_STATE state;
	ZOOMER_DIRECTION direction;
	ZOOMER_DIRECTION initDirection;

	Sprite * top;
	Sprite * bottom;
	Sprite * left;
	Sprite * right;
public:
	Zoomer();
	Zoomer(LPD3DXSPRITE spriteHandler, World * manager, OBJECT_TYPE enemy_type);
	~Zoomer();
	void InitSprites(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DTEXTURE9 texture);
	void setState(ZOOMER_STATE _state);
	ZOOMER_STATE getState();

	void setDirection(ZOOMER_DIRECTION direction);
	ZOOMER_DIRECTION getDirection();
	
	void setInitDirection(ZOOMER_DIRECTION direction);
	ZOOMER_DIRECTION getInitDirection();

	void setVelocity();

	//============== OVERRIDE VIRTUAL METHOD ===================
	virtual void Update(float t);
	virtual void Render();
	virtual void setEnemyStatefromString(string _state);
	virtual void startMoving();
	//============== END OVERRIDE VIRTUAL METHOD ===============
	void Destroy();
};
