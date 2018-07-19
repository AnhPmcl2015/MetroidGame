#include "Bullet.h"

Bullet::Bullet()
{
	vx = 0 ;
	vy = 0;
	liveTime = 0;
}

Bullet::Bullet(LPD3DXSPRITE spriteHandler) {
	this->spriteHandler = spriteHandler;
	//this->manager = manager;
	this->isActive = false;
	this->type = BULLET;
	//initsprite
}

Bullet::~Bullet() {
	this->isActive = false;
}

void Bullet::InitSprites(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DTEXTURE9 texture) {
	if (d3ddv == NULL) return ;
	//cai dat sprite o day
	bulletSprite = new Sprite(spriteHandler, texture, BULLET_PATH, WIDTH_BULLET,HEIGHT_BULLET,COUNT_BULLET);
}

void Bullet::InitPostition() {

}

BULLET_STATE Bullet::GetState()
{
	return BULLET_STATE();
}

void Bullet::SetState(BULLET_STATE value)
{
}

bool Bullet::isBulletActive()
{
	if (isActive == true)
		return true;
	return false;
}

void Bullet::ResetAllSprites()
{
	//not use
}

bool Bullet::GetStateActive()
{
	return false;
}

void Bullet::Reset(int x, int y)
{
	pos_x = x; 
	pos_y = x;
	liveTime = 0;
	vx = 0;
	vy = 0;
}

void Bullet::Update(float t)
{
	if (isActive) {
		pos_x += vx * t;
		pos_y += vy * t;

		//Kiem tra Collision o day

		liveTime = liveTime + t;

		if (liveTime > LIVE_TIME) {
			Destroy();
		}
	}
}

void Bullet::Render()
{
	if (!isActive) {
		return;
	}
	else {
		D3DXVECTOR3 position;
		position.x = pos_x;
		position.y = pos_y;
		position.z = 0;

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);

		bulletSprite->drawSprite(bulletSprite->getWidth(), bulletSprite->getHeight(), position);

		spriteHandler->End();
	}
}

void Bullet::Destroy()
{
	isActive = false;
}

