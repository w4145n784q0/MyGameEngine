#pragma once
#include "Engine/GameObject.h"
class FBX;

class EnemyBullet :
    public GameObject
{
	int hModel_;
public:
	EnemyBullet(GameObject* parent);
	~EnemyBullet() {};

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	void OnCollision(GameObject* pTarget) override;
};

