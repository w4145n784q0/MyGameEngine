#pragma once
#include "Quad.h"
#include <DirectXMath.h>

using namespace DirectX;




class Dice :
    public Quad
{
    ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
    ID3D11Buffer* pIndexBuffer_; //�C���f�b�N�X�o�b�t�@
    ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@
    Texture* pTexture_;
public:
    Dice();
    ~Dice();
    HRESULT Initialize();
    void Draw();
    void Draw(XMMATRIX& worldMatrix);
    void Release();

};

