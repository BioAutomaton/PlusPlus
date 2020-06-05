#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
#include <time.h>

using namespace std;


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
	} while (isError || number < 0);

	return number;
}


struct Book
{
	string title;
	int price;
	void generate();
	string print();
};

void Book::generate()
{
	title = "Book " + to_string(rand() % 100);
	price = rand() % 1000;
}

string Book::print()
{
	string temp = "";
	temp += title + " ";
	temp += "\nPrice: " + to_string(price);
	return temp;
}

void baseLevel()
{
	const int size = 10;
	stack<Book> BookStore;
	for (int i = 0; i < size; i++)
	{
		Book temp;
		temp.generate();
		BookStore.push(temp);
	}


	int sum = 0;
	while (!BookStore.empty())
	{
		cout << BookStore.top().print() << endl << endl;
		sum += BookStore.top().price;
		BookStore.pop();
	}

	cout << "Average price: " << sum / (double)size << endl << endl;
}

void midLevel()
{
	const int size = 4;
	stack<string> data;
	data.push("111");
	data.push("2");
	data.push("sdf4");
	data.push("bye");

	stack<string> temp;

	for (int i = 0; i < size; i++)
	{
		cout << data.top() << endl;
		temp.push(data.top());
		data.pop();
	}
	temp.pop();
	cout << endl << endl;
	for (int i = 0; i < size - 1; i++)
	{
		data.push(temp.top());
		temp.pop();
	}
	string max = "";
	for (int i = 0; i < size - 1; i++)
	{
		cout << data.top() << endl;
		if (data.top().length() > max.length())
		{
			max = data.top();
		}
		temp.push(data.top());
		data.pop();
	}
	cout << endl << endl;
	cout << "Max string: " << max << endl << endl;
}

bool isOperation(char c)
{
	const char operations[] = { '+', '-', '*' };
	for (int i = 0; i < sizeof operations; i++)
	{
		if (c == operations[i])
		{
			return true;
		}
	}

	return false;
}

void highLevel()
{

	string polska = "123*+";
	stack<int> pshepshe;
	for (int i = 0; i < polska.length(); i++)
	{
		if (isdigit(polska[i]))
		{
			pshepshe.push(polska[i]-'0');
		}
		else if (isOperation(polska[i]))
		{
			int first = pshepshe.top();
			pshepshe.pop();
			int second = pshepshe.top();
			pshepshe.pop();
			switch (polska[i])
			{
			case '+':
				pshepshe.push(first + second);
				break;
			case '-':
				pshepshe.push(first - second);
				break;
			case '*':
				pshepshe.push(first * second);
				break;
			default:
				break;
			}
		}
	}

	cout << "Result: " << pshepshe.top() << endl;
}

int main()
{
	int select = 0;
	do {
		srand(time(NULL));
		cout << "Variant 22. Lab 7.\nSelect difficulty level\n";
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
