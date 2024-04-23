#pragma once
#include "../Scene.h"
#include "../../Player/Player.h"
#include "../../Transparent/Transparent.h"

const int SCORE_NUMBER_MAX_NUM = 13;

//リザルトクラス
class RESULT : public SCENE_BASE
{
private:
	//クラス宣言
	Player player;




public:

	//初期化
	void Init(int m_score);
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