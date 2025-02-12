#pragma once
#include "../Screen/Screen.h"
#include "../Player/Player.h"

// 各マップのデータ数
const int MAP_DATA_Y = 20;
const int MAP_DATA_X = 1000;

// マップサイズ
const int MAP_SIZE = 60;

//トラップダメージ
const int TRAP_DAMAGE = 10;

//マップスピード
const int MAP_SPEED = 5;

////マップゴール地点
//const int MAP_COAL = ;

// マップチップ画像一覧
enum MapChipType {
	MAPCHIP_NONE = -1,

	MAPCHIP_BLOCK,
	MAPCHIP_COIN,
	MAPCHIP_TRAP,
	MAPCHIP_HEART,

	MAPCHIP_MAX,
};

// マップクラス
class Map
{
private:

	Screen m_screen;
	Player player;

	// 画像ハンドル
	int imgHundle[MAPCHIP_MAX];

	int move = 0;

	//マップ移動量
	int m_Map_Move_x;

public:

	Map();
	~Map();

	//ファイル読み込みフラグ
	bool isReadFile;

	//ファイルからのマップデータ
	int m_FileReadMapData[MAP_DATA_Y][MAP_DATA_X] = { 0 };

	//ファイル１読み込み終了フラグ
	int ReadFileFlag_1 = 0;
	
	//初期化
	void Init();

	//通常処理
	void Step();

	//描画
	void Draw();

	//ファイルからの読み込み
	void ReadFile();

	//マップ到達度処理
	void MapReachLevel();

	//ゲットマップ移動
	int GetMapMove() { return m_Map_Move_x; };

};

