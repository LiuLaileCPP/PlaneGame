#include"CPlayer.h"
#include"../GunList/CGuncommon.h"
#include"../GunList/CGungrade.h"
#include"../config/Config.h"
CPlayer::CPlayer():m_x(0),m_y(0),m_x1(0)
{
	m_x = (BACK_WIDTH- PLAYER_WIDTH)/2;
	m_y = BACK_HEIGHT - PLAYER_HEIGHT;
	m_x1 = (BACK_WIDTH - PLAYER_WIDTH) / 2+ 10;
	::loadimage(&m_imgPlayer, L"./res/playerplane.jpg");
	::loadimage(&m_imgMask, L"./res/playerplane-mask.jpg");
}
CPlayer::~CPlayer() {}
void  CPlayer::InitPlayer(){}
void CPlayer::ShowPlayer()
{
	::putimage(m_x,m_y, &m_imgMask,SRCPAINT);    //背景图与屏蔽图做位或操作
	::putimage(m_x, m_y, &m_imgPlayer, SRCAND);   //原图与上一步的结果做位与操作
}
void CPlayer::MovePlayer(unsigned direct)
{
	if (direct == VK_UP)     //如果方向向上
	{
		(m_y -= PLAYER_MOVE_STEP) >= 0 ? m_y -= PLAYER_MOVE_STEP : m_y = 0;
	}
	else if (direct == VK_DOWN)
	{
		(m_y += PLAYER_MOVE_STEP) <= (BACK_HEIGHT - PLAYER_HEIGHT) ? m_y += PLAYER_MOVE_STEP : m_y = (BACK_HEIGHT - PLAYER_HEIGHT);
	}
	else if (direct == VK_LEFT)
	{
		(m_x -= PLAYER_MOVE_STEP) >= 0  ? m_x -= PLAYER_MOVE_STEP : m_x = 0;
		(m_x1 -= PLAYER_MOVE_STEP) >= 0 ? m_x1 -= PLAYER_MOVE_STEP : m_x1 = 0;
	}
	else if (direct == VK_RIGHT)
	{
		(m_x += PLAYER_MOVE_STEP) <= (BACK_WIDTH - PLAYER_WIDTH) ? m_x += PLAYER_MOVE_STEP : m_x = (BACK_WIDTH - PLAYER_WIDTH);
		(m_x1 += PLAYER_MOVE_STEP) <= (BACK_WIDTH - PLAYER_WIDTH) ? m_x1 += PLAYER_MOVE_STEP : m_x1 = (BACK_WIDTH - PLAYER_WIDTH);
	}
}
CGunner* CPlayer::SendGunner()
{
	CGunner* pGun = new CGuncommon;
	int x = m_x + ((PLAYER_WIDTH- GUNNER_WIDTH) / 2);
	/*int x1= m_x1 + ((PLAYER_WIDTH - GUNNER_WIDTH) / 2);*/
	int y = m_y - GUNNER_HEIGHT;
	/*int x1= m_x1 + ((PLAYER_WIDTH - GUNNER_WIDTH) / 2);*/
	pGun->InitGun(x,y);
	/*pGun->InitGun1(x1, y);*/
	return pGun;
}

CGunner* CPlayer::SendGunner2()
{
	CGunner* pGun = new CGungrade;
	/*int x = m_x + ((PLAYER_WIDTH - GUNNER_WIDTH) / 2);*/
	int x= m_x + ((PLAYER_WIDTH - GUNNER_WIDTH) / 2);
	int y = m_y - GUNNER_HEIGHT;
	/*pGun->InitGun(x, y);*/
	pGun->InitGun(x, y);
	/*pGun->InitGun(x+10, y);*/
	return pGun;
}