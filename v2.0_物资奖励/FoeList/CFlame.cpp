//#include"CFlame.h"
//#include"../config/Config.h"
//#include "../PlaneApp/CPlaneApp.h"
//#include"../GunList/CGunList.h"
//void CFoeFlame::InitFoe()
//{
//	m_x = (rd()) % (BACK_WIDTH - FOEMID_WIDTH + 1);
//	m_y = -FLAME_HEIGHT;
//	::loadimage(&m_imgFlame, L"./res/flame.jpg");
//	m_showId = FLAMESHOWID_INIT;
//}
//void CFoeFlame::InitFoe1()
//{
//
//}
//void CFoeFlame::ShowFoe()
//{
//	::putimage(m_x, m_y, FLAME_WIDTH, FLAME_HEIGHT,
//		&m_imgFlame, FLAME_WIDTH, (FLAMESHOWID_INIT - m_showId) * FLAME_HEIGHT, SRCPAINT);
//	::putimage(m_x, m_y, FLAME_WIDTH, FLAME_HEIGHT,
//		&m_imgFlame, 0, (FLAMESHOWID_INIT - m_showId) * FLAME_HEIGHT, SRCAND);
//}
//bool CFoeFlame::IssHitFoe(CPlayer& player)
//{
//	int x1 = player.m_x + PLAYER_WIDTH / 2;
//	if (x1 >= m_x && x1 <= m_x + FLAME_WIDTH &&
//		m_y <= player.m_y && player.m_y <= m_y + FLAME_HEIGHT)
//	{
//		return true;
//	}
//	int y1 = player.m_y + PLAYER_HEIGHT / 2;
//	if (player.m_x >= m_x && player.m_x <= m_x + FLAME_WIDTH &&
//		m_y <= y1 && y1 <= m_y + FLAME_HEIGHT)
//	{
//		return true;
//	}
//	int x2 = player.m_x + PLAYER_WIDTH;
//	if (x2 >= m_x && x2 <= m_x + FLAME_WIDTH &&
//		m_y <= y1 && y1 <= m_y + FLAME_HEIGHT)
//	{
//		return true;
//	}
//	return false;
//}
//bool CFoeFlame::IssHitGun(CGunner* Gun)
//{
//	int x = Gun->m_x + GUNNER_WIDTH / 2;
//	if (x >= m_x && x <= m_x + FOEMID_WIDTH &&
//		m_y <= Gun->m_y && Gun->m_y <= m_y + FOEMID_HEIGHT)
//	{
//		return false;
//	}
//	return false;
//}