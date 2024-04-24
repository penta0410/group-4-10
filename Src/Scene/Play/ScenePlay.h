#pragma once
#include <math.h>
#include "DxLib.h"
#include "../../Collision/Collision.h"
#include "../../Common.h"
#include "../../Input/Input.h"
#include "../Scene.h"
#include "../../Map/Map.h"

//プレイシーン画像枚数
const int PLAY_IMAGE_PATH_NUM = 4;

//プレイシーン画像パス
const char PLAY_PATH[PLAY_IMAGE_PATH_NUM][256] =
{
	

};

//プレイシーンクラス
class Play : public Scene_Base
{
private:

	////画像ハンドル
	//int m_ImageHandle[PLAY_IMAGE_PATH_NUM];

	////背景座標
	//int m_BG_x[2];
	//int m_BG_y;
	//
	////背景移動量
	//int m_BG_move_x;

public:

	Map c_map;		//マップクラス宣言

	//初期化
	void Init() override;
	//ロード
	void Load() override;
	//通常処理
	void Step()	override;
	//描画処理
	void Draw() override;
	//後処理
	void Fin() override;
	
};

