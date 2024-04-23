#pragma once

#include "DxLib.h"
#include "../Input/Input.h"
#include "../Screen/Screen.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Enemy/Enemy.h"

const int PLAYER_IMAGE_NUM = 12;										//画像の配列の数
const int GRAVITY = 1.0;

//プレイヤーアニメーション種類
enum PlayerAnimationType {

	PLAYER_ANIMATION_TYPE_RUN = 0,
	PLAYER_ANIMATION_TYPE_JUMP,
	PLAYER_ANIMATION_TYPE_MIDAIR,
	PLAYER_ANIMATION_TYPE_FALL,
	PLAYER_ANIMATION_TYPE_LANDING,
	
	PLAYER_ANIMATION_TYPE_MAX,
};

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

	//画像ハンドル
	int m_ImageHandle[PLAYER_IMAGE_NUM];

	//プレイヤーのHP
	int m_HP;

	//プレイヤー移動フラグ
	int m_PlayerMoveFlag;

	//描画フラグ
	int m_drawflag;

	//マウス座標
	int m_Mouse_x;	//ｘ座標
	int m_Mouse_y;	//y座標

	//プレイヤー無敵フラグ
	bool PlayerInviFlag;

	//プレイヤー無敵フレーム
	int PlayerInviFlame;

	//プレイヤー透過処理
	int m_alpha;

	int m_AnimationFreamCnt = 0;

	int m_Animation_Num = 0;

	//プレイヤーアニメーション種類
	PlayerAnimationType now_animation;

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
	void Step(int flag);

	//描画処理
	void Draw(int flag);

	//終了処理
	void Fin();

	//操作処理
	void Control();

	//アニメーション
	void Animation();

	//Hp取得
	int GetHp() { return m_HP; }
	//Hｐセット
	void SetHp(int hp);

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

	//プレイヤー落下前チェック
	void StepPlayerMidAir();

	//プレイヤー落下更新
	void StepPlayerFall();

	//プレイヤー着地処理
	void PlayerLanding();

	//プレイヤーがジャンプ可能かどうか
	bool CanJumpPlayer();

	//プレイヤーが空中状態かどうか
	bool IsAirPlayer();

	//プレイヤー無敵かどうか
	bool PlayerInvincible();

	//Hp描画
	void DrawHp();

	//プレイヤー死亡したかどうか
	bool DeathPlayer();

	//プレイヤー回復処理
	void PlayerHeal();

	//プレイヤー無敵処理
	void StepInvincible();
};





