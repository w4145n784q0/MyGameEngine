#include "TitleScene.h"
#include"SceneManager.h"
#include"Input.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent,"TitleScene")
{
}

void TitleScene::Initialize()
{
}

void TitleScene::Update()
{
	if (Input::IsKeyUp(DIK_SPACE)) {
		SceneManager* ps = (SceneManager*)FindObject("SceneManager");
		ps->ChangeScene(SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{
}

void TitleScene::Release()
{
}
