#pragma once
#ifndef _SAMUS_H
#define _SAMUS_H_
#include "Sprite.h"
#include "GameObject.h"
#include "trace.h"
#include "World.h"

enum SAMUS_STATE {
	APPEARANCE
};

class Samus : public GameObject
{
protected:
	Sprite * appearing;

	SAMUS_STATE state;
public:
	Samus();
	Samus(LPD3DXSPRITE spriteHandler, World * manager);
	~Samus();

	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void InitPostition();

	SAMUS_STATE GetState();
	void SetState(SAMUS_STATE value);

	void ResetAllSprites();
	bool GetStateActive();

	//================ OVERRIDE VIRTUAL METHOD ==================
	void Reset(int  x, int y);
	void Update(float t);
	void Render();
	void Destroy();
	//================= END OVERRIDE VIRTUAL METHOD =============
};
#endif // !_SAMUS_H


