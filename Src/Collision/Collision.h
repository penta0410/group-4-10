
#ifndef __COLLISION_H__
#define __COLLISION_H__

// �~�̓����蔻��
// xy���W�͒��S���W
bool IsHitCircle(float x1, float y1, float r1, float x2, float y2, float r2);

// ��`�̓����蔻��
// xy���W�͍���̍��W
bool IsHitRect(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);

#endif
