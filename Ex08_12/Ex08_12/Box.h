#pragma once

#include <algorithm>;

using namespace std;

class CBox
{
public:
	CBox(double, double, double);
	~CBox(void);
private:
	double m_Height;
	double m_Width;
	double m_Length;
};