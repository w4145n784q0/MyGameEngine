#pragma once
#include"Direct3D.h"
#include <DirectXMath.h>
#include"Texture.h"

using namespace DirectX;

//�R���X�^���g�o�b�t�@�[

struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;
};

//���_���
struct VERTEX
{
	XMVECTOR position;
	XMVECTOR uv;
};

class Quad
{
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_; //�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@

	Texture* pTexture_;
public:
	Quad();
	virtual ~Quad();
	virtual HRESULT Initialize();
	virtual void Draw();
	virtual void Draw(XMMATRIX& worldMatrix);
	virtual void Release();
};

