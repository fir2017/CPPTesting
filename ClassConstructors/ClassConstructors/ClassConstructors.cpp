// ClassConstructors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

class CBox
{
	public:
		static int objectCount;
		double Volume() const;
		double GetLength();
		bool Compare(const CBox& compare);
		CBox(double length) : 
			m_Length(length), m_Width(length), m_Height(length)
		{
			cout << "Constructor 2 called " << endl;
			objectCount++;
		}


		explicit CBox(double length = 0.0, double width = 1.0, double height = 1) : 
			m_Length(length), m_Width(width), m_Height(height)
		{
			cout << "Constructor 1 called " << endl;
			objectCount++;
		}

	private:
		double m_Length, m_Width, m_Height;

	friend double SurfaceArea(const CBox& box);
};

int CBox::objectCount(0);

bool CBox::Compare(const CBox& compare)
{
	return this->Volume() > compare.Volume();
}

double SurfaceArea(const CBox& box)
{
	return 2*(box.m_Height * box.m_Length +
		box.m_Height * box.m_Width +
		box.m_Length * box.m_Width);
}

inline double CBox::GetLength()
{
	return this->m_Length;
}


inline double CBox::Volume() const
{
	return m_Length*m_Width*m_Height;
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Object count : " << CBox::objectCount << endl;
	CBox box(1.1,2.2,3.3);
	cout << "Object count : " << box.objectCount << endl;
	CBox box2 = 99.99;
	cout << "Object count : " << box.objectCount << endl;
	CBox boxes[5];
	cout << "Object count : " << box.objectCount << endl;

	cout << box.Volume() << endl;
	cout << box2.Volume() << endl;
	cout << box2.GetLength() << endl;

	cout << SurfaceArea(box) << endl;
	if (box.Compare(box2))
	{
		cout << "box1 is bigger than box2" << endl;
	}
	else
	{
		cout << "box2 is bigger than box1" << endl;
	}
	return 0;
}