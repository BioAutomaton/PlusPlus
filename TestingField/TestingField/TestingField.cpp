#include<iostream>
#include<string.h>
using namespace std;

struct name {
    char F[56];
    char I[32];
    char O[32];
    void setFullname() {
        cout << "F: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(F, 56);

        cout << endl << "I: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(I, 32);

        cin.ignore(std::cin.rdbuf()->in_avail());
        cout << endl << "o: ";
        cin.getline(O, 32);
    }
    void showFullname() {
        cout << "FIO: " << F << " " << I << " " << O << endl;
    }
};
struct adress {
    int index;
    char country[30];
    char region[30];
    char district[30];
    char city[20];
    char street[50];
    int house;
    int apartment;
    void setFulladress() {
        cout << endl << "Index:";
        while (!(cin >> index))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }

        cout << endl << "Country:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(country, 30);

        cout << endl << "Region:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(region, 30);

        cout << endl << "District:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(district, 30);

        cout << endl << "City:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(city, 20);

        cout << endl << "House:";
        while (!(cin >> house))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }

        cout << endl << "Apartment:";
        while (!(cin >> apartment))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }
    }
    void showFulladress() {
        cout << "Index:" << index << endl;
        cout << "Country:" << country << endl;
        cout << "Region:" << region << endl;
        cout << "District:" << district << endl;
        cout << "City:" << city << endl;
        cout << "House:" << house << endl;
        cout << "Apartment:" << apartment << endl;
    }
};
struct owner {
    name person;
    long tele;
    adress home;
    char CarBrand[20];
    int NumCar;
    int NumTeh;
    void setFullInfo() {
        person.setFullname();

        cout << endl << "Telephon number:";
        cin >> tele;

        home.setFulladress();

        cout << endl << "Car brand:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(CarBrand, 30);

        cout << endl << "Car number:";
        cin >> NumCar;

        cout << endl << "Teh. passport number:";
        cin >> NumTeh;

    }
    void outFullInfo() {
        person.showFullname();

        cout << "Telephon number:" << tele << endl;

        home.showFulladress();

        cout << "Car brand:" << CarBrand << endl;
        cout << "Car number:" << NumCar << endl;
        cout << "Teh. passport number:" << NumTeh << endl << endl;
    }
};


void InitOfArray(owner* array, int* size)
{
    for (size_t i = 0; i < *size; i++)
    {
        (array + i)->setFullInfo();
    }
}

void sortArray(owner* array, int* size)
{

    for (int i = 0; i < *size; i++)
    {
        for (int j = 0; j < *size - 1; j++) {
            if (strcmp((array + j)->person.F, (array + j + 1)->person.F) < 0)
            {
                swap((array + j)->person.F, (array + j + 1)->person.F);
            }
        }
    }
}

void showArray(owner* array, int* size)
{
    for (size_t i = 0; i < *size; i++)
    {
        (array + i)->outFullInfo();
    }
}

void showbynumber(owner* array, int number)
{
    (array + number - 1)->outFullInfo();
}

int main()
{
    int size;
    int number;
    int YesOrNot = 0;
    cout << "Enter size of array" << endl;
    while (!(cin >> size))
    {
        cout << "Wrong input" << endl;
        cin.clear();
        cin.ignore(65535, '\n');
    }
    int* ptrsize = &size;
    owner* array = new owner[size];

    InitOfArray(array, ptrsize);

    sortArray(array, ptrsize);

    showArray(array, ptrsize);

    cout << "Enter number of owner" << endl;
    cin >> number;
    cout << "Owner " << number << ":" << endl;
    showbynumber(array, number);

}