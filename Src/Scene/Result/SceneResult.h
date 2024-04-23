#pragma once
#include "../Scene.h"
#include "../../Player/Player.h"
#include "../../Transparent/Transparent.h"

const int SCORE_NUMBER_MAX_NUM = 13;

//���U���g�N���X
class RESULT : public SCENE_BASE
{
private:
	//�N���X�錾
	Player player;




public:

	//������
	void Init(int m_score);
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