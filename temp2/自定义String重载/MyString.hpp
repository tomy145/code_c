//
//  MyString.hpp
//  temp2
//
//  Created by Mac on 16/6/1.
//  Copyright © 2016年 Mac. All rights reserved.
//

#ifndef MyString_hpp
#define MyString_hpp

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>





class MyString
{

public:

    MyString();
    MyString(int);
    MyString(const MyString& another);
    MyString(const char * str);
    ~MyString();

    int getLength();
    char * getString();

    static void deleteThis(MyString *another);

    //重载=
    MyString & operator= (const MyString &another);

    //重载[]
    char & operator[](int index);

    //重载<<,>>
    friend std::istream & operator>>(std::istream & is, MyString *c);


    //== !=
    bool operator== (const MyString &another);
    bool operator != (const MyString &another);


    
    // < >

    bool operator<(const MyString &string);
    bool operator>(const MyString &string);
    
    //+=

    MyString & operator+= (const MyString &another);

    
private:

    char *str;
    unsigned int length;

};

//<< 重载
std::ostream & operator<<(std::ostream & os, MyString &c);



#endif /* MyString_hpp */
