#include <iostream>
using namespace std;

int primer_func()
{
	int N;
	cout << "Enter the number: ";
	cin >> N;
	return N;
}

int main()
{
	/*Функция вызывается, работает, но возвращаемое значение нигде не сохранятеся*/
	primer_func();

	/*Функция работает и значение, которое она вернула, сохраняется в переменную а*/
	int a;
	a = primer_func();
}