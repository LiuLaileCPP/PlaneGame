#include"CFoe Big.h"
#include"../config/Config.h"
#include"../GunList/CFoeGun.h"
#include <typeinfo>
#include "../GunList/CGuncommon.h"
#include "../GunList/CGungrade.h"
void CFoeBig::InitFoe(int size)
{
	if (size == 0)
	{
		m_x = (rd()) % (BACK_WIDTH - FOEBIG_WIDTH + 1);
		m_y = -FOEBIG_HEIGHT;
		::loadimage(&m_imgFoe, L"./res/foeplanebig.jpg");
		m_blood = FOEBIG_BLOOD;
		m_showId = FOEBIGSHOWID_INIT;
	}
	else if (size == 1)
	{
		//void loadimage(IMAGE * pDstImg, LPCTSTR pResType, LPCTSTR pResName, int nWidth = 0, int nHeight = 0, bool bResize = false);
		//  pResType：图像资源的类型，常见的如 "bmp" 表示 BMP 图像， "jpg" 表示 JPEG 图像等。
		//	pResName：图像资源的名称或路径。
		//	nWidth：指定加载后的图像宽度，如果为 0 则保持原始宽度。
		//	nHeight：指定加载后的图像高度，如果为 0 则保持原始高度。
		//	bResize：如果为 true 且指定了宽度和高度，则会对图像进行缩放以适应指定的大小。
		m_x = (rd()) % (BACK_WIDTH - FOEBIG_WIDTH * 2 + 1);
		m_y = -FOEBIG_HEIGHT * 2;
		::loadimage(&m_imgFoe, L"jpg",L". / res / foeplanebig.jpg", FOEBIG_WIDTH * 2, FOEBIG_HEIGHT * 2, true);
		m_blood = FOEBIG_BLOOD;
		m_showId = FOEBIGSHOWID_INIT;
	}
}
void CFoeBig::InitFoe1()
{
	m_x = (rd()) % (BACK_WIDTH - FOEBIG_WIDTH + 1);
	m_y = -FOEBIG_HEIGHT;
	::loadimage(&m_imgFoe, L"./res/foeplanebig.jpg");
	m_blood = FOEBIG_BLOOD;
	m_showId = FOEBIGSHOWID_INIT;
}
void CFoeBig::ShowFoe1() 
{
	::putimage(m_x, m_y, FOEBIG_WIDTH * 2, FOEBIG_HEIGHT * 2,
		&m_imgFoe, FOEBIG_WIDTH * 2, (FOEBIGSHOWID_INIT- m_showId)* FOEBIG_HEIGHT * 2, SRCPAINT);
	::putimage(m_x, m_y, FOEBIG_WIDTH * 2, FOEBIG_HEIGHT * 2,
		&m_imgFoe, 0, (FOEBIGSHOWID_INIT - m_showId) * FOEBIG_HEIGHT * 2, SRCAND);
}
void CFoeBig::ShowFoe()
{
	::putimage(m_x, m_y, FOEBIG_WIDTH, FOEBIG_HEIGHT,
		&m_imgFoe, FOEBIG_WIDTH, (FOEBIGSHOWID_INIT - m_showId) * FOEBIG_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, FOEBIG_WIDTH, FOEBIG_HEIGHT,
		&m_imgFoe, 0, (FOEBIGSHOWID_INIT - m_showId) * FOEBIG_HEIGHT, SRCAND);
}
bool CFoeBig::IssHitFoe(CPlayer& player) 
{
	int x1 = player.m_x + PLAYER_WIDTH / 2;
	if (x1 >= m_x && x1 <= m_x + FOEBIG_WIDTH&&
		m_y<=player.m_y && player.m_y<=m_y+ FOEBIG_HEIGHT)
	{
		return true;
	}
	int y1= player.m_y + PLAYER_HEIGHT / 2;
	if (player.m_x >= m_x && player.m_x <= m_x + FOEBIG_WIDTH &&
		m_y <=y1 && y1<= m_y + FOEBIG_HEIGHT)
	{
		return true;
	}
	int x2 = player.m_x + PLAYER_WIDTH;
	if (x2 >= m_x && x2 <= m_x + FOEBIG_WIDTH &&
		m_y <= y1 && y1 <= m_y + FOEBIG_HEIGHT)
	{
		return true;
	}
	return false;
}
bool CFoeBig::IssHitGun(CGunner* Gun)
{
	int x = Gun->m_x;
	int y = Gun->m_y;
	/*if (x >= m_x && x <= m_x + FOEBIG_WIDTH && y >= m_y && y <= m_y + FOEBIG_HEIGHT)
	{
		return true;
	}*/
	if (Gun->type == 0)
	{
		int x = Gun->m_x + GUNNER_WIDTH / 2;
		if (x >= m_x && x <= m_x + FOEBIG_WIDTH &&
			m_y <= Gun->m_y && Gun->m_y <= m_y + FOEBIG_HEIGHT)
		{
			return true;
		}
	}
	else if (Gun->type == 1)
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
		}
	}
	/*else if(Gun->type > 2)
	{
		Sleep(10);
		exit(0);
	}*/
	return false;
}
//CGunner* CFoeBig::SendGunner()
//{
//	CGunner* pGun = new CGunner;
//	int x = m_x + ((FOEBIG_WIDTH - GUNNER_WIDTH) / 2);
//	int y = m_y + GUNNER_HEIGHT;
//	m_y += GUNNER_MOVE_STEP;
//	pGun->InitGun(x, y);
//	return pGun;
//}
CGunner* CFoeBig::SendGunner()
{
	CGunner* pGun = new CFoeGun;
	int x = m_x + ((FOEBIG_WIDTH - GUNNER_WIDTH) / 2);
	/*int x1= m_x1 + ((PLAYER_WIDTH - GUNNER_WIDTH) / 2);*/
	int y = m_y + GUNNER_HEIGHT;
	/*int x1= m_x1 + ((PLAYER_WIDTH - GUNNER_WIDTH) / 2);*/
	pGun->InitGun(x, y);
	/*pGun->InitGun1(x1, y);*/
	return pGun;
}

CGunner* CFoeBig::FoeSendGunner()
{
	CGunner* pGun = new CFoeGun;
	int x = m_x + ((FOEBIG_WIDTH - GUNNER_WIDTH) / 2);
	/*int x1= m_x1 + ((PLAYER_WIDTH - GUNNER_WIDTH) / 2);*/
	int y = m_y + GUNNER_HEIGHT;
	/*int x1= m_x1 + ((PLAYER_WIDTH - GUNNER_WIDTH) / 2);*/
	pGun->InitGun(x, y);
	/*pGun->InitGun1(x1, y);*/
	return pGun;
}