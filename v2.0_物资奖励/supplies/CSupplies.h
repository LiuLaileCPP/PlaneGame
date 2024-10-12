#pragma once
#include<easyx.h>
#include"../Player/CPlayer.h"
#include<random>
using namespace std;
class CSupplies
{
public:
	int m_x;
	int m_y;
	int m_showId;
	IMAGE m_imgSup;
	static random_device rd;
public:
	CSupplies();
	virtual ~CSupplies();
public:
	virtual void InitSupplies();
	virtual void ShowSupplies();
	virtual void MoveSupplies();
	virtual bool IssHitFoe1(CPlayer&player1);
};