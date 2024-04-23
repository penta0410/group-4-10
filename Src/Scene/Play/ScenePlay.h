#pragma once
#include "../Scene.h"
#include <math.h>
#include "DxLib.h"
#include "../../Collision/Collision.h"
#include "../../Common.h"
#include "../../Input/Input.h"

//�v���C�V�[���摜����
const int PLAY_IMAGE_PATH_NUM = 4;

//�v���C�V�[���摜�p�X
const char PLAY_PATH[PLAY_IMAGE_PATH_NUM][256] =
{
	

};


//�v���C�V�[���N���X
class PLAY : public SCENE_BASE
{
private:

	//�摜�n���h��
	int m_ImageHandle[PLAY_IMAGE_PATH_NUM];

	//�w�i���W
	int m_BG_x[2];
	int m_BG_y;
	
	//�w�i�ړ���
	int m_BG_move_x;

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

