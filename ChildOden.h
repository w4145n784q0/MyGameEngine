#pragma once
#include "Engine/GameObject.h"
class FBX;

class ChildOden :
    public GameObject
{
	FBX* pFbx;
public:
	ChildOden(GameObject* parent);
	~ChildOden();

	void Initialize();
	void Update();
	void Draw();
	void Release();
};

