#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <string.h>
#include <windows.h>
#include "Lab3.SymbolSequencesProcessing.h"
//#include <ctype.h>

using namespace std;


bool isLetter(char symbol)
{
	bool result = false;

	if ((symbol >= 65 && symbol <= 90) || (symbol >= 97 && symbol <= 122))
	{
		result = true;
	}
	return result;
}

void BaseLevel()
{
	cout << "Enter 12 symbols:";
	char entering[13];
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(entering, sizeof(entering));

	for (int i = 0; i < sizeof entering; i++)
	{
		/*ASCii table contains some strange symbols above (char)128 code. Therefore, many of entered symbols will be converted into gibberish */
		entering[i] *= 2;
	}

	//char test[12];
	//CharToOem(entering, test);
	//cout << test << "\n";

	cout << entering << "\n";
}

void MidLevel()
{
	cout << "Enter 10 symbols:";
	char entering[11];
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(entering, sizeof(entering));
	_strlwr_s(entering);
	for (int i = 1; i < sizeof entering; i++)
	{
		if (isLetter(entering[i]))
		{
			if (entering[i] == entering[i - 1])
			{
				cout << "letters " << entering[i - 1] << " and " << entering[i] << " (position " << (i) << ", " << (i + 1) << ") are similar.\n";
			}
		}
	}
}

bool isPunct(char c)
{
	return c == '.' || c == '!' || c == '?' || c == ',' || c == ';';
}

void HighLevel()
{
	wchar_t  entering[] = L"Всем...привет.меня зов.    Ут Денис.У.меня        есть... друг Миша.";
	char originalArray[500] = "";

	CharToOem(entering, originalArray);

	char properArray[1000] = "";
	int prvsCopiedSymbol = 0;
	for (size_t i = 0; i < strlen(originalArray); i++)
	{
		/*If punctuation is found*/
		if (isPunct(originalArray[i]))
		{
			if (originalArray[i + 1] != ' ' && !isPunct(originalArray[i+1]))
			{
				/*If there's no space after punctuation AND it's not another punctuation, copy this puntuation, then add space*/
				strncat_s(properArray, &originalArray[prvsCopiedSymbol], i - prvsCopiedSymbol + 1);
				strcat_s(properArray, " ");
				prvsCopiedSymbol = i + 1; //keep track of previous change
			}
		}
		else
		{
			/*Otherwise copy this symbol to temporary array and keep track of symbols*/
			strncat_s(properArray, &originalArray[prvsCopiedSymbol], i - prvsCopiedSymbol + 1);
			prvsCopiedSymbol = i + 1;
		}

	}
	/*Again parse array to find lowercase letters after punctuation*/
	for (int i = 0; i < strlen(properArray); i++)
	{
		/*if punctuation is found*/
		if (properArray[i] == '.' || properArray[i] == '!' || properArray[i] == '?' || i == 0)
		{
			/*skip all punctuation after this one*/
			while (properArray[i] == ' ' || properArray[i] == '.' || properArray[i] == '!' || properArray[i] == '?')
			{
				i++;
			}

			/*When temporary[i] isnt punctuation, check if it a lowercase letter. If so, transform it to uppercase.*/
			if (properArray[i] >= 97 && properArray[i] <= 122)
			{
				properArray[i] -= (char)32;
			}
			else if (properArray[i] >= -96 && properArray[i] <= -81)
			{
				properArray[i] -= (char)32;
			}
			else if (properArray[i] >= -32 && properArray[i] <= -17)
			{
				properArray[i] -= (char)80;
			}
			else if (properArray[i] == -15)
			{
				properArray[i]--;
			}
		}

	}

	cout << properArray << endl;

}

int main()
{
	int select = 0;
	do {
		srand(time(NULL));
		cout << "Variant 22. Lab 3.\nSelect difficulty level\n";
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
		case 1:BaseLevel(); break;
		case 2:MidLevel(); break;
		case 3:HighLevel(); break;
		default: cout << "Wrong entering.\n"; break;
		}
	} while (select != 0);
}