#pragma once
#include "../Scene.h"
#include "../../Debug/DebugManager.h"

//シーンマネージャークラス
class SceneManager
{
private:
	Scene_Base* scene_state;	
public:
	static SCENE_STATE_ID g_CurrentSceneStateID;	//現在のシーンID
	static SCENE_ID g_CurrentSceneID;		//シーン種類


	//コンストラクタ・デストラクタ
	SceneManager();
	~SceneManager();

	//シーン初期化
	void InitScene();

	//シーンループ処理
	void LoopScene();

	//シーン終了処理
	void FInScene();

};