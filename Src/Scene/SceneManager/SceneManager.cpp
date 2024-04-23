#include "SceneManager.h"
#include "../Title/SceneTitle.h"
#include "../Play/ScenePlay.h"
#include "../Result/SceneResult.h"


SCENE_STATE_ID SceneManager::SceneManager::g_CurrentSceneStateID;	
SCENE_ID SceneManager::SceneManager::g_CurrentSceneID;	

//コンストラクタ
SceneManager::SceneManager()
{
	scene_state = nullptr;		//空にする
}

//デストラクタ
SceneManager::~SceneManager()
{

}

//シーン初期化
void SceneManager::InitScene()
{
	SceneManager::g_CurrentSceneStateID = SCENE_STATE_ID::SCENE_ID_INIT;	//最初初期化
	SceneManager::g_CurrentSceneID = SCENE_ID::SCENE_ID_TITLE;		//最初タイトル

	scene_state = nullptr;		//空にする
}

//シーンループ処理
void SceneManager::LoopScene()
{
	//シーン状態によるシーン遷移
	switch (SceneManager::g_CurrentSceneStateID)
	{
	case SCENE_STATE_ID::SCENE_ID_INIT:
	{
		//シーン種類によるシーン確保
		switch (SceneManager::g_CurrentSceneID)
		{
		//シーンIDがタイトルの時
		case SCENE_ID::SCENE_ID_TITLE:
		{
			scene_state = new Title;		//タイトルで確保
		}
		break;
		//シーンIDがプレイの時
		case SCENE_ID::SCENE_ID_PLAY:
		{
			scene_state = new Play;			//プレイで確保
		}
		break;
		//シーンIDがリザルトの時
		case SCENE_ID::SCENE_ID_RESULT:
		{
			scene_state = new Result;		//リザルトで確保
		}
		break;
		//======シーン数を増やしたら順次増やす必要がある===============================
		
		}

		//初期化処理
		scene_state->Init();
		//読み込み処理
		scene_state->Load();

	}
	break;
	case SCENE_STATE_ID::SCENE_ID_LOOP:
	{
		//通常処理
		scene_state->Step();
		//描画処理
		scene_state->Draw();
	}
	break;
	case SCENE_STATE_ID::SCENE_ID_FIN:
	{
		//終了処理
		scene_state->Fin();
	}
	break;
	}
}

//シーン終了処理
void SceneManager::FInScene()
{
	//シーンが空じゃなかったら今まで動作していたシーンをデリート
	if (scene_state != nullptr)
		delete scene_state;
}