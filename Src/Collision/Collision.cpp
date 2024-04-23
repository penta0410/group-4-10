
#include "DxLib.h"
#include "Collision.h"

// �~�̓����蔻��
// x���W�Ay���W�͒��S���W
bool IsHitCircle(float x1, float y1, float r1, float x2, float y2, float r2)
{
	//�Q�̔��a�̍��v
	float sum_radius = r1 + r2;
	sum_radius *= sum_radius;

	//�~���m�̒���
	float x_len = x1 - x2;
	x_len *= x_len;

	float y_len = y1 - y2;
	y_len *= y_len;

	//�~�̓����蔻��
	if(sum_radius > x_len + y_len)
	{
		return true;
	}

	return false;
}

// ��`�̓����蔻��
// xy���W�͍���̍��W
bool IsHitRect(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
	if( x1 < x2 + w2 && x1 + w1 > x2 &&
		y1 + h1 > y2 && y1 < y2 + h2 )
	{
		return true;
	}

	return false;
}

