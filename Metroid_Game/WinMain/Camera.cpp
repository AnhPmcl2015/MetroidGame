#include "Camera.h"

Camera::Camera(int _cameraWidth, int _cameraHeight, float _cameraAngle, DirectX::XMFLOAT3 _scaleFactor)
{
	cameraWidth = _cameraWidth;
	cameraHeight = _cameraHeight;
	angle = _cameraAngle;
	scaleFactor = _scaleFactor;

	D3DXMatrixOrthoLH(&_orthographicMatrix, _cameraWidth, -_cameraHeight, 0.0f, 1.0f);
	D3DXMatrixIdentity(&_identifyMatrix);

	status = 1;
	refresh = true;

	//limitX = _collisionManager->getFieldCollision(BEGINNING_ROOM)->getX();
	//limitY = _collisionManager->getFieldCollision(BEGINNING_ROOM)->getY();
	//limitWidth = _collisionManager->getFieldCollision(BEGINNING_ROOM)->getWidth();
	//limitHeight = _collisionManager->getFieldCollision(BEGINNING_ROOM)->getHeight();

	//limitUp = limitY;
	//limitDown = limitY + limitHeight;
	//limitRight = limitX + limitWidth;
	//limitLeft = limitX;

	//center view
	//stayY = 3256;

	cameraX = 128;
	cameraY = 120;
}

Camera::~Camera() {

}

void Camera::Update(bool isAutorun)
{
	//set the camera coordinate to center
	cameraX = cameraWidth / 2;
	cameraY = cameraHeight / 2;

	if (isFollowing()) {
		cameraX = cameraX + 6;
	}

}

void Camera::Follow(/*Player player*/)
{
}

void Camera::Follow(GameObject* _object)
{
	gameObject = _object;
	_x = _object->getlastPosX();
	_y = _object->getlastPosY();
}

bool Camera::isFollowing()
{
	return false;
}

//void Camera::SetTransform(DeviceManager * _device)
//{
//	_device->getdevice()->SetTransform(D3DTS_PROJECTION, &_orthographicMatrix);
//	_device->getdevice()->SetTransform(D3DTS_WORLD, &_identifyMatrix);
//	_device->getdevice()->SetTransform(D3DTS_VIEW, &_viewMatrix);
//}
