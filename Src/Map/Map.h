#pragma once
#include "../Screen/Screen.h"
#include "../Player/Player.h"

// �e�}�b�v�̃f�[�^��
const int MAP_DATA_Y = 20;
const int MAP_DATA_X = 1000;

// �}�b�v�T�C�Y
const int MAP_SIZE = 56;

//�g���b�v�_���[�W
const int TRAP_DAMAGE = 10;

//�}�b�v�X�s�[�h
const int MAP_SPEED = 4;

// �}�b�v�`�b�v�摜�ꗗ
enum MapChipType {
	MAPCHIP_NONE = -1,

	MAPCHIP_BLOCK,
	MAPCHIP_KUSA,
	MAPCHIP_HAKO,
	MAPCHIP_COIN,
	MAPCHIP_TRAP,
	MAPCHIP_HEART,

	MAPCHIP_MAX
};

// �}�b�v�N���X
class Map
{
private:

	Screen m_screen;
	Player player;

	// �摜�n���h��
	int imgHundle[MAPCHIP_MAX];

	int move = 0;

public:
	Map();
	~Map();

	//�t�@�C���ǂݍ��݃t���O
	bool isReadFile;

	//�t�@�C������̃}�b�v�f�[�^
	int m_FileReadMapData[MAP_DATA_Y][MAP_DATA_X] = { 0 };

	//�t�@�C���P�ǂݍ��ݏI���t���O
	int ReadFileFlag_1 = 0;
	
	//������
	void Init();

	//�ʏ폈��
	void Step();

	//�`��
	void Draw();

	//�t�@�C������̓ǂݍ���
	void ReadFile();

	//�R�C���ʏ폈��
	void CoinStep(int x, int y);

	//�n�[�g�ʏ폈��
	void HeartStep(int x, int y);
	
};

