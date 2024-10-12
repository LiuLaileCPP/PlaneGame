#include"GunList.h"
#include"..\\Config\Config.h"

GunList::GunList(){}
GunList::~GunList()
{
	list<Gun*>::iterator ite = m_listGun.begin();
	while (ite != m_listGun.end())
	{
		if (*ite)
		{
			delete* ite;
			*ite = nullptr;
		}
		ite++;
	}
}

void GunList::ShowAllGun()
{
	playMicGun();
	for (Gun*p : m_listGun)
	{
		if (p) p->ShowGun();
	}
}

void GunList::MoveAllGun()
{
	list<Gun*>::iterator ite = m_listGun.begin();
	while (ite != m_listGun.end())
	{
		if (*ite)
		{
			(*ite)->MoveGun();
			if ((*ite)->m_y == -GUNNER_HEIGHT)
			{
				delete (*ite);
				*ite = nullptr;
				ite = m_listGun.erase(ite);
				continue;
			}
		}
		ite++;
	}
}

void GunList::playMicGun()
{
	mciSendString(L"open .\\res\\boost.mp3",0,0,0);
	mciSendString(L"play .\\res\\boost.mp3",0,0,0);
	mciSendString(L"close .\\res\\boost.mp3",0,0,0);
}