#pragma once

enum BGM_TYPE
{	
	//���y
	BGM_TITLE,	//�^�C�g�����
	BGM_PLAY,	//�v���C���
	BGM_RESULT,	//���U���g���

	BGM_MAX_NUM
};

enum SE_TYPE
{
	SE_SYSTEM,		//�V�X�e��
	SE_CLICK_PANEL,	//�p�l���N���b�N
	SE_CLEAR,		//����
	SE_MISS,		//�s����
	SE_DAMAGE,		//�_���[�W

	SE_MAX_NUM
};

class Sound
{
public:
	//�T�E���h�܂Ƃߏ�����
	static void Init();

	class Bgm
	{
	private:
		//���n���h��
		static int handle[BGM_MAX_NUM];

	public:
		//BGM�̏�����
		static void Init();

		//BGM�̒ʏ폈���F���
		static void Play(int type);
		//BGM�̉��ʒ��߁F���,����(�߰��ð��)
		static void SetVolume(int type,int volume);
		//BGM�̒�~�F���
		static void StopSound(int type);
	};

	class Se
	{
	private:
		//���n���h��
		static int handle[SE_MAX_NUM];

	public:
		//SE�̏�����
		static void Init();

		//SE�̒ʏ폈���F���
		static void Play(int type);
		//SE�̉��ʒ��߁F���,����(�߰��ð��)
		static void SetVolume(int type,int volume);
	};
};


/*�g�����w��
	//Fin�Ŏg��
	DeleteSoundMem(�Z�Z�Z);
	//�S�폜
	InitSoundMem();

	//BGM�̒�~
	StopSoundMem(Hundle);

	//���ʂ̐ݒ�i0�`255�j�i����80���̉��ʂŏo�́j
	ChangeVolumeSoundMem( 255 * 80 / 100, Handle );

	//���ʉ��̍Đ�
	PlaySoundMem(Hundle, DX_PLAYTYPE_BACK, true);
	//BGM�̍Đ�
	PlaySoundMem(Hundle, DX_PLAYTYPE_LOOP, true);
*/