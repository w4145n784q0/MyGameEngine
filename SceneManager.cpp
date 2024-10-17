#include "SceneManager.h"
#include"TestScene.h"
SceneManager::SceneManager(GameObject* parent)
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Initialize()
{
	currentSceneID = SCENE_ID_TEST;
	nextSceneID = currentSceneID;
	Instantiate<TestScene>(this);
}

void SceneManager::Update()
{
}

void SceneManager::Draw()
{
}

void SceneManager::Release()
{
}
