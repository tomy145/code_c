//
//  main.cpp
//  标准STL总结
//
//  Created by Mac on 16/6/14.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
//查找  find()
//拷贝  copy()
//删除  erase()
//替换  replace()
//插入  insert().




void test1()
{

    string str1 = string();
    string str2 = string(2,'n');
    string str3 = string("this is a string !");
    string str4 = string(str3);

    string str5 = "zhangsan";
    string str6 = str5;

    string str7 = "1234osoep123930";

    char c1 = str7.at(2);

    cout << "c1 = " << c1 << endl;

    char c2 = str7[3];
    cout << "c2 = " << c2 << endl;


    //    c_string - string 转换

    const char *c_str = str7.c_str();
    const char *c_str2 = str7.data();

    cout << "str_cs  = " << c_str << endl;
    cout << "c_str2  = " <<c_str2 << endl;

    str7 += "你好 世界!";


    string str9 = "1234";
    string stri1 = "a123";

    cout << "cmp = " << str9.compare(stri1) << endl;

}

/**
 *  拆分字符串
 *
 *  @param src 元字符串
 *  @param del 分割的字符串
 *
 *  @return 字符数组
 */
vector<string> splitString(string &src , string del)
{

    vector<string> v1;
    string temp = src;

    string::size_type st = 0;

    while (st != EOF )
    {
        st = temp.find(del);
        v1.push_back(temp.substr(0,st));
        temp = temp.substr(st+ del.length(),temp.length() - st - del.length());
    }

    return v1;
}


void test2()
{
    //string -- 裁剪
    string str1 = "12 - 34 - 56 - 78 - 90";

    vector<string> v1 = splitString(str1, "- ");

    for (vector<string>::iterator it1 = v1.begin(); it1 != v1.end() ; it1++)
    {
        string str = *it1 ;


        cout << "str = " << *it1 << endl;
    }


    //    string::size_type st = str1.find("89");
    //
    //    cout << "st = " << st << endl;
    

}


class Person
{
public:

    Person()
    {
        this->age = 0;
    }

    Person(int age)
    {
        this->age = age;
    }

    int getAge()
    {
        return this->age;
    }

private:
    int age;

};

int main(int argc, const char * argv[])
{


    vector<Person> v1;
    for (int i = 0; i < 10; ++i)
    {
        Person p1(i + 'x');
        v1.push_back(p1);

        cout << "v1.size = " << v1.size() << endl;

    }

    for (vector<Person>::iterator it1 = v1.begin(); it1 != v1.end(); ++it1)
    {
        Person p1 = *it1;
        cout << p1.getAge() << endl;
    }



    return 0;
}
