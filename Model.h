#pragma once
#include<string>
#include"Engine/FBX.h"
#include"Engine/Transform.h"
using std::string;

namespace Model
{
	struct ModelData
	{
		FBX pFBX;
		Transform trans;
		string Filename;
	};
	//���f���̈ꗗ��ۑ�����z��vector��list

	int Load(std::string filename);

}

int Model::Load(std::string filename)
{
	//file���̃��f����ǂݍ���
	//�������f�������łɓǂݍ��܂�Ă�����G���[-1��Ԃ�
	//���߂Ă̓ǂݍ��݂������烂�f����ǂݍ���Ŕz��ɒǉ�
}