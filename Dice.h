#pragma once
#include "Quad.h"
#include"Transform.h"

class Dice :
    public Quad
{
public:
    Dice();
    virtual ~Dice();
    virtual HRESULT Initialize();
    virtual void Draw();
    void Draw(Transform &transform);
    void Release();

};

