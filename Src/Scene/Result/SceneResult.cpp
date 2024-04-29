#include "SceneResult.h"
#include "DxLib.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"
#include "../SceneManager/SceneManager.h"
#include "../../Sound/Sound.h"

//������
void Result::Init()
{
	for (int i = 0; i < RESULTHUNDLE_NUM; i++) {
		_hundle[i] = 0;
	}
	Alpha = 255;
	isAlphaPlus = false;
	PlayerXpos = -64;
	PlayerYpos = 600.0f;
	PlayerYspeed = 0.0f;
	PlayerRot = 0.0f;

	Sound::Bgm::Play(BGM_RESULT);
}
//���[�h
void Result::Load()
{
	_hundle[RESULTHUNDLE_RESULT] = LoadGraph(RESULT_PATH);
	_hundle[RESULTHUNDLE_STCLEAR] = LoadGraph(RESULTSTCLEAR_PATH);
	_hundle[RESULTHUNDLE_P2ENTER] = LoadGraph(RESULTP2ENTER_PATH);
	_hundle[RESULTHUNDLE_PLAYER] = LoadGraph(RESULTPLAYER_PATH);

}

//�ʏ폈��
void Result::Step()
{

	if (isAlphaPlus) {
		Alpha += 3;
	}
	else {
		Alpha -= 3;
	}

	if (Alpha > 255) {
		Alpha = 255;
		isAlphaPlus = false;

	}

	if (Alpha < 100) {
		Alpha = 100;
		isAlphaPlus = true;
	}

	PlayerYspeed += 2.0f;
	PlayerYpos += PlayerYspeed;

	PlayerRot += 10.0f;
	PlayerXpos += 8;
	if (PlayerXpos > 1280 + 64) {
		PlayerXpos = -64;
	}
	if (PlayerYpos > 720 - 64) {
		PlayerYspeed = -40.0f;
		PlayerYpos = 720 - 64;
	}
	//�^�C�g���V�[���ւ̑J��
	if (IsKeyPush(KEY_INPUT_RETURN)) {

		//�㏈���ֈړ�
		SceneManager::g_CurrentSceneStateID = SCENE_STATE_ID::SCENE_ID_FIN;
	}

}

//�`�揈��
void Result::Draw()
{
	//���U���g
	DrawGraph(0, 0, _hundle[RESULTHUNDLE_RESULT], true);
	DrawGraph(0, 100, _hundle[RESULTHUNDLE_STCLEAR], true);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Alpha);
	DrawGraph(0, 500, _hundle[RESULTHUNDLE_P2ENTER], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawRotaGraph(PlayerXpos, (int)PlayerYpos, 1.0f, PlayerRot / 180.0f * DX_PI_F, _hundle[RESULTHUNDLE_PLAYER], true);


	//SetFontSize(30);
	//DrawFormatString(100, 100, GetColor(255, 255, 255), "���U���g�ł�", true);
	//DrawFormatString(100, 200, GetColor(255, 255, 255), "�^�C�g���֍s���ɂ̓G���^�[�������Ă�������", true);
	//SetFontSize(16);
}

//�㏈��
void Result::Fin()
{
	Sound::Bgm::StopSound(BGM_RESULT);

	//�^�C�g���ֈړ�
	SceneManager::g_CurrentSceneID = SCENE_ID::SCENE_ID_TITLE;

}