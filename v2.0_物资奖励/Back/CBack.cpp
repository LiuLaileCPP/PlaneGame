#include"CBack.h"
#include"../config/Config.h"

CBack::CBack():m_x(0),m_y(0){}
CBack::~CBack(){}
void CBack::InitBack()
{
	::loadimage(&m_imgBack,L"./res/����.jpg");    //����ͼƬ���󶨣�����ȡ��ַ���ļ�·��������ڹ����ļ���
	m_x=0;
	m_y = -BACK_HEIGHT;
}
void CBack::ShowBack()
{
	::putimage(m_x,m_y, &m_imgBack);     //��ʾͼƬ��λ�ã�����ȡ��ַ��Ĭ��ֵ
}
void CBack::MoveBack()
{
	m_y += BACK_MOVE_STEP;
	if (m_y >= 0)                            //�ﵽ�ٽ������ָ�����ʼ״̬
	{
		m_y = -BACK_HEIGHT;
	}
}