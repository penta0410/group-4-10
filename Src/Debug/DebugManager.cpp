#include "DxLib.h"
#include "DebugManager.h"

//�R���X�g���N�^
DebugManager::DebugManager()
{

}

//�f�X�g���N�^
DebugManager::~DebugManager()
{

}

//������
void DebugManager::Init()
{
	//�f�o�b�O�t���O
	m_DebugFlag = false;
}

//�`�揈��
void DebugManager::Draw()
{
	switch (SceneManager::g_CurrentSceneID)
	{
	case SCENE_ID::SCENE_ID_TITLE:
	{
		//�^�C�g��
		SetFontSize(30);
		DrawFormatString(100, 100, GetColor(255, 255, 255), "�^�C�g���ł�", true);
		DrawFormatString(100, 200, GetColor(255, 255, 255), "�v���C�֍s���ɂ̓G���^�[�������Ă�������", true);
		SetFontSize(16);
	}
	break;
	//�V�[��ID���v���C�̎�
	case SCENE_ID::SCENE_ID_PLAY:
	{
		//�v���C
		SetFontSize(30);
		DrawFormatString(100, 100, GetColor(255, 255, 255), "�v���C�ł�", true);
		DrawFormatString(100, 200, GetColor(255, 255, 255), "���U���g�֍s���ɂ̓G���^�[�������Ă�������", true);
		SetFontSize(16);
	}
	break;
	//�V�[��ID�����U���g�̎�
	case SCENE_ID::SCENE_ID_RESULT:
	{
		//���U���g
		SetFontSize(30);
		DrawFormatString(100, 100, GetColor(255, 255, 255), "���U���g�ł�", true);
		DrawFormatString(100, 200, GetColor(255, 255, 255), "�^�C�g���֍s���ɂ̓G���^�[�������Ă�������", true);
		SetFontSize(16);
	}
	break;
	}

}

//�ʏ폈��
void DebugManager::Step()
{

}