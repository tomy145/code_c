//
//  MyString.cpp
//  temp2
//
//  Created by Mac on 16/6/1.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include "MyString.hpp"

/**
 *  无参构造函数
 */
MyString::MyString()
{
    this->length = 0;
    this->str = nullptr;
};


/**
 *  构造一个空字符串，长度为len
 */
MyString::MyString(int len)
{
    if (len > 0)
    {
        this->str = new char[len];
    }
}

/**
 *  字符串默认拷贝构造函数
 */
MyString::MyString(const MyString& another)
{
    if (this != &another)
    {
        //再重新拷贝
        this->str = new char[another.length + 1];
        strcpy(this->str, another.str);
        this->length = another.length;
    }
}

/**
 *  有参构造函数 , str 传入的字符串
 */
MyString::MyString(const char * str)
{
    if (str!= NULL)
    {
        this->length = (unsigned int)strlen(str);
        this->str = new char[this->length + 1];
        memcpy(this->str, str, this->length + 1);
    }
}


//回收之前分配的内存
void MyString::deleteThis(MyString  *another)
{
    if (another->str != nullptr)
    {
        delete [] another->str;
        another->length = 0;
    }
}



MyString & MyString::operator= (const MyString &another)
{

    if (this != &another || this->length != another.length) //初始化
    {
        //先回收自己的
        MyString::deleteThis(this);

        this->length = another.length;
        this->str = new char[this->length + 1];
        strcpy(this->str, another.str);

    }

    return *this;
}


char & MyString::operator[](int index)
{

    return  this->str[index];

}

int MyString::getLength()
{
    return this->length;
}

char * MyString::getString()
{
    return this->str;
}


std::ostream & operator<<(std::ostream & os, MyString &another)
{
    os << "string -- " << another.getString() << "," << "length -- " << another.getLength() << std::endl;

    return os;
}

std::istream & operator>>(std::istream & is, MyString *c)
{


    //清空之前的数据
    MyString::deleteThis(c);

    //创建临时缓冲区
    std::cout << "请输入字符串 --- 字符串不能超过4096个 \n";

    //开辟临时区
    char *temp = (char *)calloc(4096, sizeof(char));

    //从键盘捕获输入
    std::cin >> temp;

    int len = (unsigned int)strlen(temp) + c->getLength();

    //重新开辟空间给c->str
    c->str = (char *)calloc(len + 1, sizeof(char));
    strcpy(c->str, temp);

    if (temp != NULL)
    {
        free(temp);
        temp = NULL;
    }




    
    return is;
}



bool MyString::operator== (const MyString &another)
{
    bool cmp = false;

    if (strcmp(this->str, another.str) == 0)
    {
        cmp = true;
    }

    return cmp;
}


bool MyString:: operator != (const MyString &another)
{
    bool cmp = false;

    if (strcmp(this->str, another.str) != 0)
    {
        cmp = true;
    }

    return cmp;
}



bool MyString::operator <(const MyString &string)
{
    bool cmp = false;

    if (strcmp(this->str, string.str) < 0)
    {
        cmp = true;
    }

    return cmp;

}

bool MyString::operator>(const MyString &string)
{
    bool cmp = false;


    if (strcmp(this->str, string.str) > 0)
    {
        cmp = true;
    }


    return cmp;
}




MyString &  MyString::operator+= (const MyString &another)
{

    if (this != &another)
    {
        //先回收自己的内存
        char *temp = this->str;

        int len = this->length + another.length;

        char *buf = (char *)calloc(len + 1, sizeof(char));
        strcpy(buf, temp);
        strcat(buf, another.str);

        //回收自己的内存
        MyString::deleteThis(this);

        this->str = buf;
        this->length = len;

    }

    return *this;

}




/**
 *  析构函数
 */
MyString::~MyString()
{

    std::cout << "调用了析构--- " << this << std::endl;

    if (this->str != nullptr)
    {
        delete [] this->str;
        this->str = NULL;
        this->length = 0;
    }
}
