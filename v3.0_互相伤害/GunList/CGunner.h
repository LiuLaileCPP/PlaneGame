#pragma once
#include<easyx.h>
using namespace std; //
class CGunner
{
public:
	int type;
	int m_x;
	int m_y;
	int m_x1;
	int m_x2;
	int m_x3;
	int m_x4;
	IMAGE m_imgGun;
public:
	CGunner();
	virtual ~CGunner();
public:
	virtual void InitGun(int x, int y)=0;
	virtual void ShowGun()=0;
	virtual void MoveGun()=0;
};
//class CGunner
//{
//public:
//	int m_x;
//	int m_y;
//	int m_x1;
//	IMAGE m_imgGun;
//public:
//	CGunner();
//	~CGunner();
//public:
//	virtual void InitGun(int x, int y);
//	virtual void ShowGun();
//	virtual void ShowGun2();
//	virtual void MoveGun();
//};