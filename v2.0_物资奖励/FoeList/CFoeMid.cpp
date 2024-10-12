#include"CFoeMid.h"
#include"../config/Config.h"
#include"../GunList/CFoeGun.h"
void CFoeMid::InitFoe()
{
	m_x = (rd()) % (BACK_WIDTH - FOEMID_WIDTH + 1);
	m_y = -FOEMID_HEIGHT;
	::loadimage(&m_imgFoe, L"./res/foeplanemid.jpg");
	m_blood = FOEMID_BLOOD;
	m_showId = FOEMIDSHOWID_INIT;
}
void CFoeMid::InitFoe1()
{
	m_x = (rd()) % (BACK_WIDTH - FOEMID_WIDTH + 1);
	m_y = -FOEMID_HEIGHT;
	::loadimage(&m_imgFoe, L"./res/foeplanemid.jpg",100,100);
	m_blood = FOEMID_BLOOD;
	m_showId = FOEMIDSHOWID_INIT;
}
void CFoeMid::ShowFoe()
{
	::putimage(m_x, m_y, FOEMID_WIDTH, FOEMID_HEIGHT,
		&m_imgFoe, FOEMID_WIDTH, (FOEMIDSHOWID_INIT - m_showId) * FOEMID_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, FOEMID_WIDTH, FOEMID_HEIGHT,
		&m_imgFoe, 0, (FOEMIDSHOWID_INIT - m_showId) * FOEMID_HEIGHT, SRCAND);
}
void CFoeMid::ShowFoe1()
{
	::putimage(m_x, m_y, FOEMID_WIDTH * 2, FOEMID_HEIGHT * 2,
		&m_imgFoe, FOEMID_WIDTH, (FOEMIDSHOWID_INIT - m_showId) * FOEMID_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, FOEMID_WIDTH * 2, FOEMID_HEIGHT * 2,
		&m_imgFoe, 0, (FOEMIDSHOWID_INIT - m_showId) * FOEMID_HEIGHT, SRCAND);
}
bool CFoeMid::IssHitFoe(CPlayer& player)
{
	int x1 = player.m_x + PLAYER_WIDTH / 2;
	if (x1 >= m_x && x1 <= m_x + FOEMID_WIDTH &&
		m_y <= player.m_y && player.m_y <= m_y + FOEMID_HEIGHT)
	{
		return true;
	}
	int y1 = player.m_y + PLAYER_HEIGHT / 2;
	if (player.m_x >= m_x && player.m_x <= m_x + FOEMID_WIDTH &&
		m_y <= y1 && y1 <= m_y + FOEMID_HEIGHT)
	{
		return true;
	}
	int x2 = player.m_x + PLAYER_WIDTH;
	if (x2 >= m_x && x2 <= m_x + FOEMID_WIDTH &&
		m_y <= y1 && y1 <= m_y + FOEMID_HEIGHT)
	{
		return true;
	}
	return false;
}
bool CFoeMid::IssHitGun(CGunner* Gun)
{
	int x = Gun->m_x + GUNNER_WIDTH / 2;
	if (x >= m_x && x <= m_x + FOEMID_WIDTH &&
		m_y <= Gun->m_y && Gun->m_y <= m_y + FOEMID_HEIGHT)
	{
		return true;
	}
	return false;
}
//CGunner* CFoeMid::SendGunner()
//{
//	/*CGunner* pGun = new CGunner;
//	int x = m_x + ((FOEMID_WIDTH - GUNNER_WIDTH) / 2);
//	int y = m_y + GUNNER_HEIGHT;
//	m_y += GUNNER_MOVE_STEP;
//	pGun->InitGun(x, y);
//	return pGun;*/
//}
CGunner* CFoeMid::SendGunner()
{
	CGunner* pGun = new CFoeGun;
	int x = m_x + ((FOEMID_WIDTH - GUNNER_WIDTH) / 2);
	/*int x1= m_x1 + ((PLAYER_WIDTH - GUNNER_WIDTH) / 2);*/
	int y = m_y - GUNNER_HEIGHT;
	/*int x1= m_x1 + ((PLAYER_WIDTH - GUNNER_WIDTH) / 2);*/
	pGun->InitGun(x, y);
	/*pGun->InitGun1(x1, y);*/
	return pGun;
}