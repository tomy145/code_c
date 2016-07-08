//
//  main.cpp
//  test6
//
//  Created by Mac on 16/5/28.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <map>
#include <string.h>
#include "Circle.hpp"



using namespace std;

class Student
{


public:
    Student()
    {
        cout << "init Student---" << typeid(this).name() << endl;
        cout << "studensssst -- \n" ;
        name = (char *)calloc(100, 1);

    };

    int age;
    char *name;

    //默认拷贝构造函数
    Student(const Student &stu)
    {
        cout << "(const Student &stu)-----" << typeid(this).name() << endl;
        Student();
//        name = (char *)calloc(100, 1);
        age = stu.age;
        strcpy(name, stu.name);
    }

    void operator= (const Student &stu)
    {
        cout << "(const operator= )-----" << typeid(this).name() << endl;

        cout << "调用了显示的拷贝构造函数Test(const Test&）。。。" << endl;
        strcpy(name, stu.name);
        age = stu.age;
    }

    ~Student() //手动调用一次，系统到最后还会调用一次，
    {
        if (name != NULL)
        {
            free(name);
            name = NULL;
        }

        cout << "调用了Student的析构函数 \n";

    };
};


class A
{

public:
    A()
    {
        name = "张三";
        cout << "init a \n" ;
    }

    string getName()
    {
        return name;
    }

    ~A()
    {

    }
private:
    string name;

};

class B
{

public:

    B(A a , string na):a1(a) , name(na)
    {

    }

    B(A a)
    {
        a1 = a;
        name = "李四" + a1.getName();
    }

    B()
    {

    }

    ~B()
    {

    }

private:
    A a1;
    string name;

};

void test1()
{
    Student st1 = Student();
    strcpy(st1.name, "张三");

    Student st2 = Student();
    strcpy(st2.name, "李四");


    Student st3 = st1;
    Student st4;
    st4 = st2;

    cout << "st1.name -" << st1.name << endl;
    cout << "stu.age - " << st1.age << endl;;


    Point p1 = Point(0, 0);
    Point p2 = Point(1, 1);

    Circle c1 = Circle(p1, 1);
    Circle c2 = Circle(p2, 1);

    cout << c1.compareDistance(c2) << endl;

}

int main(int argc, const char * argv[])
{

    A a1 = A();
//    B b1 = B(a1);
    B b2 = B(a1, "张三");




    return 0;
}
