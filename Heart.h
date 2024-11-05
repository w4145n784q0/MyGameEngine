#pragma once
#include "Engine/GameObject.h"
#include"Engine/Sprite.h"

class Heart :
    public GameObject
{
private:
	int hImage_;
	int hImage2_;
	Sprite* spr_;
	int DrawCount_;
public:
	Heart(GameObject* parent);
	~Heart() {};

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	void SetDrawCount(int count) { DrawCount_ = count; }
};

