#include "DxLib.h"
#include "Transparent.h"

//初期化
int Flag = true;

//透過関数
int Transparent(int alpha, int speed)
{
	//透過処理
	//BottanAlphaFlagがtrueの時に透過する
	if (Flag)
	{
		alpha -= speed;
		
		//BottanAlphaが0以下の時BottanAlphaFlagをfalseにする
		if (alpha <= 0)
		{
			Flag = false;
		}
	}
	//BottanAlphaFlagがfalseの時に通常に戻す
	if (!Flag)
	{
		alpha += speed;

		//BottanAlphaが100以上の時BottanAlphaFlagをtrueにする
		if (alpha >= 100)
		{
			Flag = true;
		}
		
	}
	return alpha;
	
}
