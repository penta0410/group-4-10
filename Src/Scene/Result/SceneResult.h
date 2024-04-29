#pragma once
#include "../../Transparent/Transparent.h"
#include "../Scene.h"

const char RESULT_PATH[] = { "Data/Result/Result.png" };
const char RESULTSTCLEAR_PATH[] = { "Data/Result/STClear.png" };
const char RESULTP2ENTER_PATH[] = { "Data/Play/P2Enter.png" };
const char RESULTPLAYER_PATH[] = { "Data/Result/ResultPlayer.png" };

//���U���g�N���X
class Result : public Scene_Base
{
private:
	enum RESULTHUNDLE {
		RESULTHUNDLE_RESULT,	// ���U���g
		RESULTHUNDLE_STCLEAR,	// �X�e�[�W�N���A
		RESULTHUNDLE_P2ENTER,	// �v���X2�G���^�[
		RESULTHUNDLE_PLAYER,	// �v���C���[

		RESULTHUNDLE_NUM,
	};

	int _hundle[RESULTHUNDLE_NUM];
	int Alpha;
	bool isAlphaPlus;
	int PlayerXpos;
	float PlayerYpos,PlayerYspeed,PlayerRot;
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