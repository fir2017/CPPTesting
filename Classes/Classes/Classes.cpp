// Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

class CBox
{
	public:
		double m_Width;
		double m_Length;
		double m_Height;
		double Volume();
};

double CBox::Volume()
{
	return m_Height*m_Length*m_Width;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CBox box;
	box.m_Height = 1.1;
	box.m_Length = 2.2;
	box.m_Width = 3.3;

	cout << "Volume : " << box.Volume() << endl;
	cout << "Size of box : " << sizeof(box) << endl;
	return 0;
}