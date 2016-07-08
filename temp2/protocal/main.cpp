//
//  main.cpp
//  protocal
//
//  Created by Mac on 16/6/4.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include "Animal.hpp"
#include "cat.hpp"


struct S { void f(int i); };

void S::f(int i)
{
    [&, i]{};    // OK
    [&]{};   // ERROR: i preceded by & when & is the default
//    [=, this]{}; // ERROR: this when = is the default
//    [i, i]{};    // ERROR: i repeated
}



//template<typename ... Args>
//
//void f(Args... args)
//{
//    auto x = [args...] { return g(args...); };
//    
//    x();
//}




int main(int argc, const char * argv[])
{

//    auto x1 = [](int i) -> int { return i; }; // OK: return type is int

//  int x =   [](3);

//    Animal *a1 = new Cat("xiao", 3);
//
//    a1->run();
//    a1->voice();

    getchar();

    return 0;
}
