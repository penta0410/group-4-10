#include "SceneTitle.h"
#include "../SceneManager/SceneManager.h"
#include "../../Sound/Sound.h"
#include "../../Transparent/Transparent.h"

//=============================
// タイトルシーン
//=============================

//初期化
void Title::Init()
{
	for (int i = 0; i < TITLEHUNDLE_NUM; i++) {
		_hundle[i] = 0;
		Alpha[i] = 255;
		isAlphaPlus[i] = false;
	}
	PlayerRot = 0.0f;
	PlayerXpos = -64;

	Sound::Bgm::Play(BGM_TITLE);
}

//ロード
void Title::Load()
{
	_hundle[TITLEHUNDLE_TITLE] = LoadGraph(TITLE_PATH);
	_hundle[TITLEHUNDLE_TITLEROGO] = LoadGraph(TITLEROGO_PATH);

	_hundle[TITLEHUNDLE_P2ENTER] = LoadGraph(TITLEP2ENTER_PATH);
	_hundle[TITLEHUNDLE_PLAYER] = LoadGraph(TITLEPLAYER_PATH);

}

//通常処理
void Title::Step()
{
	for (int i = 0; i < TITLEHUNDLE_NUM; i++) {
		if (isAlphaPlus[i]) {
			Alpha[i] += 3;
		}
		else {
			Alpha[i] -= 3;
		}

		if (Alpha[i] > 255) {
			Alpha[i] = 255;
			isAlphaPlus[i] = false;

		}

		if (Alpha[i] < ALPHA_MIN[i]){
			Alpha[i] = ALPHA_MIN[i];
			isAlphaPlus[i] = true;
		}

	}

	PlayerXpos += 5;
	PlayerRot += 2.0f;
	if (PlayerXpos > 1280+64) {
		PlayerXpos = -64;
	}
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
	DrawGraph(0, 0, _hundle[TITLEHUNDLE_TITLE], true);

	DrawGraph(0, 0, _hundle[TITLEHUNDLE_TITLEROGO], true);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Alpha[TITLEHUNDLE_P2ENTER]);
	DrawGraph(0, 500, _hundle[TITLEHUNDLE_P2ENTER], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawRotaGraph(PlayerXpos, 300, 1.0f, PlayerRot / 180.0f * DX_PI_F, _hundle[TITLEHUNDLE_PLAYER], true);

	//SetFontSize(30);
	//DrawFormatString(100, 100, GetColor(255, 255, 255), "タイトルです", true);
	//DrawFormatString(100, 200, GetColor(255, 255, 255), "プレイへ行くにはエンターを押してください", true);
	//SetFontSize(16);
}

//消去処理
void Title::Fin()
{
	for (int i = 0; i < TITLEHUNDLE_NUM; i++) {
		DeleteGraph(_hundle[i]);
	}
	Sound::Bgm::StopSound(BGM_TITLE);

	//プレイへ移動
	SceneManager::g_CurrentSceneID = SCENE_ID::SCENE_ID_PLAY;
}

