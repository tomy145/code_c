#include <iostream>

using namespace std;

class Test
{
public:
    Test(int x, int y)
    {
        cout << "调用了有参构造test（int，int)" << endl;

        m_x = x;
        m_y = y;
    }
    Test() {
        cout << "调用了无参构造Test()" << endl;
        m_x = 0;
        m_y = 0;
    }

    //显示提供一个拷贝构造函数
    Test(const Test & another)
    {
        cout << "调用了显示的拷贝构造函数Test(const Test&）。。。" << endl;
        m_x = another.m_x;
        m_y = another.m_y;
    }

    //=赋值操作符
    void  operator=(const Test & another)
    {
        cout << "调用了 operator=(const Test&)" << endl;
        m_x = another.m_x;
        m_y = another.m_y;
    }

    void printT() {
        cout << "x = " << m_x << ", y = " << m_y << endl;
    }


    ~Test()
    {
        cout << "调用了~Test().." << endl;
    }
private:
    int m_x;
    int m_y;
};

//场景1
void test1()
{
    Test t1(10, 20);
    //Test t2(t1);
    Test t2 = t1;

    //谁先构造的，谁后析构
}

//场景2
void test2()
{
    Test t1(10, 20);
    Test t2;//t2 无参构造

    t2 = t1; //t2 =号赋值操作符
}

//场景3
void func1(Test t) // Test t = t1; //t的拷贝构造函数
{
    cout << "func1 begin..." << endl;
    t.printT();
    cout << "fun1 end..." << endl;

}

void test3()
{
    cout << "test3 begin..." << endl;

    Test t1(10, 20);//t1 有参数构造

    func1(t1);

    cout << "test3 end..." << endl;

}

//场景4
Test func2(void)
{
    cout << "func2 begin.." << endl;
    Test temp(10, 20);
    cout << "fucn2 end,," << endl;

    return temp;
}//Test 匿名 = temp

void test4()
{
    cout << "test4 begin..." << endl;
    func2(); //纯匿名的一个对象。如果说一个函数返回一个匿名对象，
    //外部没有一个变量去接收他，这个匿名对象将毫无意义
    //编译器 会立刻给他销毁，而不是等待test4执行完毕之后再销毁
    //在此刻 销毁匿名对象，  触发匿名对象的析构函数

    cout << "test4 end..." << endl;
}

//场景5
void test5()
{
    cout << "test5 begin..." << endl;
    Test t1 = func2(); //就是直接将匿名对象 转正，起个名字，就叫t1
    //就等于给匿名对象起了一个名字 叫t1
    //此时匿名对象有名字了，有意义了，编译器就不会立刻释放匿名对象

    cout << "test5 end..." << endl;
}

//场景6
void test6()
{
    cout << "test6 begin..." << endl;
    Test t1;
    
    t1 = func2(); //t1已经存在了，　匿名对象将不会被转正，　匿名对象依然无意义
    //在此刻，编译器会立刻销毁匿名对象
    
    cout << "test6 end..." << endl;
}

int main(void)
{
    
//    test1();
    test2();
    //test3();
    //test4();
    //test5();
//    test6();

    
    return 0;
}