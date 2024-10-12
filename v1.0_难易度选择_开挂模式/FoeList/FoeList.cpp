#include"FoeList.h"
#include"FoeSmall.h"
#include"FoeBig.h"
#include"FoeMid.h"
#include<typeinfo>

FoeList::FoeList()
{
}

FoeList::~FoeList()
{
	list<Foe*>::iterator ite = m_list.begin();
	while (ite != m_list.end())
	{
		if (*ite)
		{
			delete (*ite);
			*ite = nullptr;
		}
		ite++;
	}
	ite = m_listBoom.begin();
	while (ite != m_listBoom.end())
	{
		if (*ite)
		{
			delete (*ite);
			*ite = nullptr;
		}
		ite++;
	}
}

void FoeList::ShowAllFoe()
{
	for (Foe* p : m_list)
	{
		if (p) p->ShowFoe();
	}
	for (Foe* p : m_listBoom)
	{
		if (p)
		{
			p->ShowFoe();
			playMicBoom();
		}
	}
}

void FoeList::MoveAllFoe()
{
	list<Foe*>::iterator ite = m_list.begin();
	while (ite != m_list.end())
	{
		//判断父类指针的子类指向类型

			//RTTI：运行时类型识别 RunTime Type Identification 关键字typeid
			/* typeid(表达式/类型)；返回包含该类型信息的结构*/
		if (typeid(**ite) == typeid(FoeBig))
		{
			(*ite)->MoveFoe(FOEBIG_MOVE_STEP);
		}
		else if (typeid(**ite) == typeid(FoeSmall))
		{
			(*ite)->MoveFoe(FOESMALL_MOVE_STEP);
		}
		else if(typeid(**ite) == typeid(FoeMid))
		{
			(*ite)->MoveFoe(FOEMID_MOVE_STEP);
		}

		//判断出界
		if ((*ite)->m_y == BACK_HEIGHT)
		{
			delete (*ite);
			*ite = nullptr;
			ite = m_list.erase(ite);
			continue;
		}
		ite++;
	}
}

void FoeList::playMicBoom()
{
	mciSendString(L"open .\\res\\boom.mp3",0,0,0);
	mciSendString(L"play .\\res\\boom.mp3",0,0,0);
	mciSendString(L"close .\\res\\boom.mp3",0,0,0);
}