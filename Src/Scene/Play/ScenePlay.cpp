#pragma once

#include "ScenePlay.h"
#include "../../Common.h"

//=============================
// �v���C�V�[��
//=============================

//������
void PLAY::Init()
{
	player.Init();				//�v���C���[�̏���������
	player.DefaultValue();		//�v���C���[�̏����l�ݒ�
	m_map.Init();				//�}�b�v������
	effectInfo.InitEffect();	//�G�t�F�N�g������

	//�w�i���W
	m_BG_x[0] = WINDOW_WIDTH/2;
	m_BG_x[1] = WINDOW_WIDTH + (WINDOW_WIDTH / 2);
	m_BG_y = WINDOW_HEIGHT/2;

	//�w�i�ړ���
	m_BG_move_x = 0;

	flamecount = 0;

	for (int i = 0; i < PLAY_SOUND_PATH_NUM; i++)
	{
		m_PlayBgmHndl[i] = -1;
	}

	//�v���C���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//���[�h
void PLAY::Load()
{
	m_ImageHandle[0] = LoadGraph(PLAY_PATH[0]);			//�v���C�w�i
	m_ImageHandle[1] = LoadGraph(PLAY_PATH[1]);			//�v���C�w�i2
	m_ImageHandle[2] = LoadGraph(PLAY_PATH[2]);			//�R�C��
	
	effectInfo.LoadEffect(EFFECT_TYPE_SHINE, 3);		//�G�t�F�N�g�L���L��
	effectInfo.LoadEffect(EFFECT_TYPE_RECOVERY, 3);		//�G�t�F�N�g��

	//�R�C�����W
	m_coin_x = 50;
	m_coin_y = 50;

	for (int i = 0; i < 10; i++) {
		LoadDivGraph(RESULT_NUMBER_PATH, SCORE_NUMBER_MAX_NUM, SCORE_NUMBER_MAX_NUM, 1, 12, 24, m_numberHandle, false);
	}

	player.Load();				//�v���C���[�̓ǂݍ���

	//�������ASE �ǂݍ���
	for (int i = 0; i < PLAY_SOUND_PATH_NUM; i++)
	{
		m_PlayBgmHndl[i] = LoadSoundMem(PLAY_BGM_PATH[i]);
	}
}

void PLAY::Sound()
{
	PlaySoundMem(m_PlayBgmHndl[0], DX_PLAYTYPE_LOOP);
}

//�ʏ폈��
void PLAY::Step()
{	
	//�v���C���[�������Ă��鎞�����������s�����񂾂�X�g�b�v
	if (player.DeathPlayer() == false)
	{
		player.Step(1);				//�v���C���[�̒ʏ폈��
		effectInfo.StepEffect();		//�G�t�F�N�g�ʏ폈��

		//�w�i�X�N���[������
		m_BG_x[0] -= PLAYER_SPEED;
		m_BG_x[1] -= PLAYER_SPEED;
		m_BG_move_x -= PLAYER_SPEED;

		if (m_BG_x[0] <= -(WINDOW_WIDTH / 2))
		{
			m_BG_x[0] = WINDOW_WIDTH + (WINDOW_WIDTH / 2);
		}
		else if (m_BG_x[1] <= -(WINDOW_WIDTH / 2))
		{
			m_BG_x[1] = WINDOW_WIDTH + (WINDOW_WIDTH / 2);
		}

		//�}�b�v�̓����蔻��
		MapCollision(-m_BG_move_x);

		//�v���C���[�̍��W���X�V
		player.UpdatePos();
	}

	//�v���C���[�����S������
	if (player.DeathPlayer() == true)
	{
		flamecount++;

		if (flamecount > 60)
		{
			//�V�[���t���O�����U���g�V�[���ɕύX
			m_SceneFlag = 0;
			//�v���C�㏈���ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_PLAY;
		}
	}

	//�f�o�b�O(���S�ł��Ȃ��������̂���)=============================
	//���U���g�V�[���ւ̑J��
	//���V�t�g�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_LSHIFT))
	{
		//�V�[���t���O�����U���g�V�[���ɕύX
		m_SceneFlag = 0;
		//�v���C�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}
	//===============================================================
}

//�`�揈��
void PLAY::Draw()
{
	//�w�i�`��
	DrawRotaGraph(m_BG_x[0], m_BG_y, 1.0f, 0.0f, m_ImageHandle[0], true);
	DrawRotaGraph(m_BG_x[1], m_BG_y, 1.0f, 0.0f, m_ImageHandle[1], true);

	m_map.Draw(-m_BG_move_x);	//�}�b�v�`��

	player.Draw(1);				//�v���C���[�̕`�揈��

	effectInfo.DrawEffect();

	//�R�C�`��
	DrawRotaGraph(m_coin_x, m_coin_y, 0.8f, 1.0f, m_ImageHandle[2], true);

	int count = 0;

	int ItemScore = 0;

	num = 0;

	//�R�C�������`��
	SetFontSize(36);
	//�X�R�A���[���̎�
	if (m_CoinNum == 0) {
		DrawFormatString(m_coin_x + 50, m_coin_y - 20, GetColor(255, 255, 255),"X", true);
		DrawRotaGraph(m_coin_x + 150, m_coin_y, 1.8f, 0.0f, m_numberHandle[0], true);
	}
	ItemScore = m_CoinNum;
	//�X�R�A���[���ȏ�̎�
	while (ItemScore > 0) {
		num = ItemScore % 10;
		ItemScore = ItemScore / 10;
		//�R�C�������`��
		DrawFormatString(m_coin_x + 50, m_coin_y - 20, GetColor(255, 255, 255), "X", true);
		DrawRotaGraph(m_coin_x - count * 25 + 150, m_coin_y, 1.8f, 0.0f, m_numberHandle[num], true);
		count++;
	}
	SetFontSize(16);

	//�f�o�b�O
	SetFontSize(30);
	SetFontSize(16);
}

//�㏈��
void PLAY::Fin()
{
	for (int i = 0; i < PLAY_SOUND_PATH_NUM; i++)
	{
		DeleteSoundMem(m_PlayBgmHndl[i]);
	}

	//SceneFlag��0�̎�
	if (m_SceneFlag == 0)
	{
		//�v���CINIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_RESULT;
	}
}

//�}�b�v�̓����蔻��
void PLAY::MapCollision(int mapmove)
{
	//�v���C���[
	//Y�����̂ݓ����蔻����`�F�b�N����
	for (int mapIndexY = 0; mapIndexY < MAP_DATA_Y; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAP_DATA_X; mapIndexX++)
		{
			//�u���b�N�ȊO�͏������Ȃ�
			if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] == MAPCHIP_NONE)
			{
				continue;
			}

			//�ǂ̕����ɐi��ł������`�F�b�N
			bool dirArray[4] = { false,false,false,false };
			player.GetMoveDirection(dirArray);

			//��`�̓����蔻��p�̃f�[�^������
			//�v���C���[�̏��
			int Ax = player.GetPosX() - 20;
			int Ay = player.GetPosY() - 10;
			int Aw = PLAYER_WIDTH * 2;
			int Ah = PLAYER_HEIGHT * 2;

			//�I�u�W�F�N�g�̏��
			int Bx = mapIndexX * MAP_SIZE + 20 - mapmove;
			int By = mapIndexY * MAP_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE + 10;

			//Y�����݂̂Ɉړ������Ɖ��肵�����W�œ����蔻����`�F�b�N���܂�
			Ay = player.GetNextPosY();
			Ax = player.GetNextPosX();

			//�������Ă��邩�`�F�b�N
			if (IsHitRect(Ax + mapmove, Ay, Aw, Ah, Bx + mapmove, By, Bw, Bh)) {

				if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] != 7)
				{
					if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] != 8)
					{
						if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] != 9)
						{
							// ������̏C��
							if (dirArray[0]) {
								// �߂荞�ݗʂ��v�Z����
								int overlap = By + Bh - Ay;
								player.SetNextPosY(Ay + overlap);

								//�V��ɂ����牟���Ԃ�
								player.PlayerCeiling();

							}
							//�������̏C��
							if (dirArray[1]) {
								// �߂荞�ݗʂ��v�Z����
								int overlap = Ay + Ah - By;
								player.SetNextPosY(Ay - overlap);

								//����������
								player.PlayerLanding();

							}
						}
					}
				}

				//�R�C������
				if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] == 7)
				{
					//�G�t�F�N�g�`��
					effectInfo.PlayEffect(EFFECT_TYPE_SHINE, mapIndexX * MAP_SIZE -10
						+ m_BG_move_x, mapIndexY * MAP_SIZE + 10);

					ChangeVolumeSoundMem(150, m_PlayBgmHndl[1]);
					PlaySoundMem(m_PlayBgmHndl[1], DX_PLAYTYPE_LOOP, true);	//�R�C��SE
					StopSoundMem(m_PlayBgmHndl[1], true);

					m_map.CoinStep(mapIndexX, mapIndexY);

					m_CoinNum += 1;
					
				}
				//�g���b�v����
				if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] == 8)
				{
					ChangeVolumeSoundMem(130, m_PlayBgmHndl[2]);
					PlaySoundMem(m_PlayBgmHndl[2], DX_PLAYTYPE_LOOP, true);	//�R�C��SE
					StopSoundMem(m_PlayBgmHndl[2], true);

					player.TrapStep();
				}
				//�n�[�g����
				if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] == 9)
				{
					//�G�t�F�N�g�`��
					effectInfo.PlayEffect(EFFECT_TYPE_RECOVERY, mapIndexX * MAP_SIZE - 10
						+ m_BG_move_x, mapIndexY * MAP_SIZE + 10);

					ChangeVolumeSoundMem(200, m_PlayBgmHndl[3]);
					PlaySoundMem(m_PlayBgmHndl[3], DX_PLAYTYPE_LOOP, true);	//��SE
					StopSoundMem(m_PlayBgmHndl[3], true);

					player.PlayerHeal();	//�v���C���[�񕜏���

					m_map.HeartStep(mapIndexX, mapIndexY);
				}
			}
		}
	}

	// X�����̂ݓ����蔻����`�F�b�N����
	for (int mapIndexY = 0; mapIndexY < MAP_DATA_Y; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAP_DATA_X; mapIndexX++)
		{
			// �u���b�N�ȊO�͏������Ȃ�
			if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] == MAPCHIP_NONE)
				continue;

			//�ǂ̕����ɐi��ł������`�F�b�N
			bool dirArray[4] = { false,false,false,false };
			player.GetMoveDirection(dirArray);

			//�v���C���[�̏��
			int Ax = player.GetPosX() - 20;
			int Ay = player.GetPosY() - 10;
			int Aw = PLAYER_WIDTH * 2;
			int Ah = PLAYER_HEIGHT * 2;

			//�I�u�W�F�N�g�̏��
			int Bx = mapIndexX * MAP_SIZE + 20 - mapmove;
			int By = mapIndexY * MAP_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE + 10;

			//X�����݂̂Ɉړ������Ɖ��肵�����W�œ����蔻����`�F�b�N
			Ay = player.GetNextPosY();
			Ax = player.GetNextPosX();

			// �������Ă��邩�`�F�b�N
			if (IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {

				if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] != 7)
				{
					if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] != 8)
					{
						if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] != 9)
						{
							// �������̏C��
							if (dirArray[2]) {
								// �߂荞�ݗʂ��v�Z����
								int overlap = Bx + Bw - Ax;
								player.SetNextPosX(Ax + overlap);
							}

							// �E�����̏C��
							if (dirArray[3]) {
								// �߂荞�ݗʂ��v�Z����
								int overlap = Ax + Aw - Bx;
								player.SetNextPosX(Ax - overlap);
							}
						}
					}
				}

				//�R�C������
				if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] == 7)
				{
					//�G�t�F�N�g�`��
					effectInfo.PlayEffect(EFFECT_TYPE_SHINE, mapIndexX* MAP_SIZE - 10
						+ m_BG_move_x, mapIndexY* MAP_SIZE + 10);

					ChangeVolumeSoundMem(150, m_PlayBgmHndl[1]);
					PlaySoundMem(m_PlayBgmHndl[1], DX_PLAYTYPE_LOOP, true);	//�R�C��SE
					StopSoundMem(m_PlayBgmHndl[1], true);

					m_map.CoinStep(mapIndexX, mapIndexY);

					m_CoinNum += 1;
				}
				//�g���b�v����
				if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] == 8)
				{
					ChangeVolumeSoundMem(130, m_PlayBgmHndl[2]);
					PlaySoundMem(m_PlayBgmHndl[2], DX_PLAYTYPE_LOOP, true);	//�R�C��SE
					StopSoundMem(m_PlayBgmHndl[2], true);

					player.TrapStep();
				}
				//�n�[�g����
				if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] == 9)
				{
					//�G�t�F�N�g�`��
					effectInfo.PlayEffect(EFFECT_TYPE_RECOVERY, mapIndexX* MAP_SIZE - 10
						+ m_BG_move_x, mapIndexY* MAP_SIZE + 10);

					ChangeVolumeSoundMem(255, m_PlayBgmHndl[3]);
					PlaySoundMem(m_PlayBgmHndl[3], DX_PLAYTYPE_LOOP, true);	//��SE
					StopSoundMem(m_PlayBgmHndl[3], true);

					player.PlayerHeal();	//�v���C���[�񕜏���

					m_map.HeartStep(mapIndexX, mapIndexY);
				}
			}
		}
	}
}


//�R�C���Z�b�g
void PLAY::SetCoin(int num)
{
	m_CoinNum = num;
}
