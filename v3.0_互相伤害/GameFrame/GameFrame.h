#pragma once
#include<easyx.h>
#include<map>
#define ADD_MSG(MSGID,MSGTYPE,CLASS)\
	m_msgMap[MSGID] = new MsgTypefun{ MSGTYPE };\
	m_msgMap[MSGID]->p_fun_##MSGTYPE= (PFUN_##MSGTYPE)&CLASS::ON_##MSGID;
using namespace std;
class CGameFrame
{
public:
	HWND m_hWnd;
	bool m_isquit;
	ExMessage msg;
	typedef void(CGameFrame::* PFUN_EX_MOUSE)(int, int);
	typedef void(CGameFrame::* PFUN_EX_KEY)(byte);
	typedef void(CGameFrame::* PFUN_EX_CHAR)(WPARAM);
	typedef void(CGameFrame::* PFUN_EX_WINDOW)(WPARAM, LPARAM);
	typedef void(CGameFrame::* PFUN_EX_PAINT)(WPARAM, LPARAM);
	struct MsgTypefun
	{
		int MsgType;
		union
		{
			PFUN_EX_MOUSE p_fun_EX_MOUSE;
			PFUN_EX_KEY p_fun_EX_KEY;
			PFUN_EX_CHAR p_fun_EX_CHAR;
			PFUN_EX_WINDOW p_fun_EX_WINDOW;
			PFUN_EX_PAINT p_fun_EX_PAINT;
		};
	};
	map<UINT, MsgTypefun*>  m_msgMap;
	CGameFrame() :m_hWnd(NULL), m_isquit(false)
	{

	}
	virtual ~CGameFrame()
	{
		for (pair<UINT, MsgTypefun*> par : m_msgMap)
		{
			if (par.second) delete par.second;
		}
	}
	void InitGame(int width, int height, int x, int y, LPCWSTR title);
	void ON_WM_PAINT(WPARAM, LPARAM);
	/*void RunGame();*/
	static LRESULT RunGame(HWND hwnd, UINT msg, WPARAM w, LPARAM l);
	virtual void AddMsg();
	void ON_WM_CLOSE(WPARAM, LPARAM);
	virtual void Init() = 0;
	virtual void Paint() = 0;
	virtual void Close() = 0;
	/*virtual void ON_WM_LBUTTONDOWN(int, int) {};
	virtual void ON_WM_KEYDOWN(BYTE key) {};
	virtual	void ON_WM_CHAR(WPARAM KEY) {};*/
};
#define CREATE_OBJECT(OBJ_CLASS)\
	CGameFrame* CreateObject(){\
	return new OBJ_CLASS;\
	}

#define WND_PARAM(WIDTH,HEIGHT,X,Y,TITLE)\
	int wnd_width=WIDTH;\
	int wnd_height=HEIGHT;\
	int wnd_x=X;\
	int wnd_y=Y;\
	TCHAR* pTitle=(TCHAR*)TITLE;

