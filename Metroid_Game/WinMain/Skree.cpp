#include "Skree.h"
#include "World.h"
#include "Define.h"

Skree::Skree()
{
}

Skree::Skree(LPD3DXSPRITE spriteHandler, World * manager, ENEMY_TYPE enemy_type) : Enemy(spriteHandler, manager)
{
	this->setType(ENEMY);
	this->enemy_type = enemy_type;
	this->isActive = false;

	//Set animate rate ban đầu
	animate_rate = SKREE_STANDARD_ANIMATE_RATE;
	setState(ON_HANGING);
}

Skree::~Skree()
{
	delete(skree);
}

void Skree::setState(SKREE_STATE _state)
{
	state = _state;
}

SKREE_STATE Skree::getState()
{
	return state;
}

void Skree::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	if (d3ddv == NULL) return;
	//Create sprite handler
	HRESULT result = D3DXCreateSprite(d3ddv, &spriteHandler);
	if (result != D3D_OK) return;

	Texture texture3;
	LPDIRECT3DTEXTURE9 texture = texture3.loadTexture(d3ddv, ENEMY_SPRITE_PATH);
	if (texture == NULL)
		trace(L"Unable to load skreeTexture");

	// Khởi tạo sprite
	skree = new Sprite(spriteHandler, texture, SKREE_PATH, SKREE_WIDTH, SKREE_HEIGHT, SKREE_COUNT);
}
void Skree::Update(float t)
{
//	grid->add(this);
	if (!isActive) return;

	//tinh khoang cach voi samus bang dinh luat Pytago
	float rs = sqrt(((abs)(pos_x - samus_PosX)) * ((abs)(pos_x - samus_PosX)) + ((abs)(pos_y - samus_PosY) * (abs)(pos_y - samus_PosY)));

	if (rs < SKREE_DISTANCE_TO_SAMUS) {
		animate_rate = SKREE_BOOST_ANIMATE_RATE;
		vy = SKREE_SPEED;
		if (samus_PosX < pos_x)
			vx = -SKREE_SPEED;
		else if (samus_PosX > pos_x)
			vx = SKREE_SPEED;
		else
			vx = 0;
	}

	pos_x += vx * t;
	pos_y += vy * t;

	DWORD now = GetTickCount();
	if (now - last_time > 1000 / animate_rate)
	{
		skree->updateSprite();
		last_time = now;
	}
}

void Skree::Render()
{
	D3DXVECTOR3 position;
	position.x = pos_x;
	position.y = pos_y;
	position.z = 0;

	// Nếu không active thì không render
	if (!isActive)
		return;
	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
	skree->drawSprite(skree->getWidth(), skree->getHeight(), position);
	spriteHandler->End();
}

void Skree::setEnemyStatefromString(string _state)
{

}

void Skree::startMoving()
{
}

void Skree::startMovingBySamus(int _posX, int _posY)
{
	samus_PosX = _posX;
	samus_PosY = _posY;
	//animate_rate = SKREE_BOOST_ANIMATE_RATE;
}

void Skree::Destroy()
{
	//// Effect explosion

	//// Destroy
	//vx = 0;

	//manager->explsEffect->Init(this->pos_x, this->pos_y);	 // Xảy ra lỗi khi giết những mục tiêu to (Ridley, Mother Brain)
	//														 // Drop item after destroyed
	//int random;

	///* initialize random seed: */
	//srand(time(NULL));

	///* generate secret number between 1 and 10: */
	//random = rand() % 10 + 1;

	//if (random == 1 || random == 5)
	//	manager->energyItem->Init(this->pos_x, this->pos_y);
	//else if (random == 7 || random == 9)
	//	manager->missileItem->Init(this->pos_x, this->pos_y);
	//Enemy::Destroy();
}