#pragma once
#include "../../Transparent/Transparent.h"
#include "../Scene.h"

const char RESULT_PATH[] = { "Data/Result/Result.png" };
const char RESULTSTCLEAR_PATH[] = { "Data/Result/STClear.png" };
const char RESULTP2ENTER_PATH[] = { "Data/Play/P2Enter.png" };
const char RESULTPLAYER_PATH[] = { "Data/Result/ResultPlayer.png" };

//リザルトクラス
class Result : public Scene_Base
{
private:
	enum RESULTHUNDLE {
		RESULTHUNDLE_RESULT,	// リザルト
		RESULTHUNDLE_STCLEAR,	// ステージクリア
		RESULTHUNDLE_P2ENTER,	// プレス2エンター
		RESULTHUNDLE_PLAYER,	// プレイヤー

		RESULTHUNDLE_NUM,
	};

	int _hundle[RESULTHUNDLE_NUM];
	int Alpha;
	bool isAlphaPlus;
	int PlayerXpos;
	float PlayerYpos,PlayerYspeed,PlayerRot;
public:

	//初期化
	void Init() override;
	//ロード
	void Load() override;
	//音楽を流す
	void Sound();
	//通常処理
	void Step()	override;
	//描画処理
	void Draw() override;
	//後処理
	void Fin() override;

};