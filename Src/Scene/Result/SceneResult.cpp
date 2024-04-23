#include "SceneResult.h"
#include "DxLib.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"
#include "../SceneManager/SceneManager.h"

//初期化
void Result::Init()
{
	
	
}
//ロード
void Result::Load()
{


}

//通常処理
void Result::Step()
{


	//タイトルシーンへの遷移
	if (IsKeyPush(KEY_INPUT_RETURN)) {
		
		//後処理へ移動
		SceneManager::g_CurrentSceneStateID = SCENE_STATE_ID::SCENE_ID_FIN;
	}

}

//描画処理
void Result::Draw()
{
	//リザルト
	SetFontSize(30);
	DrawFormatString(100, 100, GetColor(255, 255, 255), "リザルトです", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "タイトルへ行くにはエンターを押してください", true);
	SetFontSize(16);
}

//後処理
void Result::Fin()
{

	
	//タイトルへ移動
	SceneManager::g_CurrentSceneID = SCENE_ID::SCENE_ID_TITLE;
	
}