// Ex2_02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using std::cout;
using std::endl;
using std::cin;
using std::setw;

int _tmain(int argc, _TCHAR* argv[])
{
	int apples, oranges;
	int fruit;
	apples = 5; oranges = 6;
	fruit = apples + oranges;


	cout << "We've got " << std::setiosflags(std::ios::left) <<  setw(6) << fruit << " things " << endl;

	return 0;
}

