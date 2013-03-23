// ClassConstructors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

class CBox
{
	public:
		double Volume();
		double GetLength();
		explicit CBox(double length = 0.0, double width = 1.0, double height = 1) : 
			m_Length(length), m_Width(width), m_Height(height)
		{
		}

		CBox(double length) : 
			m_Length(length), m_Width(length), m_Height(length)
		{
		}

	private:
		double m_Length, m_Width, m_Height;
};

inline double CBox::GetLength()
{
	return this->m_Length;
}


inline double CBox::Volume()
{
	return m_Length*m_Width*m_Height;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CBox box(1.1,2.2,3.3);
	CBox box2 = 99.99;
	
	cout << box.Volume() << endl;
	cout << box2.Volume() << endl;
	cout << box2.GetLength() << endl;
	return 0;
}

