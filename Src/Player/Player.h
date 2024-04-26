#pragma once
#include "DxLib.h"
#include "../Input/Input.h"
#include "../Screen/Screen.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Enemy/Enemy.h"

const int PLAYER_IMAGE_NUM = 12;										//画像の配列の数
const float GRAVITY = 1.0f;
const int PLAYER_SIZE = 60;
const float PLAYER_JUMP_POWER = 20.0f;
const char PLAYER_PATH[] = { "Data/Play/図2.png" };
const float ROTAITION_SPEED = 0.002f;

//プレイヤーのアニメーションの状態
enum PlayerState {
	
	PLAYER_STATE_RUN = 0,
	PLAYER_STATE_JUMP,
	PLAYER_STATE_MIDAIR,
	PLAYER_STATE_FALL,
	PLAYER_STATE_LANDING,
	
};

class Player
{
private:
	//クラス宣言
	Screen screen;

	//プレイヤーの座標
	float m_posX;
	float m_posY;

	//移動後の座標
	float m_nextPosX;
	float m_nextPosY;

	//移動前の座標
	float old_pos_x;
	float old_pos_y;

	//プレイヤー移動量
	float m_move_x;
	float m_move_y;

	// プレイヤー回転値
	float m_Rot;

	//画像ハンドル
	int m_ImageHandle;

	//プレイヤー移動フラグ
	int m_PlayerMoveFlag;

	//描画フラグ
	int m_drawflag;

	//マウス座標
	int m_Mouse_x;	//ｘ座標
	int m_Mouse_y;	//y座標

	//プレイヤー無敵フラグ
	bool PlayerInviFlag;

	//プレイヤー死亡確認フラグ
	bool isDeath;

	//プレイヤー無敵フレーム
	int PlayerInviFlame;

	//プレイヤー透過処理
	int m_alpha;

	int m_AnimationFreamCnt = 0;

	int m_Animation_Num = 0;

	//プレイヤーアニメ－ション状態
	PlayerState state;

public:

	//初期化
	void Init();
	
	//読み込み
	void Load();

	//初期値
	void DefaultValue();

	//通常処理
	void Step();

	//描画処理
	void Draw();

	//終了処理
	void Fin();

	//操作処理
	void Control();

	//アニメーション
	void Animation();
	
	// 死亡確認用
	bool GetisDeath() { return isDeath; }

	//座標取得
	float GetPosX() { return m_posX; }		//X座標
	float GetPosY() { return m_posY; }		//Y座標

	//移動後の座標を取得
	int GetNextPosX() { return m_nextPosX; }
	int GetNextPosY() { return m_nextPosY; }

	//移動後の座標を設定
	void SetNextPosX(int _posX);
	void SetNextPosY(int _posY);

	//座標を更新
	void UpdatePos();

	//進んでいる方向をチェック
	//上下左右
	void GetMoveDirection(bool* _dirArray);

	//プレイヤー天井処理
	void PlayerCeiling();

	// 重力計算処理
	void CalcGravity();

	// プレイヤー回転処理
	void PlayerRotation();

	// プレイヤー移動処理
	void PlayerMovement();

	//プレイヤーが落下しているかチェック
	void CheckPlayerMidAir();

	//プレイヤーが着地しているかチェック
	void CheckPlayerLanding();
	
	// ジャンプ処理
	void StepJump();

	//着地処理
	void PlayerLanding();

	//プレイヤーがジャンプ可能かどうか
	bool CanJumpPlayer();

	//プレイヤーが空中状態かどうか
	bool IsAirPlayer();
};