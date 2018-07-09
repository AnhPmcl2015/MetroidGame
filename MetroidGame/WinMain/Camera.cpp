#include "Camera.h"
#include "../WinMain/DeviceManager.h"

Camera::Camera(int _cameraWidth, int _cameraHeight, float _angle, DirectX::XMFLOAT3 _scaleFactor)
{
	cameraWidth = _cameraWidth;
	cameraHeight = _cameraHeight;
	angle = _angle;
	scaleFactor = _scaleFactor;

	D3DXMatrixOrthoLH(&_orthographicMatrix, cameraWidth, -cameraHeight, 0.0f, 1.0f);
	D3DXMatrixIdentity(&_identifyMatrix);

}


void Camera::Update()
{
	cameraPositionX = cameraWidth / 2;
	cameraPositionY = cameraHeight / 2;

	if (isFollowing()) {
		cameraPositionX = player.getX();
		cameraPositonY = player.getY();
	}
}

void Camera::Follow(Player _player) {
	player = _player;
	cameraPositionX = player.getX();
	cameraPositonY = player.getY();
}

void Camera::Unfollow()
{
	
}

void Camera::SetTransform(GraphicsDevice* gDevice) const
{
	gDevice->device->SetTransform(D3DTS_PROJECTION, &_orthographicMatrix);
	gDevice->device->SetTransform(D3DTS_WORLD, &_identifyMatrix);
	gDevice->device->SetTransform(D3DTS_VIEW, &_viewMatrix);
}
