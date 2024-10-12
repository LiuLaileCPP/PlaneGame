#pragma once
#include<easyx.h>
#include"..\\GunList\Gun.h"

class Player {
public:
	IMAGE m_img;
	IMAGE m_maskImg;
	int m_x;
	int m_y;
	Player();
	~Player();
	void InitPlayer();
	void ShowPlayer();
	void MovePlayer(int direct);
	Gun* SendGun();
};




