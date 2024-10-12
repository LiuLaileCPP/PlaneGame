#pragma once
#include<easyx.h>
#include"../GunList/CGunner.h"
//#include"../supplies/CSupplies.h"
class CPlayer
{
public:
	int m_x;
	int m_y;
	int m_x1;
	IMAGE m_imgPlayer;
	IMAGE m_imgMask;
public:
	CPlayer();
	~CPlayer();
public:
	virtual void InitPlayer();
	virtual void ShowPlayer();
	virtual void MovePlayer(unsigned direct);
	/*CSupplies* p1;*/
	CGunner* SendGunner();
	CGunner* SendGunner2();
};