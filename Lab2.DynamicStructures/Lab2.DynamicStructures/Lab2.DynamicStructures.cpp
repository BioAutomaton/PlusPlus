#include <iostream>
#include <iomanip>
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
	if (year > 2002) { result = false; }

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

struct Medical
{
	int hospital = 0;
	int chamber = 0;
	int bloodtype = 0;
	int medCardNumber = 0;
	string diagnosis = "COVID-19";

	void getMedical();

};

void Medical::getMedical()
{
	hospital = rand() % 20 + 1;
	chamber = rand() % 30;
	bloodtype = rand() % 4 + 1;
	if (rand() % 10 < 5) bloodtype *= -1;
	medCardNumber = rand() % 99999999;

	switch (rand() % 15)
	{
	case 0: diagnosis = "Flu"; break;
	case 1: diagnosis = "Cancer"; break;
	case 2: diagnosis = "AIDS"; break;
	case 3: diagnosis = "Arthritis";  break;
	case 4: diagnosis = "Hepatitis";  break;
	case 5: diagnosis = "Tuberculosis";  break;
	case 6: diagnosis = "Mental illness"; break;
	case 7: diagnosis = "Malaria";  break;
	case 8: diagnosis = "Stroke";  break;
	case 9: diagnosis = "Diabetes";  break;
	default:diagnosis = "COVID-19";  break;
	}
}

struct Patient
{
	Name name = { "John", "J.", "Doe" };
	Date birthday = { 1,1,2000 };
	Address address;
	Medical medInfo;

	string gender;
	string nationality;
	float height = 0, weight = 0;
	string phone = "+380";

	void getInfo();
	void printPatientData();
};

void Patient::getInfo()
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

	/*Phone number*/

	for (int i = 4; i < 13; i++)
	{
		phone += rand() % 10 + 48;
	}

}

void Patient::printPatientData()
{
	cout << "Name: " << name.firstName << " " << name.middleName << " " << name.lastName << endl;
	cout << setfill('0') << setw(2) << birthday.day << "." << setw(2) << birthday.month << "." << birthday.year << " ";
	cout << nationality << " " << gender << endl;
	cout << "Height: " << height << " Meters" << endl;
	cout << "Weight: " << weight << " Kilos" << endl;
	cout << "Phone number:" << phone << endl;
	cout << "Address: " << address.country << ", " << address.city << " City, " << address.district << " district, " << address.street << " str, " << address.house << ", apts No " << address.apartment;
	cout << "\nZIP-code: " << address.ZIPcode;
	cout << "\nMedical information: Hospital No " << medInfo.hospital << ", chamber No " << medInfo.chamber << ". Medical card number: " << medInfo.medCardNumber;
	cout << "\nBlood type: " << abs(medInfo.bloodtype) << (medInfo.bloodtype >= 0 ? " Positive" : " Negative");
	cout << "\nDiagnosis: " << medInfo.diagnosis;
	cout << "\n----------------------------------\n\n";
}

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

void getNewPatients(Patient*& array, int oldSize, int newSize)
{
	Patient* new_array = new Patient[newSize];
	for (int i = 0; i < oldSize; i++)
	{
		new_array[i] = array[i];
	}
	cout << "New patients: \n\n";
	for (int i = oldSize; i < newSize; ++i)
	{
		new_array[i].getInfo();
		new_array[i].address.getAddress();
		new_array[i].name.randomizer(new_array[i].gender);
		new_array[i].medInfo.getMedical();
		new_array[i].printPatientData();
	}
	delete[] array;
	array = new_array;
}

void searchBy(Patient*& database, int databaseSize, int parameter)
{
	bool isFound = false;
	if (parameter == 1)
	{
		cout << "Enter the name you're looking for: ";
		string nameEntering;
		cin >> nameEntering;
		cout << "Search result: " << endl;
		for (int i = 0; i < databaseSize; i++)
		{
			string fullname = database[i].name.firstName + " " + database[i].name.middleName + " " + database[i].name.lastName;
			if (_stricmp(&database[i].name.firstName[0], &nameEntering[0]) == 0 || _stricmp(&database[i].name.lastName[0], &nameEntering[0]) == 0 || _stricmp(&fullname[0], &nameEntering[0]) == 0)
			{
				isFound = true;
				database[i].printPatientData();
			}
		}
	}
	else if (parameter == 2)
	{
		Date dateEntering;
		do
		{
			dateEntering.day = getInteger("Enter day:");
			dateEntering.month = getInteger("Enter month:");
			dateEntering.year = getInteger("Enter year:");
			if (!dateEntering.isCorrect())
			{
				cout << "Wrong entering.\n";
			}
		} while (!dateEntering.isCorrect());

		cout << "Search result: " << endl;
		for (int i = 0; i < databaseSize; i++)
		{
			if (dateEntering.day == database[i].birthday.day && dateEntering.month == database[i].birthday.month && dateEntering.year == database[i].birthday.year)
			{
				isFound = true;
				database[i].printPatientData();
			}
		}
	}
	else if (parameter == 3)
	{
		cout << "Enter ZIP-code to perform search by:";
		string ZIPentering;
		cin >> ZIPentering;
		cout << "Search result: " << endl;
		for (int i = 0; i < databaseSize; i++)
		{
			if (strcmp(&ZIPentering[0], &database[i].address.ZIPcode[0]) == 0 )
			{
				isFound = true;
				database[i].printPatientData();
			}
		}
	}
	else if (parameter == 4)
	{
		cout << "Enter diagnosis to perform search by:";
		string diagEntering;
		cin >> diagEntering;
		cout << "Search result: " << endl;
		for (int i = 0; i < databaseSize; i++)
		{
			if (_stricmp(&diagEntering[0], &database[i].medInfo.diagnosis[0]) == 0)
			{
				isFound = true;
				database[i].printPatientData();
			}
		}
	}
	else
	{
		cout << "Wrong parameter.\n";
	}

	if (!isFound) { cout << "\nNo results.\n"; }
}



int main()
{
	srand(time(NULL));
	int size = 0;
	size = getInteger("Enter the amount of patients to recieve information about: ");
	Patient* database = new Patient[size];
	getNewPatients(database, 0, size);

	bool stop = false;
	do
	{
		cout << "What would you like to do?\n1 - load more data about patients.\n2 - print all data\n3 - search by ...\n4 - sort by birthday\n5 - exit";
		int choice = 0;
		choice = getInteger("\nYour choice: ");
		switch (choice)
		{
		case 1:
		{
			int addition;
			addition = getInteger("Enter amount of new patients: ");
			getNewPatients(database, size, size + addition);
			size += addition;
			break;
		}
		case 2:
		{
			cout << "All data: \n\n";
			for (int i = 0; i < size; i++)
			{
				database[i].printPatientData();
			}
			break;
		}
		case 3:
		{
			/*There can be other search types, but it will be super boring to consider them all.
			Too many parameters, so I've chose the most important ones.*/
			cout << "You can search by:\n1 - name\n2 - birhday\n3 - ZIP-code\n4 - diagnosis\n";
			int parameter = getInteger("Your choice: ");
			searchBy(database, size, parameter);
			break;
		}
		case 4:
		{
			/*Bubble sort by birthday*/
			for (int i = 0; i < size; i++)
			{
				for (int i = 0; i < size - 1; i++)
				{
					Patient temp;
					if (database[i].birthday.year > database[i + 1].birthday.year)
					{
						temp = database[i];
						database[i] = database[i + 1];
						database[i + 1] = temp;
					}
					else if (database[i].birthday.year == database[i + 1].birthday.year)
					{
						if (database[i].birthday.month > database[i + 1].birthday.month)
						{
							temp = database[i];
							database[i] = database[i + 1];
							database[i + 1] = temp;
						}
						else if (database[i].birthday.month == database[i + 1].birthday.month)
						{
							if (database[i].birthday.day > database[i + 1].birthday.day)
							{
								temp = database[i];
								database[i] = database[i + 1];
								database[i + 1] = temp;
							}
						}
					}
				}
			}
			cout << "Array has been sorted by birthday date.";
			break;
		}
		case 5: stop = true; break;
		default:break;
		}
	} while (!stop);

	delete[] database;

}
