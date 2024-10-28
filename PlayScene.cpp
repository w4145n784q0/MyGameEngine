#include "PlayScene.h"
#include"Player.h"
#include"Enemy.h"
#include"SceneManager.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	/*Player* pPlayer;
	pPlayer = new Player(this);
	pPlayer->Initialize();
	childList_.push_back(pPlayer);*/

	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
}

void PlayScene::Update()
{
	if (FindObject("Enemy") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
	/*SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	pSceneManager->ChangeScene(SCENE_ID_CLEAR);*/
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
