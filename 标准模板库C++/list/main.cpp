//
//  main.cpp
//  list
//
//  Created by Mac on 16/6/13.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <functional>
#include <algorithm>
#include <numeric>
#include <set>
#include <list>
#include <map>
#include <vector>
#include <string>

using namespace std;

void test1()
{
    using namespace std;
    int arr[] = {1,2,66,334,22,56};

    list<int>l1 = list<int>(arr, arr + sizeof(arr) / sizeof(int));

    list<int>::iterator it1 = l1.begin();
    for (int i = 0; i < 6; i++)
    {
        cout << "list i = " << *it1 << endl;
        it1++;
    }

    cout << " ---- " << endl;

    for (list<int>::iterator it2 = l1.begin(); it2 != l1.end(); it2++)
    {
        cout << "i = " << *it2 << endl;

        it2 = l1.erase(it2);//删除的时候一定要重新赋值迭代器
    }
}

class A
{

public:
    A(int num)
    {
        this->number = num;
    }
    int number;


};


class fum
{

public:
    bool operator()(A a1,A a2)
    {
        return a1.number > a2.number;
    }

};


void test2()
{
    //    set<A> s1;
    //
    //    for (int i = 0; i < 10; i++)
    //    {
    //        A a1(i + 'd');
    //        s1.insert(a1);
    //    }


    int arr[6] = {1,3,4,6,0,2};

    std::sort(arr, arr+6, [=](int a , int b)
         {
             return a < b;
         });


    for (int i = 0; i < 6; i++)
    {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }
    

}

void test3()
{

    map<int, string, greater<int>> mp1;
    mp1.insert(make_pair(1, "张三"));
    mp1.insert(make_pair(4, "王麻子"));
    mp1.insert(make_pair(0, "你大爷"));
    mp1.insert(pair<int, string>(5,"隔壁老王"));
    mp1.insert(map<int,string>::value_type(8,"老王隔壁"));

    map<int,string,greater<int>>::iterator it1;
    it1 = mp1.find(4);

    cout << it1->first << endl;
    cout << it1->second << endl;

}


class Person
{
public:

    Person(string name , int age , string phone , double wage)
    {
        this->name = name;
        this->age = age;
        this->phoneNumber = phone;
        this->wage = wage;
    }

    Person()
    {
        this->name = "";
        this->age = 0;
        this->phoneNumber = "0";
        this->wage = 0.00;

    }

    bool operator()(Person &p1,Person &p2)
    {
        return p1.wage > p2.wage;
    }

    string name;
    int age;
    string phoneNumber;
    double wage;

};


void test4()
{
    multimap<string, Person > mp1;

    Person p1 = Person("张三", 28, "11111111111", 7800.0);
    Person p2 = Person("王麻子", 30, "00000000000", 10000);
    Person p3 = Person("李四", 35, "00000000000", 14000);
    Person p4 = Person("赵六", 32, "00000000000", 14000);

    mp1.insert(make_pair("技术研发部", p1));
    mp1.insert(make_pair("技术研发部", p2));
    mp1.insert(make_pair("技术研发部", p3));
    mp1.insert(make_pair("技术研发部", p4));

    mp1.find("技术研发部");


    //    string st = to_string(1234);

    for (int i = 0; i < 3; i++)
    {
        string st1 = "张三" + to_string(i);

        cout << st1 << endl;

    }




    int arr[3] = {1,2,2};

    for_each(arr, arr+3, [](int a)
             {
                 cout << "a = " << a << endl;
             });


    int arr2[3] = {0};

    transform(arr, arr+3,arr2, [](int a)
              {
                  cout << "a = " << endl;
                  
                  return a;
              });

}


void test5()
{
    std::vector<int> someList;

    for (int i = 0; i < 10;i++)
    {
        someList.insert(someList.begin(), i + 'o');
    }

    int total = 0;

    int po = 0;



    std::for_each(someList.begin(), someList.end(), [&total,&po](int x)
                  {
                      total += x;

                      cout << "x = " << x  << endl;

                      cout << "total = " << total << endl;

                      po = x * x;
                      
                      cout << "po = " << po << endl;
                  });
    
    std::cout << "total = " << total << endl;
    
    
    //    lambda 完整表达式写法  [捕获外面的值 =x] (形参列表) -> 返回值 { 实现体 }

}


void test6()
{
    int x = 0;
    int y = 0;

    // 写法
    function<void (int a , int b)> fun = [&x,&y](int a , int b)->void {

        cout << " x  = " << x + 3 << endl;
        cout << " y = " << y + 3 << endl;

        cout << "input a = " << a << endl;
        cout << "intput b = " << b << endl;

        
    };
    
    
    fun(1,2);
}

int main(int argc, const char * argv[])
{








    return 0;
}
