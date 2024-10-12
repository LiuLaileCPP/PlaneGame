#include"Gun.h"
#include"..\\Config\Config.h"
#include<typeinfo>
using namespace std;

#include"..\\FoeList\FoeBig.h"
#include"..\\FoeList\FoeMid.h"
#include"..\\FoeList\FoeSmall.h"

Gun::Gun() :m_x(0), m_y(0)
{

}
Gun::~Gun() {}

void Gun::InitGun(int x, int y)
{
	m_x = x;
	m_y = y;
	::loadimage(&m_img, L".\\res\\gunner.jpg");
}

void Gun::ShowGun()
{
	::putimage(m_x, m_y, GUNNER_WIDTH / 2, GUNNER_HEIGHT, &m_img, GUNNER_WIDTH / 2, 0, SRCPAINT);
	::putimage(m_x, m_y, GUNNER_WIDTH / 2, GUNNER_HEIGHT, &m_img, GUNNER_WIDTH / 2, 0, SRCAND);

}

void Gun::MoveGun()
{
	m_y -= GUN_MOVE_STEP;
}

bool Gun::isHitFoe(Foe* pfoe)
{
	if (!pfoe) return false;
	if (typeid(*pfoe) == typeid(FoeBig))
	{
		if (m_x >= pfoe->m_x + FOEBIG_WIDTH / 4
			&& m_x <= pfoe->m_x + FOEBIG_WIDTH / 4 * 3
			&& m_y >= pfoe->m_y + FOEBIG_HEIGHT / 4
			&& m_y <= pfoe->m_y + FOEBIG_HEIGHT / 4 * 3)
		{
			return true;
		}
	}
	else if (typeid(*pfoe) == typeid(FoeSmall))
	{
		if (m_x >= pfoe->m_x + FOESMALL_WIDTH / 4
			&& m_x <= pfoe->m_x + FOESMALL_WIDTH / 4 * 3
			&& m_y >= pfoe->m_y + FOESMALL_HEIGHT / 4
			&& m_y <= pfoe->m_y + FOESMALL_HEIGHT / 4 * 3)
		{
			return true;
		}
	}
	else if (typeid(*pfoe) == typeid(FoeMid))
	{
		if (m_x >= pfoe->m_x + FOEMID_WIDTH / 4
			&& m_x <= pfoe->m_x + FOEMID_WIDTH / 4 * 3
			&& m_y >= pfoe->m_y + FOEMID_HEIGHT / 4
			&& m_y <= pfoe->m_y + FOEMID_HEIGHT / 4 * 3)
		{
			return true;
		}
	}
	return false;
}