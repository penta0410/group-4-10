#include "SceneTitle.h"
#include "../SceneManager/SceneManager.h"

//=============================
// タイトルシーン
//=============================

//初期化
void Title::Init()
{
	

	//ループへ
	SceneManager::g_CurrentSceneStateID = SCENE_STATE_ID::SCENE_ID_LOOP;
}

//ロード
void Title::Load()
{


}

//通常処理
void Title::Step()
{
	
	//メインメニューシーンへの遷移
	//Enterキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		
		//後処理へ移動
		SceneManager::g_CurrentSceneStateID = SCENE_STATE_ID::SCENE_ID_FIN;
	}

}

//描画処理
void Title::Draw()
{
	//デバッグ
	SetFontSize(30);
	DrawFormatString(100, 100, GetColor(255, 255, 255), "タイトルです", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "プレイへ行くにはエンターを押してください", true);
	SetFontSize(16);
}

//消去処理
void Title::Fin()
{
	
	//INITへ移動
	SceneManager::g_CurrentSceneStateID = SCENE_STATE_ID::SCENE_ID_INIT;
	//プレイへ移動
	SceneManager::g_CurrentSceneID = SCENE_ID::SCENE_ID_PLAY;
}

