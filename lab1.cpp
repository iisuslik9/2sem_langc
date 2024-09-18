//4.09.24
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <Windows.h>
using namespace std;
struct student {
    string first_name;
    string last_name;
    short marks[3];
};
void PrintStudent(student st) {
    cout << st.first_name + " " + st.last_name + " marks: \n";
    for (int i = 0; i < 3; i++)
    {
        cout << st.marks[i] << " ";
    }
    cout << endl;
}
bool ReadFile(const string filename, student*& array, int& n);
//struct point {
//    int x = 13, y = 26; //default value
//}C, D = {8,1}; //сразу создаем объекты структуры
//
//struct { //безымяная структура
//    int x = 1, y = 6; 
//}G; //объекты можем создать только здесь
//
//
//void PrintPoint(string name, point T) {
//    cout << "точка " + name + " имееет координаты:" << "\n";
//    cout << "координата x = " << T.x << "\n";
//    cout << "координата y = " << T.y << "\n";
//}
int main()
{
    setlocale(LC_ALL, "rus");
   /* point A, B = { 5,7 }, F, M;
    A.x = 15;
    A.y = 30;
    PrintPoint("A", A);
    PrintPoint("B", B);
    C = { 1,3 };
    PrintPoint("C", C);
    PrintPoint("D", D);
    PrintPoint("F", F);
    
    cout << G.x << " " << G.y << "\n";
    M = A;*/

    student anton, artem = { "Artem", "Zdanov", {4,5,2} };
    anton.first_name = "Anton";
    anton.last_name = "Brodyak";
    anton.marks[0] = 3;
    anton.marks[1] = 4;
    anton.marks[2] = 5;

    PrintStudent(artem);
    PrintStudent(anton);

    //массив структур
    student* st_array;
    string name = "in.txt";
    int n;
    if (!ReadFile(name, st_array, n)){
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        PrintStudent(st_array[i]);
    }
    return 0;
}

bool ReadFile(const string filename, student*& array, int& n) {
    ifstream fin;
    fin.open(filename);
    if (!fin.is_open()) {
        cout << "не удалось открыть файл" + filename + "\n";
        return false;
    }
    stringstream obj;
    string str;
    int count = 0;
    while (getline(fin, str)) {
        obj << str << "\n";
        count++;
    }
    fin.close();
    n = count;
    array = new student[n];
    for (int i = 0; i < n; i++)
    {
        getline(obj, str);
        int index = str.find(' ');
        array[i].last_name = str.substr(0,index);
        str = str.substr(index + 1);

        index = str.find(' ');
        array[i].first_name = str.substr(0, index);
        str = str.substr(index + 1);

        for (int j = 0; j < 3; j++)
        {
            str.find(' ');
            array[i].marks[j] =stoi( str.substr(0, index));
            str = str.substr(index + 1);
        }
    }

    free(array);
    return true;
}

//вывести худшего и лучшего студента
темы указатель на ссылку и строковый поток
массив структур
