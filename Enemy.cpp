#include "Enemy.h"
#include"Model.h"
Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel(-1)
{
}

void Enemy::Initialize()
{
	hModel = Model::Load("Assets//Black_oden.fbx");
	transform_.position_.y = 2.5f;
	transform_.scale_ = { 0.5,0.5,0.5 };
	transform_.rotate_.x = 180;
}

void Enemy::Update()
{
	static int dt;
	dt += 5;
	float nTime = dt / (60.0f * 10.0f) - 2.0;
	transform_.position_.x = 4.0 * sin(nTime);
}

void Enemy::Draw()
{
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void Enemy::Release()
{
	
}