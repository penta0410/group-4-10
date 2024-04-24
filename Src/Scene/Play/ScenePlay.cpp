#pragma once
#include "ScenePlay.h"
#include "../SceneManager/SceneManager.h"

//=============================
// プレイシーン
//=============================

//初期化
void Play::Init()
{
	//マップ初期化
	c_map.Init();
	//プレイヤー初期化
	c_player.Init();

	//背景座標
	m_BG_x[0] = WINDOW_WIDTH / 2;		//背景１
	m_BG_x[1] = WINDOW_WIDTH + (WINDOW_WIDTH / 2);		//背景２
	m_BG_y = WINDOW_HEIGHT / 2;

	//背景移動量
	m_BG_move_x = 0;











	//用意した画像枚数だけ
	for (int i = 0; i < PLAY_IMAGE_PATH_NUM; i++)
	{
		m_ImageHandle[i] = -1;
	}
}

//ロード
void Play::Load()
{
	//用意した画像枚数だけ
	for (int i = 0; i < PLAY_IMAGE_PATH_NUM; i++)
	{
		m_ImageHandle[i] = LoadGraph(PLAY_PATH[i]);
	}
}

//通常処理
void Play::Step()
{	
	
	//プレイヤーが生きている時だけ処理を行う死んだらストップ
	if (c_player.DeathPlayer() == false)
	{
		//マップ通常処理
		c_map.Step();

		//背景スクロール処理
		BGScroll();

		//マップ当たり判定
		MapCollision(BGScroll());

	}
	//シーンへの遷移
	//エンター押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		
		//後処理へ移動
		SceneManager::g_CurrentSceneStateID = SCENE_STATE_ID::SCENE_ID_FIN;
	}
	
}

//描画処理
void Play::Draw()
{
	//背景描画
	DrawRotaGraph(m_BG_x[0], m_BG_y, 1.0f, 0.0f, m_ImageHandle[0], true);
	DrawRotaGraph(m_BG_x[1], m_BG_y, 1.0f, 0.0f, m_ImageHandle[1], true);

	//マップ描画
	c_map.Draw();
	
	//デバッグ

}

//後処理
void Play::Fin()
{
	//プレイヤー終了処理
	c_player.Fin();

	//リザルトへ移動
	SceneManager::g_CurrentSceneID = SCENE_ID::SCENE_ID_RESULT;
}

//背景スクロール処理
int Play::BGScroll()
{
	//背景スクロール処理
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

//マップの当たり判定
void Play::MapCollision(int mapmove)
{
	//プレイヤー
	//Y方向のみ当たり判定をチェックする
	for (int mapIndexY = 0; mapIndexY < MAP_DATA_Y; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAP_DATA_X; mapIndexX++)
		{
			//ブロック以外は処理しない
			if (c_map.m_FileReadMapData[mapIndexY][mapIndexX] == MAPCHIP_NONE)
			{
				continue;
			}

			//どの方向に進んでいたかチェック
			bool dirArray[4] = { false,false,false,false };
			c_player.GetMoveDirection(dirArray);

			//矩形の当たり判定用のデータを準備
			//プレイヤーの情報
			int Ax = c_player.GetPosX() - 20;
			int Ay = c_player.GetPosY() - 10;
			int Aw = PLAYER_SIZE;
			int Ah = PLAYER_SIZE;

			//オブジェクトの情報
			int Bx = mapIndexX * MAP_SIZE + 20 - mapmove;
			int By = mapIndexY * MAP_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE + 10;

			//Y方向のみに移動したと仮定した座標で当たり判定をチェックします
			Ay = c_player.GetNextPosY();
			Ax = c_player.GetNextPosX();

			//当たっているかチェック
			if (IsHitRect(Ax + mapmove, Ay, Aw, Ah, Bx + mapmove, By, Bw, Bh)) {

				if (c_map.m_FileReadMapData[mapIndexY][mapIndexX] != 7)
				{
					if (c_map.m_FileReadMapData[mapIndexY][mapIndexX] != 8)
					{
						if (c_map.m_FileReadMapData[mapIndexY][mapIndexX] != 9)
						{
							// 上方向の修正
							if (dirArray[0]) {
								// めり込み量を計算する
								int overlap = By + Bh - Ay;
								c_player.SetNextPosY(Ay + overlap);

								//天井についたら押し返す
								c_player.PlayerCeiling();

							}
							//下方向の修正
							if (dirArray[1]) {
								// めり込み量を計算する
								int overlap = Ay + Ah - By;
								c_player.SetNextPosY(Ay - overlap);

								//落下したら
								c_player.PlayerLanding();

							}
						}
					}
				}
			}
		}
	}

	// X方向のみ当たり判定をチェックする
	for (int mapIndexY = 0; mapIndexY < MAP_DATA_Y; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAP_DATA_X; mapIndexX++)
		{
			// ブロック以外は処理しない
			if (c_map.m_FileReadMapData[mapIndexY][mapIndexX] == MAPCHIP_NONE)
				continue;

			//どの方向に進んでいたかチェック
			bool dirArray[4] = { false,false,false,false };
			c_player.GetMoveDirection(dirArray);

			//プレイヤーの情報
			int Ax = c_player.GetPosX() - 20;
			int Ay = c_player.GetPosY() - 10;
			int Aw = PLAYER_SIZE;
			int Ah = PLAYER_SIZE;

			//オブジェクトの情報
			int Bx = mapIndexX * MAP_SIZE + 20 - mapmove;
			int By = mapIndexY * MAP_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE + 10;

			//X方向のみに移動したと仮定した座標で当たり判定をチェック
			Ay = c_player.GetNextPosY();
			Ax = c_player.GetNextPosX();

			// 当たっているかチェック
			if (IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {

				if (c_map.m_FileReadMapData[mapIndexY][mapIndexX] != 7)
				{
					if (c_map.m_FileReadMapData[mapIndexY][mapIndexX] != 8)
					{
						if (c_map.m_FileReadMapData[mapIndexY][mapIndexX] != 9)
						{
							// 左方向の修正
							if (dirArray[2]) {
								// めり込み量を計算する
								int overlap = Bx + Bw - Ax;
								c_player.SetNextPosX(Ax + overlap);
							}

							// 右方向の修正
							if (dirArray[3]) {
								// めり込み量を計算する
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