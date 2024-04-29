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

	Sound::Bgm::Play(BGM_TITLE);
}
//���[�h
void Result::Load()
{
	_hundle[RESULTHUNDLE_RESULT] = LoadGraph(RESULT_PATH);
	_hundle[RESULTHUNDLE_STCLEAR] = LoadGraph(RESULTSTCLEAR_PATH);
}

//�ʏ폈��
void Result::Step()
{


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
	DrawGraph(0, 200, _hundle[RESULTHUNDLE_STCLEAR], true);

	//SetFontSize(30);
	//DrawFormatString(100, 100, GetColor(255, 255, 255), "���U���g�ł�", true);
	//DrawFormatString(100, 200, GetColor(255, 255, 255), "�^�C�g���֍s���ɂ̓G���^�[�������Ă�������", true);
	//SetFontSize(16);
}

//�㏈��
void Result::Fin()
{

	StopSound();
	Sound::Bgm::StopSound(BGM_TITLE);

	//�^�C�g���ֈړ�
	SceneManager::g_CurrentSceneID = SCENE_ID::SCENE_ID_TITLE;

}