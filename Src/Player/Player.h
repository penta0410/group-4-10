#pragma once
#include "DxLib.h"
#include "../Input/Input.h"
#include "../Screen/Screen.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Enemy/Enemy.h"

const int PLAYER_IMAGE_NUM = 12;										//�摜�̔z��̐�
const float GRAVITY = 1.0f;
const int PLAYER_SIZE = 60;
const float PLAYER_JUMP_POWER = 20.0f;
const char PLAYER_PATH[] = { "Data/Play/�}2.png" };
const float ROTAITION_SPEED = 0.002f;

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

	// �v���C���[��]�l
	float m_Rot;

	//�摜�n���h��
	int m_ImageHandle;

	//�v���C���[�ړ��t���O
	int m_PlayerMoveFlag;

	//�`��t���O
	int m_drawflag;

	//�}�E�X���W
	int m_Mouse_x;	//�����W
	int m_Mouse_y;	//y���W

	//�v���C���[���G�t���O
	bool PlayerInviFlag;

	//�v���C���[���S�m�F�t���O
	bool isDeath;

	//�v���C���[���G�t���[��
	int PlayerInviFlame;

	//�v���C���[���ߏ���
	int m_alpha;

	int m_AnimationFreamCnt = 0;

	int m_Animation_Num = 0;

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
	void Step();

	//�`�揈��
	void Draw();

	//�I������
	void Fin();

	//���쏈��
	void Control();

	//�A�j���[�V����
	void Animation();
	
	// ���S�m�F�p
	bool GetisDeath() { return isDeath; }

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

	// �d�͌v�Z����
	void CalcGravity();

	// �v���C���[��]����
	void PlayerRotation();

	// �v���C���[�ړ�����
	void PlayerMovement();

	//�v���C���[���������Ă��邩�`�F�b�N
	void CheckPlayerMidAir();

	//�v���C���[�����n���Ă��邩�`�F�b�N
	void CheckPlayerLanding();
	
	// �W�����v����
	void StepJump();

	//���n����
	void PlayerLanding();

	//�v���C���[���W�����v�\���ǂ���
	bool CanJumpPlayer();

	//�v���C���[���󒆏�Ԃ��ǂ���
	bool IsAirPlayer();
};