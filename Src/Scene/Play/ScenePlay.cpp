#pragma once
#include "ScenePlay.h"
#include "../SceneManager/SceneManager.h"

//=============================
// �v���C�V�[��
//=============================

//������
void Play::Init()
{

	
}

//���[�h
void Play::Load()
{
	
}

//�ʏ폈��
void Play::Step()
{	


	//�V�[���ւ̑J��
	//�G���^�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		
		//�㏈���ֈړ�
		SceneManager::g_CurrentSceneStateID = SCENE_STATE_ID::SCENE_ID_FIN;
	}
	
}

//�`�揈��
void Play::Draw()
{
	//�v���C
	SetFontSize(30);
	DrawFormatString(100, 100, GetColor(255, 255, 255), "�v���C�ł�", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "���U���g�֍s���ɂ̓G���^�[�������Ă�������", true);
	SetFontSize(16);
}

//�㏈��
void Play::Fin()
{

	//���U���g�ֈړ�
	SceneManager::g_CurrentSceneID = SCENE_ID::SCENE_ID_RESULT;
}
