#include "DxLib.h"
#include "Transparent.h"

//������
int Flag = true;

//���ߊ֐�
int Transparent(int alpha, int speed)
{
	//���ߏ���
	//BottanAlphaFlag��true�̎��ɓ��߂���
	if (Flag)
	{
		alpha -= speed;
		
		//BottanAlpha��0�ȉ��̎�BottanAlphaFlag��false�ɂ���
		if (alpha <= 0)
		{
			Flag = false;
		}
		
	}
	//BottanAlphaFlag��false�̎��ɒʏ�ɖ߂�
	if (!Flag)
	{
		alpha += speed;

		//BottanAlpha��100�ȏ�̎�BottanAlphaFlag��true�ɂ���
		if (alpha >= 100)
		{
			Flag = true;
		}
		
	}
	return alpha;
	
}
