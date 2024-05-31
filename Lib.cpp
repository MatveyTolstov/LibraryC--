#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
typedef bool (*CheckStringFunction)(const string&, const string&);

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    string inputLine;
    string searchLetter;
    HINSTANCE load;

    cout << "Введите вашу строку: ";
    getline(cin, inputLine);
    cout << "Введите символы для поиска в строке: ";
    getline(cin, searchLetter);

    load = LoadLibrary(L"LibraryForSearch.dll");
   

    CheckStringFunction checkString = (CheckStringFunction)GetProcAddress(load, "CheckString");

    bool result = checkString(inputLine, searchLetter);

    if (result)
    {
        cout << "Содержит ли строка " << inputLine << " " << "символы " << searchLetter << endl;
        cout << "Да " << endl;
    }
    else
    {
        cout << "Содержит ли строка " << inputLine <<" " << "символы " << searchLetter << endl;
        cout << "Неа " << endl;
    }

    FreeLibrary(load);

    return 0;
}

