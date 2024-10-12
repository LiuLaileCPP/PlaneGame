#include "GameFrame.h"
#include"..\\PlaneApp\\PlaneApp.h"

CGameFrame* pGame = nullptr;

CGameFrame* CreateObject();
extern int wndWidth;
extern int wndHeight;
extern int wndX;
extern int wndY;
extern const wchar_t* wndTitle;


int main() {
	pGame = CreateObject();
	pGame->InitGame(wndWidth, wndHeight, wndX, wndY, wndTitle);
	pGame->PaintGame();
	while (!pGame->m_isQuit) { 
		Sleep(1000);
	}

	delete pGame;
	pGame = nullptr;

	return 0;
}


