#include "SceneTitle.h"

//=============================
// タイトルシーン
//=============================

//初期化
void TITLE::Init()
{
	

	//タイトルループへ
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

//ロード
void TITLE::Load()
{


}

void TITLE::Sound()
{
	
}

//通常処理
void TITLE::Step()
{
	
	//メインメニューシーンへの遷移
	//Enterキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//シーンフラグをプレイシーンに変更
		m_SceneFlag = 0;
		//タイトル後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}

}

//描画処理
void TITLE::Draw()
{
	
}

//消去処理
void TITLE::Fin()
{
	
	//SceneFlagが0の時
	if (m_SceneFlag == 0)
	{
		//INITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
}

