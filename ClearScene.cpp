#include "ClearScene.h"
#include"SceneManager.h"
#include"Input.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent,"ClearScene"),hImage_(-1),spr(nullptr)
{
}

void ClearScene::Initialize()
{
	//hImage_ = spr->Load("Assets//sample.png");
}

void ClearScene::Update()
{
	if (Input::IsKeyUp(DIK_SPACE)) {
		SceneManager* ps = (SceneManager*)FindObject("SceneManager");
		ps->ChangeScene(SCENE_ID_TITLE);
	}
}

void ClearScene::Draw()
{
	Transform trs;
	trs.position_ = { 100,100,0 };
	//spr->Draw(trs);
}

void ClearScene::Release()
{
}
