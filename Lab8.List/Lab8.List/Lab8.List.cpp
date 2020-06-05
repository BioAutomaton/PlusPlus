#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <io.h>
#include <sstream>
#include <list>
#include "List.h"
#include "Forward_list.h"

using namespace std;

#pragma warning(disable:4996)

/*Function to foolproof numeric entering*/
int getInteger(const char* text)
{
	bool isError = false;
	string s;
	int number = 0;
	do {
		isError = false;
		cout << text << endl;
		cin >> s;
		for (size_t i = 0; i < s.length(); i++)
		{
			if ((int)(s[i]) < 0 || !isdigit(s[i]))
			{
				isError = true;
				break;
			}
		}
		if (!isError)
			number = atoi(s.c_str());
		else { cout << "Error: Wrong entering.\n"; }
	} while (isError || number <= 0);

	return number;
}


void baseLevel()
{
	Forward_list<string> data;
	for (int i = 0; i < 6; i++)
	{
		string temp = "";
		for (int j = 0; j < 10; j++)
		{
			temp += (rand() %60) + '0';
		}
		data.push_front(temp);
	}

	int counter = 0;
	for (int i = 0; i < data.getSize(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			if (isalpha(data[i][j]))
			{
				cout << data[i][j];
				counter++;
			}
		}
	}
	cout << endl<< counter << endl;
}

void midLevel()
{
	const int size = 400;
	Forward_list<float> data;
	for (int i = 0; i < size; i++)
	{
		double temp;
		temp = (float)(-50 + rand() % 400) / 10;
		data.push_front(temp);
	}

	float firstNegative = 0;
	for (int i = 0; i < size; i++)
	{
		if (data[i] < 0)
		{
			firstNegative = data[i];
			break;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (data[i] == 20)
		{
			data.InsertBefore(firstNegative, i);

			cout << data[i] << endl;
			cout << data[i+1] << endl;
			i++;		
		}
	}
	//data.~Forward_list();

}

void highLevel()
{
	const int size = 5;
	List<int> data;
	for (int i = 0; i < size; i++)
	{
		data.push_front(i);
	}
	data[4] = 10;

	for (int i = 0; i < size; i++)
	{
		cout << data[i] << endl;
	}

	cout << endl;
	for (int i = 0; i < size; i++)
	{
		if (data[i] == 10)
		{
			data.erase(i);
			break;
		}
	}

	for (int i = 0; i < data.getSize(); i++)
	{
		cout << data[i] << endl;
	}
} 

int main() 
{
	int select = 0;
	do {
		srand(time(NULL));
		cout << "Variant 22. Lab 6.\nSelect difficulty level\n";
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
