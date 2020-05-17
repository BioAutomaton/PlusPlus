#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <io.h>
#include "Lab5.TextFiles.h"
#include <sstream>

using namespace std;

#pragma warning(disable:4996)

struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
	void getDate();
	string printDate();
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

void Date::getDate()
{

	/*Birthday*/
	/*Edit numbers according to needs*/

	do
	{
		day = rand() % 31 + 1;
		month = rand() % 12 + 1;
		year = rand() % 52 + 1950;
	} while (!isCorrect());
}
string Date::printDate()
{
	string date = "";
	date += to_string(day);
	date += ".";
	date += to_string(month);
	date += ".";
	date += to_string(year);
	return date;
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
	string printInfo();
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


	/*Height and weight*/

	height = (float)(rand() % 40 + 160) / 100;
	weight = (float)(rand() % 400 + 600) / 10;

	/*Birthday*/

	birthday.getDate();

	/*Address*/

	address.getAddress();

	/*Name*/

	name.randomizer(gender);


}

string ManequinnMaker::printInfo()
{
	string info = "";

	info += "Name: " + name.firstName + " " + name.middleName + " " + name.lastName + "\n";
	info += "Birthday: " + birthday.printDate() + "\n";
	info += nationality + " " + gender + "\n";
	info += "Height: " + to_string(height) + " Meters" + "\n";
	info += "Weight: " + to_string(weight) + " Kilos" + "\n";
	info += "Address: " + address.country + ", " + address.city + " City, " + address.district + " district, " + address.street + " str, " + to_string(address.house) + ", apts No " + to_string(address.apartment);
	info += "\nZIP-code: " + address.ZIPcode;
	info += "\n\n---\n\n";

	return info;
}

void baseLevel()
{
	int numberOfMM;
	numberOfMM = getInteger("Enter number of Mannequinn makers to generate info about: ");
	ofstream fout;
	ifstream fin;

	string path = "C:\\lab5samples\\BaseLevel\\";
	ManequinnMaker* database = new ManequinnMaker[numberOfMM];
	fout.open(path + "DBimport.txt");
	for (int i = 0; i < numberOfMM; i++)
	{
		fout << "Mannequinn Maker #" << i + 1 << ":\n\n";
		database[i].getInfo();
		fout << database[i].printInfo();
	}
	fout.close();


	fin.open(path + "DBimport.txt");

	if (fin.is_open())
	{
		string data;
		while (getline(fin, data))
		{
			cout << data << endl;
		}
	}


	fin.close();
	fout.open(path + "TheMostYoungMM.txt");
	ManequinnMaker max;
	for (int i = 0; i < numberOfMM; i++)
	{

		if (database[i].gender == "Female")
		{
			if (database[i].birthday.year > max.birthday.year)
			{
				max = database[i];
			}
			else if (database[i].birthday.year == max.birthday.year)
			{
				if (database[i].birthday.month > max.birthday.month)
				{
					max = database[i];
				}
				else if (database[i].birthday.month == max.birthday.month)
				{
					if (database[i].birthday.day > max.birthday.day)
					{
						max = database[i];
					}
				}
			}
		}
	}
	fout << max.printInfo();
	cout << "Younger one: \n\n" << max.printInfo();

	delete[] database;
}

void midLevel() //Task: to merge 2 text files
{
	const int NumberOfFilesToMerge = 2;
	string filepaths[NumberOfFilesToMerge + 1];

	for (int i = 0; i < NumberOfFilesToMerge; i++)
	{
		filepaths[i] = "C:\\lab5samples\\MidLevel\\input" + to_string(i + 1) + ".txt";
	}
	filepaths[NumberOfFilesToMerge] = "C:\\lab5samples\\MidLevel\\Result.txt";

	/*Entering simulation (create files and fill them up).*/

	ofstream fout;
	string samples[12] =
	{
		"Stand up straight with your shoulders back. ",
		"Treat yourself like someone you are responsible for helping. ",
		"Befriend people who want the best for you. ",
		"Compare yourself to who you were yesterday, not the person someone are today. ",
		"Do not let your children do anything that makes you dislike them. ",
		"Set your house in perfect order before you criticise the world. ",
		"Pursue what is meaningful, not what is expedient. ",
		"Tell the truth. Or at least do not lie. ",
		"Assume the person you are listening to knows something you do not. ",
		"Be precise in your speech. ",
		"Do not bother children while they are skateboarding. ",
		"Pet a cat when you encounter one in the street. "
	};

	for (int i = 0; i < NumberOfFilesToMerge; i++)
	{
		fout.open(filepaths[i]);
		fout << samples[rand() % 12];
		fout.close();
	}

	/*Scanning*/
	string scanresult;
	ifstream fin;
	for (int i = 0; i < NumberOfFilesToMerge; i++)
	{
		char scan[200];
		fin.open(filepaths[i]);
		fin.getline(scan, 200);
		fin.close();
		scanresult += scan;
		cout << filepaths[i] << ": " << scan << endl;
	}

	/*Output*/
	fout.open(filepaths[NumberOfFilesToMerge]);
	fout << scanresult;
	cout << filepaths[NumberOfFilesToMerge] << scanresult;
	fout.close();

}

class Matrix
{
public:

	static const int dimensions = 3;
	double values[dimensions][dimensions] = { NULL };
	double determinant = 0;

	Matrix()
	{
		for (int rows = 0; rows < dimensions; rows++)
		{
			for (int cols = 0; cols < dimensions; cols++)
			{
				values[rows][cols] = (double) 1 + rand() % 25;
			}
		}
		determinant = GetDeterminant();
	}

	Matrix(int a)
	{
		for (int rows = 0; rows < dimensions; rows++)
		{
			for (int cols = 0; cols < dimensions; cols++)
			{
				values[rows][cols] = rows == cols ? (a == 0 ? 0 : a) : 0;
			}
		}
		determinant = GetDeterminant();
	}

	double GetDeterminant()
	{
		double det = 0;

		det += values[0][0] * values[1][1] * values[2][2];
		det += values[0][1] * values[1][2] * values[2][0];
		det += values[1][0] * values[2][1] * values[0][2];

		det -= values[2][0] * values[1][1] * values[0][2];
		det -= values[2][1] * values[1][2] * values[0][0];
		det -= values[1][0] * values[0][1] * values[2][2];

		return det;
	}

	Matrix GetReversed()
	{
		Matrix temp;

		for (int rows = 0; rows < dimensions; rows++)
		{
			for (int cols = 0; cols < dimensions; cols++)
			{
				temp.values[rows][cols] = values[rows][cols];
			}
		}

		temp = temp.Transpose().Minors() / determinant;
		
		return temp;
	}


	string printMatrix()
	{
		string output = "";	

		for (int rows = 0; rows < dimensions; rows++)
		{
			for (int cols = 0; cols < dimensions; cols++)
			{
				output += to_string(values[rows][cols]) + ",";
			}
			output += "\n";
		}

		return output;
	}

	Matrix Transpose()
	{
		Matrix temp;

		for (int rows = 0; rows < dimensions; rows++)
		{
			for (int cols = 0; cols < dimensions; cols++)
			{
				temp.values[rows][cols] = values[rows][cols];
			}
		}
		
		for (int rows = 0; rows < dimensions - 1; rows++)
		{
			for (int cols = rows + 1; cols < dimensions; cols++)
			{
				swap(temp.values[cols][rows], temp.values[rows][cols]);
			}
		}

		temp.determinant = GetDeterminant();
		return temp;
	}

	Matrix Minors()
	{
		Matrix temp;

		temp.values[0][0] = (values[1][1] * values[2][2] - values[2][1] * values[1][2]);
		temp.values[0][1] = (values[1][0] * values[2][2] - values[2][0] * values[1][2]);
		temp.values[0][2] = (values[1][0] * values[2][1] - values[2][0] * values[1][1]);
		temp.values[1][0] = (values[0][1] * values[2][2] - values[2][1] * values[0][2]);
		temp.values[1][1] = (values[0][0] * values[2][2] - values[2][0] * values[0][2]);
		temp.values[1][2] = (values[0][0] * values[2][1] - values[2][0] * values[0][1]);
		temp.values[2][0] = (values[0][1] * values[1][2] - values[1][1] * values[0][2]);
		temp.values[2][1] = (values[0][0] * values[1][2] - values[1][0] * values[0][2]);
		temp.values[2][2] = (values[0][0] * values[1][1] - values[1][0] * values[0][1]);

		temp.values[0][1] *= -1;
		temp.values[1][0] *= -1;
		temp.values[1][2] *= -1;
		temp.values[2][1] *= -1;

		return temp;
	}

	bool operator ==(Matrix second)
	{
		bool result = true;

		for (int rows = 0; rows < dimensions; rows++)
		{
			for (int cols = 0; cols < dimensions; cols++)
			{
				if (abs(values[rows][cols] - second.values[rows][cols]) > 0.001 )
				{
					result = false;
					return result;
				}
			}
		}

		return result;
	}

	Matrix operator *(Matrix multiplier)
	{
		Matrix temp;

		for (int rows = 0; rows < dimensions; rows++)
		{
			for (int cols = 0; cols < dimensions; cols++)
			{
				double sum = 0;
				for (int t = 0; t < dimensions; t++) {
					sum += values[rows][t] * multiplier.values[t][cols];
				}
				temp.values[rows][cols] = sum;
			}
		}

		temp.determinant = GetDeterminant();
		return temp;
	}
	Matrix operator *(double multiplier)
	{
		Matrix temp;

		for (int rows = 0; rows < dimensions; rows++)
		{
			for (int cols = 0; cols < dimensions; cols++)
			{
				temp.values[rows][cols] = values[rows][cols] * multiplier;
			}
		}

		temp.determinant = GetDeterminant();
		return temp;
	}
	
	Matrix operator /(double multiplier)
	{
		Matrix temp;

		for (int rows = 0; rows < dimensions; rows++)
		{
			for (int cols = 0; cols < dimensions; cols++)
			{
				temp.values[rows][cols] = values[rows][cols] / multiplier;
			}
		}

		temp.determinant = GetDeterminant();
		return temp;
	}

	private:


};


void highLevel()
{

	int NumberOfMatrix;
	NumberOfMatrix = getInteger("Enter number of matrices to generate: ");
	ofstream fout1;
	ofstream fout2;
	ifstream fin;

	Matrix* array = new Matrix[NumberOfMatrix];
	for (int matrix = 0; matrix < NumberOfMatrix; matrix++)
	{
		array[matrix] = Matrix();
	}

	/*Database import simulation*/

	fout1.open("C:\\lab5samples\\HighLevel\\Matrices.csv");
	for (int matrix = 0; matrix < NumberOfMatrix; matrix++)
	{
		fout1 << "Matrix #" << matrix + 1 << ": \n";
		if (matrix > 1)
		{
			fout1 << (rand() % 4 > 0 ? array[matrix].printMatrix() : array[matrix - 1].GetReversed().printMatrix());
		}
		else
		{
			fout1 << array[matrix].printMatrix();
		}
		
	}

	fout1.close();

	delete[] array;

	Matrix* import = new Matrix[NumberOfMatrix];
	for (int matrix = 0; matrix < NumberOfMatrix; matrix++)
	{
		import[matrix] = Matrix(0);
	}

	fin.open("C:\\lab5samples\\HighLevel\\Matrices.csv");
	string data;
	for (int matrix = 0; matrix < NumberOfMatrix; matrix++)
	{
		for (int rows = 0; rows < import[matrix].dimensions; rows++)
		{
			int cols = 0;
			do
			{
				getline(fin, data);
			} while (!isdigit(data[0]) && data[0] != '-');
				string number;
				int i = 0;
				while (i < data.length()) {
					number = "";
					while(data[i] != ',')
					{
						number += data[i++];
					}
					i++;
					import[matrix].values[rows][cols++] = stod(&number[0]);
				
			}
		}
		import[matrix].determinant = import[matrix].GetDeterminant();
	}
	fin.close();
	bool* isIrreversible = new bool[NumberOfMatrix];

	fout1.open("C:\\lab5samples\\HighLevel\\OutReversible.csv");
	fout2.open("C:\\lab5samples\\HighLevel\\OutIrreversible.csv");
	for (int matrix = 0; matrix < NumberOfMatrix; matrix++)
	{
		if (import[matrix].determinant == 0)
		{
			fout2 << "Matrix #" << matrix + 1 << ":\n" << import[matrix].printMatrix() << endl;
		}
		else
		{
			isIrreversible[matrix] = true;
			Matrix reverse = import[matrix].GetReversed();
			for (int compare = 0; compare < NumberOfMatrix; compare++)
			{
				if (reverse == import[compare])
				{
					fout1 << "Matrix #" << matrix + 1 << ":\n" << import[matrix].printMatrix();
					fout1 << "X\n";
					fout1 << "Matrix #" << compare + 1 << ":\n" << import[compare].printMatrix();
					fout1 << "=\n";
					fout1 << (import[matrix] * import[compare]).printMatrix() << endl;
					fout1 << "-----\n\n";
					isIrreversible[matrix] = false;
					isIrreversible[compare] = false;
					break;
				}
				
			}

			if (isIrreversible[matrix] == true)
			{
				fout2 << "Matrix #" << matrix + 1 << ":\n" << import[matrix].printMatrix() << endl;
			}
		}

	}
	fout1.close();
	fout2.close();
	delete[] import;
	delete[] isIrreversible;
}

int main()
{

	CreateDirectory(L"c:\\lab5samples", NULL);
	CreateDirectory(L"c:\\lab5samples\\BaseLevel", NULL);
	CreateDirectory(L"c:\\lab5samples\\MidLevel", NULL);
	CreateDirectory(L"c:\\lab5samples\\HighLevel", NULL);

	int select = 0;
	do {
		srand(time(NULL));
		cout << "Variant 22. Lab 5.\nSelect difficulty level\n";
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

