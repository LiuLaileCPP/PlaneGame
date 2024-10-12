#pragma once
#include <windows.h>
#include<easyx.h>
#include<map>

using namespace std;

class CGameFrame;
extern CGameFrame* pGame;

#define INIT_MSGMAP(MSGID,MSGTYPE,CLASS) \
	m_msgmap[MSGID].type = MSGTYPE;\
	m_msgmap[MSGID].p##MSGTYPE = (P_##MSGTYPE)&CLASS::On_##MSGID;
#define mouse	    1
#define key			2
#define char		4
#define window	    8

class CGameFrame {
public:
	HWND m_hwnd;
	bool m_isQuit;

	typedef void (CGameFrame ::* P_mouse)(int, int);
	typedef void (CGameFrame::* P_key)(int);
	typedef void (CGameFrame::* P_window)(WPARAM,LPARAM);

	struct MsgTypeFun {
		int type;
		union {
			P_mouse pmouse;
			P_key pkey;
			P_window pwindow;
		};
	};
	map<int, MsgTypeFun> m_msgmap;
	CGameFrame() :m_isQuit(0) {

	}
	virtual ~CGameFrame(){}
	virtual void InitMsgMap(){}

	void InitGame(int width, int height, int x, int y, const wchar_t* pTitle)
	{
		m_hwnd = ::initgraph(width,height);
		::setbkcolor(RGB(255,255,255));
		::cleardevice();//立即刷新
		::MoveWindow(m_hwnd,x,y,width,height,1);
		::SetWindowText(m_hwnd,pTitle);
		INIT_MSGMAP(WM_CLOSE, window, CGameFrame)
		InitMsgMap();
		::SetWindowLong(m_hwnd, GWL_WNDPROC, (LONG)&CGameFrame::RunGame);
		On_Init();
	}
	void PaintGame()
	{
		::BeginBatchDraw();
		::cleardevice();
		On_Paint();
		::EndBatchDraw();
	}
	static LRESULT	WINAPI RunGame(HWND hwnd, UINT msg, WPARAM w, LPARAM l) {
		if (pGame->m_msgmap.count(msg)) {   //如果存在于map中
			switch (pGame->m_msgmap[msg].type)
			{
			case EX_MOUSE:
			{
				(pGame->*pGame->m_msgmap[msg].pmouse)(GET_X_LPARAM(l), GET_Y_LPARAM(l));
			}
			break;
			case EX_KEY:
			{
				(pGame->*pGame->m_msgmap[msg].pkey)(w);
			}
			break;
			case EX_WINDOW:
			{
				(pGame->*pGame->m_msgmap[msg].pwindow)(w, l);
			}
			}
			pGame->PaintGame();
		}
		return ::DefWindowProc(hwnd, msg, w, l);
	}
	//关闭游戏
	void On_WM_CLOSE(WPARAM, LPARAM) {
		On_Close(); 
		::closegraph(); 
		pGame->m_isQuit = true;
	}


public:
	virtual void On_Init() = 0; 
	virtual void On_Paint() = 0;
	virtual void On_Close() = 0;
};

#define WND_PARAM(W,H,X,Y,TITLE)\
	int wndWidth = W;\
	int wndHeight=H;\
	int wndX=X;\
	int wndY=Y;\
	const wchar_t* wndTitle=TITLE;



#define CREATE_OBJECT(CLASS)\
	CGameFrame* CreateObject() {\
		return new CLASS;\
	}
