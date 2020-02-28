#include <iostream>
#include <stdlib.h>     
#include <time.h>       
#include <string>

struct Computers {
	//string name;
	float frequency;
	int RAM;
	bool dvdrom;
	float price;
};

using namespace std;
int main()
{
	srand(time(NULL));

	const int N = 10;
	Computers Warehouse[N];

	for (int item = 0; item < N; item++)
	{
		//Warehouse[item].name = 
		Warehouse[item].frequency = (float)(rand() % 30 + 20) / 10;
		

		switch (rand() % 6 + 1)
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

		Warehouse[item].dvdrom = rand() % 2;
		
		
		cout << "Frequency: " << Warehouse[item].frequency << endl;
		cout << "RAM: " << Warehouse[item].RAM << endl;
		cout << "Has a DVD-ROM: " << (Warehouse[item].dvdrom == true ? "Yes\n" : "No\n");
	}

}