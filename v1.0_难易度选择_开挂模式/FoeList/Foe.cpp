#include"Foe.h"

random_device Foe::rd_foe;

Foe::Foe()
{
	m_x = 0;
	m_y = 0;
	m_blood = 0;
	m_showId = 0;
}

Foe::~Foe()
{

}

void Foe::MoveFoe(int step)
{
	m_y += step;
}