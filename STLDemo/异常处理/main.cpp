//
//  main.cpp
//  异常处理
//
//  Created by Mac on 16/6/8.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <string>


void dvide(double x , double y)
{
    if (y == 0)
    {
        std::cout << "除数不能为0 " << std::endl;

//        throw "除数不能为0";
    }
}

int main(int argc, const char * argv[])
{


//    try
//    {
//        dvide(3,0);
//    }
//    catch (std::string exp)
//    {
//        std::cout << "value = " << exp << std::endl;
//    }



    std::cout << "Hello, World!\n";
    return 0;
}
