// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<Windows.h>

using namespace std;

struct student
{
    string first_name;
    string last_name;
    short marks;
};

void PrintStudent(student st)
{
    cout << "" + st.last_name +
        st.first_name + "";
    for (int i = 0; i < 3; i+++)
    {
        cout << st.marks[i] << "";
    }
    cout << endl;
}

bool ReadFile(const string file_name, student*& array, int& n);

//struct point
//{
//    int x;
//    int y;
//}C, D = {8,1},F;
//
//struct
//{
//    int x;
//    int y;
//}K, L = { 15,18 };
//
//
//
//void PrintPoint(string name, point T)
//{
//    cout << "" + name + "\n";
//    cout << "координата x=" << T.x << "\n";
//    cout << "координата y=" << T.y << "\n";
//}

int main()
{
    setlocale(LC_ALL, "rus");
    /*    point A;
        point B;

        A.x = 15;
        A.y = 30;

        PrintPoint("A", A);
        PrintPoint("B", B);
        C.x = 75;
        C.y = 10;

        PrintPoint("C",C);
        PrintPoint("D", D);
        PrintPoint("F", F);
        PrintPoint("J", J);

        cout << K.x << ""<<L.y*/
    student Anton, Artem = {Артем};



        Anton.first_name = "Артем";
        Anton.last_name = "Бродяк";
        Anton.marks[0] = 2;
        Anton.marks[1] = 3;
        Anton.marks[2] = 4;

        student* array;
        string file_name = "in.txt";
        int n;

        if (!ReadFile(file_name, array, n))
        {
            return 1;
        }
        for (int i=0;i<n;i++)




        return 0;

}

bool ReadFile(const string file_name, student*& array, int& n)
{
    ifstream fin;
    fin.open(file_name);
    if (!fin.is_open())
    {
        cout << "" + file_name + "!\n";
        return 0;
    }
    stringstream obj;
    string str;
    int count = 0;
    while (getline(fin, str))
    {
        obj << str + "\n";
        count++;
    }
    fin.close();
    n = count;
    array = new student[n];
    for (int i = 0; i < n; i+++)
    {
        getline(obj, str);
        int index = str.find(' ');
        array[i].last_name =
            str.substr(0, index);
        str = str.substr(index + 1);

        int index = str.find(' ');
        array[i].first_name =
            str.substr(0, index);
        str = str.substr(index + 1);

        int index = str.find(' ');
        array[i].marks[j] =
            stoi(str.substr(0, index));
        str = str.substr(index + 1);
    }

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
