#pragma once
#include "../../Transparent/Transparent.h"
#include "../Scene.h"

const char RESULT_PATH[] = { "Data/Result/Result.png" };
const char RESULTSTCLEAR_PATH[] = { "Data/Result/STClear.png" };

//���U���g�N���X
class Result : public Scene_Base
{
private:
	enum RESULTHUNDLE {
		RESULTHUNDLE_RESULT,	// ���U���g
		RESULTHUNDLE_STCLEAR,	// �X�e�[�W�N���A

		RESULTHUNDLE_NUM,
	};

	int _hundle[RESULTHUNDLE_NUM];

public:

	//������
	void Init() override;
	//���[�h
	void Load() override;
	//���y�𗬂�
	void Sound();
	//�ʏ폈��
	void Step()	override;
	//�`�揈��
	void Draw() override;
	//�㏈��
	void Fin() override;

};