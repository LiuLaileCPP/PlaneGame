#include"Player.h"
#include"..\\Config\Config.h"

Player::Player():m_x(0),m_y(0)
{

}
Player::~Player()
{

}

void Player::InitPlayer()
{
	::loadimage(&m_img,L".\\res\\player.jpg");
	::loadimage(&m_maskImg,L".\\res\\player_mask.jpg");
	m_x = (BACK_WIDTH - PLAYER_WIDTH);
	m_y = (BACK_HEIGHT - PLAYER_HEIGHT);
}

void Player::ShowPlayer()
{
	::putimage(m_x,m_y,&m_maskImg,SRCPAINT);
	::putimage(m_x,m_y,&m_img,SRCAND);
}

void Player::MovePlayer(int direct)
{
	if (direct == VK_UP)
	{
		m_y - PLAYER_MOVE_STEP > 0 ? m_y -= PLAYER_MOVE_STEP : m_y = 0;
 	}
	if (direct == VK_DOWN)
	{
		m_y + PLAYER_MOVE_STEP <= (BACK_HEIGHT - PLAYER_HEIGHT) ?
			m_y += PLAYER_MOVE_STEP : m_y = BACK_HEIGHT - PLAYER_HEIGHT;
	}
	if (direct == VK_LEFT)
	{
		m_x - PLAYER_MOVE_STEP >= 0 ? m_x -= PLAYER_MOVE_STEP
			: m_x = 0;
	}
	if (direct == VK_RIGHT)
	{
		m_x + PLAYER_MOVE_STEP <= (BACK_WIDTH - PLAYER_WIDTH) ?
			m_x += PLAYER_MOVE_STEP : m_x = BACK_WIDTH - PLAYER_WIDTH;
	}
}

Gun* Player::SendGun()
{
	Gun* pGun = new Gun;
	pGun->InitGun(
		m_x + (PLAYER_WIDTH - GUNNER_WIDTH) / 2,
		m_y - GUNNER_HEIGHT
		);
	return pGun;
}
