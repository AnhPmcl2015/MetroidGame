#include"GraphicDevice.h"

GraphicsDevice::GraphicsDevice()
{

}

GraphicsDevice::~GraphicsDevice()
{
	if (device)
	{
		device->Release();
		device = NULL;
	}

	if (direct3d)
	{
		direct3d->Release();
		direct3d = NULL;
	}
}

bool GraphicsDevice::Initialize(HWND hWnd, bool windowed)
{

	//khoi tao con tro DirectX 3D
	direct3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS presentationParams;
	ZeroMemory(&presentationParams, sizeof(presentationParams));
	presentationParams.Windowed = windowed;
	presentationParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
	presentationParams.hDeviceWindow = hWnd;

	//khoi taio Device
	//D3DADAPTER_DEFAULT = Primary display adapter (bo hieu chinh) (mac dinh card do hoa)
	//D3DDEVTYPE_HAL = Hardware rasterization. Shading is done with software, hardware, or mixed transform and lighting.
	//D3DCREATE_MIXED_VERTEXPROCESSING = Uses both hardware and software for 3D calculations (de tinh toan )
	if (!SUCCEEDED(direct3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&presentationParams,
		&device)))
	{
		return false;
	}

	if (!CreateCharacterTex(FILE_IMAGE))
	{
		return false;
	}
	if (!CreateBrickTex(BRICK_FILE))
	{
		return false;
	}
	if (!CreateSceneTex(INTRO_FILE))
	{
		return false;
	}

	return true;
}

void GraphicsDevice::Clear(D3DCOLOR color)
{
	//xoa toan bo buffer

	device->Clear(0, NULL, D3DCLEAR_TARGET, color, 1.0f, 0);
}

void GraphicsDevice::Begin()
{
	device->BeginScene();
}

void GraphicsDevice::End()
{
	device->EndScene();
}

void GraphicsDevice::Present()
{
	//trinh bay len man hinh window
	device->Present(NULL, NULL, NULL, NULL);
}

bool GraphicsDevice::CreateCharacterTex(LPCWSTR file)
{
	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(file, &info);

	if (!SUCCEEDED(D3DXCreateTextureFromFileEx(
		device,
		file,
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(0, 0, 0),
		&info,
		NULL,
		&characterTex)))
	{
		/*std::string s = "Make sure the file exist and path is right. Requested Image: " + file;
		MessageBox(NULL, s.c_str(), NULL, NULL);*/
		return false;
	}
	return true;
}

bool GraphicsDevice::CreateBrickTex(LPCWSTR file)
{
	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(file, &info);

	if (!SUCCEEDED(D3DXCreateTextureFromFileEx(
		device,
		file,
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(0, 0, 0),
		&info,
		NULL,
		&brickTex)))
	{
		/*std::string s = "Make sure the file exist and path is right. Requested Image: " + file;
		MessageBox(NULL, s.c_str(), NULL, NULL);*/
		return false;
	}
	return true;
}

bool GraphicsDevice::CreateSceneTex(LPCWSTR file)
{
	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(file, &info);

	if (!SUCCEEDED(D3DXCreateTextureFromFileEx(
		device,
		file,
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(0, 0, 0),
		&info,
		NULL,
		&sceneTex)))
	{
		/*LPCWSTR s = L"Make sure the file exist and path is right. Requested Image: " + file;
		MessageBox(NULL, s, NULL, NULL);*/
		return false;
	}
	return true;
}

LPDIRECT3DTEXTURE9 GraphicsDevice::getCharaterTex()
{
	return characterTex;
}
LPDIRECT3DTEXTURE9 GraphicsDevice::getBrickTex()
{
	return brickTex;
}
LPDIRECT3DTEXTURE9 GraphicsDevice::getSceneTex()
{
	return sceneTex;
}