#pragma once
#include "Engine/GameObject.h"

//�O���錾
class FBX;

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

