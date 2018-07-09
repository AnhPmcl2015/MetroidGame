#include "Sprite.h"
#include <vector>

/*
	Khoi tao Sprite 
		SpriteHandler : chỗ chứa sprite khi vẽ
		textureFilePath: duong dan den file hinh anh chua Sprite
		width: chieu ngang moi sprite
		height: chieu dai moi sprite
		count: dem so luong sprite (trong truong hop xet chuyen dong nhan vat)

	Ex: Sprite *playerJump = new Sprite(SpriteHandler, L'Player_32x16.png", WIDTH_SAMUS_STAND, HEIGHT_SAMUS_STAND, 4);
		Sprite di chuyen qua phai co 4 sprite => count = 4;
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
		D3DPOOL_DEFAULT,
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

Sprite::Sprite(LPD3DXSPRITE SpriteHandler, LPWSTR textureFilePath, LPWSTR coord, int width, int height, int count)
{
	this->count = count;
	sprite = SpriteHandler;
	this->textureFilePath = textureFilePath;
	this->_Coord = coord;

	// Gan he mau trong suot
	transColor = D3DCOLOR_ARGB(255, 255, 255, 255);
	this->_Index = 0;

	this->width = width;
	this->height = height;

	LPDIRECT3DDEVICE9 d3ddv;
	SpriteHandler->GetDevice(&d3ddv);
	
	texture = loadTexture(d3ddv, transColor, this->textureFilePath);
	if (texture == NULL)
		return;
}

Sprite::~Sprite() {
	texture->Release();
}

// Cap nhat vi tri cua sprite tiep theo
void Sprite::updateSprite() {
	this->_Index = (this->_Index + 1) % count;
}

/*
	x: Toa do vi tri x cua Sprite
	y: Toa do vi tri y cua Sprite
	width: Chieu ngang pixel cua Sprite dang xet
	height: Chieu dai pixel cua Sprite dang xet
	position: Vi tri xua hien tren man hinh theo 3 truc (x, y, z)
*/
void Sprite::drawSprite(int width, int height, D3DXVECTOR3 position) {
	if (this->sprite == NULL || this->texture == NULL)
		return;
	RECT rect;
	rect = ReadCoord();
	/*RECT rect;
	rect.left = (_Index % count) * width;
	rect.top = (_Index / count) * height;
	rect.right = rect.left + width;
	rect.bottom = rect.top + height;*/

	D3DXVECTOR3 pos(0,0,0);
	//pos.x = position.x;
	//pos.y = position.y;

	this->sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);

	// Texture being used is width by height:
	D3DXVECTOR2 spriteCentre = D3DXVECTOR2((float)width, (float)height);

	// Screen position of the sprite
	D3DXVECTOR2 trans = D3DXVECTOR2(position.x, position.y);

	// Build our matrix to rotate, scale and position our sprite
	D3DXMATRIX mat;

	D3DXVECTOR2 scaling(2.0f,-2.0f);

	// out, scaling centre, scaling rotation, scaling, rotation centre, rotation, translation
	D3DXMatrixTransformation2D(&mat, &D3DXVECTOR2( width/2, height/2 ) , 0.0, &scaling, &spriteCentre, NULL, &trans);


	this->sprite->SetTransform(&mat);
	this->sprite->Draw(this->texture, &rect, NULL, NULL, this->transColor);
	
	this->sprite->End();
}

void Sprite::Reset()
{
	_Index = 0;
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

RECT Sprite::ReadCoord()
{
	int ** coord = new int*[2];	//init array Sprite's position

								//Read file info of file
	fstream f;
	try
	{
		f.open(_Coord);
	}
	catch (std::fstream::failure e)
	{
		MessageBox(NULL, L"[Sprite class]--Read sprite info from file failed", L"Error", NULL);
	}
	string line;
	int id = 0;
	while (!f.eof() && id < count)
	{
		vector<string> pos;
		string split;
		getline(f, line);
		istringstream iss(line);

		while (getline(iss, split, '\t'))
		{
			pos.push_back(split);
		}

		coord[id] = new int[count];

		coord[id][0] = stoi(pos[0]);
		srect.left = coord[id][0];

		coord[id][1] = stoi(pos[1]);
		srect.top = coord[id][1];

		srect.right = srect.left + width;
		srect.bottom = srect.top + height + 1;

		if (id == _Index)
		{
			break;
		}

		id++;
	}
	f.close();

	return srect;
}