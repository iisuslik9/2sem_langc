
#include "MyString.h"
#include <iostream>
using std::ostream;
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::strlen;

MyString::MyString() :len(0)
{
	str = new char[1];
	str[0] = '\0';
}

MyString::MyString(const char* s) {
	len = strlen(s);
	str = new char[len + 1];
	for (size_t i = 0; i <= len; i++)
	{
		str[i] = s[i];
	}
}
//����������� �����������
MyString::MyString(const MyString& s) {
	len = s.len;
	str = new char[len + 1];
	for (size_t i = 0; i <= len; i++)
	{
		str[i] = s.str[i];
	}
}
MyString::~MyString() {
	delete[] str;
	len = 0;
	str = new char[1];
	str[0] = '\0';
	cout << "������ �������"<<endl;
}
void MyString::ConsolePrint() {
	cout << str << endl;
}
MyString& MyString::operator=(MyString& s) {
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	for (size_t i = 0; i <= len; i++)
	{
		str[i] = s.str[i];
	}
	return *this; //������������  ��������� this
}

//������������� �������� ����������� ������, ��������� ��� ��� ������������ ����,�� ����� ������ �� ���� ����� ������ 
// //, ���������� ������ <<
ostream& operator<<(ostream& stream, const MyString& s) {
	stream << s.str << "����� ������ = " << s.len;
	return stream;
}

//���������� ��������� ������������ [] ��� ����������� ������� �� ��� ������� � ������
char& MyString::operator[](int index) {
	if (index < len && index >= 0) {
		return str[index];
	}
	else {
		char zero = '0';
		return zero;
	}
}
//blackbox