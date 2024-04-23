#include "SceneResult.h"
#include "DxLib.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"

//初期化
void RESULT::Init(int m_score)
{
	
	//リザルトループへ
	g_CurrentSceneID = SCENE_ID_LOOP_RESULT;
}
//ロード
void RESULT::Load()
{


}

//通常処理
void RESULT::Step()
{


	//タイトルシーンへの遷移
	if (IsKeyPush(KEY_INPUT_RETURN)) {
		//シーンフラグをタイトルシーンに変更
		m_SceneFlag = 0;
		//リザルト後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_RESULT;
	}

}

//描画処理
void RESULT::Draw()
{
	

}

//後処理
void RESULT::Fin()
{

	//SceneFlagが0の時
	if (m_SceneFlag == 0)
	{
		//プレイINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}
}