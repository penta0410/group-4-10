#pragma once

#include "Player.h"
#include "../Map/Map.h"
#include "../Transparent/Transparent.h"
#include "../Input/Input.h"
#include "../Common.h"

//初期化処理
void Player::Init()
{
	//座標
	m_posX = 0;			//X座標
	m_posY = 0;			//Y座標
	m_nextPosX = 0;		//移動後のX座標
	m_nextPosY = 0;		//移動後のY座標
	old_pos_x = 0;		//移動前のX座標
	old_pos_y = 0;		//移動前のY座標

	//移動量
	m_move_x = 0;		//X移動量
	m_move_y = 0;		//Y移動量

	// 回転値
	m_Rot = 0.0f;

	//画像ハンドル
	memset(&m_ImageHandle, -1, sizeof(m_ImageHandle));

	//プレイヤー無敵フラグ
	PlayerInviFlag = false;

	//プレイヤー死亡確認フラグ
	isDeath = false;

	//プレイヤー無敵フレーム
	PlayerInviFlame = 0;

	//プレイヤー透過処理
	m_alpha = 0;

	//プレイヤーアニメ−ション状態
	state = PLAYER_STATE_FALL;

	// ゲームモード
	gamemode = GAMEMODE_NORMAL;
}

//読み込み処理
void Player::Load()
{
	m_ImageHandle = LoadGraph(PLAYER_PATH);
}

//初期値設定処理
void Player::DefaultValue()
{
	//座標
	m_posX = PLAYER_SIZE * 6;	//X座標
	m_posY = PLAYER_SIZE / 2 * 2;	//Y座標
	m_nextPosX = m_posX;		//移動後のX座標
	m_nextPosY = m_posY;		//移動後のY座標
	old_pos_x = m_posX;			//移動前のX座標
	old_pos_y = m_posY;			//移動前のY座標
}

//通常処理
void Player::Step()
{
	switch (gamemode) {
	case GAMEMODE_NORMAL:
		switch (state) {
		case PLAYER_STATE_RUN:	// プレイヤーが動いている最中なら
			Control();			// 操作できる
			break;

		case PLAYER_STATE_JUMP:		// プレイヤーがジャンプ状態なら
			StepJump();				// ジャンプ処理
			break;

		case PLAYER_STATE_MIDAIR:	// プレイヤーが空中にいるなら
			PlayerMovement();		// プレイヤー移動処理
			CheckPlayerMidAir();	// プレイヤーが落下しているかチェック
			break;

		case PLAYER_STATE_FALL:		// プレイヤーが落下しているなら
			PlayerMovement();		// プレイヤー移動処理
			break;

		case PLAYER_STATE_LANDING:	// プレイヤーが着地したなら
			PlayerLanding();		// 着地処理
			break;
		}
		break;
	case GAMEMODE_SPACE:
		StepSpace();
		break;
	}
	m_nextPosY += m_move_y;

}

//描画処理
void Player::Draw()
{
	// プレイヤーの描画
	DrawRotaGraph(m_posX + (PLAYER_SIZE / 2), m_posY + (PLAYER_SIZE / 2), 1.0f, m_Rot / 180.0f * DX_PI_F, m_ImageHandle, true);

	SetFontSize(26);
	if (gamemode == GAMEMODE_NORMAL)
	{
		DrawFormatString(0, 60, GetColor(0, 100, 255), "モード：＜ノーマル＞", true);
	}
	else if (gamemode == GAMEMODE_SPACE)
	{
		DrawFormatString(0, 60, GetColor(255, 100, 0), "モード：＜スペース＞", true);
	}
	SetFontSize(16);

	//デバッグ
	//プレイヤー当たり判定（真ん中が原点のため矯正）
	//DrawBox(m_posX - (PLAYER_SIZE / 2), m_posY - (PLAYER_SIZE / 2),
	//	(m_posX - (PLAYER_SIZE / 2)) + PLAYER_SIZE,
	//	(m_posY - (PLAYER_SIZE / 2)) + PLAYER_SIZE, GetColor(255, 255, 255), true);

	////プレイヤー回転値
	//DrawFormatString(0, 80, GetColor(255, 255, 255), "%f", m_Rot);

}

//終了処理
void Player::Fin()
{
	
}

//操作処理
void Player::Control()
{
	m_nextPosX = m_posX;
	m_nextPosY = m_posY;

	//ジャンプ処理
	if (IsKeyPush(KEY_INPUT_SPACE))
	{
		if (CanJumpPlayer())
		{
			//ジャンプ状態に設定
			state = PLAYER_STATE_JUMP;
		}
	}
}

//アニメーション
void Player::Animation()
{
	//フレームカウントを加算
	m_AnimationFreamCnt++;

	//1秒たったら
	if (m_AnimationFreamCnt >= 15)
	{
		//アニメーション番号を1つ加算
		m_Animation_Num++;
		//アニメーションが反対向きにならないようにする
		if (m_Animation_Num > 8)
		{
			//アニメーションを最初に戻す
			m_Animation_Num = 6;
		}

		//アニメーション処理が終わったらフレームカウントを初期化
		m_AnimationFreamCnt = 0;
	}
}

// 進んでいる方向をチェック
// 上下左右の順になっている
void Player::GetMoveDirection(bool* _dirArray) {

	// 右方向のチェック
	if (m_nextPosX > m_posX) {
		_dirArray[3] = true;
	}

	// 左方向のチェック
	if (m_nextPosX < m_posX) {

		_dirArray[2] = true;
	}

	// 下方向のチェック
	if (m_nextPosY > m_posY) {
		_dirArray[1] = true;
	}

	// 上方向のチェック
	if (m_nextPosY < m_posY) {
		_dirArray[0] = true;
	}

}

//空中状態かどうか
bool Player::IsAirPlayer()
{
	switch (state)
	{
	case PLAYER_STATE_MIDAIR:
	case PLAYER_STATE_JUMP:
	case PLAYER_STATE_FALL:
		return true;
	}

	return false;

}

// ゲームモードを変更する
void Player::SetGamemodeNoramal()
{
	gamemode = GAMEMODE_NORMAL;
	
	
}

void Player::SetGamemodeSpace()
{
	gamemode = GAMEMODE_SPACE;
}

// 宇宙状態の通常処理
void Player::StepSpace()
{
	if (IsKeyKeep(KEY_INPUT_SPACE)) {
		m_move_y -= GRAVITY / 2;
		m_Rot -= ROTAITION_SPEED;
	}
	else {
		m_move_y += GRAVITY / 2;
		m_Rot += ROTAITION_SPEED;
	}
	if (m_Rot < 45.0f) {
		m_Rot = 45.0f;
	}
	if (m_Rot > 135.0f) {
		m_Rot = 135.0f;
	}
}

//天井処理
void Player::PlayerCeiling()
{
	//ｙの移動量をリセット
	m_move_y = 0.0f;

	if (IsAirPlayer())
	{
		//プレイヤー落下状態に変更
		state = PLAYER_STATE_FALL;
	}
}

// 重力計算処理
void Player::CalcGravity()
{
	m_move_y += GRAVITY;
}

// プレイヤー回転処理
void Player::PlayerRotation()
{
	m_Rot += ROTAITION_SPEED;

	if (m_Rot > 360.0f) {
		m_Rot = 0.0f;
	}
}

// プレイヤー移動処理
void Player::PlayerMovement()
{
	// 重力計算処理
	CalcGravity();

	// プレイヤー回転処理
	PlayerRotation();
}

//プレイヤーが落下しているかチェック
void Player::CheckPlayerMidAir()
{
	// もしYの速度がプラスなら落下している
	if (m_move_y > 0) {
		//プレイヤー落下状態に変更
		state = PLAYER_STATE_FALL;
	}
}

// ジャンプ処理
void Player::StepJump()
{
	m_move_y = -PLAYER_JUMP_POWER;	// 初期値を入れる
	state = PLAYER_STATE_MIDAIR;	// 空中にいることにする
}

//着地処理
void Player::PlayerLanding()
{
	//ｙの移動量をリセット
	m_move_y = 0.0f;
	// 回転値はその時の値によって変更
	if (m_Rot < 45.0f) {
		m_Rot = 0.0f;
	}
	else if (m_Rot < 135.0f) {
		m_Rot = 90.0f;
	}
	else if (m_Rot < 225.0f) {
		m_Rot = 180.0f;
	}
	else if (m_Rot < 315.0f) {
		m_Rot = 270.0f;
	}
	else {
		m_Rot = 0.0f;
	}

	//走っている状態に変更
	state = PLAYER_STATE_RUN;
}


//座標を更新
void Player::SetNextPosX(int _posX)
{
	m_nextPosX = _posX;
}

//座標を更新
void Player::SetNextPosY(int _posY)
{
	m_nextPosY = _posY;
}

//ジャンプ可能かどうか
bool Player::CanJumpPlayer()
{
	switch (state)
	{
	case PLAYER_STATE_JUMP:
	case PLAYER_STATE_MIDAIR:
	case PLAYER_STATE_FALL:
		return false;
	}

	return true;

}

// 座標を更新
void Player::UpdatePos() {
	m_posX = m_nextPosX;
	m_posY = m_nextPosY;
}

