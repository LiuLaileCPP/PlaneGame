#include"CGuncommon.h"
#include"../config/Config.h"
#include<easyx.h>
#include <graphics.h> 
#include <cmath>

void CGuncommon::InitGun(int x, int y)
{
	type = 0;
	m_x = x;
	m_y = y;
	/*m_x1 = x;
	m_y1 = y;*/
	
	::loadimage(&m_imgGun, L"./res/gunner.jpg");
	/*::loadimage(&m_imgGun, L"./res/gunner.jpg");*/
}
void CGuncommon::ShowGun()
{

	::putimage(m_x, m_y,/*Ŀ���λ��*/ GUNNER_WIDTH, GUNNER_HEIGHT,/*��ʾԭͼ�Ĵ�С*/
		&m_imgGun/*��ʾͼƬ*/, GUNNER_WIDTH, 0,/*��ͼƬ���ĸ�λ�ÿ�ʼ��ʾ*/SRCPAINT/*���䷽ʽ*/);
	::putimage(m_x, m_y, GUNNER_WIDTH, GUNNER_HEIGHT,
		&m_imgGun, 0, 0, SRCAND);
	//::putimage(m_x1, m_y,/*Ŀ���λ��*/ GUNNER_WIDTH, GUNNER_HEIGHT,/*��ʾԭͼ�Ĵ�С*/
	//	&m_imgGun/*��ʾͼƬ*/, GUNNER_WIDTH, 0,/*��ͼƬ���ĸ�λ�ÿ�ʼ��ʾ*/SRCPAINT/*���䷽ʽ*/);
	//::putimage(m_x1, m_y, GUNNER_WIDTH, GUNNER_HEIGHT,
	//	&m_imgGun, 0, 0, SRCAND);
}
void CGuncommon::MoveGun()
{
	m_y -= GUNNER_MOVE_STEP;
}