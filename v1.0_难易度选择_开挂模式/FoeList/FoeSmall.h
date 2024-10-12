#pragma once
#include "Foe.h"

class FoeSmall :public Foe {
public:
	void InitFoe();
	void ShowFoe();
	bool isHitPlayer(int , int);
};