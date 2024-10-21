#pragma once
#include "Engine/GameObject.h"

enum SCENE_ID
{
	SCENE_ID_TEST = 0,
	SCENE_ID_PLAY,
	SCENE_MAS
};

class SceneManager :
    public GameObject
{
	SCENE_ID currentSceneID;
	SCENE_ID nextSceneID;

public:
	SceneManager(GameObject* parent);
	~SceneManager() ;

	//�V�[���؂�ւ�()
	void ChangeScene(SCENE_ID nextScene)
	{
		nextSceneID = nextScene;
	}

	void Initialize();
	void Update();
	void Draw();
	void Release();
};

