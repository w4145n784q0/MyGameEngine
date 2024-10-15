#include"Model.h"

namespace Model
{
	std::vector<ModelData*> modelList_;
}
//namespace�͕ʂ̂Ƃ��납��ł��ǉ��ł���

int Model::Load(std::string filename)
{
	//file���̃��f����ǂݍ���
	//�������f�������łɓǂݍ��܂�Ă�����G���[-1��Ԃ�
	//���߂Ă̓ǂݍ��݂������烂�f����ǂݍ���Ŕz��ɒǉ�

	ModelData* pData = new ModelData;//new����Ώ���ɂ͏����Ȃ��������ŏ����K�v����
	pData->Filename_ = filename;
	pData->pFBX_ = nullptr;

	for (auto& e : modelList_)
	{
		if (e->Filename_ == filename)//�����̂��͓̂���FBX���g����transform�����ς���
		{
			pData->pFBX_ = e->pFBX_;
			break;
		}
	}

	if (pData->pFBX_ == nullptr)//�����̃t�@�C���̓��X�g�ɂȂ�
	{
		pData->pFBX_ = new FBX;
		pData->pFBX_->Load(filename);
	}
	modelList_.push_back(pData);
	return(modelList_.size() - 1);
}

void Model::SetTransform(int hModel, Transform transform)
{
	//handle��modeldata�ɓ��Ă�ꂽNo�̂���
	modelList_[hModel]->trans_ = transform;

}

void Model::Draw(int hModel)
{
	modelList_[hModel]->pFBX_->Draw(modelList_[hModel]->trans_);
}

void Model::Release()
{
}
