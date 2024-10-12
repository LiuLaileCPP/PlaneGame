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

	::putimage(m_x, m_y,/*目标的位置*/ GUNNER_WIDTH, GUNNER_HEIGHT,/*显示原图的大小*/
		&m_imgGun/*显示图片*/, GUNNER_WIDTH, 0,/*从图片的哪个位置开始显示*/SRCPAINT/*传输方式*/);
	::putimage(m_x, m_y, GUNNER_WIDTH, GUNNER_HEIGHT,
		&m_imgGun, 0, 0, SRCAND);
	//::putimage(m_x1, m_y,/*目标的位置*/ GUNNER_WIDTH, GUNNER_HEIGHT,/*显示原图的大小*/
	//	&m_imgGun/*显示图片*/, GUNNER_WIDTH, 0,/*从图片的哪个位置开始显示*/SRCPAINT/*传输方式*/);
	//::putimage(m_x1, m_y, GUNNER_WIDTH, GUNNER_HEIGHT,
	//	&m_imgGun, 0, 0, SRCAND);
}
void CGuncommon::MoveGun()
{
	m_y -= GUNNER_MOVE_STEP;
}