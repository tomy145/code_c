//
//  main.cpp
//  继承
//
//  Created by Mac on 16/6/3.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <string>


class Animal
{
public:
    Animal(int age)
    {
        this->lifeValue = 100;
        this->age = age;
    }

    Animal()
    {
        this->age = 0;
        this->lifeValue = 100;//满分
    }

    void printSelf()
    {
        std::cout << " self is - " << typeid(this).name() << std::endl;
    }

private:
    int age;
    double lifeValue;

};


class Person:public Animal
{

public:

    Person(std::string name , int age):Animal(age)
    {
        this->name = name;
    }

    void makeTool()
    {
        std::cout << "this class -- " << typeid(this).name() << std::endl;
        std::cout << "make a tool \n";

    }

private:
    std::string name;

};


int main(int argc, const char * argv[])
{
    Person p1 = Person("张三", 13);

    p1.makeTool();
    p1.printSelf();


    return 0;
}
