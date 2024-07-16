#pragma once
#include"Direct3D.h"
#include <DirectXMath.h>
#include"Texture.h"
#include<vector>
#include"Transform.h"
#include<filesystem>

#include <d3d11.h>
#include <fbxsdk.h>
#include <string>
#include "Transform.h"

#pragma comment(lib, "LibFbxSDK-MD.lib")
#pragma comment(lib, "LibXml2-MD.lib")
#pragma comment(lib, "zlib-MD.lib")
//�}���`�f�o�b�O��mt�Ȃ�MD�̂Ƃ����MT�ɂ���

class FBX
{
private:
	struct CONSTANT_BUFFER
	{
		XMMATRIX	matWVP;
		XMMATRIX    matW;
	};

	//���_���
	struct VERTEX
	{
		XMVECTOR position;
		//XMVECTOR uv;
		//XMVECTOR normal;//�@���x�N�g���@�m�[�}���ǉ�
	};
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_; //�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@

	int vertexCount_;	//���_��
	int polygonCount_;	//�|���S����
	void InitVertex(fbxsdk::FbxMesh* mesh);//���_�o�b�t�@����
	void InitIndex(fbxsdk::FbxMesh* mesh);//�C���f�b�N�X�o�b�t�@����
	void InitConstantBuffer();//�R���X�^���g�o�b�t�@����
public:
	FBX();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    Release();
	void PassDataToCB(Transform& transform);
	void SetBufferToPipeline();
};

