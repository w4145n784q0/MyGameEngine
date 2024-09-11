#pragma once
#include "Engine/GameObject.h"
class PlayScene :
    public GameObject
{
public:
	PlayScene(GameObject* parent);
	~PlayScene();

	 void Initialize();
	 void Update();
	 void Draw();
	 void Release();
};

