#pragma once
#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

class MyString
{
public:
	MyString();
	MyString(int len); //
	MyString(const MyString& another);//str1=str2, str1(str2)
	MyString(const char * str);//str1="123",  str1("123")
	~MyString();

	//жиди=
	MyString &operator=(const MyString& another); //

	//жиди[]
	char& operator[](int index);

	

	//== !=

	// < >

	//+=
	MyString & operator+=(MyString &another);
	MyString & operator+=(char *str);

	bool operator>(MyString &another);
	bool operator<(MyString &another);

	//жиди<<,>>
	friend ostream& operator<<(ostream &os, MyString &string);
	friend istream &operator>>(istream &is, MyString &string);

private:
	int len;
	char *str;
};

