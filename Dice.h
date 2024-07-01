#pragma once
#include "Quad.h"
#include <DirectXMath.h>
#include"Transform.h"

using namespace DirectX;




class Dice :
    public Quad
{
     ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
    ID3D11Buffer* pIndexBuffer_; //インデックスバッファ
    ID3D11Buffer* pConstantBuffer_;	//コンスタントバッファ
    Texture* pTexture_;
public:
    Dice();
    virtual ~Dice();
    virtual HRESULT Initialize();
    virtual void Draw();
    void Draw(Transform &transform);
    void Release();

};

