#pragma once
#include"Gun.h"
#include<list>
using namespace std;
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

class GunList {
public:
	list<Gun*>m_listGun;

	GunList();
	~GunList();
	void ShowAllGun();
	void MoveAllGun();
	void playMicGun();
};