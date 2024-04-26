#include "Map.h"
#include "DxLib.h"
#include <string.h>

const int MAX_DATA_LEN = 256;
Map::Map() {}
Map::~Map() {}

void Map::Init() {
	// �摜�̓ǂݍ���
	imgHundle[MAPCHIP_BLOCK] = LoadGraph("Data/Play/�u���b�N.png");		//�u���b�N
	imgHundle[MAPCHIP_COIN] = LoadGraph("Data/Play/coin.png");	//�R�C��
	imgHundle[MAPCHIP_TRAP] = LoadGraph("Data/Play/�g�Q.png");	//�g���b�v
	imgHundle[MAPCHIP_HEART] = LoadGraph("Data/Play/heart.png");	//�n�[�g

	ReadFile();
	isReadFile = true;
	
	//�}�b�v�ړ���
	m_Map_Move_x = 0;

	//�t�@�C���P�ǂݍ��ݏI���t���O
	ReadFileFlag_1 = 0;
	
}

void Map::Draw() {

	for (int y = 0; y < MAP_DATA_Y; y++)
	{
		for (int x = 0; x < MAP_DATA_X; x++)
		{
			// �u���b�N��`��
			if (isReadFile) {
				int mapchipType = m_FileReadMapData[y][x];
				if (m_FileReadMapData[y][x] != MAPCHIP_NONE) {

					//�}�b�v�X�N���[��
					move = x * MAP_SIZE - m_Map_Move_x;

					DrawGraph(move, y * MAP_SIZE, imgHundle[mapchipType], true);
				
				}
			}
		}
	}
}

//�ʏ폈��
void Map::Step()
{
	//�}�b�v�ړ�
	m_Map_Move_x += MAP_SPEED;

	//�}�b�v���B�x����
	MapReachLevel();

}

// �t�@�C������̓ǂݍ���
void Map::ReadFile() {


	FILE* fp;
	fopen_s(&fp, "Data/Play/map.csv", "r");

	int mapIndexX = 0;
	int mapIndexY = 0;

	while (true) {
		// ���l������ǂݍ���
		fscanf_s(fp, "%d", &m_FileReadMapData[mapIndexY][mapIndexX]);
		mapIndexX++;

		// �u,�v���΂����߂ɓǂݍ��݂����s
		char map = fgetc(fp);

		// EOF�̏ꍇ�͓ǂݍ��ݏI��
		if (map == EOF)
		{
			break;
		}

		// ���s�R�[�h�̏ꍇ�͕ۑ����ύX����
		if (map == '\n')
		{
			mapIndexY++;
			mapIndexX = 0;
		}
	}
}

//�}�b�v���B�x����
void Map::MapReachLevel()
{

}