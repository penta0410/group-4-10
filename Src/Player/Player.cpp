#pragma once

#include "Player.h"
#include "../Map/Map.h"
#include "../Transparent/Transparent.h"
#include "../Input/Input.h"
#include "../Common.h"

//����������
void Player::Init()
{
	//���W
	m_posX = 0;			//X���W
	m_posY = 0;			//Y���W
	m_nextPosX = 0;		//�ړ����X���W
	m_nextPosY = 0;		//�ړ����Y���W
	old_pos_x = 0;		//�ړ��O��X���W
	old_pos_y = 0;		//�ړ��O��Y���W

	//�ړ���
	m_move_x = 0;		//X�ړ���
	m_move_y = 0;		//Y�ړ���

	// ��]�l
	m_Rot = 0.0f;

	//�摜�n���h��
	memset(&m_ImageHandle, -1, sizeof(m_ImageHandle));

	//�v���C���[���G�t���O
	PlayerInviFlag = false;

	//�v���C���[���S�m�F�t���O
	isDeath = false;

	//�v���C���[���G�t���[��
	PlayerInviFlame = 0;

	//�v���C���[���ߏ���
	m_alpha = 0;

	//�v���C���[�A�j���|�V�������
	state = PLAYER_STATE_FALL;

	// �Q�[�����[�h
	gamemode = GAMEMODE_NORMAL;
}

//�ǂݍ��ݏ���
void Player::Load()
{
	m_ImageHandle = LoadGraph(PLAYER_PATH);
}

//�����l�ݒ菈��
void Player::DefaultValue()
{
	//���W
	m_posX = PLAYER_SIZE * 6;	//X���W
	m_posY = PLAYER_SIZE / 2 * 2;	//Y���W
	m_nextPosX = m_posX;		//�ړ����X���W
	m_nextPosY = m_posY;		//�ړ����Y���W
	old_pos_x = m_posX;			//�ړ��O��X���W
	old_pos_y = m_posY;			//�ړ��O��Y���W
}

//�ʏ폈��
void Player::Step()
{
	switch (gamemode) {
	case GAMEMODE_NORMAL:
		switch (state) {
		case PLAYER_STATE_RUN:	// �v���C���[�������Ă���Œ��Ȃ�
			Control();			// ����ł���
			break;

		case PLAYER_STATE_JUMP:		// �v���C���[���W�����v��ԂȂ�
			StepJump();				// �W�����v����
			break;

		case PLAYER_STATE_MIDAIR:	// �v���C���[���󒆂ɂ���Ȃ�
			PlayerMovement();		// �v���C���[�ړ�����
			CheckPlayerMidAir();	// �v���C���[���������Ă��邩�`�F�b�N
			break;

		case PLAYER_STATE_FALL:		// �v���C���[���������Ă���Ȃ�
			PlayerMovement();		// �v���C���[�ړ�����
			break;

		case PLAYER_STATE_LANDING:	// �v���C���[�����n�����Ȃ�
			PlayerLanding();		// ���n����
			break;
		}
		break;
	case GAMEMODE_SPACE:
		StepSpace();
		break;
	}
	m_nextPosY += m_move_y;

}

//�`�揈��
void Player::Draw()
{
	// �v���C���[�̕`��
	DrawRotaGraph(m_posX + (PLAYER_SIZE / 2), m_posY + (PLAYER_SIZE / 2), 1.0f, m_Rot / 180.0f * DX_PI_F, m_ImageHandle, true);

	//�f�o�b�O
	//�v���C���[�����蔻��i�^�񒆂����_�̂��ߋ����j
	//DrawBox(m_posX - (PLAYER_SIZE / 2), m_posY - (PLAYER_SIZE / 2),
	//	(m_posX - (PLAYER_SIZE / 2)) + PLAYER_SIZE,
	//	(m_posY - (PLAYER_SIZE / 2)) + PLAYER_SIZE, GetColor(255, 255, 255), true);

	//�v���C���[��]�l
	DrawFormatString(0, 80, GetColor(255, 255, 255), "%f", m_Rot);

}

//�I������
void Player::Fin()
{
	
}

//���쏈��
void Player::Control()
{
	m_nextPosX = m_posX;
	m_nextPosY = m_posY;

	//�W�����v����
	if (IsKeyPush(KEY_INPUT_SPACE))
	{
		if (CanJumpPlayer())
		{
			//�W�����v��Ԃɐݒ�
			state = PLAYER_STATE_JUMP;
		}
	}
}

//�A�j���[�V����
void Player::Animation()
{
	//�t���[���J�E���g�����Z
	m_AnimationFreamCnt++;

	//1�b��������
	if (m_AnimationFreamCnt >= 15)
	{
		//�A�j���[�V�����ԍ���1���Z
		m_Animation_Num++;
		//�A�j���[�V���������Ό����ɂȂ�Ȃ��悤�ɂ���
		if (m_Animation_Num > 8)
		{
			//�A�j���[�V�������ŏ��ɖ߂�
			m_Animation_Num = 6;
		}

		//�A�j���[�V�����������I�������t���[���J�E���g��������
		m_AnimationFreamCnt = 0;
	}
}

// �i��ł���������`�F�b�N
// �㉺���E�̏��ɂȂ��Ă���
void Player::GetMoveDirection(bool* _dirArray) {

	// �E�����̃`�F�b�N
	if (m_nextPosX > m_posX) {
		_dirArray[3] = true;
	}

	// �������̃`�F�b�N
	if (m_nextPosX < m_posX) {

		_dirArray[2] = true;

	}

	// �������̃`�F�b�N
	if (m_nextPosY > m_posY) {
		_dirArray[1] = true;

	}

	// ������̃`�F�b�N
	if (m_nextPosY < m_posY) {
		_dirArray[0] = true;
	}

}

//�󒆏�Ԃ��ǂ���
bool Player::IsAirPlayer()
{
	switch (state)
	{
	case PLAYER_STATE_MIDAIR:
	case PLAYER_STATE_JUMP:
	case PLAYER_STATE_FALL:
		return true;
	}

	return false;

}

// �Q�[�����[�h��ύX����
void Player::SetGamemodeNoramal()
{
	gamemode = GAMEMODE_NORMAL;
	m_Rot = 0.0f;
	state = PLAYER_STATE_FALL;
}

void Player::SetGamemodeSpace()
{
	gamemode = GAMEMODE_SPACE;
	m_Rot = 90.0f;
}

// �F����Ԃ̒ʏ폈��
void Player::StepSpace()
{
	if (IsKeyKeep(KEY_INPUT_SPACE)) {
		m_move_y -= GRAVITY / 2;
		m_Rot -= ROTAITION_SPEED;
	}
	else {
		m_move_y += GRAVITY / 2;
		m_Rot += ROTAITION_SPEED;
	}
	if (m_Rot < 45.0f) {
		m_Rot = 45.0f;
	}
	if (m_Rot > 135.0f) {
		m_Rot = 135.0f;
	}
}

//�V�䏈��
void Player::PlayerCeiling()
{
	//���̈ړ��ʂ����Z�b�g
	m_move_y = 0.0f;

	if (IsAirPlayer())
	{
		//�v���C���[������ԂɕύX
		state = PLAYER_STATE_FALL;
	}
}

// �d�͌v�Z����
void Player::CalcGravity()
{
	m_move_y += GRAVITY;
}

// �v���C���[��]����
void Player::PlayerRotation()
{
	m_Rot += ROTAITION_SPEED;

	if (m_Rot > 360.0f) {
		m_Rot = 0.0f;
	}
}

// �v���C���[�ړ�����
void Player::PlayerMovement()
{
	// �d�͌v�Z����
	CalcGravity();

	// �v���C���[��]����
	PlayerRotation();
}

//�v���C���[���������Ă��邩�`�F�b�N
void Player::CheckPlayerMidAir()
{
	// ����Y�̑��x���v���X�Ȃ痎�����Ă���
	if (m_move_y > 0) {
		//�v���C���[������ԂɕύX
		state = PLAYER_STATE_FALL;
	}
}

// �W�����v����
void Player::StepJump()
{
	m_move_y = -PLAYER_JUMP_POWER;	// �����l������
	state = PLAYER_STATE_MIDAIR;	// �󒆂ɂ��邱�Ƃɂ���
}

//���n����
void Player::PlayerLanding()
{
	//���̈ړ��ʂ����Z�b�g
	m_move_y = 0.0f;
	// ��]�l�͂��̎��̒l�ɂ���ĕύX
	if (m_Rot < 45.0f) {
		m_Rot = 0.0f;
	}
	else if (m_Rot < 135.0f) {
		m_Rot = 90.0f;
	}
	else if (m_Rot < 225.0f) {
		m_Rot = 180.0f;
	}
	else if (m_Rot < 315.0f) {
		m_Rot = 270.0f;
	}
	else {
		m_Rot = 0.0f;
	}

	//�����Ă����ԂɕύX
	state = PLAYER_STATE_RUN;
}


//���W���X�V
void Player::SetNextPosX(int _posX)
{
	m_nextPosX = _posX;
}

//���W���X�V
void Player::SetNextPosY(int _posY)
{
	m_nextPosY = _posY;
}

//�W�����v�\���ǂ���
bool Player::CanJumpPlayer()
{
	switch (state)
	{
	case PLAYER_STATE_JUMP:
	case PLAYER_STATE_MIDAIR:
	case PLAYER_STATE_FALL:
		return false;
	}

	return true;

}

// ���W���X�V
void Player::UpdatePos() {
	m_posX = m_nextPosX;
	m_posY = m_nextPosY;
}

