#include <iostream>
#include <stdlib.h>     
#include <time.h>       
#include <string>

using namespace std;

struct Computer {
	char name[8];
	float frequency;
	int RAM;
	bool dvdrom;
	int price;
};


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



void BaseLevel()
{
	const int N = 10;
	Computer Warehouse[N];

	for (int item = 0; item < N; item++)
	{
		/*Enter 2 random letter in name, then '-', then random 4 digits.*/

		for (int i = 0; i < 8; i++)
		{
			Warehouse[item].name[i] = (i > 2 ? 48 + rand() % 10 : (char)65 + rand() % 25);
			if (i == 2) { Warehouse[item].name[i] = (char)45; }
			/*last char in array must be nullvalue, otherwise trash will be shown in output*/
			if (i == 7) { Warehouse[item].name[i] = NULL; }
		}

		/*Randomly enter CPU freq in range [2,0 4,5] GHz*/

		Warehouse[item].frequency = (float)(rand() % 25 + 20) / 10;

		/*Randomly choose RAM from the pool*/

		switch (rand() % 7 + 1)
		{
		case 1:Warehouse[item].RAM = 2; break;
		case 2:Warehouse[item].RAM = 4; break;
		case 3:Warehouse[item].RAM = 8; break;
		case 4:Warehouse[item].RAM = 12; break;
		case 5:Warehouse[item].RAM = 16; break;
		case 6:Warehouse[item].RAM = 32; break;
		case 7:Warehouse[item].RAM = 64; break;
		default: Warehouse[item].RAM = 1;
		}

		/*Decide if the computer has DVD-ROM*/

		Warehouse[item].dvdrom = rand() % 2;

		/*Calculate price of the computer based on previous values.*/
		Warehouse[item].price = (int)Warehouse[item].dvdrom * 250 + Warehouse[item].frequency * 5000 + Warehouse[item].RAM * 125;


		cout << "Name: " << Warehouse[item].name << endl;
		cout << "CPU Frequency: " << Warehouse[item].frequency << " GHz" << endl;
		cout << "RAM: " << Warehouse[item].RAM << " GB" << endl;
		cout << "Has a DVD-ROM: " << (Warehouse[item].dvdrom == true ? "Yes\n" : "No\n");
		cout << "Price: " << Warehouse[item].price << " UAH" << endl;
		cout << "\n\n";
	}

	cout << "All computers with RAM > 10 in Warehouse: \n\n";

	for (int item = 0; item < 7; item++)
	{
		if (Warehouse[item].RAM > 10) {
			cout << "Name: " << Warehouse[item].name << endl;
			cout << "CPU Frequency: " << Warehouse[item].frequency << " GHz" << endl;
			cout << "RAM: " << Warehouse[item].RAM << " GB" << endl;
			cout << "Has a DVD-ROM: " << (Warehouse[item].dvdrom == true ? "Yes\n" : "No\n");
			cout << "Price: " << Warehouse[item].price << " UAH" << endl;
			cout << "\n\n";
		}
	}
}

void MidLevel()
{
	struct Auto
	{
		string mark;
		string dealer;
		string type;
		Date manufacture;
		Date registration;
	};


	const int N = 1000;
	Auto Parking[N];

	for (int car = 0; car < N; car++)
	{
		/*Car type*/

		switch (rand() % 5)
		{
		case 0:Parking[car].type = "Sedan";		break;
		case 1:Parking[car].type = "Pickup";	break;
		case 2:Parking[car].type = "Hatchback";	break;
		case 3:Parking[car].type = "Universal";	break;
		case 4:Parking[car].type = "Coupe";		break;
		default: Parking[car].type = "N/A";		break;
		}

		/*Car mark + dealer. I gather that these parameters should be paired, cause they usually are.*/

		switch (rand() % 10)
		{
		case 0: Parking[car].mark = "Audi"; Parking[car].dealer = "Germany";		break;
		case 1: Parking[car].mark = "Tesla"; Parking[car].dealer = "USA";			break;
		case 2: Parking[car].mark = "Nissan"; Parking[car].dealer = "Japan";		break;
		case 3: Parking[car].mark = "BMW"; Parking[car].dealer = "Germany";			break;
		case 4: Parking[car].mark = "Chevrolet"; Parking[car].dealer = "France";	break;
		case 5: Parking[car].mark = "Mercedes"; Parking[car].dealer = "Germany";	break;
		case 6: Parking[car].mark = "Jaguar"; Parking[car].dealer = "UK";			break;
		case 7: Parking[car].mark = "Porsche"; Parking[car].dealer = "Germany";		break;
		case 8: Parking[car].mark = "Hyundai"; Parking[car].dealer = "South Korea";	break;
		case 9: Parking[car].mark = "Honda"; Parking[car].dealer = "Japan";			break;
		default: Parking[car].mark = "N/A"; Parking[car].dealer = "N/A";			break;
		}

		/*Date of manufacture */
		do
		{
			Parking[car].manufacture.day = rand() % 31 + 1;
			Parking[car].manufacture.month = rand() % 12 + 1;
			Parking[car].manufacture.year = rand() % 10 + 2000;
		} while (!Parking[car].manufacture.isCorrect());

		/*Date of registration based of manufacture date*/
		do
		{
			Parking[car].registration.day = Parking[car].manufacture.day + rand() % 29 - rand() % 29;
			Parking[car].registration.month = Parking[car].manufacture.month + rand() % 12 - rand() % 12;
			Parking[car].registration.year = Parking[car].manufacture.year + rand() % 30;
		} while (!Parking[car].registration.isCorrect());
	}

	cout << "Cars that have been manufactured before 2005 and registered this year: \n\n";

	for (int car = 0; car < N; car++)
	{
		if (Parking[car].registration.year == 2020 && Parking[car].manufacture.year < 2005)
		{
			cout << Parking[car].mark << "\n";
			cout << Parking[car].dealer << "\n";
			cout << Parking[car].type << "\n";
			cout << Parking[car].manufacture.day << "." << Parking[car].manufacture.month << "." << Parking[car].manufacture.year << " MAN" << endl;
			cout << Parking[car].registration.day << "." << Parking[car].registration.month << "." << Parking[car].registration.year << " REG" << endl;
			cout << "\n\n";
		}

	}

}

void HighLevel()
{

}

int main()
{
	int select = 0;
	do {
		srand(time(NULL));
		cout << "Variant 22. Lab 1.\nSelect difficulty level\n";
		cout << "1 - Base level\n2 - Mid level \n3 - High level\n";
		cout << "Or enter 0 to exit.\n";
		cin >> select;
		switch (select)
		{
		case 0: break;
		case 1:BaseLevel(); break;
		case 2:MidLevel(); break;
		case 3:HighLevel(); break;
		default: cout << "Wrong entering."; break;
		}
	} while (select != 0);
}