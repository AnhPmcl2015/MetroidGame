#pragma once
#include "bullet.h"
#include <vector>
using namespace std;
class Manager
{
private:
	//LPDIRECT3DDEVICE9 m_d3ddv;

	vector<Bullet*> weapon = vector<Bullet*>(0);
public:
	Manager();
	Manager(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DTEXTURE9);
	~Manager();

	void _CreateBullets(float X = 0, float Y = 0, float VX = 0, float VY = 0);
	virtual void UpdateObject(float delta);
	virtual void Render();
};
