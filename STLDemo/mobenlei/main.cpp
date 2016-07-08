#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

template <class T>
class A
{
public:
    A(T a)
    {
        this->a = a;
    }

    void print()
    {
        cout << "a = " << a << endl;
    }
private:
    T a;
};

//类B 继承类A  如果继承的类A 是已经实例化， 类b 依然是一个普通类，
class B :public A<int>
{
public:
    B(int a, int b) :A<int>(a) {
        this->b = b;
    }

    void printB() {

    }
private:
    int b;
};


//类C 继承类A   如果继承的类A 没有被实例化，依然有泛化类型， 类C 是一个模板类
template <typename T>
class C :public A<T>
{
public:
    C(T a, T b) :A<T>(a) {
        this->b = b;
    }

    void printC()
    {
        cout << "template ---" << endl;
    }

private:
    T b;
};


template <class T>
class T1
{


public:

    T1()
    {
        this->num = 0;
    }

    T1(T t1)
    {
        this->num = t1;
    }

    void printT()
    {
        std::cout << "t = " << this->num << std::endl;
        std::cout << "type is -- " << typeid(this->num).name() << std::endl;
    }

private:

    T num;


};




void test1()
{
    A<int> a(10);

    a.print();

    cout << " ------ " << endl;
    B b(10, 20); //类b就是一个普通类，

    cout << " ------ " << endl;
    C<int> c(100, 200);
}


int main(void)
{

    T1<int> temp(14);
    temp.printT();

    std::cout << typeid(temp).name() << std::endl;
    
    
    return 0;
}