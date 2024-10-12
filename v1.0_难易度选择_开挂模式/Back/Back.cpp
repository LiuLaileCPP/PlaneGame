#include"Back.h"

Back::Back() :m_x(0),m_y(0)
{

}

Back::~Back() {

}

void Back::InitBack()
{
	::loadimage(&m_backImg, L".\\res\\back.jpg");
	m_x = 0;
	m_y = -BACK_HEIGHT;
}

void Back::ShowBack()
{
	if (m_y == 0)
	{
		m_y = -BACK_HEIGHT;
		return;
	}
	m_y += BACK_MOVE_STEP;
}