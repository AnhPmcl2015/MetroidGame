#pragma once
#include "Map.h"

void Map::setLimitation(int _camera_X, int _camera_Y, int width, int height)
{
	camera_X = _camera_X;
	camera_Y = _camera_Y;
	widthLimitation = width;
	heightLimitation = height;
}

bool Map::loadMap(string filePath) {
	ifstream file_txt(filePath);
	string str;
	while (getline(file_txt, str)) {
		stringMap.push_back(str);
	}
	if (!stringMap.empty())
		return true;
	return false;
}

bool Map::Initialize(LPDIRECT3DDEVICE9 device)
{
	graphic = device;
	//TODO: make dataset -> filepath for room
	if (loadMap())
		return true;
	return false;
}

void Map::Draw(float gameTime)
{
	//declare a Sprite named painter for Draw
	//TODO: edite SpriteManager class. 
	painter = new GameSprite(); 

	//firstly, get the start coordinate of camera view, as camera_X, camera_Y
	//secondly, access to start coordinate of recent room as position.x, position.y
	//continue, get the maximum tile to show in that camera view, you can change this number through declaration in "define.h" 
	//with the two above, we calculate the start coordinate where begin to draw out room under camera view
	int x = camera_X - position.x;
	int y = camera_Y - position.y;

	//then calculate the referenced from string map, divide by 16 cause the size of one tile is 16x16 px
	int textMap_X = x / 16;
	int textMap_Y = y / 16;

	char brick;
	if (painter->initialize(/*parameter ???*/)) // checking if initialized successfully
	{
		//two next for loop will scan the string Map from start coordinate calculated (textMap_X, textMap_Y), then it will run through the stringMap, and draw every "brick" availble in the cameraview
		for (int i = textMap_Y; i < textMap_Y + TILE_ROOM_LIMITATION_Y; i++) {
			//get one line - start drawing on by one, from right to left, top to bottom
			string textLine = stringMap[i];
			for (int j = textMap_X; j < textMap_X + TILE_ROOM_LIMITATION_Y; j++) {
				brick = textLine[j];
				switch (brick)
				{
				case '1':
				{
					painter->Draw(0, 0, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case '2':
				{
					painter->Draw(0, 16, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case '3':
				{
					painter->Draw(0, 32, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case '4':
				{
					painter->Draw(0, 48, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case '5':
				{
					painter->Draw(0, 64, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case '6':
				{
					painter->Draw(0, 80, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case '7':
				{
					painter->Draw(0, 96, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case '8':
				{
					painter->Draw(0, 112, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case '9':
				{
					painter->Draw(0, 128, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'a':
				{
					painter->Draw(0, 144, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'b':
				{
					painter->Draw(0, 160, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'c':
				{
					painter->Draw(0, 176, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'd':
				{
					painter->Draw(0, 192, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));

					break;
				}
				case 'e':
				{
					painter->Draw(0, 224, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'f':
				{
					painter->Draw(0, 240, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));

					break;
				}
				case 'g':
				{
					painter->Draw(0, 256, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'h':
				{
					painter->Draw(0, 270, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'i':
				{
					painter->Draw(0, 288, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'k':
				{
					painter->Draw(0, 304, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'l':
				{
					painter->Draw(0, 320, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'm':
				{
					painter->Draw(0, 336, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'n':
				{
					painter->Draw(0, 352, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'o':
				{
					painter->Draw(0, 368, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'p':
				{
					painter->Draw(0, 384, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'q':
				{
					painter->Draw(0, 400, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'r':
				{
					painter->Draw(0, 416, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 's':
				{
					painter->Draw(0, 432, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 't':
				{
					painter->Draw(0, 448, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'u':
				{
					painter->Draw(0, 464, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'v':
				{
					painter->Draw(0, 480, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'w':
				{
					painter->Draw(0, 496, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'x':
				{
					painter->Draw(0, 512, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'y':
				{
					painter->Draw(0, 528, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'z':
				{
					painter->Draw(0, 544, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'A':
				{
					painter->Draw(0, 560, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'B':
				{
					painter->Draw(0, 576, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'C':
				{
					painter->Draw(0, 592, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'D':
				{
					painter->Draw(0, 608, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'E':
				{
					painter->Draw(0, 624, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'F':
				{
					painter->Draw(0, 640, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'G':
				{
					painter->Draw(0, 656, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'H':
				{
					painter->Draw(0, 672, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'I':
				{
					painter->Draw(0, 688, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'K':
				{
					painter->Draw(0, 704, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'L':
				{
					painter->Draw(0, 720, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'M':
				{
					painter->Draw(0, 736, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'N':
				{
					painter->Draw(0, 752, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'O':
				{
					painter->Draw(0, 768, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'P':
				{
					painter->Draw(0, 784, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'Q':
				{
					painter->Draw(0, 800, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'R':
				{
					painter->Draw(0, 816, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'S':
				{
					painter->Draw(0, 832, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'T':
				{
					painter->Draw(0, 848, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case'U':
				{
					painter->Draw(0, 864, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case '0':
				{
					break;
				}
				default:
					break;
				}
			}
		}
	}
}

void Map::Update() {
	roomID++;
	switch (roomID) {
	case ROOM_1: {
		break;
	}
	case ROOM_2: {
		break;
	}
	case ROOM_3: {
		break;
	}
	}
}

void Map::Update(int _roomID) {
	switch (_roomID) {
	case ROOM_1: {
		break;
	}
	case ROOM_2: {
		break;
	}
	case ROOM_3: {
		break;
	}
	}
}
