#pragma once
#include "../../Transparent/Transparent.h"
#include "../Scene.h"


//���U���g�N���X
class Result : public Scene_Base
{
private:
	




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