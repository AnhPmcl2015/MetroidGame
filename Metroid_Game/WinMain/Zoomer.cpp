#include "Zoomer.h"
#include "World.h"

Zoomer::Zoomer()
{

}

Zoomer::Zoomer(LPD3DXSPRITE spriteHandler, World * manager, OBJECT_TYPE enemy_type) : Enemy(spriteHandler, manager)
{
	this->setType(enemy_type);
	this->isActive = false;

	//Set vận tốc
	vx = 0.0f;
	vy = 0.0f;
}


Zoomer::~Zoomer()
{
	delete(top);
	delete(bottom);
	delete(left);
	delete(right);
}

void Zoomer::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	LPWSTR top_path = NULL, bottom_path = NULL, left_path = NULL, right_path = NULL;
	Texture texture2, texture3;
	LPDIRECT3DTEXTURE9 texture = texture2.loadTexture(d3ddv, ENEMY_SPRITE_PATH);
	if (texture == NULL)
		trace(L"Unable to load zoomerTexture");
	switch (this->type)
	{
	case ZOOMER_YELLOW:
		top_path = ZOOMER_YELLOW_TOP;
		bottom_path = ZOOMER_YELLOW_BOTTOM;
		left_path = ZOOMER_YELLOW_LEFT;
		right_path = ZOOMER_YELLOW_RIGHT;

		//Khởi tạo máu
		//health = HEALTH_BEDGEHOG_YELLOW;

		//Khởi tạo sát thương
		//damage = DAMAGE_BEDGEHOG;
		break;
	case ZOOMER_PINK:
		top_path = ZOOMER_PINK_UP;
		bottom_path = ZOOMER_PINK_BOTTOM;
		left_path = ZOOMER_PINK_LEFT;
		right_path = ZOOMER_PINK_RIGHT;

		//Khởi tạo máu
		//health = HEALTH_ZOOMER_PINK;

		//Khởi tạo sát thương
		//damage = DAMAGE_ZOOMER;
		break;
	}

	//// Khởi tạo sprite
	top = new Sprite(spriteHandler, texture, top_path, ZOOMER_WIDTH, ZOOMER_HEIGHT, ZOOMER_SPRITE_COUNT);
	bottom = new Sprite(spriteHandler, texture, bottom_path, ZOOMER_WIDTH, ZOOMER_HEIGHT, ZOOMER_SPRITE_COUNT);
	left = new Sprite(spriteHandler, texture, left_path, ZOOMER_WIDTH, ZOOMER_HEIGHT, ZOOMER_SPRITE_COUNT);
	right = new Sprite(spriteHandler, texture, right_path, ZOOMER_WIDTH, ZOOMER_HEIGHT, ZOOMER_SPRITE_COUNT);
}

void Zoomer::setEnemyStatefromString(string _state) {
	if (_state == "ON_ZOOMER_UP") {
		setState(ON_ZOOMER_UP);
	}
	else if (_state == "ON_ZOOMER_LEFT") {
		setState(ON_ZOOMER_LEFT);
	}
	else if (_state == "ON_ZOOMER_RIGHT") {
		setState(ON_ZOOMER_RIGHT);
	}
	else if (_state == "ON_ZOOMER_BOTTOM") {
		setState(ON_ZOOMER_BOTTOM);
	}
}

void Zoomer::setState(ZOOMER_STATE _state) {
	state = _state;
}


ZOOMER_STATE Zoomer::getState() {
	return state;
}

void Zoomer::startMoving()
{
	if (direction == "RIGHT") {
		setVelocityX(ZOOMER_SPEED);
		setVelocityY(0);
	}
	else if (direction == "LEFT") {
		setVelocityX(-ZOOMER_SPEED);
		setVelocityY(0);
	}
	else if (direction == "UP") {
		setVelocityY(-ZOOMER_SPEED);
		setVelocityX(0);
	}
	else if (direction == "DOWN") {
		setVelocityY(ZOOMER_SPEED);
		setVelocityX(0);
	}
}

void Zoomer::setSamusLocation(int _posX, int _posY)
{
}


void Zoomer::Update(float t)
{
	if (!isActive) return;

	pos_x += vx * t;
	pos_y += vy * t;

	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_ENEMY_RATE)
	{
		switch (state)
		{
		case ON_ZOOMER_UP:
			top->updateSprite();
			break;
		case ON_ZOOMER_BOTTOM:
			bottom->updateSprite();
			break;
		case ON_ZOOMER_LEFT:
			left->updateSprite();
			break;
		case ON_ZOOMER_RIGHT:
			right->updateSprite();
			break;
		}
		last_time = now;
	}

}

void Zoomer::Render()
{
	D3DXVECTOR3 position;
	position.x = pos_x;
	position.y = pos_y;
	position.z = 0;

	// Nếu không active thì không render
	if (!isActive)
		return;
	switch (state)
	{
	case ON_ZOOMER_UP:
		top->drawSprite(top->getWidth(), top->getHeight(), position);
		break;
	case ON_ZOOMER_BOTTOM:
		bottom->drawSprite(bottom->getWidth(), bottom->getHeight(), position);
		break;
	case ON_ZOOMER_LEFT:
		left->drawSprite(left->getWidth(), left->getHeight(), position);
		break;
	case ON_ZOOMER_RIGHT:
		right->drawSprite(right->getWidth(), right->getHeight(), position);
		break;
	}
}

void Zoomer::Destroy()
{
	this->isActive = false;
}