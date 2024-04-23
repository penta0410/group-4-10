
#ifndef __EFFECT_H__
#define __EFFECT_H__

//�G�t�F�N�g�̎��
enum EFFECT_TYPE
{
	EFFECT_TYPE_EXPLOSION = 0,	//����
	EFFECT_TYPE_RECOVERY,		//��
	EFFECT_TYPE_SHINE,			//�L���L��

	EFFECT_TYPE_NUM,
};

//��x�ɕ\���ł���G�t�F�N�g�ő吔
#define EFFECT_MAX_NUM		(4)

//�G�t�F�N�g�̃A�j���ő吔
#define EFFECT_ANIME_MAX_NUM	(4)	

//�G�t�F�N�g���
struct EffectInfo
{
	EFFECT_TYPE	effectType;	//�G�t�F�N�g�̎��

	int	handle[EFFECT_ANIME_MAX_NUM];	//�摜�n���h��

	int x, y;		//���W
	bool isUse;		//�g�p�t���O

	int animeNum;			//�A�j����
	int currentAnimeIndex;	//���݂̃A�j���ԍ�

	float changeTime;		//�P��������̕\������
	float currentChangeTime;	//���݂̃A�j������

	
	//�G�t�F�N�g�̓ǂݍ���
	//����	�F�t�@�C���p�X, �G�t�F�N�g���, �A�j������, ���摜��, �c�摜��, ������̉��T�C�Y, ������̏c�T�C�Y
	void LoadEffect(EFFECT_TYPE type, int create_num);

	//�G�t�F�N�g�̏�����
	void InitEffect();

	//�G�t�F�N�g�ʏ폈��
	void StepEffect();

	//�G�t�F�N�g�`�揈��
	void DrawEffect();

	//�G�t�F�N�g�`��i���]�j����
	void DrawTurnEffect();

	//�G�t�F�N�g�̌㏈��
	void FinEffect();

	//�G�t�F�N�g�̍Đ�
	//����	�F�G�t�F�N�g�̎��, �w���W, �x���W, �P��������̕\������
	void PlayEffect(EFFECT_TYPE type, float x, float y);

};

//�G�t�F�N�g���
static EffectInfo effectInfo[EFFECT_MAX_NUM];

//�G�t�F�N�g�̃t�@�C���p�X
const char effectFilePath[EFFECT_TYPE_NUM][256] =
{
	"Data/Effect/EffectExplosion.png",
	"Data/Effect/EffectRecovery.png",
	"Data/Effect/Shine.png",

};

//�e�G�t�F�N�g�̃A�j����
const int effectAnimeImgNum[EFFECT_TYPE_NUM] =
{
	4,	//EFFECT_TYPE_EXPLOSION
	3,	//EFFECT_TYPE_RECOVERY
	3,  //EFFECT_TYPE_SHINE

};

//�e�G�t�F�N�g�̉摜������ [0] = x, [1] = y
const int effectImageSplitNum[EFFECT_TYPE_NUM][2] =
{
	{ 2, 2,},	//EFFECT_TYPE_EXPLOSION
	{ 2, 2,},	//EFFECT_TYPE_RECOVERY
	{ 3, 1,},	//EFFECT_TYPE_SHINE

};

//�G�t�F�N�g�̉摜�T�C�Y
const int effectImageSize[EFFECT_TYPE_NUM][2] =
{
	{64, 64,},	//EFFECT_TYPE_EXPLOSION
	{32, 32,},	//EFFECT_TYPE_RECOVERY
	{64, 64,},	//EFFECT_TYPE_SHINE

};

//�e�G�t�F�N�g�̃A�j���摜�؂�ւ�����
const float effectChageTime[EFFECT_TYPE_NUM] =
{
	0.05f,	//EFFECT_TYPE_EXPLOSION
	0.1f,	//EFFECT_TYPE_RECOVERY
	0.1f,	//EFFECT_TYPE_SHINE

};



class Effect
{


public:

	
	
};

#endif
