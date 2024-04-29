#pragma once
#include "../../Transparent/Transparent.h"
#include "../Scene.h"

const char RESULT_PATH[] = { "Data/Result/Result.png" };
const char RESULTSTCLEAR_PATH[] = { "Data/Result/STClear.png" };

//リザルトクラス
class Result : public Scene_Base
{
private:
	enum RESULTHUNDLE {
		RESULTHUNDLE_RESULT,	// リザルト
		RESULTHUNDLE_STCLEAR,	// ステージクリア

		RESULTHUNDLE_NUM,
	};

	int _hundle[RESULTHUNDLE_NUM];

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