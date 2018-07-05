//#include"KeyBoard.h"
//
//KeyBoard::KeyBoard(Player* player)
//{
//	_player = player;
//}
//
//KeyBoard::~KeyBoard()
//{
//
//}
//
//bool KeyBoard::InitializeKeyBoard(HWND hWnd, HINSTANCE hInstance)
//{
//	HRESULT hr = DirectInput8Create(
//		hInstance,
//		DIRECTINPUT_VERSION,
//		IID_IDirectInput8,
//		(VOID**)&_di,
//		NULL);
//
//	if (hr != DI_OK)
//		return false;
//	hr = _di->CreateDevice(GUID_SysKeyboard, &_keyboard, NULL);
//	if (hr != DI_OK)
//		return false;
//
//	hr = _keyboard->SetDataFormat(&c_dfDIKeyboard);
//
//	
//	hr = _keyboard->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
//
//	DIPROPDWORD dipdw;
//
//	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
//	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
//	dipdw.diph.dwObj = 0;
//	dipdw.diph.dwHow = DIPH_DEVICE;
//	dipdw.dwData = KEYBOARD_BUFFER_SIZE;
//
//	hr = _keyboard->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
//	if (hr != DI_OK)
//		return false;
//
//	hr = _keyboard->Acquire();
//	if (hr != DI_OK)
//		return false;
//
//	return true;
//}
//
//void KeyBoard::ProcessKeyBoard(HWND hWnd)
//{
//	_keyboard->GetDeviceState(sizeof(_keyStates), _keyStates);
//
//	if (IsKeyDown(DIK_ESCAPE))
//	{
//		PostMessage(hWnd, WM_QUIT, 0, 0);
//	}
//
//	DWORD dwElement = KEYBOARD_BUFFER_SIZE;
//	HRESULT hr = _keyboard->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), _keyEvents, &dwElement, 0);
//
//	for (DWORD i = 0; i < dwElement; i++)
//	{
//		int KeyCode = _keyEvents[i].dwOfs;
//		int keyState = _keyEvents[i].dwData;
//		if ((keyState & 0x80)>0)
//			OnKeyDown(KeyCode);
//		else
//			OnKeyUp(KeyCode);
//	}
//}
//
//int KeyBoard::IsKeyDown(int KeyCode)
//{
//	return(_keyStates[KeyCode] & 0x80) > 0;
//}
//
//void KeyBoard::OnKeyUp(int KeyCode) 
//{
//	switch (KeyCode)
//	{
//	case DIK_UP:
//	{
//		_player->moveGaurdTerminated();
//		break;
//	}
//	case DIK_Z:
//	{
//		//_player->moveShootTerminated();
//		_player->endShoot();
//	}
//	case DIK_LEFT:
//	case DIK_RIGHT:
//	{
//		_player->setDirection(0);
//		break;
//	}
//	case DIK_X:
//	{
//		_player->resetHighJump();
//		break;
//	}
//	default:
//		break;
//	}
//}
//void KeyBoard::OnKeyDown(int KeyCode)
//{
//	switch (KeyCode)
//	{
//	case DIK_X:
//	{
//		_player->jump();
//		break;
//	}
//	case DIK_Z:
//	{
//		/*_player->moveShoot();
//		_player->movegaurd();*/
//		_player->startShoot();
//		break;
//	}
//	case DIK_UP:
//	{
//		_player->movegaurd();
//		break;
//	}
//	}
//}
