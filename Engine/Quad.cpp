#include "Quad.h"
#include"Camera.h"

Quad::Quad(): pVertexBuffer_(nullptr), pIndexBuffer_(nullptr),
pConstantBuffer_(nullptr),pTexture_(nullptr),
vertexNum_(0),indexNum_(0)
{
}

Quad::~Quad()
{
	Release();
}

HRESULT Quad::Initialize()
{
	InitVertexData();

	if (FAILED(CreateVertexBuffer()))
	{
		return E_FAIL;
	}

	InitIndexData();

	if (FAILED(CreateIndexBuffer()))
	{
		return E_FAIL;
	}
	if (FAILED(CreateConstantBuffer()))
	{
		return E_FAIL;
	}

	if (FAILED(LoadTexture()))
	{
		return E_FAIL;
	}

	return S_OK;

	// ���_���
	//VERTEX vertices[] =
	//{
	//	//�l�p�`
	//	{ XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f), {0.0, 0.0, 0.0, 0.0}},// �l�p�`�̒��_�i����j
	//	{ XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f),	 {1.0, 0.0, 0.0, 0.0}},// �l�p�`�̒��_�i�E��j
	//	{ XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f),	 {1.0, 1.0, 0.0, 0.0}},// �l�p�`�̒��_�i�E���j
	//	{ XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f), {0.0, 1.0, 0.0, 0.0}},	// �l�p�`�̒��_�i�����j		
	//};
	//�܊p�`
	//XMVectorSet(0.5f,  1.2f, 0.0f, 0.0f),//�܊p�`�̒��_�i��ԏ�j
	//XMVectorSet(-0.3f, 0.5f, 0.0f, 0.0f),//�܊p�`�̒��_�i����j
	//	XMVectorSet(0.0f, -0.5f, 0.0f, 0.0f),//�܊p�`�̒��_�i�����j
	//	XMVectorSet(1.0f, -0.5f, 0.0f, 0.0f),//�܊p�`�̒��_�i�E���j
	//	XMVectorSet(1.3f, 0.5f, 0.0f, 0.0f),//�܊p�`�̒��_�i�E��j*/
	//6�p�`
	//XMVectorSet(0.5f,  1.0f, 0.0f, 0.0f),//�Z�p�`�̒��_�i�E��j
	//	XMVectorSet(1.0f,  0.0f, 0.0f, 0.0f),//�Z�p�`�̒��_�i�E�����j
	//	XMVectorSet(0.5f,  -1.0f, 0.0f, 0.0f),//�Z�p�`�̒��_�i�E���j
	//	XMVectorSet(-0.5f,  -1.0f, 0.0f, 0.0f),//�Z�p�`�̒��_�i�����j
	//	XMVectorSet(-1.0f,  0.0f, 0.0f, 0.0f),//�Z�p�`�̒��_�i�������j
	//	XMVectorSet(-0.5f,  1.0f, 0.0f, 0.0f),//�Z�p�`�̒��_�i����j*/
	//�l�p��
	//XMVectorSet(-0.5f,  0.0f, 1.0f, 0.0f),	// �l�p���̒��_�i����j
	//XMVectorSet(1.5f,  0.0f, 1.0f, 0.0f),	// �l�p���̒��_�i�E��j
	//XMVectorSet(0.5f, 0.0f, -1.0f, 0.0f),	// �l�p���̒��_�i�E���j
	//XMVectorSet(-1.5f, 0.0f, -1.0f, 0.0f),	// �l�p���̒��_�i�����j	
	//XMVectorSet(0.0f, 3.0f, 0.0f, 0.0f),     //�l�p���̒��_�i��ԏ�j
	////�C���f�b�N�X��� �l�p�`
	//int index[] = { 0,2,3, 0,1,2, }
	//�܊p�`
	//int index[] = { 0,1,2, 0,2,3, 0,3,4, };
	//�Z�p�`
	//int index[] = {0,1,2 };
	//�C���f�b�N�X��� �l�p�`
	//int index[] = { 0,2,3, 0,1,2, 0,1,4, 1,2,4, 2,3,4, 0,3,4, };
}

void Quad::Draw(Transform& transform)
{
	//�R���X�^���g�o�b�t�@�ɓn�����
	//XMVECTOR position = { 0, 3, -10, 0 };	//�J�����̈ʒu
	//XMVECTOR target = { 0, 0, 0, 0 };	//�J�����̏œ_
	//XMMATRIX view = XMMatrixLookAtLH(position, target, XMVectorSet(0, 1, 0, 0));	//�r���[�s��
	//XMMATRIX proj = XMMatrixPerspectiveFovLH(XM_PIDIV4, 800.0f / 600.0f, 0.1f, 100.0f);//�ˉe�s��
	////��p�A�A�X�y�N�g��A�j�A���ʁA�t�@�[����
	//CONSTANT_BUFFER cb;
	//cb.matWVP = XMMatrixTranspose(worldMatrix * Camera::GetViewMatrix() * Camera::GetProjectionMatrix());
	//cb.matW = XMMatrixTranspose(worldMatrix);
	//
	//D3D11_MAPPED_SUBRESOURCE pdata;
	//Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPU����̃f�[�^�A�N�Z�X���~�߂�
	//memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));	// �f�[�^��l�𑗂�
	//Direct3D::pContext->Unmap(pConstantBuffer_, 0);	//�ĊJ
	////���_�o�b�t�@
	//UINT stride = sizeof(VERTEX);
	//UINT offset = 0;
	//Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);
	//// �C���f�b�N�X�o�b�t�@�[���Z�b�g
	//stride = sizeof(int);
	//offset = 0;
	//Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);
	////�R���X�^���g�o�b�t�@
	//Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//���_�V�F�[�_�[�p	
	//Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//�s�N�Z���V�F�[�_�[�p
	////�T���v���[�ƃV�F�[�_�[���\�[�X�r���[���V�F�[�_�ɃZ�b�g
	//ID3D11SamplerState* pSampler = pTexture_->GetSampler();
	//Direct3D::pContext->PSSetSamplers(0, 1, &pSampler);
	//ID3D11ShaderResourceView* pSRV = pTexture_->GetSRV();
	//Direct3D::pContext->PSSetShaderResources(0, 1, &pSRV);
	//Direct3D::pContext->DrawIndexed(6, 0, 0); //�l�p�`
	////Direct3D::pContext->DrawIndexed(9, 0, 0); �܊p�`
	////Direct3D::pContext->DrawIndexed(18, 0, 0);//�l�p��

	Direct3D::SetShader(SHADER_3D);
	transform.Calculation();//�g�����X�t�H�[�����v�Z

	//�R���X�^���g�o�b�t�@�ɏ��n��
	PassDataToCB(transform);

	//���_�o�b�t�@�A�C���f�b�N�X�o�b�t�@�A�R���X�^���g�o�b�t�@���p�C�v���C���ɃZ�b�g
	SetBufferToPipeline();

	Direct3D::pContext->DrawIndexed(index_.size(), 0, 0);
}
	

void Quad::Release()
{
	SAFE_RELEASE(pConstantBuffer_);
	SAFE_RELEASE(pIndexBuffer_);
	SAFE_RELEASE(pVertexBuffer_);
}

void Quad::InitVertexData()
{
	vertices_ =
	{
		{ XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f), {0.0, 0.0, 0.0, 0.0}},// �l�p�`�̒��_�i����j
		{ XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f),	 {1.0, 0.0, 0.0, 0.0}},// �l�p�`�̒��_�i�E��j
		{ XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f),	 {1.0, 1.0, 0.0, 0.0}},// �l�p�`�̒��_�i�E���j
		{ XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f), {0.0, 1.0, 0.0, 0.0}},	// �l�p�`�̒��_�i�����j	
	};
	vertexNum_ = vertices_.size();
}

HRESULT Quad::CreateVertexBuffer()
{
	HRESULT hr;
	// ���_�f�[�^�p�o�b�t�@�̐ݒ�
	D3D11_BUFFER_DESC bd_vertex;
	bd_vertex.ByteWidth = sizeof(VERTEX) * vertexNum_;//�������̐�L�T�C�Y���Ƃ�@
	bd_vertex.Usage = D3D11_USAGE_DEFAULT;
	bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd_vertex.CPUAccessFlags = 0;
	bd_vertex.MiscFlags = 0;
	bd_vertex.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA data_vertex;
	data_vertex.pSysMem = vertices_.data();//vector�̐擪�ɂ��鐔�l���Ƃ�
	hr = Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_);

	if (FAILED(hr))
	{
		MessageBox(NULL, L"���_�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
		return hr;
	}
	return S_OK;
}

void Quad::InitIndexData()
{
	index_ = { 0,2,3, 0,1,2 };
	indexNum_ = index_.size();
}

HRESULT Quad::CreateIndexBuffer()
{
	HRESULT hr;

	// �C���f�b�N�X�o�b�t�@�𐶐�����
	D3D11_BUFFER_DESC   bd;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(int) * indexNum_;
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = index_.data();
	InitData.SysMemPitch = 0;
	InitData.SysMemSlicePitch = 0;
	hr = Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"�C���f�b�N�X�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
		return hr;
	}
	return S_OK;
}

HRESULT Quad::CreateConstantBuffer()
{
	HRESULT hr;

	//�R���X�^���g�o�b�t�@�쐬
	D3D11_BUFFER_DESC cb;
	cb.ByteWidth = sizeof(CONSTANT_BUFFER);
	cb.Usage = D3D11_USAGE_DYNAMIC;
	cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cb.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	cb.MiscFlags = 0;
	cb.StructureByteStride = 0;

	// �R���X�^���g�o�b�t�@�̍쐬
	hr = Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"�R���X�^���g�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
		return hr;
	}

	return S_OK;
	/*pTexture_ = new Texture;
	pTexture_->Load("Asset\\dice.png");*/

}

HRESULT Quad::LoadTexture()
{
	pTexture_ = new Texture;
	HRESULT hr;
	if (FAILED(hr = pTexture_->Load("Assets\\dice.png")))
	{
		MessageBox(NULL, L"�e�N�X�`���̍쐬�Ɏ��s", L"error", MB_OK);
		return hr;
	}
	return S_OK;
}

void Quad::PassDataToCB(Transform& transform)
{
	CONSTANT_BUFFER cb;
	cb.matWVP = XMMatrixTranspose(transform.GetWorldMatrix() * Camera::GetViewMatrix() * Camera::GetProjectionMatrix());
	cb.matW = XMMatrixTranspose(transform.GetNormalMatrix());

	D3D11_MAPPED_SUBRESOURCE pdata;
	Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPU����̃f�[�^�A�N�Z�X���~�߂�
	memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));	// �f�[�^��l�𑗂�
	Direct3D::pContext->Unmap(pConstantBuffer_, 0);	//�ĊJ
}

void Quad::SetBufferToPipeline()
{
	//���_�o�b�t�@
	UINT stride = sizeof(VERTEX);
	UINT offset = 0;
	Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);

	// �C���f�b�N�X�o�b�t�@�[���Z�b�g
	stride = sizeof(int);
	offset = 0;
	Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);

	//�R���X�^���g�o�b�t�@
	Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//���_�V�F�[�_�[�p	
	Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//�s�N�Z���V�F�[�_�[�p

	//�T���v���[�ƃV�F�[�_�[���\�[�X�r���[���V�F�[�_�ɃZ�b�g
	ID3D11SamplerState* pSampler = pTexture_->GetSampler();
	Direct3D::pContext->PSSetSamplers(0, 1, &pSampler);

	ID3D11ShaderResourceView* pSRV = pTexture_->GetSRV();
	Direct3D::pContext->PSSetShaderResources(0, 1, &pSRV);
}