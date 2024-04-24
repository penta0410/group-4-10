#pragma once
#include "ScenePlay.h"
#include "../SceneManager/SceneManager.h"

//=============================
// �v���C�V�[��
//=============================

//������
void Play::Init()
{
	//�}�b�v������
	c_map.Init();
	//�v���C���[������
	c_player.Init();

	//�w�i���W
	m_BG_x[0] = WINDOW_WIDTH / 2;		//�w�i�P
	m_BG_x[1] = WINDOW_WIDTH + (WINDOW_WIDTH / 2);		//�w�i�Q
	m_BG_y = WINDOW_HEIGHT / 2;

	//�w�i�ړ���
	m_BG_move_x = 0;











	//�p�ӂ����摜��������
	for (int i = 0; i < PLAY_IMAGE_PATH_NUM; i++)
	{
		m_ImageHandle[i] = -1;
	}
}

//���[�h
void Play::Load()
{
	//�p�ӂ����摜��������
	for (int i = 0; i < PLAY_IMAGE_PATH_NUM; i++)
	{
		m_ImageHandle[i] = LoadGraph(PLAY_PATH[i]);
	}
}

//�ʏ폈��
void Play::Step()
{	
	
	//�v���C���[�������Ă��鎞�����������s�����񂾂�X�g�b�v
	if (c_player.DeathPlayer() == false)
	{
		//�}�b�v�ʏ폈��
		c_map.Step();

		//�w�i�X�N���[������
		BGScroll();

		//�}�b�v�����蔻��
		MapCollision(BGScroll());

	}
	//�V�[���ւ̑J��
	//�G���^�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		
		//�㏈���ֈړ�
		SceneManager::g_CurrentSceneStateID = SCENE_STATE_ID::SCENE_ID_FIN;
	}
	
}

//�`�揈��
void Play::Draw()
{
	//�w�i�`��
	DrawRotaGraph(m_BG_x[0], m_BG_y, 1.0f, 0.0f, m_ImageHandle[0], true);
	DrawRotaGraph(m_BG_x[1], m_BG_y, 1.0f, 0.0f, m_ImageHandle[1], true);

	//�}�b�v�`��
	c_map.Draw();
	
	//�f�o�b�O

}

//�㏈��
void Play::Fin()
{
	//�v���C���[�I������
	c_player.Fin();

	//���U���g�ֈړ�
	SceneManager::g_CurrentSceneID = SCENE_ID::SCENE_ID_RESULT;
}

//�w�i�X�N���[������
int Play::BGScroll()
{
	//�w�i�X�N���[������
	m_BG_x[0] -= BG_MOVE_SPEED;
	m_BG_x[1] -= BG_MOVE_SPEED;
	m_BG_move_x -= BG_MOVE_SPEED;

	if (m_BG_x[0] <= -(WINDOW_WIDTH / 2))
	{
		m_BG_x[0] = WINDOW_WIDTH + (WINDOW_WIDTH / 2);
	}
	else if (m_BG_x[1] <= -(WINDOW_WIDTH / 2))
	{
		m_BG_x[1] = WINDOW_WIDTH + (WINDOW_WIDTH / 2);
	}

	return m_BG_move_x;

}

//�}�b�v�̓����蔻��
void Play::MapCollision(int mapmove)
{
	//�v���C���[
	//Y�����̂ݓ����蔻����`�F�b�N����
	for (int mapIndexY = 0; mapIndexY < MAP_DATA_Y; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAP_DATA_X; mapIndexX++)
		{
			//�u���b�N�ȊO�͏������Ȃ�
			if (c_map.m_FileReadMapData[mapIndexY][mapIndexX] == MAPCHIP_NONE)
			{
				continue;
			}

			//�ǂ̕����ɐi��ł������`�F�b�N
			bool dirArray[4] = { false,false,false,false };
			c_player.GetMoveDirection(dirArray);

			//��`�̓����蔻��p�̃f�[�^������
			//�v���C���[�̏��
			int Ax = c_player.GetPosX() - 20;
			int Ay = c_player.GetPosY() - 10;
			int Aw = PLAYER_SIZE;
			int Ah = PLAYER_SIZE;

			//�I�u�W�F�N�g�̏��
			int Bx = mapIndexX * MAP_SIZE + 20 - mapmove;
			int By = mapIndexY * MAP_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE + 10;

			//Y�����݂̂Ɉړ������Ɖ��肵�����W�œ����蔻����`�F�b�N���܂�
			Ay = c_player.GetNextPosY();
			Ax = c_player.GetNextPosX();

			//�������Ă��邩�`�F�b�N
			if (IsHitRect(Ax + mapmove, Ay, Aw, Ah, Bx + mapmove, By, Bw, Bh)) {

				if (c_map.m_FileReadMapData[mapIndexY][mapIndexX] != 7)
				{
					if (c_map.m_FileReadMapData[mapIndexY][mapIndexX] != 8)
					{
						if (c_map.m_FileReadMapData[mapIndexY][mapIndexX] != 9)
						{
							// ������̏C��
							if (dirArray[0]) {
								// �߂荞�ݗʂ��v�Z����
								int overlap = By + Bh - Ay;
								c_player.SetNextPosY(Ay + overlap);

								//�V��ɂ����牟���Ԃ�
								c_player.PlayerCeiling();

							}
							//�������̏C��
							if (dirArray[1]) {
								// �߂荞�ݗʂ��v�Z����
								int overlap = Ay + Ah - By;
								c_player.SetNextPosY(Ay - overlap);

								//����������
								c_player.PlayerLanding();

							}
						}
					}
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
			if (c_map.m_FileReadMapData[mapIndexY][mapIndexX] == MAPCHIP_NONE)
				continue;

			//�ǂ̕����ɐi��ł������`�F�b�N
			bool dirArray[4] = { false,false,false,false };
			c_player.GetMoveDirection(dirArray);

			//�v���C���[�̏��
			int Ax = c_player.GetPosX() - 20;
			int Ay = c_player.GetPosY() - 10;
			int Aw = PLAYER_SIZE;
			int Ah = PLAYER_SIZE;

			//�I�u�W�F�N�g�̏��
			int Bx = mapIndexX * MAP_SIZE + 20 - mapmove;
			int By = mapIndexY * MAP_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE + 10;

			//X�����݂̂Ɉړ������Ɖ��肵�����W�œ����蔻����`�F�b�N
			Ay = c_player.GetNextPosY();
			Ax = c_player.GetNextPosX();

			// �������Ă��邩�`�F�b�N
			if (IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {

				if (c_map.m_FileReadMapData[mapIndexY][mapIndexX] != 7)
				{
					if (c_map.m_FileReadMapData[mapIndexY][mapIndexX] != 8)
					{
						if (c_map.m_FileReadMapData[mapIndexY][mapIndexX] != 9)
						{
							// �������̏C��
							if (dirArray[2]) {
								// �߂荞�ݗʂ��v�Z����
								int overlap = Bx + Bw - Ax;
								c_player.SetNextPosX(Ax + overlap);
							}

							// �E�����̏C��
							if (dirArray[3]) {
								// �߂荞�ݗʂ��v�Z����
								int overlap = Ax + Aw - Bx;
								c_player.SetNextPosX(Ax - overlap);
							}
						}
					}
				}
			}
		}
	}
}