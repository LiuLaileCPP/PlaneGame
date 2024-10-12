#pragma once
#include"Foe.h"

class FoeMid :public Foe
{
public:
	void InitFoe();
	void ShowFoe();
	bool isHitPlayer(int ,int);
};