// Ex04_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

void treble(double*);
auto pfun = treble;
void runner (void (*blah)(double*));

int _tmain(int argc, _TCHAR* argv[])
{
	double num = 5;
	double* ptr = nullptr;
	ptr = &num;

	cout << *ptr << endl;

	treble(ptr);
	cout << *ptr << endl;
	double* cal = nullptr; // new double(*ptr * 20);
	double temp = *ptr * 20;
	cal = &temp;
	pfun(cal);
	cout << *cal << endl;
	runner(pfun);
//	return 0;
}

void treble(double* data)
{
	double* result = new double(0.0);
	*data = 3.0 * *data;
}

void runner(void (*blah)(double*))
{
	cout << "Address of blah ";
	cout << blah << endl;

	double* d = new double(5.0);
	blah(d);
	cout << "double d " << *d << endl;

}


