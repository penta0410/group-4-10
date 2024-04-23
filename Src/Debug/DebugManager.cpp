#include "DxLib.h"
#include "DebugManager.h"

//コンストラクタ
DebugManager::DebugManager()
{

}

//デストラクタ
DebugManager::~DebugManager()
{

}

//初期化
void DebugManager::Init()
{
	//デバッグフラグ
	m_DebugFlag = false;
}

//描画処理
void DebugManager::Draw()
{
	switch (SceneManager::g_CurrentSceneID)
	{
	case SCENE_ID::SCENE_ID_TITLE:
	{
		//タイトル
		SetFontSize(30);
		DrawFormatString(100, 100, GetColor(255, 255, 255), "タイトルです", true);
		DrawFormatString(100, 200, GetColor(255, 255, 255), "プレイへ行くにはエンターを押してください", true);
		SetFontSize(16);
	}
	break;
	//シーンIDがプレイの時
	case SCENE_ID::SCENE_ID_PLAY:
	{
		//プレイ
		SetFontSize(30);
		DrawFormatString(100, 100, GetColor(255, 255, 255), "プレイです", true);
		DrawFormatString(100, 200, GetColor(255, 255, 255), "リザルトへ行くにはエンターを押してください", true);
		SetFontSize(16);
	}
	break;
	//シーンIDがリザルトの時
	case SCENE_ID::SCENE_ID_RESULT:
	{
		//リザルト
		SetFontSize(30);
		DrawFormatString(100, 100, GetColor(255, 255, 255), "リザルトです", true);
		DrawFormatString(100, 200, GetColor(255, 255, 255), "タイトルへ行くにはエンターを押してください", true);
		SetFontSize(16);
	}
	break;
	}

}

//通常処理
void DebugManager::Step()
{

}