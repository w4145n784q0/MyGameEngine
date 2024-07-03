#pragma once
#include"Direct3D.h"
#include <DirectXMath.h>
#include"Texture.h"
#include<vector>
#include"Transform.h"

using std::vector;
using namespace DirectX;

//�R���X�^���g�o�b�t�@�[:�A�v��������V�F�[�_�ɖ��t���[���n���������

struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;
	XMMATRIX    matW;
};

//���_���
struct VERTEX
{
	XMVECTOR position;
	XMVECTOR uv;
	XMVECTOR normal;//�@���x�N�g���@�m�[�}���ǉ�
};

class Quad
{
protected:
	int vertexNum_;
	std::vector<VERTEX> vertices_;
	int indexNum_;//�C���f�b�N�X��
	std::vector<int> index_;//�C���f�b�N�X���

	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_; //�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@

	Texture* pTexture_;
public:
	Quad();
	virtual ~Quad();
	HRESULT Initialize();
	//void Draw();
	void Draw(Transform& transform);
	void Release();
private:
	virtual void InitVertexData();
	HRESULT CreateVertexBuffer();
	virtual void InitIndexData();
	HRESULT CreateIndexBuffer();
	HRESULT CreateConstantBuffer();
	HRESULT LoadTexture();

	//---------------draw�֐�����Ă΂��֐�---------------
	void PassDataToCB(XMMATRIX worldMatrix);
	void SetBufferToPipeline();
};

