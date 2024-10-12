#include"CBack.h"
#include"../config/Config.h"

CBack::CBack():m_x(0),m_y(0){}
CBack::~CBack(){}
void CBack::InitBack()
{
	::loadimage(&m_imgBack,L"./res/背景.jpg");    //具体图片做绑定，变量取地址，文件路径（相对于工程文件）
	m_x=0;
	m_y = -BACK_HEIGHT;
}
void CBack::ShowBack()
{
	::putimage(m_x,m_y, &m_imgBack);     //显示图片，位置，变量取地址，默认值
}
void CBack::MoveBack()
{
	m_y += BACK_MOVE_STEP;
	if (m_y >= 0)                            //达到临界条件恢复到初始状态
	{
		m_y = -BACK_HEIGHT;
	}
}