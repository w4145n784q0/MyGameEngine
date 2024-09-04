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

		//�}�e���A��
	struct MATERIAL
	{
		Texture* pTexture;
		XMFLOAT4 diffuse;
	};

	struct CONSTANT_BUFFER {
		XMMATRIX	matWVP;//���[���h�r���[�v���W�F�N�V����
		XMMATRIX    matNormal;//�@���x�N�g���̕ϊ��p
		XMFLOAT4 diffuseColor;
		//bool isTextured;
		int isTextured;
	};

	//���_���
	struct VERTEX
	{
		XMVECTOR position;
		XMVECTOR uv;
		XMVECTOR normal;//�@���x�N�g���@�m�[�}���ǉ�
	};

	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer** pIndexBuffer_; //�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@
	/*std::vector<MATERIAL>pMaterialBuffer;*/
	std::vector <MATERIAL> pMaterialList_;
	std::vector<int>indexCount_;

	int vertexCount_;	//���_��
	int polygonCount_;	//�|���S����
	int materialCount_;	//�}�e���A���̌�
	void InitVertex(fbxsdk::FbxMesh* mesh);//���_�o�b�t�@����
	void InitIndex(fbxsdk::FbxMesh* mesh);//�C���f�b�N�X�o�b�t�@����
	void InitConstantBuffer();//�R���X�^���g�o�b�t�@����
	void InitMaterial(fbxsdk::FbxNode* pNode);
	
public:
	FBX();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    Release();
	
};

