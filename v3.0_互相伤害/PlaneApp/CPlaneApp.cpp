#include"CPlaneApp.h"
#include "../GameFrame/GameFrame.h"
#include"../config/Config.h"
#include"../FoeList/CFoe.h"
#include"../FoeList/CFoeSma.h"
#include"../FoeList/CFoeMid.h"
#include"../FoeList/CFoe Big.h"
#include"../FoeList/CFlame.h"
#include"../GunList/CGungrade.h"
#include<typeinfo>
extern int score;
extern int lostBlood;
extern int listFoeSize;

CREATE_OBJECT(CPlaneApp);      //ʹ��˵���ĺ� ��������
WND_PARAM(BACK_WIDTH+16, BACK_HEIGHT + 39, 400,50, L"�ɻ���ս");//���ڲ����ĺ꣬��ȣ��߶ȣ�λ��x,y������
CPlaneApp::CPlaneApp():/*m_score(0),*/ m_level(0){}  //
CPlaneApp::~CPlaneApp()
{
	
}
void CPlaneApp::Init()
{
	m_back.InitBack();    //������ʼ��
	m_player.InitPlayer();
	::loadimage(&m_imgBoard,L"./res/cardboard.png",100,40);
	/*if (pp)
	{
		pp->InitSupplies();
	}*/
	SetTimer();//��ʼ��ʱ���趨���еĶ�ʱ��������һ����������Ч
}
void CPlaneApp::Paint()
{
	m_back.ShowBack();   //�ػ汳��
	m_player.ShowPlayer();
	/*if (!m_CSupplies.IssHitFoe1(m_player))
	{*/
		m_gunLst.ShowAllGun();
	/*}
	else*/
	/*{*/
		/*m_gunLst.ShowAllGun2();*/
	/*}*/
	m_FoeList.ShowAllFoe();
	if (pp)
	{
		pp->ShowSupplies();
	}
	ShowScore();
	ShowGameLevel();
	
}
void CPlaneApp::Close()
{
	KillTimer();
}
void CPlaneApp::AddMsg()
{
	
	ADD_MSG(WM_TIMER,EX_WINDOW,CPlaneApp)     //����Ϣ����Ϣid�����������window���������
		ADD_MSG(WM_KEYDOWN, EX_KEY, CPlaneApp)
		CGameFrame::AddMsg();      //����AddMsg�����˹رպ��ػ�	
}
void CPlaneApp::ON_WM_KEYDOWN(BYTE key)
{
	/*m_player.MovePlayer(key);*/
}
void CPlaneApp::ShowScore()
{
	::putimage(0,0,&m_imgBoard);
	::putimage(93, 0, &m_imgBoard);
	score;
	lostBlood;
	WCHAR arr[5] = { 0 };
	WCHAR arr2[5] = { 0 };
	WCHAR arr3[5] = { 0 };
	_itow_s(score,arr,10);
	_itow_s(listFoeSize,arr3,10);
	_itow_s(PLAYER_BLOOD - lostBlood, arr2, 10);
	wstring str = L"����Ϊ:";
	wstring str2 = L"   ʣ��Ѫ��Ϊ:";
	wstring str3 = L" listFoeSizeΪ:";
	str += arr;
	str2 += arr2;
	str3 += arr3;
	str += str2;
	//str += str3;
	settextcolor(RGB(0,0,0));
	RECT rect{0,0,200,40};
	::setbkmode(TRANSPARENT);
	::drawtext(str.c_str(),&rect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

	//��Ҽ��ٵ�Ѫ�� == ���Ѫ��
	if (lostBlood == PLAYER_BLOOD)
	{
		//������Ϸ
		KillTimer();
		::MessageBox(m_hWnd, L"GameOver", L"��ʾ", MB_OK);
		::PostMessage(m_hWnd, WM_CLOSE, 0, 0);
	}
}
void CPlaneApp::ShowGameLevel()
{
	/*::putimage(0, 0, &m_imgBoard);*/
	m_level;
	char a='0';
	/**/
	wstring str1 = L"�ؿ�Ϊ:";
	m_level = score / 5 + 1;
	WCHAR  s[10]={0};
	_itow_s(m_level,s, 10);

	str1 += s;
	settextcolor(RGB(50, 200, 60));
	RECT rect{ 0,0,1000,40 };
	::setbkmode(TRANSPARENT);
	::drawtext(str1.c_str(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
void CPlaneApp::SetTimer()
{
	::SetTimer(m_hWnd, BACK_MOVE_TIMERID/*��ʱ��ID*/, BACK_MOVE_INTERVAL/*Ƶ��*/,nullptr/*�ص�����*/);    //�趨��ʱ����window API
	::SetTimer(m_hWnd, PLAYER_MOVE_TIMERID, PLAYER_MOVE_INTERVAL, nullptr);
	::SetTimer(m_hWnd, GUNNER_MOVE_TIMERID, GUNNER_MOVE_INTERVAL, nullptr);
	::SetTimer(m_hWnd, GUNNER_SEND_TIMERID, GUNNER_SEND_INTERVAL, nullptr);
	::SetTimer(m_hWnd, CREATE_FOE_TIMERID, CREATE_FOE_INTERVAL, nullptr);
	::SetTimer(m_hWnd, CREATE_FLAME_TIMERID, CREATE_FLAME_INTERVAL, nullptr);
	/*::SetTimer(m_hWnd, FOE_MOVE_TIMERID, FOE_MOVE_INTERVAL, nullptr);*/
	::SetTimer(m_hWnd, FLAME_MOVE_TIMERID, FLAME_MOVE_INTERVAL, nullptr);
	::SetTimer(m_hWnd, FLAME_MOVE_TIMERID, FLAME_MOVE_INTERVAL, nullptr);
	::SetTimer(m_hWnd, CHEAK_HIT_TIMERID, CHEAK_HIT_INTERVAL, nullptr);
	::SetTimer(m_hWnd, CHANGE_PIC_TIMERID, CHANGE_PIC_INTERVAL, nullptr);

	::SetTimer(m_hWnd, FOE_MOVE_TIMERID, FOE_MOVE_INTERVAL, nullptr);

	/*if (m_score <= 5)
	* 
	{
		::SetTimer(m_hWnd, FOE_MOVE_TIMERID, FOE_MOVE_INTERVAL, nullptr);
	}
	else
	{
		::SetTimer(m_hWnd, FOE_MOVE_TIMERID, FOE_MOVE_INTERVAL1, nullptr);
	}*/
}


void CPlaneApp::KillTimer()
{
	::KillTimer(m_hWnd, BACK_MOVE_TIMERID);
	::KillTimer(m_hWnd, PLAYER_MOVE_TIMERID);
	::KillTimer(m_hWnd, GUNNER_MOVE_TIMERID);
	::KillTimer(m_hWnd, GUNNER_SEND_TIMERID);
	::KillTimer(m_hWnd, CREATE_FOE_TIMERID);
	::KillTimer(m_hWnd, FOE_MOVE_TIMERID);
	::KillTimer(m_hWnd, CREATE_FLAME_TIMERID);
	::KillTimer(m_hWnd, CHEAK_HIT_TIMERID);
	::KillTimer(m_hWnd, CHANGE_PIC_TIMERID);
	::KillTimer(m_hWnd, FLAME_MOVE_TIMERID);
	::KillTimer(m_hWnd, FLAME_MOVE_TIMERID);
}
//��ʱ����Ϣ������
void CPlaneApp::ON_WM_TIMER(WPARAM w/*������ʱ��ID*/, LPARAM)
{
	switch (w)
	{
	case BACK_MOVE_TIMERID:     //��������ƶ��Ķ�ʱ����������
	{
		m_back.MoveBack();
	}
	break;
	case PLAYER_MOVE_TIMERID:   //��ʱ����Ƿ��·����
	{
		if (::GetAsyncKeyState(VK_UP))      //��ȡ�첽����״̬������Ϊ��0
		{
			m_player.MovePlayer(VK_UP);
		}
		if (::GetAsyncKeyState(VK_DOWN))
		{
			m_player.MovePlayer(VK_DOWN);
		}
		if (::GetAsyncKeyState(VK_LEFT))
		{
			m_player.MovePlayer(VK_LEFT);
		}
		if (::GetAsyncKeyState(VK_RIGHT))
		{
			m_player.MovePlayer(VK_RIGHT);
		}
	}
	break;
	case GUNNER_MOVE_TIMERID:
	{
		/*if (!m_CSupplies.IssHitFoe1(m_player))
		{*/
			m_gunLst.MoveAllGun();
			
	/*	}*/
		/*else
		{
			m_gunLst.MoveAllGun2();
		}*/
	}
	break;
	case GUNNER_SEND_TIMERID:
	{
		if (IsHit == true)
		{
			m_gunLst.m_listGun.push_back(m_player.SendGunner2());
		}
		else {
			m_gunLst.m_listGun.push_back(m_player.SendGunner());
		}
		listFoeSize = m_FoeList.m_LstFoe.size();
		list<CFoe*> ::iterator ite = m_FoeList.m_LstFoe.begin();
		while (ite != m_FoeList.m_LstFoe.end())
		{
			if (*ite == 0)
			{
				break;
			}
			m_gunLst.m_listFoeGun.push_back((*ite)->SendGunner());
			ite++;
		}
	}
	break;
	case CREATE_FLAME_TIMERID:
	{
		
		if (pp==nullptr)
		{
			pp = new CSupplies;
		}
		else if (pp)
		{
			pp->InitSupplies();
		}
	}
	break;
	case CREATE_FOE_TIMERID:
	{
		int m = CFoe::rd() % 11;
		CFoe* pFoe = nullptr;
		if (m >= 0 && m <= 2)
		{
				pFoe = new CFoeSma;
		}
		else if (m >= 3 && m <= 6)
		{
				pFoe = new CFoeMid;
		}
		else if(m>=7 && m<=9)
		{
				pFoe = new CFoeBig;
		}
		if (pFoe)
		{
			if (score <= 30)
			{
				pFoe->InitFoe();
			}
			else
			{
				pFoe->InitFoe();
			}
			m_FoeList.m_LstFoe.push_back(pFoe);
		}
	}
	break;
	/*case CREATE_FLAME_TIMERID:
	{
		int n = Flame::rd() % 11;
		Flame* pFlame = new Flame;
		pFlame->InitFlame();
		m_FlameList.m_listFlame.push_back(pFlame);
	}
	break;*/
	case FOE_MOVE_TIMERID:
	{
		m_FoeList.MoveAllFoe();
	}
	break;
	case FLAME_MOVE_TIMERID:
	{
		if (pp)
		{
			pp->MoveSupplies();
		}
	}
	break;
	
	case CHEAK_HIT_TIMERID:
	{
		
		bool IsBoom = false;
		list<CFoe*>::iterator iteFoe = m_FoeList.m_LstFoe.begin();
		while (iteFoe!= m_FoeList.m_LstFoe.end())
		{
			if (*iteFoe)
			{
				if ((*iteFoe)->IssHitFoe(m_player))
				{
					KillTimer();
					::MessageBox(m_hWnd, L"GameOver", L"��ʾ", MB_OK);
					::PostMessage(m_hWnd, WM_CLOSE, 0, 0);
					return;
				}
			}

			list<CGunner*>::iterator iteGun = m_gunLst.m_listGun.begin();
			while (iteGun != m_gunLst.m_listGun.end())
			{
				if (*iteFoe&&*iteGun)
				{
					if ((*iteFoe)->IssHitGun(*iteGun))
					{
						delete (*iteGun);
						(*iteGun) = nullptr;
						iteGun = m_gunLst.m_listGun.erase(iteGun);
						if (((*iteFoe)->m_blood -=GUNNER_HURT)<=0)
						{
							if (typeid(**iteFoe) == typeid(CFoeBig))
							{
								score += FOEBIG_SCORE;
							}
							else if (typeid(**iteFoe) == typeid(CFoeMid))
							{
								score += FOEMID_SCORE;
							}
							else if (typeid(**iteFoe) == typeid(CFoeSma))
							{
								score += FOESMA_SCORE;
							}

							if (score > 30) {
								//ԭ����ֹͣ��
								::KillTimer(m_hWnd, FOE_MOVE_TIMERID);

								//�����趨�µĸ�Ƶ�ʵĶ�ʱ��

								::SetTimer(m_hWnd, FOE_MOVE_TIMERID, FOE_MOVE_INTERVAL1, nullptr);
								(*iteFoe)->MoveFoe(FOEBIG_MOVE_STEP1);
								(*iteFoe)->MoveFoe(FOEMID_MOVE_STEP1);
								(*iteFoe)->MoveFoe(FOESMA_MOVE_STEP1);
							
							}


							m_FoeList.m_LstFoeBoom.push_back(*iteFoe);
							iteFoe = m_FoeList.m_LstFoe.erase(iteFoe);
							IsBoom = true;
							break;
						}

						continue;
					}
				}
				iteGun++;
			}
			/*if (pp)
			{
				if (pp->IssHitFoe1(m_player))
					delete pp;
				pp = nullptr;
			}*/
			if (IsBoom) {
				IsBoom = false;
			}
			else {
				iteFoe++;
			}
		}
		///
		while (pp && pp->IssHitFoe1(m_player))
		{
				delete pp;
				pp = nullptr;
				IsHit = true;
		}
		
		/*if (pp && pp->IssHitFoe1(m_player))
		{
			delete pp;
			pp = nullptr;
		}
		m_gunLst.m_listGun.push_back(m_player.SendGunner2());*/

		//���Player��Ѫ�����
		list<CGunner*>::iterator iteHurt = m_gunLst.m_listFoeGun.begin();
		while (iteHurt != m_gunLst.m_listFoeGun.end())
		{
			if (*iteHurt == 0)
				break;
			int gun_x = (*iteHurt)->m_x;
			int gun_y = (*iteHurt)->m_y;

			//�������
			if (gun_x >= m_player.m_x && gun_x <= m_player.m_x + PLAYER_WIDTH
				&& gun_y >= m_player.m_y && gun_y <= m_player.m_y + PLAYER_HEIGHT)
			{
				//�����ӵ�

				delete (*iteHurt);
				*iteHurt = 0;
				iteHurt = m_gunLst.m_listFoeGun.erase(iteHurt);

				//����Ѫ��
				lostBlood++;
				continue;
			}
			iteHurt++;
		}
	}
	break;
	case CHEAK_HITF_TIMERID:
	{
		/*if (pp->IssHitFoe1(m_player))
		{
			CGunner* pGun = new CGungrade;
		}*/
		if (pp && pp->IssHitFoe1(m_player))
			delete pp;
		pp = nullptr;
	}
	break;
	case CHANGE_PIC_TIMERID:
	{
		list<CFoe*>::iterator ite = m_FoeList.m_LstFoeBoom.begin();
		while (ite != m_FoeList.m_LstFoeBoom.end())
		{
			if (*ite)
			{
				if (--(*ite)->m_showId <= 0)
				{
					delete (*ite);
					(*ite) = nullptr;
					ite = m_FoeList.m_LstFoeBoom.erase(ite);
					continue;
				}
			}
			ite++;
		}
	}
	break;
	}
}
