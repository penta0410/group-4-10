#include "SceneResult.h"
#include "DxLib.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"
#include "../SceneManager/SceneManager.h"

//������
void Result::Init()
{
	
	
}
//���[�h
void Result::Load()
{


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
	SetFontSize(30);
	DrawFormatString(100, 100, GetColor(255, 255, 255), "���U���g�ł�", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "�^�C�g���֍s���ɂ̓G���^�[�������Ă�������", true);
	SetFontSize(16);
}

//�㏈��
void Result::Fin()
{

	
	//�^�C�g���ֈړ�
	SceneManager::g_CurrentSceneID = SCENE_ID::SCENE_ID_TITLE;
	
}