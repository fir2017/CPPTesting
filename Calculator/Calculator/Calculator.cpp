// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

void eatspaces(char* str);
double expr (char* str);
double term (char* str, int& index);
double number(char* str, int& index);

int _tmain(int argc, _TCHAR* argv[])
{
	const int MAX(80);
	char buffer[MAX];
	cout << "Enter a calculation : " << endl;
	for (;;)
	{
		cin.getline(buffer,MAX);
		eatspaces(buffer);

		if (!buffer[0])
			return 0;

		try
		{
			cout << "\t=" << expr(buffer) << endl << endl;
		}
		catch(const char* pEx)
		{
			cerr << pEx << endl;
			cerr << "Ending program." << endl;
			return 1;
		}
	}
	return 0;
}

double number(char* str, int& index)
{
	auto value = 0.0;
	if (!isdigit(*(str+index)))
	{
		char message[31] = "Invalid character i number: ";
		strncat_s(message,str+index,1);
		throw message;
	}

	while (isdigit(*(str+index)))
		value = 10*value + (*(str+index++) - '0');

	if (*(str+index) != '.')
		return value;

	double factor = 1.0;
	while (isdigit(*(str+(++index))))
	{
		factor *= 0.1;
		value = value + (*(str+index) - '0')*factor;
	}
	return value;
}

double term (char* str, int& index)
{
	auto value = 0.0;
	value = number(str,index);

	while(true)
	{
		if (*(str+index) == '*')
			value *= number(str,++index);
		else if (*(str+index) == '/')
			value /= number(str,++index);
		else break;
	}
	return value;
}

double expr(char* str)
{
	auto value = 0.0;
	int index = 0;
	value = term(str,index);

	for(;;)
	{
		switch (*(str + index++))
		{
			case '\0':
				return value;
			case '+':
				value += term(str,index);
				break;
			case '-':
				value -= term(str,index);
				break;
			default:
				char message[38] = "Expression evaluation error. Found: ";
				strncat_s(message, str+index-1,1);
				throw message;
				break;
		}
	}
	return value;
}

void eatspaces(char* str)
{
	int i = 0, j = 0;
	while ((*(str+i) = *(str + j++)) != '\0')
	{
		if (*(str + i) != ' ')
			i++;
	}
	return;
}

