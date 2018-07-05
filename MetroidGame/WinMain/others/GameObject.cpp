#include "GameObject.h"

GameObject::GameObject(
	float x, 
	float y, 
	float rotation, 
	float speed, 
	float maxSpeed, 
	/*CollisionManager* collisionManager, */
	SpriteManager* spritemanager, 
	GraphicsDevice* gDevice
	/*,Sound* sound*/
	)
{
	float twopi = pi * 2;
	position.x = x;
	position.y = y;
	position.z = 0;

	if (rotation > twopi)
		rotation = twopi;
	if (rotation < 0)
		rotation = 0;

	if (speed > maxSpeed)
		speed = maxSpeed;
	if (speed < 0)
		speed = 0;

	_rotation = rotation;
	_speed = speed;

	velocity.x = cos(rotation)*speed;
	velocity.y = sin(rotation)*speed;
	velocity.z = 0;

	_MaxSpeed = maxSpeed;

	//_collisionManager = collisionManager;
	_spriteManager = spritemanager;
	_gDevice = gDevice;
	//_sound = sound;
}

bool GameObject::Initialize(LPDIRECT3DDEVICE9 device)
{
	return true;
}

void GameObject::Update(float gameTime)
{
}

void GameObject::Draw(float gameTime)
{
}

ObjectStatus GameObject::GetStatus() const
{
	return status;
}

void GameObject::SetSpeed(float speed)
{
	if (speed >= 0 && speed <= _MaxSpeed)
	{
		_speed = speed;
		velocity.x = cos(_rotation)*speed;
		velocity.y = sin(_rotation)*speed;
		velocity.z = 0;
	}
}

D3DXVECTOR3 GameObject::getPosition()
{
	return position;
}
GameObject::~GameObject()
{
	if (_Gs)
	{
		delete _Gs;
		_Gs = nullptr;
	}
}