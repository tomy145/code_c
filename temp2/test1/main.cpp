#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class A
{
public:
    A(int a)
    {
        m_a = a;
        cout << "A(int ) ..."<< m_a << endl;
    }

    void printA() {
        cout << "a = " << m_a << endl;
    }

    ~A(){
        cout << "~A().." <<m_a<< endl;
    }
private:
    int m_a;
};


//构造函数的初始化列表的顺序不是 觉得成员变量的构造顺序
//成员变量的初始化顺序 跟初始化列表无关 而是 根据成员变量的定义先后有关
class B {
public:
    B(int value1, int value2, int b):  a1(value1), a2(value2)
    {
        cout << "B(int,int,int)..." << endl;

        m_b = b;
    }

    void printB()
    {
        cout << "b = " << m_b << endl;
        a1.printA();
        a2.printA();
    }

    ~B() {
        cout << "~B().." << endl;
    }
private:
    A a2;
    A a1;
    int m_b;
};

//先构造的后析构



class ABC
{
public:
    ABC(int a, int b, int c)
    {
        m_a = a;
        m_b = b;
        m_c = c;
    }

    ABC(int a, int b)
    {
        m_c = a;
        m_b = b;
    }

    ABC(int a)
    {
        m_a = a;
//        ABC(10, 20); //此处会产生一个匿名对象，这行代码过后会立即释放这个对象


    }
    ABC(const ABC &another)
    {
        m_a = another.m_a;
        m_b = another.m_b;
        m_c = another.m_c;
    }
    ABC() {
        m_a = 0;
        m_b = 0;
        m_c = 0;
    }

    ~ABC()
    {
        cout << this << endl;
        cout << "died \n";
    }

private:
    int m_a;
    int m_b;
    int m_c;
};

class ABCD
{
public:
    ABCD(int d) {
        //abcOBJ无参构造
        m_d = d;
    }

    ABCD(int a, int b, int c, int d) :objABC(a, b, c)
    {
        m_d = d;

    }

    ABCD(ABC &abcobj, int d) :objABC(abcobj)
    {
        m_d = d;
        //objABC = abcobj;
    }

    ABCD(int a, int d) :objABC(a)
    {
        m_d = d;
    }
    
private:
    ABC objABC;
    int m_d;
};

class Test
{
public:
    Test(int a, int m) :m_m(m)
    {
        m_a = a;
        //m_m = m;//常量成员变量不能赋值
    }
private:
    int m_a;
    const int m_m;
};

void test1()
{
    B b(100, 200, 3);
    b.printB();

    ABCD abcd1(10);

    ABCD abcd2(1, 2, 4, 5);

    ABC abc(1, 2, 3);

    ABCD abcd3(abc, 40);

    ABCD abcd4(100, 200);
}

int main(void)
{

    ABC a1 = ABC(12);

    
    
    return 0;
}