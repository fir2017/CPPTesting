// Ex07_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h";
#include "Structures.h";

using namespace std;
long CalculateArea(const RECTANGLE& rectangle);
void Move(RECTANGLE& rectangle, const int& x, const int& y);

int _tmain(int argc, _TCHAR* argv[])
{
	BOOK b = {"AuthorTest","TitleTest","PublisherTest",1973};
	cout << b.Author << endl << b.Year << endl;

	RECTANGLE rectangle = {0,0,10,10};

	cout << "Area of the rectangle is "<< CalculateArea(rectangle) << endl;

	Move(rectangle,5,5);

	cout << "Area of the rectangle is "<< CalculateArea(rectangle) << endl;
	cout << rectangle.Left << "\t" << rectangle.Top << "\t" << rectangle.Right << "\t" << rectangle.Bottom << endl;
	return 0;
}

void Move(RECTANGLE& rectangle, const int& x, const int& y)
{
	int width = rectangle.Right - rectangle.Left;
	int height = rectangle.Bottom - rectangle.Top;

	rectangle.Top = y;
	rectangle.Left = x;
	rectangle.Bottom = y + height;
	rectangle.Right = x + width;
}

long CalculateArea(const RECTANGLE& rectangle)
{
	return (rectangle.Right-rectangle.Left)*(rectangle.Bottom-rectangle.Top);
}



