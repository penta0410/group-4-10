#pragma once
#include "DxLib.h"
#include "../Scene.h"
#include "../../Input/Input.h"
#include "../../Transparent/Transparent.h"
#include "../../Collision/Collision.h"


//タイトルクラス
class TITLE : public SCENE_BASE 
{
private:
	
	

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

