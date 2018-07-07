#include "Samus.h"
#include "Game.h"
#include <vector>
#include "trace.h"
#include "Metroid.h"

void Samus::Render()
{
	// Nếu không active thì không render
	if (!isActive)
		return;
	else {
		D3DXVECTOR3 position;
		position.x = pos_x;
		position.y = pos_y;
		position.z = 0;

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND| D3DXSPRITE_OBJECTSPACE);

		switch (state)
		{
		case APPEARANCE:
			appearing->drawSprite(0, 0, appearing->getWidth(), appearing->getHeight(), position);
			break;
		}

		spriteHandler->End();
	}	
}

Samus::Samus()
{
	appearing = NULL;

	/*width = 40;
	height = 64;*/

	this->isActive = true;
	state = APPEARANCE;
}

void Samus::Destroy()
{
	//Ngưng active
	this->isActive = false;

	//--TO DO: Đưa Samus ra khỏi viewport
}

Samus::Samus(LPD3DXSPRITE spriteHandler, World * manager)
{
	this->spriteHandler = spriteHandler;
	this->manager = manager;
	this->isActive = true;

	//Set type
	this->type = SAMUS;

	/*width = 40;
	height = 50;*/

	gravity = FALLDOWN_VELOCITY_DECREASE;
}

Samus::~Samus()
{
	delete(appearing);
}

void Samus::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	if (d3ddv == NULL) return;

	//Create instance of sprites
	appearing = new Sprite(spriteHandler, L"Player_32x16.png", WIDTH_SAMUS_STAND, HEIGHT_SAMUS_STAND, 1, 1);
}

void Samus::InitPostition()
{
	//--TO DO: This code will be edited soon
	pos_x = 50;
	pos_y = 120;

	vx = 0;
	vx_last = 1.0f;
	vy = 0;

	//Init state of samus
	state = APPEARANCE;
}

SAMUS_STATE Samus::GetState()
{
	return state;
}

void Samus::SetState(SAMUS_STATE value)
{
	state = value;
}

void Samus::ResetAllSprites()
{
	appearing->Reset();
}

bool Samus::GetStateActive()
{
	return isActive;
}

void Samus::Reset(int x, int y)
{
	// Cho samus active trở lại
	this->isActive = true;

	//Đặt lại vị trí
	this->pos_x = x;
	this->pos_y = y;
}

void Samus::Update(float t)
{
	//
	// Update samus status
	//

	vy -= gravity;

	pos_x += vx * t;
	pos_y += vy * t;

	// Animate samus if he is running
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		switch (state)
		{
		case APPEARANCE:
			appearing->updateSprite();
			break;
		}
		last_time = now;
	}
}
//----------------------------------