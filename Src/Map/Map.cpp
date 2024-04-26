#include "Map.h"
#include "DxLib.h"
#include <string.h>

const int MAX_DATA_LEN = 256;
Map::Map() {}
Map::~Map() {}

void Map::Init() {
	// 画像の読み込み
	imgHundle[MAPCHIP_BLOCK] = LoadGraph("Data/Play/ブロック.png");		//ブロック
	imgHundle[MAPCHIP_COIN] = LoadGraph("Data/Play/coin.png");	//コイン
	imgHundle[MAPCHIP_TRAP] = LoadGraph("Data/Play/トゲ.png");	//トラップ
	imgHundle[MAPCHIP_HEART] = LoadGraph("Data/Play/heart.png");	//ハート

	ReadFile();
	isReadFile = true;
	
	//マップ移動量
	m_Map_Move_x = 0;

	//ファイル１読み込み終了フラグ
	ReadFileFlag_1 = 0;
	
}

void Map::Draw() {

	for (int y = 0; y < MAP_DATA_Y; y++)
	{
		for (int x = 0; x < MAP_DATA_X; x++)
		{
			// ブロックを描画
			if (isReadFile) {
				int mapchipType = m_FileReadMapData[y][x];
				if (m_FileReadMapData[y][x] != MAPCHIP_NONE) {

					//マップスクロール
					move = x * MAP_SIZE - m_Map_Move_x;

					DrawGraph(move, y * MAP_SIZE, imgHundle[mapchipType], true);
				
				}
			}
		}
	}
}

//通常処理
void Map::Step()
{
	//マップ移動
	m_Map_Move_x += MAP_SPEED;

	//マップ到達度処理
	MapReachLevel();

}

// ファイルからの読み込み
void Map::ReadFile() {


	FILE* fp;
	fopen_s(&fp, "Data/Play/map.csv", "r");

	int mapIndexX = 0;
	int mapIndexY = 0;

	while (true) {
		// 数値部分を読み込む
		fscanf_s(fp, "%d", &m_FileReadMapData[mapIndexY][mapIndexX]);
		mapIndexX++;

		// 「,」を飛ばすために読み込みを実行
		char map = fgetc(fp);

		// EOFの場合は読み込み終了
		if (map == EOF)
		{
			break;
		}

		// 改行コードの場合は保存先を変更する
		if (map == '\n')
		{
			mapIndexY++;
			mapIndexX = 0;
		}
	}
}

//マップ到達度処理
void Map::MapReachLevel()
{

}