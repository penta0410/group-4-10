#pragma once
#include "../Scene/SceneManager/SceneManager.h"

//デバッグマネージャークラス
class DebugManager
{
private:

	//デバッグフラグ
	bool m_DebugFlag;

public:

	
	//コンストラクタ・デストラクタ
	DebugManager();
	~DebugManager();

	//初期化
	void Init();

	//描画処理
	void Draw();

	//通常処理
	void Step();

};