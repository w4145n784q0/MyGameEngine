#pragma once
#include "Engine/GameObject.h"
class FBX;

class EnemyBullet :
    public GameObject
{
	int hModel_;
	int attacktype;
public:
	EnemyBullet(GameObject* parent);
	~EnemyBullet() {};

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	void Attack1();
	void Attack2();

	void SetAttack(int attack) { attacktype = attack; }

	void OnCollision(GameObject* pTarget) override;
};

