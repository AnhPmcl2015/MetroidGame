#include "BulletManager.h"

Manager::Manager()
{
	
}

Manager::Manager(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DTEXTURE9 texture)
{
	//m_d3ddv = d3ddv;
	if (texture != NULL && d3ddv != NULL)
	{		
		for (int i = 0; i < weapon.size(); i++)
		{
			weapon[i] = new Bullet();
			weapon[i]->InitSprites(d3ddv, texture);
		}
			
	}
}

Manager::~Manager()
{
	/*if (m_d3ddv)
	{
		m_d3ddv = nullptr;
		delete m_d3ddv;
	}*/
}

void Manager::_CreateBullets(float X, float Y, float VX, float VY)
{
	weapon.push_back(new Bullet(X, Y, VX, VY));
}

void Manager::UpdateObject(float delta)
{
	for (int i = 0; i < weapon.size(); i++)
	{
		weapon[i]->Update(delta);
	}
}

void Manager::Render()
{
	for (int i = 0; i < weapon.size(); i++)
	{
		weapon[i]->Render();
	}
}