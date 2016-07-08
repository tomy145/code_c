//
//  main.cpp
//  MyNumber
//
//  Created by Mac on 16/6/7.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include "Number.hpp"


class A
{

public:
    A():a(10)
    {

    }

private:
    int a;

};

int main(int argc, const char * argv[])
{

//    Number<int> n1 = Number<int>(3);
//    Number<int>n2 = Number<int>(49);
//
//    n1.swapNumber(n1, n2);
//
//    Number<int>::swapNumber(n1, n2);

    int arr[3] = {0,1,2};

    int *p = arr;
    int *q = &arr[2];

    std::cout << p << " --" << q << std::endl;

    std::cout << (char *)p  - (char *)q<< " --" << (char *)q << std::endl;


    return 0;
}
