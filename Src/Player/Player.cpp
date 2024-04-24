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
	state = PLAYER_STATE_MIDAIR;
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
	m_posX = PLAYER_SIZE / 2;	//X���W
	m_posY = PLAYER_SIZE / 2;	//Y���W
	m_nextPosX = m_posX;		//�ړ����X���W
	m_nextPosY = m_posY;		//�ړ����Y���W
	old_pos_x = m_posX;			//�ړ��O��X���W
	old_pos_y = m_posY;			//�ړ��O��Y���W
}

//�ʏ폈��
void Player::Step()
{
	//�v���C���[���W�����v�\���ǂ���
	if(CanJumpPlayer())
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
		CheckPlayerLanding();	//�v���C���[�����n���Ă��邩�`�F�b�N
		break;

	case PLAYER_STATE_LANDING:	// �v���C���[�����n�����Ȃ�
		PlayerLanding();		//���n����
		break;
	}

	m_nextPosY += m_move_y;
	// ���W�X�V
	UpdatePos();
}

//�`�揈��
void Player::Draw()
{
	// �v���C���[�̕`��
	DrawRotaGraph(m_posX, m_posY, 1.0f, m_Rot, m_ImageHandle, true);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "%d", state);
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

//�V�䏈��
//void Player::PlayerCeiling()
//{
//	//���̈ړ��ʂ����Z�b�g
//	m_move_y = 0.0f;
//
//	if (IsAirPlayer())
//	{
//		//�v���C���[������ԂɕύX
//		state = PLAYER_STATE_FALL;
//	}
//}

// �d�͌v�Z����
void Player::CalcGravity()
{
	m_move_y -= GRAVITY;
}

// �v���C���[��]����
void Player::PlayerRotation()
{
	m_Rot += ROTAITION_SPEED * 180 / DX_PI;
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
	// ����Y�̑��x���}�C�i�X�Ȃ痎�����Ă���
	if (m_move_y < 0) {
		//�v���C���[������ԂɕύX
		state = PLAYER_STATE_FALL;
	}
}

//�v���C���[�����n���Ă��邩�`�F�b�N
void Player::CheckPlayerLanding()
{
	if (m_nextPosY > WINDOW_HEIGHT - PLAYER_SIZE) {
		// ���n�����
		state = PLAYER_STATE_LANDING;
	}
}

// �W�����v����
void Player::StepJump()
{
	m_move_y = PLAYER_JUMP_POWER;	// �����l������
	state = PLAYER_STATE_MIDAIR;	// �󒆂ɂ��邱�Ƃɂ���
}

//���n����
void Player::PlayerLanding()
{
	//���̈ړ��ʂ����Z�b�g
	m_move_y = 0.0f;
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

