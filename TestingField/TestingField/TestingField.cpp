
#include <conio.h>;
#include <iostream>;

using std::cin;
using std::cout;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Russian");
    char Mother, Father, Sister, Brother;
    cout << "Введите ФИО матери:\t";
    cin >> Mother;
    cout << "Введите ФИО отца:\t";
    cin >> Father;
    cout << "Введите ФИО сестры:\t";
    cin >> Sister;
    cout << "Введите ФИО брата:\t";
    cin >> Brother;
    cout << "\n";
    cout << "\n";
    cout << "Введённые данные:\n";
    cout << "\n";
    cout << "ФИО матери:\t" << Mother << endl;
    cout << "ФИО отца:\t" << Father << endl;
    cout << "ФИО сестры:\t" << Sister << endl;
    cout << "ФИО брата:\t" << Brother;

    _getch();
    return 0;
}