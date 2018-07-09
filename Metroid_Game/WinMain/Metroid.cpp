#include "Metroid.h"
#include <time.h>
#include "trace.h"
#include "utils.h"

void Metroid::_InitBackground()
{
}

void Metroid::_InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	Texture text;
	this->setPlayerTexture(text.loadTexture(d3ddv, L"Player_32x16.png"));
	if (this->getPlayerTexture() == NULL)
		trace(L"Unable to load PlayerTexture");

	this->setBrickTexture(text.loadTexture(d3ddv, L"brick_16x16.png"));
	if (this->getBrickTexture() == NULL)
		trace(L"Unable to load BrickTexture");
}

void Metroid::_InitPositions()
{

}

Metroid::Metroid(HINSTANCE hInstance, LPWSTR Name, int Mode, int IsFullScreen, int FrameRate) 
	:Game(hInstance, Name, Mode, IsFullScreen, FrameRate)
{
	tick_per_frame = 1000 / _dxgraphics->getFrameRate();

	isFreezing = false;
	isOnFloor = false;
	isInGame = false;
}

Metroid::~Metroid()
{
}

/*
	Khoi tao Spritehandler va Texture cho game
*/
void Metroid::LoadResources(LPDIRECT3DDEVICE9 d3ddev)
{
	//---------Khởi tạo spriteHandler---------------
	if (d3ddev == NULL) return;

	HRESULT result = D3DXCreateSprite(d3ddev, &spriteHandler);
	if (result != D3D_OK) 
		trace(L"Unable to create SpriteHandler");

	this->_InitSprites(d3ddev);

	// Khoi tao map
	this->map = new Map(this->getSpriteHandler(), this->getBrickTexture(), "field1.txt", this->_device, 0, 0, this->_dxgraphics->getScreenWidth(), this->_dxgraphics->getScreenHeight());
	if (map == NULL)
		trace(L"Unable to load map");
}

//Kiểm tra screen Mode (bắt đầu, room1, room2,... hay gameover)
void Metroid::Update(float Delta)
{

}

//update các object trong game
void Metroid::UpdateFrame(float Delta)
{
}

//render từng screen mode (room1, room2,... hay gameover)
void Metroid::Render(LPDIRECT3DDEVICE9 d3ddv)
{
	RenderStartScreen(_device->getdevice());
}

//render các scene chính (room1, room2...) trong game
void Metroid::RenderStartScreen(LPDIRECT3DDEVICE9 d3ddv)
{

}

//render từng object trong game
void Metroid::RenderFrame(LPDIRECT3DDEVICE9 d3ddv)
{
	map->drawMap(1.1);
}

void Metroid::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, float Delta)
{
}

void Metroid::OnKeyDown(int KeyCode)
{
}

DWORD Metroid::GetTickPerFrame()
{
	return tick_per_frame;
}

LPD3DXSPRITE Metroid::getSpriteHandler() {
	return this->spriteHandler;
}

Map * Metroid::getMap() {
	return this->map;
}