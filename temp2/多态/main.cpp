//
//  main.cpp
//  多态
//
//  Created by Mac on 16/6/3.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>

class People
{

public:

    int age;

    People(int age)
    {
        this->age = age;
    }

    People()
    {
        this->age = 0;
    }

    virtual void grow()
    {
        std::cout << "People 长到了 " << this->age + 1 << "岁 \n";
    }


    virtual ~People()
    {
        std::cout << " People -- 析构函数 -- " << typeid(People).name() << std::endl;
    }
private:


};

class Student:public People
{

public:

    Student(int age , int idNum):People(age)
    {
        this->idNumber = idNum;
    }
    Student()
    {
        this->idNumber = 0;
    }


    virtual void grow()
    {
        std::cout << "Student 长到了 " << this->age + 1 << "岁 \n";
    }

private:

    int idNumber;



};

class Teacher:public People
{

public:

    Teacher(int age , int teachAge):People(age)
    {
        this->teachAge = teachAge;
    }


    Teacher()
    {
        this->teachAge = 0;
    }

    virtual void grow()
    {
        std::cout << "Teacher 长到了 " << this->age + 1 << "岁 \n";
    }


private:
    int teachAge;

};


//发生多态的必要条件
//1、必须要有继承
//2、必须要重写父类的方法，并且要在重写父类的方法中添加Virtual关键字
//3、必须要使用父类指针指向子类对象


//学习一门编程语言的一般步骤
//找一个IDE，一个好的IDE能节省很多的时间，提高效率
//二、学习基础语法,学习该语言的进阶（文件IO , 异常处理，多线程，UI库）
//三、学习该语言的标准库
//四、学习一些第三方库
//五、找一个项目练手，熟练运用

/**
 *  成长
 *
 *  @param p 父类指针
 */
void grow(People *p)
{
    p->grow();
}


int main(int argc, const char * argv[])
{

    People p1(13);
    Student st1(18,1920);
    Teacher t1(28,3);

    grow(&p1);
    grow(&st1);
    grow(&t1);

    return 0;
}
