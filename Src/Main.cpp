
#include "DxLib.h"
#include "Scene/Scene.h"
#include "../Src/Scene/Title/SceneTitle.h"
#include "../Src/Scene/Play/ScenePlay.h"
#include "../Src/Scene/Result/SceneResult.h"
#include "Common.h"
#include "FPS/fps.h"
#include "Scene/Meinmenu/MeinmenuScene.h"
#include "Input/Input.h"

//�t���[�����[�g���ϐ�
FrameRateInfo frameRateInfo;

//�ŏ��̃V�[��ID
int g_CurrentSceneID = SCENE_ID_INIT_TITLE;

//�^�C�g���N���X�錾
TITLE title;
//���C�����j���[�N���X�錾
MEIN_MENU meinmenu;
//�v���C�V�[���N���X�錾
PLAY play;
//���U���g�V�[���N���X�錾
RESULT result;

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

			//�V�[��ID�ɂ���ď����̐U�蕪��
			switch (g_CurrentSceneID)
			{
			case SCENE_ID_INIT_TITLE:
			{
				//�^�C�g��������
				title.Init();
				title.Load();
				title.Sound();
			}	break;
			case SCENE_ID_LOOP_TITLE:
			{
				//�^�C�g���ʏ폈��
				title.Step();
				//�^�C�g���`�揈��
				title.Draw();
			}	break;
			case SCENE_ID_FIN_TITLE:
			{
				//�^�C�g���㏈��
				title.Fin();
			}	break;
			case SCENE_ID_INIT_MEIN_MENU:
			{
				// �Q�[������������
				meinmenu.Init();
			}	break;
			case SCENE_ID_LOOP_MEIN_MENU:
			{
				//���C�����j���[�ʏ폈��
				meinmenu.Step();
				//���C�����j���[�`�揈��
				meinmenu.Draw();
			}	break;
			case SCENE_ID_FIN_MEIN_MENU:
			{
				//���C�����j���[�㏈��
				meinmenu.Fin();
			}	break;
			case SCENE_ID_INIT_PLAY:
			{
				//�v���C������  
				play.Init();
				play.Load();
				play.Sound();

			}	break;
			case SCENE_ID_LOOP_PLAY:
			{
				//�v���C�`�揈��
				play.Draw();
				//�v���C�ʏ폈��
				play.Step();
			}	break;
			case SCENE_ID_FIN_PLAY:
			{
				//�v���C�㏈��
				play.Fin();
			}	break;
			case SCENE_ID_INIT_RESULT:
			{
				//���U���g������  
				result.Init(play.GetCoin());
				//���U���g�ǂݍ���
				result.Load();

				result.Sound();
			}   break;
			case SCENE_ID_LOOP_RESULT:
			{
				//���U���g�`�揈��
				result.Draw();
				//���U���g�ʏ폈��
				result.Step();
			}	break;
			case SCENE_ID_FIN_RESULT:
			{
				//���U���g�㏈��
				result.Fin();
			}   break;
			}//�V�[���U�蕪����switch���I��

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
	DxLib_End();

	return 0;
}
