//
//  Number.hpp
//  STLDemo
//
//  Created by Mac on 16/6/7.
//  Copyright © 2016年 Mac. All rights reserved.
//

#ifndef Number_hpp
#define Number_hpp

#include <iostream>

template <class T>
class Number
{

public:

    Number(T v)
    {
        this->value = v;
    }
    Number<T>()
    {
        this->value = 0;
    }

    Number(const Number &num)
    {
        this->value = num.value;
    }

    void printSelf()
    {
        std::cout << "this value = " << this->value << std::endl;
    }

    static void swapNumber(Number<T> &n1 , Number<T> &n2)
    {
        std::cout << "swapNumber == " << std::endl;
        Number<T> temp = n1;
        n1 = n2;
        n2 = temp;
    }

private:
    T value;


};

#endif /* Number_hpp */
