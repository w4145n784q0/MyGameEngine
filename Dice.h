#pragma once
#include "Quad.h"
#include"Transform.h"

class Dice :
    public Quad
{
public:
    Dice() :Quad() {};
    virtual ~Dice();
    void InitVertexData() override;
    void InitIndexData() override;
    /*//virtual HRESULT Initialize();
    //virtual void Draw();
    void Draw(Transform &transform);
    void Release();*/


    /*HRESULT CreateVertexBuffer();
    HRESULT CreateIndexBuffer();
    HRESULT CreateConstantBuffer();
    HRESULT LoadTexture();
    //---------------draw�֐�����Ă΂��֐�---------------
    void PassDataToCB(XMMATRIX worldMatrix);
    void SetBufferToPipeline();*/
};

