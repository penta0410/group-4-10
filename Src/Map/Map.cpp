#include "Map.h"
#include "DxLib.h"
#include <string.h>

const int MAX_DATA_LEN = 256;
Map::Map() {}
Map::~Map() {}

void Map::Init() {
	// �摜�̓ǂݍ���
	imgHundle[MAPCHIP_BLOCK] = LoadGraph("Data/Play/�}1.png");		//�y�u���b�N
	imgHundle[MAPCHIP_KUSA] = LoadGraph("Data/Play/�}2.png");		//���u���b�N
	imgHundle[MAPCHIP_HAKO] = LoadGraph("Data/Play/�}51.png");	//�ؔ�
	imgHundle[MAPCHIP_COIN] = LoadGraph("Data/Play/coin.png");	//�R�C��
	imgHundle[MAPCHIP_TRAP] = LoadGraph("Data/Play/Trap.png");	//�g���b�v
	imgHundle[MAPCHIP_HEART] = LoadGraph("Data/Play/heart.png");	//�n�[�g

	ReadFile();
	isReadFile = true;
	
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
					move = x * MAP_SIZE - MAP_SPEED;
					if (m_FileReadMapData[y][x] != MAPCHIP_COIN)
					{
						if (m_FileReadMapData[y][x] != MAPCHIP_TRAP)
						{
							if (m_FileReadMapData[y][x] != MAPCHIP_HEART)
							{
								DrawGraph(move, y * MAP_SIZE, imgHundle[mapchipType], true);
							}
						}
					}

					//�R�C��
					if (m_FileReadMapData[y][x] == MAPCHIP_COIN)
					{
						DrawGraph(move, y * MAP_SIZE, imgHundle[mapchipType], true);
					}

					//�n�[�g
					if (m_FileReadMapData[y][x] == MAPCHIP_HEART)
					{
						DrawGraph(move, y * MAP_SIZE, imgHundle[mapchipType], true);
					}

					//�g���b�v
					if (m_FileReadMapData[y][x] == MAPCHIP_TRAP)
					{
						DrawGraph(move, y * MAP_SIZE, imgHundle[mapchipType], true);
					}

				}
			}
		}
	}
}

//�ʏ폈��
void Map::Step()
{

}

//�R�C���ʏ폈��
void Map::CoinStep(int x, int y)
{
	if (m_FileReadMapData[y][x] == 7)
	{
		m_FileReadMapData[y][x] = -1;
	}
}

//�n�[�g�ʏ폈��
void Map::HeartStep(int x, int y)
{
	if (m_FileReadMapData[y][x] == 9)
	{
		m_FileReadMapData[y][x] = -1;
	}
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

