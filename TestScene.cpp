#include "TestScene.h"
#include"SceneManager.h"
#include"Input.h"
TestScene::TestScene(GameObject* parent)
	:GameObject(parent,"TestScene")
{
}

void TestScene::Initialize()
{
}

void TestScene::Update()
{
	if (Input::IsKeyUp(DIK_A)) {

	}

}

void TestScene::Draw()
{
}

void TestScene::Release()
{
}
