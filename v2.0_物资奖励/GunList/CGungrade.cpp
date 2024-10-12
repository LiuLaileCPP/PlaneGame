#include"CGungrade.h"
#include"../config/Config.h"
#include<easyx.h>
#include <graphics.h> 
#include <cmath>
void CGungrade::InitGun(int x, int y)
{
	m_x = x;
	m_y = y;
	m_x1 = x;
	m_x2 = x;
	m_x3 = x;
	m_x4 = x;
	::loadimage(&m_imgGun, L"./res/gunner.jpg");
	::loadimage(&m_imgGun, L"./res/gunner.jpg");
	::loadimage(&m_imgGun, L"./res/gunner.jpg");
	::loadimage(&m_imgGun, L"./res/gunner.jpg");
	::loadimage(&m_imgGun, L"./res/gunner.jpg");
}
void CGungrade::ShowGun()
{
	//pie(m_x, m_y, m_x, m_y - GUNNER_MOVE_STEP, PI / 180 * 60, PI / 180 * 120);

	::putimage(m_x, m_y,/*目标的位置*/ GUNNER_WIDTH, GUNNER_HEIGHT,/*显示原图的大小*/
		&m_imgGun/*显示图片*/, GUNNER_WIDTH, 0,/*从图片的哪个位置开始显示*/SRCPAINT/*传输方式*/);
	::putimage(m_x, m_y, GUNNER_WIDTH, GUNNER_HEIGHT,
		&m_imgGun, 0, 0, SRCAND);
	::putimage(m_x1/*+10*/, m_y,/*目标的位置*/ GUNNER_WIDTH, GUNNER_HEIGHT,/*显示原图的大小*/
		&m_imgGun/*显示图片*/, GUNNER_WIDTH, 0,/*从图片的哪个位置开始显示*/SRCPAINT/*传输方式*/);
	::putimage(m_x1 /*+ 10*/, m_y, GUNNER_WIDTH, GUNNER_HEIGHT,
	&m_imgGun, 0, 0, SRCAND);
	::putimage(m_x2/*+10*/, m_y,/*目标的位置*/ GUNNER_WIDTH, GUNNER_HEIGHT,/*显示原图的大小*/
		&m_imgGun/*显示图片*/, GUNNER_WIDTH, 0,/*从图片的哪个位置开始显示*/SRCPAINT/*传输方式*/);
	::putimage(m_x2 /*+ 10*/, m_y, GUNNER_WIDTH, GUNNER_HEIGHT,
		&m_imgGun, 0, 0, SRCAND);
	::putimage(m_x3/*+10*/, m_y,/*目标的位置*/ GUNNER_WIDTH, GUNNER_HEIGHT,/*显示原图的大小*/
		&m_imgGun/*显示图片*/, GUNNER_WIDTH, 0,/*从图片的哪个位置开始显示*/SRCPAINT/*传输方式*/);
	::putimage(m_x3 /*+ 10*/, m_y, GUNNER_WIDTH, GUNNER_HEIGHT,
		&m_imgGun, 0, 0, SRCAND);
	::putimage(m_x4/*+10*/, m_y,/*目标的位置*/ GUNNER_WIDTH, GUNNER_HEIGHT,/*显示原图的大小*/
		&m_imgGun/*显示图片*/, GUNNER_WIDTH, 0,/*从图片的哪个位置开始显示*/SRCPAINT/*传输方式*/);
	::putimage(m_x4 /*+ 10*/, m_y, GUNNER_WIDTH, GUNNER_HEIGHT,
		&m_imgGun, 0, 0, SRCAND);
	//::putimage(m_x, m_y,/*目标的位置*/ GUNNER_WIDTH, GUNNER_HEIGHT,/*显示原图的大小*/
	//	&m_imgGun/*显示图片*/, GUNNER_WIDTH, 0,/*从图片的哪个位置开始显示*/SRCPAINT/*传输方式*/, PI / 180 * 60, PI / 180 * 120);
	//double PI = 3.1415926;
	//int w = 300;
	//int h = 740;
	//loadimage(&m_imgGun, L"./res/gunner.jpg");//加载图片，并大小缩放 
	//setfillstyle(BS_DIBPATTERN, NULL, &m_imgGun);
	//pie(m_x,m_y, m_x+w ,m_y+h, PI / 180 * 60, PI / 180 * 120);
}
void CGungrade::MoveGun()
{
	m_y -= GUNNER_MOVE_STEP;
	m_x1 -= (int)(GUNNER_MOVE_STEP * 0.2);
	m_x2 -= (int)(GUNNER_MOVE_STEP * (- 0.2));
	m_x3 -= (int)(GUNNER_MOVE_STEP * 0.3);
	m_x4 -= (int)(GUNNER_MOVE_STEP * (-0.3));
}