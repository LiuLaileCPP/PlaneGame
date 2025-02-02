#include"CGunList.h"
#include"../config/Config.h"
CGunList::CGunList(){}
CGunList::~CGunList()
{
	list<CGunner*>::iterator ite = m_listGun.begin();
	while (ite!=m_listGun.end())
	{
		if (*ite)
		{
			delete (*ite);
			(*ite) = nullptr;
		}
		ite++;
	}
	m_listGun.clear();
}
//void CGunList::InitGun(int x, int y){}
void CGunList::ShowAllGun()
{
	for (CGunner*pGun: m_listGun)
	{
		if (pGun)
		{
			pGun->ShowGun();
		}
	}
	for (CGunner* pGun : m_listFoeGun)
	{
		if (pGun)
		{
			pGun->ShowGun();
		}
	}
}
//void CGunList::ShowAllGun2()
//{
//	for (CGunner* pGun : m_listGun1)
//	{
//		if (pGun)
//		{
//			pGun->ShowGun2();
//		}
//	}
//}
void CGunList::MoveAllGun()
{
	list<CGunner*>::iterator ite = m_listGun.begin();
	while (ite != m_listGun.end())
	{    //是否出界
		if (*ite)
		{
			(*ite)->MoveGun();
			if ((*ite)->m_y <= 0)
			{
				delete (*ite);
				(*ite) = nullptr;
				ite=m_listGun.erase(ite);     //自带++效果
				continue;
			}
		}
		ite++;
	}

	ite = m_listFoeGun.begin();
	while (ite != m_listFoeGun.end())
	{    //是否出界
		if (*ite)
		{
			(*ite)->m_y += FOE_GUN_STEP;
			if ((*ite)->m_y >= BACK_HEIGHT)
			{
				delete (*ite);
				(*ite) = nullptr;
				ite = m_listFoeGun.erase(ite);     //自带++效果
				continue;
			}
		}
		ite++;
	}
}
//void CGunList::MoveAllGun2()
//{
//	list<CGunner*>::iterator ite = m_listGun.begin();
//	while (ite != m_listGun.end())
//	{    //是否出界
//		if (*ite)
//		{
//			(*ite)->MoveGun();
//			if ((*ite)->m_y <= -GUNNER_HEIGHT)
//			{
//				delete (*ite);
//				(*ite) = nullptr;
//				ite = m_listGun.erase(ite);     //自带++效果
//				continue;
//			}
//		}
//		ite++;
//	}
//}
