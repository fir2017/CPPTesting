// CopyProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

class CMessage
{
	private:
		char* pmessage;

	public:
		void ShowIt() const
		{
			cout << endl << pmessage;
		}

		CMessage operator+(const CMessage& aMessage) const
		{
			cout << "Add operator function called." << endl;
			size_t len = strlen(pmessage) + strlen(aMessage.pmessage) + 1;
			CMessage message;
			message.pmessage = new char[len];
			strcpy_s(message.pmessage, len, pmessage);
			strcat_s(message.pmessage, len, aMessage.pmessage);
 			return message;
		}

		CMessage& operator=(const CMessage& aMessage)
		{
			cout << "Assigment operator function called." << endl;
			if (this != &aMessage)
			{
				delete[] pmessage;
				pmessage = new char[strlen(aMessage.pmessage)+1];
				strcpy_s(this->pmessage,strlen(aMessage.pmessage)+1, aMessage.pmessage);
			}
			return *this;
		}

		CMessage(const char* text = "Default Message")
		{
			cout << "Constructor called" << endl;
			pmessage = new char[strlen(text)+1];
			strcpy_s(pmessage,strlen(text)+1,text);
		}

		CMessage(CMessage&& aMessage)
		{
			cout << "Move copy constructor called." << endl;
			pmessage = aMessage.pmessage;
			aMessage.pmessage = nullptr;
		}

		CMessage(const CMessage& aMessage)
		{
			cout << "Copy constructor called." << endl;
			size_t len = strlen(aMessage.pmessage)+1;
			pmessage = new char[len];
			strcpy_s(pmessage,len,aMessage.pmessage);
		}

		~CMessage()
		{
			cout << "Destructor called." << endl;
			delete[] pmessage;
		}
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMessage* one = new CMessage("Unique text");

	CMessage two("blahblahblah");
	CMessage three("three");

	one->ShowIt();
	cout << endl;
	CMessage four = *one + two + three;
	four.ShowIt();
	//	cout << one->ShowIt() << endl;
	delete one;
	one = nullptr;
	return 0;
}

