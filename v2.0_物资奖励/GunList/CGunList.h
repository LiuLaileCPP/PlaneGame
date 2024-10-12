#pragma once
#include<list>
#include"CGunner.h"
using namespace std;

class CGunList
{
public:
	list<CGunner*> m_listGun;
	list<CGunner*> m_listGun1;
public:
	CGunList();
	~CGunList();
public:
	//virtual void InitGun(int x, int y);
	virtual void ShowAllGun();
	/*virtual void ShowAllGun2();*/
	virtual void MoveAllGun();
	/*virtual void MoveAllGun2();*/
	/*virtual void MoveAllGun2();*/
};