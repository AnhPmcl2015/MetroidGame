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
		case STAND_RIGHT:
			standRight->drawSprite(75, 5, standRight->getWidth(), standRight->getHeight(), position);
			break;
		case STAND_LEFT:
			standLeft->drawSprite(75, 43, standLeft->getWidth(), standLeft->getHeight(), position);
			break;
		case RUNNING_LEFT:
			runLeft->drawSprite(0, 0, runLeft->getWidth(), runLeft->getHeight(), position);
			break;
		case RUNNING_RIGHT:
			runRight->drawSprite(0, 41, runRight->getWidth(), runRight->getHeight(), position);
			break;
		case STAND_SHOOT_UP_LEFT:
			standShootL->drawSprite(335, 39, standShootL->getWidth(), standShootL->getHeight(), position);
			break;
		case STAND_SHOOT_UP_RIGHT:
			standShootR->drawSprite(335, 1, standShootR->getWidth(), standShootR->getHeight(), position);
			break;
		case MORPH_LEFT:
			morphLeft->drawSprite(100, 52, morphLeft->getWidth(), morphLeft->getHeight(), position);
			break;
		case MORPH_RIGHT:
			morphRight->drawSprite(100, 14, morphRight->getWidth(), morphRight->getHeight(), position);
			break;
		case RUN_SHOOTING_LEFT:
			runShootL->drawSprite(460, 44, runShootL->getWidth(), runShootL->getHeight(), position);
			break;
		case RUN_SHOOTING_RIGHT:
			runShootR->drawSprite(460, 6, runShootR->getWidth(), runShootR->getHeight(), position);
			break;
		case JUMP_LEFT:
			jumpLeft->drawSprite(300, 50, jumpLeft->getWidth(), jumpLeft->getHeight(), position);
			break;
		case JUMP_RIGHT:
			jumpRight->drawSprite(300, 12, jumpRight->getWidth(), jumpRight->getHeight(), position);
			break;
		case TRANSFORM_BALL_LEFT:
			ballLeft->drawSprite(200, 24, ballLeft->getWidth(), ballLeft->getHeight(), position);
			break;
		case TRANSFORM_BALL_RIGHT:
			ballRight->drawSprite(200, 62, ballRight->getWidth(), ballRight->getHeight(), position);
			break;
		case JUMP_SHOOT_UP_LEFT:
			jumpShootL->drawSprite(360, 39, jumpShootL->getWidth(), jumpShootL->getHeight(), position);
			break;
		case JUMP_SHOOT_UP_RIGHT:
			jumpShootR->drawSprite(360, 0, jumpShootR->getWidth(), jumpShootR->getHeight(), position);
			break;
		}

		spriteHandler->End();
	}	
}

Samus::Samus()
{
	standRight = NULL;

	/*width = 40;
	height = 64;*/

	this->isActive = true;
	state = STAND_LEFT;
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
	delete(standRight);
}

void Samus::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	if (d3ddv == NULL) return;

	//Create instance of sprites
	standRight = new Sprite(spriteHandler, TEXTURE_GAME_CHARACTERS, WIDTH_SAMUS_STAND, HEIGHT_SAMUS_STAND, 4, COUNT_SAMUS_STAND);
	standLeft = new Sprite(spriteHandler, TEXTURE_GAME_CHARACTERS, WIDTH_SAMUS_STAND, HEIGHT_SAMUS_STAND, 25, COUNT_SAMUS_STAND);
	runRight = new Sprite(spriteHandler, TEXTURE_GAME_CHARACTERS, WIDTH_SAMUS_RUNRIGHT, HEIGHT_SAMUS_RUNRIGHT, 1, COUNT_SAMUS_RUNRIGHT);
	runLeft = new Sprite(spriteHandler, TEXTURE_GAME_CHARACTERS, WIDTH_SAMUS_RUNLEFT, HEIGHT_SAMUS_RUNLEFT, 22, COUNT_SAMUS_RUNLEFT);
	standShootL = new Sprite(spriteHandler, TEXTURE_GAME_CHARACTERS, WIDTH_SAMUS_STANDSHOOTUP, HEIGHT_SAMUS_STANDSHOOTUP, 35, COUNT_SAMUS_STANDSHOOTUP);
	standShootR = new Sprite(spriteHandler, TEXTURE_GAME_CHARACTERS, WIDTH_SAMUS_STANDSHOOTUP, HEIGHT_SAMUS_STANDSHOOTUP, 14, COUNT_SAMUS_STANDSHOOTUP);
	morphLeft = new Sprite(spriteHandler, TEXTURE_GAME_CHARACTERS, WIDTH_SAMUS_MORPHLEFT, HEIGHT_SAMUS_MORPHLEFT, 26, COUNT_SAMUS_MORPHLEFT);
	morphRight = new Sprite(spriteHandler, TEXTURE_GAME_CHARACTERS, WIDTH_SAMUS_MORPHRIGHT, HEIGHT_SAMUS_MORPHRIGHT, 5, COUNT_SAMUS_MORPHRIGHT);
	runShootL = new Sprite(spriteHandler, TEXTURE_GAME_CHARACTERS, WIDTH_SAMUS_RUNSHOOTleft, HEIGHT_SAMUS_RUNSHOOTleft, 40, COUNT_SAMUS_RUNSHOOTleft);
	runShootR = new Sprite(spriteHandler, TEXTURE_GAME_CHARACTERS, WIDTH_SAMUS_RUNSHOOTright, HEIGHT_SAMUS_RUNSHOOTright, 19, COUNT_SAMUS_RUNSHOOTright);
	jumpLeft = new Sprite(spriteHandler, TEXTURE_GAME_CHARACTERS, WIDTH_SAMUS_JUMP, HEIGHT_SAMUS_JUMP, 34, COUNT_SAMUS_JUMP);
	jumpRight = new Sprite(spriteHandler, TEXTURE_GAME_CHARACTERS, WIDTH_SAMUS_JUMP, HEIGHT_SAMUS_JUMP, 13, COUNT_SAMUS_JUMP);
	ballLeft = new Sprite(spriteHandler, TEXTURE_GAME_CHARACTERS, WIDTH_SAMUS_BALLLEFT, HEIGHT_SAMUS_BALLLEFT, 30, COUNT_SAMUS_BALLLEFT);
	ballRight = new Sprite(spriteHandler, TEXTURE_GAME_CHARACTERS, WIDTH_SAMUS_BALLRIGHT, HEIGHT_SAMUS_BALLRIGHT, 9, COUNT_SAMUS_BALLRIGHT);
	jumpShootL = new Sprite(spriteHandler, TEXTURE_GAME_CHARACTERS, WIDTH_SAMUS_JUMPSHOOTleft, HEIGHT_SAMUS_JUMPSHOOTleft, 36, COUNT_SAMUS_JUMPSHOOTleft);
	jumpShootR = new Sprite(spriteHandler, TEXTURE_GAME_CHARACTERS, WIDTH_SAMUS_JUMPSHOOTright, HEIGHT_SAMUS_JUMPSHOOTright, 15, COUNT_SAMUS_JUMPSHOOTright);
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
	state = STAND_RIGHT;
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
	standRight->Reset();
	standLeft->Reset();
	runRight->Reset();
	runLeft->Reset();
	standShootL->Reset();
	standShootR->Reset();
	morphLeft->Reset();
	morphRight->Reset();
	runShootL->Reset();
	runShootR->Reset();
	jumpLeft->Reset();
	jumpRight->Reset();
	ballLeft->Reset();
	ballRight->Reset();
	jumpShootL->Reset();
	jumpShootR->Reset();
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
		case STAND_RIGHT:
			standRight->updateSprite();
			break;
		case STAND_LEFT:
			standLeft->updateSprite();
			break;
		case RUNNING_LEFT:
			runLeft->updateSprite();
			break;
		case RUNNING_RIGHT:
			runRight->updateSprite();
			break;
		}
		last_time = now;
	}
}
//----------------------------------------------------------