#pragma once

//�P�t���[���̎��ԁi�~���b�j
#define FRAME_TIME	(1000 / FRAME_RATE)

//�t���[�����[�g���
struct FrameRateInfo
{
	int currentTime;	//���݂̎���
	int lastFrameTime;	//�O��̃t���[�����s���̎���
	int count;			//�t���[���J�E���g�p
	int calcFpsTime;	//FPS���v�Z��������
	float fps;			//�v������FPS�i�\���p�j
};

//�t���[�����[�g���ϐ�
extern FrameRateInfo frameRateInfo;

// FPS�v�Z
void CalcFPS();

//FPS�\���i�f�o�b�O�p�j
void DrawFPS();