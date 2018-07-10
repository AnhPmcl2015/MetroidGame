#pragma once
#include <DirectXMath.h>
//#include "Player.h"
#include "../WinMain/GameObject.h"


class DeviceManger;

class Camera {
public: 
	Camera(int _cameraWidth, int _cameraHeight, float _cameraAngle, DirectX::XMFLOAT3 _scaleFactor);
	~Camera();

	void Update(bool isAutorun);
	void Follow(/*Player _player*/);
	void Follow(GameObject* _object);
	void unFollow();
	bool isFollowing();
	void SetTransform(DeviceManger* _device);

	int getWidth() { return cameraWidth; }
	int getHeight() { return cameraHeight; }

	int getX();
	int getY();


private:
	float angle;
	DirectX::XMFLOAT3 scaleFactor;
	D3DXMATRIX _orthographicMatrix;
	D3DXMATRIX _identifyMatrix;
	D3DXMATRIX _viewMatrix;

	//Player* player;
	GameObject* gameObject;

	int cameraWidth;
	int cameraHeight;
	bool refresh;

	//CollisionManager* _collisionManager;
	int status;

	int stayX;
	int stayY;

	int limitX;
	int limitY;
	int limitWidth;
	int limitHeight;

	int limitUp;
	int limitDown;
	int limitLeft;
	int limitRight;

	int playerX;
	int playerY;

	int _x; int _y;
	int cameraX;
	int cameraY;
};