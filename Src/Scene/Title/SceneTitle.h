#pragma once
#include "DxLib.h"
#include "../../Input/Input.h"
#include "../../Transparent/Transparent.h"
#include "../../Collision/Collision.h"
#include "../Scene.h"

const char TITLE_PATH[] = { "Data/Play/Title.png" };
const char TITLEROGO_PATH[] = { "Data/Play/TitleRogo.png" };
const char TITLEP2ENTER_PATH[] = { "Data/Play/P2Enter.png" };

//タイトルクラス
class Title : public Scene_Base
{
private:
	enum TITLEHUNDLE {
		TITLEHUNDLE_TITLE,	// タイトル
		TITLEHUNDLE_TITLEROGO,	// タイトルロゴ
		TITLEHUNDLE_P2ENTER,	// プレス2エンター

		TITLEHUNDLE_NUM,
	};

	int _hundle[TITLEHUNDLE_NUM];
	

public:

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

