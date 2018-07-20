#include "Bullet.h"

Bullet::Bullet()
{
	vx = 0;
	vy = 0;
	liveTime = 0;
}

Bullet::Bullet(float x_pos, float y_pos, float _vx, float _vy)
{
	pos_x = x_pos;
	pos_y = y_pos;
	vx = _vx;
	vy = _vy;
}

Bullet::Bullet(LPD3DXSPRITE spriteHandler, World * manager) {
	this->spriteHandler = spriteHandler;
	this->manager = manager;
	this->isActive = false;
	this->type = BULLET;
}

Bullet::~Bullet() {
	this->isActive = false;
}

void Bullet::InitSprites(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DTEXTURE9 texture) {
	if (d3ddv == NULL) return ;
	//cai dat sprite o day
	bulletSprite = new Sprite(spriteHandler, texture, BULLET_PATH, WIDTH_BULLET, HEIGHT_BULLET, 1);
}

void Bullet::InitPostition() {

}

BULLET_STATE Bullet::GetState()
{
	return state;
}

void Bullet::SetState(BULLET_STATE value)
{
	state = value;
}

void Bullet::ResetAllSprites()
{
	bulletSprite->Reset();
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

void Bullet::SetDirection(BulletDirection value)
{
	bulletdir = value;
}

BulletDirection Bullet::GetDirection()
{
	return bulletdir;
}