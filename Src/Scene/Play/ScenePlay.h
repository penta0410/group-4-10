#pragma once
#include <math.h>
#include "DxLib.h"
#include "../../Collision/Collision.h"
#include "../../Common.h"
#include "../../Input/Input.h"
#include "../Scene.h"
#include "../../Map/Map.h"
#include "../../Common.h"
#include "../../Player/Player.h"

//プレイシーン画像枚数
const int PLAY_IMAGE_PATH_NUM = 4;

//背景移動スピード
const int BG_MOVE_SPEED = 1;

//プレイシーン画像パス
const char PLAY_PATH[PLAY_IMAGE_PATH_NUM][256] =
{
	"Data/Play/BackGround.png",		//背景
	"Data/Play/BackGround2.png",	//背景２

};



//プレイシーンクラス
class Play : public Scene_Base
{
private:

	//画像ハンドル
	int m_ImageHandle[PLAY_IMAGE_PATH_NUM];

	//背景座標
	int m_BG_x[2];
	int m_BG_y;
	
	//背景移動量
	int m_BG_move_x;

	//マップムーブ
	int mapmove;

	//クリアフラグ
	bool IsClear;

public:

	Map c_map;				//マップクラス宣言
	Player c_player;		//プレイヤークラス宣言


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
	
	// マップの当たり判定
	void MapCollision();

	//背景スクロール処理
	int BGScroll(int move_speed);

	//クリアしたかどうか
	bool IsClear() { return IsClear; };

};

