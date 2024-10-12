#include "CFoe.h"

CFoe::CFoe():m_x(0),m_y(0),m_blood(0),m_showId(0){}
CFoe::~CFoe(){}
void CFoe::MoveFoe(int step)
{
	m_y += step;
}
random_device CFoe::rd;