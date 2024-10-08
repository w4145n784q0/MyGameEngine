#include "Input.h"


namespace Input
{
	//�O����A�N�Z�X����Ȃ�w�b�_�ɂ����ǉ�
	LPDIRECTINPUT8   pDInput = nullptr;

	//�L�[�{�[�h
	LPDIRECTINPUTDEVICE8 pKeyDevice = nullptr;
	BYTE keyState[256] = { 0 };
	BYTE prevKeyState[256] = { 0 };    //�O�t���[���ł̊e�L�[�̏��
	

		//�}�E�X
	LPDIRECTINPUTDEVICE8	pMouseDevice_;	//�f�o�C�X�I�u�W�F�N�g
	DIMOUSESTATE mouseState_;				//�}�E�X�̏��
	DIMOUSESTATE prevMouseState_;			//�O�t���[���̃}�E�X�̏��
	XMVECTOR mousePosition;//�}�E�X�̈ʒu

	void Initialize(HWND hWnd)
	{
		DirectInput8Create(GetModuleHandle(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDInput, nullptr);
		
		//�L�[�{�[�h
		pDInput->CreateDevice(GUID_SysKeyboard, &pKeyDevice, nullptr);//�f�o�C�X�̃I�u�W�F�N�g�쐬
		pKeyDevice->SetDataFormat(&c_dfDIKeyboard);//�L�[�{�[�h�ł��邱�Ƃ��`
		pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);//���̎��s���̃A�v���ɑ΂���D��x
	
		//�}�E�X
		pDInput->CreateDevice(GUID_SysMouse, &pMouseDevice_, nullptr);
		pMouseDevice_->SetDataFormat(&c_dfDIMouse);
		pMouseDevice_->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	}

	void Update()
	{
		

		//�L�[�{�[�h
		memcpy(prevKeyState, keyState, size_t(256));
		pKeyDevice->Acquire();//�����̂��}�i�[�݂����Ȃ��́i�L�[�{�[�h�����������Ƃ�����B�B�H�j
		pKeyDevice->GetDeviceState(sizeof(keyState), &keyState);//���̏u�Ԃ̑S�L�[�̏�Ԃ�ǂ�

		//�}�E�X
		pMouseDevice_->Acquire();
		memcpy(&prevMouseState_, &mouseState_, sizeof(mouseState_));
		pMouseDevice_->GetDeviceState(sizeof(mouseState_), &mouseState_);

	}

	/////////////////////////////�@�L�[�{�[�h���擾�@//////////////////////////////////
	bool IsKey(int keyCode)
	{
		if (keyState[keyCode] & 0x80)//128
		{
			return true;
		}
		return false;
	}

	bool IsKeyDown(int keyCode)
	{
		//���͉����ĂāA�O��͉����ĂȂ�
		if ((keyState[keyCode] & 0x80) && keyState[keyCode] != prevKeyState[keyCode])
		{
			return true;
		}
		return false;
	}

	bool IsKeyUp(int keyCode)
	{
		if ((prevKeyState[keyCode] & 0x80) && keyState[keyCode] != prevKeyState[keyCode])
		{
			return true;
		}
		return false;
	}
	/////////////////////////////�@�L�[�{�[�h���擾�@//////////////////////////////////

	/////////////////////////////�@�}�E�X���擾�@//////////////////////////////////

	//�}�E�X�̃{�^����������Ă��邩���ׂ�
	bool IsMouseButton(int buttonCode)
	{
		//�����Ă�
		if (mouseState_.rgbButtons[buttonCode] & 0x80)
		{
			return true;
		}
		return false;
	}

	//�}�E�X�̃{�^�����������������ׂ�i�������ςȂ��͖����j
	bool IsMouseButtonDown(int buttonCode)
	{
		//���͉����ĂāA�O��͉����ĂȂ�
		if (IsMouseButton(buttonCode) && !(prevMouseState_.rgbButtons[buttonCode] & 0x80))
		{
			return true;
		}
		return false;
	}

	//�}�E�X�̃{�^�����������������ׂ�
	bool IsMouseButtonUp(int buttonCode)
	{
		//�������ĂȂ��āA�O��͉����Ă�
		if (!IsMouseButton(buttonCode) && prevMouseState_.rgbButtons[buttonCode] & 0x80)
		{
			return true;
		}
		return false;
	}

	XMVECTOR GetMousePosition()
	{
		return mousePosition;
	}

	void SetMousePosition(int x, int y)
	{
		mousePosition = XMVectorSet((float)x, (float)y, 0, 0);
	}

	/////////////////////////////�@�}�E�X���擾�@//////////////////////////////////


	void Release()
	{
		SAFE_RELEASE(pMouseDevice_);
		SAFE_RELEASE(pKeyDevice);
		SAFE_RELEASE(pDInput);
	}
}