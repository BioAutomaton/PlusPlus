#include <iostream>
#include <string.h>
#include <string>
#include <ctype.h>

using namespace std;

bool strongPassword(char* password, bool* errors, const int SIZE);

int main()
{
	cout << "Password creation. The password must contain:\n-More than 8 characters\n-At least one lowercase letter\n-At least one uppercase letter";
	cout << "\n-At least one digit\n-At least one special symbol\n";
	char password[100];
	cout << "You password: ";

	/*By default all errors are true. By checking the entering programm will eliminate them if the password satisfies corresponding reqirement*/
	bool errors[5] = { 1,1,1,1,1 };  

	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(password, 100);

	if (strongPassword(password, errors, 5) == true) { cout << "Good password. Well done!\n"; }
	else
	{
		/*Errors output*/
		cout << "Bad password.\n";
		cout << (errors[0] == true ? "\nThe password must contain more than 8 characters." : "\nLength is good.") << endl;
		cout << (errors[1] == true ? "\nThe password must contain at least one lowercase letter." : "\nHas a lowercase letter.") << endl;
		cout << (errors[2] == true ? "\nThe password must contain at least one uppercase letter." : "\nHas an uppercase letter.") << endl;
		cout << (errors[3] == true ? "\nThe password must contain at least one digit." : "\nHas a digit.") << endl;
		cout << (errors[4] == true ? "\nThe password must contain at least one special symbol." : "\nHas a special symbol.") << endl;
	}
}

bool strongPassword(char* password, bool* errors, const int SIZE)
{
	/*The password is good by default. To make a bad password at least one error must be present.*/
	bool result = true;

	/*Length check*/
	if (strlen(password) >= 8) { errors[0] = false; }
	else { errors[0] = true; }

	for (int i = 0; i < strlen(password); i++)
	{
		/*Lowercase check*/
		if (errors[1] != false && islower(password[i]))
		{
			errors[1] = false;
		}
		/*Uppercase check*/
		if (isupper(password[i]))
		{
			errors[2] = false;
		}
		/*Digit check*/
		if (isdigit(password[i]))
		{
			errors[3] = false;
		}
		/*Special symbols check*/
		if (ispunct(password[i]))
		{
			errors[4] = false;
		}
	}

	/*If all errors are false, the password remains good. If at least one is true, the password becomes bad.*/
	bool res = false;
	for (size_t i = 0; i < SIZE; i++)
	{
		res |= errors[i]; // res = res | errors[i];
	}

	return res;
}

