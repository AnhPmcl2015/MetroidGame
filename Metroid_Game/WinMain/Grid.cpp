﻿#include "Grid.h"
#include "Samus.h"
#include "MaruMari.h"
// Lưu vào mảng 2 chiều
// Height khi quy đổi ra sẽ là row -> pos_y tương ứng với row
// Width khi quy đổi ra sẽ là column -> pos_x tương ứng column

Grid::Grid() {
	numOfRow = DEFINE_ROW;
	numOfColumn = DEFINE_COLUMN;
	for (int i = 0; i < numOfRow; i++)
	{
		for (int j = 0; j < numOfColumn; j++)
			cells[i][j] = NULL;
	}
	this->deltaTime = 0.0f;
}

Grid::Grid(int height, int width) {
	this->numOfRow = (int)ceil((float)height * BRICK_SIZE / CELL_SIZE);
	this->numOfColumn = (int)ceil((float)width * BRICK_SIZE / CELL_SIZE);

	for (int i = 0; i < numOfRow; i++)
	{
		for (int j = 0; j < numOfColumn; j++)
			cells[i][j] = NULL;
	}
	this->deltaTime = 0.0f;
}

Grid::~Grid() {
	delete[] cells;
}

// Cái này là dùng danh sách liên kết đôi để lưu trữ và truy xuất object
// Nếu mà mình xác định vị trí object thuộc cell nào rồi thì mình đưa nó vào đầu danh sách liên kết đôi đó
// Ở đây 1 cell là 1 danh sách liên kết đôi
// Giải thuật ở dưới là thêm vào đầu dslk đôi
void Grid::add(GameObject* object) {
	// Lưu trữ lại giá trị cũ của object sau mỗi lần update
	object->setlastPosX(object->getPosX());
	object->setlastPosY(object->getPosY());

	// Xác định object đang nằm ở grid nào
	int column = floor(object->getPosX() / CELL_SIZE); // trừ đi 1 do mảng bắt đầu từ 0
	int row = floor(object->getPosY() / CELL_SIZE);


	// Thêm object vào đầu của list
	object->previousUnit = NULL;
	object->nextUnit = cells[row][column];
	cells[row][column] = object;

	if (object->nextUnit != NULL) {
		object->nextUnit->previousUnit = object;
	}
}

void Grid::resetGrid(int width, int height) {
	this->numOfRow = (int)ceil(height * BRICK_SIZE / CELL_SIZE);
	this->numOfColumn = (int)ceil(width * BRICK_SIZE / CELL_SIZE);

	for (int i = 0; i < numOfRow; i++)
	{
		for (int j = 0; j < numOfColumn; j++)
			cells[i][j] = NULL;
	}
	this->deltaTime = 0.0f;
}

// Dùng để xét cái ô cell hiện tại, như là va chạm của object mình đang xét với các object còn lại
// Kế bên đó là xét với các cell lân cận
// Theo người ta nói các cell càn xét thêm là:
//		1 ô trên,
//		1 ô trái trên
//		1 ô trái
//		1 ô trái dưới
// Ở đây ta cho vào vòng lặp là xét tất cả các object với nhau
bool Grid::handleCell(GameObject* object, int row, int column) {
	bool isCollision = false;
	GameObject *cell = cells[row][column];
	if (object != NULL) {
		if ((object->getType() != BRICK || object->getType() != ITEM) && object->isActive) {
			// Đầu tiên là xét trong chính cell của nó trước
			if (this->handleObject(object, cell))
				isCollision = true;

			// Còn đây là xét với các cell kế bên
			if (row > 0)
				if (this->handleObject(object, cells[row - 1][column])) // phia tren
					isCollision = true;
			if (row < this->numOfRow - 1)
				if (this->handleObject(object, cells[row + 1][column])) // phia duoi
					isCollision = true;

			if (object->vx <= 0) {    // Neu van toc nang giam thi xet ben trai
				if (row > 0 && column > 0)
					if (this->handleObject(object, cells[row - 1][column - 1])) // trai tren
						isCollision = true;
				if (column > 0)
					if (this->handleObject(object, cells[row][column - 1])) // phia trai
						isCollision = true;
				if (column > 0 && row < numOfRow - 1)
					if (this->handleObject(object, cells[row + 1][column - 1])) // trai duoi
						isCollision = true;
			}
			else {
				if (row > 0 && column < this->numOfColumn - 1)
					if (this->handleObject(object, cells[row - 1][column + 1])) // phai tren
						isCollision = true;
				if (column < this->numOfColumn - 1)
					if (this->handleObject(object, cells[row][column + 1]))    // ben phai
						isCollision = true;
				if (column < this->numOfColumn - 1 && row < this->numOfRow - 1)
					if (this->handleObject(object, cells[row + 1][column + 1])) // phai duoi
						isCollision = true;
			}
			
		}
	}
	return isCollision;
}

// Dùng để xét giữa object đang xét với các object còn lại trong cell hoặc cell lân cận
// Nếu mà khoảng cách giữa object đang xét với các object khác nhỏ hơn khoảng cách có thể va chạm
// Lúc đó sẽ xét va chạm
bool Grid::handleObject(GameObject *object, GameObject* otherObject) {
	bool isCollision = false;
	while (otherObject != NULL) {
		if (object != otherObject && otherObject->isActive) {
			// Mình phải tính va chạm là từ khoảng cách giữa 2 điểm từ tâm của nó
			int x1 = (int)((object->pos_x + object->width/2));
			int y1 = (int)((object->pos_y + object->height/2));
			D3DXVECTOR2 objectPos(x1, y1);

			int x2 = (int)((otherObject->pos_x + otherObject->width/2));
			int y2 = (int)((otherObject->pos_y + otherObject->height/2));
			D3DXVECTOR2 otherPos(x2, y2);
			if (Math::distance(objectPos, otherPos) < 150) {
				if (handleCollision(object, otherObject))
					isCollision = true;
			}
		}
		otherObject = otherObject->nextUnit;
	}
	return isCollision;
}

// Xét va chạm và cập nhật tình trạng của 2 object
bool Grid::handleCollision(GameObject *object, GameObject *otherObject) {
	COLLISION_DIRECTION collisionDirection = NONE;
	float collisionTime = object->sweptAABB(otherObject, collisionDirection, this->getDeltaTime());
	
	if (collisionDirection != NONE) {
		if (object->getType() == SAMUS) {
			this->handleSamus(object, otherObject, collisionDirection, collisionTime);
		}
		else if (object->getType() == ZOOMER_PINK || object->getType() == ZOOMER_YELLOW) {
			this->handleZoomer(object, otherObject, collisionDirection, collisionTime);
		}
		else if (object->getType() == BULLET) {
			this->handleSamusBullet(object, otherObject, collisionDirection, collisionTime);
		}
		else if (object->getType() == SKREE) {
			this->handleSkree(object, otherObject, collisionDirection, collisionTime);
		}
		else if (object->getType() == RIDLEY) {
			this->handleRidley(object, otherObject, collisionDirection, collisionTime);
		}
		return true;
	}
	else {
		return false;
	}
}

void Grid::handleSamus(GameObject* object, GameObject* otherObject, COLLISION_DIRECTION collisionDirection, float collisionTime) {
	Samus* samus = dynamic_cast<Samus*>(object);
	//object->pos_y += object->vy * collisionTime *this->getDeltaTime();
	OBJECT_TYPE otherObjectType = otherObject->getType();
	if (collisionDirection == BOTTOM)
	{
		samus->isBottom = true;
		switch (otherObjectType) {
		case BRICK: {
			samus->isCollideWithEnemy = false;
			object->pos_y += object->vy * collisionTime *this->getDeltaTime();
			if (samus->isJumping) {
				samus->isJumping = false;
				samus->isOnGround = true;
				samus->isFalling = false;
				if (!samus->getIsBall()) {
					samus->pos_y -= (64 - samus->getHeight());
					samus->setWidth(32);
					samus->setHeight(64);
					switch (samus->GetState()) {
					case JUMP_RIGHT: case MORPH_RIGHT: {
						samus->SetState(STAND_RIGHT);
						samus->isMorphing = false;
						break;
					}
					case JUMP_LEFT: case MORPH_LEFT: {
						samus->SetState(STAND_LEFT);
						samus->isMorphing = false;
						break;
					}
					case JUMP_SHOOT_UP_LEFT: {
						samus->SetState(STAND_SHOOT_UP_LEFT);
						break;
					}

					case JUMP_SHOOT_UP_RIGHT: {
						samus->SetState(STAND_SHOOT_UP_RIGHT);
						break;
					}
				}
				
				}
			}
			
		}
		}
	}
	else if (collisionDirection == TOP) {
		samus->isTop = true;
		switch (otherObjectType) {
		case BRICK: {
			object->pos_y += object->vy * collisionTime*this->getDeltaTime();

			break;
		}
		}
	}
	else if (collisionDirection == RIGHT) {
		samus->isRight = true;
		switch (otherObjectType) {
		case BRICK: {
			object->pos_x += object->vx * collisionTime*this->getDeltaTime();
			break;
		}
		case ZOOMER_YELLOW: case ZOOMER_PINK: case RIDLEY:
		{
			samus->isCollideWithEnemy = true;
			samus->isRight = true;
			//samus->vx = ;
			break;
		}
		case GATE_BLOCK: {
			samus->isRight = false;
			break;
		}
		case GATE:
			Gate * gate = dynamic_cast<Gate*>(otherObject);
			if (gate->GetGateType() == GATE_RIGHT && gate->getGateState() == CLOSE)
			{
				gate->setIsLeft(true);
				//gate->setGateState(DESTROYING);
				if (samus->pos_x == gate->pos_x + gate->width)
					gate->setGateState(CLOSE);
				samus->pos_x += samus->vx * this->getDeltaTime();
			}
			else if (gate->GetGateType() == GATE_RIGHT && gate->getGateState() == OPEN)
			{
				samus->isRight = false;
				samus->pos_x += samus->vx * this->getDeltaTime();
				if (samus->pos_x == gate->pos_x + gate->width)
					gate->setGateState(CLOSE);
			}
			if (gate->GetGateType() == GATE_LEFT && gate->getGateState() == CLOSE)
			{
				//gate->setGateState(OPEN);
				samus->isRight = true;
			}
			else if (gate->GetGateType() == GATE_LEFT && gate->getGateState() == OPEN)
			{
				samus->isRight = false;
			}
			break;
		}
	}
	else if (collisionDirection == LEFT) {
		samus->isLeft = true;
		switch (otherObjectType) {
		case BRICK: {
			object->pos_x += object->vx * collisionTime*this->getDeltaTime();
			break;
		}
		case ZOOMER_YELLOW : case ZOOMER_PINK: case RIDLEY:
		{
			samus->isLeft = true;
			samus->isCollideWithEnemy = true;
			samus->pos_x += 45;
			break;
		}
		case GATE_BLOCK: {
			samus->isLeft = false;
			break;
		}
		case GATE:
			Gate * gate = dynamic_cast<Gate*>(otherObject);
			if (gate->GetGateType() == GATE_LEFT && gate->getGateState() == CLOSE)
			{
				gate->setIsLeft(true);
				//gate->setGateState(DESTROYING);
				if (samus->pos_x == gate->pos_x + gate->width)
					gate->setGateState(CLOSE);
				samus->pos_x += samus->vx * this->getDeltaTime();
			}
			else if (gate->GetGateType() == GATE_LEFT && gate->getGateState() == OPEN)
			{
				samus->isLeft = false;
				samus->pos_x += samus->vx * this->getDeltaTime();
				if (samus->pos_x == gate->pos_x + gate->width)
					gate->setGateState(CLOSE);
			}

			if (gate->GetGateType() == GATE_RIGHT && gate->getGateState() == CLOSE)
			{
				samus->isLeft = true;
			}
			else if (gate->GetGateType() == GATE_RIGHT && gate->getGateState() == OPEN)
			{
				samus->isLeft = false;
			}
			break;
		}

	}

}

// Xử lý zoomer khi va chạm với các thể loại object
void Grid::handleZoomer(GameObject* object, GameObject* otherObject, COLLISION_DIRECTION collisionDirection, float collisionTime) {
	Zoomer* zoomer = dynamic_cast<Zoomer*>(object);

	OBJECT_TYPE type = otherObject->getType();
	switch (collisionDirection) {
	case BOTTOM: {
		zoomer->setIsBottomCollided(true);
		if (type != SAMUS && type != BULLET && type!=EXPLOSION_BOMB && type != SKREE) {
			object->pos_y += object->vy * collisionTime * deltaTime;
		}
		else if (type == BULLET) {
			zoomer->setHealth(zoomer->getHealth() - 20);
			zoomer->setIsBottomCollided(false);
			if (zoomer->getHealth() == 0)
			{
				zoomer->isActive = false;
				zoomer->Destroy(zoomer->pos_x, zoomer->pos_y);
			}
			else {
				zoomer->setIsEnemyFreezed(true);
			}
			Bullet* bullet = dynamic_cast<Bullet*>(otherObject);
			bullet->Reset();
		}
		else if (type == EXPLOSION_BOMB) {
			object->pos_y += object->vy * deltaTime;
			zoomer->setIsBottomCollided(false);
		}
		else if (type == SAMUS) {
			Samus* samus = dynamic_cast<Samus*>(otherObject);
			if (!samus->isCollideWithEnemy) {
				samus->collideEnemy();
			}
			zoomer->setIsBottomCollided(false);
		}
		break;

	}

	case TOP: {
		zoomer->setIsTopCollided(true);
		if (type != SAMUS && type != BULLET && type != EXPLOSION_BOMB && type != SKREE) {
			object->pos_y += object->vy * collisionTime * deltaTime;
		}
		else if (type == BULLET) {

			zoomer->setHealth(zoomer->getHealth() - 20);
			zoomer->setIsTopCollided(false);
			if (zoomer->getHealth() == 0)
			{
				zoomer->isActive = false;
				zoomer->Destroy(zoomer->pos_x, zoomer->pos_y);
			}
			else {
				zoomer->setIsEnemyFreezed(true);
			}
			Bullet* bullet = dynamic_cast<Bullet*>(otherObject);
			bullet->Reset();
		}
		else if (type == EXPLOSION_BOMB) {
			object->pos_y += object->vy * deltaTime;
			zoomer->setIsTopCollided(false);
		}
		else if (type == SAMUS) {
			Samus* samus = dynamic_cast<Samus*>(otherObject);
			if (!samus->isCollideWithEnemy) {
				samus->collideEnemy();
			}
			zoomer->setIsTopCollided(false);
		}
		break;
	}

	case LEFT: {
		zoomer->setIsLeftCollided(true);
		if (type != SAMUS && type != BULLET && type != EXPLOSION_BOMB && type != SKREE) {
			object->pos_x += object->vx * collisionTime *deltaTime;
		}
		else if (type == BULLET) {

			zoomer->setHealth(zoomer->getHealth() - 20);
			zoomer->setIsLeftCollided(false);
			if (zoomer->getHealth() == 0)
			{
				zoomer->isActive = false;
				zoomer->Destroy(zoomer->pos_x, zoomer->pos_y);
			}
			else {
				zoomer->setIsEnemyFreezed(true);
			}
			Bullet* bullet = dynamic_cast<Bullet*>(otherObject);
			bullet->Reset();
		}
		else if (type == EXPLOSION_BOMB) {
			object->pos_y += object->vy * deltaTime;
			zoomer->setIsLeftCollided(false);
		}
		else if (type == SAMUS) {
			Samus* samus = dynamic_cast<Samus*>(otherObject);
			if (!samus->isCollideWithEnemy) {
				samus->collideEnemy();
			}
			zoomer->setIsLeftCollided(false);
			zoomer->pos_x += 20.0f;
		}
		break;
	}

	case RIGHT: {
		zoomer->setIsRightCollided(true);
		if (type != SAMUS && type != BULLET && type != EXPLOSION_BOMB && type != SKREE) {
			object->pos_x += object->vx * collisionTime *deltaTime;
		}
		else if (type == BULLET) {

			zoomer->setHealth(zoomer->getHealth() - 20);
			zoomer->setIsRightCollided(false);
			if (zoomer->getHealth() == 0)
			{
				zoomer->isActive = false;
				zoomer->Destroy(zoomer->pos_x, zoomer->pos_y);
			}
			else {
				zoomer->setIsEnemyFreezed(true);
			}
			Bullet* bullet = dynamic_cast<Bullet*>(otherObject);
			bullet->Reset();
		}
		else if (type == EXPLOSION_BOMB) {
			object->pos_y += object->vy * deltaTime;
			zoomer->setIsRightCollided(false);
		}
		else if (type == SAMUS) {
			Samus* samus = dynamic_cast<Samus*>(otherObject);
			if (!samus->isCollideWithEnemy) {
				samus->collideEnemy();
			}
			zoomer->setIsRightCollided(false);
			zoomer->pos_x -= 45.0f;
		}
		break;
	}
	}
}

void Grid::handleSamusBullet(GameObject* object, GameObject* otherObject, COLLISION_DIRECTION collisionDirection, float collisionTime) {
	if (!object->isActive)
		return;

	Bullet* bullet = dynamic_cast<Bullet*>(object);
	OBJECT_TYPE type = otherObject->getType();

	switch (collisionDirection) {
	case TOP: {
		bullet->setIsTop(true);
		if (type == BRICK || type == BULLET || type == ITEM || type == EXPLOSION_BOMB 
			|| type == BOMB_ITEM || type == MARU_MARI
			|| type == ENERGY_ITEM || type == MISSILE_ITEM) {
			object->pos_y += object->vy * collisionTime * this->getDeltaTime();
			bullet->Reset();
		}
		else if (type == ZOOMER_YELLOW || type == ZOOMER_PINK)
		{
			Zoomer* zoomer = dynamic_cast<Zoomer*>(otherObject);

			zoomer->setHealth(zoomer->getHealth() - 20);

			if (zoomer->getHealth() == 0)
			{
				zoomer->isActive = false;
				zoomer->Destroy(zoomer->pos_x, zoomer->pos_y);
			}
			else {
				zoomer->setIsEnemyFreezed(true);
			}
			bullet->Reset();
		}
		break;
	}

	case BOTTOM: {
		bullet->setIsBottom(true);
		// Khong lam gi ca
		break;
	}

	case LEFT: {
		bullet->setIsLeft(true);
		if (type == BRICK || type == BULLET || type == ITEM || type == EXPLOSION_BOMB
			|| type == BOMB_ITEM || type == MARU_MARI || type == ENERGY_ITEM || type == MISSILE_ITEM) {
			object->pos_x += object->vx * collisionTime * this->getDeltaTime();
			bullet->Reset();
		}
		else if (type == ZOOMER_YELLOW || type == ZOOMER_PINK)
		{
			Zoomer* zoomer = dynamic_cast<Zoomer*>(otherObject);

			zoomer->setHealth(zoomer->getHealth() - 20);
			if (zoomer->getHealth() == 0)
			{
				zoomer->isActive = false;
				zoomer->Destroy(zoomer->pos_x, zoomer->pos_y);
			}
			else {
				zoomer->setIsEnemyFreezed(true);
			}
			bullet->Reset();
		}
		else if (type == GATE)
		{
			Gate * gate = dynamic_cast<Gate*>(otherObject);
			if (gate->GetGateType() == GATE_LEFT || gate->GetGateType() == GATE_RIGHT)
			{
				gate->setIsRight(true);
				gate->setGateState(DESTROYING);
				gate->setActive(false);
			}
		}
		break;
	}

	case RIGHT: {
		bullet->setIsRight(true);
		if (type == BRICK || type == BULLET || type == ITEM || type == EFFECT
			|| type == BOMB_ITEM || type == MARU_MARI
			|| type == ENERGY_ITEM || type == MISSILE_ITEM) {
			object->pos_x += object->vx * collisionTime * this->getDeltaTime();
			bullet->Reset();
		}
		else if (type == ZOOMER_YELLOW || type == ZOOMER_PINK)
		{
			Zoomer* zoomer = dynamic_cast<Zoomer*>(otherObject);

			zoomer->setHealth(zoomer->getHealth() - 20);

			if (zoomer->getHealth() == 0)
			{
				zoomer->isActive = false;
				zoomer->Destroy(zoomer->pos_x, zoomer->pos_y);
			}
			else {
				zoomer->setIsEnemyFreezed(true);
			}
			bullet->Reset();
		}
		else if (type == GATE)
		{
			Gate * gate = dynamic_cast<Gate*>(otherObject);
			if (gate->GetGateType() == GATE_LEFT || gate->GetGateType() == GATE_LEFT)
			{
				gate->setIsLeft(true);
				gate->setGateState(DESTROYING);
				
				if (gate->getGateState() == DESTROYING)
				{
					gate->setGateState(OPEN);
					float time = 0.1f;
					time -= this->getDeltaTime();
					if (time <= 0.0f)
						gate->setGateState(CLOSE);
				}
			}
		}
		break;
	}
	}

	if (type == SAMUS) {
		bullet->setIsTop(false);
		bullet->setIsLeft(false);
		bullet->setIsBottom(false);
		bullet->setIsRight(false);
	}
}

void Grid::handleSkree(GameObject *object, GameObject *otherObject, COLLISION_DIRECTION collisionDirection, float collisionTime)
{
	if (otherObject->getType() == BRICK && collisionDirection == BOTTOM) {
		Skree* skree = dynamic_cast<Skree*>(object);
		skree->pos_x += skree->vx *collisionTime*this->getDeltaTime();
		skree->pos_y += skree->vy * collisionTime*this->getDeltaTime();
		skree->setVelocityX(0);
		skree->setVelocityY(0);
		skree->setHealth(0.0f);
		skree->setState(LANDED);
	}
	else if (otherObject->getType() == SAMUS && otherObject->isActive) {
		// khi va cham vs quai thi bi vang ra
		Samus* samus = dynamic_cast<Samus*>(otherObject);
		if (!samus->isCollideWithEnemy) {
			samus->collideEnemy();
		}
	}
}

void Grid::handleRidley(GameObject *object, GameObject *otherObject, COLLISION_DIRECTION collisionDirection, float collisionTime)
{
	Ridley * ridley = dynamic_cast<Ridley*>(object);

	OBJECT_TYPE type = otherObject->getType();
	switch (collisionDirection)
	{
	case BOTTOM:
		if (type == BRICK)
		{
			ridley->setIsBottomCollided(true);
			ridley->setTimePush(900);
			ridley->setRidleyState(SIT_LEFT);
			ridley->pos_y += ridley->vy * collisionTime * this->getDeltaTime();
		}
		else
			ridley->setIsBottomCollided(false);
		break;
	case LEFT:

		break;
	case TOP:
		if (type == BRICK)
		{
			ridley->setIsTopCollided(true);
			//ridley->setTimePush(300);
			ridley->setRidleyState(FLY_LEFT);
			ridley->setVelocityY(-ridley->getVelocityY());
			ridley->pos_y += ridley->vy * collisionTime * this->getDeltaTime();
		}
		break;
	case RIGHT:

		break;
	}
}

void Grid::updateGrid(GameObject* object, float newPosX, float newPosY) {

	// Kiểm tra xem nó có thay đổi cell hay không
	int oldRow = floor(object->getlastPosY() / CELL_SIZE);
	int oldColumn = floor(object->getlastPosX() / CELL_SIZE);

	int newRow = floor(newPosY / CELL_SIZE);
	int newColumn = floor(newPosX / CELL_SIZE);

	// Nếu không thay đổi cell thì thoát ra
	if (oldRow == newRow && oldColumn == newColumn) {
		return; 
	}

	// Xóa object ra khỏi cell hiện tại và cập nhật và cell mới
	if (object->previousUnit != NULL)
		object->previousUnit->nextUnit = object->nextUnit;
	if (object->nextUnit != NULL)
		object->nextUnit->previousUnit = object->previousUnit;

	// Nếu object đang là đứng đầu
	if (cells[oldRow][oldColumn] == object)
		cells[oldRow][oldColumn] = object->nextUnit;

	this->add(object);

	// Cập nhật lại vị trí last Post của object
	object->setlastPosX(object->getPosX());
	object->setlastPosY(object->getPosY());
}

void Grid::setDeltaTime(float deltaTime) {
	this->deltaTime = deltaTime;
}

float Grid::getDeltaTime() {
	return this->deltaTime;
}
