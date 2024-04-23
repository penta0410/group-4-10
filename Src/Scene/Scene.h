#pragma once

//�V�[���x�[�X�N���X
class Scene_Base
{
protected:

public:

	//������
	void virtual Init() {};
	//�f�[�^���[�h
	void virtual Load() {};
	//�ʏ폈��
	void virtual Step() {};
	//�`�揈��
	void virtual Draw() {};
	//�㏈��
	void virtual Fin() {};

};

//�V�[�����
enum class SCENE_ID
{
	SCENE_ID_TITLE = 100,	//�^�C�g��

	SCENE_ID_PLAY = 200,	//�v���C
	
	SCENE_ID_RESULT = 300,	//���U���g
};

//�V�[�����
enum class SCENE_STATE_ID
{
	
	SCENE_ID_INIT = 100,
	
	SCENE_ID_LOOP,

	SCENE_ID_FIN,
	
};

