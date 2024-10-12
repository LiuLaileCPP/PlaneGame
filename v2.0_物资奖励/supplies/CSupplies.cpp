#include"CSupplies.h"
#include"../config/Config.h"
//#include"../PlaneApp/CPlaneApp.h"
random_device CSupplies::rd;
CSupplies::CSupplies():m_x(0), m_y(0),m_showId(0)
{

}
CSupplies::~CSupplies()
{

}
void CSupplies::InitSupplies()
{
	m_x = (rd()) % (BACK_WIDTH - FLAME_WIDTH + 1);
	m_y = -FLAME_HEIGHT;
	::loadimage(&m_imgSup, L"./res/flame.jpg");
	m_showId = FLAMESHOWID_INIT;
}
void CSupplies::ShowSupplies()
{
	::putimage(m_x, m_y, FLAME_WIDTH, FLAME_HEIGHT,
		&m_imgSup, FLAME_WIDTH, (FLAMESHOWID_INIT - m_showId) * FLAME_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, FLAME_WIDTH, FLAME_HEIGHT,
		&m_imgSup, 0, (FLAMESHOWID_INIT - m_showId) * FLAME_HEIGHT, SRCAND);
}
bool CSupplies::IssHitFoe1(CPlayer& player1)
{
	int x1 = m_x + FLAME_WIDTH / 2;
	if (player1.m_x <= x1 && x1 <= player1.m_x + PLAYER_WIDTH &&
		player1.m_y <= m_y && m_y <= player1.m_y + PLAYER_HEIGHT)
	{
		return true;
	}
	int y1 = m_y + FLAME_HEIGHT / 2;
	if (m_x >= player1.m_x && m_x <= player1.m_x + PLAYER_WIDTH &&
		y1 >=player1. m_y && y1 <= player1.m_y + PLAYER_HEIGHT)
	{
		return true;
	}
	int x2 = m_x + FLAME_WIDTH;
	if (player1.m_x <= x2 &&  x2<= player1.m_x + PLAYER_WIDTH &&
		y1 >= player1.m_y && y1<= player1.m_y + PLAYER_HEIGHT)
	{
		return true;
	}
	return false; 
	/*int x1 = player1.m_x + PLAYER_WIDTH / 2;
	if (x1 >= m_x && x1 <= m_x + FLAME_WIDTH &&
		m_y <= player1.m_y && player1.m_y <= m_y + FLAME_HEIGHT)
	{
		return true;
	}
	int y1 = player1.m_y + PLAYER_HEIGHT / 2;
	if (player1.m_x >= m_x && player1.m_x <= m_x + FLAME_WIDTH &&
		m_y <= y1 && y1 <= m_y + FLAME_HEIGHT)
	{
		return true;
	}
	int x2 = player1.m_x + PLAYER_WIDTH;
	if (x2 >= m_x && x2 <= m_x + FLAME_WIDTH &&
		m_y <= y1 && y1 <= m_y + FLAME_HEIGHT)
	{
		return true;
	}
	return false;*/
}
void CSupplies::MoveSupplies()
{
		m_y += FLAME_MOVE_STEP;
}