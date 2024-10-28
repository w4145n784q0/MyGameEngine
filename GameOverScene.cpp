#include "GameOverScene.h"
#include"SceneManager.h"
#include"Input.h"
GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent,"GameOverScene")
{
}

void GameOverScene::Initialize()
{
}

void GameOverScene::Update()
{
	if (Input::IsKeyUp(DIK_SPACE)) {
		SceneManager* ps = (SceneManager*)FindObject("SceneManager");
		ps->ChangeScene(SCENE_ID_TITLE);
	}
}

void GameOverScene::Draw()
{
}

void GameOverScene::Release()
{
}
