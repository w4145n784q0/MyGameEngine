#pragma once
#include <string>
#include<list>
#include"Transform.h"

class GameObject
{
protected:
	std::list<GameObject*>childList_;
	Transform transform_;
	GameObject*	pParent_;
	std::string objectName_;

public:
	GameObject();
	GameObject(GameObject* parent, const std::string& name);
	~GameObject();

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;
	void UpdateSub();
	void DrawSub();
	void ReleaseSub();

	//template <typename T>//�N���X�Ȃ�class�Ƃ����@�قړ���
	template <class T> //t�|�C���^�^�@�������̃N���X�ɍ��킹������
	T* Instantiate(GameObject* pParent)
	{
		T* pTmp = new T(pParent);
		if (pTmp != nullptr)
		{
			pTmp->Initialize();
			childList_.push_back(pTmp);
		}
		return pTmp;
	}
};

