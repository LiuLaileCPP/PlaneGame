#include"FoeMid.h"

void FoeMid::InitFoe()
{
	m_img;
	::loadimage(&m_img,L".\\res\\foemid.jpg");

	m_x = rd_foe() % (BACK_WIDTH - FOEMID_WIDTH + 1);
	m_y = -FOEMID_HEIGHT;
	m_blood = FOEMID_BLOOD;
	m_showId = FOEMID_INIT_SHOWID;
}

void FoeMid::ShowFoe()
{
	::putimage(m_x,m_y,FOEMID_WIDTH,FOEMID_HEIGHT,&m_img,FOEMID_WIDTH,FOEMID_HEIGHT * (FOEMID_INIT_SHOWID - m_showId),SRCPAINT);
	::putimage(m_x,m_y,FOEMID_WIDTH,FOEMID_HEIGHT,&m_img,FOEMID_WIDTH,FOEMID_HEIGHT * (FOEMID_INIT_SHOWID - m_showId),SRCAND);
}

bool FoeMid::isHitPlayer(int x, int y)
{
	if (x >= m_x + FOEMID_WIDTH / 4
		&& x <= m_x + FOEMID_WIDTH / 4 * 3
		&& y >= m_y + FOEMID_HEIGHT / 4
		&& y <= m_y + FOEMID_HEIGHT / 4 * 3)
	{
		return true;
	}
	return false;
}