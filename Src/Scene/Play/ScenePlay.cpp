#pragma once
#include "ScenePlay.h"
#include "../SceneManager/SceneManager.h"

//=============================
// プレイシーン
//=============================

//初期化
void Play::Init()
{
	c_map.Init();
	
}

//ロード
void Play::Load()
{
	
}

//通常処理
void Play::Step()
{	
	c_map.Step();

	//シーンへの遷移
	//エンター押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		
		//後処理へ移動
		SceneManager::g_CurrentSceneStateID = SCENE_STATE_ID::SCENE_ID_FIN;
	}
	
}

//描画処理
void Play::Draw()
{
	c_map.Draw();

	//プレイ
	SetFontSize(30);
	DrawFormatString(100, 100, GetColor(255, 255, 255), "プレイです", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "リザルトへ行くにはエンターを押してください", true);
	SetFontSize(16);
}

//後処理
void Play::Fin()
{
	
	//リザルトへ移動
	SceneManager::g_CurrentSceneID = SCENE_ID::SCENE_ID_RESULT;
}
