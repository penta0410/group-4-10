#include "SceneManager.h"
#include "../Title/SceneTitle.h"
#include "../Play/ScenePlay.h"
#include "../Result/SceneResult.h"


SCENE_STATE_ID SceneManager::SceneManager::g_CurrentSceneStateID;	
SCENE_ID SceneManager::SceneManager::g_CurrentSceneID;	

//�R���X�g���N�^
SceneManager::SceneManager()
{
	scene_state = nullptr;		//��ɂ���
}

//�f�X�g���N�^
SceneManager::~SceneManager()
{

}

//�V�[��������
void SceneManager::InitScene()
{
	SceneManager::g_CurrentSceneStateID = SCENE_STATE_ID::SCENE_ID_INIT;	//�ŏ�������
	SceneManager::g_CurrentSceneID = SCENE_ID::SCENE_ID_TITLE;		//�ŏ��^�C�g��

	scene_state = nullptr;		//��ɂ���
}

//�V�[�����[�v����
void SceneManager::LoopScene()
{
	//�V�[����Ԃɂ��V�[���J��
	switch (SceneManager::g_CurrentSceneStateID)
	{
	case SCENE_STATE_ID::SCENE_ID_INIT:
	{
		//�V�[����ނɂ��V�[���m��
		switch (SceneManager::g_CurrentSceneID)
		{
		//�V�[��ID���^�C�g���̎�
		case SCENE_ID::SCENE_ID_TITLE:
		{
			scene_state = new Title;		//�^�C�g���Ŋm��
		}
		break;
		//�V�[��ID���v���C�̎�
		case SCENE_ID::SCENE_ID_PLAY:
		{
			scene_state = new Play;			//�v���C�Ŋm��
		}
		break;
		//�V�[��ID�����U���g�̎�
		case SCENE_ID::SCENE_ID_RESULT:
		{
			scene_state = new Result;		//���U���g�Ŋm��
		}
		break;
		//======�V�[�����𑝂₵���珇�����₷�K�v������===============================
		
		}

		//����������
		scene_state->Init();
		//�ǂݍ��ݏ���
		scene_state->Load();

	}
	break;
	case SCENE_STATE_ID::SCENE_ID_LOOP:
	{
		//�ʏ폈��
		scene_state->Step();
		//�`�揈��
		scene_state->Draw();
	}
	break;
	case SCENE_STATE_ID::SCENE_ID_FIN:
	{
		//�I������
		scene_state->Fin();
	}
	break;
	}
}

//�V�[���I������
void SceneManager::FInScene()
{
	//�V�[�����󂶂�Ȃ������獡�܂œ��삵�Ă����V�[�����f���[�g
	if (scene_state != nullptr)
		delete scene_state;
}