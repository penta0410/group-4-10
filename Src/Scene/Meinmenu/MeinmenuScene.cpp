#include "DxLib.h"
#include "MeinmenuScene.h"
#include "../Scene.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"

//=============================
// ���C�����j���[�V�[��
//=============================

//������
void MEIN_MENU::Init()
{

	//���C�����j���[���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_MEIN_MENU;
}

//���[�h
void MEIN_MENU::Load()
{

}

//�ʏ폈��
void MEIN_MENU::Step()
{

	//�v���C�V�[���ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//�V�[���t���O���v���C�V�[���ɕύX
		m_SceneFlag = 0;
		//�^�C�g���㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_MEIN_MENU;
	}
}

//�`�揈��
void MEIN_MENU::Draw()
{

	//�f�o�b�O
	SetFontSize(30);
	DrawFormatString(100, 100, GetColor(255, 255, 255), "���C�����j���[�V�[���ł��B", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "enter�Ńv���C�V�[��", true);
	SetFontSize(16);
}

//�㏈��
void MEIN_MENU::Fin()
{

	//SceneFlag��0�̎�
	if (m_SceneFlag == 0)
	{
		//�v���CINIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
}
