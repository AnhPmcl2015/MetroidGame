#pragma once
#include "Map.h"

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
	return true;
}

void Map::Draw(float gameTime)
{
	//declare a Sprite named painter for Draw
	//painter = new Sprite(); 
	
	//problem here
	int x = initX - position.x;
	int y = initY - position.y;
	//end problem here

	char brick;
	if (painter->initialize(/*parameter ???*/)) // checking if initialized successfully
	{
		for (string line : stringMap) {
			for (int j = 0; j < line.size(); j++) {
				brick = line[j];
				switch (brick)
				{
				case '1':
				{
					brick->Draw(0, 0, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case '2':
				{
					brick->Draw(0, 16, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case '3':
				{
					brick->Draw(0, 32, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case '4':
				{
					brick->Draw(0, 48, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case '5':
				{
					brick->Draw(0, 64, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case '6':
				{
					brick->Draw(0, 80, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case '7':
				{
					brick->Draw(0, 96, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case '8':
				{
					brick->Draw(0, 112, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case '9':
				{
					brick->Draw(0, 128, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'a':
				{
					brick->Draw(0, 144, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'b':
				{
					brick->Draw(0, 160, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'c':
				{
					brick->Draw(0, 176, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'd':
				{
					brick->Draw(0, 192, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));

					break;
				}
				case 'e':
				{
					brick->Draw(0, 224, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'f':
				{
					brick->Draw(0, 240, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));

					break;
				}
				case 'g':
				{
					brick->Draw(0, 256, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'h':
				{
					brick->Draw(0, 270, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'i':
				{
					brick->Draw(0, 288, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'k':
				{
					brick->Draw(0, 304, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'l':
				{
					brick->Draw(0, 320, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'm':
				{
					brick->Draw(0, 336, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'n':
				{
					brick->Draw(0, 352, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'o':
				{
					brick->Draw(0, 368, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'p':
				{
					brick->Draw(0, 384, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'q':
				{
					brick->Draw(0, 400, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'r':
				{
					brick->Draw(0, 416, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 's':
				{
					brick->Draw(0, 432, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 't':
				{
					brick->Draw(0, 448, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'u':
				{
					brick->Draw(0, 464, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'v':
				{
					brick->Draw(0, 480, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'w':
				{
					brick->Draw(0, 496, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'x':
				{
					brick->Draw(0, 512, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'y':
				{
					brick->Draw(0, 528, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'z':
				{
					brick->Draw(0, 544, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'A':
				{
					brick->Draw(0, 560, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'B':
				{
					brick->Draw(0, 576, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'C':
				{
					brick->Draw(0, 592, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'D':
				{
					brick->Draw(0, 608, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'E':
				{
					brick->Draw(0, 624, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'F':
				{
					brick->Draw(0, 640, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'G':
				{
					brick->Draw(0, 656, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'H':
				{
					brick->Draw(0, 672, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'I':
				{
					brick->Draw(0, 688, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'K':
				{
					brick->Draw(0, 704, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'L':
				{
					brick->Draw(0, 720, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'M':
				{
					brick->Draw(0, 736, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'N':
				{
					brick->Draw(0, 752, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'O':
				{
					brick->Draw(0, 768, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'P':
				{
					brick->Draw(0, 784, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'Q':
				{
					brick->Draw(0, 800, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'R':
				{
					brick->Draw(0, 816, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'S':
				{
					brick->Draw(0, 832, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case 'T':
				{
					brick->Draw(0, 848, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
					break;
				}
				case'U':
				{
					brick->Draw(0, 864, 16, 16, D3DXVECTOR3(j * 16 + position.x, i * 16 + position.y, 0));
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
