//
//  main.cpp
//  test4
//
//  Created by Mac on 16/5/28.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>


using namespace std;

void printTList(list<int> l1)
{
    list<int>::iterator it1;
    it1 = l1.begin() ;

    for (int i = 0; i < l1.size(); i++)
    {
        cout << "list i = " << *it1 << endl;
        ++it1;
    }

    cout << endl;

}


void test2()
{
    //1、构造函数
    list<int> l1; //默认为空
    list<int> l2(3);//创建一个含有三个初始值为0 的链表
    list<int>l3(5,3 ); //创建一个含有链表，里面有5个元素， 每个元素的初始值是3;
    list<int>l4(l1);//创建一个拷贝l1的链表
    list<int>l5(l3.begin(), l3.end()); ////c5含c1一个区域的元素[_First, _Last)。

    cout << "l1.size = " << l1.size() << endl;
    cout << "l2.size = " << l2.size() << endl;
    cout << "l3.size = " << l3.size() << endl;
    cout << "l4.size = " << l4.size() << endl;
    cout << "l5.size = " << l5.size() << endl;
    cout << endl;

    //    成员函数
    //    c.begin()      返回指向链表第一个元素的迭代器。
    //    c.end()      返回指向链表最后一个元素之后的迭代器。
    //    list<int> a1{1,2,3,4,5};
    //    list<int>::iterator it;
    //
    //    for(it = a1.begin();it!=a1.end();it++)
    //    {
    //        cout << *it << "\t";
    //    }
    //
    //    cout << endl;



    //    c.rbegin()      返回逆向链表的第一个元素,即c链表的最后一个数据。
    //
    //    c.rend()      返回逆向链表的最后一个元素的下一个位置,即c链表的第一个数据再往前的位置

//    list<int> a1{1,2,3,4,5};
//    list<int>::reverse_iterator it;
//    for(it = a1.rbegin();it!=a1.rend();it++)
//    {
//        cout << *it << "\t";
//    }
//    
//    cout << endl;

//   operator= 重载赋值运算符
    list<int> a1{1,2,3,4,5} ,a2;
//    a2 = a1;
//    printTList(a2);

//    list<int>::reverse_iterator it;
//
//    for(it = a1.rbegin();it!=a1.rend();it++)
//    {
//        cout << *it << "\t";
//    }
//
//    cout << endl;



//    c.assign(n,num)      将n个num拷贝赋值给链表c。
//    c.assign(beg,end)      将[beg,end)区间的元素拷贝赋值给链表c
//    a2.assign(6, 20); //动态扩容，双向链表
//    printTList(a2);

//    c.front()      返回链表c的第一个元素。
//
//    c.back()      返回链表c的最后一个元素。

//    cout << a1.front() << endl;
//    cout << a1.back() << endl;

//    cout << "a1.empty = " << a1.empty() << endl;

//    cout << "返回链表c中实际元素的个数  = " << a1.size() << endl;
//    cout << "返回链表c可能容纳的最大元素数量 = " << a1.max_size() << endl;
//    //清除链表 a1.clear()
//    a1.clear();
//    printTList(a1);
//    cout << "a1.szie ="  << a1.size() << endl; //清除之后大小自动会为0
//    cout << "a1.cap = " << a1.max_size() << endl;

//    c.insert(pos,num)      在pos位置插入元素num。
//    list<int>::iterator ita1 = a1.begin();
//    a1.insert(ita1 , 99);
//    printTList(a1);
//    //    c.insert(pos,n,num)      在pos位置插入n个元素num。
//    cout << endl;
//    a1.insert(ita1, 3, 38);
//    printTList(a1);
//
////    c.insert(pos,beg,end)      在pos位置插入区间为[beg,end)的元素。
//    cout << "inser.(begin,end) " << endl;
//    int arr1[] = {1,2,3,5,6,9};
//    a1.insert(a1.begin(), arr1+1, arr1 +4);
//    printTList(a1);
//
////    c.erase(pos)　　　　删除pos位置的元素
//    list<int>::iterator a12 = a1.begin();
//    a1.erase(a12++); //擦除第二个
//    printTList(a1);

//    c.push_back(num)      在末尾增加一个元素。
//    cout << "a1.c.push_back() " << endl;
//    a1.push_back(332);
//    printTList(a1);
////    c.pop_back()      删除末尾的元素。
//    cout << "a.pop_back()" << endl;
//    a1.pop_back();
//    printTList(a1);
////    c.push_front(num)      在开始位置增加一个元素。
//    cout << "c.push_front()" << endl;
//    a1.push_front(28);
//    printTList(a1);
////    c.pop_front()      删除第一个元素。
//    cout << "c.pop_front()" << endl;
//    a1.pop_front();
//    printTList(a1);

//    resize(n)      从新定义链表的长度,超出原始长度部分用0代替,小于原始部分删除。
//    resize(n,num)            从新定义链表的长度,超出原始长度部分用num代替。

//    cout << "resize = " << a1.size() << endl;
//    a1.resize(19);
//    cout << a1.size() << endl;

//    c1.swap(c2);      将c1和c2交换。
//    swap(c1,c2);      同上。

    a2 = {222,1,44,5,12,4432,2};

//    cout << "swap " << endl;
//    a1.swap(a2);
//
//    printTList(a1);
//    printTList(a2);

//    c1.merge(c2)      合并2个有序的链表并使之有序,从新放到c1里,释放c2。
//
//    c1.merge(c2,comp)      合并2个有序的链表并使之按照自定义规则排序之后从新放到c1中,释放c2。

//    a1.merge(a2);
//    printTList(a1);
//
//    a2.~list();
//    cout << "a2 die ---" << endl;
//
//    printTList(a2); // 此时a2已经释放,不会出现野指针访问,list内部已经帮你考虑到了

//    c1.splice(c1.beg,c2)      将c2连接在c1的beg位置,释放c2
//    a1.splice(a1.begin(), a2); //合并之后，a2，已经释放
//
//    printTList(a1);
//
//    cout << "ss" << endl;
//    printTList(a2);

//    c1.splice(c1.beg,c2,c2.beg)      将c2的beg位置的元素连接到c1的beg位置，并且在c2中施放掉beg位置的元素
//    a1.splice(a1.begin(), a1, a2.begin());
//    printTList(a1);
//    cout << " splice --- " << endl;
//    printTList(a2);

//    c1.splice(c1.beg,c2,c2.beg,c2.end)      将c2的[beg,end)位置的元素连接到c1的beg位置并且释放c2的[beg,end)位置的元素
//    a1.splice(a1.begin(), a1, a2.begin(), a2.end());
//    printTList(a1);
//    cout << "a1 splice --" << endl;
//    printTList(a2);

//    remove(num)             删除链表中匹配num的元素。
//    a2.remove(8); //删除 链表中的节点的值为8 的这个节点
//    printTList(a2);
//    remove_if(comp)       删除条件满足的元素,参数为自定义的回调函数。

   a2.remove_if([](int n)
    {
        cout << "n = " << n << endl;
        return n < 3;
    } );
//
//    printTList(a2);

//    reverse()       反转链表
//    a1.reverse();
//    list<int>::iterator it;
//    cout << "reverse:";
//    for(it = a1.begin();it!=a1.end();it++)
//    {
//        cout << *it << " ";
//    }
//    cout << endl;

//    unique()       删除相邻的元素
//    cout << "unique" << endl;
//    a1.unique();
//    printTList(a1);


    cout << "sort 之前 。。。" << endl;
    printTList(a2);
//    a2.sort(); //默认是按照从小到大排序
    a2.sort([](int a , int b)
    {
        cout << "a = " << a << endl << "b = " << b << endl;
        return a > b;
    });

    cout << "sort 之后..." << endl;

    printTList(a2);




}

//函数默认参数值，从右向左规则赋值
void test1(int x , int w = 20)
{
    cout << "x * w = " << x * w << endl;
}

//占位参数，必须传两个参数
void test3(int x , int  = 20)
{

}



void func(char x)
{
    cout << "char x = " << x << endl;
}

void func(int x)
{
    cout << "int x = " << x << endl;
}

void func(string x )
{
    cout << "string x  = " << x << endl;
}

void func(int x , char c)
{
    cout << "int x = " << x << " --" << "char c = " << c << endl;
}

typedef void (*funcP)(int );

void test5()
{
    int a = 30;
    char c = 's';
    double d = 12.8;

//    func(c);
//    func(a);
//    func("ss");

    funcP fp1;
    fp1 = &func;

    fp1(a);
    fp1(c);



}

struct Student
{
private:
    string name;
    int age;
public:
    void setName(string na)
    {
        this->name = na;
    }

    string getName()
    {
        return this->name;
    }

    void setAge(int ag)
    {
        this->age = ag;
    }

    int getAge()
    {
        return this->age;
    }
};

void test6()
{
    Student st1;
    st1.setName("小华 --- \n");
    st1.setAge(24);
}

int main(int argc, const char * argv[])
{

    test2();
    getchar();

    return 0;
}
