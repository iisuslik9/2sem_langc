#include <iostream>
#include <windows.h>
#include "MyString.h"
using std::cin;
using std::cout;
using std::endl;
int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    MyString s1;
    MyString s2("я студент группы 210");
    MyString s3(s2); 
    s1.ConsolePrint();
    s2.ConsolePrint();
    s3.ConsolePrint();
    s1 = s2;
    s1.ConsolePrint();
    cout << s1 << endl;
    cout << s1[-10] << endl;
    return 0;
}

