#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "../others/GameObject.h"
#include "../others/DataSet.h"

class BackGround :public GameObject
{
public:
	BackGround(
		float x, 
		float y, 
		float rotation, 
		float speed, 
		float maxSpeed, 
		//CollisionManager* collisionManager, 
		SpriteManager* spriteManager, 
		GraphicsDevice* gDevice/*,
		Sound* sound*/);
	~BackGround();

	bool Initialize(LPDIRECT3DDEVICE9 device);
	void Update(float gameTime);
	void Draw(float gameTime);

	bool is_initialize = false;
	
	int index;
private:

	GameSprite* intro;
	GameSprite* selectStart;
	GameSprite* selectContinue;

};

#endif