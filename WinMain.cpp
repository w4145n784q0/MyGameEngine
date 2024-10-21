//�C���N���[�h
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include<cstdlib>//���{�{����Ă�ł��n�j
#include"Engine/Direct3D.h"
#include"Engine/Camera.h"
#include"Engine/RootJob.h"
#include"Input.h"
#include"Model.h"

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib, "winmm.lib")

//�萔�錾
const wchar_t* WIN_CLASS_NAME = L"SampleGame";//�E�B���h�E�N���X��
const wchar_t* APP_GAME = L"�T���v���Q�[��";//�A�v���P�[�V������

RootJob* pRootJob = nullptr;

const int WINDOW_WIDTH = 800;//�E�B���h�E��
const int WINDOW_HEIGHT = 600;//�E�B���h�E�̍���


//�v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);



//�G���g���[�|�C���g
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
  //�E�B���h�E�N���X�i�݌v�}�j���쐬
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);             //���̍\���̂̃T�C�Y
    wc.hInstance = hInstance;                   //�C���X�^���X�n���h��
    wc.lpszClassName = WIN_CLASS_NAME;            //�E�B���h�E�N���X��
    wc.lpfnWndProc = WndProc;                   //�E�B���h�E�v���V�[�W��
    wc.style = CS_VREDRAW | CS_HREDRAW;         //�X�^�C���i�f�t�H���g�j
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); //�A�C�R��
    wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);   //�������A�C�R��
    wc.hCursor = LoadCursor(NULL, IDC_NO);   //�}�E�X�J�[�\��
    wc.lpszMenuName = NULL;                     //���j���[�i�Ȃ��j
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //�w�i�i���j
    RegisterClassEx(&wc);  //�N���X��o�^

    //�E�B���h�E�T�C�Y�̌v�Z
    //(�\���̈��WINDOW_WIDTH * WINDOW_HEIGHT�Ɏw�肷�邽�߂̌v�Z)
    RECT winRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    AdjustWindowRect(&winRect, WS_OVERLAPPEDWINDOW, FALSE);
    int winW = winRect.right - winRect.left;     //�E�B���h�E��
    int winH = winRect.bottom - winRect.top;     //�E�B���h�E����

  //�E�B���h�E���쐬
    HWND hWnd = CreateWindow(
        WIN_CLASS_NAME,         //�E�B���h�E�N���X�� ��̃N���X���Ɠ���
        APP_GAME,     //�^�C�g���o�[�ɕ\��������e
        WS_OVERLAPPEDWINDOW, //�X�^�C���i���ʂ̃E�B���h�E�j
        CW_USEDEFAULT,       //�\���ʒu���i���܂����j
        CW_USEDEFAULT,       //�\���ʒu��i���܂����j
        winW,                 //�E�B���h�E��
        winH,                 //�E�B���h�E����
        NULL,                //�e�E�C���h�E�i�Ȃ��j
        NULL,                //���j���[�i�Ȃ��j
        hInstance,           //�C���X�^���X
        NULL                 //�p�����[�^�i�Ȃ��j
    );

  //�E�B���h�E��\��
    ShowWindow(hWnd, nCmdShow);

    //Direct3D������
    HRESULT hr =  Direct3D::Initialize(winW, winH, hWnd);
    if (FAILED(hr))
    {
        return 0;
    }

    Camera::Initialize();
    Input::Initialize(hWnd);

    pRootJob = new RootJob(nullptr);
    pRootJob->Initialize();
    

  //���b�Z�[�W���[�v�i�����N����̂�҂j
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        //���b�Z�[�W����
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        //���b�Z�[�W�Ȃ�
        else
        {//���̂���������1�t���[��

            timeBeginPeriod(1);
            static DWORD startTime = timeGetTime();//timeGetTime() ->window���N�����Ă���̎��Ԃ��~���b
            DWORD nowTime = timeGetTime();
            timeEndPeriod(1);

            static DWORD lastUpdateTime = nowTime;
            static DWORD countFps = 0;// DWORD unsigned long�̈Ӗ�
            //char str[16];

            if (nowTime - startTime >= 1000)
            {
                std::wstring str;
                wsprintf(str.data(), L"%u", countFps);
                SetWindowTextW(hWnd, str.c_str());

                countFps = 0;
                startTime = nowTime;
            }

            if (nowTime - lastUpdateTime <= 1000.0f / 60.0f)//1/60�b
            {
                continue;//�������牺�̏������X���[���ď�ɖ߂��@
            }
            //1/60�b�������̂ōX�V���X�V���Ԃ����̎��ԂɍX�V
            lastUpdateTime = nowTime;
            //wsprintf(str.data(), L"%u", nowTime - startTime);
            countFps++;

            //�J�����̍X�V
            Camera::Update();

            //���͏��̍X�V
            Input::Update();

            //���[�g�W���u����Ȃ��邷�ׂẴI�u�W�F�N�g��UPDATE����
            pRootJob->UpdateSub();

            //�Q�[���̏����@�`��J�n����
            Direct3D::BeginDraw();
            
            //���[�g�W���u����Ȃ��邷�ׂẴI�u�W�F�N�g��
            //DRAW����
            pRootJob->DrawSub();

            if (Input::IsKeyUp(DIK_ESCAPE))
            {
                static int cnt = 0;
                cnt++;
                if (cnt >= 3)
                {
                    PostQuitMessage(0);
                }
            }

            if (Input::IsMouseButtonUp(0))
            {
                
            }
            //�Q�[���̓��e�������Ă���

            //�`��I������
            Direct3D::EndDraw();
            
        }
    }
    Model::Release();
    pRootJob->ReleaseSub();
    Input::Release();
    Direct3D::Release();
	return 0;
}

//�E�B���h�E�v���V�[�W���i�������������ɂ�΂��֐��j
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY://�E�B���h�E������ꂽ��i�C�x���g�j
        PostQuitMessage(0);  //�v���O�����I��
        return 0;
        //WM_CLOSE X�{�^��
        //WM_
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

BOOL CALLBACK DialogProc(HWND hDlg, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_MOUSEMOVE:
        Input::SetMousePosition(LOWORD(lp), HIWORD(lp));
        return 0;
    }
    return FALSE;
}