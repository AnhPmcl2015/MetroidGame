#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#define _USER_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <string>
#include "../drawable/GameSprite.h"
#include "DataSet.h"
//#include"CollisionManager.h"
#include "../drawable/SpriteManager.h"
//#include"Sound.h"

enum class ObjectStatus{ Contruction ,Active, Dying, Dead, Defended, Auto };

const float pi = 3.14159265359;

class GameObject
{
public:
	GameObject(
		float x,
		float y,
		float rotation,
		float speed,
		float maxSpeed,
		//CollisionManager* collisionManager,
		SpriteManager* spritemanager,
		GraphicsDevice* gDevice
		//,Sound* sound
		);
	~GameObject();

	virtual bool Initialize(LPDIRECT3DDEVICE9 device);
	virtual void Update(float gameTime);
	virtual void Draw(float gameTime);

	ObjectStatus GetStatus() const;

	void SetSpeed(float speed);

	D3DXVECTOR3 getPosition();

	SpriteManager* _spriteManager;
protected:

	GraphicsDevice* _gDevice;
	D3DXVECTOR3 position;
	D3DXVECTOR3 velocity;
	float _rotation;
	float _speed;
	ObjectStatus status;
	float _MaxSpeed;
	/*CollisionManager* _collisionManager;
	Sound* _sound;*/
private:
	

	GameSprite* _Gs;

};

#endif