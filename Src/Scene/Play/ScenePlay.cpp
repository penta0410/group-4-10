#pragma once
#include "ScenePlay.h"

//=============================
// プレイシーン
//=============================

//初期化
void PLAY::Init()
{


	//プレイループへ
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//ロード
void PLAY::Load()
{
	
}

//通常処理
void PLAY::Step()
{	

	//シーンへの遷移
	//エンター押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//シーンフラグをリザルトシーンに変更
		m_SceneFlag = 0;
		//プレイ後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}
	//===============================================================
}

//描画処理
void PLAY::Draw()
{
	
}

//後処理
void PLAY::Fin()
{
	
	//SceneFlagが0の時
	if (m_SceneFlag == 0)
	{
		//プレイINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_RESULT;
	}
}
