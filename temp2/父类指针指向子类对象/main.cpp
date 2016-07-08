#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

/*
 子类对象可以当作父类对象使用
 子类对象可以直接赋值给父类对象 、、反过来则失败
 子类对象可以直接初始化父类对象 、、反过来则失败
	*****父类指针可以直接指向子类对象 // 反过来是不可以的，因为父类内存满足不了子类指针需求
	父类引用可以直接引用子类对象
 */


class Parent
{
public:
    void printP()
    {
        cout << "a =" << a << endl;
    }

    int a;
};


class Child :public Parent
{
public:
    void printC()
    {
        cout << "child :printC: b = " << b << endl;
    }

    int b;
};


void myPrint(Parent *pp) //父类指针可以指向子类对象。Parent*pp = &c
{
    pp->printP();
}

void test1()
{
    Parent p;
    p.a = 10;

    Child c;
    c.a = 20;
    c.b = 300;

    p = c;//子类对象给父类对象赋值

    p.printP();

    Parent p2 = c; //子类对象给父类对象初始化

    p2.printP();



    c.printP(); //已经把子类对象当做父类对象使用


    cout << " ------------" << endl;

    Parent *pp = &p;
    Child *cp = &c;

    //    cp = &p; //父类的内存空间 满足不了子类指针的偏移， 需求
    cp->a;
    cp->b;
    cp->printC();
    cp->printP();




    pp = &c; //子类的内存空间 能够完全满足父类指针的偏移， 需求

    pp->a;
    pp->printP();
    
    myPrint(&p);
    myPrint(&c);

}



//int main(void)
//{
//
//
//
//
////    std::cout << clock() << std::endl;
//
//
//
//    std::chrono::time_point<std::chrono::system_clock> start, end;
//
//    start = std::chrono::system_clock::now();
//
//    std::cout << "start -- " << &start << std::endl;
//    for (int i = 0; i < 100000; i++)
//    {
//        std::cout << "i = " << i << " --- time " << __TIME__ << endl;
//    }
//    std::cout << "end -- " << __TIME__ << std::endl;
//
//
//
//    end = std::chrono::system_clock::now();
//
//
//
//
//    return 0;
//}


long fibonacci(unsigned n)
{
    if (n < 2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    std::cout << "f(42) = " << fibonacci(42) << '\n';
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
    << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

