//
//  main.cpp
//  test3cpp
//
//  Created by Mac on 16/5/27.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <vector>



using namespace std;


void swap(int &a , int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void test1()
{
    int a = 10;

    int b = 20;

    swap(a, b);

    cout << "b = " << b << endl;
    cout << "a = " << a << endl;

}

void test2()
{
    vector<int> a;

    for (int i = 0; i < 10; i++)
    {
        a.push_back(i);
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "a i = " << a.at(i) << endl;
    }

    

    for (int j = 0; j < 10; j++)
    {
        a.pop_back();
    }

    cout << "a size = " << a.size() << endl;
}


void getHero(int * &a)
{
    a = (int *)calloc(1, 4);
}

void test3()
{
    int *p = NULL;
    getHero(p);

    *p = 30;

    cout << "p = " << *p << endl;
    free(p);

}

void printV(vector <int> &vp)
{
    for (int i = 0; i < vp.size(); i++)
    {
        cout << "vp i = " << vp.at(i) << endl;
    }
}

void test4()
{
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < 10; i++)
    {
        a.push_back(i); //插入一个值,在最后面追加
        b.push_back(i + 'a');
    }


    using namespace std;
    //    for (int j = 9; j >=0 ; j--)
    //    {
    //        cout << "a.i = " << a.at(j) << endl; //根据索引获取值
    //    }
    //
    //    for (int j = 9; j >=0 ; j--)
    //    {
    //        cout << "a.si = " << a.at(j) << endl; //根据索引获取值
    //    }

    //常见操作
    //    a.push_back(9); //在最后面追加一个数字

    //    printV(a);

    //    int c = a.at(10); //根据索引获取一个值
    //    a.pop_back()  //去掉数组最后面那个数字

    //    cout << "c = " << a.max_size() << endl; //获取最大可以分配多少个

    //    auto p = a.begin(); //获取vector的首地址

    //    cout << *(p + 1) << endl; // 相当于 a.at(0) + 1
    //    a.end()得到数组的最后一个单元+1指针

    //    auto c = a.front(); //得到数组头的引用
    //
    //    c = 30;
    //    cout << "c = " << c << endl;
    //    printV(a);

    //    auto c = a.back(); //得到数组末尾的引用

    //    cout << "a的容量是 = " << a.capacity() << endl;
    //    cout << "a的size是 = " << a.size() << endl;
    //    a.resize(a.size() * 2); //改变大小数组
    //    cout << "a的size是 = " << a.size() << endl;

    //    a.clear(); //清空数据
    //    cout << a.size() << endl; //清空数据
    //    cout << a.capacity() << endl;
    //    int k = a.empty(); //0 代表不为空 ， 1 代表为空, 判断是否为空
    //    cout <<  k  << endl;

    //    cout << a.empty() << endl;

    //    a.swap(b); //交换两个vector
    //
    //    printV(a);
    //    printV(b);

    //    a.erase(a.begin() + 5); //删除第五个

    //    printV(a);

    //    二维数组
    //    vector<vector<int> >vv(3, vector<int>(4));        //这里，两个“>”间的空格是不可少的
    
    //    a.insert(a.begin() + 1, 19); //在指定位置插入一个元素
    //    a.insert(a.begin() + 3, 39); //插入到指定位置
    //    a.insert(a.begin(), 3, 1); //第一个参数是起始位置，第二个参数是指要插入元素的个数，第三个参数是指要插入元素的值
    
    //    printV(a);

//    a[3] = 30; //给指定位置赋值
//    printV(a);

//    std::vector<int>::iterator p  = b.begin(); //创建一个迭代器 --- 可以看做是指针
//    p += 9;
//    cout << "*p = " << *p << endl;

//    vector<string> v1; // 创建空容器，其对象类型为string类
//    vector<string> v2(10); // 创建有10个具有初始值（即空串）的string类对象的容器
//    vector<string> v3(5, "hello"); // 创建有5个值为“hello”的string类对象的容器
//    vector<string> v4(v3.begin(), v3.end()); // v4是与v3相同的容器（完全复制）

//    (6)C++ Vector排序
//    vector< int > vi ;
//    vi.push_back(1);
//    vi.push_back(3);
//    vi.push_back(0);
//    
////    sort(vi.begin(), vi.end());  //默认从小到大排序
//
//    printV(vi);
//
//    reverse(vi.begin(),vi.end()); /// 从大道小
//
//    printV(vi);

//    (8)寻找
//    vector < int > vi ;
//    for( int i = 0 ; i < 10 ; i ++)
//    {
//        vi.push_back(i);
//    }
//    vector < int >::iterator it = find(vi.begin() , vi.end(),4) ;
//    cout << *it << endl ; ///返回容器内找到值的位置。
    cout << a.data() << endl;

}

void test6()
{
    vector<int> iVec;
    cout << "容器 大小为: " << iVec.size() << endl;
    cout << "容器 容量为: " << iVec.capacity() << endl; //1个元素， 容器容量为1

    iVec.push_back(1);
    cout << "容器 大小为: " << iVec.size() << endl;
    cout << "容器 容量为: " << iVec.capacity() << endl; //2个元素， 容器容量为2

    iVec.push_back(2);
    cout << "容器 大小为: " << iVec.size() << endl;
    cout << "容器 容量为: " << iVec.capacity() << endl; //3个元素， 容器容量为4

    iVec.push_back(3);
    cout << "容器 大小为: " << iVec.size() << endl;
    cout << "容器 容量为: " << iVec.capacity() << endl; //4个元素， 容器容量为4

    iVec.push_back(4);
    iVec.push_back(5);
    cout << "容器 大小为: " << iVec.size() << endl;
    cout << "容器 容量为: " << iVec.capacity() << endl; //5个元素， 容器容量为8

    iVec.push_back(6);
    cout << "容器 大小为: " << iVec.size() << endl;
    cout << "容器 容量为: " << iVec.capacity() << endl; //6个元素， 容器容量为8

    iVec.push_back(7);
    cout << "容器 大小为: " << iVec.size() << endl;
    cout << "容器 容量为: " << iVec.capacity() << endl; //7个元素， 容器容量为8

    iVec.push_back(8);
    cout << "容器 大小为: " << iVec.size() << endl;
    cout << "容器 容量为: " << iVec.capacity() << endl; //8个元素， 容器容量为8

    iVec.push_back(9);
    cout << "容器 大小为: " << iVec.size() << endl;
    cout << "容器 容量为: " << iVec.capacity() << endl; //9个元素， 容器容量为16
    /* vs2005/8 容量增长不是翻倍的，如
     9个元素   容量9
     10个元素 容量13 */

    /* 测试effective stl中的特殊的交换 swap() */
    cout << "当前vector 的大小为: " << iVec.size() << endl;
    cout << "当前vector 的容量为: " << iVec.capacity() << endl;
    vector<int>(iVec).swap(iVec);

    cout << "临时的vector<int>对象 的大小为: " << (vector<int>(iVec)).size() << endl;
    cout << "临时的vector<int>对象 的容量为: " << (vector<int>(iVec)).capacity() << endl;
    cout << "交换后，当前vector 的大小为: " << iVec.size() << endl;
    cout << "交换后，当前vector 的容量为: " << iVec.capacity() << endl;
}

int main(int argc, const char * argv[])
{

    test4();


    getchar();


    return 0;
}


