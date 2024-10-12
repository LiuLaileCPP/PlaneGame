#pragma once
#include"..\\FoeList\Foe.h"

class Gun{
public:
	IMAGE m_img;
	int m_x;
	int m_y;
	Gun();
	~Gun();
	void InitGun(int,int);
	void ShowGun();
	void MoveGun();
	bool isHitFoe(Foe* foe);
};