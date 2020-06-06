#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
//#include <stack>
#include <time.h>

using namespace std;


#pragma warning(disable:4996)


// Class for stack
template <class X>
class stack
{
private:
	X* array;
	int top;
	int capacity;

public:
	stack(int size = 10);	// constructor

	void push(X);
	X pop();
	X peek();

	int size();
	bool isEmpty();
	bool isFull();

	// destructor
	~stack() {
		delete[] array;
	}
};

// Constructor to initialize stack
template <class X>
stack<X>::stack(int size)
{
	array = new X[size];
	capacity = size;
	top = -1;
}

// function to add an element x in the stack
template <class X>
void stack<X>::push(X x)
{
	if (isFull())
	{
		cout << "Stack Overflow\n";
		exit(EXIT_FAILURE);
	}

	array[++top] = x;
}

// function to pop top element from the stack
template <class X>
X stack<X>::pop()
{
	// check for stack underflow
	if (isEmpty())
	{
		cout << "Stack underflow\n";
		exit(EXIT_FAILURE);
	}

	// decrease stack size by 1 and (optionally) return the popped element
	return array[top--];
}

// function to return top element in a stack
template <class X>
X stack<X>::peek()
{
	if (!isEmpty())
		return array[top];
	else
		exit(EXIT_FAILURE);
}

// Utility function to return the size of the stack
template <class X>
int stack<X>::size()
{
	return top + 1;
}

// Utility function to check if the stack is empty or not
template <class X>
bool stack<X>::isEmpty()
{
	return top == -1;	// or return size() == 0;
}

// Utility function to check if the stack is full or not
template <class X>
bool stack<X>::isFull()
{
	return top == capacity - 1;	// or return size() == capacity;
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
	while (!BookStore.isEmpty())
	{
		cout << BookStore.peek().print() << endl << endl;
		sum += BookStore.peek().price;
		BookStore.pop();
	}

	cout << "Average price: " << sum / (double)size << endl << endl;

	// BookStore.~stack(); error calling destructor
}

void midLevel()
{
	const int size = 4;
	stack<string> data(size);
	data.push("111");
	data.push("2");
	data.push("sdf4");
	data.push("bye");

	stack<string> temp(size);

	for (int i = 0; i < size; i++)
	{
		cout << data.peek() << endl;
		temp.push(data.peek());
		data.pop();
	}
	temp.pop();
	cout << endl << endl;
	for (int i = 0; i < size - 1; i++)
	{
		data.push(temp.peek());
		temp.pop();
	}
	string max = "";
	for (int i = 0; i < size - 1; i++)
	{
		cout << data.peek() << endl;
		if (data.peek().length() > max.length())
		{
			max = data.peek();
		}
		temp.push(data.peek());
		data.pop();
	}
	cout << endl << endl;
	cout << "Max string: " << max << endl << endl;

	//data.~stack(); error calling destructor
	//temp.~stack(); error calling destructor
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
			pshepshe.push(polska[i] - '0');
		}
		else if (isOperation(polska[i]))
		{
			int first = pshepshe.peek();
			pshepshe.pop();
			int second = pshepshe.peek();
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
	cout << "\nResult: " << pshepshe.peek() << endl << endl;

	//pshepshe.~stack(); error calling destructor
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
