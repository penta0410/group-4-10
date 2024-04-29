#pragma once
#include <math.h>
#include "DxLib.h"
#include "../../Collision/Collision.h"
#include "../../Common.h"
#include "../../Input/Input.h"
#include "../Scene.h"
#include "../../Map/Map.h"
#include "../../Common.h"
#include "../../Player/Player.h"

//�v���C�V�[���摜����
const int PLAY_IMAGE_PATH_NUM = 4;

//�w�i�ړ��X�s�[�h
const int BG_MOVE_SPEED = 1;

//�v���C�V�[���摜�p�X
const char PLAY_PATH[PLAY_IMAGE_PATH_NUM][256] =
{
	"Data/Play/BackGround.png",		//�w�i
	"Data/Play/BackGround2.png",	//�w�i�Q

};



//�v���C�V�[���N���X
class Play : public Scene_Base
{
private:

	//�摜�n���h��
	int m_ImageHandle[PLAY_IMAGE_PATH_NUM];

	//�w�i���W
	int m_BG_x[2];
	int m_BG_y;
	
	//�w�i�ړ���
	int m_BG_move_x;

	//�}�b�v���[�u
	int mapmove;

	//�N���A�t���O
	bool IsClear;

public:

	Map c_map;				//�}�b�v�N���X�錾
	Player c_player;		//�v���C���[�N���X�錾


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
	
	// �}�b�v�̓����蔻��
	void MapCollision();

	//�w�i�X�N���[������
	int BGScroll(int move_speed);

	//�N���A�������ǂ���
	bool IsClear() { return IsClear; };

};

