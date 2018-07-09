#pragma once
#pragma once
#include <DirectXMath.h>
#include "../WinMain/game/Player.h"

class Camera {
public:
	Camera() {

	}
	Camera(int _cameraWidth, int _cameraHeight, float _angle, DirectX::XMFLOAT3 _scaleFactor);
	~Camera() {

	}

	void Update();
	void Follow();
	void Unfollow();
	bool isFollowing();
	void SetTransform(GraphicsDevice* gDevice);


	int getWidth();
	int getHeight();

	int getCenterPositionX();
	int getCenterPositionY();

protected:
	int cameraWidth;
	int cameraHeight;
	float angle;
	DirectX::XMFLOAT3 scaleFactor;
	D3DXMATRIX _orthographicMatrix;
	D3DXMATRIX _identifyMatrix;
	D3DXMATRIX _viewMatrix;

	int cameraLimitX;
	int cameraLimitY;

	int cameraPositionX;
	int cameraPositionY;

	Player player;
};

int Camera::getX()
{
	return _x;
}
int Camera::getY()
{
	return _y;
}