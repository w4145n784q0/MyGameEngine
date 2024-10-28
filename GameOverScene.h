#pragma once
#include "Engine/GameObject.h"
class GameOverScene :
    public GameObject
{
public:
	GameOverScene(GameObject* parent);
	~GameOverScene() {};

	void Initialize();
	void Update();
	void Draw();
	void Release();
};

