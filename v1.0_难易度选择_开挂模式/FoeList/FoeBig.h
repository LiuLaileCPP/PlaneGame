#pragma once 
#include"Foe.h"

class FoeBig :public Foe {
public:
	void InitFoe();
	void ShowFoe();
	bool isHitPlayer(int, int);
};