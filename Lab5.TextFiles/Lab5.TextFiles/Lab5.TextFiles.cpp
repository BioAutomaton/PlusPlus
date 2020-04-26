#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <string.h>
#include <windows.h>
#include <fstream>

using namespace std;

#pragma warning(disable:4996)

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
	if (year > 2004) { result = false; }

	return result;
}

/*Struct to store name data*/
struct Name
{
	string firstName;
	string middleName;
	string lastName;
	void randomizer(string gender);
};

/*Function to generate name*/
void Name::randomizer(string gender)
{
	/*First name gender-based generator*/

	if (_stricmp(&gender[0], "male") == 0)
	{
		switch (rand() % 10)
		{
		case 0: firstName = "Mike"; break;
		case 1: firstName = "Jeff"; break;
		case 2: firstName = "Thomas"; break;
		case 3: firstName = "Kreig"; break;
		case 4: firstName = "Oscar"; break;
		case 5: firstName = "Peter"; break;
		case 6: firstName = "Jim"; break;
		case 7: firstName = "Leonardo"; break;
		case 8: firstName = "Brian"; break;
		case 9: firstName = "Ricardo"; break;
		default:firstName = "John"; break;
		}
	}
	else if (_stricmp(&gender[0], "female") == 0)
	{
		switch (rand() % 10)
		{
		case 0: firstName = "Felicia"; break;
		case 1: firstName = "Hope"; break;
		case 2: firstName = "Emma"; break;
		case 3: firstName = "Olivia"; break;
		case 4: firstName = "Ava"; break;
		case 5: firstName = "Isabella"; break;
		case 6: firstName = "Sophia"; break;
		case 7: firstName = "Charlotte"; break;
		case 8: firstName = "Mia"; break;
		case 9: firstName = "Amelia"; break;
		default:firstName = "Evelyn"; break;
		}
	}


	/*Middle name generator. Usually, we don't know person's middle name, so we'll leave it to be a mystery*/

	middleName = (char)(rand() % 25) + 65;
	middleName += ".";

	/*Last name generator*/

	switch (rand() % 10)
	{
	case 0: lastName = "Connor"; break;
	case 1: lastName = "Johnson"; break;
	case 2: lastName = "Smith"; break;
	case 3: lastName = "Miller"; break;
	case 4: lastName = "White"; break;
	case 5: lastName = "Jobs"; break;
	case 6: lastName = "Beyfong"; break;
	case 7: lastName = "Brown"; break;
	case 8: lastName = "Williams"; break;
	case 9: lastName = "Ford"; break;
	default:lastName = "John"; break;
	}

}

/*Struct to store address data*/
struct Address
{
	string country;
	string city;
	string district;
	string street;
	unsigned int house = 1;
	unsigned int apartment = 1;
	string ZIPcode = "";
	void getAddress();
};

/*Function to emulate data import from a database*/
void Address::getAddress()
{
	/*Country*/

	switch (rand() % 10)
	{
	case 0: country = "Narnia"; ZIPcode += "0"; break;
	case 1: country = "Neverland"; ZIPcode += "1"; break;
	case 2: country = "Exandria"; ZIPcode += "2"; break;
	case 3: country = "Morrowind"; ZIPcode += "3"; break;
	case 4: country = "Middle-earth"; ZIPcode += "4"; break;
	case 5: country = "Durotar"; ZIPcode += "5"; break;
	case 6: country = "Oz"; ZIPcode += "6"; break;
	case 7: country = "Nazjatar"; ZIPcode += "7"; break;
	case 8: country = "Pandaria"; ZIPcode += "8"; break;
	case 9: country = "Teldrassil"; ZIPcode += "9"; break;
	default:country = "Azeroth"; ZIPcode += "0"; break;
	}

	/*City*/

	switch (rand() % 10)
	{
	case 0: city = "Korhal"; ZIPcode += "0"; break;
	case 1: city = "Char"; ZIPcode += "1"; break;
	case 2: city = "Zerus"; ZIPcode += "2"; break;
	case 3: city = "Kaldir"; ZIPcode += "3"; break;
	case 4: city = "Mar-Sara"; ZIPcode += "4"; break;
	case 5: city = "Adria"; ZIPcode += "5"; break;
	case 6: city = "Harbor"; ZIPcode += "6"; break;
	case 7: city = "Bel'Shir"; ZIPcode += "7"; break;
	case 8: city = "Aiur"; ZIPcode += "8"; break;
	case 9: city = "New Folsom"; ZIPcode += "9"; break;
	default:city = "Stormgrad"; ZIPcode += "0"; break;
	}

	/*District*/

	switch (rand() % 10)
	{
	case 0: district = "Central"; ZIPcode += "0"; break;
	case 1: district = "Northern"; ZIPcode += "1"; break;
	case 2: district = "Southern"; ZIPcode += "2"; break;
	case 3: district = "Eastern"; ZIPcode += "3"; break;
	case 4: district = "Western"; ZIPcode += "4"; break;
	case 5: district = "Silver"; ZIPcode += "5"; break;
	case 6: district = "Golden"; ZIPcode += "6"; break;
	case 7: district = "Platinum"; ZIPcode += "7"; break;
	case 8: district = "Glorious"; ZIPcode += "8"; break;
	case 9: district = "Natural"; ZIPcode += "9"; break;
	default:district = "Fascinating"; ZIPcode += "0"; break;
	}

	/*Street*/


	switch (rand() % 10)
	{
	case 0: street = "Gorbachova"; ZIPcode += "0"; break;
	case 1: street = "Filatova"; ZIPcode += "1"; break;
	case 2: street = "Gagarina"; ZIPcode += "2"; break;
	case 3: street = "Jukova"; ZIPcode += "3"; break;
	case 4: street = "Lenina"; ZIPcode += "4"; break;
	case 5: street = "Oktyabrskaya"; ZIPcode += "5"; break;
	case 6: street = "Korolyova"; ZIPcode += "6"; break;
	case 7: street = "Glushko"; ZIPcode += "7"; break;
	case 8: street = "Fifth Division"; ZIPcode += "8"; break;
	case 9: street = "Lunina"; ZIPcode += "9"; break;
	default:street = "Poskot"; ZIPcode += "0"; break;
	}

	/*House and apartment*/

	house = rand() % 99 + 1;
	apartment = rand() % 300;
	ZIPcode += (char)(rand() % 10) + 48;


}

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

struct ManequinnMaker
{
	Date birthday;
	Name name;
	Address address;
	string gender;
	string nationality;
	float height = 0, weight = 0;

	void getInfo();
};

void ManequinnMaker::getInfo()
{
	/*Gender*/

	int tmp = rand() % 100 + 1;
	if (tmp <= 50)
	{
		gender = "Male";
	}
	else
	{
		gender = "Female";
	}

	/*Nationality*/

	switch (rand() % 10)
	{
	case 0: nationality = "German"; break;
	case 1: nationality = "American"; break;
	case 2: nationality = "Canadian"; break;
	case 3: nationality = "Chinese"; break;
	case 4: nationality = "Russian"; break;
	case 5: nationality = "British"; break;
	case 6: nationality = "French"; break;
	case 7: nationality = "Mexican"; break;
	case 8: nationality = "Irish"; break;
	case 9: nationality = "Arabic"; break;
	default:
		break;
	}

	/*Birthday*/

	do
	{
		birthday.day = rand() % 31 + 1;
		birthday.month = rand() % 12 + 1;
		birthday.year = rand() % 52 + 1950;
	} while (!birthday.isCorrect());

	/*Height and weight*/

	height = (float)(rand() % 40 + 160) / 100;
	weight = (float)(rand() % 400 + 600) / 10;

}

void baseLevel()
{

}

void midLevel()
{
	ofstream fout;
	fout.open("FirstInput.txt");
	fout << "Tell the truth. That's the only way to make the world a better place.";
	fout.close();

	fout.open("SecondInput.txt");
	fout << "Adapt responsibility. Pick something worth doing and do it, so that your life could be meaningful.";
	fout.close();


	/*fout.open("SecondInput.txt");
	fout.open("Output.txt");*/
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