#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    wchar_t  S1[] = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    char lower[81];

    wchar_t  S2[] = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    char upper[81];

    int a = CharToOem(S1, lower);
    int b = CharToOem(S2, upper);
    cout << lower << endl;
    for (int i = 0; i < strlen(lower); i++)
    {
        cout << (int)lower[i] << " " << lower[i] << endl;
    }
    cout << upper << endl;
    for (int i = 0; i < strlen(upper); i++)
    {
        cout << (int)upper[i] << " " << upper[i] << endl;
    }
}