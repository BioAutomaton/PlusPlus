#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <ctime>

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
	} while (isError || number < 0);

	return number;
}


struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
	void generate();
};

void Date::generate()
{
	do
	{
		year = 2020 + rand() % 100;
		month = rand() % 12;
		day = rand() % 31;
	} while (!Date::isCorrect());
}

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
		if ((day >= 1) && (day <= 31))
			result = true;
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day > 0) && (day <= 30))
			result = true;
		break;
	}
	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day > 0) && (day <= 28))
				result = true;
		}
		else
		{
			if ((day > 0) && (day <= 29))
				result = true;
		}
		break;
	}

	default:
		result = false;
	}
	return result;
}

struct Time 
{
	int seconds, minutes, hours;
	bool isCorrect();
	void generate();
};

void Time::generate()
{
	do
	{
		hours = rand() % 24;
		minutes = rand() % 60;
		seconds = rand() % 60;
	} while (!Time::isCorrect());
}

bool Time::isCorrect() 
{
	if (hours < 24 && hours >= 0)
	{
		if (minutes >= 0 && minutes < 60)
		{
			if (seconds >=0 && seconds < 60)
			{
				return true;
			}
		}
	}
	return false;
}

struct DateTime
{
	Date d;
	Time t;
	bool isCorrect();
	void generate();
};

void DateTime::generate()
{	
	t.generate();
	d.generate();
}

bool DateTime::isCorrect()
{
	if (d.isCorrect() && t.isCorrect())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void baseLevel()
{
	int sum = 0;
	Time t;
	struct tm* entered;
	char formatted[80];
	time_t entered_time = time(NULL);
	entered = localtime(&entered_time);

	do
	{
		cout << "Input time (HH MM SS): ";
		t.hours = getInteger("Hours: ");
		t.minutes = getInteger("Minutes: ");
		t.seconds = getInteger("Seconds: ");
	} while (!t.isCorrect());

	entered->tm_hour = t.hours;
	entered->tm_min = t.minutes;
	entered->tm_sec = t.seconds;

	strftime(formatted, sizeof(formatted), "%I %M %S %p", entered);
	cout << "Entered time: " << formatted << endl;

	cout << endl << "Part 2" << endl;
	struct tm Spaceship_start = *localtime(&entered_time);
	DateTime dt;
	dt.generate();
	Spaceship_start.tm_year = dt.d.year;
	Spaceship_start.tm_mon = dt.d.month;
	Spaceship_start.tm_mday = dt.d.month;
	Spaceship_start.tm_hour = dt.t.hours;
	Spaceship_start.tm_min = dt.t.minutes;
	Spaceship_start.tm_sec = dt.t.seconds;

	time_t now = time(NULL);
	time_t start = mktime(&Spaceship_start);
	time_t difference = (time_t)difftime(now, start);
	
	struct tm* diff = localtime(&difference);
	strftime(formatted, sizeof(formatted), "%Y:%m:%d:%H:%M:%S", diff); //%Y %m %d %H %M %S
	cout << formatted << " to start";
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
