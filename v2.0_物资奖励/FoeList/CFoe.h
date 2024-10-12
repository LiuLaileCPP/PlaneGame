#pragma once
#include<easyx.h>
#include"../Player/CPlayer.h"
#include<random>
using namespace std;
class CFoe
{
public:
	int m_x;
	int m_y;
	IMAGE m_imgFoe;
	IMAGE m_imgFlame;
	int m_blood;
	int m_showId;
	static random_device rd;
public:
	CFoe();
	virtual ~CFoe();
public:
	virtual void InitFoe()=0;
	virtual void InitFoe1() = 0;
	virtual void ShowFoe()=0;
	virtual void ShowFoe1() = 0;
	void MoveFoe(int step);
	virtual bool IssHitFoe(CPlayer& player)=0;
	virtual bool IssHitGun(CGunner* Gun)=0;
};