#pragma once
#include "../../Transparent/Transparent.h"
#include "../Scene.h"


//リザルトクラス
class Result : public Scene_Base
{
private:
	




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