#include <iostream>
#include <stdlib.h>     
#include <time.h>       
#include <string>

struct Computers {
	char name[8];
	float frequency;
	int RAM;
	bool dvdrom;
	int price;
};

using namespace std;
int BaseDifficulty()
{
	srand(time(NULL));

	const int N = 10;
	Computers Warehouse[N];

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