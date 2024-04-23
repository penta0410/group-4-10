#pragma once

//�V�[���x�[�X�N���X
class SCENE_BASE
{
protected:

	//�V�[���t���O
	int m_SceneFlag;
	//�V�[���t���[��
	int m_SceneFlame;
	
public:

	//������
	void virtual Init();
	//�f�[�^���[�h
	void virtual Load();
	//�ʏ폈��
	void virtual Step();
	//�`�揈��
	void virtual Draw();
	//�㏈��
	void virtual Fin();

};

enum SCENE_ID
{
	//�^�C�g���֘A
	SCENE_ID_INIT_TITLE = 100,
	SCENE_ID_LOOP_TITLE,
	SCENE_ID_FIN_TITLE,

	//���C�����j���[�֘A
	SCENE_ID_INIT_MEIN_MENU = 200,
	SCENE_ID_LOOP_MEIN_MENU,
	SCENE_ID_FIN_MEIN_MENU,

	//�v���C�֘A
	SCENE_ID_INIT_PLAY = 300,
	SCENE_ID_LOOP_PLAY,
	SCENE_ID_FIN_PLAY,

	//���U���g�֘A
	SCENE_ID_INIT_RESULT = 400,
	SCENE_ID_LOOP_RESULT,
	SCENE_ID_FIN_RESULT,

};
//���݂̃V�[��ID
extern int g_CurrentSceneID;

