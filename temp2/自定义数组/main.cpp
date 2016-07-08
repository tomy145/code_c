

#include <iostream>

#include "MyArray.hpp"

using namespace std;

class Test
{

  friend  bool cmpName(Test &p1 , Test &p2);

public:

    void setName(string name)
    {
        this->name = name;
    };

private:
    int age;
    string name;

};


void test1()
{

    MyArray array1(10); //开辟一个能存放10个元素数组

    for (int i = 0; i < 10; i++) {
        array1.setData(i, i + 10);
    }

    for (int i = 0; i < 10; i++) {
        cout << array1.getData(i) << endl;
    }

    cout << " ---- " << endl;
    MyArray array2 = array1;

    for (int i = 0; i < 10; i++) {
        cout << array2.getData(i) << endl;
    }

    array1.setData(14, 29);


    cout << array1.getData(12) << endl;
}

bool cmpName(Test &p1 , Test &p2)
{
    bool cmp = false;



    return cmp;
}

int main(void)
{


    Test t1 = Test();


    return 0;
}





//全局函数
//如果一个const修饰的对象，或者const修饰的对象指针， 如果通过这个对象 调用对象的成员方法。
//那么这个成员方法的this指针一定要是const类型的。
ostream& operator<<(ostream &os, const MyArray &array)
{
    os << "遍历整个数组" << endl;

    //array.getLen();//getLen(&array); const MyArray*const this = &array;
    
    for (int i = 0; i < array.getLen(); i++)
    {
        os << array[i]  << endl; //array.operator[](i)
    }

    os << "调用了 《《 重载" << endl;
    
    
    return os;
}
