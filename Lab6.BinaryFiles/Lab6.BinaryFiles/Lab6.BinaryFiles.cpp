#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <io.h>
#include <sstream>

using namespace std;

FILE* f_out, * f_in;

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

char names[30][100] = { "Smith","Johnson","Williams","Brown","Jones","Miller","Davis","Garcia","Rodriguez","Wilson",
"Martinez","Anderson","Taylor","Thomas","Hernandez","Moore","Martin","Jackson","Thompson","White","Lopez","Lee",
"Gonzalez","Harris","Clark","Lewis","Robinson","Walker","Perez","Hall" };

struct ClientInfo
{
public: char thirdName[100] = "";
	const int baseCharge = 100, socialCharge = 80;
	int paidMonths = 0;
	void generate();
	string print();
};

void ClientInfo::generate()
{
	paidMonths = 1 + (rand() % 24);
	strcat(thirdName, names[rand() % 30]);
}

string ClientInfo::print()
{
	string out = "";
	out += "Name: ";
	out += thirdName;
	out += "\n";
	out += "Paid months: " + to_string(paidMonths) + "\n";
	return out;
}

void baseLevel()
{
	int numberOfClients = getInteger("Enter the number of clients");

	ClientInfo* clients = new ClientInfo[numberOfClients];

	for (int i = 0; i < numberOfClients; i++)
	{
		clients[i].generate();
	}

	f_out = fopen("c:\\lab6samples\\1.BaseLevel\\Clients.bin", "wb");
	fwrite(clients, sizeof(ClientInfo), numberOfClients, f_out);
	fclose(f_out);

	delete[] clients;

	ClientInfo* import = new ClientInfo[numberOfClients];
	f_in = fopen("c:\\lab6samples\\1.BaseLevel\\Clients.bin", "rb");
	fread(import, sizeof(ClientInfo), numberOfClients, f_in);
	fclose(f_in);

	for (int i = 0; i < numberOfClients; i++)
	{
		cout << import[i].print();
		cout << "Money spent: " + to_string(import[i].paidMonths * import[i].baseCharge) + "\n";
		cout << "Could be saved: " + to_string(import[i].paidMonths * import[i].baseCharge - import[i].paidMonths * import[i].socialCharge) + "\n\n";
	}

	delete[] import;
}

void midLevel()
{
	const int size = 6;
	int array[size];
	cout << "Before: ";
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 25;
		if (rand() % 2 == 0)
		{
			array[i] *= -1;
		}
		cout << array[i] << (i == size - 1 ? ";" : ", ");
	}
	cout << endl;
	f_out = fopen("c:\\lab6samples\\2.MidLevel\\Numbers.bin", "wb");
	fwrite(array, sizeof(int), size, f_out);
	fclose(f_out);

	int import[size];
	f_in = fopen("c:\\lab6samples\\2.MidLevel\\Numbers.bin", "rb");
	fread(import, sizeof(int), size, f_in);
	fclose(f_in);

	int min = 2147483647, max = 0;
	int minIndex = 0, maxIndex = 0;
	for (int i = 0; i < size; i++)
	{
		if (import[i] > max)
		{
			max = import[i];
			maxIndex = i;
		}
		else if (import[i] < min) // for instances when size = 1, "else" should be erased
		{
			min = import[i];
			minIndex = i;
		}
	}
	import[maxIndex] = min;
	import[minIndex] = max;

	cout << "After:  ";
	for (int i = 0; i < size; i++)
	{
		cout << import[i] << (i == size - 1 ? ";" : ", ");
	}
	cout << endl;

	f_out = fopen("c:\\lab6samples\\2.MidLevel\\NumbersAfter.bin", "wb");
	fwrite(import, sizeof(int), size, f_out);
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
		case 3:highLevel(); break;
		default: cout << "Wrong entering.\n"; break;
		}
	} while (select != 0);
}

