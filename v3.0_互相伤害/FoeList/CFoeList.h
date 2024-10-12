#pragma once
#include<list>
#include"../FoeList/CFoe.h"
using namespace std;
class CFoeList
{
public:
	list<CFoe*> m_LstFoe;
	list<CFoe*> m_LstFoeBoom;
public:
	CFoeList();
	~CFoeList();
public:
	void ShowAllFoe();
	void MoveAllFoe();
};