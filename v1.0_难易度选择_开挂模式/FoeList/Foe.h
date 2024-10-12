#pragma once
#include"..\\Config\Config.h"
#include<random>
using namespace std;

class Foe{
public:
	int m_x;
	int m_y;
	IMAGE m_img;
	int m_showId;
	int m_blood;
	static random_device rd_foe;
	Foe();
	virtual ~Foe();
	virtual void InitFoe() = 0;
	virtual void ShowFoe() = 0;
	virtual bool isHitPlayer(int,int) = 0;

	void MoveFoe(int step);
};