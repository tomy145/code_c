//
//  main.cpp
//  MyVector
//
//  Created by Mac on 16/6/7.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <ostream>
#include <string>
#include "MyVector.h"
#include <typeinfo>
#include <algorithm>
#include <vector>


class Person
{

public:

    Person()
    {

    }

    Person(std::string name)
    {
        this->name = name;
    }

    Person(const Person &another)
    {
        this->name = name;
    }


    Person & operator= (const Person &another) //= 号操作符重载
    {
        if (this != &another)
        {
            //1、先清除之前的数据
            this->name = "";

            //赋值
            this->name = another.name;


        }

        return *this;
    }


    std::string & getName()
    {
        return this->name;
    }


private:
    std::string name;
    
};

std::ostream & operator<< (std::ostream & os , Person &another )
{
    os << "name is --" << another.getName() << std::endl;
    return os;
}




void test1()
{
    MyVector<int> arr1 = MyVector<int>(10);

    for (int i = 0; i < arr1.getLength(); i++)
    {
        arr1[i] = i + 'a';
    }

    std::cout << arr1 << std::endl;
}


void test2()
{
    MyVector<Person> arr1 = MyVector<Person>(10);

    for (int i = 0; i < arr1.getLength(); i++)
    {
        std::string name = "123";
        Person p1 = Person(name);
        arr1[i] = p1;

    }

    std::cout << arr1 << std::endl;

    std::cout << typeid(int).name() << std::endl;
    

}

int main(int argc, const char * argv[])
{


    using namespace std;
    vector<int> v1;// = vector<int>(1000);

    for (int i = 0; i < 1000; i++)
    {
        v1.insert(v1.begin() + i, i + 'a');
    }

    int k = 98 + 28;
    vector<int>::iterator it1 = find(v1.begin(), v1.end(), k);

    cout << *it1 << endl;



    return 0;
}





