#include "SceneTitle.h"

//=============================
// �^�C�g���V�[��
//=============================

//������
void TITLE::Init()
{
	

	//�^�C�g�����[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

//���[�h
void TITLE::Load()
{


}

void TITLE::Sound()
{
	
}

//�ʏ폈��
void TITLE::Step()
{
	
	//���C�����j���[�V�[���ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//�V�[���t���O���v���C�V�[���ɕύX
		m_SceneFlag = 0;
		//�^�C�g���㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}

}

//�`�揈��
void TITLE::Draw()
{
	
}

//��������
void TITLE::Fin()
{
	
	//SceneFlag��0�̎�
	if (m_SceneFlag == 0)
	{
		//INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
}

