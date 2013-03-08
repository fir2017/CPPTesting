// Ex04_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int sum(int count, ...)
{
	if (count <= 0) return 0;
	va_list arg_ptr;
	va_start(arg_ptr,count);

	int sum = 0;
	for (int i = 0; i<count;i++)
	{
		sum += va_arg(arg_ptr,int);
	}

	va_end(arg_ptr);
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << sum(9,6,2,3,4,5,6,3,2,4) << endl;
	cout << sum(9,23,43,56,43,2,5,6,2,1) << endl;
}


