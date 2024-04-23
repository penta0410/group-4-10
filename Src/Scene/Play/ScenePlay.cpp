#pragma once
#include "ScenePlay.h"
#include "../SceneManager/SceneManager.h"

//=============================
// �v���C�V�[��
//=============================

//������
void Play::Init()
{

	//���[�v��
	SceneManager::g_CurrentSceneStateID = SCENE_STATE_ID::SCENE_ID_LOOP;
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
	//�f�o�b�O
	SetFontSize(30);
	DrawFormatString(100, 100, GetColor(255, 255, 255), "�v���C�ł�", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "aa���U���g�֍s���ɂ̓G���^�[�������Ă�������", true);
	SetFontSize(16);
}

//�㏈��
void Play::Fin()
{

	//INIT�ֈړ�
	SceneManager::g_CurrentSceneStateID = SCENE_STATE_ID::SCENE_ID_INIT;
	//���U���g�ֈړ�
	SceneManager::g_CurrentSceneID = SCENE_ID::SCENE_ID_RESULT;
}
