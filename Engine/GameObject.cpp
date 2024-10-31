#include "GameObject.h"
#include"Direct3D.h"
#include"../SphereCollider.h"
#include<string>

using std::string;

GameObject::GameObject()
	:pParent_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	:pParent_(parent),objectName_(name),isDead_(false),pCollider_(nullptr),Hp_(0)
{
	if (parent != nullptr) {
		this->transform_.pParent_ = &(parent->transform_);
	}
}

GameObject::~GameObject()
{
}

void GameObject::Release()
{
}

void GameObject::UpdateSub()
{
	Update();
	RoundRobin(GetRootJob());

	for (auto itr : childList_)
	{
		itr->UpdateSub();
	}
	for (auto itr = childList_.begin(); itr != childList_.end();)
	{
		if ((*itr)->isDead_) {
			(*itr)->ReleaseSub();
			SAFE_DELETE(*itr);
			itr = childList_.erase(itr);
		}
		else
		{
			itr++;
		}
	}
}

void GameObject::DrawSub()
{
	Draw();
	for (auto itr : childList_)
	{
		itr->DrawSub();
	}
}

void GameObject::ReleaseSub()
{
	Release();
	for (auto itr : childList_)
	{
		itr->ReleaseSub();
	}
}

void GameObject::KillMe()
{
	isDead_ = true;
}

GameObject* GameObject::FindObject(string objName)
{
	//��������݂�rootjob��T����
	//����roogjob����S���̎q��H����objname��T��
	GameObject* rootJob = GetRootJob();
	GameObject* res = rootJob->FindChildObject(objName);
	return (res);
}

GameObject* GameObject::GetRootJob()
{
	if (pParent_ == nullptr){
		return this;
	}
	return pParent_->GetRootJob();
}

GameObject* GameObject::FindChildObject(string objName)
{
	if (this->objectName_ == objName)
	{
		return this;
	}
	else
	{
		for (auto itr : childList_)
		{
			GameObject* obj = itr->FindChildObject(objName);
			if(obj != nullptr)
				return obj;
		}
	}
	return nullptr;
}

void GameObject::AddCollider(SphereCollider* pColl)
{
	pCollider_ = pColl;

}

void GameObject::Collision(GameObject* pTarget)
{
	if (this->pCollider_ == nullptr || pTarget->pCollider_ == nullptr || pTarget == this)
	{
		return;
	}

	//�����ƃ^�[�Q�b�g�̃R���C�_�[���m�̓����蔻��
	
	XMVECTOR p1 = XMLoadFloat3(&transform_.position_);
	XMVECTOR p2 = XMLoadFloat3(&pTarget->transform_.position_);
	
	float dist = XMVectorGetX(XMVector3Length(p1 - p2));//this��target�̋���
	float rDist = this->pCollider_->GetRadius() + pTarget->pCollider_->GetRadius();//this��target�̔��a�̍��v
	if (dist <= rDist)
	{//��_�Ԃ̋��� >= this ��target�̔��a�̍��v
		//�������Ă�Ƃ��̏���	
  		OnCollision(pTarget);
	}
}

void GameObject::RoundRobin(GameObject* pTarget)
{
	//�����ƃ^�[�Q�b�g�̓����蔻��
	if (this->pCollider_ == nullptr) {
		return;
	}
	if (pTarget->pCollider_ != nullptr){
		Collision(pTarget);
	}

	//�����ƃ^�[�Q�b�g�̎q�I�u�W�F�N�g�S���̓����蔻��i�ċA�����j
	for (auto itr : pTarget->childList_)
	{
		RoundRobin(itr);
	}
}
