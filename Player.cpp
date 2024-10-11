#include "Player.h"
#include"Engine/FBX.h"
#include"ChildOden.h"
#include"Input.h"
Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),pOden(nullptr)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	pOden = new FBX();
	pOden->Load("Assets//oden.fbx");
	transform_.scale_ = { 0.4,0.4,0.4 };
	transform_.position_ = { 0,-2,0 };

	/*GameObject *pCO = Instantiate<ChildOden>(this);
	pCO->SetPosition(0, 0, -1);
	GameObject* pCO2 = Instantiate<ChildOden>(this);
	pCO2->SetPosition(-2, 0, -1);*/
}

void Player::Update()
{
	transform_.rotate_.y += 1;
	/*if (transform_.rotate_.y > 60 * 2) 
	{
		KillMe();
	}*/

	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.2;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.2;
	}

	if(Input::IsKey(DIK_SPACE))
	{
		GameObject* pCO = Instantiate<ChildOden>(this);
		pCO->SetPosition(0, 5, 0);
	}
}

void Player::Draw()
{
	pOden->Draw(transform_);
}

void Player::Release()
{
	pOden->Release();
	delete pOden;
}
