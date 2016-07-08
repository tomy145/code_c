//
//  main.cpp
//  类=重载
//
//  Created by Mac on 16/6/1.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>


class Student
{

public:

    Student(int age , char *name)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
    }

    Student (const Student &another)
    {
        this->age = another.age;

        this->name = new char[strlen(another.name ) + 1];
        strcpy(this->name, another.name);
    };

    Student & operator =( const Student &another) // 重载
    {

        //先判断是否是同一个对象
        if (this != &another) //不是同一对象
        {
            //先清除自身开辟的内存
            delete [] this->name;
            this->age = 0;

            //深拷贝
            this->name = new char[strlen(another.name + 1)];
            strcpy(this->name, another.name);
            this->age = another.age;

        }

        return *this;
    }

    int operator()(int i)
    {
        int sum = 0;

        sum += i * i;

        return sum;
    }

    void print()
    {
        std::cout << "age = " << this->age <<std::endl;
        std::cout << "name = " << this->name << std::endl;
    }

    Student()
    {
        this->age = 0;
        this->name = NULL;
    }

    ~Student()
    {
        if (this->name != NULL)
        {
            delete [] this->name;
            this->name = nullptr;
            this->age = 0;

            std::cout << "delete self --- \n";
        }
    }
private:
    int age;
    char *name;

};

class A
{

public:
    int id;
    A(int id)
    {
        this->id = id;
    }

    A()
    {
        this->id = 0;
    }


};


void test()
{
    char *name1 = "李四";
    Student st1(12,name1);
    char *name2 = "张三";
    Student st2 = Student(27,name2);

    st1 = st2;

    st1.print();

    std::cout << st1(3) << std::endl;
    

}


class B
{

public:

    int id;

    B(int a)
    {
        this->id = a;
        std::cout << "b init \n";
        std::cout << "b init  --- a = " << this->id << std::endl;

    }

    B()
    {
        std::cout << "b init \n";
    }

    void func()
    {
        std::cout << "B func \n";
    }

    ~B()
    {
        std::cout << "B delete \n";
    }

private:


};

class MyPtr
{

public:
    MyPtr()
    {
        ptr = nullptr;
    };

    MyPtr(B *ptr)
    {
        this->ptr = ptr;
    }

    B * operator->()
    {
        return this->ptr;
    }

    B & operator*()
    {
        return *ptr;
    }

    ~MyPtr()
    {
        std::cout << " ~MyPtr() \n";
    }

private:
    B *ptr;

};



class MyString
{

};


int main(int argc, const char * argv[])
{


    MyPtr autPtr = MyPtr(new B(20));

    autPtr->func();


    std::cout << "autoPtr.id = " << autPtr->id << std::endl;



    return 0;
}
