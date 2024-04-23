
#include "DxLib.h"
#include "Scene/Scene.h"
#include "Common.h"
#include "FPS/fps.h"
#include "Input/Input.h"
#include "Scene/SceneManager/SceneManager.h"

//�t���[�����[�g���ϐ�
FrameRateInfo frameRateInfo;

SceneManager c_scene_manager;			//�V�[���}�l�[�W���[�N���X�錾

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);
	//�E�B���h�E�T�C�Y��ύX
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);

	//DX���C�u�����̏�����
	if(DxLib_Init() == -1)
	{
		return -1;
	}

	//�`�悷��X�N���[����ݒ�
	SetDrawScreen(DX_SCREEN_BACK);
	//���͐��䏉����
	InitInput();

	//�V�[���}�l�[�W���[������
	c_scene_manager.InitScene();

	//=====================================
	//�Q�[�����C�����[�v
	while(ProcessMessage() != -1)
	{
		Sleep(1);	//�V�X�e���ɏ�����Ԃ�
		//���݂̎��Ԃ��擾
		frameRateInfo.currentTime = GetNowCount();

		//�ŏ��̃��[�v�Ȃ�
		//���݂̎��Ԃ��AFPS�̌v�Z���������Ԃɐݒ�
		if (frameRateInfo.calcFpsTime == 0.0f)
		{
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
			frameRateInfo.fps = (float)FRAME_RATE;
		}

		// ���݂̎��Ԃ��A�O��̃t���[�������
		// 1000/60�~���b�i1/60�b�j�ȏ�o�߂��Ă����珈�������s����
		if (frameRateInfo.currentTime - frameRateInfo.lastFrameTime >= FRAME_TIME)
		{
			//�t���[�����s���̎��Ԃ��X�V
			frameRateInfo.lastFrameTime = frameRateInfo.currentTime;
			//�t���[�������J�E���g
			frameRateInfo.count++;

			if (IsKeyPush(KEY_INPUT_ESCAPE))
			{
				//�G�X�P�[�v�L�[�������ꂽ��I��
				break;
			}

			//��ʂɕ\�����ꂽ���̂��������i�P���[�v�̂P�x�����s���j
			ClearDrawScreen();
			//���͐���X�e�b�v
			StepInput();

			//�Q�[�����C������==========================
			//�V�[���}�l�[�W���[���[�v
			c_scene_manager.LoopScene();
			//===================================
			
			//FPS�v�Z
			CalcFPS();
			//FPS�\��
			DrawFPS();
			//�t���b�v�֐��i���[�v�̏I���ɂP�x�����s���j
			ScreenFlip();

		}//�t���[�����[�g��if���I���

	}//���C�����[�v�̏I���
	//�Ō�ɂP�񂾂���鏈���������ɏ���
	//DX���C�u�����̌㏈��
	
	//�V�[���}�l�[�W���[�I��
	c_scene_manager.FInScene();

	DxLib_End();

	return 0;
}
