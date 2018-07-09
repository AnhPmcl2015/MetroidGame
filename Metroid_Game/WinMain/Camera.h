﻿#ifndef CAMERA_H
#define CAMERA_H

#include <DirectXMath.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "DeviceManager.h"


class Camera
{
public:
	//Constructors and Destructor
	Camera(int width, int height, float angle, DirectX::XMFLOAT3 scaleFactors);
	~Camera();

	//Game Functions
	void Update();
	void SetTransform(DeviceManager *device) const;

private:
	float angle;
	DirectX::XMFLOAT3 scaleFactors;
	D3DXMATRIX orthographicMatrix;	//ma trận tầm nhìn
	D3DXMATRIX identityMatrix;	//ma trận vật
	D3DXMATRIX viewMatrix;	//ma trận trong world

	int width;
	int height;
};

#endif /* CAMERA_H */
