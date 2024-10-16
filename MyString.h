#pragma once

#include <iostream>
using std::ostream;
using std::istream;

#ifndef STRING_H_
#define STRING_H_


class MyString
{
private:
	char* str;
	size_t len;
public:
	MyString();
	MyString(const char* s);
	MyString(const MyString& s);
	~MyString();
	void ConsolePrint();
	//перегрузка оператора присваивания =
	MyString& operator=(MyString& s); //возращаем lvalue, принимаем rvalue
	//дружественная фукция, перегрузка вывода <<
	friend ostream& operator<<(ostream& stream, const MyString& s);
	//перегрузка оператора присваивания [] для определения символа по его индексу в строке
	char& operator[](int index);
};

#endif // !STRING_H_