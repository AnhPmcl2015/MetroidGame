#include"BackGround.h"

BackGround::BackGround(float x, float y, float rotation, float speed, float maxSpeed, /*CollisionManager* collisionManager,*/ SpriteManager* spriteManager, GraphicsDevice* gDevice/*, Sound* sound*/) :
GameObject(x, y, rotation, speed, maxSpeed,/* collisionManager,*/ spriteManager, gDevice/*,sound*/)
{

}

bool BackGround::Initialize(LPDIRECT3DDEVICE9 device)
{
	if (!intro)
	{
		intro = new GameSprite(_spriteManager);
		if (!intro->initialize(device, _gDevice->getSceneTex(),INTRO_INDEX, SCENE_COUNT))
		{
			return false;
		}
	}
	if (!selectStart)
	{
		selectStart = new GameSprite(_spriteManager);
		if (!selectStart->initialize(device, _gDevice->getSceneTex(), START_INDEX, SCENE_COUNT))
		{
			return false;
		}
	}
	if (!selectContinue)
	{
		selectContinue = new GameSprite(_spriteManager);
		if (!selectContinue->initialize(device, _gDevice->getSceneTex(), CONTINUE_INDEX, SCENE_COUNT))
		{
			return false;
		}
	}

	is_initialize = true;

	return true;
}


void BackGround::Update(float gameTime){}

void BackGround::Draw(float gameTime)
{
	switch (index)
	{
	case 0:
	{
		intro->Draw(gameTime, position);
		break;
	}
	case 1:
	{
		selectStart->Draw(gameTime, position);
		break;
	}
	case 2:
	{
		selectContinue->Draw(gameTime, position);
		break;
	}
	default:
		break;
	}
}

BackGround::~BackGround()
{

}