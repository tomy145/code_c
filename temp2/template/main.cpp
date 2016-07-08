//
//  main.cpp
//  template
//
//  Created by Mac on 16/6/2.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <string>




template <typename T> T Add(T a, T b)
{
    return a + b;
}

template <typename T> T sum(T t1,T t2)
{
    return t1 + t2;
}

int main(int argc, const char * argv[])
{

    double a = 10.99 ,b = 20.34;
    std::cout << sum<double>(a, b) << std::endl;

    return 0;
}
