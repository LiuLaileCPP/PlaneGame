
#pragma once
#include"CGunner.h"
class CGungrade :public CGunner
{
public:
	virtual void InitGun(int x, int y) override;
	virtual void ShowGun() override;
	virtual void MoveGun() override;
};