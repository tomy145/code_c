//
//  main.cpp
//  test1cpp
//
//  Created by Mac on 16/5/20.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>

typedef void swapAIntData(int *,int *);


int func(int a, int b = 2)
{
    return a+b;
}

void swapP(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swpapAnd(int & a, int & b)
{
    int tem = a;

    a = b;
    b = tem;


}

unsigned long  sum(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * sum(num -1);
    }

}

unsigned long sum2(unsigned long num)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return num + sum2(num - 1);
    }
}



// 例3-20  函数和数据的测试
void simple()		// 定义一个简单函数
{
    std::cout << "It is a simple program.\n" ;

}



void test1()
{
    using namespace std;

    int a = 10;
    int b = 30;

    swapAIntData swap1;
    //    swap1 = &swapP;

    cout << "未交换之前 --- a = " << a << ", b = " << b << endl;

    swpapAnd(a, b);

    cout << "交换之后 a = " << a << ", b = " << b << endl;

    cout << func(1) << endl;

    cout << "Hello, World!\n";

    unsigned long m = sum(5);

    cout << "sum = " << m  << endl;

    cout << " sum2 = " << sum2(100) << endl;

    cout << "Call function ...\n" ;
    simple() ;		// 名方式调用
    ( & simple )() ;		// 地址方式调用
    ( * & simple )() ;		// 间址调用
    cout << "Address of function :\n" ;
    cout << &simple << endl ;		// 函数名是地址
    cout << & simple << endl ;		// 取函数地址
    cout << *&simple << endl ;     	// 函数地址所指对象
    int c = 100 ;		// 声明一个整数对象
    cout << "Value of a :\n" ;        cout << c << endl;
    cout << "Address of a :\n" ;    cout << &c << endl;
}

void test3()
{
    using namespace std;

    int len = 99999;

    int *p1 = new int(len);

    cout << sizeof(p1) << endl;

    for (int i = 0; i < len; i++)
    {
        p1[i] = i;
        cout << p1[i] << endl;
    }

    delete p1;
    

}

/// 定义一个类Person
class Person
{

public:
    int age;
    std::string name;
    Person(int age,const char *name)
    {
        this->age = age;
        this->name = name;

    };

    void desc()
    {
        std::cout << this->age << std::endl;
        std::cout << this->name << std::endl;
    };

    ~Person() //默认析构函数，系统会自动调用
    {
        std::cout << "调用析构函数 --- " << std::endl;
    };

} ;

void test4()
{
    Person p1 = Person(13,"39ld");

    std::cout<< p1.name << std::endl;

    p1.desc();

}

/// 狗对象
class Dog
{


private:
    std::string name; //名字
    int age; //年龄

public:
    void setAge(int age)
    {
        this->age = age;
    }
    int getAge()
    {
        return this->age;
    }

    void setName(std::string name)
    {
        this->name = name;
    }

    std::string getName()
    {
        return this->name;
    }

//private:
    //声明友元函数,在里面定义也可以，在外面定义也可以
    friend void dogFriend(Dog d1);


};

void dogFriend(Dog d1)
{
    std::cout << "dog name is --" << d1.name << std::endl;
}

class A1
{
public:
    A1()
    {
        a1 = 100;
        a2 = 200;
    }
    int getA1()
    {
        return this->a1;
    }
    //声明一个友元函数
    friend void setA1(A1 *p, int a1); //什么这个函数是这个类的好朋友

protected:
private:
    int a1;
    int a2;
};


void test5()
{

    using namespace std;

    int a = 10;
    int &b = a;
    b = 20;


    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}




//C
class Test
{
public:
protected:
private:
    int a;
    const int A() //const // ====>int A(const this)
    {
        //观点1：const是修饰a,但是通过测试，我们发现，b++也不能编译通过
        //这说明：const把a 和 b都修饰了。。。。

        //剖析：因为this作为函数的第一个参数，被隐藏。。。。const没有地方放。。。。
        //
        //const是修饰this

        a ++;
        //b++;
        return a;
    }
    void A(int val)
    {
        a = val;
    }

    int BBB()
    {

        return a;
    }
    
    int b;
};


int Aaaaa(const Test *pthis) 
{ 
    return 10; 
}


void test6()
{
    using namespace std;

    Dog d1 =  Dog();
    d1.setAge(12);
    d1.setName("dog");
    cout << "name is --- " << d1.getName() << endl;
    dogFriend(d1);
}



namespace NameSpace1
{
    int a = 20;
}

namespace NameSpace2
{
    int a = 30;
    namespace NameSpace3
    {
        struct Student
        {
            int age;
            std::string name;
        };
    };
}


void test7()
{
    using namespace std;
    cout << "s a = " << NameSpace1::a << endl;
    cout << "s b a = " << NameSpace2::a << endl;

    NameSpace2::NameSpace3::Student stu;
    stu.name = "小米";

    cout << "stu = " << stu.name << endl;
    

}

enum color
{
    red = 0x04,
    yellow
};



void test8()
{
    using namespace std;

    int a = 10 , b = 20 , c = 30;

    const int *pa = &a;

    pa = &b;

    pa = &c;

    cout << "a = " << a << endl;
    cout << "pa = " << *pa << endl;

    color c1 = red;

    cout << "c1 = " << c1 << endl;
    
    c1 = yellow;

}

struct Student
{

    int &age;
    double &name;

};

void test9()
{
    using namespace std;
    cout << "student size = " << sizeof(Student) << endl;

}

class Car
{

public:
    static std::string type;

public:

    int useYear;
    double distance;

};

class Box
{
public:
    Box(int l, int w):length(l),width(w)
    {

    }
    int volume()
    {
        return length * width * height;
    }
    static int height;
    int length;
    int width;
};

int Box::height = 5;

void test10()
{
    //     cout<<sizeof(Box)<<endl;
    //     Box b(2,3);
    //     cout<<sizeof(b)<<endl;

    using namespace std;

    cout<<Box::height<<endl;
    Box b(1,1);
    cout<<b.height<<endl;
    cout<<b.volume()<<endl;
    cout << b.length << endl;

}

class delegate
{
public:
    virtual void print(int a) = 0; //抽象类
};

class Animal:public delegate
{
public:
    Animal()
    {
        std::cout << this << " Animal is init \n";
    }
    int age;
    void run()
    {
        std::cout << "跑起来了" << std::endl;
    }

    ~Animal()
    {
        std::cout << this << " Animal is die \n";
    }
//虚函数必须实现
    void print(int a)
    {
        std:: cout << "a = " << a << std::endl;
    }
};

class Bird : public Animal
{

public:

    Bird()
    {
        std:: cout << "birld is init \n";
    }
    std::string myColor;
    void fly()
    {
        std:: cout << this  << "鸟 飞起来了! \n";
    }

    ~Bird()
    {
        std::cout << "Bird is Die \n";
    }

};

void test11()
{

    Bird b1 = Bird();
    b1.myColor = "红色";
    b1.fly();
    b1.Animal::run();
    b1.print(30);
}

//泛型编程
template <typename T>

void swap(T &a , T &b)
{
    T t1 = a;
    a = b;
    b = t1;
};


int main(int argc, const char * argv[])
{

    using namespace std;

    string a = "学习";
    string b = "英语";
    swap(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;


    return 0;
}
