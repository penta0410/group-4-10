#include "SceneTitle.h"
#include "../SceneManager/SceneManager.h"

//=============================
// �^�C�g���V�[��
//=============================

//������
void Title::Init()
{
	

	//���[�v��
	SceneManager::g_CurrentSceneStateID = SCENE_STATE_ID::SCENE_ID_LOOP;
}

//���[�h
void Title::Load()
{


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
	//�f�o�b�O
	SetFontSize(30);
	DrawFormatString(100, 100, GetColor(255, 255, 255), "�^�C�g���ł�", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "�v���C�֍s���ɂ̓G���^�[�������Ă�������", true);
	SetFontSize(16);
}

//��������
void Title::Fin()
{
	
	//INIT�ֈړ�
	SceneManager::g_CurrentSceneStateID = SCENE_STATE_ID::SCENE_ID_INIT;
	//�v���C�ֈړ�
	SceneManager::g_CurrentSceneID = SCENE_ID::SCENE_ID_PLAY;
}

