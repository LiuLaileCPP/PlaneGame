#include"FoeBig.h"

void FoeBig::InitFoe()
{
	m_img;
	::loadimage(&m_img,L".\\res\\foebig.jpg");

	m_x = rd_foe() % (BACK_WIDTH - FOEBIG_WIDTH + 1);
	m_y = -FOEBIG_HEIGHT;
	m_blood = FOEBIG_BLOOD;
	m_showId = FOEBIG_INIT_SHOWID;
}

void FoeBig::ShowFoe()
{
	::putimage(m_x,m_y,FOEBIG_WIDTH,FOEBIG_HEIGHT,&m_img,FOEBIG_WIDTH,FOEBIG_HEIGHT * (FOEBIG_INIT_SHOWID - m_showId),SRCPAINT);

	::putimage(m_x,m_y,FOEBIG_WIDTH,FOEBIG_HEIGHT,&m_img,FOEBIG_WIDTH,FOEBIG_HEIGHT* (FOEBIG_INIT_SHOWID - m_showId),SRCAND);
}

bool FoeBig::isHitPlayer(int x, int y)
{
	if (x >= m_x + FOEBIG_WIDTH / 4
		&& x <= m_x + FOEBIG_WIDTH / 4 * 3
		&& y >= m_y + FOEBIG_HEIGHT / 4
		&& y <= m_y + FOEBIG_HEIGHT / 4 * 3)
	{
		return true;
	}
	return false;
}