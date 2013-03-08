// Ex04_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

double* treble(double);

int _tmain(int argc, _TCHAR* argv[])
{
	double num = 5;
	double* ptr = nullptr;

	ptr = treble(num);
	cout << endl << "Three times num = " << 3 * num << endl;
	cout << endl << "Result = " << *ptr << endl;
//	return 0;
}

double* treble(double data)
{
	double* result = new double(0.0);
	*result = 3.0 * data;
	return result;
}


