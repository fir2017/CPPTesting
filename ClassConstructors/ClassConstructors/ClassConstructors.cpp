// ClassConstructors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

class CBox
{
	public:
		double m_Length, m_Width, m_Height;
		double Volume();
		CBox(double length, double width, double height)
		{
			m_Height = height;
			m_Length = length;
			m_Width = width;
		}
};

inline double CBox::Volume()
{
	return m_Length*m_Width*m_Height;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CBox box(1.1,2.2,3.3);
	cout << box.Volume() << endl;
	return 0;
}

