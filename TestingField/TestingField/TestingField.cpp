#include <iostream>
#include <windows.h>
#include <string>
#include <string.h>


#pragma warning(disable:4996)

FILE* f_out, * f_in;

using namespace std;

void Task2()
{
	int matrix[5][5];
	setlocale(LC_ALL, "Rus");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matrix[i][j] = rand() % 100;
		}
	}
	f_out = fopen("c:\\matrix.bin", "wb");
	fwrite(matrix, sizeof(int), 25, f_out);
	fclose(f_out);
	int restored [5][5];
	f_in = fopen("c:\\matrix.bin", "rb");
	fread(restored, sizeof(int), 25, f_in);
	fclose(f_in);
	cout << endl << "Матрица которую вы ввели: " << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << restored[i][j] << "\t";
		}
		cout << endl << endl;
	}
	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matrix[i][j] *= 2;
		}
	}
	fout = fopen("matrix.bin", "wb");
	fwrite(matrix, sizeof(int), matrix[5][5], fout);
	fclose(fout);
	cout << endl << endl << "Матрица, елементы которой увеличены в 2 раза:" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl << endl;
	}*/
}

int main()
{
	Task2();
}