#include"GameSprite.h"

GameSprite::GameSprite(SpriteManager* data)
{
	//gan gia tri cho color ( he mau trong suot )

	_data = data;
	color = D3DCOLOR_ARGB(255, 255, 255, 255);

	initialized = false;
}


bool GameSprite::initialize(LPDIRECT3DDEVICE9 device, LPDIRECT3DTEXTURE9 tex , int indexInData, int count)
{
	//Lay thong tin tu file hinh goc

	_tex = tex;
	startIndex = indexInData;
	index = startIndex;
	_count = count;

	x = _data->getCoordinate(startIndex)->_xInTexture;
	y = _data->getCoordinate(startIndex)->_yInTexture;
	_width = _data->getCoordinate(startIndex)->_width;
	_height = _data->getCoordinate(startIndex)->_height;

	// khoi tao Sprite

	if (!SUCCEEDED(D3DXCreateSprite(device, &sprite)))
	{
		MessageBox(NULL, L"file not found", NULL, NULL);
		return false;
	}

	initialized = true;

	return true;
}

bool GameSprite::IsInitialize()
{
	return initialized;
}

void GameSprite::Update(float gameTime)
{
	//cap nhap sprite de co chuyen dong
	index++;
	if (index == _count + startIndex)
		index = startIndex;
}

void GameSprite::Draw(float gameTime, D3DXVECTOR3 position)
{
	//ve sprite the tham so da cap nhap

	if (sprite && _tex)
	{
		RECT srect;
		srect.left = _data->getCoordinate(index)->_xInTexture;
		srect.top = _data->getCoordinate(index)->_yInTexture;
		srect.right = srect.left + _data->getCoordinate(index)->_width;
		srect.bottom = srect.top + _data->getCoordinate(index)->_height;

		sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
		sprite->Draw(_tex, &srect, NULL, &position, color);
		sprite->End();
	}
}

void GameSprite::Draw(int XInTexture, int yInTexture, int width, int height, D3DXVECTOR3 position)
{
	if (sprite && _tex)
	{
		RECT srect;
		srect.left = XInTexture;
		srect.top = yInTexture;
		srect.right = srect.left + _width;
		srect.bottom = srect.top + _height;

		sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
		sprite->Draw(_tex, &srect, NULL, &position, color);
		sprite->End();
	}
}

float GameSprite::getWidth()
{
	return _data->getCoordinate(index)->_width;
}
float GameSprite::getHeight()
{
	return _data->getCoordinate(index)->_height;
}

GameSprite::~GameSprite()
{
	if (sprite)
	{
		sprite->Release();
		sprite = 0;
	}
	/*if (_tex)
	{
		_tex->Release();
		_tex = 0;
	}*/
}