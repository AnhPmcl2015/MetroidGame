//#include"Game.h"
//
//Game::Game()
//{
//
//}
//
//bool Game::Initialize(HWND hWnd, HINSTANCE hInstance, int width, int height)
//{
//	gDevice = new GraphicsDevice();
//	if (!gDevice->Initialize(hWnd, true))
//	{
//		return false;
//	}
//
//	//sound = new Sound(hWnd);
//	sound->LoadingSource();
//
//
//	spriteManager = new SpriteManager();
//	if (!spriteManager->Initialize(SPRITE_FILE))
//	{
//		return false;
//	}
//
//	scene = new BackGround(0, 0, 0, 0, 0, collisionManager, spriteManager, gDevice, sound);
//	if (!scene->Initialize(gDevice->device))
//	{
//		return false;
//	}
//
//	map = new Map(0, 0, 0, 0, 0, NULL, spriteManager, gDevice,sound);
//	if (!map->Initialize(gDevice->device))
//		return false;
//
//	collisionManager = new CollisionManager(width, height);
//	if (collisionManager)
//	{
//		collisionManager->ReadBrickData(COLLISION_FILE);
//		collisionManager->ReadMonsterData(MONSTER_FILE);
//		collisionManager->ReadRelation(RELATION_FILE);
//		collisionManager->ReadDoorData(DOOR_FILE);
//		collisionManager->ReadFieldData(FIELD_FILE);
//		map->ImportCollisionManager(collisionManager);
//	}
//	else
//	{
//		return false;
//	}
//
//	quadTree = new QuadTree(0, 0, 512, 512, 0, 0);
//	if (quadTree)
//	{
//		quadTree->Initialize(QUADTREE_FILE);
//	}
//	collisionManager->ImportQuadTree(quadTree);
//
//	player = new Player(626, 3250, 0, 0.2f, 0.2f, collisionManager, spriteManager, gDevice,sound);
//	//player = new Player(2976, 3232, 0, 0.2f, 0.2f, collisionManager, spriteManager, gDevice,sound);
//	//player = new Player(3136, 3232, 0, 0.2f, 0.2f, collisionManager, spriteManager, gDevice,sound);
//	if (!player->Initialize(gDevice->device))
//	{
//		return false;
//	}
//
//	collisionManager->ImportPlayerCol(626, 3250, 14, 32);
//
//	monsterManager = new MonsterManager(collisionManager, spriteManager, gDevice, sound);
//	if (monsterManager)
//	{
//		monsterManager->Initialize(MONSTER_FILE);
//	}
//
//	doorManager = new DoorManager(collisionManager, spriteManager, gDevice, sound);
//	if (doorManager)
//	{
//		doorManager->Initialize(DOOR_FILE);
//	}
//
//	keyBoard = new KeyBoard(player);
//	if (keyBoard->InitializeKeyBoard(hWnd, hInstance) == false)
//		return false;
//
//	camera = new Camera(width, height + 48, 0, DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f), collisionManager);
//
//	_width = width;
//	_height = height;
//
//	camera->Follow(scene);
//
//	sound->Play("title-screen", true, 1);
//
//	Intro = true;
//	SelectScene = false;
//	SelectScene1 = false;
//	SelectScene2 = false;
//	PLayScene = false;
//	scene->index = 0;
//
//	return true;
//}
//
//void Game::Run(float gameTime)
//{
//	//chay ham Update va Draw
//	Update(gameTime);
//	Draw(gameTime);
//}
//
//void Game::Update(float gameTime)
//{
//	camera->Update(AutoPlayer);
//	if (PLayScene == true)
//	{
//		_gameTime = gameTime;
//
//		
//
//		map->setLimitation(
//			(camera->getX() - (camera->getWidth() / 2)),
//			(camera->getY() + 32 - ((camera->getHeight()) / 2)),
//			camera->getWidth(),
//			camera->getHeight(),
//			player->GetPosition().x,
//			player->GetPosition().y);
//
//		for (int i = 0; i < collisionManager->DoorList.size(); i++)
//		{
//			doorManager->update(collisionManager->DoorList[i]);
//		}
//
//		player->Update(gameTime);
//
//		if (player->Auto == false)
//		{
//			for (int i = 0; i < collisionManager->MonsterList.size(); i++)
//			{
//				monsterManager->update(collisionManager->MonsterList[i], gameTime);
//			}
//
//		}
//	}
//}
//
//void Game::DrawMap()
//{
//	map->Draw(_gameTime);
//}
//
//void Game::Draw(float gameTime)
//{
//	gDevice->Clear(D3DCOLOR_XRGB(0, 0, 0));
//	gDevice->Begin();
//	if (PLayScene == true)
//	{
//		if (camera)
//		{
//			camera->SetTransform(gDevice);
//		}
//
//		if (map&&map->IsInitialize == true)
//		{
//			DrawMap();
//		}
//
//
//
//		if (player)
//			player->Draw(gameTime);
//
//		for (int i = 0; i < collisionManager->DoorList.size(); i++)
//		{
//			doorManager->draw(collisionManager->DoorList[i]);
//		}
//		for (int i = 0; i < collisionManager->MonsterList.size(); i++)
//		{
//			monsterManager->draw(collisionManager->MonsterList[i], gameTime);
//		}
//
//
//		collisionManager->resetList();
//	}
//	else
//	{
//		if (camera)
//		{
//			camera->SetTransform(gDevice);
//		}
//		scene->Draw(gameTime);
//	}
//	gDevice->End();
//	gDevice->Present();
//}
//
//void Game::ProcessController(HWND hWnd)
//{
//	keyBoard->ProcessKeyBoard(hWnd);
//	ProcessInput();
//}
//
//void Game::ProcessInput()
//{
//	if (keyBoard->IsKeyDown(DIK_LEFT))
//	{
//		if (PLayScene == true)
//			player->ProcessKey(LEFT_ARROW);
//	}
//	else if (keyBoard->IsKeyDown(DIK_RIGHT))
//	{
//		if (PLayScene == true)
//			player->ProcessKey(RIGHT_ARROW);
//	}
//	else if (keyBoard->IsKeyDown(DIK_UP))
//	{
//		if (PLayScene == true)
//			player->ProcessKey(UP_ARROW);
//		else
//			SceneChange(3);
//	}
//	else if (keyBoard->IsKeyDown(DIK_DOWN))
//	{
//		if (PLayScene == true)
//			player->ProcessKey(DOWN_ARROW);
//		else
//			SceneChange(2);
//	}
//	else if (keyBoard->IsKeyDown(DIK_F))
//	{
//		if (PLayScene == true)
//			player->ProcessKey(GOD_MODE);
//	}
//	else if (keyBoard->IsKeyDown(DIK_X))
//	{
//		if (PLayScene == true)
//			player->ProcessKey(JUMP_BUTTON);
//	}
//	else if (keyBoard->IsKeyDown(DIK_Z))
//	{
//		if (PLayScene == true)
//			player->ProcessKey(SHOOT_BUTTON);
//	}
//	else if (keyBoard->IsKeyDown(DIK_C))
//	{
//		if (Intro == true)
//			SceneChange(1);
//		else if (SelectScene2 == true)
//			SceneChange(4);
//	}
//	else
//		player->ProcessKey(UNKEY);
//}
//
//void Game::SceneChange(int index)
//{
//	switch (index)
//	{
//	case 1:
//	{
//		if (Intro == true)
//			Intro = false;
//		SelectScene1 = true;
//		scene->index = 1;
//		break;
//	}
//	case 2:
//	{
//		if (Intro == false)
//		{
//			SelectScene1 = true;
//			SelectScene2 = false;
//			scene->index = 1;
//		}
//		break;
//	}
//	case 3:
//	{
//		if (Intro == false)
//		{
//			SelectScene2 = true;
//			SelectScene1 = false;
//			scene->index = 2;
//		}
//		break;
//	}
//	case 4:
//	{
//		if (SelectScene2 == true)
//		{
//			PLayScene = true;
//			camera->Follow(player);
//			sound->Stop("title-screen");
//			sound->Play("brinstar", true, 1);
//		}
//		break;
//	}
//	default:
//		break;
//	}
//}
//
//
//Game::~Game()
//{
//	if (player)
//	{
//		delete player;
//		player = nullptr;
//	}
//
//	if (gDevice)
//	{
//		delete gDevice;
//		gDevice = nullptr;
//	}
//
//	if (camera)
//	{
//		delete camera;
//		camera = nullptr;
//	}
//	if (map)
//	{
//		delete map;
//		map = nullptr;
//	}
//
//}
