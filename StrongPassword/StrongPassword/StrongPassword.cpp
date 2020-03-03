#include <iostream>
#include <string.h>
#include <string>
#include <ctype.h>

using namespace std;

bool strongPassword(char* password, bool* errors)
{

	bool result = true;
	if (strlen(password) >= 8) { errors[0] = false; }
	else { errors[0] = true; }

	for (int i = 0; i < strlen(password); i++)
	{
		if (islower(password[i]))
		{
			errors[1] = false;
		}

		if (isupper(password[i]))
		{
			errors[2] = false;
		}

		if (isdigit(password[i]))
		{
			errors[3] = false;
		}

		if (ispunct(password[i]))
		{
			errors[4] = false;
		}
	}

	if (errors[0] || errors[1] || errors[2] || errors[3] || errors[4]) { result = false; }

	return result;
}

int main()
{
	cout << "Password creation. The password must contain:\n-More than 8 characters\n-At least one lowercase letter\n-At least one uppercase letter";
	cout << "\n-At least one digit\n-At least one special symbol\n";
	char password[20];
	cout << "You password: ";
	bool errors[5] = { 1,1,1,1,1 };
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(password, 20);
	bool isStrong = strongPassword(password, errors);
	if (isStrong) { cout << "Good password.\n"; }
	else
	{
		cout << "Bad password.\n";
		cout << (errors[0] == true ? "\nThe password must contain more than 8 characters." : "\nLength is good.") << endl;
		cout << (errors[1] == true ? "\nThe password must contain at least one lowercase letter." : "\nHas a lowercase letter.") << endl;
		cout << (errors[2] == true ? "\nThe password must contain at least one uppercase letter." : "\nHas an uppercase letter.") << endl;
		cout << (errors[3] == true ? "\nThe password must contain at least one digit." : "\nHas a digit.") << endl;
		cout << (errors[4] == true ? "\nThe password must contain at least one special symbol." : "\nHas a special symbol.") << endl;
	}
}


