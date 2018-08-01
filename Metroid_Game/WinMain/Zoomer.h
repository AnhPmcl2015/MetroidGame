#pragma once
#include "Enemy.h"
#include "Define.h"


class Zoomer : public Enemy
{
protected:
	ZOOMER_STATE state;
	Sprite * top;
	Sprite * bottom;
	Sprite * left;
	Sprite * right;
public:
	Zoomer();
	Zoomer(LPD3DXSPRITE spriteHandler, World * manager, OBJECT_TYPE enemy_type);
	~Zoomer();
	virtual void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void setState(ZOOMER_STATE _state);
	ZOOMER_STATE getState();

	//============== OVERRIDE VIRTUAL METHOD ===================
	virtual void Update(float t);
	virtual void Render();
	virtual void setEnemyStatefromString(string _state);
	virtual void startMoving();
	virtual void setSamusLocation(int _posX, int _posY);
	//============== END OVERRIDE VIRTUAL METHOD ===============
	virtual void Destroy();
};
