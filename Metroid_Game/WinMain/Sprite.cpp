#include "Sprite.h"

/*
	Khoi tao Sprite 
		textureFilePath: duong dan den file hinh anh chua Sprite
		width: chieu ngang moi sprite
		height: chieu dai moi sprite
		startIndexOfSprite: vi tri index cua sprite dang xet trong texture
		count: dem so luong sprite (trong truong hop xet chuyen dong nhan vat)

	Ex: Sprite *playerJump = new Sprite(L'Player_32x16.png", WIDTH_SPRITE_PLAYER, HEIGHT_SPRITE_PLAYER, 1, 4, d3ddev);
		Sprite di chuyen qua phai co 4 sprite => count = 4;
		vi tri sprite di chuyen qua phai la dau tien => startIndexOfSprite = 1;
*/
Sprite::Sprite(LPD3DXSPRITE sprite, LPDIRECT3DTEXTURE9 texture, int width, int heigth, int startIndexOfSprite, int count) {

	
	// Gan he mau trong suot
	transColor = D3DCOLOR_ARGB(255, 255, 255, 255);
	this->currentIndexOfSprite = startIndexOfSprite;
	this->sprite = sprite;
	if (this->sprite == NULL)
		return;
	this->texture = texture;
	if (this->texture == NULL)
		return;
}

Sprite::~Sprite() {

}

// Cap nhat vi tri cua sprite tiep theo
void Sprite::updateSprite() {
	this->currentIndexOfSprite += 1;
	if (this->currentIndexOfSprite >= (this->startIndexOfSprite + this->count))
		this->currentIndexOfSprite = startIndexOfSprite;
}

/*
	x: Toa do vi tri x cua Sprite
	y: Toa do vi tri y cua Sprite
	width: Chieu ngang pixel cua Sprite dang xet
	height: Chieu dai pixel cua Sprite dang xet
	position: Vi tri xua hien tren man hinh theo 3 truc (x, y, z)
*/
void Sprite::drawSprite(int x, int y, int width, int height, D3DXVECTOR3 position) {
	if (this->sprite == NULL || this->texture == NULL)
		return;

	RECT rect;
	rect.left = x;
	rect.top = y;
	rect.right = x + width;
	rect.bottom = y + height;

	this->sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
	this->sprite->Draw(this->texture, &rect, NULL, &position, this->transColor);
	this->sprite->End();
}
