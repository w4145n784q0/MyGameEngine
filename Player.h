#pragma once
#include "Engine/GameObject.h"
#include"Heart.h"
class FBX;//pointa�g���Ȃ�O���錾���邾����OK�@���d��`�̖h�~�Ɏg����

class Player :
    public GameObject
{
	int hModel;
public:
	Player(GameObject* parent);
	~Player();

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};

