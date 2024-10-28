#pragma once
#include "Engine/GameObject.h"
class TitleScene :
    public GameObject
{
public:
	TitleScene(GameObject* parent);
	~TitleScene(){};

	void Initialize();
	void Update();
	void Draw();
	void Release();
};

