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
	//���������� ��������� ������������ =
	MyString& operator=(MyString& s); //��������� lvalue, ��������� rvalue
	//������������� ������, ���������� ������ <<
	friend ostream& operator<<(ostream& stream, const MyString& s);
	//���������� ��������� ������������ [] ��� ����������� ������� �� ��� ������� � ������
	char& operator[](int index);
};

#endif // !STRING_H_