#include "Transform.h"

Transform::Transform()
   :position_(XMVectorZero()),
    rotate_(XMVectorZero()),
    scale_(XMVectorSet(1,1,1,1)),
    matTranslate_(XMMatrixIdentity()),
    matRotate_(XMMatrixIdentity()),
    matScale_(XMMatrixIdentity())
{
  /* float x = XMVectorGetX(position_);
   float y = XMVectorGetY(position_);
   float z = XMVectorGetZ(position_);
   float w = XMVectorGetW(position_);*/
}

Transform::~Transform()
{
}

void Transform::Calclation()
{

    float tx = XMVectorGetX(position_);
    float ty = XMVectorGetY(position_);
    float tz = XMVectorGetZ(position_);
    matTranslate_ = XMMatrixTranslation(tx, ty, tz);

    //R = z*x*y‚Ì‡”Ô‚Ås—ñ‚ð‚©‚¯‚é‚ÆDirectX‚Ì‰ñ“]‚É‚È‚é
    //digree->radians XMConvertToRadians
    float tmp_rx = XMConvertToRadians(XMVectorGetX(rotate_));
    float tmp_ry = XMConvertToRadians(XMVectorGetY(rotate_));
    float tmp_rz = XMConvertToRadians(XMVectorGetZ(rotate_));

    XMMATRIX rx = XMMatrixRotationX(tmp_rx);
    XMMATRIX ry = XMMatrixRotationY(tmp_ry);
    XMMATRIX rz = XMMatrixRotationZ(tmp_rz);
    matRotate_ = rz * rx * ry;

    float sx = XMVectorGetX(scale_);
    float sy = XMVectorGetY(scale_);
    float sz = XMVectorGetZ(scale_);
    matScale_ = XMMatrixScaling(sx, sy, sz);


}

XMMATRIX Transform::GetWorldMatrix()
{
    return matScale_ * matRotate_ * matTranslate_;
}
