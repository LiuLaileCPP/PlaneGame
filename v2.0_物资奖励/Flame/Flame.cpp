//#include"Flame.h"
//#include"../config/Config.h"
//#include<random>
//Flame::Flame() :m_x1(0), m_y1(0), m_showId(0)
//{
//
//}
//Flame::~Flame() {}
//void Flame::InitFlame()
//{
//	m_x1 = (rd()) % (BACK_WIDTH - FOEBIG_WIDTH + 1);
//	m_y1 = -FLAME_HEIGHT;
//	::loadimage(&m_imgFlame, L"./res/flame.jpg");
//	m_showId = FLAMESHOWID_INIT;
//}
//void Flame::ShowFlame()
//{
//	::putimage(m_x1, m_y1, FLAME_WIDTH, FLAME_HEIGHT,
//		&m_imgFlame, FLAME_WIDTH, (FLAMESHOWID_INIT - m_showId) * FLAME_HEIGHT, SRCPAINT);
//	::putimage(m_x1, m_y1, FLAME_WIDTH, FLAME_HEIGHT,
//		&m_imgFlame, 0, (FLAMESHOWID_INIT - m_showId) * FLAME_HEIGHT, SRCAND);
//
//}
//bool Flame::IssHitFoe(CPlayer& player)
//{
//	int x1 = player.m_x1 + PLAYER_WIDTH / 2;
//	if (x1 >= m_x1 && x1 <= m_x1 + FOEMID_WIDTH &&
//		m_y1 <= player.m_y && player.m_y <= m_y1 + FOEMID_HEIGHT)
//	{
//		return true;
//	}
//	int y1 = player.m_y + PLAYER_HEIGHT / 2;
//	if (player.m_x1 >= m_x1 && player.m_x1 <= m_x1 + FOEMID_WIDTH &&
//		m_y1 <= y1 && y1 <= m_y1 + FOEMID_HEIGHT)
//	{
//		return true;
//	}
//	int x2 = player.m_x1 + PLAYER_WIDTH;
//	if (x2 >= m_x1 && x2 <= m_x1 + FOEMID_WIDTH &&
//		m_y1 <= y1 && y1 <= m_y1 + FOEMID_HEIGHT)
//	{
//		return true;
//	}
//	return false;
//}
//void Flame::MoveFlame(int step)
//{
//	m_y1 += step;
//}
//random_device Flame::rd;