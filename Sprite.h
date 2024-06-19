#pragma once
#include"Direct3D.h"
#include <DirectXMath.h>
#include"Texture.h"
#include<vector>

using std::vector;
using namespace DirectX;

//コンスタントバッファー:アプリ側からシェーダに毎フレーム渡したい情報

struct CONSTANT_BUFFER
{
	XMMATRIX    matW;
};

//頂点情報
struct VERTEX
{
	XMVECTOR position;
	XMVECTOR uv;
};

class Sprite
{
	uint64_t vertecNum_;            //頂点数
	vector<VERTEX> vertices_;        //頂点情報
	uint64_t indexNum_;             //インデックス数
	vector<int> indces_;            //インデックス情報

	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_;    //インデックスバッファ
	ID3D11Buffer* pConstantBuffer_;	//コンスタントバッファ

	Texture* pTexture_;				//textureへのポインタ
public:
	Sprite();
	 ~Sprite();
	 HRESULT Initialize();//初期化　コンストラクタでできないやつはこっちで初期化
	 void Draw(XMMATRIX& worldMatrix);//描画
	 void Release();//解放
private:
	//-----------------initializeから呼ばれる関数-----------------
	void  InitVertexData();//頂点情報の準備
	HRESULT CreateVertexBuffer();

	void InitIndexData();
	HRESULT CreateIndexBuffer();
	HRESULT CreateConstantBuffer();
	HRESULT LoadTexture();

	//-----------------Drawから呼ばれる関数-----------------
	void PassDataToCB(DirectX::XMMATRIX& worldMatrix);
	void SetBufferToPipeline();
};

