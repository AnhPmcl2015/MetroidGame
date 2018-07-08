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

	this->viewMatrix = D3DXMATRIX(
		scaleFactors.x * cos(angle), scaleFactors.x * sin(angle), 0, 0,
		-scaleFactors.y * sin(angle), scaleFactors.y * cos(angle), 0, 0,
		0, 0, scaleFactors.z, 0,
		-cameraX * scaleFactors.x * cos(angle) + cameraY * scaleFactors.y * sin(angle), 
		-cameraX * scaleFactors.y * sin(angle) - cameraY * scaleFactors.y * cos(angle), 0, 1
		/*1/cameraX, 0, 0, 0,
		0, 1/cameraY, 0, 0,
		0, 0, 1/(), 0, 0,
		0, 0, , 1*/
	);
}

void Camera::SetTransform(DeviceManager* device) const
{
	device->getdevice()->SetTransform(D3DTS_PROJECTION, &orthographicMatrix);
	device->getdevice()->SetTransform(D3DTS_WORLD, &identityMatrix);
	device->getdevice()->SetTransform(D3DTS_VIEW, &viewMatrix);
}





