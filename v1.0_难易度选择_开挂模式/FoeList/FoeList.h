#pragma once 
#include"list"
using namespace std;
#include"Foe.h"
#include"..\\Config\Config.h"
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

class FoeList
{
public:
	list<Foe*>m_list;
	list<Foe*>m_listBoom;

	FoeList();
	~FoeList();

	void ShowAllFoe();
	void MoveAllFoe();
	void playMicBoom();
};
