#include<malloc.h>
#include<windowsx.h>
#include"GameFrame.h"

void CGameFrame::InitGame(int width, int height, int x, int y, LPCWSTR title)
{
	m_hWnd = ::initgraph(width, height);
	::setbkcolor(RGB(255, 255, 255));
	::cleardevice();
	::MoveWindow(m_hWnd, x, y, width, height, TRUE);
	::SetWindowText(m_hWnd, title);
	AddMsg();
	::SetWindowLong(m_hWnd,GWLP_WNDPROC,(LONG) & CGameFrame::RunGame);
	Init();
}
void CGameFrame::AddMsg()
{

	/*ADD_MSG(WM_LBUTTONDOWN, EX_MOUSE)
	ADD_MSG(WM_KEYDOWN, EX_KEY)
	ADD_MSG(WM_CHAR, EX_CHAR)*/
	ADD_MSG(WM_CLOSE, EX_WINDOW,CGameFrame)
	ADD_MSG(WM_PAINT, EX_WINDOW,CGameFrame)
}
void  CGameFrame::ON_WM_PAINT(WPARAM, LPARAM)
{
	::BeginBatchDraw();
	::cleardevice();
	Paint();
	::EndBatchDraw();
}
//void CGameFrame::RunGame()
//{
//	PaintGame();
//	while (1)
//	{
//		getmessage(&msg);
//		if (msg.message == WM_LBUTTONDOWN)
//		{
//			ON_WM_LBUTTONDOWN(msg.x, msg.y);
//		}
//		if (msg.message == WM_KEYDOWN)
//		{
//			ON_WM_KEYDOWN(msg.vkcode);
//		}
//		if (msg.message == MIM_CLOSE)
//		{
//			CloseGame();
//			break;
//		}
//	}
//}
CGameFrame* pGame = nullptr;
CGameFrame* CreateObject();
extern int wnd_width;
extern int wnd_height;
extern int wnd_x;
extern int wnd_y;
extern TCHAR* pTitle;
LRESULT CGameFrame::RunGame(HWND hwnd, UINT msg, WPARAM w, LPARAM l)
{
	/*if (msg == WM_LBUTTONDOWN)
	{
		pGame->ON_WM_LBUTTONDOWN(GET_X_LPARAM(l), GET_Y_LPARAM(l));
	}
	if (msg == WM_KEYDOWN)
	{
		pGame->ON_WM_KEYDOWN(w);
	}
	if (msg == MIM_CLOSE)
	{
		pGame->CloseGame();
	}
	pGame->PaintGame();*/
	if (pGame->m_msgMap.count(msg))
	{
		switch (pGame->m_msgMap[msg]->MsgType)
		{
		case EX_MOUSE:
		{
			(pGame->*pGame->m_msgMap[msg]->p_fun_EX_MOUSE)(GET_X_LPARAM(l), GET_Y_LPARAM(l));
		}
		break;
		case EX_KEY:
		{
			(pGame->*pGame->m_msgMap[msg]->p_fun_EX_KEY)(w);
		}
		break;
		case EX_CHAR:
		{
			(pGame->*pGame->m_msgMap[msg]->p_fun_EX_CHAR)(w);
		}
		break;
		case EX_WINDOW:
		{
			(pGame->*pGame->m_msgMap[msg]->p_fun_EX_WINDOW)(w,l);
		}
		break;

		/*case EX_KEY:
		{
		}
		break;
		case EX_CHAR:
		{
		}
		break;
		case EX_WINDOW:
		{
		}
		break;
		}*/
		}
		/*pGame->PaintGame();*/
		RECT rect{ wnd_width,wnd_height};
		::InvalidateRect(hwnd,&rect,false);
	}
	return ::DefWindowProc(hwnd, msg, w, l);
}
		


void CGameFrame::ON_WM_CLOSE(WPARAM, LPARAM)
{
	Close();
	::closegraph();
	m_isquit = true;
}
int score = 0;
int main()
{
	pGame = CreateObject();
	pGame->InitGame(wnd_width, wnd_height, wnd_x, wnd_y, pTitle);
	pGame->ON_WM_PAINT(0, 0);
	//pGame->RunGame;
	while (!pGame->m_isquit)
	{
		Sleep(1000);
	}
	delete pGame;
	pGame = nullptr;

	return 0;
}