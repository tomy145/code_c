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

		this->str = new char[len + 1];//多一个\0空间
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
		this->str = new char[len + 1]; //开辟str的空间长度
		strcpy(this->str, str); //将str拷贝给this->str
	}
}

MyString::MyString(const MyString& another)
{
	cout << "MyString(const MyString& another)" << endl;
	//深拷贝
	this->len = another.len;

	//拷贝str
	this->str = new char[len + 1];
	strcpy(this->str, another.str);
}

MyString &  MyString::operator=(const MyString& another)
{

	cout << " MyString::operator= ..." << endl;

	//判断是否是自身
	if (this == &another) {
		return *this;
	}

	//之前是否有垃圾回收
	if (this->str != NULL) {
		delete[]this->str;
		this->str = NULL;
		this->len = 0;
	}

	//深拷贝
	this->len = another.len;
	this->str = new char[len + 1];
	strcpy(this->str, another.str);

	//返回自身
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
	//如果另一个字符串是空字符串
	if (another.len == 0) {
		return *this;
	}
	else if (this->len == 0) {
		*this = another;

		return *this;
	}

	//两边都不是空字符串
	//"123"   "abc"
	//"123abc"
	char *old_str = this->str;//将之前的str的堆内存地址保存下来，以备释放

	//求出新字符串的长度
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
	//回收之前的数据
	if (string.str != NULL) {
		delete[]  string.str;
		string.str = NULL;
		string.len = 0;
	}

	char buf[4096] = { 0 };
	cout << "请输入一个字符串小于4096" << endl;
	cin >> buf;

	string.len = strlen(buf);
	string.str = new char[string.len + 1];
	strcpy(string.str, buf);


	return is;
}
