#pragma once

#include "Player.h"
#include "../Map/Map.h"
#include "../Transparent/Transparent.h"

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

	//画像ハンドル
	memset(m_ImageHandle, -1, sizeof(m_ImageHandle));

	//HP
	m_HP = 0;

	//プレイヤー無敵フラグ
	PlayerInviFlag = false;

	//プレイヤー無敵フレーム
    PlayerInviFlame = 0;

	//プレイヤー透過処理
	m_alpha = 0;

}

//読み込み処理
void Player::Load()
{
	
}

//初期値設定処理
void Player::DefaultValue()
{
	
}

//通常処理
void Player::Step(int flag)
{
	
	
}

//描画処理
void Player::Draw(int flag)
{
	

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
		if (CanJumpPlayer() == true)
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

//落下前チェック
void Player::StepPlayerMidAir()
{
	//ジャンプ頂上に到達する２フレーム前にアニメーションを再生する
	if (state == PLAYER_STATE_JUMP && m_move_y > -GRAVITY * 2)
	{
		//空中状態に変更
		state = PLAYER_STATE_MIDAIR;
	}
}

//落下更新
void Player::StepPlayerFall()
{
	//落下し始めて５フレーム後に落下状態にする
	if (m_move_y > GRAVITY * 5)
	{
		//落下状態に変更
		state = PLAYER_STATE_FALL;
	}
}

//着地処理
void Player::PlayerLanding()
{
	//ｙの移動量をリセット
	m_move_y = 0.0f;

	//待機状態に戻す
	if (IsAirPlayer())
	{
		//状態に変更
		state = PLAYER_STATE_RUN;
	}
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

//Hｐセット
void Player::SetHp(int hp)
{
	m_HP = hp;
}

//プレイヤー無敵かどうか
bool Player::PlayerInvincible()
{
	//プレイヤー無敵フレーム
	PlayerInviFlame++;

	//プレイヤー無敵
	PlayerInviFlag = true;

	//1秒たったら無敵解除
	if (PlayerInviFlame > 120)
	{
		//プレイヤー無敵出ない
		PlayerInviFlag = false;

		//フレーム初期化
		PlayerInviFlame = 0;
	}

	return PlayerInviFlag;
}

//Hp描画
void Player::DrawHp()
{
	DrawBox(m_posX - 13, m_posY - 33, m_posX + 53, m_posY - 30, GetColor(255, 255, 255), true);
	DrawBox(m_posX - 10, m_posY - 30, m_posX + m_HP / 2 , m_posY - 20, GetColor(0, 255, 0), true);
	DrawBox(m_posX - 13, m_posY - 20, m_posX + 53, m_posY - 17, GetColor(255, 255, 255), true);
	DrawBox(m_posX - 13, m_posY - 33, m_posX - 10, m_posY - 17, GetColor(255, 255, 255), true);
	DrawBox(m_posX + 50, m_posY - 33, m_posX + 53, m_posY - 17, GetColor(255, 255, 255), true);

}

//プレイヤー死亡処理
bool Player::DeathPlayer()
{
	if (m_HP > -20)
	{
		return false;
	}
	else if (m_HP <= -20)
	{
		return true;
	}
}

//プレイヤー回復処理
void Player::PlayerHeal()
{
	m_HP += 10;
}

//プレイヤー無敵処理
void Player::StepInvincible()
{
	//プレイヤーが無敵だったら
	if (PlayerInvincible() == true)
	{
		
	}
}