#include "ChildOden.h"
#include"Engine/FBX.h"
#include"Model.h"

ChildOden::ChildOden(GameObject* parent)
	:GameObject(parent,"ChildOden"), hModel(-1)/*pFbx(nullptr)*/
{
}

ChildOden::~ChildOden()
{
}

void ChildOden::Initialize()
{
	/*pFbx = new FBX();
	pFbx->Load("Assets//oden.fbx");*/
	hModel = Model::Load("Assets//oden.fbx");
	transform_.scale_ = { 0.2,0.2,0.2 };
	/*transform_.position_.x = 2.0f;
	transform_.position_.y = 1.0f;*/

}

void ChildOden::Update()
{
	transform_.position_.y += 0.3;
	transform_.rotate_.y += 3;
	if (transform_.position_.y >= 20)
	{
		KillMe();
	}
}

void ChildOden::Draw()
{
	//pFbx->Draw(transform_);
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void ChildOden::Release()
{
}
