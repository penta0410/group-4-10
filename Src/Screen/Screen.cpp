#pragma once

#include <DxLib.h>
#include "Screen.h"
#include "../Common.h"

//�X�N���[���̃��[���h���W
Screen::Screen()
{
	m_player_x = 0;
	m_player_y = 0;

	m_screenX = 0;
	m_screenY = 0;
}

Screen::~Screen() {}

//�X�N���[���̃X�e�b�v
void Screen::StepScreen(int x)
{
	//���@�����S�ɂȂ�悤�ɁA
	//�X�N���[�����W��ݒ�

	m_screenX = x - WINDOW_WIDTH / 2;

}

//�X�N���[���̂w���W���擾
float Screen::GetScreenX()
{
	return m_screenX;
}

//�X�N���[���̂x���W���擾
float Screen::GetScreenY()
{
	return m_screenY;
}



