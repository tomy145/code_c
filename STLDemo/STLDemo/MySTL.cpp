//
//  MySTL.cpp
//  STLDemo
//
//  Created by Mac on 16/6/6.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include "MySTL.hpp"

template <class T>
void MyVector<T>::push_back()
{
    std::cout << " push_back()" << std::endl;
}

template <class T>
void  MyVector<T>::clear()
{
    std::cout << "clear ..." << std::endl;
}
