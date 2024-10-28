#include "EnemyBullet.h"
#include"Engine/FBX.h"
#include"Model.h"
#include"Enemy.h"
#include"SphereCollider.h"
#include"SceneManager.h"
#include"Player.h"

EnemyBullet::EnemyBullet(GameObject* parent)
	:GameObject(parent,"EnemyBullet"),hModel_(-1)
{
}

void EnemyBullet::Initialize()
{
	hModel_ = Model::Load("Assets//Black_oden.fbx");
	transform_.scale_ = { 0.2,0.2,0.2 };
	transform_.rotate_.x = 180;
	SphereCollider* col = new SphereCollider(0.1f);
	this->AddCollider(col);
}

void EnemyBullet::Update()
{
	transform_.position_.y -= 0.3;
	transform_.rotate_.y += 3;
	Player* player = (Player*)FindObject("Player");

	if (transform_.position_.y <= -20)
	{
		KillMe();
	}

}

void EnemyBullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void EnemyBullet::Release()
{
}

void EnemyBullet::OnCollision(GameObject* pTarget)
{
	KillMe();
	pTarget->KillMe();
}
