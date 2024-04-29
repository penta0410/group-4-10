#pragma once
#include "DxLib.h"
#include "../../Input/Input.h"
#include "../../Transparent/Transparent.h"
#include "../../Collision/Collision.h"
#include "../Scene.h"

const char TITLE_PATH[] = { "Data/Play/Title.png" };
const char TITLEROGO_PATH[] = { "Data/Play/TitleRogo.png" };
const char TITLEP2ENTER_PATH[] = { "Data/Play/P2Enter.png" };

//�^�C�g���N���X
class Title : public Scene_Base
{
private:
	enum TITLEHUNDLE {
		TITLEHUNDLE_TITLE,	// �^�C�g��
		TITLEHUNDLE_TITLEROGO,	// �^�C�g�����S
		TITLEHUNDLE_P2ENTER,	// �v���X2�G���^�[

		TITLEHUNDLE_NUM,
	};

	int _hundle[TITLEHUNDLE_NUM];
	

public:

	//������
	void Init() override;
	//���[�h
	void Load() override;
	//�ʏ폈��
	void Step()	override;
	//�`�揈��
	void Draw() override;
	//�㏈��
	void Fin() override;

};

