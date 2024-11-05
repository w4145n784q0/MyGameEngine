#include "Heart.h"

namespace
{
	float size = 0.08;
}

Heart::Heart(GameObject* parent)
	:GameObject(parent, "Enemy"), hImage_(-1), spr_(nullptr),DrawCount_(-1)
{
}

void Heart::Initialize()
{
	spr_ = new Sprite();
	hImage_ = spr_->Load("Assets//bar.png");
	transform_.scale_ = { size,size,size };
}

void Heart::Update()
{
	
}

void Heart::Draw()
{
	for (int i = 0; i < DrawCount_; i++)
	{
		Transform trs;
		trs = transform_;
		trs.position_.x  = 0.1 * i;
		spr_->Draw(trs);
	}

}

void Heart::Release()
{
}
