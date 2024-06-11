#pragma once
#include "Quad.h"
#include <DirectXMath.h>

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
    ~Dice();
    HRESULT Initialize();
    void Draw();
    void Draw(XMMATRIX& worldMatrix);
    void Release();

};

