#pragma once
#include "../Scene/SceneManager/SceneManager.h"

//�f�o�b�O�}�l�[�W���[�N���X
class DebugManager
{
private:

	//�f�o�b�O�t���O
	bool m_DebugFlag;

public:

	
	//�R���X�g���N�^�E�f�X�g���N�^
	DebugManager();
	~DebugManager();

	//������
	void Init();

	//�`�揈��
	void Draw();

	//�ʏ폈��
	void Step();

};