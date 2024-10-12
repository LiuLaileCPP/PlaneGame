#include"FoeSmall.h"

void FoeSmall::InitFoe()
{
	m_img;
	::loadimage(&m_img,L".\\res\\foesam.jpg");
	m_x = rd_foe() % (BACK_WIDTH - FOESMALL_WIDTH + 1);
	m_y = -FOESMALL_HEIGHT;
	m_blood = FOESMALL_BLOOD;
	m_showId = FOESMALL_INIT_SHOWID;
}

void FoeSmall::ShowFoe()
{
	::putimage(m_x, m_y, FOESMALL_WIDTH, FOESMALL_HEIGHT, &m_img, FOESMALL_WIDTH, FOESMALL_HEIGHT * (FOESMALL_INIT_SHOWID - m_showId), SRCPAINT);
	::putimage(m_x,m_y,FOESMALL_WIDTH,FOESMALL_HEIGHT,&m_img,FOESMALL_WIDTH,FOESMALL_HEIGHT * (FOESMALL_INIT_SHOWID - m_showId),SRCAND);
}

bool FoeSmall::isHitPlayer(int x, int y)
{
	if (x >= m_x + FOESMALL_WIDTH / 4
		&& x <= m_x + FOESMALL_WIDTH / 4 * 3
		&& y >= m_y + FOESMALL_HEIGHT / 4 
		&& y <= m_y + FOESMALL_HEIGHT / 4 * 3)
	{
		return true;
	}
	return false;
}
