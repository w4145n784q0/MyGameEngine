#pragma once
#include "Engine/GameObject.h"
#include"Engine/Sprite.h"

class ClearScene :
    public GameObject
{
private:
	int hImage_;
	Sprite* spr;
public:
	ClearScene(GameObject* parent);
	~ClearScene() {};

	void Initialize();
	void Update();
	void Draw();
	void Release();
};

