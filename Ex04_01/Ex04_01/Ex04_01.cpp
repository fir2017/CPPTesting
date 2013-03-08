// Ex04_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	const int MAX = 100;
	long primes[MAX] = {2,3,5};
	int count(3);
	bool found(false);
	long trial(5);

	do {
		trial += 2;
		found = false;
		for (int i = 0; i < count; i++)
		{
			found = (trial % *(primes + i)) == 0;
			if (found) break;
		}

		if (!found)
		{
			*(primes + count++) = trial;
		}
	} while (count < MAX);

	for (int i = 0; i < MAX; i++)
	{
		if (i % 5 == 0)
			cout << endl;
		cout << setw(4) << *(primes + i);
	}
	cout << endl;

}


