#include "Sprite.h"

/*
	Khoi tao Sprite 
		textureFilePath: duong dan den file hinh anh chua Sprite
		width: chieu ngang moi sprite
		height: chieu dai moi sprite
		startIndexOfSprite: vi tri index cua sprite dang xet trong texture
		count: dem so luong sprite (trong truong hop xet chuyen dong nhan vat)

	Ex: Sprite *playerJump = new Sprite(L'Player_32x16.png", WIDTH_SAMUS_STAND, HEIGHT_SAMUS_STAND, 1, 4, d3ddev);
		Sprite di chuyen qua phai co 4 sprite => count = 4;
		vi tri sprite di chuyen qua phai la dau tien => startIndexOfSprite = 1;
*/

// Load Texture
LPDIRECT3DTEXTURE9 loadTexture(LPDIRECT3DDEVICE9 d3ddev, D3DCOLOR transColor, LPWSTR fileName) {
	HRESULT result;
	LPDIRECT3DTEXTURE9 _texture = NULL;

	// Doc thong tin file anh de tao texture
	D3DXIMAGE_INFO infoOfTexture;

	result = D3DXGetImageInfoFromFile(fileName, &infoOfTexture);
	if (result != D3D_OK)
	{
		trace(L"[ERROR] Failed to get information from image file '%s'", fileName);
		return NULL;
	}

	result = D3DXCreateTextureFromFileEx(
		d3ddev,
		fileName,
		infoOfTexture.Width,
		infoOfTexture.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transColor,
		&infoOfTexture,
		NULL,
		&_texture);

	if (result != D3D_OK)
		return NULL;
	return _texture;
}

Sprite::Sprite(LPD3DXSPRITE SpriteHandler, LPWSTR textureFilePath, int width, int height, int startIndexOfSprite, int count)
{
	this->count = count;
	sprite = SpriteHandler;
	this->textureFilePath = textureFilePath;
	// Gan he mau trong suot
	transColor = D3DCOLOR_ARGB(255, 255, 255, 255);
	this->currentIndexOfSprite = startIndexOfSprite;

	this->width = width;
	this->height = height;

	LPDIRECT3DDEVICE9 d3ddv;
	SpriteHandler->GetDevice(&d3ddv);
	
	texture = loadTexture(d3ddv, transColor, this->textureFilePath);
	if (texture == NULL)
		return;
}

Sprite::~Sprite() {

}

// Cap nhat vi tri cua sprite tiep theo
void Sprite::updateSprite() {
	this->currentIndexOfSprite = (this->currentIndexOfSprite + 1) % count;
	

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
	this->x = x;
	this->y = y;
	if (this->sprite == NULL || this->texture == NULL)
		return;

	RECT rect;
	rect.left = x;
	rect.top = y;
	rect.right = x + width;
	rect.bottom = y + height;

	D3DXVECTOR3 pos(0,0,0);
	//pos.x = position.x;
	//pos.y = position.y;

	this->sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);

	// Texture being used is 38 by 17:
	D3DXVECTOR2 spriteCentre = D3DXVECTOR2(17.0f, 38.0f);

	// Screen position of the sprite
	D3DXVECTOR2 trans = D3DXVECTOR2(position.x, position.y);

	// Build our matrix to rotate, scale and position our sprite
	D3DXMATRIX mat;

	D3DXVECTOR2 scaling(2.0f, -2.0f);

	// out, scaling centre, scaling rotation, scaling, rotation centre, rotation, translation
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &spriteCentre, NULL, &trans);

	/*D3DXMATRIX matScale;
	D3DXMatrixScaling(&matScale, 2, -2, 1);
	D3DXMATRIX matTranslate;
	D3DXMatrixTranslation(&matTranslate, position.x, position.y, position.z);
	D3DXMATRIX matTransform;
	D3DXMatrixMultiply(&matTransform, &matScale, &matTranslate);*/

	
	this->sprite->Draw(this->texture, &rect, NULL, &pos, this->transColor);
	this->sprite->SetTransform(&mat);
	this->sprite->End();
}

void Sprite::Reset()
{
	currentIndexOfSprite = 0;
}

void Sprite::setWidth(int value)
{
	width = value;
}

int Sprite::getWidth()
{
	return width;
}

void Sprite::setHeight(int value)
{
	height = value;
}

int Sprite::getHeight()
{
	return height;
}