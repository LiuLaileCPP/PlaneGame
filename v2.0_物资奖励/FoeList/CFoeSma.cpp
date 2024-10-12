#include"CFoeSma.h"
#include"../config/Config.h"
#include"../GunList/CFoeGun.h"

void CFoeSma::InitFoe()
{
	m_x = (rd()) % (BACK_WIDTH - FOESMA_WIDTH + 1);
	m_y = -FOESMA_HEIGHT;
	::loadimage(&m_imgFoe, L"./res/foeplanesma.jpg");
	m_blood = FOESMA_BLOOD;
	m_showId = FOESMASHOWID_INIT;
}
void CFoeSma::InitFoe1()
{
	m_x = (rd()) % (BACK_WIDTH - FOESMA_WIDTH + 1);
	m_y = -FOESMA_HEIGHT;
	::loadimage(&m_imgFoe, L"./res/foeplanesma.jpg",100,100);
	m_blood = FOESMA_BLOOD;
	m_showId = FOESMASHOWID_INIT;
}
void CFoeSma::ShowFoe()
{
	::putimage(m_x, m_y, FOESMA_WIDTH, FOESMA_HEIGHT,
		&m_imgFoe, FOESMA_WIDTH, (FOESMASHOWID_INIT - m_showId) * FOESMA_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, FOESMA_WIDTH, FOESMA_HEIGHT,
		&m_imgFoe, 0, (FOESMASHOWID_INIT - m_showId) * FOESMA_HEIGHT, SRCAND);
}
void CFoeSma::ShowFoe1()
{
	::putimage(m_x, m_y, FOESMA_WIDTH * 2, FOESMA_HEIGHT * 2,
		&m_imgFoe, FOESMA_WIDTH, (FOESMASHOWID_INIT - m_showId) * FOESMA_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, FOESMA_WIDTH * 2, FOESMA_HEIGHT * 2,
		&m_imgFoe, 0, (FOESMASHOWID_INIT - m_showId) * FOESMA_HEIGHT, SRCAND);
}
bool CFoeSma::IssHitFoe(CPlayer& player)
{
	int x1 = player.m_x + PLAYER_WIDTH / 2;
	if (x1 >= m_x && x1 <= m_x + FOESMA_WIDTH &&
		m_y <= player.m_y && player.m_y <= m_y + FOESMA_HEIGHT)
	{
		return true;
	}
	int y1 = player.m_y + PLAYER_HEIGHT / 2;
	if (player.m_x >= m_x && player.m_x <= m_x + FOESMA_WIDTH &&
		m_y <= y1 && y1 <= m_y + FOESMA_HEIGHT)
	{
		return true;
	}
	int x2 = player.m_x + PLAYER_WIDTH;
	if (x2 >= m_x && x2 <= m_x + FOESMA_WIDTH &&
		m_y <= y1 && y1 <= m_y + FOESMA_HEIGHT)
	{
		return true;
	}
	return false;
}
bool CFoeSma::IssHitGun(CGunner* Gun)
{
	/*if(typeid(Gun) == typeid(CGuncomment))*/
	int x = Gun->m_x + GUNNER_WIDTH / 2;
	if (x >= m_x && x <= m_x + FOESMA_WIDTH &&
		m_y <= Gun->m_y && Gun->m_y <= m_y + FOESMA_HEIGHT)
	{
		return true;
	}
	/*else if (typeid(Gun) == typeid(CGungrade))
	{
		int x = Gun->m_x;
		int y = Gun->m_y;
		if (x >= m_x && x <= m_x + FOEBIG_WIDTH && y >= m_y && y <= m_y + FOEBIG_HEIGHT)
		{
			return true;
		}
		x = Gun->m_x1;
		if (x >= m_x && x <= m_x + FOEBIG_WIDTH && y >= m_y && y <= m_y + FOEBIG_HEIGHT)
		{
			return true;
		}
		x = Gun->m_x2;
		if (x >= m_x && x <= m_x + FOEBIG_WIDTH && y >= m_y && y <= m_y + FOEBIG_HEIGHT)
		{
			return true;
		}
		x = Gun->m_x3;
		if (x >= m_x && x <= m_x + FOEBIG_WIDTH && y >= m_y && y <= m_y + FOEBIG_HEIGHT)
		{
			return true;
		}
		x = Gun->m_x4;
		if (x >= m_x && x <= m_x + FOEBIG_WIDTH && y >= m_y && y <= m_y + FOEBIG_HEIGHT)
		{
			return true;
		}*/
	return false;
}
//CGunner* CFoeSma::SendGunner()
//{
//	/*CGunner* pGun = new CGunner;
//	int x = m_x + ((FOESMA_WIDTH - GUNNER_WIDTH) / 2);
//	int y = m_y + GUNNER_HEIGHT;
//	m_y += GUNNER_MOVE_STEP;
//	pGun->InitGun(x, y);
//	return pGun;*/
//}
CGunner* CFoeSma::SendGunner()
{
	CGunner* pGun = new CFoeGun;
	int x = m_x + ((FOESMA_WIDTH - GUNNER_WIDTH) / 2);
	/*int x1= m_x1 + ((PLAYER_WIDTH - GUNNER_WIDTH) / 2);*/
	int y = m_y - GUNNER_HEIGHT;
	/*int x1= m_x1 + ((PLAYER_WIDTH - GUNNER_WIDTH) / 2);*/
	pGun->InitGun(x, y);
	/*pGun->InitGun1(x1, y);*/
	return pGun;
}