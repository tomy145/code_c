#include "MyString.h"


MyString::MyString()
{
	this->len = 0;
	this->str = NULL;
}


MyString::MyString(int len)
{
	if (len == 0) {
		this->len = 0;
		this->str = new char[len + 1];
		strcpy(this->str, "");
	}
	else {
		this->len = len;

		this->str = new char[len + 1];//��һ��\0�ռ�
		memset(this->str, 0, len + 1);
	}
}

MyString::MyString(const char * str)
{
	cout << "MyString(const char * str)" << endl;
	if (str == NULL) {
		this->len = 0;
		this->str = new char[len + 1];
		strcpy(this->str, "");
	}
	else {
		int len = strlen(str);

		this->len = len;
		this->str = new char[len + 1]; //����str�Ŀռ䳤��
		strcpy(this->str, str); //��str������this->str
	}
}

MyString::MyString(const MyString& another)
{
	cout << "MyString(const MyString& another)" << endl;
	//���
	this->len = another.len;

	//����str
	this->str = new char[len + 1];
	strcpy(this->str, another.str);
}

MyString &  MyString::operator=(const MyString& another)
{

	cout << " MyString::operator= ..." << endl;

	//�ж��Ƿ�������
	if (this == &another) {
		return *this;
	}

	//֮ǰ�Ƿ�����������
	if (this->str != NULL) {
		delete[]this->str;
		this->str = NULL;
		this->len = 0;
	}

	//���
	this->len = another.len;
	this->str = new char[len + 1];
	strcpy(this->str, another.str);

	//��������
	return *this;
}

MyString::~MyString()
{
	if (this->str != NULL) {
		cout << "~MyString()..." << endl;
		delete[]this->str;
		this->len = 0;
		this->str = NULL;
	}
}

char& MyString::operator[](int index)
{
	return this->str[index];
}

MyString & MyString::operator+=(MyString &another)
{
	//�����һ���ַ����ǿ��ַ���
	if (another.len == 0) {
		return *this;
	}
	else if (this->len == 0) {
		*this = another;

		return *this;
	}

	//���߶����ǿ��ַ���
	//"123"   "abc"
	//"123abc"
	char *old_str = this->str;//��֮ǰ��str�Ķ��ڴ��ַ�����������Ա��ͷ�

	//������ַ����ĳ���
	int len = this->len + another.len;
	
	this->str = new char[len + 1];
	strcpy(this->str, old_str);
	strcat(this->str, another.str);

	if (old_str != NULL) {
		delete[]old_str;
	}

	return *this;
}

MyString & MyString::operator += (char *str)
{
	return *this;
}

bool MyString::operator>(MyString &another)
{
	int ret = strcmp(this->str, another.str);

	if (ret > 0) {
		return true;
	}
	else {
		return false;
	}
}

bool MyString::operator<(MyString &another)
{
	int ret = strcmp(this->str, another.str);

	if (ret < 0) {
		return true;
	}
	else {
		return false;
	}
}


ostream& operator<<(ostream &os, MyString &string)
{
	if (string.str != NULL) {
		os << string.str;
	}

	return os;
}

istream &operator>>(istream &is, MyString &string)
{
	//����֮ǰ������
	if (string.str != NULL) {
		delete[]  string.str;
		string.str = NULL;
		string.len = 0;
	}

	char buf[4096] = { 0 };
	cout << "������һ���ַ���С��4096" << endl;
	cin >> buf;

	string.len = strlen(buf);
	string.str = new char[string.len + 1];
	strcpy(string.str, buf);


	return is;
}
