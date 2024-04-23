#pragma once
#include "../Scene.h"
#include "../../Player/Player.h"
#include <math.h>
#include "DxLib.h"
#include "ScenePlay.h"
#include "../../Collision/Collision.h"
#include "../../Input/Input.h"
#include "../../Screen/Screen.h"
#include "../../Map/Map.h"
#include "../Result/SceneResult.h"
#include "../../Effect/Effect.h"

//�v���C�V�[���摜����
const int PLAY_IMAGE_PATH_NUM = 4;
const int PLAY_SOUND_PATH_NUM = 5;

const char PLAY_BGM_PATH[PLAY_SOUND_PATH_NUM][256] =
{
	"Data/Sound/Play/PlayBGM.mp3",		//�v���C�V�[����BGM
	"Data/Sound/Play/coin04.mp3",		//�R�C���l��SE
	"Data/Sound/Play/damaged1.mp3",		//�_���[�WSE
	"Data/Sound/Play/recovery.mp3",		//��SE

};

//�v���C�V�[���p�X
const char PLAY_PATH[PLAY_IMAGE_PATH_NUM][256] =
{
	"Data/Play/BackGround.png",		//�w�i
	"Data/Play/BackGround2.png",		//�w�i�Q
	"Data/Play/coin.png",			//�R�C��

};

const char PLAY_SCENE_BGM[] = { "" };				//�v���C�V�[����BGM

//�v���C�V�[���N���X
class PLAY : public SCENE_BASE
{
private:
	//�N���X�錾
	Player player;			//�v���C���[�N���X
	Screen m_screen;		//�X�N���[���N���X
	Map m_map;				//�}�b�v�N���X
	RESULT m_result;

	//�G�t�F�N�g���
	EffectInfo effectInfo;

	//�摜�n���h��
	int m_ImageHandle[PLAY_IMAGE_PATH_NUM];

	//�w�i���W
	int m_BG_x[2];
	int m_BG_y;
	
	//�w�i�ړ���
	int m_BG_move_x;

	//�R�C��UI���W
	int m_coin_x;
	int m_coin_y;

	//�l���R�C���ۑ��ϐ�
	int m_CoinNum;

	//�����t�H���g�n���h��
	int MojiHandle;

	//����������
	int m_numberHandle[10];
	int num;

	//�T�E���h�n���h��
	int m_PlayBgmHndl[5];

	int flamecount;

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
	// �}�b�v�̓����蔻��
	void MapCollision(int mapmove);

	//�R�C���Q�b�g
	int GetCoin() { return m_CoinNum; };

	//�R�C���Z�b�g
	void SetCoin(int num);

};

