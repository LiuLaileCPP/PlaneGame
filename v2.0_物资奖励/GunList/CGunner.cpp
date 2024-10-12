#include"CGunner.h"
#include"../config/Config.h"
CGunner::CGunner():m_x(0),m_y(0),m_x1(0),m_x2(0),m_x3(0),m_x4(0){}
CGunner::~CGunner() {}
//void CGunner::MoveGun()
//{
//	m_y -= GUNNER_MOVE_STEP;
//	/*m_x -= GUNNER_MOVE_STEP;*/
//	/*m_x1 -= (int)(GUNNER_MOVE_STEP * 0.2);*/
//	/*m_x -= (int)(GUNNER_MOVE_STEP * 0.2);*/
//	//double PI = 3.1415926;
//	//pie(m_x, m_y, m_x, m_y-GUNNER_MOVE_STEP , PI / 180 * 60, PI / 180 * 120);
//}



//#include"CGunner.h"
//#include"../config/Config.h"
//#include<easyx.h>
//#include <graphics.h> 
//#include <cmath>
//CGunner::CGunner():m_x(0),m_y(0)
//{
//
//}
//CGunner::~CGunner(){}
//void CGunner::InitGun(int x, int y)
//{
//	m_x = x;
//	m_y = y;
//	::loadimage(&m_imgGun, L"./res/gunner.jpg");
//}
//void CGunner::InitGun2(int x1, int y)
//{
//	m_x1 = x1;
//	m_y = y;
//	::loadimage(&m_imgGun, L"./res/gunner.jpg");
//}
//void CGunner::ShowGun()
//{
//
//	::putimage(m_x, m_y,/*目标的位置*/ GUNNER_WIDTH, GUNNER_HEIGHT,/*显示原图的大小*/
//		&m_imgGun/*显示图片*/, GUNNER_WIDTH, 0,/*从图片的哪个位置开始显示*/SRCPAINT/*传输方式*/);
//	::putimage(m_x, m_y, GUNNER_WIDTH, GUNNER_HEIGHT,
//		&m_imgGun, 0, 0, SRCAND);
	//::putimage(m_x+10, m_y,/*目标的位置*/ GUNNER_WIDTH, GUNNER_HEIGHT,/*显示原图的大小*/
	//	&m_imgGun/*显示图片*/, GUNNER_WIDTH, 0,/*从图片的哪个位置开始显示*/SRCPAINT/*传输方式*/);
	//::putimage(m_x+10, m_y, GUNNER_WIDTH, GUNNER_HEIGHT,
	//	&m_imgGun, 0, 0, SRCAND);
	//double PI = 3.1415926;
	//int w = 300;
	//int h = 740;
	//loadimage(&m_imgGun, L"./res/gunner.jpg");//加载图片，并大小缩放 
	//setfillstyle(BS_DIBPATTERN, NULL, &m_imgGun);
	//solidpie(m_x,m_y, m_x+w ,m_y+h, PI / 180 * 0, PI / 180 * 180);
//}
//void CGunner::ShowGun2()
//{
//	::putimage(m_x, m_y,/*目标的位置*/ GUNNER_WIDTH, GUNNER_HEIGHT,/*显示原图的大小*/
//		&m_imgGun/*显示图片*/, GUNNER_WIDTH, 0,/*从图片的哪个位置开始显示*/SRCPAINT/*传输方式*/);
//	::putimage(m_x, m_y, GUNNER_WIDTH, GUNNER_HEIGHT,
//		&m_imgGun, 0, 0, SRCAND);
//	::putimage(m_x+10, m_y,/*目标的位置*/ GUNNER_WIDTH, GUNNER_HEIGHT,/*显示原图的大小*/
//		&m_imgGun/*显示图片*/, GUNNER_WIDTH, 0,/*从图片的哪个位置开始显示*/SRCPAINT/*传输方式*/);
//	::putimage(m_x+10, m_y, GUNNER_WIDTH, GUNNER_HEIGHT,
//		&m_imgGun, 0, 0, SRCAND);
//	double PI = 3.1415926;
//	int w = 300;
//	int h = 740;
//	loadimage(&m_imgGun, L"./res/gunner.jpg");//加载图片，并大小缩放 
//	setfillstyle(BS_DIBPATTERN, NULL, &m_imgGun);
//	solidpie(m_x,m_y, m_x+w ,m_y+h, PI / 180 * 0, PI / 180 * 180);
//}
//void CGunner::MoveGun()
//{
//	m_y -= GUNNER_MOVE_STEP;
//}