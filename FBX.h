#pragma once
#include"Direct3D.h"
#include <DirectXMath.h>
#include"Texture.h"
#include<vector>
#include"Transform.h"
#include<filesystem>
#include"TextServ.h";

#include <d3d11.h>
#include <fbxsdk.h>
#include <string>
#include "Transform.h"

#pragma comment(lib, "LibFbxSDK-MD.lib")
#pragma comment(lib, "LibXml2-MD.lib")
#pragma comment(lib, "zlib-MD.lib")
//マルチデバッグがmtならMDのところをMTにする

class FBX
{
private:

		//マテリアル
	struct MATERIAL
	{
		Texture* pTexture;
	};

	struct VERTEX {
		XMMATRIX	matWVP;//ワールドビュープロジェクション
		XMMATRIX    matNormal;//法線ベクトルの変換用
	};

	//頂点情報
	struct VERTEX
	{
		XMVECTOR position;
		//XMVECTOR uv;
		//XMVECTOR normal;//法線ベクトル　ノーマル追加
	};

	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_; //インデックスバッファ
	ID3D11Buffer* pConstantBuffer_;	//コンスタントバッファ
	std::vector<MATERIAL>pMaterialBuffer;
	MATERIAL* pMaterialList_;

	int vertexCount_;	//頂点数
	int polygonCount_;	//ポリゴン数
	int materialCount_;	//マテリアルの個数
	void InitVertex(fbxsdk::FbxMesh* mesh);//頂点バッファ準備
	void InitIndex(fbxsdk::FbxMesh* mesh);//インデックスバッファ準備
	void InitConstantBuffer();//コンスタントバッファ準備
	void InitMaterial();
	
public:
	FBX();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    Release();
	void PassDataToCB(Transform& transform);
	void SetBufferToPipeline();
};

