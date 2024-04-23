#pragma once

#include "Player.h"
#include "../Map/Map.h"
#include "../Transparent/Transparent.h"

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

	//�摜�n���h��
	memset(m_ImageHandle, -1, sizeof(m_ImageHandle));

	//HP
	m_HP = 0;

	//�v���C���[���G�t���O
	PlayerInviFlag = false;

	//�v���C���[���G�t���[��
    PlayerInviFlame = 0;

	//�v���C���[���ߏ���
	m_alpha = 0;

}

//�ǂݍ��ݏ���
void Player::Load()
{
	
}

//�����l�ݒ菈��
void Player::DefaultValue()
{
	
}

//�ʏ폈��
void Player::Step(int flag)
{
	
	
}

//�`�揈��
void Player::Draw(int flag)
{
	

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
		if (CanJumpPlayer() == true)
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

//�����O�`�F�b�N
void Player::StepPlayerMidAir()
{
	//�W�����v����ɓ��B����Q�t���[���O�ɃA�j���[�V�������Đ�����
	if (state == PLAYER_STATE_JUMP && m_move_y > -GRAVITY * 2)
	{
		//�󒆏�ԂɕύX
		state = PLAYER_STATE_MIDAIR;
	}
}

//�����X�V
void Player::StepPlayerFall()
{
	//�������n�߂ĂT�t���[����ɗ�����Ԃɂ���
	if (m_move_y > GRAVITY * 5)
	{
		//������ԂɕύX
		state = PLAYER_STATE_FALL;
	}
}

//���n����
void Player::PlayerLanding()
{
	//���̈ړ��ʂ����Z�b�g
	m_move_y = 0.0f;

	//�ҋ@��Ԃɖ߂�
	if (IsAirPlayer())
	{
		//��ԂɕύX
		state = PLAYER_STATE_RUN;
	}
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

//H���Z�b�g
void Player::SetHp(int hp)
{
	m_HP = hp;
}

//�v���C���[���G���ǂ���
bool Player::PlayerInvincible()
{
	//�v���C���[���G�t���[��
	PlayerInviFlame++;

	//�v���C���[���G
	PlayerInviFlag = true;

	//1�b�������疳�G����
	if (PlayerInviFlame > 120)
	{
		//�v���C���[���G�o�Ȃ�
		PlayerInviFlag = false;

		//�t���[��������
		PlayerInviFlame = 0;
	}

	return PlayerInviFlag;
}

//Hp�`��
void Player::DrawHp()
{
	DrawBox(m_posX - 13, m_posY - 33, m_posX + 53, m_posY - 30, GetColor(255, 255, 255), true);
	DrawBox(m_posX - 10, m_posY - 30, m_posX + m_HP / 2 , m_posY - 20, GetColor(0, 255, 0), true);
	DrawBox(m_posX - 13, m_posY - 20, m_posX + 53, m_posY - 17, GetColor(255, 255, 255), true);
	DrawBox(m_posX - 13, m_posY - 33, m_posX - 10, m_posY - 17, GetColor(255, 255, 255), true);
	DrawBox(m_posX + 50, m_posY - 33, m_posX + 53, m_posY - 17, GetColor(255, 255, 255), true);

}

//�v���C���[���S����
bool Player::DeathPlayer()
{
	if (m_HP > -20)
	{
		return false;
	}
	else if (m_HP <= -20)
	{
		return true;
	}
}

//�v���C���[�񕜏���
void Player::PlayerHeal()
{
	m_HP += 10;
}

//�v���C���[���G����
void Player::StepInvincible()
{
	//�v���C���[�����G��������
	if (PlayerInvincible() == true)
	{
		
	}
}