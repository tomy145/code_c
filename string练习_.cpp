#include <iostream>
#include <string>

using namespace std;

// 构造函数
void test1()
{
	string str;	// 默认构造, 空
	string str1("hello, STL!");	// 带参 -- char*
	string str2(10, 'Y');	// 10个字符Y
	string str3(str1);

	cout << str << endl;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
}

// 赋值
void test2()
{
	string str = "hello, world!";	// =操作符

	string str1;
	str1.assign("change the world by program");	// char*

	string str2;
	str2.assign(str);	// string

	string str3;
	str3.assign(10, 'X');	// n个字符

	string str4;
	str4.assign("change the world by program", 10);	// char* 中取前10个

	string str5;
	str5.assign(str1, 7, 10);	// string 第n号位置取m个元素

	cout << str << endl;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
	cout << str5 << endl;
}

// 取值
void test3()
{
	string str = "hello,world";
	for (unsigned int i = 0; i < str.size(); ++i)
	{
		cout << str[i] << " ";
		cout << str.at(i) << " ";
	}
	cout << endl;

	for (string::iterator it = str.begin(); it != str.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test4()
{
	// char* --> string
	string str("change the world by program");
	// string --> const char*
	const char* ar = str.data();
	const char* ar1 = str.c_str();

	cout << ar << endl << ar1 << endl;

	char array[128] = { 0 };
	str.copy(array, 20, 3);
	cout << "array = " << array << endl;

	string str2 = "";
	if (str2.empty())
	{
		cout << "str2 is empty string" << endl;
	}
}

// 比较
void test5()
{
	string str = "hello, world!";
	string str1 = "Hello, world!";
	string str2 = "Hello, world!";
	string str3 = "zello, world!";

	int ret = str.compare(str1);
	cout << "ret = " << ret << endl;

	ret = str.compare(str3);
	cout << "ret = " << ret << endl;

	ret = str1.compare(str2);
	cout << "ret = " << ret << endl;

	// 取字串
	string sub = str.substr(7, 5);
	cout << "sub = " << sub << endl;

	// 查找字符
	int pos = str.find('l');
	int pos1 = str.find('l', 4);
	cout << "pos = " << pos << endl;
	cout << "pos1= " << pos1 << endl;
	// 查找字符串
	int pos3 = str.find("ll8o");
	cout << "pos3= " << pos3 << endl;

	// 字符串替换
	cout << "old string = " << str << endl;
	string newstr = str.replace(3, 5, "897888865");
	cout << "newstring = " << newstr << endl;
}

// 插入删除操作
void test6()
{
	string str = "hello, world";

	str.insert(3, "9999999999999");
	
	string str1("8888888");
	str1.insert(3, 10, 'X');

	cout << "str = " << str << endl;
	cout << "str1=" << str1 << endl;

	string str3("hello, world!");
	str3.erase(3, 5);
	cout << "str3 = " << str3 << endl;
}

int main(void)
{
	// Enter your code
	// test1();
	// test2();
	// test3();
	// test4();
	// test5();
	test6();
	
	cout << "----------- The End -----------" << endl;
	system("pause");
}