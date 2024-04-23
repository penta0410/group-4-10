
#include "DxLib.h"
#include "Scene/Scene.h"
#include "Common.h"
#include "FPS/fps.h"
#include "Input/Input.h"
#include "Scene/SceneManager/SceneManager.h"

//フレームレート情報変数
FrameRateInfo frameRateInfo;

SceneManager c_scene_manager;			//シーンマネージャークラス宣言

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(true);
	//ウィンドウサイズを変更
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);

	//DXライブラリの初期化
	if(DxLib_Init() == -1)
	{
		return -1;
	}

	//描画するスクリーンを設定
	SetDrawScreen(DX_SCREEN_BACK);
	//入力制御初期化
	InitInput();

	//シーンマネージャー初期化
	c_scene_manager.InitScene();

	//=====================================
	//ゲームメインループ
	while(ProcessMessage() != -1)
	{
		Sleep(1);	//システムに処理を返す
		//現在の時間を取得
		frameRateInfo.currentTime = GetNowCount();

		//最初のループなら
		//現在の時間を、FPSの計算をした時間に設定
		if (frameRateInfo.calcFpsTime == 0.0f)
		{
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
			frameRateInfo.fps = (float)FRAME_RATE;
		}

		// 現在の時間が、前回のフレーム時より
		// 1000/60ミリ秒（1/60秒）以上経過していたら処理を実行する
		if (frameRateInfo.currentTime - frameRateInfo.lastFrameTime >= FRAME_TIME)
		{
			//フレーム実行時の時間を更新
			frameRateInfo.lastFrameTime = frameRateInfo.currentTime;
			//フレーム数をカウント
			frameRateInfo.count++;

			if (IsKeyPush(KEY_INPUT_ESCAPE))
			{
				//エスケープキーが押されたら終了
				break;
			}

			//画面に表示されたものを初期化（１ループの１度だけ行う）
			ClearDrawScreen();
			//入力制御ステップ
			StepInput();

			//ゲームメイン処理==========================
			//シーンマネージャーループ
			c_scene_manager.LoopScene();
			//===================================
			
			//FPS計算
			CalcFPS();
			//FPS表示
			DrawFPS();
			//フリップ関数（ループの終わりに１度だけ行う）
			ScreenFlip();

		}//フレームレートのif文終わり

	}//メインループの終わり
	//最後に１回だけやる処理をここに書く
	//DXライブラリの後処理
	
	//シーンマネージャー終了
	c_scene_manager.FInScene();

	DxLib_End();

	return 0;
}
