#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <io.h>
#include <sstream>
#include <string>
#include "TestingField.h"


using namespace std;

FILE* f_out, * f_in;

#pragma warning(disable:4996)

void baseLevel()
{}

void midLevel()
{}

/*Function to foolproof numeric entering*/
int getInteger(const char* text)
{
	bool isError = false;
	string s;
	int number = 0;
	do {
		isError = false;
		cout << text << " ";
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

struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day <= 28) && (day > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((day <= 29) && (day > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((day == 28) && (day > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((day <= 29) && (day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}
	if (year > 2019) { result = false; }

	return result;
}

struct client
{
	char name[100];
	Date lastPurchaseDate;
	int lasttimeprice;
	double discount;
};

void thirdLvl()
{
	const int size = 2;
	client array[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Enter name: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(array[i].name, 56); ;
		do
		{
			array[i].lastPurchaseDate.day = getInteger("Enter day of last purchase:");
			array[i].lastPurchaseDate.month = getInteger("Enter month of last purchase:");
			array[i].lastPurchaseDate.year = getInteger("Enter year of last purchase:");
			if (array[i].lastPurchaseDate.isCorrect() != true)
			{
				cout << "Error. Try again.\n";
			}
		} while (array[i].lastPurchaseDate.isCorrect() != true);
		array[i].lasttimeprice = getInteger("Enter the price of last purchase:");
		array[i].discount = 0;
	}

	f_out = fopen("3.bin", "wb");
	fwrite(array, sizeof(client), size, f_out);
	fclose(f_out);

	client import[size];
	f_in = fopen("3.bin", "rb");
	fread(import, sizeof(client), size, f_in);
	fclose(f_in);

	for (int i = 0; i < size; i++)
	{
		if (import[i].lasttimeprice > 5000 && import[i].discount <= 10)
		{
			import[i].discount += 5;
			cout << import[i].name << " recieves +5% discount!";
		}
	}

	f_out = fopen("3.bin", "wb");
	fwrite(import, sizeof(client), size, f_out);
	fclose(f_out);
}

struct info
{
	char information[100] = "Somebody once told me the World is gonna roll me";
	int integer;
	float real;
	void generate();
	string print();
};

void info::generate()
{
	integer = rand() % 100;
	real = (float)(rand()) / ((float)(RAND_MAX / 100));
}

string info::print()
{
	string out = "";
	out += information;
	out += "\n";
	out += "Integer: " + to_string(integer) + "\n";
	out += "Real number: " + to_string(real) + "\n";
	return out;
}

void highLevel()
{
	const int size = 1;
	info abstract[size];
	for (int i = 0; i < size; i++)
	{
		abstract[i].generate();
	}

	f_out = fopen("c:\\lab6samples\\3.HighLevel\\Abstract.bin", "wb");
	fwrite(abstract, sizeof(info), size, f_out);
	fclose(f_out);


	info import[size];
	f_in = fopen("c:\\lab6samples\\3.HighLevel\\Abstract.bin", "rb");
	fread(import, sizeof(info), size, f_in);
	fclose(f_in);
	cout << "Before: \n";
	for (int i = 0; i < size; i++)
	{
		cout << import[i].print() << endl;
	}
	cout << "After: \n";
	for (int i = 0; i < size; i++)
	{
		import[i].integer = (int)import[i].real;
		cout << import[i].print() << endl;
	}

	f_out = fopen("c:\\lab6samples\\3.HighLevel\\Abstract.bin", "wb");
	fwrite(import, sizeof(info), size, f_out);
	fclose(f_out);
}

int main()
{

	CreateDirectory(L"c:\\lab6samples", NULL);
	CreateDirectory(L"c:\\lab6samples\\1.BaseLevel", NULL);
	CreateDirectory(L"c:\\lab6samples\\2.MidLevel", NULL);
	CreateDirectory(L"c:\\lab6samples\\3.HighLevel", NULL);

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
		case 3:thirdLvl(); break;
		default: cout << "Wrong entering.\n"; break;
		}
	} while (select != 0);
}

