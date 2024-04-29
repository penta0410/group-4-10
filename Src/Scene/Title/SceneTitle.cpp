#include "SceneTitle.h"
#include "../SceneManager/SceneManager.h"
#include "../../Sound/Sound.h"

//=============================
// �^�C�g���V�[��
//=============================

//������
void Title::Init()
{
	for (int i = 0; i < TITLEHUNDLE_NUM; i++) {
		_hundle[i] = 0;
	}
	Sound::Bgm::Play(BGM_TITLE);
}

//���[�h
void Title::Load()
{
	_hundle[TITLEHUNDLE_TITLE] = LoadGraph(TITLE_PATH);
	_hundle[TITLEHUNDLE_TITLEROGO] = LoadGraph(TITLEROGO_PATH);
	_hundle[TITLEHUNDLE_P2ENTER] = LoadGraph(TITLEP2ENTER_PATH);
	
}

//�ʏ폈��
void Title::Step()
{
	
	//���C�����j���[�V�[���ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{	
		//�㏈���ֈړ�
		SceneManager::g_CurrentSceneStateID = SCENE_STATE_ID::SCENE_ID_FIN;
	}

}

//�`�揈��
void Title::Draw()
{
	DrawGraph(0, 0, _hundle[TITLEHUNDLE_TITLE], true);
	DrawGraph(0, 0, _hundle[TITLEHUNDLE_TITLEROGO], true);
	DrawGraph(0, 500, _hundle[TITLEHUNDLE_P2ENTER], true);

	
	//SetFontSize(30);
	//DrawFormatString(100, 100, GetColor(255, 255, 255), "�^�C�g���ł�", true);
	//DrawFormatString(100, 200, GetColor(255, 255, 255), "�v���C�֍s���ɂ̓G���^�[�������Ă�������", true);
	//SetFontSize(16);
}

//��������
void Title::Fin()
{
	for (int i = 0; i < TITLEHUNDLE_NUM; i++) {
		DeleteGraph(_hundle[i]);
	}

	//�v���C�ֈړ�
	SceneManager::g_CurrentSceneID = SCENE_ID::SCENE_ID_PLAY;
}

