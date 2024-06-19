#pragma once
#include"Direct3D.h"
#include <DirectXMath.h>
#include"Texture.h"
#include<vector>

using std::vector;
using namespace DirectX;

//�R���X�^���g�o�b�t�@�[:�A�v��������V�F�[�_�ɖ��t���[���n���������

struct CONSTANT_BUFFER
{
	XMMATRIX    matW;
};

//���_���
struct VERTEX
{
	XMVECTOR position;
	XMVECTOR uv;
};

class Sprite
{
	uint64_t vertecNum_;            //���_��
	vector<VERTEX> vertices_;        //���_���
	uint64_t indexNum_;             //�C���f�b�N�X��
	vector<int> indces_;            //�C���f�b�N�X���

	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_;    //�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@

	Texture* pTexture_;				//texture�ւ̃|�C���^
public:
	Sprite();
	 ~Sprite();
	 HRESULT Initialize();//�������@�R���X�g���N�^�łł��Ȃ���͂������ŏ�����
	 void Draw(XMMATRIX& worldMatrix);//�`��
	 void Release();//���
private:
	//-----------------initialize����Ă΂��֐�-----------------
	void  InitVertexData();//���_���̏���
	HRESULT CreateVertexBuffer();

	void InitIndexData();
	HRESULT CreateIndexBuffer();
	HRESULT CreateConstantBuffer();
	HRESULT LoadTexture();

	//-----------------Draw����Ă΂��֐�-----------------
	void PassDataToCB(DirectX::XMMATRIX& worldMatrix);
	void SetBufferToPipeline();
};

