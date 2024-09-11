//インクルード
#include <Windows.h>
#include"Engine/Direct3D.h"
#include"Engine/Camera.h"
#include"Engine/RootJob.h"
#pragma comment(lib,"d3d11.lib")


//定数宣言
const wchar_t* WIN_CLASS_NAME = L"SampleGame";//ウィンドウクラス名
const wchar_t* APP_GAME = L"サンプルゲーム";//アプリケーション名

RootJob* pRootJob = nullptr;

const int WINDOW_WIDTH = 800;//ウィンドウ幅
const int WINDOW_HEIGHT = 600;//ウィンドウの高さ


//プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);



//エントリーポイント
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
  //ウィンドウクラス（設計図）を作成
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);             //この構造体のサイズ
    wc.hInstance = hInstance;                   //インスタンスハンドル
    wc.lpszClassName = WIN_CLASS_NAME;            //ウィンドウクラス名
    wc.lpfnWndProc = WndProc;                   //ウィンドウプロシージャ
    wc.style = CS_VREDRAW | CS_HREDRAW;         //スタイル（デフォルト）
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); //アイコン
    wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);   //小さいアイコン
    wc.hCursor = LoadCursor(NULL, IDC_NO);   //マウスカーソル
    wc.lpszMenuName = NULL;                     //メニュー（なし）
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //背景（白）
    RegisterClassEx(&wc);  //クラスを登録

    //ウィンドウサイズの計算
    //(表示領域をWINDOW_WIDTH * WINDOW_HEIGHTに指定するための計算)
    RECT winRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    AdjustWindowRect(&winRect, WS_OVERLAPPEDWINDOW, FALSE);
    int winW = winRect.right - winRect.left;     //ウィンドウ幅
    int winH = winRect.bottom - winRect.top;     //ウィンドウ高さ

  //ウィンドウを作成
    HWND hWnd = CreateWindow(
        WIN_CLASS_NAME,         //ウィンドウクラス名 上のクラス名と同じ
        APP_GAME,     //タイトルバーに表示する内容
        WS_OVERLAPPEDWINDOW, //スタイル（普通のウィンドウ）
        CW_USEDEFAULT,       //表示位置左（おまかせ）
        CW_USEDEFAULT,       //表示位置上（おまかせ）
        winW,                 //ウィンドウ幅
        winH,                 //ウィンドウ高さ
        NULL,                //親ウインドウ（なし）
        NULL,                //メニュー（なし）
        hInstance,           //インスタンス
        NULL                 //パラメータ（なし）
    );

  //ウィンドウを表示
    ShowWindow(hWnd, nCmdShow);

    //Direct3D初期化
    HRESULT hr =  Direct3D::Initialize(winW, winH, hWnd);
    if (FAILED(hr))
    {
        return 0;
    }

    Camera::Initialize();

    pRootJob = new RootJob;
    pRootJob->Initialize();

  //メッセージループ（何か起きるのを待つ）
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        //メッセージあり
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        //メッセージなし
        else
        {
            //カメラの更新
            Camera::Update();
            //ルートジョブからつながるすべてのオブジェクトをUPDATEする
            pRootJob->Update();

            //ゲームの処理　描画開始処理
            Direct3D::BeginDraw();
            
            //ルートジョブからつながるすべてのオブジェクトをDRAWする
         //   pRootJob->Draw();

            //ゲームの内容を書いていく

            //描画終了処理
            Direct3D::EndDraw();
            
        }
    }
    pRootJob->Release();
    Direct3D::Release();
	return 0;
}

//ウィンドウプロシージャ（何かあった時によばれる関数）
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY://ウィンドウが閉じられたら（イベント）
        PostQuitMessage(0);  //プログラム終了
        return 0;
        //WM_CLOSE Xボタン
        //WM_
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}