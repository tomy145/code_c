//
//  main.cpp
//  test2Cpp
//
//  Created by Mac on 16/5/27.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <pthread.h>
#include <vector>

//单独使用C++标准库的这三个对象
//using std:: cin;
//using std:: cout;
//using std:: endl;

void test1()
{
    using namespace std;

    std::cout << "Hello, World!\n";

    int a = 10;

    cin >> a;

    cout << "a = " << a << endl;
}

namespace SpaceA
{
    int a = 10;
    namespace SpaceB
    {

        struct Student
        {
            int age;
            std::string name;
        };

    };
}

void test2()
{
    using namespace std;

    using SpaceA::SpaceB::Student;

    Student stu1;
    stu1.age = 29;
    stu1.name = "张三";
}

using namespace std;


void test3()
{
    bool a = true;

    cout << "a = " << a << endl;
    a = -1;
    cout << "a -1 = " << a << endl;
    a = 19;
    cout << "a > 1  = " << a << endl;
}

void test4()
{
    const int a = 10;
    printf("a add = %p \n" , &a);
    int *p = (int *)(&a);
    *p = 30;

    printf("a  = %d \n" , a);
    printf("a add = %d \n" , *p);
    

}

//C11 新特性
void fun1 [[noreturn]]() //永不返回
{
    // 可以抛出异常
    //throw "error";
}

void func2 [[carries_dependency]]() //编译器优化选项
{
    cout << "hello world \n";

//    for(int i = 0; i < 100; i++)[[omp::parallel()]]
//    {
//
//        cout << "i = " << i << endl;
//        cout << "current Thread = " << pthread_self() << endl;
//
//    }

    auto a = 20.0;

    cout << "a size = " << sizeof(a) << endl;



}


int main(int argc, const char * argv[])
{


    return 0;
}
