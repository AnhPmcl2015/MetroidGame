#include "Camera.h"
#include <d3d9.h>

Camera::Camera(int width, int height, float angle, DirectX::XMFLOAT3 scaleFactors)
{
	this->width = width;
	this->height = height;
	this->angle = angle;
	this->scaleFactors = scaleFactors;

	D3DXMatrixOrthoLH(&orthographicMatrix, width, height, 0.0f, 1.0f);
	D3DXMatrixIdentity(&identityMatrix);
}

Camera::~Camera()
{
	
}

void Camera::Update()
{
	int cameraX = width/2, cameraY = height/2;

	D3DXVECTOR3 eye(200, 200, -1);
	D3DXVECTOR3 direction(0, 0, 1);
	D3DXVECTOR3 up(0, 1, 0);	//r

	D3DXMatrixLookAtLH(&viewMatrix, &eye, &(eye + direction), &up);
}

void Camera::SetTransform(DeviceManager* device) const
{
	device->getdevice()->SetTransform(D3DTS_PROJECTION, &orthographicMatrix);
	device->getdevice()->SetTransform(D3DTS_WORLD, &identityMatrix);
	device->getdevice()->SetTransform(D3DTS_VIEW, &viewMatrix);
}






