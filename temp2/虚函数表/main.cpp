//
//  main.cpp
//  虚函数表
//
//  Created by Mac on 16/6/4.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <string>


using namespace std;

class People
{

public:
    People(std::string name , int age)
    {
        this->age = age;
        this->name = name;
    }

    People()
    {
        this->age = 0;
        this->name = "";
    }

    virtual ~People()
    {
        cout << "~People "  << endl;
    }

    virtual void printSelf()
    {
        cout << "typeName - " << typeid(this).name() << "  --- " << "name - " << this->name << " - age -- "  << this->age << endl;
    }

private:

    int age;
    string name;

};

class Student:public People
{
public:

    Student(string name , int age ,  int id):People(name,age)
    {
        cout << "Student(string name , int age ,  int id):People(name,age) " << endl;
    }

    Student()
    {
        cout << " Student() " << endl;
        this->idNumber = 0;

    }

    virtual void printSelf()
    {
        cout << "typeName - " << typeid(this).name() << "  --- " << "idNumber - " << this->idNumber << endl;
    }

    ~ Student()
    {
        cout << " ~Student()  " << endl;
    }


private:

    int idNumber;

};



class Base
{
public:

    Base(int i) :baseI(i){};

    virtual void print(void){ cout << "调用了虚函数Base::print()"; }

    virtual void setI(){cout<<"调用了虚函数Base::setI()";}

    virtual ~Base(){}

private:

    int baseI;
    
};

int main(int argc, const char * argv[])
{



//    People p1 = People("张三 --- ", 37);
//    int * vptrAdree = (int *)(&p1);
//    cout << "虚函数指针（vprt）的地址是：\t"<<vptrAdree << endl;
//
//    typedef void (*func)(void);
//
////    (Fun)*( (int *)*(int*)(&b));
//
//    func fun = (func)(&p1);
//
//    fun();
//
//
//    Student stu1 = Student("小明", 22, 1728272);




    Base b(1);


    int * vptrAdree = (int *)(&b);
    cout << "虚函数指针（vprt）的地址是：\t"<<vptrAdree << endl;


    typedef void(*Fun)(void);

    cout << *  (int*)(&b) << endl;

//    Fun vfunc = (Fun)
//     * (   (int *)   *  (int*)(&b)  );

//    cout << "第一个虚函数的地址是：" << (int *)*(int*)(&b) << endl;
//    cout << "通过地址，调用虚函数Base::print()：";
////    vfunc();



    std::cout << "Hello, World!\n";
    return 0;
}
