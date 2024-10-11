#pragma once
#include<string>
#include"Engine/FBX.h"
#include"Engine/Transform.h"
using std::string;

namespace Model
{
	struct ModelData
	{
		FBX pFBX;
		Transform trans;
		string Filename;
	};
	//モデルの一覧を保存する配列vectorかlist

	int Load(std::string filename);

}

int Model::Load(std::string filename)
{
	//file名のモデルを読み込む
	//同じモデルがすでに読み込まれていたらエラー-1を返す
	//初めての読み込みだったらモデルを読み込んで配列に追加
}