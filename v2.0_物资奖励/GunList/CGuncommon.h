#pragma once
#include"../GunList/CGunner.h"
class CGuncommon :public CGunner
{
public:
	virtual void InitGun(int x, int y) override;
	virtual void ShowGun() override;
	virtual void MoveGun() override;
};