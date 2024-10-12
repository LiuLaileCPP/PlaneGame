//#include"FlameList.h"
//#include"../config/Config.h"
//
//FlameList::FlameList() {}
//FlameList::~FlameList()
//{
//	list<Flame*>::iterator ite = m_listFlame.begin();
//	while (ite != m_listFlame.end())
//	{
//		if (*ite)
//		{
//			delete (*ite);
//			(*ite) = nullptr;
//		}
//		ite++;
//	}
//	m_listFlame.clear();
//}
////void CGunList::InitGun(int x, int y){}
//void FlameList::ShowAllFlame()
//{
//	for (Flame* pFlame : m_listFlame)
//	{
//		if (pFlame)
//		{
//			pFlame->ShowFlame();
//		}
//	}
//}
//void FlameList::MoveAllFlame()
//{
//	list<Flame*>::iterator ite = m_listFlame.begin();
//	while (ite != m_listFlame.end())
//	{    //是否出界
//		if (*ite)
//		{
//			(*ite)->MoveFlame(3);
//			if ((*ite)->m_y1 <= -GUNNER_HEIGHT)
//			{
//				delete (*ite);
//				(*ite) = nullptr;
//				ite = m_listFlame.erase(ite);     //自带++效果
//				continue;
//			}
//		}
//		ite++;
//	}
//}
