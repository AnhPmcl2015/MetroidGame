#include "Map.h"


Map::Map(LPD3DXSPRITE spriteHandler, LPDIRECT3DTEXTURE9 texture, string filePath, DeviceManager *deviceManager, int x, int y, int width, int height) {
	this->filePath = filePath;
	this->deviceManager = deviceManager;
	this->setLimitation(x, y, width, height);
	this->texture = texture;
	if (this->texture == NULL)
		trace(L"Unable to read map texture");
	this->sprite = new Sprite(spriteHandler, this->getTexture(), WIDTH_SPRITE_BRICK, HEIGHT_SPRITE_BRICK, 1, 1);
	if (this->sprite == NULL)
		trace(L"Unable to load map sprite");

	if (!this->loadMap(this->filePath)) {
		trace(L"Unable to load map");
	}
}

Map::~Map() {
	delete sprite;
}

void Map::setLimitation(int x, int y, int width, int height) {
	this->camera_X = x;
	this->camera_Y = y;
	this->widthLimitation = width;
	this->heightLimitation = height;
}

LPDIRECT3DDEVICE9 Map::getDevice() {
	return this->deviceManager->getdevice();
}

LPDIRECT3DTEXTURE9 Map::getTexture() {
	return this->texture;
}

vector<string> Map::getStringMap() {
	return this->stringMap;
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

void Map::drawMap(float gameTime) {
	int x = this->camera_X/BRICK_SIZE;
	int y = this->camera_Y/BRICK_SIZE;

	char brick;
	
	for (int i = y; i < Y_LIMITATION + y ; i++) {
		string textline = (this->getStringMap())[i];

		for (int j = x; j < X_LIMITATION + x; j++) {
			brick = textline[j];
			switch (brick)
			{
			case '1':
			{
				sprite->drawSprite(0, 0, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case '2':
			{
				sprite->drawSprite(0, 16, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case '3':
			{
				sprite->drawSprite(0, BRICK_SIZE, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case '4':
			{
				sprite->drawSprite(0, 48, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case '5':
			{
				sprite->drawSprite(0, 64, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case '6':
			{
				sprite->drawSprite(0, 80, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case '7':
			{
				sprite->drawSprite(0, 96, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case '8':
			{
				sprite->drawSprite(0, 112, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case '9':
			{
				sprite->drawSprite(0, 128, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'a':
			{
				sprite->drawSprite(0, 144, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'b':
			{
				sprite->drawSprite(0, 160, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'c':
			{
				sprite->drawSprite(0, 176, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'd':
			{
				sprite->drawSprite(0, 192, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));

				break;
			}
			case 'e':
			{
				sprite->drawSprite(0, 224, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'f':
			{
				sprite->drawSprite(0, 240, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));

				break;
			}
			case 'g':
			{
				sprite->drawSprite(0, 256, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'h':
			{
				sprite->drawSprite(0, 270, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'i':
			{
				sprite->drawSprite(0, 288, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'k':
			{
				sprite->drawSprite(0, 304, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'l':
			{
				sprite->drawSprite(0, 320, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'm':
			{
				sprite->drawSprite(0, 336, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'n':
			{
				sprite->drawSprite(0, 352, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'o':
			{
				sprite->drawSprite(0, 368, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'p':
			{
				sprite->drawSprite(0, 384, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'q':
			{
				sprite->drawSprite(0, 400, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'r':
			{
				sprite->drawSprite(0, 416, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 's':
			{
				sprite->drawSprite(0, 432, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 't':
			{
				sprite->drawSprite(0, 448, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'u':
			{
				sprite->drawSprite(0, 464, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'v':
			{
				sprite->drawSprite(0, 480, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'w':
			{
				sprite->drawSprite(0, 496, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'x':
			{
				sprite->drawSprite(0, 512, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'y':
			{
				sprite->drawSprite(0, 528, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'z':
			{
				sprite->drawSprite(0, 544, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'A':
			{
				sprite->drawSprite(0, 560, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'B':
			{
				sprite->drawSprite(0, 576, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'C':
			{
				sprite->drawSprite(0, 592, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'D':
			{
				sprite->drawSprite(0, 608, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'E':
			{
				sprite->drawSprite(0, 624, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'F':
			{
				sprite->drawSprite(0, 640, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'G':
			{
				sprite->drawSprite(0, 656, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'H':
			{
				sprite->drawSprite(0, 672, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'I':
			{
				sprite->drawSprite(0, 688, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'K':
			{
				sprite->drawSprite(0, 704, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'L':
			{
				sprite->drawSprite(0, 720, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'M':
			{
				sprite->drawSprite(0, 736, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'N':
			{
				sprite->drawSprite(0, 752, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'O':
			{
				sprite->drawSprite(0, 768, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'P':
			{
				sprite->drawSprite(0, 784, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'Q':
			{
				sprite->drawSprite(0, 800, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'R':
			{
				sprite->drawSprite(0, 816, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'S':
			{
				sprite->drawSprite(0, 832, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case 'T':
			{
				sprite->drawSprite(0, 848, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
				break;
			}
			case'U':
			{
				sprite->drawSprite(0, 864, 16, 16, D3DXVECTOR3(j * BRICK_SIZE, i * BRICK_SIZE, 0));
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

void Map::Update() {

}

void Map::Update(int roomID) {

}