#pragma once
#include <dInput.h>
#include <DirectXMath.h>

#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dInput8.lib")

//SAFE_RELEASE�͕ʂ̃N���X�Ő錾���Ă��Ă������Ő錾���Ȃ��Ǝg���Ȃ�
#define SAFE_RELEASE(p) if(p != nullptr){ p->Release(); p = nullptr;}
using namespace DirectX;

namespace Input
{
	void Initialize(HWND hWnd);
	void Update();
	bool IsKey(int keyCode);
	bool IsKeyDown(int keyCode);
	bool IsKeyUp(int keyCode);

	//�}�E�X�̃{�^����������Ă��邩���ׂ�
//�����FbuttonCode	���ׂ����{�^���̔ԍ�
//�ߒl�F������Ă����true
	bool IsMouseButton(int buttonCode);

	//�}�E�X�̃{�^�����������������ׂ�i�������ςȂ��͖����j
	//�����FbuttonCode	���ׂ����{�^���̔ԍ�
	//�ߒl�F�������u�Ԃ�������true
	bool IsMouseButtonDown(int buttonCode);

	//�}�E�X�̃{�^�����������������ׂ�
	//�����FbuttonCode	���ׂ����{�^���̔ԍ�
	//�ߒl�F�������u�Ԃ�������true
	bool IsMouseButtonUp(int buttonCode);

	//�}�E�X�̈ʒu���擾
	XMVECTOR GetMousePosition();

	//�}�E�X�̈ʒu���w��
	void SetMousePosition(int x, int y);

	void Release();
};