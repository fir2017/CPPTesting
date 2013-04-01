// Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

template <class T>
class CSamples
{
public:
	CSamples(const T values[], int count)
	{
		m_Free = count < maxSamples ? count : maxSamples;
		for (int i = 0; i < m_free; i++)
		{
			m_Values[i] = values[i];
		}
	}

	CSamples(const T& value)
	{
		m_Values[0] = value;
		m_Free = 1;
	}

	CSamples(): m_Free(0) {}

	bool Add(const T& value)
	{
		bool OK = m_Free < maxSamples;
		if (OK)
			m_Values[m_Free++] = value;
		return OK;
	}

	T Max() const
	{
		T theMax = m_Values[0];
		for (int i = 1; i < m_Free; i++)
		{
			if (m_Values[i] > theMax)
				theMax = m_Values[i];
		}
		return theMax;
	}

private:
	static const size_t maxSamples = 100;
	T m_Values[maxSamples];
	int m_Free;
};


int _tmain(int argc, _TCHAR* argv[])
{
	CSamples<double> myData(10.1);
	myData.Add(2.0);
	myData.Add(12.4);
	myData.Add(3.0);
	double max = myData.Max();
	cout << max << endl;
	return 0;
}

