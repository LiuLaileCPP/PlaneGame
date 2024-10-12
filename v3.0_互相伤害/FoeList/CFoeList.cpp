#include"CFoeList.h"
#include<typeinfo>
#include"CFoe Big.h"
#include"CFoeMid.h"
#include"CFoeSma.h"
#include"CFlame.h"
#include"../config/Config.h"
#include"../PlaneApp/CPlaneApp.h"
extern int score;

CFoeList::CFoeList(){}
CFoeList::~CFoeList()
{
	list<CFoe*>::iterator ite = m_LstFoe.begin();
	while (ite != m_LstFoe.end())
	{
		if (*ite)
		{
			delete (*ite);
			(*ite) = nullptr;
		}
		ite++;
	}
	m_LstFoe.clear();
	ite = m_LstFoeBoom.begin();
	while (ite != m_LstFoeBoom.end())
	{
		if (*ite)
		{
			delete (*ite);
			(*ite) = nullptr;
		}
		ite++;
	}
	m_LstFoeBoom.clear();

}
		
void CFoeList::ShowAllFoe()
{
	if (score <= 30)
	{
		for (CFoe* pFoe : m_LstFoe)
		{
			if (pFoe)
			{
				pFoe->ShowFoe();
			}
		}
		for (CFoe* pFoe : m_LstFoeBoom)
		{
			if (pFoe)
			{
				pFoe->ShowFoe();
			}
		}
	}
	else 
	{
		for (CFoe* pFoe : m_LstFoe)
		{
			if (pFoe)
			{
				pFoe->ShowFoe();
			}
		}
		for (CFoe* pFoe : m_LstFoeBoom)
		{
			if (pFoe)
			{
				pFoe->ShowFoe();
			}
		}
	}
}
void CFoeList::MoveAllFoe()
{
	list<CFoe*>::iterator ite = m_LstFoe.begin();
	while (ite != m_LstFoe.end())
	{
		if (*ite)
		{
			if (typeid(**ite) == typeid(CFoeBig)) {
				(*ite)->MoveFoe(FOEBIG_MOVE_STEP);
				/*if (CPlaneApp::m_score >= 5);
				(*ite)->MoveFoe(FOEBIG_MOVE_STEP1);*/
			}else if (typeid(**ite) == typeid(CFoeMid)) {
				/*(*ite)->MoveFoe(FOEMID_MOVE_STEP);
				if (m_score >= 5);*/
				(*ite)->MoveFoe(FOEMID_MOVE_STEP);
			}else if (typeid(**ite) == typeid(CFoeSma)) {
				(*ite)->MoveFoe(FOESMA_MOVE_STEP);
				/*if (m_score >= 5);
				(*ite)->MoveFoe(FOEMID_MOVE_STEP1);*/
			}
			if ((*ite)->m_y >= 800)
			{
				delete (*ite);
				(*ite) = nullptr;
				ite = m_LstFoe.erase(ite);
				continue;
			}
		}
		ite++;
	}
}