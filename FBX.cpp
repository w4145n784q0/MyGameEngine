#include "FBX.h"

FBX::FBX():
pVertexBuffer_(nullptr),pIndexBuffer_(nullptr),
pConstantBuffer_(nullptr),
vertexCount_(-1),polygonCount_(-1)
{
}

HRESULT FBX::Load(std::string fileName)
{
	//�}�l�[�W���𐶐�
	FbxManager* pFbxManager = FbxManager::Create();

	//�C���|�[�^�[�𐶐�
	FbxImporter* fbxImporter = FbxImporter::Create(pFbxManager, "imp");
	fbxImporter->Initialize(fileName.c_str(), -1, pFbxManager->GetIOSettings());

	//�V�[���I�u�W�F�N�g��FBX�t�@�C���̏��𗬂�����
	FbxScene* pFbxScene = FbxScene::Create(pFbxManager, "fbxscene");
	fbxImporter->Import(pFbxScene);
	fbxImporter->Destroy();

	//�}�l�[�W�����
	pFbxManager->Destroy();
	return S_OK;
}

void FBX::Draw(Transform& transform)
{
}

void FBX::Release()
{
}
