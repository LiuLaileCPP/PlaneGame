#pragma once
#include<easyx.h>


class CBack
{
public:
	int m_x;
	int m_y;
	IMAGE m_imgBack;
public:
	CBack();
	~CBack();
public:
	virtual void InitBack();
	virtual void ShowBack();
	virtual void MoveBack();
};