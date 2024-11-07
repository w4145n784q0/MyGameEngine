#include "EnemyBullet.h"
#include"Engine/FBX.h"
#include"Model.h"
#include"Enemy.h"
#include"SphereCollider.h"
#include"SceneManager.h"
#include"Player.h"

#include<cmath>

namespace {
	const int DeadLine = -20;
	int rot = 180;
	float MoveX = 0.1f;
	const float pi = 3.14f;
}

EnemyBullet::EnemyBullet(GameObject* parent)
	:GameObject(parent,"EnemyBullet"),hModel_(-1),attacktype(0),movevalue(0.0f)
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
	Player* player = (Player*)FindObject("Player");//‹¤’Ê
	switch (attacktype)
	{
	case 0:
		Attack1();
		break;
	case 1:
		Attack2();
		break;
	case 2:
		Attack3();
		break;
	default:
		break;
	}

	/*transform_.position_.y -= 0.3;
	transform_.rotate_.y += 3;*/

	if (transform_.position_.y <= DeadLine)//‹¤’Ê
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

void EnemyBullet::Attack1()
{
	transform_.position_.y -= 0.3;
	transform_.rotate_.y += 3;
}

void EnemyBullet::Attack2()
{
	transform_.position_.y -= 0.1;
	transform_.rotate_.y += 3;

	float val = sin(movevalue) * 0.1f;//-0.1‚©‚ç0.1
	transform_.position_.x += val;
	movevalue += 0.08f;

	if (movevalue >= 2 * pi) 
	{
		movevalue -= 2 * pi;
	}
}

void EnemyBullet::Attack3()
{
	transform_.position_.y -= 0.08;
	transform_.rotate_.y += 3;
}

void EnemyBullet::OnCollision(GameObject* pTarget)
{
	if (pTarget == FindObject("Player"))
	{
 		KillMe();
		pTarget->Damage();
	}
}
