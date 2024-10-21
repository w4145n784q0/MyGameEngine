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

	//ÉVÅ[ÉìêÿÇËë÷Ç¶()
	void ChangeScene(SCENE_ID nextScene)
	{
		nextSceneID = nextScene;
	}

	void Initialize();
	void Update();
	void Draw();
	void Release();
};

