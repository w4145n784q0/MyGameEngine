//インクルード
#include <Windows.h>
#include"Direct3D.h"
#include<tchar.h>
#include"Quad.h"
#include"Camera.h"
#include"Dice.h"
#include "Sprite.h"
namespace{
//定数宣言
const wchar_t* WIN_CLASS_NAME = L"SampleGame";//ウィンドウクラス名
const wchar_t* APP_GAME = L"サンプルゲーム";//アプリケーション名
const int WINDOW_WIDTH = 800;//ウィンドウ幅
const int WINDOW_HEIGHT = 600;//ウィンドウの高さ
}

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

   /* Quad* qu = new Quad;
    qu->Initialize();*/

    /*Dice* di = new Dice();
    di->Initialize();*/

    std::string textureData("Asset\\Dice.png");
    Sprite* pSprite;
    pSprite = new Sprite();
    hr = pSprite->Load(textureData);

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
            //ゲームの処理
            Direct3D::BeginDraw();
           // XMMATRIX mat = XMMatrixIdentity();
            XMMATRIX mat = XMMatrixScaling(1 / 2.0f, 1 / 2.0f, 1.0f);
            pSprite->Draw(mat);

            //回転
            //static float rot = 0.0;
            //rot += 0.001;
            ////角度をラジアンにするなら XMConvertToRadians
            ////ラジアンを角度にするならXMCOnvertToDegrees
            //XMMATRIX rmat = XMMatrixRotationX(rot);
            //rmat = rmat * XMMatrixRotationY(XMConvertToRadians(45.0));
            //
            //static float factor = 0.0;
            //factor += 0.001;
            //float scale = 1.5 + sin(factor);
            ////XMMATRIX smat = XMMatrixScaling(scale, scale, scale);
           // XMMATRIX tmat = XMMatrixTranslation(2.0 * sin(factor), 0, 0);
          //  XMMATRIX mat = smat * rmat * tmat;

           // XMMATRIX tmat = XMMatrixTranslation(3.0*cos(factor), 1.5*sin(factor), 0.0f);
            //単位行列　数字の1と同じ
         //   XMMATRIX mat = XMMatrixIdentity();
            //mat = rmat /** tmat*/;
            ////qu->Draw(mat);
            //di->Draw(mat);

            //描画処理
            
        }
    }

  //  SAFE_DELETE(qu);
    //SAFE_DELETE(di);
    SAFE_DELETE(pSprite);
    Direct3D::Release();
	return 0;
}

//ウィンドウプロシージャ（何かあった時によばれる関数）
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);  //プログラム終了
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}