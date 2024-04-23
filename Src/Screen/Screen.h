
#ifndef __SCREEN_H__
#define __SCREEN_H__


class Screen
{
private:

	int m_player_x = 0;
	int m_player_y = 0;

	float m_screenX = 0;
	float m_screenY = 0;

public:

	Screen();
	~Screen();

	//�X�N���[���̃X�e�b�v
	void StepScreen(int x);

	//�X�N���[���̂w���W���擾
	float GetScreenX();

	//�X�N���[���̂x���W���擾
	float GetScreenY();
};

#endif
