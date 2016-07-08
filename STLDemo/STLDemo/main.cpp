//
//  main.cpp
//  STLDemo
//
//  Created by Mac on 16/6/6.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <utility>
#include <string>
#include "MySTL.hpp"
template <typename T > void swapAnumber(T &t1 , T & t2)
{
    T temp = t1;
    t1 = t2;
    t2 = temp;
}

template <typename T>
void print(T &t1 , T & t2)
{
    std::cout << "print ..." << std::endl;
    std::cout << "t1 = " << t1 << ", t2 = " << t2 << std::endl;

}


/**
 *  C 语言版本泛型编程
 *
 *  @param t1   参数
 *  @param t2   参数
 *  @param size 大小
 */
void c_MySwap(void *t1 , void *t2 , int size)
{
    void *temp = calloc(1, size);
    temp = memcpy(temp, t1, size);

    t1 = memcpy(t1, t2, size);
    t2 = memcpy(t2, temp, size);

    free(temp);

}


template <typename T ,typename U >
void sort_Array(T *&t1 ,  U s1)
{

    for (int i = 0; i < s1; i++)
    {
        for (int j = i; j < s1 - 1; j++)
        {
            if (t1[i] > t1[j])
            {
                T temp = t1[i];
                t1[i] = t1[j];
                t1[j] = temp;
            }
        }
    }

}

template <typename T , typename U>

void printArray(T *& t1 , U count)
{
    for (int i = 0;i < count; i++)
    {
        std::cout << "t1[" << i << "] = " << t1[i] << std::endl;
    }
}


void test1()
{
    //    int a = 10;
    //    int b = 30;
    //
    ////    swapAnumber<int>(a, b);
    ////
    ////    print(a, b);
    //
    //    c_MySwap(&a, &b, sizeof(int));
    //
    //    print(a, b);


    //    std::cout << "Hello, World!\n";


    int array[4] = {1,3,4,29};

    int *p = array;

    sort_Array<int,int>(p,sizeof(int));
    
    printArray<int,int>(p,sizeof(int));
}

template <typename T , int index>
void  printValue(T &t1)
{
    std::cout << t1[index] << std::endl;
}

void test2()
{
    int arr[5] = {1,3,55,23,67};
    int *p = arr;

    printValue<int*, 3>(p);
}

struct A
{
    int v;
};



int main(int argc, const char * argv[])
{



    



    return 0;
}
