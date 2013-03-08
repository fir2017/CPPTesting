// Ex04_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

void treble(double*);

int _tmain(int argc, _TCHAR* argv[])
{
	double num = 5;
	double* ptr = nullptr;
	ptr = &num;

	cout << *ptr << endl;

	double* retval = nullptr;
	treble(ptr);
	cout << *ptr << endl;
//	return 0;
}

void treble(double* data)
{
	double* result = new double(0.0);
	*data = 3.0 * *data;
}


