#pragma once

//シーンベースクラス
class Scene_Base
{
protected:

public:

	//初期化
	void virtual Init() {};
	//データロード
	void virtual Load() {};
	//通常処理
	void virtual Step() {};
	//描画処理
	void virtual Draw() {};
	//後処理
	void virtual Fin() {};

};

//シーン種類
enum class SCENE_ID
{
	SCENE_ID_TITLE = 100,	//タイトル

	SCENE_ID_PLAY = 200,	//プレイ
	
	SCENE_ID_RESULT = 300,	//リザルト
};

//シーン状態
enum class SCENE_STATE_ID
{
	
	SCENE_ID_INIT = 100,
	
	SCENE_ID_LOOP,

	SCENE_ID_FIN,
	
};

