#include "Box.h"


CBox::CBox(double lv =1.0, double hv = 1.0, double wv = 1.0) : m_Height(hv)
{
	if (lv < 0.0 || hv < 0.0 || wv < 0.0) throw "Negative dimensions not allowed";
	m_Length = std::max(lv,wv);
	m_Width = std::min(lv,wv);
	if (m_Height > m_Length)
	{
		m_Height = m_Length;
		m_Length = hv;

			
	}
}


CBox::~CBox(void)
{
}
