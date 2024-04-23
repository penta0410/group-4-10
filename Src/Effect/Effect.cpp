
#include <DxLib.h>
#include "Effect.h"
#include "../Common.h"



//�G�t�F�N�g�̓ǂݍ���
//����	�F�t�@�C���p�X, �G�t�F�N�g���, �A�j������, ���摜��, �c�摜��, ������̉��T�C�Y, ������̏c�T�C�Y
void EffectInfo::LoadEffect(EFFECT_TYPE type, int create_num)
{
	for (int create_index = 0; create_index < create_num; create_index++)
	{
		for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
		{
			//�ǂݍ��݂��Ă��Ȃ��G�t�F�N�g����������
			//�i�ЂƂڂ̉摜�n���h�����[���Ȃ�ǂݍ��݂���ĂȂ��j
			if (effectInfo[effect_index].handle[0] == 0)
			{
				//�摜�𕪊��ǂݍ���
				int success_flg = LoadDivGraph(effectFilePath[type],
					effectAnimeImgNum[type],
					effectImageSplitNum[type][0],
					effectImageSplitNum[type][1],
					effectImageSize[type][0],
					effectImageSize[type][1],
					effectInfo[effect_index].handle);

				//��������

				if (success_flg == 0)
				{
					//�A�j�������i�[
					effectInfo[effect_index].animeNum = effectAnimeImgNum[type];

					//�P��������̕\�����Ԃ�ݒ�
					effectInfo[effect_index].changeTime = effectChageTime[type];

					//�G�t�F�N�g�̎�ނ�ݒ�
					effectInfo[effect_index].effectType = type;
				}

				//���ۂɂ�����炸������
				break;
			}
		}
	}
}

//�G�t�F�N�g�̏�����
void EffectInfo::InitEffect()
{
	//���ׂẴG�t�F�N�g���̕ϐ����N���A����i�[���ɂ���j
	for(int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		for(int anime_index = 0; anime_index < EFFECT_ANIME_MAX_NUM; anime_index++)
			effectInfo[effect_index].handle[anime_index] = 0;

		effectInfo[effect_index].x = effectInfo[effect_index].y = 0;
		effectInfo[effect_index].isUse = false;
		effectInfo[effect_index].animeNum = 0;
		effectInfo[effect_index].currentAnimeIndex = 0;
		effectInfo[effect_index].changeTime = 0.0f;
		effectInfo[effect_index].currentChangeTime = 0.0f;
	}
}

//�G�t�F�N�g�ʏ폈��
void EffectInfo::StepEffect()
{
	for(int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//�g�p���Ȃ�A�j�����Ԃ��o�߂����āA�A�j���ԍ����X�V����
		if(effectInfo[effect_index].isUse == true)
		{
			//�摜�؂�ւ��ɕK�v�Ȏ��Ԍo�߂�����
			if(effectInfo[effect_index].currentChangeTime >= effectInfo[effect_index].changeTime)
			{
				effectInfo[effect_index].currentAnimeIndex++;		//���̉摜��
				effectInfo[effect_index].currentChangeTime = 0.0f;	//�v�����ԃ��Z�b�g

				//���̉摜�����������Ȃ�
				if(effectInfo[effect_index].currentAnimeIndex >= effectInfo[effect_index].animeNum)
				{
					//�g�p���t���O��OFF��
					effectInfo[effect_index].isUse = false;

					//�ȉ��̏����͕s�v
					continue;
				}
			}

			//���ԍX�V
			effectInfo[effect_index].currentChangeTime += 1.0f / FRAME_RATE;
		}
	}
}

//�G�t�F�N�g�`�揈��
void EffectInfo::DrawEffect()
{
	for(int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//�g�p���Ȃ猻�݂̃A�j���ԍ��ŕ`�悷��
		if(effectInfo[effect_index].isUse == true)
		{
			DrawRotaGraph(effectInfo[effect_index].x, 
						  effectInfo[effect_index].y,
						  1.0,
						  0.0, 
						  effectInfo[effect_index].handle[effectInfo[effect_index].currentAnimeIndex],
						  true
						  );
		}
	}
}

//�G�t�F�N�g�`��i���]�j����
void EffectInfo::DrawTurnEffect()
{
	for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//�g�p���Ȃ猻�݂̃A�j���ԍ��ŕ`�悷��
		if (effectInfo[effect_index].isUse == true)
		{
			DrawTurnGraph(effectInfo[effect_index].x,
				effectInfo[effect_index].y,
				effectInfo[effect_index].handle[effectInfo[effect_index].currentAnimeIndex],
				true
			);
		}
	}
}
//�G�t�F�N�g�̌㏈��
void EffectInfo::FinEffect()
{
	//���ׂẴG�t�F�N�g���폜����
	for(int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//���ׂč폜����
		for(int anime_index = 0; anime_index < EFFECT_ANIME_MAX_NUM; anime_index++)
		{
			//�[���ȊO�Ȃ�폜����
			if(effectInfo[effect_index].handle[anime_index] != 0)
			{
				//�摜�폜
				DeleteGraph(effectInfo[effect_index].handle[anime_index]);

				//�폜������[�������Ă���
				effectInfo[effect_index].handle[anime_index] = 0;
			}
		}
	}
}

//�G�t�F�N�g�̍Đ�
//����	�F�G�t�F�N�g�̎��, �w���W, �x���W, �P��������̕\������
void EffectInfo::PlayEffect(EFFECT_TYPE type, float x, float y)
{
	//���g�p�G�t�F�N�g��T���čĐ�
	for(int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//�g�p���Ȃ�ȉ��s��Ȃ�
		if(effectInfo[effect_index].isUse == true)
			continue;

		//�^�C�v����v����
		if(effectInfo[effect_index].effectType == type)
		{
			effectInfo[effect_index].x = x;	//���W�ݒ�
			effectInfo[effect_index].y = y;

			//�v���p�̕ϐ����N���A
			effectInfo[effect_index].currentAnimeIndex = 0;
			effectInfo[effect_index].currentChangeTime = 0.0f;

			effectInfo[effect_index].isUse = true;	//�g�p���ɂ���

			break;	//������
		}
	}
}

