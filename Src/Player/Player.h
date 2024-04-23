#pragma once

#include "DxLib.h"
#include "../Input/Input.h"
#include "../Screen/Screen.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Enemy/Enemy.h"

const int PLAYER_IMAGE_NUM = 12;										//�摜�̔z��̐�
const int GRAVITY = 1.0;

//�v���C���[�A�j���[�V�������
enum PlayerAnimationType {

	PLAYER_ANIMATION_TYPE_RUN = 0,
	PLAYER_ANIMATION_TYPE_JUMP,
	PLAYER_ANIMATION_TYPE_MIDAIR,
	PLAYER_ANIMATION_TYPE_FALL,
	PLAYER_ANIMATION_TYPE_LANDING,
	
	PLAYER_ANIMATION_TYPE_MAX,
};

//�v���C���[�̃A�j���[�V�����̏��
enum PlayerState {
	
	PLAYER_STATE_RUN = 0,
	PLAYER_STATE_JUMP,
	PLAYER_STATE_MIDAIR,
	PLAYER_STATE_FALL,
	PLAYER_STATE_LANDING,
	
};

class Player
{
private:
	//�N���X�錾
	Screen screen;

	//�v���C���[�̍��W
	float m_posX;
	float m_posY;

	//�ړ���̍��W
	float m_nextPosX;
	float m_nextPosY;

	//�ړ��O�̍��W
	float old_pos_x;
	float old_pos_y;

	//�v���C���[�ړ���
	float m_move_x;
	float m_move_y;

	//�摜�n���h��
	int m_ImageHandle[PLAYER_IMAGE_NUM];

	//�v���C���[��HP
	int m_HP;

	//�v���C���[�ړ��t���O
	int m_PlayerMoveFlag;

	//�`��t���O
	int m_drawflag;

	//�}�E�X���W
	int m_Mouse_x;	//�����W
	int m_Mouse_y;	//y���W

	//�v���C���[���G�t���O
	bool PlayerInviFlag;

	//�v���C���[���G�t���[��
	int PlayerInviFlame;

	//�v���C���[���ߏ���
	int m_alpha;

	int m_AnimationFreamCnt = 0;

	int m_Animation_Num = 0;

	//�v���C���[�A�j���[�V�������
	PlayerAnimationType now_animation;

	//�v���C���[�A�j���|�V�������
	PlayerState state;

public:

	//������
	void Init();
	
	//�ǂݍ���
	void Load();

	//�����l
	void DefaultValue();

	//�ʏ폈��
	void Step(int flag);

	//�`�揈��
	void Draw(int flag);

	//�I������
	void Fin();

	//���쏈��
	void Control();

	//�A�j���[�V����
	void Animation();

	//Hp�擾
	int GetHp() { return m_HP; }
	//H���Z�b�g
	void SetHp(int hp);

	//���W�擾
	float GetPosX() { return m_posX; }		//X���W
	float GetPosY() { return m_posY; }		//Y���W

	//�ړ���̍��W���擾
	int GetNextPosX() { return m_nextPosX; }
	int GetNextPosY() { return m_nextPosY; }

	//�ړ���̍��W��ݒ�
	void SetNextPosX(int _posX);
	void SetNextPosY(int _posY);

	//���W���X�V
	void UpdatePos();

	//�i��ł���������`�F�b�N
	//�㉺���E
	void GetMoveDirection(bool* _dirArray);

	//�v���C���[�V�䏈��
	void PlayerCeiling();

	//�v���C���[�����O�`�F�b�N
	void StepPlayerMidAir();

	//�v���C���[�����X�V
	void StepPlayerFall();

	//�v���C���[���n����
	void PlayerLanding();

	//�v���C���[���W�����v�\���ǂ���
	bool CanJumpPlayer();

	//�v���C���[���󒆏�Ԃ��ǂ���
	bool IsAirPlayer();

	//�v���C���[���G���ǂ���
	bool PlayerInvincible();

	//Hp�`��
	void DrawHp();

	//�v���C���[���S�������ǂ���
	bool DeathPlayer();

	//�v���C���[�񕜏���
	void PlayerHeal();

	//�v���C���[���G����
	void StepInvincible();
};





