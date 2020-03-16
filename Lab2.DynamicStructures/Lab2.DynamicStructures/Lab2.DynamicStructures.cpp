#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <string.h>

using namespace std;

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

	if (year == 2020 && month > 3) { result = false; }
	if (year > 2020) { result = false; }

	return result;
}

struct Name
{
	string firstName;
	string middleName;
	string lastName;
	void randomizer(string gender);
};

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
	else
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
		case 10: firstName = "Mike"; break;
		case 11: firstName = "Jeff"; break;
		case 12: firstName = "Thomas"; break;
		case 13: firstName = "Kreig"; break;
		case 14: firstName = "Oscar"; break;
		case 15: firstName = "Peter"; break;
		case 16: firstName = "Jim"; break;
		case 17: firstName = "Leonardo"; break;
		case 18: firstName = "Brian"; break;
		case 19: firstName = "Ricardo"; break;
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

struct Patient
{
	string gender;
	Name name;
	string nationality;


	void getGender();
	void getNationality();
};

void Patient::getGender()
{
	/*50 out of 101 - male; other 50 - female. Rare but probable occurancy 101 - other gender*/
	int tmp = rand() % 101 + 1;
	if (tmp <= 50)
	{
		gender = "Male";
	}
	else if (tmp == 101)
	{
		gender = "Other";
	}
	else
	{
		gender = "Female";
	}
}

void Patient::getNationality()
{
	switch (rand()%10)
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
}
int main()
{
	srand(time(NULL));
	int N;
	cin >> N;
	Patient * test = new Patient[N];

	for (int i = 0; i < N; i++)
	{
		test[i].getGender();
		test[i].getNationality();
		test[i].name.randomizer(test[i].gender);

		cout << test[i].gender << endl;
		cout << test[i].nationality << endl;
		cout << test[i].name.firstName << " " << test[i].name.middleName << " " << test[i].name.lastName;
		cout << endl;	
		cout << endl;	
		cout << endl;	
	}

}
