#pragma once
#include <d3d9.h>
#include <vector>
#include <d3dx9.h>
#include <math.h>

static class Math
{
public:
	static bool isPointinRectangle(D3DXVECTOR2 point, RECT rect);
	static float distance(D3DXVECTOR2 point1, D3DXVECTOR2 point2);
	static int abs(int a, int b);

	static int Max(int a, int b);
	static int Min(int a, int b);
};
