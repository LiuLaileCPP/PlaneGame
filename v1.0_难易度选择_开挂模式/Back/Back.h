#pragma once
#include<easyx.h>
#include"..\\Config\\Config.h"

class Back {
public:
	IMAGE m_backImg;
	int m_x;
	int m_y;

	Back();
	~Back();

	void InitBack();
	void ShowBack();
	void MoveBack();
};