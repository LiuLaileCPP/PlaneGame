#pragma once
#include"../GameFrame/GameFrame.h"    //../上一层目录，./当前目录
#include"../Back/CBack.h"
#include"../Player/CPlayer.h"
#include"../GunList/CGunList.h"
#include"../FoeList/CFoeList.h"
#include"../Flame/FlameList.h"
#include"../supplies/CSupplies.h"
//#include "../FoeList/CFoe Big.h"
//#include "../FoeList/CFoeMid.h"
//#include "../FoeList/CFoeSma.h"


class CPlaneApp :public CGameFrame
{
public:
	 int m_score;  //
	int m_level;
	bool IsHit = false;
	IMAGE m_imgBoard;
	IMAGE  m_img1;
	IMAGE  m_img2;
	IMAGE  m_img3;
	CBack m_back;
	CPlayer m_player;
	/*CFoeBig m_foebig;
	CFoeMid m_foemid;
	CFoeSma m_foesma;*/
	CGunList m_gunLst;
	CFoeList m_FoeList;
	/*CSupplies m_CSupplies;*/
	CSupplies* pp = nullptr;
public:
	CPlaneApp();
	~CPlaneApp();
public:
	virtual void Init();
	virtual void Paint();
	virtual void Close();
	virtual  void AddMsg();  //虚函数根据自己的需求，选择性的重写，添加自己所需要的消息，最后要显示的调用父类的CGameFrame::AddMsg;并且在子类添加对应的消息处理函数。
	void ON_WM_KEYDOWN(BYTE key);
	void ON_WM_TIMER(WPARAM, LPARAM);
	void ShowScore();
	void ShowGameLevel();
	void SetTimer();
	void KillTimer();
};
/*int CPlaneApp::m_score = 0;*/  //
