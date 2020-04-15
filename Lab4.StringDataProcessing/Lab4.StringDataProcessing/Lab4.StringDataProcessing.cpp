#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <string.h>
#include <windows.h>

using namespace std;

void baseLevel()
{
	string entering = "";
	cout << "Enter your string: ";
	cin >> entering;
	int counter = 0;
	for (int i = 0; i < strlen(&entering[0]); i++)
	{
		entering[i] == '!' ? counter++ : counter = counter;
		entering[i] == '?' ? counter-- : counter = counter;
	}

	if (counter > 0)
	{
		cout << "! appears more frequently\n";
	}
	else if(counter < 0)
	{
		cout << "? appears more frequently\n";
	}
	else
	{
		cout << "! and ? appear the same number of times.\n";
	}
}

void midLevel()
{

}

void highLevel()
{

}

int main()
{
	int select = 0;
	do {
		srand(time(NULL));
		cout << "Variant 22. Lab 4.\nSelect difficulty level\n";
		cout << "1 - Base level\n2 - Mid level \n3 - High level\n";
		cout << "Or enter 0 to exit.\n";
		bool isError = false;
		string s;
		do {
			isError = false;
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(&s[0], 10);
			for (size_t i = 0; i < s.length(); i++)
			{
				if ((int)(s[i]) < 0 || !isdigit(s[i]))
				{
					isError = true;
					break;
				}
			}
			if (!isError)
				select = atoi(s.c_str());
			if (isError || select < 0 || select > 3)
			{
				cout << "Wrong entering.\n";
			}
		} while (isError || select < 0 || select > 3);

		switch (select)
		{
		case 0: break;
		case 1:baseLevel(); break;
		case 2:midLevel(); break;
		case 3:highLevel(); break;
		default: cout << "Wrong entering.\n"; break;
		}
	} while (select != 0);
}