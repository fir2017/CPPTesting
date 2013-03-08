// Ex04_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

template<typename T>
auto max(T x[] ,const int& length) -> decltype(x[0])
{
	decltype(x[0]) maximum(x[0]);
	for (int i = 0; i<length; i++)
	{
		if (maximum < x[i])
			maximum = x[i];
	}
	return maximum;
}

int _tmain(int argc, _TCHAR* argv[])
{

	int ints[] = {1,3,21,6,3,8,5,9,1};

	cout << endl << max(ints,_countof(ints)) << endl;
}

