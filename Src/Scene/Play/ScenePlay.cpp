#pragma once
#include "ScenePlay.h"

//=============================
// �v���C�V�[��
//=============================

//������
void PLAY::Init()
{


	//�v���C���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//���[�h
void PLAY::Load()
{
	
}

//�ʏ폈��
void PLAY::Step()
{	

	//�V�[���ւ̑J��
	//�G���^�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//�V�[���t���O�����U���g�V�[���ɕύX
		m_SceneFlag = 0;
		//�v���C�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}
	//===============================================================
}

//�`�揈��
void PLAY::Draw()
{
	
}

//�㏈��
void PLAY::Fin()
{
	
	//SceneFlag��0�̎�
	if (m_SceneFlag == 0)
	{
		//�v���CINIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_RESULT;
	}
}
