#include "Metroid.h"
#include <time.h>
#include "trace.h"
#include "utils.h"

void Metroid::_InitBackground()
{
}

void Metroid::_InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	world->InitSprites(d3ddv);
}

void Metroid::_InitPositions()
{
	world->samus->InitPostition();
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

void Metroid::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	//---------Khởi tạo spriteHandler---------------
	if (d3ddv == NULL) return;

	//Create sprite handler
	HRESULT result = D3DXCreateSprite(d3ddv, &spriteHandler);
	if (result != D3D_OK) return;
	//-----------------------

	world = new World(spriteHandler, this);
	srand((unsigned)time(NULL));
	_InitSprites(d3ddv);
	_InitPositions();
}

//Kiểm tra screen Mode (bắt đầu, room1, room2,... hay gameover)
void Metroid::Update(float Delta)
{
	Game::Update(Delta);
	UpdateFrame(Delta);
}

//update các object trong game
void Metroid::UpdateFrame(float Delta)
{
	
	world->Update(Delta);
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
	world->Render();
}

void Metroid::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, float Delta)
{
	if (_input->IsKeyDown(DIK_RIGHT))
	{
		world->samus->setVelocityXLast(world->samus->getVelocityX());
		world->samus->setVelocityX(SAMUS_SPEED);
		world->samus->SetState(RUNNING_RIGHT);
	}
	else if (_input->IsKeyDown(DIK_LEFT)) {
		world->samus->setVelocityXLast(world->samus->getVelocityX());
		world->samus->setVelocityX(-SAMUS_SPEED);
		world->samus->SetState(RUNNING_LEFT);
	}
	else
	{		
		if (world->samus->getVelocityXLast() > 0)
			world->samus->SetState(STAND_RIGHT);
		if (world->samus->getVelocityXLast() < 0)
			world->samus->SetState(STAND_LEFT);
		world->samus->setVelocityX(0);
	}
}

void Metroid::OnKeyDown(int KeyCode)
{
}

DWORD Metroid::GetTickPerFrame()
{
	return tick_per_frame;
}
