#include "Camera.h"

namespace Camera
{
	//変数
	XMVECTOR position_;	//カメラの位置（視点）
	XMVECTOR target_;	//見る位置（焦点）
	XMMATRIX viewMatrix_;	//ビュー行列
	XMMATRIX projMatrix_;	//プロジェクション行列
	float AspectRatio = (FLOAT)800 / (FLOAT)600;//アスペクト比
}

//初期化
void Camera::Initialize()
{
	position_ = XMVectorSet(0, 3, -10, 0);	//カメラの位置
	target_ = XMVectorSet(0, 0, 0, 0);	//カメラの焦点
	//プロジェクション行列
	projMatrix_ = XMMatrixPerspectiveFovLH(XM_PIDIV4, AspectRatio, 0.1f, 100.0f);
}

void Camera::Initialize(XMVECTOR _position, XMVECTOR _target)
{
	position_ = _position;
	target_ = _target;
	projMatrix_ = XMMatrixPerspectiveFovLH(XM_PIDIV4, AspectRatio, 0.1f, 100.0f);
}

//更新
void Camera::Update()
{//ビュー行列の作成
	viewMatrix_ = XMMatrixLookAtLH(position_, target_, XMVectorSet(0, 1, 0, 0));
}

//位置を設定
void Camera::SetPosition(XMVECTOR position)
{
	position_ = position;
}

//焦点を設定
void Camera::SetTarget(XMVECTOR target)
{
	target_ = target;
}

//ビュー行列を取得
XMMATRIX Camera::GetViewMatrix()
{
	return viewMatrix_;
}

//プロジェクション行列を取得
XMMATRIX Camera::GetProjectionMatrix()
{
	return projMatrix_;
}