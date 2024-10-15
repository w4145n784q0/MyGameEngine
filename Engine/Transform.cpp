#include "Transform.h"

Transform::Transform()
   :position_({0,0,0}),
    rotate_({ 0,0,0 }),
    scale_({ 1,1,1 }),
    matTranslate_(XMMatrixIdentity()),
    matRotate_(XMMatrixIdentity()),
    matScale_(XMMatrixIdentity()),
    pParent_(nullptr)
{
  /* float x = XMVectorGetX(position_);
   float y = XMVectorGetY(position_);
   float z = XMVectorGetZ(position_);
   float w = XMVectorGetW(position_);*/
}

Transform::~Transform()
{
}

void Transform::Calculation()
{
//srt�̏��Ԃł�����ƃ��[���h�ϊ�
    matTranslate_ = XMMatrixTranslation(position_.x, position_.y, position_.z);

    //R = z*x*y�̏��Ԃōs����������DirectX�̉�]�ɂȂ�
    //digree->radians XMConvertToRadians
    XMMATRIX rx = XMMatrixRotationX(XMConvertToRadians(rotate_.x));
    XMMATRIX ry = XMMatrixRotationY(XMConvertToRadians(rotate_.y));
    XMMATRIX rz = XMMatrixRotationZ(XMConvertToRadians(rotate_.z));

    matRotate_ = rz * rx * ry;

    matScale_ = XMMatrixScaling(scale_.x,scale_.y,scale_.z);
}

XMMATRIX Transform::GetWorldMatrix()
{
    if (pParent_ != nullptr) {
        return matScale_ * matRotate_ * matTranslate_ * pParent_->GetWorldMatrix();//srt * �e�̎p���s������߂�
    }
    else
    {
        return matScale_ * matRotate_ * matTranslate_;//srt�����߂�
    }
}

XMMATRIX Transform::GetNormalMatrix()
{
    //���s�ړ��͖����@��]�͂�����@�g��k���͂��Ƃɖ߂�
    return(  matRotate_ * XMMatrixInverse(nullptr,matScale_));
}