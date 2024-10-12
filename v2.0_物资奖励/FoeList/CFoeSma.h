#pragma once
#include"CFoe.h"
class CFoeSma :public CFoe
{
public:
	virtual void InitFoe() override;
	virtual void InitFoe1() override;
	virtual void ShowFoe() override;
	virtual void ShowFoe1() override;
	bool IssHitFoe(CPlayer& player) override;
	bool IssHitGun(CGunner* Gun) override;
	CGunner* SendGunner();
};