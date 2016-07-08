//
//  main.cpp
//  自定义String重载
//
//  Created by Mac on 16/6/1.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <string>
#include "MyString.hpp"


//MyString();
//MyString(int);
//MyString(const MyString& another);
//MyString(const char * str);
//~MyString();
//
//int getLength();
//char * getString();
//
//static void deleteThis(MyString *another);
//
////重载=
//MyString operator= (const MyString &another);
//
////重载[]
//char & operator[](int index);
//
////重载<<,>>
//friend std::istream & operator>>(std::istream & is, MyString *c);
//
//
////== !=
//bool operator== (const MyString &another);
//bool operator != (const MyString &another);
//
//
//
//// < >
//
//bool operator<(const MyString &string);
//bool operator>(const MyString &string);
//
////+=
//
//MyString & operator+= (const MyString &another);




int main(int argc, const char * argv[])
{

    MyString str1("123");
//    MyString str2(str1);

    MyString str3("345");

//    str3 = str1;
//    std::cout << str1 << std::endl; 重载操作符<<成立

//    str3[1] = 'c';

    std::cin >> &str3;

    std::cout << str3 << std::endl; //重载操作符<<成立





    return 0;
}

